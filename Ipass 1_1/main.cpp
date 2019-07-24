#include "Servo9g.hpp"
#include "TCS3200.hpp"
#include "hwlib.hpp"

enum class kleurtjes {
    none = 0,
    red,
    orange,
    yellow,
    green,
    blue,
    brown,
    };

int main(void){
    namespace target = hwlib::target;
    
    kleurtjes color = kleurtjes::none;
    
    /// Setting up the pins for the sensor
    auto s0 = target::pin_out( target::pins::d22 );
    auto s1 = target::pin_out( target::pins::d24 );
    auto s2 = target::pin_out( target::pins::d26 );
    auto s3 = target::pin_out( target::pins::d29 ); 
    auto out = target::pin_in( target::pins::d2 );
    
    /// Setting up the servo pins
    auto start = target::pin_out( target::pins::d7 );
    auto one = target::pin_out( target::pins::d31 );
    auto two = target::pin_out( target::pins::d32 );
    auto three = target::pin_out( target::pins::d35 );
    auto four = target::pin_out( target::pins::d36 );
    auto five = target::pin_out( target::pins::d39 );
    auto six = target::pin_out( target::pins::d40 );
    
    /// Setting up the servo's
    Servo Chamber(start);
    Servo Red(one);
    Servo Orange(two);
    Servo Yellow(three);
    Servo Green(four);
    Servo Blue(five);
    
    auto button = target::pin_in( target::pins::d3 );
    
    /// Two sensor objects are created. "Sensor" is used to scan the color 
    /// and "base" is used to check the amount of intervening light and to correct for that.
    TCS3200 sensor(s0,s1,s2,s3,out);
    TCS3200 base(s0,s1,s2,s3,out);
    /// Both sensors are set to 20%
    sensor.SetScale(1,0);
    base.SetScale(1,0);
    
    base.Scan();
    hwlib::cout <<"BASE:  R:"<< base.red <<",  G:"<< base.green <<",  B:"<< base.blue <<",   Clear:"<< base.clear << hwlib::endl;
while(true){

    sensor.Scan();
    /// The sensor checks wether there is an m&m in the machine.
    /// If not, a new base scan is made.
    if (sensor.clear < 50){
        base.Scan();
        hwlib::cout <<"BASE:  R:"<< base.red <<",  G:"<< base.green <<",  B:"<< base.blue <<",   Clear:"<< base.clear << hwlib::endl;
    }
    hwlib::cout <<"R:"<< sensor.red <<",  G:"<< sensor.green <<",  B:"<< sensor.blue <<",   Clear:"<< sensor.clear << hwlib::endl;
    
    if(button.read()){
        Chamber.SetPosition(1);
        if (color==kleurtjes::brown || color==kleurtjes::none){
            hwlib::wait_ms(1000);
            Chamber.SetPosition(2);
        }
        else if (color==kleurtjes::red){
            Red.SetPosition(2);
            hwlib::wait_ms(5);
            Chamber.SetPosition(1);
            hwlib::wait_ms(1000);
            Chamber.SetPosition(2);
            hwlib::wait_ms(1000);
            Red.SetPosition(1);
        }
        else if (color==kleurtjes::orange){
            Orange.SetPosition(2);
            hwlib::wait_ms(5);
            Chamber.SetPosition(1);  
            hwlib::wait_ms(1000);
            Chamber.SetPosition(2);
            hwlib::wait_ms(1000);
            Orange.SetPosition(1);
        }
        else if(color==kleurtjes::yellow){
            Yellow.SetPosition(2);
            hwlib::wait_ms(5);
            Chamber.SetPosition(1);
            hwlib::wait_ms(1000);
            Chamber.SetPosition(2);
            hwlib::wait_ms(1000);
            Yellow.SetPosition(1);
        }
        else if(color==kleurtjes::green){
            Green.SetPosition(2);
            hwlib::wait_ms(5);
            Chamber.SetPosition(1);
            hwlib::wait_ms(1000);
            Chamber.SetPosition(2);
            hwlib::wait_ms(1000);
            Green.SetPosition(1);
        }
        else if(color==kleurtjes::blue){
            Blue.SetPosition(2);
            hwlib::wait_ms(5);
            Chamber.SetPosition(1);
            hwlib::wait_ms(1000);
            Chamber.SetPosition(2);
            hwlib::wait_ms(1000);
            Blue.SetPosition(1);
        }
    }
    
    int Rchange = sensor.red-base.red;
    int Gchange = sensor.green-base.green;
    int Bchange = sensor.blue-base.blue;
    
    // Checks if the changes are big enough to not be just small fluctuations. 
    if (Rchange>1 and Gchange>1 and Bchange>1){
    if (Rchange<6){
        hwlib::cout <<"ROY"<< hwlib::endl;
        if (Gchange>=6 and Bchange>5){
            color=kleurtjes::orange;
            hwlib::cout <<"Orange"<< hwlib::endl;
        }
        else if(Gchange>=5 and Bchange<6){
            color=kleurtjes::red;
            hwlib::cout <<"Red"<< hwlib::endl;
        }
        else{
            color=kleurtjes::yellow;
            hwlib::cout <<"Yellow"<< hwlib::endl;
        }
    }else{
        hwlib::cout <<"BGB"<<hwlib::endl;
        if (Gchange>8 and Bchange>6){
            color=kleurtjes::brown;
            hwlib::cout <<"Brown"<< hwlib::endl;
        }
        else if(Gchange<7 and Bchange>5){
            color=kleurtjes::green;
            hwlib::cout <<"Green"<< hwlib::endl;
        }
        else if(Gchange<9 and Bchange<7){
            color=kleurtjes::blue;
            hwlib::cout <<"Blue"<< hwlib::endl;
        }
    }
    }
}
}
