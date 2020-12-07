#ifndef  COMMAND4MOVE_HH
#define  COMMAND4MOVE_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif
#include "Interp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Rotate
 *
 * Plik zawierający definicja klasy Interp4Rotate
 */

    /*!
    * \brief  Klasa używana do reprezentacji polecenia rotacji
    *
    *  Klasa używana do reprezentacji polecenia rotacji
    */
    class Interp4Rotate: public Interp4Command
    {
        private:
            /*! 
             * \brief Nazwa obiektu, który ma zostać obrócony
            *
            * Nazwa obiektu, który ma zostać obrócony 
            */
            std::string obj_name; 
            /*! 
            * \brief Prędkość kątowa obiektu w stopniach / sekundę (stopnie / s)
            *
            *  Prędkość kątowa obiektu w stopniach / sekundę (stopnie / s)
            */
            double rot_speed_degs;
            /*! 
            * \brief Obrót obiektu w stopniach (deg)
            *
            *  Obrót obiektu w stopniach (deg)
            */
            double rot_deg;
        public:
           /*! 
            * \brief Konstruktor klasy Interp4Rotate
            *
            *  Konstruktor klasy Interp4Rotate
            */
            Interp4Rotate();
            /*! 
            * \brief Destruktor klasy Interp4Rotate
            *
            *  Destruktor klasy Interp4Rotate
            */
            ~Interp4Rotate();
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
            * \brief Zwraca nazwę obiektu, którego dotyczy polecenie obrotu
            * 
            * Zwraca nazwę obiektu, którego dotyczy polecenie obrotu
            * 
            * \return nazwa obiektu
            */
            std::string GetObjName(){return obj_name;}
    };

#endif
