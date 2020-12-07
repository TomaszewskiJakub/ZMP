#ifndef MOBILEOBJECT_HH
#define MOBILEOBJECT_HH
#include "Vector3D.hh"
#include "Vector2D.hh"
#include <string>
#include <iostream>


/*!
 * \file
 * \brief Definicja klasy MobileObject.
 *
 *  Plik zawierający definicją klasy MobileObject.
 * 
 */

    /*! 
    *   
    *   \brief Klasa używana do reprezentacji obiektu mobilnego
    *
    *   Obiekt mobliny jest obiektem, któr może się ruszać 
    */
    class MobileObject
    {
        protected:
            /*! \brief Nazwa obiektu jako std::string */
            std::string name;
            /*! \brief Wektor 3D rotacji zdefiniowana jako (roll, pitch yaw) lub (rotX, rotY, rotZ) w stopniach*/
            Vector3D rot_deg;
            /*! \brief Wektor 3D pozycja zdefiniowany jako (x, y z) w metrach*/
            Vector3D pos_m;
            
        public:
            /*!
            * \brief Konstruktor mbiektu mobilnego
            *
            * Konstruktor Obiektu mobilnego
            * \param[in] in_name - nazwa obiektu mobilnego jako string
            * \param[in] in_rot - rotacja obiektu jako Vector3D (roll, pitch, yaw). Wartości są w stopniach
            * \param[in] in_pos - pozycja obiektu jako Vector3D (x, y, z). Wartości są w metrach
            */
            MobileObject(std::string in_name, Vector3D in_rot_deg, Vector3D in_pos_m): name(in_name), rot_deg(in_rot_deg), pos_m(in_pos_m)  {};
            /*!
            * \brief Konstruktor obiektu mobilnego
            *
            * construktor obiektu mobilnego 
            */
            MobileObject(){};

            /*!
            * \brief Wirtualny destruktor
            *
            *  
            */
            virtual ~MobileObject() {}
           /*!
             * \brief Udostępia wartość kąta \e roll.
             *
             * Udostępia wartość kąta \e roll. Jest ona wyrażona w stopniach.
             */
            virtual double GetAng_Roll_deg() const { return rot_deg[0]; }
            /*!
             * \brief Udostępia wartość kąta \e pitch.
             *
             * Udostępia wartość kąta \e pitch. Jest ona wyrażona w stopniach.
            */
            virtual double GetAng_Pitch_deg() const { return rot_deg[1]; }
               /*!
             * \brief Udostępia wartość kąta \e yaw.
             *
             * Udostępia wartość kąta \e yaw. Jest ona wyrażona w stopniach.
             */
            virtual double GetAng_Yaw_deg() const { return rot_deg[2]; }

            /*!
             * \brief Zmienia wartość kąta \e roll.
             *
             * Zmienia wartość kąta \e roll.
             * \param[in] Ang_Roll_deg - nowa wartość kąta \e roll wyrażona w stopniach.
             */
            virtual void SetAng_Roll_deg(double Ang_Roll_deg) { rot_deg[0] = Ang_Roll_deg; }
             /*!
            * \brief Zmienia wartość kąta \e pitch.
            *
            * Zmienia wartość kąta \e pitch.
            * \param[in] Ang_Pitch_deg - nowa wartość kąta \e pitch wyrażona w stopniach.
            */
            virtual void SetAng_Pitch_deg(double Ang_Pitch_deg) { rot_deg[1] = Ang_Pitch_deg; }
            /*!
            * \brief Zmienia wartość kąta \e yaw.
            *
            * Zmienia wartość kąta \e yaw.
            * \param[in] Ang_Yaw_deg - nowa wartość kąta \e yaw wyrażona w stopniach.
            */
            virtual void SetAng_Yaw_deg(double Ang_Yaw_deg) { rot_deg[2] = Ang_Yaw_deg; }

              /*!
            * \brief Udostępnia współrzędne położenia obiektu w trybie tylko do odczytu.
            *
            * Udostępnia współrzędne punktu, który definiuje położenia obiektu
            * w trybie tylko do odczytu.
             *Domyślnie przyjmuje się, że jest to geometryczny środek bryły
            * Wartość Vector3D w metrach.
            * 
            */
            virtual const Vector3D & GetPosition_m() const { return pos_m; }
            /*!
            * \brief Udostępnia współrzędne położenia obiektu w trybie modyfikacji.
            *
            * Udostępnia współrzędne punktu, który definiuje położenia obiektu
            * w trybie modyfikacji.
            * Domyślnie przyjmuje się, że jest to geometryczny środek bryły.
            * Wartość Vector3D w metrach.
            * 
            */
            virtual Vector3D & UsePosition_m() { return pos_m; }
            /*!
            * \brief Zmienia współrzędne położenia obiektu.
            *
            * Zmienia współrzędne punktu, który definiuje położenia obiektu.
            * Domyślnie przyjmuje się, że jest to geometryczny środek bryły.
            * \param[in] rPos_m - współrzędne nowgo położenia. Przyjmuje się,
            *                     że są one wyrażone w metrach.
            */
            virtual void SetPosition_m(const Vector3D &rPos_m) { pos_m = rPos_m; }


            /*!
            * \brief Zmienia nazwę obiektu.
            *
            *  Zmienia nazwę obiektu.
            *  \param[in] sName - nowa nazwa obiektu.
            */
            virtual void SetName(const char* sName) { name = sName; }
            /*!
            * \brief Udostępnia nazwę obiektu.
	        *
	        * Udostępnia nazwę obiektu w trybie tylko do odczytu.
           */
            virtual const std::string & GetName() const { return name; }

    };


#endif