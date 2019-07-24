#ifndef SERVO9G_HPP
#define SERVO9G_HPP 

#include "hwlib.hpp"

/// @file

/// \brief
/// Servo supporting class
/// \details
///
/// This class helps with controlling the servo's by simply setting the servo to one of two positions.
/// It does this by sending a 20 ms wave to the input_pin from the servo.
class Servo {   
private:
   hwlib::pin_out & wave;

public:

/// \brief
/// Position
/// \details
///
/// The variable P is used to set the Position of the servo motor.
   int P;
   
/// \brief
/// Servo constructor
/// \details
///
/// The constructor of the servo sets the servo up with in output pins it needs.
   Servo( 
        hwlib::pin_out & wave
   ):
        wave(wave)
   {}
   
/// \brief
/// Set position
/// \details
///
/// The Set position function sets the servo to the position given by the P(osition) variable.
   void SetPosition(int P);
};

#endif // SERVO9G_HPP