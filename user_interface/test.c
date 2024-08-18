#include <LiquidCrystal.h>
#include <Servo.h>
#include <SoftwareSerial.h>

// Initialize the LCD and servo
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo myservo;

// Define barcode scanner RX and TX pins
const int barcodeRxPin = 0;
const int barcodeTxPin = 1;

// Initialize software serial for barcode scanner
SoftwareSerial barcodeScanner(barcodeRxPin, barcodeTxPin);

// Define remaining ultrasonic sensor pins
const int trigPin2 = 13;
const int echoPin2 = 10;
const int trigPin3 = 7;
const int echoPin3 = 6;

// Define servo pin and barrier state
const int servoPin = 9;
bool isBarrierOpen = false;

// Variables to store the previous state
bool prevPosition1Occupied = false;
bool prevPosition2Occupied = false;
bool prevBarrierOpen = false;

void setup() {
  // Attach the servo and start the LCD
  myservo.attach(servoPin);
  lcd.begin(16, 2);
  Serial.begin(9600);

  // Initialize the barcode scanner
  //barcodeScanner.begin(9600);
  lcd.clear();
  lcd.print("Keine Pos. besetzt");

  // Set pin modes for the ultrasonic sensors
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
}

void loop() {
  int distance2 = getDistance(trigPin2, echoPin2);
  int distance3 = getDistance(trigPin3, echoPin3);

  bool position1Occupied = distance2 < 10;
  bool position2Occupied = distance3 < 10;

  // Check for data from the barcode scanner
  if (Serial.available() > 0) {
    String barcode = Serial.readStringUntil('\n');
    barcode.trim(); // Trim whitespace
    Serial.println(barcode);

    // Open the barrier if the barcode is "16"
    if (barcode == "16") {
      operateBarrier();
    } else {
      lcd.clear();
      lcd.print("Ungultiger Barcode");
      delay(2000);
      lcd.clear();
    }
  }

  // Rest of the parking logic
  if (!isBarrierOpen && (position1Occupied != prevPosition1Occupied || position2Occupied != prevPosition2Occupied)) {
    lcd.clear();
    if (position1Occupied && position2Occupied) {
      lcd.print("Beide Pos. besetzt");
    } else if (position1Occupied) {
      lcd.print("Pos 1 besetzt");
    } else if (position2Occupied) {
      lcd.print("Pos 2 besetzt");
    } else {
      lcd.print("Keine Pos. besetzt");
    }
    prevPosition1Occupied = position1Occupied;
    prevPosition2Occupied = position2Occupied;
  }
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    lcd.clear();
    lcd.print(command);
    command.trim();
    if (command == "open") {
      operateBarrier();
    }
  }

  delay(1000);
}

void operateBarrier() {
  if (!prevBarrierOpen) {
    prevBarrierOpen = true;
    myservo.write(90); // Rotate servo to open position
    lcd.clear();
    lcd.print("Barriere offnet");
    delay(5000); // Wait for 5 seconds
    myservo.write(0); // Rotate servo to closed position
    lcd.clear();
    lcd.print("Barriere schliesst");
    delay(2000); // Wait for barrier to close
    lcd.clear();
    lcd.print("Keine Pos. besetzt");
    isBarrierOpen = false;
    prevBarrierOpen = false;
  }
}

int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}