/* 
 * I leave several functions of Print console in order to Test or Unpack the program.
 * Developed by Slewog during his Codage training at Microbus in 2019.
 * To use the program use a BT terminal with an "On" function that sends '1', "SOS" that sends '2', "Blink" that sends '3',"Star Wars" that sends '4', Dragon Ball that sends '5' and "Off" that sends '0'.
*/

// Setup Pin and BT
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

// Variable for Note for Dragon Ball song realised by Sebastian Cuenca.
int tempo = 170; // Playback speed
int length = 191; // Number of notes (including spaces)                                                              
char notes[] = "cgfgegdg ggefgagfed eecdefedc=0 00caggcdefedcdcc=cde !BAGFEDC ccccc-9-c- -------989-9 99998888668468 99-ccccccc-9-c---cddr-989 9-98888gfffrdrcdrrcrrcr rfrdcc-8--8-- 8-cddrcddrc cgfffrfg"; // Reproduction of the tone, each space represents a break
float beats[] = {4,1,1,1,1,1,1,1,1, 2,2,1,1,1,1,2,1,2,2,1, 2,2,1,1,1,1,2,1,2,2,2,1, 1,1,2,2,2,1,3,1,1,2, 2,2,2,3,2,2,1,8,8,2,1, 2,2,2,2,2,2,2,4,1, 1,1,1,1,2,1,2,1,2,3,1, 1,1,1,1,1,1,1,1,2,1,2,3,1, 1,2,2,1,2,1,2,2,1,2,2,1,2,6,1, 1,1,1,4,1,1,1,1,1,2,1,2, 1,2,3,1,2,2,1,3,1,2,2,1,6,1, 1,1,1,2,2,1,2,2,1,4,1, 1,1,6,2,2,1,2,1,1,2,1,3,1, 1,1,1,1,1,1,2,1,1,2,1,1,2,1, 1,1,2,1,3,1,5,1,1,2,1,1, 1,2,3,1,1,1,1,10}; //Duration of each note
//                        0                 1                       2                      3                     4                     5                     6                         7                             8                       9                               10                        11                        12                        13                         14                      15                                                                                        

void setup()
{
  Serial.begin(BT_Speed); // Frequency Port Com, to enter in the serial monitor for Debug.
  pinMode(Pin_Led, OUTPUT); // Led Pin Settings.
  pinMode(Pin_Buzzer, OUTPUT); // Buzzer Pin Settings.
  tone(Pin_Buzzer, 2500, 500); // Bip for end of the setup.
}

void loop()
{
  // Check that Com Port is available and bigger than 0.
  if (Serial.available() > 0){ 
    // Stock the value of the Com Port.
    Data_BT = Serial.read();
    // Print the state of the Variable Data_BT for the Debug mode in the console.
    //Serial.println(Data_BT);
    // Print Debug message in the console.
    //Serial.println("I came back to the beginning of the code"); 

    if (Data_BT == '0'){ // If the value read is 0, start function Off.
      off();
    }
    if (Data_BT == '1'){ // If the value read is 1, start function On.
      on();
    }
    if (Data_BT == '2') { // If the value read is 2, start function S.O.S, otherwise it does not fit in the loop.
      // Print the state of the lamp in the console.
      Serial.println("S.O.S Mode");
      // As long as we do not receive new values ​​the loop is repeated.
      while (Serial.available() == 0){ 
        sos_mode();
      }
      //Serial.println("I came out of the loop S.O.S"); // Print Debug message in the console.
    }
    if (Data_BT == '3') { // If the value read is 3, start function Blink, otherwise it does not fit in the loop.
      // Print the state of the lamp in the console.
      Serial.println("Blink Mode");
      // As long as we do not receive new values ​​the loop is repeated.
      while (Serial.available() == 0){
        blink_mode();
      }
      //Serial.println("I came out of the loop Blink"); // Print Debug message in the console.
    }
    if (Data_BT == '4') { // If the value read is 4, start function Star Wars.
      // Print the state of the lamp in the console.
      Serial.println("Song Star Wars Play"); 
      StarWars();
    }
    if (Data_BT == '5') { // If the value read is 5, start function Dragon Ball.
      // Print the state of the lamp in the console.
      Serial.println("Song Dragon Ball Play");
      DragonBall();
    }
  }
}

// ---------------------------------- The functions called in the loop ----------------------------------
void on() // Switch the lamp on.
{
  // Print the state of the lamp in the console.
  Serial.println("Lamp on"); 
  digitalWrite(Pin_Led, HIGH);
}

void off() // Switch the lamp off.
{
  // Print the state of the lamp in the console.
  Serial.println("Lamp off"); 
  digitalWrite(Pin_Led, LOW);
}

void blink_mode() // Switch the lamp on mode blink.
{
  // Print the state of the lamp in the console.
  //Serial.println("I am in the loop Blink");
  digitalWrite(Pin_Led, HIGH);
  delay (250);
  digitalWrite(Pin_Led, LOW);
  delay (250);
}

void sos_mode() // Switch the lamp on signal S.O.S
{
  // Print Debug message in the console.
  //Serial.println("I am in the loop S.O.S"); 
  dot(); dash(); dot();
  delay (3000);
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

//---------------------------------- Star Wars Song ----------------------------------
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

// ---------------------------------- Dragon Ball Song ----------------------------------
void DragonBall() 
{
  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
  }
    // pause between notes
    delay(tempo / 2); 
  }
}

void playTone(int ton1, int duration) 
{
  for (long i = 0; i < duration * 1000L; i += ton1) { 
    tone(Pin_Buzzer, ton1);   
    delayMicroseconds(ton1);
  }
  noTone(Pin_Buzzer);
}

void playNote(char note, int duration) 
{
//                        c    c#   d    d#   e    f    f#   g    g#   a    a#   b             d#                  g#              a#           D#                   G#        A#
  char names[] = { ' ',  '!', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 'c', 'd', 'r', 'e', 'f', 'g', 'S',  'a', 'b','s','C', 'D', 'R', 'E', 'F', 'G', 'O', 'A', 'o', 'B', 'i', 'N', 'R', 'u',  '1', 'L', 'k'}; // Musical notes
  int tones[] =  {   0, 1046, 138, 146, 155, 164, 174, 184, 195, 207, 220, 233, 246, 261, 293, 311, 329, 349, 391, 415, 440, 493, 466 ,523, 587, 622, 659, 698, 783, 831,880, 932, 987, 466, 740, 622, 415, 1046, 622u, 227}; // Frequency of each note
  // Playing note by note vector notes[]
  for (int i = 0; i < 40; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}
