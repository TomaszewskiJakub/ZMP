#ifndef SCENE_HH
#define SCENE_HH

#include <map>
#include <iostream>
#include <iterator>
#include <string>
#include <memory>

#include "MobileObject.hh"
#include "AccessControl.hh"

/*!
 * \file
 * \brief Definicja klasy Scene 
 *
 *  Plik zawierający definicje klasy Scene
 */
    /*!
    * \brief Klasa używana do reprezentacji Sceny
    *
    *  Klasa używana do reprezentacji Sceny. Zawiera wszystkie obiekty
    */
    class Scene: public AccessControl
    {
        private:
            /*!
            * \brief Kolekcja wszystkich obiektów mobilnych 
            *
            *  Kolekcja wszystkich obiektów mobilnych 
            */
            std::map<std::string, std::shared_ptr<MobileObject>> mapMobileObjects;
        public:
            /*!
            * \brief Funkcja pozwala na znalezienie zadanego obiektu
            * \param[in, out] name - nazwa obiektu, który ma zostać znaleziony
            * \param[out] tempMobileObject - pusty wskaźnik do obiektu. Jeśli obiekt zostanie znaleziony, zostanie tutaj zwrócony
            * \retval true - obiekt został znaleziony
            * \retval false - obiekt nie został znaleziony
            */
            bool FindMobileObject (std::string name, std::shared_ptr<MobileObject> & tempMobileObject);
             /*!
            * \brief Dodaje obiekt mobilny do Sceny
            * \param[in] handler - wskaźnik do obiektu mobilnego, który ma zostać dodany do sceny
            * 
            */
            void AddMobileObject(std::shared_ptr<MobileObject> handler);


            /*!
            * \brief Udostępnia kolekcje wyszystkich obiektów mobilnych 
            * 
            *  Udostępnia kolekcje wyszystkich obiektów mobilnych
            *  \return kolekcja obiektów mobilnych
            */
            std::map<std::string, std::shared_ptr<MobileObject>> & GetMapMobileObjects() {return mapMobileObjects;}



    };


#endif