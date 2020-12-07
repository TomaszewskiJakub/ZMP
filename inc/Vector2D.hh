#ifndef VECTOR2D_HH
#define VECTOR2D_HH


#include <cassert>


/*!
 * \file
 * \brief Definicja klasy Vector2D
 *
 *  Plik zawierający definicję klasy Vector2D
 */

/*!
 * \brief Rozmiar wektora
 */
#define DIM2D 2

   /*!
    * \brief Klasa używana do reprezentacji Wektora 2D
    *
    *  Klasa używana do reprezentacji Wektora 2D
    */
   class Vector2D {
      private:
          /*!
         * \brief Tabela zawierająca współrzędne wektora o rozmiarze 2
         *  Tabela zawierająca współrzędne wektora o rozmiarze 2
         */
         double _Wsp[DIM2D];
      public:  
         /*!
         * \brief IZainicjuj wszystkie współrzędne jako 0
         */
         Vector2D() { for (double &Wsp : _Wsp)  Wsp = 0; }
         /*!
         * \brief Inicjalizuje współrzędne do zadanych x, y
         * \param[in] x - wartość współrzędnej x
         * \param[in] y - wartość współrzędnej y
         */
         Vector2D(double x, double y){_Wsp[0]=x; _Wsp[0]=y;}

        /*!
         * \brief Udostępnia wybrane współrzędne (tylko do odczytu)
         *
         * \param[in]  Idx - indeks wybranej współrzędnej
         *
         * \pre 0 <= Idx && Idx < DIM2D
         */
         double operator [] (int Idx) const 
         { assert(0 <= Idx && Idx < DIM2D); return _Wsp[Idx]; }
         /*!
         * \brief Udostępnia wybrane współrzędne (modyfikuj)
         *
         * \param[in]  Idx - indeks wybranej współrzędnej
         *
         * \pre 0 =< Idx && Idx < DIM2D
         */
         double& operator [] (int Idx) { return _Wsp[Idx]; }

         /*!
         * \brief  Udostępia wartość współrzędną x (tylko do odczytu).
         */
         double x() const { return _Wsp[0]; }
          /*!
         * \brief  Udostępia wartość współrzędnej x (modyfikuj).
         */
         double& x() { return _Wsp[0]; }

         /*!
         * \brief Udostępia wartość współrzędną y (tylko do odczytu).
         */
         double y() const { return _Wsp[1]; }
           /*!
         * \brief GUdostępia wartość współrzędnej y (modyfikuj).
         */
         double& y() { return _Wsp[1]; }
   };


#endif
