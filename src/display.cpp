#include <display.h>

void displayStartup() {
    lcd.clear();
    lcd.gotoXY(0,0);
    lcd.print("Kalibrert");
    delay(1500);
    lcd.clear();
    lcd.gotoXY(0,0);
    lcd.print("Batteri:");
    lcd.gotoXY(0,1);
    lcd.print(battery_cap);
    lcd.gotoXY(7,1);
    lcd.print("%");
    delay(1500);
    lcd.clear();
    lcd.gotoXY(0,0);
    lcd.print("Klar");
    lcd.gotoXY(0,1);
    lcd.print("til å");
    delay(500);
    lcd.gotoXY(0,0);
    lcd.print("KJØRE!!");
    delay(500);
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
        lcd.gotoXY(0,1);
        lcd.print(battery_cap);
        lcd.gotoXY(8,1);
        lcd.print("%");

        lcd.gotoXY(0, 0);
        lcd.print("Avstand:");
        lcd.gotoXY(0,1);
        lcd.print(remaining_distance());
        lcd.gotoXY(7,1);
        lcd.print("m");
    }
}

// displayStartup if battery is low/empty, to go charge the battery
// displayStatus if battery is low/empty, to go charge the battery
// displayStatus obstacle distance/collision warning
// displayStatus speed
// displayStatus line sensor readings?
// Or create separate functions for them
