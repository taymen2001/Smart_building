/*
 * Arduino Keypad calculator Program
 */
#include <LiquidCrystal.h> //Header file for LCD from https://www.arduino.cc/en/Reference/LiquidCrystal
#include <Keypad.h> //Header file for Keypad from https://github.com/Chris--A/Keypad
#include <Servo.h>
Servo servo;
int angle = 0,x = 0;
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Three columns


// Define the Keymap
char keys[ROWS][COLS] = {

  {'1','2','3','A'},

  {'4','5','6','B'},

  {'7','8','9','C'},

  {'*','0','#','D'}

};

byte rowPins[ROWS] = {9, 8, 7, 6}; // Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = {5, 4, 3, 2};  // Connect keypad COL0, COL1 and COL2 to these Arduino pins.

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //  Create the Keypad

const int buzzer = 10;

const int rs = 19, en = 18, d4 = 17, d5 = 16, d6 = 15, d7 = 14; //Pins to which LCD is connected
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

 long Number;
 char key, action, input, named = '-', push = '-';
 boolean result = false;


void beep(){
  tone(buzzer,1000);
  delay(300);
  noTone(buzzer);
  delay(100);
  tone(buzzer,1000);
  delay(300);
  noTone(buzzer);
  delay(100);
  tone(buzzer,1000);
  delay(300);
  noTone(buzzer);
}
void wrong()
{
  while( x <6)
    {
      lcd.setCursor(3, 0);   // set the cursor to column 0, line 1
  lcd.print("Invalid ID");
    lcd.setCursor(8, 1);
    lcd.print(5-x);
    delay(1000);
    lcd.clear();
    x+=1;
    }      //Display the 
  }
void doorOpen() {
  servo.write(90);
  delay(5);
  int g = 90;
  while (g <= 180){
    delay(60);
     servo.write(g);
     
    g = g + 3;
  }

  
}
void doorClose() {
   
 servo.write(180);
  delay(5);
  int h = 180;
  while ( h >= 90){
      servo.write(h);
      delay(60);
    h = h - 3;
  }
    
}

void setup() {
  Serial.begin(9600);
servo.attach(11);
  servo.write(0);
  lcd.begin(16, 2); //We are using a 16*2 LCD display
  lcd.setCursor(2, 0);
  lcd.print("SwinburneUni"); //Display a intro message
  lcd.setCursor(3, 1);   // set the cursor to column 0, line 1
  lcd.print("Hello ^_^"); //Display a intro message 
pinMode(buzzer,OUTPUT);
   delay(4000); //Wait for display to show info
   lcd.clear(); //Then clean it
    named = '-';
    push = '-';
    Number = 0;
    x = 0;
}

void loop() {
  
key = kpd.getKey(); //storing pressed key value in a char

if (key!=NO_KEY)
DetectButtons();

if (result==false)
DisplayResult();   
}

void DetectButtons()
{ 
     lcd.clear(); //Then clean it
    if (key=='*') //If cancel Button is pressed
    {Number=0; action = '.'; push = '-';input = 'q';result=false;named = '-';}
    if (Number < 999999999)
    {
     if (key == '1') //If Button 1 is pressed
    {
    if (Number==0)
    Number=1;
    else
    Number = (Number*10) + 1; //Pressed twice
    }
    
     if (key == '4') //If Button 4 is pressed
    {
    if (Number==0)
    Number=4;
    else
    Number = (Number*10) + 4; //Pressed twice
    }
    
     if (key == '7') //If Button 7 is pressed
    {
    if (Number==0)
    Number=7;
    else
    Number = (Number*10) + 7; //Pressed twice
    } 
  

    if (key == '0')
    {
    if (Number==0)
    Number=0;
    else
    Number = (Number*10) + 0; //Pressed twice
    }
    
     if (key == '2') //Button 2 is Pressed
    {
     if (Number==0)
    Number=2;
    else
    Number = (Number*10) + 2; //Pressed twice
    }
    
     if (key == '5')
    {
     if (Number==0)
    Number=5;
    else
    Number = (Number*10) + 5; //Pressed twice
    }
    
     if (key == '8')
    {
     if (Number==0)
    Number=8;
    else
    Number = (Number*10) + 8; //Pressed twice
    }   
  

    if (key == '#')
    {
    named = '-';
   if (Number != 0)
   Number = (floor(Number/10));
    }
    
     if (key == '3')
    {
     if (Number==0)
    Number=3;
    else
    Number = (Number*10) + 3; //Pressed twice
    }
    
     if (key == '6')
    {
    if (Number==0)
    Number=6;
    else
    Number = (Number*10) + 6; //Pressed twice
    }
    
     if (key == '9')
    {
    if (Number==0)
    Number=9;
    else
    Number = (Number*10) + 9; //Pressed twice
    }  
    }
      if (key == 'A' || key == 'B' || key == 'C' || key == 'D') //Detecting Buttons on Column 4
  {
    if (key == 'A')
    {
     
      action = 'a';
      named = '-';
      Number = 0;
      push = ',';
    }
     if (key == 'B')
    {
      
      action = 'b'; 
      named = '-';
      Number = 0;
      push = ',';
    }
     if (key == 'C')
    {
      
      action = 'c';
      named = '-';
      Number = 0;
      push = ',';
    }

     if (key == 'D'){
     
     if (action == 'a' or action == 'b' or action == 'c')
    {
     
      named = ',';
      push = ',';
      
      Result();
      
    }
      }  
    delay(100);
  }
  
}

void Result()
{
if (action == 'a'){
    if (Number == 999999){
    input = 'o';
    action = ',';
   lcd.setCursor(0, 0);
  lcd.print("Have a nice day");
  lcd.setCursor(13, 1);   // set the cursor to column 0, line 1
  lcd.print("^_^");//Display the result
  lcd.setCursor(0, 1);
  lcd.print("Tung Nguyen");
  Serial.print(Number);
  Serial.print("\t");
  Serial.println("Tung Nguyen");
  beep();
    doorOpen();
  delay(5000);
  doorClose();
  setup();
    }
    
 else if (Number == 888888){
    input = 'o';
    action = ',';
   lcd.setCursor(0, 0);
  lcd.print("Have a nice day");
  lcd.setCursor(13, 1);   // set the cursor to column 0, line 1
  lcd.print("^_^");//Display the result
  lcd.setCursor(0, 1);
  lcd.print("Dat Nguyen");
  Serial.println(Number);
  Serial.println("Dat Nguyen");
  beep();
    doorOpen();
  delay(5000);
  doorClose();
  setup();
    }

  else if (Number == 799999){
    input = 'o';
    action = ',';
   lcd.setCursor(0, 0);
  lcd.print("Have a nice day");
  lcd.setCursor(13, 1);   // set the cursor to column 0, line 1
  lcd.print("^_^");//Display the result
  lcd.setCursor(0, 1);
  lcd.print("Oanh Tran");
  Serial.println(Number);
  Serial.println("Oanh Tran");
  beep();
    doorOpen();
  delay(5000);
  doorClose();
  setup();
    }

   else if (Number == 777777){
    input = 'o';
    action = ',';
   lcd.setCursor(0, 0);
  lcd.print("Have a nice day");
  lcd.setCursor(13, 1);   // set the cursor to column 0, line 1
  lcd.print("^_^");//Display the result
  lcd.setCursor(0, 1);
  lcd.print("Duc Le");
  Serial.println(Number);
  Serial.print("Duc_Le");
  beep();
   doorOpen();
  delay(5000);
  doorClose();
  setup();
    }
    else{
    input = 'x';
    action = ',';
    wrong();
    setup();
    }
}
if (action == 'b'){
    if (Number == 699999){
    input = 'o';
    action = ',';
   lcd.setCursor(0, 0);
  lcd.print("Have a nice day");
  lcd.setCursor(13, 1);   // set the cursor to column 0, line 1
  lcd.print("^_^");//Display the result
  lcd.setCursor(0, 1);
  lcd.print("Ha Hoang");
  Serial.println(Number);
  Serial.println("Ha Hoang");
  beep();
    doorOpen();
  delay(5000);
  doorClose();
  setup();
    }

    else if (Number == 666666){
    input = 'o';
    action = ',';
   lcd.setCursor(0, 0);
  lcd.print("Have a nice day");
  lcd.setCursor(13, 1);   // set the cursor to column 0, line 1
  lcd.print("^_^");//Display the result
  lcd.setCursor(0, 1);
  lcd.print("Duan Truong");
  Serial.println(Number);
  Serial.println("Duan Truong");
  beep();
    doorOpen();
  delay(5000);
  doorClose();
  setup();
    }

   else if (Number == 555555){
    input = 'o';
    action = ',';
   lcd.setCursor(0, 0);
  lcd.print("Have a nice day");
  lcd.setCursor(13, 1);   // set the cursor to column 0, line 1
  lcd.print("^_^");//Display the result
  lcd.setCursor(0, 1);
  lcd.print("Minh Bui");
  Serial.println(Number);
  Serial.println("Minh Bui");
  beep();
    doorOpen();
  delay(5000);
  doorClose();
  setup();
    }

   else if (Number == 444444){
    input = 'o';
    action = ',';
   lcd.setCursor(0, 0);
  lcd.print("Have a nice day");
  lcd.setCursor(13, 1);   // set the cursor to column 0, line 1
  lcd.print("^_^");//Display the result
  lcd.setCursor(0, 1);
  lcd.print("Thuy Pham");
  Serial.println(Number);
  Serial.println("Thuy Pham");
  beep();
    doorOpen();
  delay(5000);
  doorClose();
  setup();
    }
    else{
    input = 'x';
    action = ',';
    wrong();
    setup();
    }
}
if (action == 'c'){
    if (Number == 399999){
    input = 'o';
    action = ',';
   lcd.setCursor(0, 0);
  lcd.print("Have a nice day");
  lcd.setCursor(13, 1);   // set the cursor to column 0, line 1
  lcd.print("^_^");//Display the result
  lcd.setCursor(0, 1);
  lcd.print("Lam Nguyen");
  Serial.println(Number);
  Serial.println("Lam Nguyen");
  beep();
    doorOpen();
  delay(5000);
  doorClose();
  setup();
    }

   else if (Number == 333333){
    input = 'o';
    action = ',';
   lcd.setCursor(0, 0);
  lcd.print("Have a nice day");
  lcd.setCursor(13, 1);   // set the cursor to column 0, line 1
  lcd.print("^_^");//Display the result
  lcd.setCursor(0, 1);
  lcd.print("Hoang Nguyen");
  Serial.println(Number);
  Serial.println("Hoang Nguyen");
  beep();
    doorOpen();
  delay(5000);
  doorClose();
  setup();
    }

   else if (Number == 299999){
    input = 'o';
    action = ',';
   lcd.setCursor(0, 0);
  lcd.print("Have a nice day");
  lcd.setCursor(13, 1);   // set the cursor to column 0, line 1
  lcd.print("^_^");//Display the result
  lcd.setCursor(0, 1);
  lcd.print("Quang Hoang");
  Serial.println(Number);
  Serial.println("Quang Hoang");
  beep();
    doorOpen();
  delay(5000);
  doorClose();
  setup();
    }

   else if (Number == 222222){
    input = 'o';
    action = ',';
   lcd.setCursor(0, 0);
  lcd.print("Have a nice day");
  lcd.setCursor(13, 1);   // set the cursor to column 0, line 1
  lcd.print("^_^");//Display the result
  lcd.setCursor(0, 1);
  lcd.print("Huy Nguyen");
  Serial.println(Number);
  Serial.println("Huy Nguyen");
  beep();
    doorOpen();
  delay(5000);
  doorClose();
  setup();
    }

   else if (Number == 111111){
    input = 'o';
    action = ',';
   lcd.setCursor(0, 0);
  lcd.print("Have a nice day");
  lcd.setCursor(13, 1);   // set the cursor to column 0, line 1
  lcd.print("^_^");//Display the result
  lcd.setCursor(0, 1);
  lcd.print("Minh Ho");
  Serial.println(Number);
  Serial.println("Minh Ho");
  beep();
    doorOpen();
  delay(5000);
  doorClose();
  setup();
    }
    else{
    input = 'x';
    action = ',';
    wrong();
    setup();
    }
}

}

void DisplayResult()
{
  if (action == ','){
    lcd.setCursor(0, 0);   // set the cursor to column 0, line 1
  lcd.print("");
  }
  if (action == 'a'){
  lcd.setCursor(4, 0);   // set the cursor to column 0, line 1
  lcd.print("Teacher");}
  else if (action == 'b'){
  lcd.setCursor(5, 0); 
  lcd.print("Staff");}
  else if (action == 'c'){
  lcd.setCursor(4, 0);
  lcd.print("Student");}
  
  if (result==true)
  {} //Display the result
  if (named == '-'){
  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1
  lcd.print(Number); //Display the result
  }
  if (push == '-'){
  lcd.setCursor(3, 0);   // set the cursor to column 0, line 1
  lcd.print("Push A-B-C");
  }
}
