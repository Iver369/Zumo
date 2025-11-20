#include <display.h>

int BatteryTimer=6000;
int DistanceTimer=3000;
int Timerstate=BatteryTimer;

void displayStartup() {
    lcd.clear();
    lcd.gotoXY(0,0);
    lcd.print("Kalibr-");
    lcd.gotoXY(0,1);
    lcd.print("ering");
}

void displayStatus() {
    static unsigned long lastChangeDisplay = 0;
    static bool showingBattery = true;
    unsigned long nowDisplay = millis();

    // Bytt visning hvert 3 sekund
    if (nowDisplay - lastChangeDisplay >= Timerstate) {
        lastChangeDisplay = nowDisplay;
        showingBattery = !showingBattery;
        if (Timerstate==BatteryTimer) {
            Timerstate=DistanceTimer;
        }
        else if (Timerstate==DistanceTimer) {
            Timerstate=BatteryTimer;
        } 
        lcd.clear();
    }
    if (showingBattery) {
            //  Batteri-visning
            lcd.gotoXY(0, 0);
            lcd.print("Batteri:");

            lcd.gotoXY(0, 1);
            lcd.print(battery_cap);
            lcd.gotoXY(7, 1);
            lcd.print("%");

    } else {
            //  Avstands-visning
            lcd.gotoXY(0, 0);
            lcd.print("Avstand:");
            lcd.gotoXY(0, 1);
            lcd.print(remaining_distance());
            lcd.gotoXY(7, 1);
            lcd.print("m");
            }
        
    }

