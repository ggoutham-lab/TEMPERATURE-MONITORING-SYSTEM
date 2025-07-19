
#include <Adafruit_LiquidCrystal.h>
int temp = 0;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  lcd_1.begin(16, 2);
}
 
void loop()
{

 // measure the 5v with a meter for an accurate value
 //In particular if your Arduino is USB powered

 float voltage = analogRead(A0) * 4.68;
 voltage /= 1024.0;
 
 // now print out the temperature

 float temp = (voltage - 0.5) * 100;
  Serial.println(temp);
  lcd_1.setCursor(0, 0);
  lcd_1.print("Temp. Monitr. system");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Temp Value=");
  lcd_1.setCursor(12, 1);
  lcd_1.print(temp);
 delay(100);
}
