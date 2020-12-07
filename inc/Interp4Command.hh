#ifndef  INTERP4COMMAND_HH
#define  INTERP4COMMAND_HH

#include <iostream>
#include "MobileObject.hh"
#include <memory>
#include "AccessControl.hh"
#include <unistd.h>
#include <cmath>
#include "Scene.hh"
/*!
 * \file
 * \brief Definicja klasy Interp4Command
 *
 * Plik zawiera definicję klasy Interp4Command
 */

    /*!
    * \brief Klasa używana to reprezentowania wirtualnych metod obiektu mobilnego
    *
    *  Klasa używana to reprezentowanie abstrakcjnych metod obiektu mobilnego
    */
    class Interp4Command {
        public:
           /*!
            * \brief Wirtualny destruktor
            *
            */
            virtual ~Interp4Command() {}
            /*!
            * \brief  Wyświetla postać bieżącego polecenia (nazwę oraz wartości parametrów)
            */
            virtual void PrintCmd() const = 0;
            /*!
            * \brief Wyświetla składnię polecenia
            */
            virtual void PrintSyntax() const = 0;
            /*!
            *  \brief  Zwraca wskaźnik do napisu będącego nazwą danego polecenia. 
            */
            virtual const char* GetCmdName() const = 0;
            /*!
            * \brief Wykonuje polecenie 
            * \retval true - wykonanie bez problemów
            * \retval false - wystąpił błąd podczas wykonywania
            */
            virtual bool ExecCmd(  std::shared_ptr<MobileObject>  & wObMob,  std::shared_ptr<Scene>  & pAccCtrl  ) const = 0;
            /*!
            * \brief Wczytuję parametry komendy
            * \param[in, out] Strm_CmdsList - strumień zawierający parametry do odczytania
            * \retval true - wczytanie wykonane z powodzeniem
            * \retval false - wczytanie nie zostało wykonane z powodzeniem
            */
            virtual bool ReadParams(std::istream& Strm_CmdsList) = 0;
            /*!
            * \brief Zwraza nazwę obiektu, którego dotyczy polecenie
            * \return Nazwę obiektu
            */
            virtual std::string GetObjName() = 0;
    };




#endif
