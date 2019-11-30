/* 
 * I leave several functions of Print console in order to Test or Unpack the program.
 * Developed by Slewog during his Codage training at Microbus in 2019.
 * To use the program use a BT terminal with an "On" function that sends '1', "SOS" that sends '2', "Blink" that sends '3', and "Off" that sends '0'.
*/

// Variable for Note.
const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;

#define Pin_Led 2 // Pine variable used for the Led.
#define Pin_Buzzer 4 // Pine used for the Piezzo.
#define BT_Speed 9600 // Adjusting the speed of BT.

char Data_BT = '0'; // Variable which retrieves the value of the transmitter BT and initialization with the value '0'.
const int ledPin1 = 4;
int counter = 0;

void setup()
{
  Serial.begin(BT_Speed); // Frequency Port Com, to enter in the serial monitor for Debug.
  pinMode(Pin_Led, OUTPUT); // Led Pin Settings.
  pinMode(Pin_Buzzer, OUTPUT); // Buzzer Pin Settings.
  tone(Pin_Buzzer, 2500, 500);
}

void loop()
{
  if (Serial.available() > 0){ // Check that Com Port is available
    Data_BT = Serial.read(); // Stock the value of the Com Port.
    //Serial.println(Data_BT); // Print the state of the Variable Data_BT for the Debug mode in the console.
    //Serial.println("I came back to the beginning of the code"); // Print Debug message in the console.

    if (Data_BT == '0'){ // If the value read is 0, start function Off.
      off();
    }
    if (Data_BT == '1'){ // If the value read is 1, start function On.
      on();
    }
    if (Data_BT == '2') { // If the value read is 2, start function S.O.S, otherwise it does not fit in the loop.
      while (Serial.available() == 0){ // As long as we do not receive new values ​​the loop is repeated.
        sos_mode();
      }
      //Serial.println("I came out of the loop S.O.S"); // Print Debug message in the console.
    }
    if (Data_BT == '3') { // If the value read is 3, start function Blink, otherwise it does not fit in the loop.
      while (Serial.available() == 0){ // As long as we do not receive new values ​​the loop is repeated
        blink_mode();
      }
      //Serial.println("I came out of the loop Blink"); // Print Debug message in the console.
    }
    if (Data_BT == '4') { // If the value read is 4, start function Star Wars.
      Serial.println("Song Play"); // Print the state of the lamp in the console.
      StarWars();
    }
  }
}

void on() // Switch the lamp on.
{
  //Serial.println("Lamp on"); // Print the state of the lamp in the console.
  digitalWrite(Pin_Led, HIGH);
}

void off() // Switch the lamp off.
{
  //Serial.println("Lamp off"); // Print the state of the lamp in the console.
  digitalWrite(Pin_Led, LOW);
}

void sos_mode() // Switch the lamp on signal S.O.S
{
  //Serial.println("I am in the loop S.O.S"); // Print Debug message in the console.
  dot(); dash(); dot();
  delay (3000);
}

void blink_mode() // Switch the lamp on mode blink.
{
  //Serial.println("I am in the loop Blink"); // Print the state of the lamp in the console.
  digitalWrite(Pin_Led, HIGH);
  delay (250);
  digitalWrite(Pin_Led, LOW);
  delay (250);
}


void dot() // Letter 'S' of Signal S.O.S
{
  for (int i= 0; i < 3; i++){ // Repeat 3X function
    digitalWrite(Pin_Led, HIGH);
    delay (250);
    digitalWrite(Pin_Led, LOW);
    delay (250);
  }
}

void dash() // Letter 'O' of Signal S.O.S
{
  for (int i= 0; i < 3; i++){ // Repeat 3X function
    digitalWrite(Pin_Led, HIGH);
    delay (1000);
    digitalWrite(Pin_Led, LOW);
    delay (250);
  }
}

void StarWars()
{
  firstSection();
  secondSection();
  variant1();
  delay(500);
  variant2();
  delay(650);
}
 
void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(Pin_Buzzer, note, duration);
  //Play different LED depending on value of 'counter'
  if(counter % 2 == 0)
  {
    digitalWrite(Pin_Led, HIGH);
    delay(duration);
    digitalWrite(Pin_Led, LOW);
  }else
  {
    digitalWrite(Pin_Led, HIGH);
    delay(duration);
    digitalWrite(Pin_Led, LOW);
  }
  //Stop tone on buzzerPin
  noTone(Pin_Buzzer);
  delay(50);
  //Increment counter
  counter++;
}
 
void firstSection()
{
  beep(a, 500);
  beep(a, 500);    
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);  
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
  delay(500);
  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);  
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
  delay(500);
}
 
void secondSection()
{
  beep(aH, 500);
  beep(a, 300);
  beep(a, 150);
  beep(aH, 500);
  beep(gSH, 325);
  beep(gH, 175);
  beep(fSH, 125);
  beep(fH, 125);    
  beep(fSH, 250);
  delay(325);
  beep(aS, 250);
  beep(dSH, 500);
  beep(dH, 325);  
  beep(cSH, 175);  
  beep(cH, 125);  
  beep(b, 125);  
  beep(cH, 250);  
  delay(350);
}

void variant1()
{
  beep(f, 250);  
  beep(gS, 500);  
  beep(f, 350);  
  beep(a, 125);
  beep(cH, 500);
  beep(a, 375);  
  beep(cH, 125);
  beep(eH, 650);
}

void variant2()
{
  beep(f, 250);  
  beep(gS, 500);  
  beep(f, 375);  
  beep(cH, 125);
  beep(a, 500);  
  beep(f, 375);  
  beep(cH, 125);
  beep(a, 650);
}
