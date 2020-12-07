#ifndef CUBOID_HH
#define CUBOID_HH
#include "MobileObject.hh"

/*!
 * \file
 * \brief Definicja klasy Cuboid
 *
 * Plik Zawierający definicję klasy Cuboid
 * 
 */

    /*! 
    *   
    *   \brief Klasa używana do reprezentowania prostopadłościennego obiektu mobilnego
    *
    *  
    */
    class Cuboid: public MobileObject
    {   
        private:
            /*!
            * \brief Skala cuboida w postaci wektora 3D
            */
            Vector3D scale;
            /*!
            * \brief Skladowa R koloru cuboida, wartość całkowita [0,255]
            */
            int colorR;
            /*!
            * \brief Skladowa G koloru cuboida, wartość całkowita [0,255] 
            */
            int colorG;
           /*!
            * \brief Skladowa B koloru cuboida, wartość całkowita [0,255] 
            */
            int colorB;

        public:

            /*!
            * \brief Konstruktor Cuboida
            *
            * Konstruktor Cuboida
            * \param[in] in_name - imię obiektu jako string
            * \param[in] in_rot_deg - rotacja obiektu jako Vector3D (roll, pitch, yaw). Wartości są w stopniach
            * \param[in] in_pos_m - pozycja obiektu jako Vector3D (x, y, z). Wartości są w  metrach
            */

            Cuboid(std::string in_name, Vector3D in_rot_deg, Vector3D in_pos_m):
                                        MobileObject(in_name, in_rot_deg, in_pos_m) {};
             /*!
            * \brief Cuboid constructor
            *
            * Mobile object constructor
            * \param[in] in_name - imię obiektu jako string
            * \param[in] in_rot_deg - rotacja obiektu jako Vector3D (roll, pitch, yaw). Wartości są w stopniach
            * \param[in] in_pos_m - pozycja obiektu jako Vector3D (x, y, z). Wartości są w  metrach
            * \param[in] in_scale - skala obiektu jako Vector3D (x, y, z).
            * \param[in] in_color - Kolor jako Vector3D (R, G, B). Każda z wartości w zakresie [0, 255]
            */
            Cuboid(std::string in_name, Vector3D in_rot_deg, Vector3D in_pos_m, Vector3D in_scale, int in_colorR, int in_colorG, int in_colorB):
                                        MobileObject(in_name, in_rot_deg, in_pos_m), scale(in_scale), 
                                        colorR(in_colorR), colorG(in_colorG), colorB(in_colorB) {};
            /*!
            * \brief Konstruktor Cuboida 
            *
            * Kontruktor Cuboida
            */
            Cuboid(){};

            /*!
            * \brief Udostępnia skalę obiektu mobilnego w postaci wektora 
            *
            *  Udostępnia skalę obiektu mobilnego w postaci wektora 
            *  \return Skala obiektu mobilnego w postaci wektora 
            */
            const Vector3D & GetScale(){return scale;}; 

            /*!
            * \brief Udostępnia skladową R koloru obiektu mobilnego 
            *
            *  Udostępnia skladową R koloru obiektu mobilnego 
            *  \return Składowa R bieku mobilnego
            */
            const int & GetColorR(){return colorR;}

             /*!
            * \brief Udostępnia skladową G koloru obiektu mobilnego 
            *
            *  Udostępnia skladową G koloru obiektu mobilnego 
            *  \return Składowa G bieku mobilnego
            */
            const int & GetColorG(){return colorG;}

             /*!
            * \brief Udostępnia skladową B koloru obiektu mobilnego 
            *
            *  Udostępnia skladową B koloru obiektu mobilnego 
            *  \return Składowa B bieku mobilnego
            */
            const int & GetColorB(){return colorB;} 
    };


#endif