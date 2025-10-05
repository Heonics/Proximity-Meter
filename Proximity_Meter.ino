/*
  Proximity Meter Code

  First LED glows at 20cm and more LED glows as the distance reduces

  6 LEDs are connected at digital pin 2-7 and a Ultrasonic Distance Sensor HC-SR04 at pin 11(Trig) and 12(Echo).

  by Heonics

  https://github.com/Heonics/Proximity-Meter/blob/main/Proximity_Meter.ino


Required Materials :
1 X Arduino Uno
1 X HC-SR04
2 X 5mm Green LEDs
2 X 5mm Yellow LEDs
2 X 5mm Red LEDs
1 X 120ohms Resistor
1 X Breadboard

Circuit Diagram :
Arduino Digital Pin 2 -> LED 1(Green) +ve 
Arduino Digital Pin 3 -> LED 2(Green) +ve 
Arduino Digital Pin 4 -> LED 3(Yellow) +ve 
Arduino Digital Pin 5 -> LED 4(Yellow) +ve 
Arduino Digital Pin 6 -> LED 5(Red) +ve 
Arduino Digital Pin 7 -> LED 6(Red) +ve 
Arduino GND -> 120ohms resistor -> All LEDs -ve
Arduino 5V -> HC-SR04 VCC
Arduino GND -> HC-SR04 Gnd
Arduino Digital Pin 11 -> HC-SR04 Echo
Arduino Digital Pin 10 -> HC-SR04 Trig
*/

#include <HCSR04.h>//Install this Library from Library Manager in Arduino IDE

UltraSonicDistanceSensor distanceSensor(10, 11);  // Initialize the HC-SR04 sensor that is connected to digital pins 10(Trig) and 11(Echo).

int LED1 = 2; // LED1 connected to Digital Pin 2
int LED2 = 3; // LED2 connected to Digital Pin 3
int LED3 = 4; // LED3 connected to Digital Pin 4
int LED4 = 5; // LED4 connected to Digital Pin 5
int LED5 = 6; // LED5 connected to Digital Pin 6
int LED6 = 7; // LED6 connected to Digital Pin 7

int max_val = 20; // define maximum value(in cm) of the range which should not be less than 2(HC-SR04 Sensor measurement limitations)
int min_val = 4; // define the minimum value of the range(in cm) of the range which should not be grater than 400(HC-SR04 Sensor measurement limitations)

int dif_distance = (max_val-min_val)*(1.0/6.0); // Calculates the distance difference for each LED

void setup () {
	pinMode(LED1, OUTPUT); //Configuring LED1 as output
	pinMode(LED2, OUTPUT); //Configuring LED2 as output
	pinMode(LED3, OUTPUT); //Configuring LED3 as output
	pinMode(LED4, OUTPUT); //Configuring LED4 as output
	pinMode(LED5, OUTPUT); //Configuring LED5 as output
	pinMode(LED6, OUTPUT); //Configuring LED6 as output
}

void loop () {
		int distance_measured = distanceSensor.measureDistanceCm(); // read the distance and store it

	  if(distance_measured <= max_val && distance_measured >= (min_val+(dif_distance*5))){ // checks if it is in 1st range
      // only turn on first LED
			digitalWrite(LED1, HIGH);
			digitalWrite(LED2, LOW);
			digitalWrite(LED3, LOW);
			digitalWrite(LED4, LOW);
			digitalWrite(LED5, LOW);
			digitalWrite(LED6, LOW);
		}else if(distance_measured <= max_val && distance_measured >= (min_val+(dif_distance*4))){ // checks if it is in 2nd range
      // only turn on first 2 LEDs
			digitalWrite(LED1, HIGH);
			digitalWrite(LED2, HIGH);
			digitalWrite(LED3, LOW);
			digitalWrite(LED4, LOW);
			digitalWrite(LED5, LOW);
			digitalWrite(LED6, LOW);
		}else if(distance_measured <= max_val && distance_measured >= (min_val+(dif_distance*3))){ // checks if it is in 3rd range
      // only turn on first 3 LEDs
			digitalWrite(LED1, HIGH);
			digitalWrite(LED2, HIGH);
			digitalWrite(LED3, HIGH);
			digitalWrite(LED4, LOW);
			digitalWrite(LED5, LOW);
			digitalWrite(LED6, LOW);
		}else if(distance_measured <= max_val && distance_measured >= (min_val+(dif_distance*2))){ // checks if it is in 3rd Last range
      // only turn on first 4 LEDs
			digitalWrite(LED1, HIGH);
			digitalWrite(LED2, HIGH);
			digitalWrite(LED3, HIGH);
			digitalWrite(LED4, HIGH);
			digitalWrite(LED5, LOW);
			digitalWrite(LED6, LOW);
		}else if(distance_measured <= max_val && distance_measured >= (min_val+(dif_distance))){ // checks if it is in 2nd Last range
      // only turn on first 5 LEDs
			digitalWrite(LED1, HIGH);
			digitalWrite(LED2, HIGH);
			digitalWrite(LED3, HIGH);
			digitalWrite(LED4, HIGH);
			digitalWrite(LED5, HIGH);
			digitalWrite(LED6, LOW);
		}else if(distance_measured <= max_val){ // checks if it is in Last range
      // turn on all LEDs
			digitalWrite(LED1, HIGH);
			digitalWrite(LED2, HIGH);
			digitalWrite(LED3, HIGH);
			digitalWrite(LED4, HIGH);
			digitalWrite(LED5, HIGH);
			digitalWrite(LED6, HIGH);
		}else{
      // turn on all LEDs
			digitalWrite(LED1, LOW);
			digitalWrite(LED2, LOW);
			digitalWrite(LED3, LOW);
			digitalWrite(LED4, LOW);
			digitalWrite(LED5, LOW);
			digitalWrite(LED6, LOW);
		}
}
