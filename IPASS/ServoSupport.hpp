#ifndef SERVOSUPPORT_HPP
#define SERVOSUPPORT_HPP 

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
   hwlib::pin_out & servoInput;

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
/// The constructor of the servo sets the servo up with the output pins it needs (input for the servo).
   Servo( 
        hwlib::pin_out & servoInput
   ):
        servoInput(servoInput)
   {}
   
/// \brief
/// Set position
/// \details
///
/// The Set position function sets the servo to the position given by the P(osition) variable.
   void SetServoPosition(int P);
};

#endif // SERVOSUPPORT_HPP