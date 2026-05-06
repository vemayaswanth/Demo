// #include <Arduino.h>

// #define SENSE_PIN PD2 

// void setup() {
//   // 1. Initialize the UART hardware at 9600 baud
//   // The 'L' tells the C compiler this is a Long integer
//   Serial_begin(9600L); 
  
//   // 2. Print the "Hello" message to verify connection
//   // _s stands for "String"
//   Serial_println_s("--- STM8 ADC START ---");
  
//   pinMode(SENSE_PIN, INPUT);
// }

// void loop() {
//   int rawValue = analogRead(SENSE_PIN);
  
//   // Print the data label
//   Serial_print_s("Raw ADC: "); 
  
//   // Print the actual number followed by a new line
//   // _i stands for "Integer"
//   Serial_println_i(rawValue); 
  
//   delay(500);
// }


#include <Arduino.h>

// ADC Pin (Potentiometer)
#define SENSE_PIN PD2
// Onboard LED Pin
#define LED_PIN PA3

void setup() {
  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  
  // Initialize the ADC pin as an input
  pinMode(SENSE_PIN, INPUT);
}

void loop() {
  // 1. Read the potentiometer (returns 0 to 1023)
  int speed = analogRead(SENSE_PIN);
  
  // 2. Prevent a 0ms delay (which looks like the LED is always ON)
  if (speed < 10) {
    speed = 10; 
  }

  // 3. Blink the LED using the 'speed' value as the interval
  digitalWrite(LED_PIN, HIGH);
  delay(speed);
  
  digitalWrite(LED_PIN, LOW);
  delay(speed);
}