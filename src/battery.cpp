#include <Arduino.h>

int batteri_cap=100;
int speed = 4; //må hentes inn i main kode
int strøm = 0.5; // kan justeres for hvor fort batteriet skal tømmes
int time = 1; // kan kjøre koden hvert sekund eller så må vi telle tiden bilen kjører
void battery_calculator(){
    batteri_cap= batteri_cap-((speed/time)*strøm); //enkel formel for å beregne hvor mye det blir igjen på batteriet
    if(batteri_cap<=0){
        Serial.println("Du er tom for strøm og bilen stopper");
    }
    else if (batteri_cap>15){
        Serial.println("Du er nesten tom for strøm og bør lade");
    }
    else{
        Serial.println("Dette er din batteri prosent:");
        Serial.println(batteri_cap);
    }
}