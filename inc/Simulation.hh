#ifndef SIMULATION_HH
#define SIMULATION_HH

#include "Parser.hh"
#include "PluginManager.hh"
#include "Scene.hh"
#include <sstream>
#include "Cuboid.hh"

/*!
 * \file
 * \brief Definicja klasy Simulation
 *
 *  Plik zawierający definicję klasy Simulation
 */



    /*!
    * \brief Klasa używana do reprezentowania Symulacji
    *
    *  Klasa używana do reprezentowania Symulacji. Zawiera menadżer wtyczek, parser oraz scene 
    */
    class Simulation
    {
        private:
            /*!
            * \brief Parser plików cmd oraz xml
            *
            * Parser plików cmd oraz xml
            */
            std::shared_ptr<Parser> parser;
          /*!
            * \brief Wskaźnik menadżera wtyczek
            *
            *  Wskaźnik menadżera wtyczek
            */
            std::shared_ptr<PluginManager> plugManager;
             /*!
            * \brief Wskażnik Sceny 
            *
            *  Wskaźnik Sceny
            */
            std::shared_ptr<Scene> scene;
            /*!
            * \brief Numer gniazda serwera
            *   
            *  Numer gniazda serwera
            */   
            int serverSocket;

            
        public:
            /*!
            * \brief Inicjalizuję instancję Symulacji
            * 
            *  Inicjalizuję instancję Symulacji
            * \param[in] cmdPath - nazwa pliku cmd 
            * \param[in] xmlPath - nazwa pliku xml
            */
            bool init(std::string cmdPath, std::string xmlPath);


            /*!
            * \brief Metoda uruchamiająca symulację 
            */
            bool exec(); 

            /*!
            * \brief Udostępnia wskaźnik na nascene
            * 
            * Udostępnia wskaźnik na nascene
            */
            std::shared_ptr<Scene> & GetScene(){return scene;}

            /*!
            * \brief Dodje cuboida z konfiguracji wczytanej przez parser
            * \retval True - operacja zakońćzona powodzeniem
            * \retval False - operacja zakońćzona niepowodzeniem
            */
            bool AddCuboids();


            /*!
            * \brief  Szablon metody dodający obiekt mobliny na scene
            * \param[in] in_name - nazwa obiektu, który ma zostać dodany 
            * \param[in] in_rot_deg - Wektor rotacji (roll, pitch, yaw). Wartości w stopniach.
            * \param[in] in_pos_m -Wektor pozycji (x, y, z). Wartości w metrach.
            */
            template <typename T>
            bool AddMobileObject(std::string in_name, Vector3D in_rot_deg, Vector3D in_pos_m)
            {
                T mobileObjectTest;
                MobileObject* mobileTest;
                if(!(mobileTest = dynamic_cast< MobileObject* >(&mobileObjectTest)))
                {
                    std:: cout << "Podany typ " << typeid(mobileObjectTest).name() << "nie jest ObiektemMobilnym!!!"<< std::endl;
                    return false;
                }
                std::shared_ptr<T> objectToAdd = std::make_shared<T>(in_name, in_rot_deg, in_pos_m);
                scene->AddMobileObject(objectToAdd);

                return true;
            }

            
    };


#endif
