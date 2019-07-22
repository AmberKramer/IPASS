#ifndef TCS3200_HPP
#define TCS3200_HPP 

#include "hwlib.hpp"
#include "frequency.hpp"

/// @file

/// \brief
/// TCS3200 color sensor
/// \details
///
/// This is a Library that makes it easier to use the TCS3200 color sensor.
/// The pins used are stored as pin_in and pin_out, defined by hwlib.

class TCS3200 {   
private:  
   hwlib::pin_out & s0;
   hwlib::pin_out & s1;
   hwlib::pin_out & s2; 
   hwlib::pin_out & s3;
   hwlib::pin_in & out;

public:
   
/// \brief
/// Pin states
/// \details
///
/// The states for the pins are in are saved here. 
/// The pins used for setting the scale are set to 20% unless changed.
   int S0=1;
   int S1=0;
   int S2;
   int S3;

/// \brief
/// Scan results red
/// \details
///
/// This is where the scanned frequency for the red photodiodes is saved.
/// The user can access the result to use it.
   int red;
   
/// \brief
/// Scan results green
/// \details
///
/// This is where the scanned frequency for the green photodiodes is saved.
/// The user can access the result to use it.
   int green;
   
/// \brief
/// Scan results blue
/// \details
///
/// This is where the scanned frequency for the blue photodiodes is saved.
/// The user can access the result to use it.
   int blue;
   
/// \brief
/// Scan results clear
/// \details
///
/// This is where the scanned frequency for the clear photodiodes is saved.
/// The user can access the result to use it.
   int clear;

/// \brief
/// constructor from explicit values
/// \details
/// This constructor initializes the sensor with all the pins needed.
/// The default value for the scan results is 0,
/// so there won't be any magical numbers when asking for the results
/// without scanning.
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

/// \brief
/// Set the scaling
/// \details
///
/// This function sets the scale of the scans that the sensor takes.
/// It sets the scaling by taking the settings you give it when running the fuction.
   void SetScale(int S0, int S1);
   
/// \brief
/// Scan with photodiode
/// \details
///
/// This function scans with a selected photodiode.
/// The photodiode used is selected by putting in 
/// whether the pins used are high high or low.
   int ScanColor(int S2, int S3);
   
/// \brief
/// Scan colors
/// \details
/// This function scans for all 4 types of photodiodes
/// and saves the results in the scan results variables.
/// The results are saved at 20% of the original scan.
   void Scan();
};

#endif // TCS3200_HPP