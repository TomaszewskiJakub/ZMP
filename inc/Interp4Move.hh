#ifndef  COMMAND4MOVE_HH
#define  COMMAND4MOVE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif

#include "Interp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Move
 *
 * Plik zawierający definicję klasy Interp4Move
 */

    /*!
    * \brief Klasa używana do reprezentacji polecenia move
    *
    *  Klasa używana do reprezentacji polecenia move
    */
    class Interp4Move: public Interp4Command
    {
        private:
            /*! 
            * \brief Nazwa obiektu, który ma wykonać ruch 
            *
            *  Nazwa obiektu, który ma wykonać ruch 
            */
            std::string obj_name;
            /*! 
            * \brief Prędkość obiektu w metrach/sekunde (m/s)
            *
            *  Prędkość obiektu w metrach/sekunde (m/s)
            */
            int vel_ms;
            /*! 
            * \brief Długość przesunięcia obiektu
            *
            *  Długość przesunięcia obiektu w metrach (m)
            */
            int dist_m;
        public:
            /*! 
            * \brief Konstruktor klasy Interp4Move
            *
            *  Konstruktor klasy Interp4Move
            */
            Interp4Move();
             /*! 
            * \brief Destruktor klasy Interp4Move
            *
            *  Destruktor klasy Interp4Move
            */
            ~Interp4Move();
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
            * \brief Zwraca nazwę obiektu, którego dotyczy polecenie ruchu
            * 
            * Zwraca nazwę obiektu, którego dotyczy polecenie ruchu
            * 
            * \return nazwa obiektu
            */
            std::string GetObjName(){return obj_name;}
    };

#endif
