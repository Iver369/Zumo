#include <display.h>

void display(){
    lcd.clear();
    delay(1000);
    lcd.gotoXY(2,1);
    lcd.print("Hei");
    delay(5000);
    lcd.clear();
}

