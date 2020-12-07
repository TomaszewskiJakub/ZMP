#ifndef PLUGINMANAGER_HH
#define PLUGINMANAGER_HH

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <cstdio>
#include <dlfcn.h>
#include <memory>
#include <map>
#include <vector>
#include "LibraryInterface.hh"
#include "Scene.hh"


/*!
 * \file
 * \brief Definicja klasy PluginManager
 *
 *  Plik zawierający definicję klasy PluginManager
 */

    /*!
    * \brief Klasa używana do reprezentacji menadżera pluginów
    *
    *  Klasa używana do reprezentacji menadżera pluginów. Zawiera wszystkie instancje i interfejs bibliotek
    */
    class PluginManager
    {
        private:
           /*!
            * \brief Kolekcja wszystkich załadowanych wtyczek
            *
            *  Kolekcja wszystkich załadowanych wtyczek
            * 
            */
            std::map<std::string, std::shared_ptr<LibraryInterface>> mapLibraries;
            /*!
            * \brief Wskaźnik do bieżącej instancji polecenia
            *
            *  Wskaźnik do bieżącej instancji polecenia
            */
            Interp4Command* cmdInstance;
        public:
            /*!
            * \brief Inicjalizuję instancję PlugiManager
            * 
            *  Inicjalizuję instancję PlugiManager
            * \param[in] pluginPaths - wektor zawierający ścieżki do wtyczek
            */
            bool init(std::vector<std::string> pluginPaths);
             /*!
            * \brief Uruchamia podane polecenia  
            * \param[in, out] commandsStream - strumień poleceń
            * \param[in] scene - scena zawierająca wszystkie obiekty 
            * \param[in] serverSocket - gniazdo do serwera
            */
            bool exec(std::istream & commandsStream, std::shared_ptr<Scene> & scene ,  int serverSocket); 
    };


#endif
