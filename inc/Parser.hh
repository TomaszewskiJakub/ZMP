#ifndef PARSER_HH
#define PARSER_HH

#include <string>
#include <sstream>
#include <cassert>
#include <cstdio>
#include <iostream>
#include "xmlinterp.hh"
using namespace XERCES_CPP_NAMESPACE;
#define LINESIZE 500

/*!
 * \file
 * \brief Definicja kalsy Parser
 *
 *  Plik zawierający definicje klasy Parser
 */

    /*! 
    *   
    *   \brief Kalsa używania do reprezenacji parsera CMD oraz XML
    *
    *   Parser CMD oraz XML
    */
    class Parser
    {
        private:
            /*! \brief Nazwa pliku cmd do odczytania*/
            std::string cmdFile;
             /*! \brief Nazwa pliku xml do odczytania*/
            std::string xmlFile;
            /*! \brief Konfiguracja odczytana z pliku xml */
            Configuration conf;
        public:
            /*!
            * \brief Konstruktor Parsera
            *
            * Konstruktor Parsera
            * \param[in] cmd - nazwa pliku cmd 
            * \param[in] xml - nazwa pliku xml
            */
            Parser(std::string cmd, std::string xml): cmdFile(cmd), xmlFile(xml) {} 
           /*!
            * \brief Wczytuje dane z pliku cmd 
            *
            * Wczytuje dane z pliku cmd 
            * \param[out] IStrm4Cmds - strumien wyjściowy
            * \retval true -  Wczytanie pliku powiodło się 
            * \retval false - Wczytanie pliku nie powiodło się 
            */
            bool ParseCmd(std::istringstream & IStrm4Cmds);
            /*!
            * \brief Wczytuje dane z pliku xml
            *
            * Wczytuje dane z pliku xml
            * \param[out] IStrm4Cmds - strumien wyjściowy
            * \retval true -  Wczytanie pliku powiodło się 
            * \retval false - Wczytanie pliku nie powiodło się 
            */
            bool ParseXML(std::istringstream & IStrm4Cmds);
            /*!
            * \brief Zwraca aktualne wartości konfiguracji (tylko do odczytu)
            *
            * \return - Aktualne wartosci konfiguracji
            */
            Configuration  GetConf() const { return conf; }

    };


#endif