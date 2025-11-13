#include <display.h>

void displayStartup() {
    lcd.clear();
    lcd.gotoXY(0,0);
    lcd.print("Calibration done!");
    delay(1500);
    lcd.clear();
    lcd.gotoXY(0,0);
    lcd.print("Battery: ");
    lcd.print(battery_cap);
    lcd.print("%");
    delay(1500);
    lcd.clear();
    lcd.gotoXY(0,0);
    lcd.print("Ready to drive!");
    delay(1500);
    lcd.clear();
}

void displayStatus() {
    static unsigned long lastUpdate = 0;   
    unsigned long now = millis();        


    if (now - lastUpdate >= 1000) {
        lastUpdate = now;

        lcd.clear();
        lcd.gotoXY(0, 0);
        lcd.print("⚡︎: ");
        lcd.print(battery_cap);
        lcd.print("%");

        lcd.gotoXY(0, 1);
        lcd.print("Range: ");
        lcd.print(remaining_distance());
        lcd.print(" m");
    }
}

// displayStartup if battery is low/empty, to go charge the battery
// displayStatus if battery is low/empty, to go charge the battery
// displayStatus obstacle distance/collision warning
// displayStatus speed
// displayStatus line sensor readings?
// Or create separate functions for them
