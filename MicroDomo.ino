/* 
 * I leave several functions of Print console in order to Test or Unpack the program.
 * Developed by Slewog during his Codage training at Microbus in 2019.
 * To use the program use a BT terminal with an "On" function that sends '1', "SOS" that sends '2', "Blink" that sends '3',"Star Wars" that sends '4' and "Off" that sends '0' or install my APK "Micro_Domo".
 * If you have a piezo to use the song functions, connect it to pin 4 and to a GND.
*/

// Settings
#define Pin_Led 2 // Pine variable used for the Led.
#define Pin_Buzzer 4 // Pine used for the Piezzo.
#define BT_Speed 9600 // Adjusting the speed of BT.
char Data_BT = '0'; // Variable which retrieves the value of the transmitter BT and initialization with the value '0'.

// Variable for Note for Star Wars song.
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
int counter = 0;

void setup()
{
  Serial.begin(BT_Speed); // Frequency Port Com, to enter in the serial monitor for Debug.
  pinMode(Pin_Led, OUTPUT); // Led Pin Settings.
  pinMode(Pin_Buzzer, OUTPUT); // Buzzer Pin Settings.
  tone(Pin_Buzzer, 2500, 500); // Bip for end of the setup.
}

void loop()
{
  // Repeat as long as the serial port is 0.
  while (Serial.available() == 0){
    delay(50);
    return_state_lamp();
  }
  // Check that Com Port is available and bigger than 0.
  if (Serial.available() > 0){ 
    // Stock the value of the Com Port.
    Data_BT = Serial.read();
    // If the value read is 0, switch "OFF" the lamp.
    if (Data_BT == '0'){
      digitalWrite(Pin_Led, LOW);
    }
    // If the value read is 1, switch "ON" the lamp.
    if (Data_BT == '1'){
      digitalWrite(Pin_Led, HIGH);
    }
    // If the value read is 2, start function S.O.S.
    if (Data_BT == '2') {
      delay(250);
      // As long as we do not receive new values ​​the loop is repeated.
      while (Serial.available() == 0){ 
        sos_mode();
      }
    }
    // If the value read is 3, start function Blink.
    if (Data_BT == '3') {
      delay(250);
      // As long as we do not receive new values ​​the loop is repeated.
      while (Serial.available() == 0){
        blink_mode();
      }
    }
    // If the value read is 4, start function Star Wars.
    if (Data_BT == '4') {
      delay(250);
      StarWars();
    }
  }
}

// ---------------------------------- The functions called in the loop ----------------------------------

// Returns the status of the lamp to the application once it is connected to it.
void return_state_lamp()
{
  Serial.println(Data_BT);
}

// Activate the flashing mode.
void blink_mode()
{
  return_state_lamp();
  digitalWrite(Pin_Led, HIGH);
  delay (250);
  digitalWrite(Pin_Led, LOW);
  delay (250);
}

// Activate the S.O.S mode.
void sos_mode()
{
  dot(); dash(); dot();
  delay (3000);
}

// Letter 'S' of Signal S.O.S.
void dot() 
{
  return_state_lamp();
  // Repeat 3 time this loop.
  for (int i= 0; i < 3; i++){ 
    digitalWrite(Pin_Led, HIGH);
    delay (250);
    digitalWrite(Pin_Led, LOW);
    delay (250);
  }
}

// Letter 'O' of Signal S.O.S.
void dash() 
{
  return_state_lamp();
  // Repeat 3 time this loop.
  for (int i= 0; i < 3; i++){
    digitalWrite(Pin_Led, HIGH);
    delay (1000);
    digitalWrite(Pin_Led, LOW);
    delay (250);
  }
}

//---------------------------------- Star Wars Song ----------------------------------

// Activate the Star Wars song.
void StarWars()
{
  firstSection();
  secondSection();
  variant1();
  delay(500);
  variant2();
  delay(650);
  Data_BT = '0'; // We reset Data_BT to 0 to indicate to the app that the songs are finished.
}
 
void beep(int note, int duration)
{
  return_state_lamp();
  //Play tone on buzzerPin
  tone(Pin_Buzzer, note, duration);
  //Play LED depending on value of 'counter'
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
