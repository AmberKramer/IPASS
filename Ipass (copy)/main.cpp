#include "Servo9g.hpp"
#include "TCS3200.hpp"
#include "hwlib.hpp"

int main(void){
    int color=0;
    namespace target = hwlib::target;
    auto s0 = target::pin_out( target::pins::d22 );
    auto s1 = target::pin_out( target::pins::d24 );
    auto s2 = target::pin_out( target::pins::d26 );
    auto s3 = target::pin_out( target::pins::d29 ); 
    auto out = target::pin_in( target::pins::d2 );
    
    auto start = target::pin_out( target::pins::d7 );
    auto one = target::pin_out( target::pins::d31 );
    auto two = target::pin_out( target::pins::d32 );
    auto three = target::pin_out( target::pins::d35 );
    auto four = target::pin_out( target::pins::d36 );
    auto five = target::pin_out( target::pins::d39 );
    auto six = target::pin_out( target::pins::d40 );
    
    Servo Chamber(start);
    Servo Red(one);
    Servo Orange(two);
    Servo Yellow(three);
    Servo Green(four);
    Servo Blue(five);
    
    auto button = target::pin_in( target::pins::d3 );
    
    TCS3200 sensor(s0,s1,s2,s3,out);
    TCS3200 base(s0,s1,s2,s3,out);
    sensor.SetScale(1,0);
    base.SetScale(1,0);
    
    base.Scan();
    hwlib::cout <<"BASE:  R:"<< base.red <<",  G:"<< base.green <<",  B:"<< base.blue <<",   Clear:"<< base.clear << hwlib::endl;
while(true){

    sensor.Scan();
    if (sensor.clear < 50){
        base.Scan();
        hwlib::cout <<"BASE:  R:"<< base.red <<",  G:"<< base.green <<",  B:"<< base.blue <<",   Clear:"<< base.clear << hwlib::endl;
    }
    hwlib::cout <<"R:"<< sensor.red <<",  G:"<< sensor.green <<",  B:"<< sensor.blue <<",   Clear:"<< sensor.clear << hwlib::endl;
    if(button.read()==1){
        Chamber.SetPosition(1);
        if (color==0){
            hwlib::wait_ms(1000);
            Chamber.SetPosition(2);
        }
        else if (color==1){
            Red.SetPosition(2);
            hwlib::wait_ms(5);
            Chamber.SetPosition(1);
            hwlib::wait_ms(1000);
            Chamber.SetPosition(2);
            hwlib::wait_ms(1000);
            Red.SetPosition(1);
        }
        else if (color==2){
            Orange.SetPosition(2);
            hwlib::wait_ms(5);
            Chamber.SetPosition(1);
            hwlib::wait_ms(1000);
            Chamber.SetPosition(2);
            hwlib::wait_ms(1000);
            Orange.SetPosition(1);
        }
        else if(color==3){
            Yellow.SetPosition(2);
            hwlib::wait_ms(5);
            Chamber.SetPosition(1);
            hwlib::wait_ms(1000);
            Chamber.SetPosition(2);
            hwlib::wait_ms(1000);
            Yellow.SetPosition(1);
        }
        else if(color==4){
            Green.SetPosition(2);
            hwlib::wait_ms(5);
            Chamber.SetPosition(1);
            hwlib::wait_ms(1000);
            Chamber.SetPosition(2);
            hwlib::wait_ms(1000);
            Green.SetPosition(1);
        }
        else if(color==5){
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
    
    if (Rchange>1 and Gchange>1 and Bchange>1){
    if (Rchange<6){
        hwlib::cout <<"ROY"<< hwlib::endl;
        if (Gchange>=6 and Bchange>5){
            color=2;
            hwlib::cout <<"Orange"<< hwlib::endl;
        }else if(Gchange>=5 and Bchange<6){
            color=1;
            hwlib::cout <<"Red"<< hwlib::endl;
        }else{
            color=3;
            hwlib::cout <<"Yellow"<< hwlib::endl;
        }
    }else{
        hwlib::cout <<"BGB"<<hwlib::endl;
        if (Gchange>8 and Bchange>6){
            color=0;
            hwlib::cout <<"Brown"<< hwlib::endl;
        }else if(Gchange<7 and Bchange>5){
            color=4;
            hwlib::cout <<"Green"<< hwlib::endl;
        }else if(Gchange<9 and Bchange<7){
            color=5;
            hwlib::cout <<"Blue"<< hwlib::endl;
        }
    }
    }
}
}
