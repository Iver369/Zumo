#include <display.h>

void display(){
    lcd.clear();
    delay(1000);
    lcd.gotoXY(0,0);
    lcd.print("Batterti");
    lcd.gotoXY(0,1);
    lcd.print("-status:");
    delay(5000);
    lcd.clear();
}

