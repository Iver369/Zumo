#include <display.h>

void displayStartup() {
    static unsigned long previousMillis = 0;
    static int state = 0; 
    unsigned long currentMillis = millis();

switch (state) {
    case 0:
        lcd.clear();
        lcd.gotoXY(0,0);
        lcd.print("Kalibrert");
        previousMillis = currentMillis;
        state = 1;
        break; 
    
    case 1:  
        if (currentMillis - previousMillis >= 1500) {
            lcd.clear();
            lcd.gotoXY(0,0);
            lcd.print("Batteri:");
            lcd.gotoXY(0,1);
            lcd.print(battery_cap);
            lcd.gotoXY(7,1);
            lcd.print("%");
            previousMillis = currentMillis; 
            state = 2; 
        }
        break; 
    case 2:
        if (currentMillis - previousMillis >= 1500) {
            lcd.clear();
            lcd.gotoXY(0,0);
            lcd.print("Klar");
            lcd.gotoXY(0,1);
            lcd.print("til å");
            previousMillis = currentMillis;
            state = 3;
        }
        break;
   
    case 3:
        if (currentMillis - previousMillis >= 500) {
            lcd.gotoXY(0,0);
            lcd.print("KJØRE!");
            previousMillis = currentMillis;
            state = 4;
        }
        break;
    
    case 4:
        if (currentMillis - previousMillis >= 500) {
            lcd.clear();
            state = 5;
        }
        break; 
    }
}