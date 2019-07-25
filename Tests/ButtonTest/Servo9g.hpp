#ifndef SERVO9G_HPP
#define SERVO9G_HPP 

#include "hwlib.hpp"

class Servo {   
private:
   hwlib::pin_out & wave;

//   f freq(out,5);

public:
   int P;

   Servo( 
        hwlib::pin_out & wave
   ):
        wave(wave)
   {}
   void SetPosition(int P);
};

#endif // SERVO9G_HPP