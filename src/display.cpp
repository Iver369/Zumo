#include <display.h>

int BatteryTimer=6000;
int DistanceTimer=3000;
int Timerstate=BatteryTimer;

void displayStartup() {
    display.clear();
    display.setLayout21x8();
    display.gotoXY(0,0);
    display.print("Kalibr-");
    display.gotoXY(0,1);
    display.print("ering");
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
        display.clear();
    }
    if (showingBattery) {
            //  Batteri-visning
            display.gotoXY(0, 0);
            display.print("Batteri:");

            display.gotoXY(0, 1);
            display.print(battery_cap);
            display.gotoXY(7, 1);
            display.print("%");

    } else {
            //  Avstands-visning
            display.gotoXY(0, 0);
            display.print("Avstand:");
            display.gotoXY(0, 1);
            display.print(remaining_distance());
            display.gotoXY(7, 1);
            display.print("m");
            }
        
    }

