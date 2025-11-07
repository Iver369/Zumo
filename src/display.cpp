void setup(){
    lcd.clear();
    delay(1000);
    lcd.gotoXY(0,0);
    lcd.print("Hei");
    delay(5000);
    lcd.clear();
}

void loop(){
    lcd.gotoXY(0,0);
    lcd.print("Hade");
}

