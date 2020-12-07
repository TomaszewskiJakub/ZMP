#ifndef  COMMAND4PAUSE_HH
#define  COMMAND4PAUSE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif
#include "Interp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Pause
 *
 * Plik zawierający definicję klasy Interp4Pause
 */



    /*!
    * \brief Klasa używana do reprezentacji polecenia pause 
    *
    *  Klasa używana do reprezentacji polecenia pause 
    */
    class Interp4Pause: public Interp4Command
    {
        private:
             /*! 
            * \brief Czas pausy w sekunach (s)
            *
            *  Czas pausy w sekunach (s)
            */
            int time_ms;
        public:
              /*! 
            * \brief Konstruktor klasy Interp4Pause
            *
            *  Konstruktor klasy Interp4Pause
            */
            Interp4Pause();
              /*! 
            * \brief Destruktor klasy Interp4Pause
            *
            *  Destruktor klasy Interp4Pause
            */
            ~Interp4Pause();
             /*!
            * \brief Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów)
            */
            void PrintCmd() const;
            /*!
            * \brief Wyświetla składnię polecenia
            */
            void PrintSyntax() const;
            /*!
            * \brief Zwraca wskaźnik do napisu będącego nazwą danego polecenia
            * \return wskaźnik do napisu będącego nazwą danego polecenia
            */
            const char* GetCmdName() const;
            /*!
            * \brief Wykonuje polecenie 
            * \param[in, out] wObMob - wskaźnik na obiekt mobilny na którym ma zostać wykonane polecenie
            * \param[in, out] pAccCtrl - wskaźnik na scene na której znajduję się obiekt mobilny
            * \retval true - wykonanie bez problemów
            * \retval false - wystąpił błąd podczas wykonywania  
            */
            bool ExecCmd(std::shared_ptr<MobileObject> & wObMob,  std::shared_ptr<Scene> & pAccCtrl) const;
            /*!
            * \brief Wczytuję parametry komendy
            * \param[in, out] Strm_CmdsList - strumień zawierający parametry do odczytania
            * \retval true - wczytanie wykonane z powodzeniem
            * \retval false - wczytanie nie zostało wykonane z powodzeniem
            */
            bool ReadParams(std::istream& Strm_CmdsList);
            /*!
            * \brief Funkcja statyczna tworząca instancję polecenia,
            * 
            * Funkcja statyczna tworząca instancję polecenia
            * \return wskaźnik do instancji polecenia 
            */
            static Interp4Command* CreateCmd();
            /*!
            * \brief Zwraca nazwę obiektu
            * 
            * Zwraca nazwę obiektu
            * 
            * \return nazwa obiektu
            */
            std::string GetObjName(){return "";}
    };

#endif
