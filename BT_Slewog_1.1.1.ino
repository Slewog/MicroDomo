/* 
 * I leave several functions of Print console in order to Test or Unpack the program.
 * Developed by Slewog during his Codage training at Microbus in 2019.
 * To use the program use a BT terminal with an "On" function that sends '1', "SOS" that sends '2', "Blink" that sends '3', and "Off" that sends '0'.
*/

#define Pin_Bulb 2 // Pine variable used for the bulb.
#define BT_Speed 9600 // Adjusting the speed of

char Data_BT = '0'; // Variable which retrieves the value of the transmitter BT and initialization with the value '0'.

void setup()
{
  Serial.begin(BT_Speed); // Frequency Port Com, to enter in the serial monitor for Debug.
  pinMode(Pin_Bulb, OUTPUT); // Bulb Pin Settings.
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
    if (Data_BT == '1'){ // If the value read is , start function On..
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
  }
}

void on() // Switch the lamp on.
{
  //Serial.println("Lamp on"); // Print the state of the lamp in the console.
  digitalWrite(Pin_Bulb, HIGH);
}

void off() // Switch the lamp off.
{
  //Serial.println("Lamp off"); // Print the state of the lamp in the console.
  digitalWrite(Pin_Bulb, LOW);
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
  digitalWrite(Pin_Bulb, HIGH);
  delay (175);
  digitalWrite(Pin_Bulb, LOW);
  delay (175);
}

void dot() // Letter 'S' of Signal S.O.S
{
  for (int i= 0; i < 3; i++){ // Repeat 3X function
    digitalWrite(Pin_Bulb, HIGH);
    delay (250);
    digitalWrite(Pin_Bulb, LOW);
    delay (250);
  }
}

void dash() // Letter 'O' of Signal S.O.S
{
  for (int i= 0; i < 3; i++){ // Repeat 3X function
    digitalWrite(Pin_Bulb, HIGH);
    delay (1000);
    digitalWrite(Pin_Bulb, LOW);
    delay (250);
  }
}
