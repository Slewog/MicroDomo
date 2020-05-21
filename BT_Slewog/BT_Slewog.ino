/* 
 * I leave several functions of Print console in order to Test or Unpack the program.
 * Developed by Slewog during his Codage training at Microbus in 2019.
 * To use the program use a BT terminal with an "On" function that sends '1', "SOS" that sends '2', "Blink" that sends '3' and "Off" that sends '0' or install my apk "Micro_BT".
*/

// Setup Pin and BT
#define Pin_Led 2 // Pine variable used for the Led.
#define BT_Speed 9600 // Adjusting the speed of BT.
char Data_BT = '0'; // Variable which retrieves the value of the transmitter BT and initialization with the value '0'.

void setup()
{
  Serial.begin(BT_Speed); // Frequency Port Com, to enter in the serial monitor for Debug.
  pinMode(Pin_Led, OUTPUT); // Led Pin Settings.
}

void loop()
{
  // Check that Com Port is available and bigger than 0.
  if (Serial.available() > 0){ 
    // Stock the value of the Com Port.
    Data_BT = Serial.read();
    // Returns the lamp status to the application.
    Serial.println(Data_BT);

    if (Data_BT == '0'){ // If the value read is 0, start function Off.
      off();
    }
    if (Data_BT == '1'){ // If the value read is 1, start function On.
      on();
    }
    if (Data_BT == '2') { // If the value read is 2, start function S.O.S, otherwise it does not fit in the loop.
      // As long as we do not receive new values ​​the loop is repeated.
      while (Serial.available() == 0){ 
        sos_mode();
      }
    }
    if (Data_BT == '3') { // If the value read is 3, start function Blink, otherwise it does not fit in the loop.
      // As long as we do not receive new values ​​the loop is repeated.
      while (Serial.available() == 0){
        blink_mode();
      }
    }
  }
}

// ---------------------------------- The functions called in the loop ----------------------------------
void on() // Switch the lamp on.
{
  digitalWrite(Pin_Led, HIGH);
}

void off() // Switch the lamp off.
{
  digitalWrite(Pin_Led, LOW);
}

void blink_mode() // Switch the lamp on mode blink.
{
  digitalWrite(Pin_Led, HIGH);
  delay (250);
  digitalWrite(Pin_Led, LOW);
  delay (250);
}

void sos_mode() // Switch the lamp on signal S.O.S
{
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
