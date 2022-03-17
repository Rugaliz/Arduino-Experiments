// Uses a PIR sensor to detect movement, buzzes a buzzer
// Made by Rugaliz



int ledPin_red = 12;       // pin for the red LED
int ledPin_yellow = 8;     // pin for the yellow LED
int ledPin_green = 6;      // pin for the green LED
int inputPin = 2;          // input pin (for PIR sensor)
int pinSpeaker = 4;        //Set up a speaker/buzzer

int val = 0;           // variable for reading the pin status

void setup() {
  pinMode(ledPin_red, OUTPUT);      // declare LED as output
  pinMode(ledPin_yellow, OUTPUT);   
  pinMode(ledPin_green, OUTPUT);    
  pinMode(inputPin, INPUT);         // declare sensor as input
  pinMode(pinSpeaker, OUTPUT);      //declare speaker as output
  Serial.begin(9600);
}


void loop(){

  val = digitalRead(inputPin);          // read input value

  if (val == HIGH) {              // check if the input is HIGH
    digitalWrite(ledPin_green, LOW);    // turn green LED OFF
    digitalWrite(ledPin_yellow, LOW);   // turn yellow LED OFF
    digitalWrite(ledPin_red, HIGH);     // turn LED ON
    digitalWrite(pinSpeaker, HIGH);	// activate speaker
  }
  
  else {
      digitalWrite(pinSpeaker, LOW);	  // turn LED OFF
      digitalWrite(ledPin_red, LOW);      
      digitalWrite(ledPin_yellow, HIGH);  // turn yellow LED ON
      delay(1000);      // Keeps yellow LED blinking while idle
      digitalWrite(ledPin_yellow, LOW); // turn yellow LED OFF      
      delay(500);
      digitalWrite(ledPin_green, HIGH);   // turn green LED ON

  }
  
}
