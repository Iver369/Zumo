#include <display.h>

void displayStartup() {
    lcd.clear();
    lcd.gotoXY(0,0);
    lcd.print("Kalib-");
    lcd.gotoXY(0,1);
    lcd.print("rering");
}

void displayStatus() {
    static unsigned long lastChangeDisplay = 0;
    static bool showingBattery = true;
    unsigned long nowDisplay = millis();

    // Bytt visning hvert 3 sekund
    if (nowDisplay - lastChangeDisplay >= 3000) {
        lastChangeDisplay = nowDisplay;
        showingBattery = !showingBattery;
        lcd.clear();
    }
    if (showingBattery) {
            // ⚡ Batteri-visning
            lcd.gotoXY(0, 0);
            lcd.print("Batteri:");

            lcd.gotoXY(0, 1);
            lcd.print(battery_cap);
            lcd.gotoXY(7, 1);
            lcd.print("%");

    } else {
            // 📏 Avstands-visning
            lcd.gotoXY(0, 0);
            lcd.print("Avstand:");
            lcd.gotoXY(0, 1);
            lcd.print(remaining_distance());
            lcd.gotoXY(7, 1);
            lcd.print("m");
            }
        
    }

