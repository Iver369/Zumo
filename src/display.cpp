#include <display.h>

void display(){
    lcd.clear();
    delay(1000);
    lcd.gotoXY(1,0);
    lcd.print("Battertistatus:");
    delay(5000);
    lcd.clear();
}

