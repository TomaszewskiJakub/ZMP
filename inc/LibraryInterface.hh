#ifndef LIBRARYINTERFACE_HH
#define LIBRARYINTERFACE_HH

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <cstdio>
#include <dlfcn.h>
#include <memory>
#include "Interp4Command.hh"


/*!
 * \file
 * \brief Definicja klasy LibraryInterface
 *
 *  Plik zawierający definicję klasy LibraryInterface
 */


/*!
* \brief Klasa używana do reprezentacji library interface
*
*   Klasa używana do reprezentacji library interface
*/
class LibraryInterface
{
    private:
       /*!
        * \brief Wskaźnik do biblioteki dzielonej
        *
        *  Wskaźnik używany do biblioteki dzielonej 
        */
        void* libHandler;
       /*!
        * \brief Wskaźźńik do funkcji tworzącej instancję
        *
        *  Wskaźńik do funkcji tworzącej instancję
        */
        Interp4Command* (*createCmd)(void);
          /*!
        * \brief Nazwa komendy jako string 
        *
        *  Nazwa komendy jako string 
        */
        std::string cmdName;
        
    public:
         /*!
        * \brief Konstruktor Library interface 
        *
        * Konstruktor Library interface
        */
        LibraryInterface(){}
        /*!
        * \brief Destruktor Library interface
        *
        * Destruktor Library interface 
        */
        ~LibraryInterface();
        
        /*!
        * \brief Inicjalizuję instancję library interface 
        * 
        *  Inicjalizuję instancję library interface
        * \param[in] fileName - nazwa pliku biblioteki, która ma zostać otwarta
        * \retval true - inicjalizacja wykonana bez problemu
        * \retval false - inicjalizacja wykonana z problemami
        */
        bool init(std::string fileName);

         /*!
        * \brief Udostępnia nazwę library interface
        * 
        *  Udostępnia nazwę library interface
        * 
        */
        std::string GetName(){return cmdName;}
        /*!
        * \brief  Tworzy obiekt modelujący dane polecenie
        * 
        *  Tworzy obiekt modelujący dane polecenie
        * 
        */
        Interp4Command* CreateCmd(){ return createCmd(); }
};


#endif
