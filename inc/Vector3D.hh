#ifndef VECTOR3D_HH
#define VECTOR3D_HH


#include <cassert>

/*!
 * \file
 * \brief Definicja klasy Vector3D
 *
 *  Plik zawierający definicję klasy Vector3D
 */

/*!
 * \brief Rozmiar wektora
 */
#define DIM3D 3

    /*!
    * \brief Klasa używana do reprezentacji Wektora 3D
    *
    *  Klasa używana do reprezentacji Wektora 3D
    */
   class Vector3D {
      private:
         /*!
         * \brief Tabela zawierająca współrzędne wektora o rozmiarze 3
         *  Tabela zawierająca współrzędne wektora o rozmiarze 3
         */
         double _Wsp[DIM3D];
      public:  
            /*!
            * \brief Initialize all coorinates to 0
            */
            Vector3D() { for (double &Wsp : _Wsp)  Wsp = 0; }
             /*!
            * \brief Inicjalizuje współrzędne do zadanych x, y, z
            * \param[in] x - wartość współrzędnej x
            * \param[in] y - wartość współrzędnej y
            * \param[in] z - wartość współrzędnej z
            */
            Vector3D(double x, double y, double z){_Wsp[0]=x; _Wsp[1]=y; _Wsp[2]=z;}
            /*!
            * \brief Udostępnia wybrane współrzędne (tylko do odczytu)
            *
            * \param[in]  Idx - indeks wybranej współrzędnej.
            *
            * \pre 0 <= Idx && Idx < DIM2D
            */
            double operator [] (int Idx) const 
            { assert(0 <= Idx && Idx < DIM3D); return _Wsp[Idx]; }
            /*!
            * \brief Udostępnia wybrane współrzędne (modyfikuj)
            *
            * \param[in]  Idx - indeks wybranej współrzędnej.
            *
            * \pre 0 =< Idx && Idx < DIM2D
            */
            double& operator [] (int Idx) { return _Wsp[Idx]; }

             /*!
            * \brief Udostępia wartość współrzędną x (tylko do odczytu).
            */
            double x() const { return _Wsp[0]; }
            /*!
            * \brief Udostępia wartość współrzędną x (modyfikuj).
            */
            double& x() { return _Wsp[0]; }
            /*!
            * \brief Udostępia wartość współrzędną y (tylko do odczytu).
            */
            double y() const { return _Wsp[1]; }
             /*!
            * \brief Udostępia wartość współrzędną y (modyfikuj).
            */
            double& y() { return _Wsp[1]; }

            /*!
            * \brief Udostępia wartość współrzędną z (tylko do odczytu)
            */
            double z() const { return _Wsp[2]; }
             /*!
            * \brief Udostępia wartość współrzędną z (modyfikuj).
            */
            double& z() { return _Wsp[2]; }
};


#endif
