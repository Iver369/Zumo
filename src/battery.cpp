#include <Arduino.h>

int battery_cap=100;
int power = 0.5; // kan justeres for hvor fort batteriet skal tømmes
int battery_calculator(int speed,int time){
    battery_cap -= abs((speed/time)*power); //enkel formel for å beregne hvor mye det blir igjen på batteriet
    if(battery_cap<=0){
        Serial.println("Du er tom for strøm og bilen stopper");
    }
    else if (battery_cap>15){
        Serial.println("Du er nesten tom for strøm og bør lade");
    }
    else{
        Serial.println("Dette er din batteri prosent:");
        Serial.println(battery_cap);
    }
    return battery_cap;
}