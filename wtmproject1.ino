#include <Wire.h> 
#include <Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>
#include<SPI.h>
#include<Servo.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Servo servo;
int pin1=12;
int pin2=11;
int pot=A8;
int pos2=0;    
int val=0;

void setup() {
 servo.attach(9);
 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 display.display();
 pinMode(A8,INPUT);
 pinMode(12,OUTPUT);
 pinMode(11,OUTPUT);
 Serial.begin(9600);

}

void loop() {
  display.clearDisplay();
 display.setTextColor(WHITE);
 display.setCursor(30,32);
  val=analogRead(pot);
  Serial.println(val);
  pos2=map(val,0,1023,0,180);
  servo.write(pos2);
  
  if (val>=0&&val<900)
  { digitalWrite(pin2,LOW);
    digitalWrite(pin1,HIGH);
    display.print("STOP!!");
    display.display();  
  }
 
 else if(val>900)
 {
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
  display.print("GO!");
  display.display();
 }
 

}
