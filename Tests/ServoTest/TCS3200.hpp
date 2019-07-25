#ifndef TCS3200_HPP
#define TCS3200_HPP 

#include "hwlib.hpp"
#include "frequency.hpp"

class TCS3200 {   
private:
   hwlib::pin_out & s0;
   hwlib::pin_out & s1;
   hwlib::pin_out & s2; 
   hwlib::pin_out & s3;
   hwlib::pin_in & out;

//   f freq(out,5);

public:
   
   int S0=1;
   int S1=0;
   int S2;
   int S3;

   int red;
   int green;
   int blue;
   int clear;

   TCS3200( 
        hwlib::pin_out & s0,
        hwlib::pin_out & s1,
        hwlib::pin_out & s2,
        hwlib::pin_out & s3,
        hwlib::pin_in & out
   ):
        s0(s0),
        s1(s1),
        s2(s2),
        s3(s3),
        out(out),
        red(0),
        green(0),
        blue(0),
        clear(0)
   {}
   void SetScale(int S0, int S1);
   int ScanColor(int S2, int S3);
   void Scan();
};

#endif // TCS3200_HPP