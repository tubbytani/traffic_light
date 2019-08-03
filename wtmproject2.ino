#include <Wire.h> 
#include <Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>
#include<SPI.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int pin1=12;
int pin2=11;
int pot=A8;
int pos2 = 0;    
int val=0;

void setup() {
 
 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 display.display();
 pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
   pinMode(9,OUTPUT);// put your setup code here, to run once:

 pinMode(12,OUTPUT);
 pinMode(11,OUTPUT);
 Serial.begin(9600);

}

void loop() {
  display.clearDisplay();
 display.setTextColor(WHITE);
 display.setCursor(30,32);
  val=analogRead(pot);
  pos2=map(val,0,1023,0,180);
  
  if (val>=0&&val<900)
  { digitalWrite(pin2,LOW);
    digitalWrite(pin1,HIGH);
    display.print("STOP!!");
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
    analogWrite(9,100);
    delay(7000);
    display.display();
    
  }
  else if(val>900)
 {
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
  display.print("GO!");
  digitalWrite(8,LOW);
  digitalWrite(7,HIGH);
  analogWrite(9,100);
  delay(7000);
  display.display();
 }
 

}
