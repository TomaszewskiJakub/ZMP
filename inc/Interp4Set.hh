#ifndef  COMMAND4SET_HH
#define  COMMAND4SET_HH

#ifndef __GNUG__
# pragma interface
# pragma implementation
#endif
#include "Interp4Command.hh"

/*!
 * \file
 * \brief Definicja klasy Interp4Set
 *
 * Plik zawieracjący definicję klasy Interp4Set
 */

	/*!
    * \brief Klasa używana do reprezentacji polecenia set
    *
    *  Klasa używana do reprezentacji polecenia set
    */
	class Interp4Set: public Interp4Command
	{
		private:
			/*! 
            * \brief Nazwa obiektu, który ma zostać ustawiony 
            *
            *  Nazwa obiektu, który ma zostać ustawiony 
            */
			std::string obj_name;
			/*! 
            * \brief Pozycja końcowa współrzędnej x w metrach (m)
            *
            *  Pozycja końcowa współrzędnej x w metrach (m)
            */
			int pos_x_m;
			/*! 
            * \brief Pozycja końcowa współrzędnej y w metrach (m)
            *
            *  Pozycja końcowa współrzędnej y w metrach (m)
            */
			int pos_y_m;
			/*! 
            * \brief Końcowy obrót wokół osi Z w stopniach
            *
            *  Końcowy obrót wokół osi Z w stopniach
            */
			int angle_z_deg;
		public:
			/*! 
            * \brief Konstruktor klasy Interp4Set
            *
            *  Konstruktor klasy Interp4Set
            */
			Interp4Set();
			/*! 
            * \brief Destruktor klasy Interp4Set
            *
            *   Destruktor klasy Interp4Set
            */
			~Interp4Set();
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
             * \brief Zwraca nazwę obiektu, którego dotyczy polecenie set
            * 
            * Zwraca nazwę obiektu, którego dotyczy polecenie set
            * 
            * \return nazwa obiektu
            */
			std::string GetObjName(){return obj_name;}
	};

#endif
