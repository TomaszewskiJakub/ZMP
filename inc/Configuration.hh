#ifndef CONFIGURATION_HH
#define CONFIGURATION_HH
#include <vector>
#include "MobileObject.hh"
#include "Vector3D.hh"


/*!
 * \file
 * \brief Definicja klasy Configuration 
 *
 *  Plik zawierający definicję klasy Configuration 
 */

    /*!
    * \brief Klasa używana do reprezentacji konfiguracji
    *
    *  Klasa używana do reprezentacji konfiguracji odczytanej z pliku xml. Zawiera wektor ścieżek do wtyczek, nazwy obiektów mobilnych, ich skal oraz kolorów.
    */
class Configuration 
{
    private:
         /*!
        * \brief Wektor ścieżek do wtyczek
        *
        *  Wektor ścieżek do wtyczek
        */
        std::vector<std::string> plugPaths;

        /*!
        * \brief Wektor nazw obiektów mobilnych 
        *
        *  Wektor nazw obiektów mobilnych do dodania
        */
        std::vector<std::string> mobileName;

         /*!
        * \brief Wektor skal obiektów mobilnych
        *
        *  Wektor skal obiektów do dodania
        */
        std::vector<Vector3D> mobileScale;
       /*!
        * \brief Wektor kolorów obiektów mobilnych
        *
        *  Wektor kolorów obiektów do dodania
        */
        std::vector<Vector3D> mobileColor;
    
    public:
    
         /*!
        * \brief Udostępnia wektor ścieżek do wtyczek (tylko do odczytu)
        *
        *  Udostępnia wektor ścieżek wtyczek do dodania (tylko do odczytu)
        *  \return wektor ścieżek wtyczek
        */
        std::vector<std::string> GetPluginPaths() const { return plugPaths; }

         /*!
        * \brief Dodaje ścieżkę do wektora ścieżek wtyczek
        *
        *  Dodaj element do wektor ścieżek wtyczek
        *  \param[in] path - ścieżka do wtyczki
        */
        void AddPluginPaths(std::string path) { plugPaths.push_back(path); }


         /*!
       * \brief Udostępnia wektor nazw obiektów mobilnych 
        *
        *  Udostępnia wektor nazwobiektów mobilnych
        *  \return Wektor nazw obiektów mobilnych
        */
        std::vector<std::string> GetMobileName() const { return mobileName; }
        /*!
        * \brief Dodaj nazwę do wektora nazw obiektów mobilnych
        *
        *  Dodaj nazwę do wektora nazw obiektów mobilnych
        *  \param[in] - nazwa obiektu mobilnego do dodania
        */
        void AddMobileName(std::string mobName) { mobileName.push_back(mobName); }

       /*!
        * \brief Udostępnia wektor skal obiektów mobilnych
        *
        *  Udostępnia wektor skal obiektów mobilnych
        *  \return Wektor skal obiektów mobilnych
        */
        std::vector<Vector3D> GetMobileScale()  const { return mobileScale; }
        /*!
        * \brief Dodaje skalę do wektora skal obiektów mobilnych
        *
        *  Dodaje skalę do wektora skal obiektów mobilnych
        */
        void AddMobileScale(Vector3D mobScale) { mobileScale.push_back(mobScale); }


         /*!
        * \brief Udostępnia wektor kolorów obiektów mobilnych
        *
        *  Udostępnia wektor kolorów obiektów mobilnych
        *  \return Wektor kolorów obiektów mobilnych
        */
        std::vector<Vector3D> GetMobileColor() const { return mobileColor; }
        /*!
        * \brief Dodaje kolor do wektora kolorów obiektów mobilnych
        *
        *  Dodaje kolor do wektora kolorów obiektów mobilnych
        */
        void AddMobileColor(Vector3D mobColor) { mobileColor.push_back(mobColor); }


};


#endif
