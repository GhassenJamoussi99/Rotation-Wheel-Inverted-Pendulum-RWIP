//const uint16_t BLINK_INTERVAL = 500;  // Time interval between toggling LED1 in milliseconds
//const uint8_t GREEN_LED = 13;         // GREEN_LED is connected to D13
//const uint8_t YELLOW_LED = 12;        // YELLOW_LED is connected to D12
//const uint8_t RED_LED = 11;           // RED_LED is connected to D11
const uint8_t SW1 = 22;               // SW1 is connected to D10
const uint8_t SW2 = 24; 
const uint8_t SW3 = 26;             // SW2 is connected to D9

enum states {                         // Define enumerated type for state machine states
  WP, 
  P1, 
  P2,
  BP 
};
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
states state;                         // Global variable to store current state
uint32_t wp_time;                 // Global variable to store the time that YELLOW_LED last changed state
uint16_t wp_count;                // Global variable to store the number of times YELLOW_LED has changed 
                                      //   states

void setup() {
  //pinMode(GREEN_LED, OUTPUT);         // Configure GREEN_LED pin as a digital output
  //pinMode(YELLOW_LED, OUTPUT);        // Configure YELLOW_LED pin as a digital output
  //pinMode(RED_LED, OUTPUT);           // Configure RED_LED pin as a digital output
  pinMode(SW1, INPUT);                // Configure SW1 pin as a digital input
  pinMode(SW2, INPUT);                // Configure SW2 pin as a digital input
  
  //digitalWrite(GREEN_LED, HIGH);      // Set GREEN_LED high initially
  //digitalWrite(YELLOW_LED, LOW);      // Set YELLOW_LED low initially
  //digitalWrite(RED_LED, LOW);         // Set RED_LED low initially

  state = WP;
  Serial.begin(9600);
}

void loop() {
                   // Local variable to store the current value of the millis timer
  buttonState1 = digitalRead(SW1);
  buttonState2 = digitalRead(SW2);
  buttonState3 = digitalRead(SW3);
  switch (state) {
    case WP:
      //show welcome page 
      
      //delay(2000);
      if (buttonState1 == HIGH) { 
        Serial.print("welcome page\n"); // else if YELLOW_LED has toggled 20 times, 
        Serial.print("going to page 1\n"); //   turn off YELLOW_LED,
        state = P1;  
      }
      
      break;

    case P1:
      
      if (buttonState2 == HIGH) {   // If SW2 is pressed,
        Serial.print("going to page 2\n"); //   turn off YELLOW_LED,
        state = P2;                 //   switch to the GREEN state, and 
          //   turn on GREEN_LED
      }else if (buttonState3 == HIGH){
        Serial.print("shutting down\n"); //   turn off YELLOW_LED,
        state = BP; 
      }
      break;

    case BP:
      if (buttonState2 == HIGH && buttonState1 == HIGH) { 
        delay(3000);  // If SW2 is pressed,
        Serial.print("starting ...\n"); //   turn off YELLOW_LED,
        state = WP;                 //   switch to the GREEN state, and 
          //   turn on GREEN_LED
      }
      break;
    case P2:
      if (buttonState1 == HIGH) {  // else if YELLOW_LED has toggled 20 times, 
        Serial.print("going to page 1\n"); //   turn off YELLOW_LED,
        state = P1;  
      }else if (buttonState3 == HIGH){
        Serial.print("shutting down\n"); //   turn off YELLOW_LED,
        state = BP; 
      }
      
      break;
  }
}