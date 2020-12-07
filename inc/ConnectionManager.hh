#ifndef CONNECTIONMANAGER_HH
#define CONNECTIONMANAGER_HH
#include "Port.hh"
#include "Simulation.hh"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <vector>

/*!
 * \file
 * \brief Definicja klasy ConnectionManager
 *
 *  Plik zawierający definicję klasy ConnectionManager
 */

    /*!
    * \brief Klasa używana do reprezentacji menadżera połączenia
    *
    *  Klasa używana do reprezentacji menadżera połączenia. Odpowiada za połączenie Symulacji z Serwerem
    */
class ConnectionManager 
{
    private:
        /*!
        * \brief Deskryptor gniazda sieciowego, poprzez które wysyłane są polecenia.
        */
        int socket_manager = 0;

        /*!
        * \brief Wartość tego pola decyduje o kontynuacji wykonywania wątku.
        * 
        * Wartość tego pola decyduje o kontynuacji wykonywania wątku.
        * W przypadku wartości \p true, pętla wątku będzie wykonywana.
        * Natomiast wartość \p false powoduje przerwanie pętli.
        */
        volatile bool _ContinueLooping = true;

        /*!
        * \brief Wskaźnik na symulacje, której stan jest przesyłany w postaci
        *        poleceń do serwera graficzneg.
        */
        std::shared_ptr<Simulation> mySim;
    public:
       /*! 
        * \brief Konstruktor klasy ConnectionManager
        *
        *  Konstruktor klasy ConnectionManager
        */
        ConnectionManager(){}

       /*! 
        * \brief Destruktor klasy ConnectionManager
        *
        *  Destruktor klasy ConnectionManager
        *  Odpowiada za wysłanie wiadomości "Close" do serwera oraz zamknięcie  portu
        */
        ~ConnectionManager(){Send("Close\n"); close(socket_manager);}

      /*!
        * \brief Inicjalizuję instancję ConnectionManager
        * 
        *  Inicjalizuję instancję ConnectionManager
        * \param[in] sim - wskaźnik na symulację
        * \retval true - inicjalizacja wykonana bez problemu
        * \retval false - inicjalizacja wykonana z problemami
        */
        bool init(std::shared_ptr<Simulation> sim);

          /*!
        * \brief Sprawdza, czy pętla wątku może być wykonywana.
        * 
        * Sprawdza, czy pętla wątku może być wykonywana.
        * \retval true - pętla wątku może być nadal wykonywana.
        * \retval false - w przypadku przeciwnym.
        */
        bool ShouldCountinueLooping() const { return _ContinueLooping; }

        /*!
        * \brief Powoduje przerwanie działania pętli wątku.
        *
        * Powoduje przerwanie działania pętli wątku.
        * \warning Reakcja na tę operację nie będize natychmiastowa.
        */
        void CancelCountinueLooping() { _ContinueLooping = false; }

        /*!
        * \brief Ta metoda jest de facto treścią wątku komunikacyjnego
        *
        * Przegląda scenę i tworzy odpowiednie polecenia, a następnie
        * wysyła je do serwera.
        * \param[in] Socket - deskryptor gniazda sieciowego, poprzez które
        *                     wysyłane są polecenia.
        */
        void Watching_and_Sending();

        /*!
        * \brief Tworzy polecenie  do wysłania na zerwer dla zadanego cobuida
        * 
        * Tworzy polecenie do wysłania na serwer dla zadanego cobuida
        * \param[in] mob - Cuboid dla którego ma zostać utworzone polecenie
        * 
        */
        std::string CreateMessage(Cuboid mob);

        /*!
        * \brief Wysyła napis do serwera poprzez gniazdo sieciowe.
        *
        * Wysyła napis do serwera poprzez gniazdo sieciowe.
        * 
        * \param[in] sMesg - zawiera napis, który ma zostać wysłany poprzez
        *                    gniazdo sieciowe.
        */
        int Send(const char *sMesg);

};


#endif
