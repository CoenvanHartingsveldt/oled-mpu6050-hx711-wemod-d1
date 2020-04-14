/*#include <HX711.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;
Adafruit_Sensor *mpu_temp, *mpu_accel, *mpu_gyro;
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = D4;
const int LOADCELL_SCK_PIN = D3;
const int buttonPin = D0;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status

HX711 scale;
float seed = 340;

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
  Serial.begin(115200);
    scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
    scale.set_scale(seed);
      // while (!Serial);
  Serial.println("MPU6050 OLED demo");
  delay(10);

  if (!mpu.begin()) {
    Serial.println("Sensor initiatie gefaalt");
    while (1)
      yield();
  }
  Serial.println("MPU-6050 sensor gevonden");

  mpu_temp = mpu.getTemperatureSensor();
  mpu_temp->printSensorDetails();

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 adressering fout"));
    for (;;)
      ; // Don't proceed, loop forever
  }
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setRotation(0);
 
}

void loop() 
{

  if (Serial.available()) {
    char z = Serial.read();

    if (z == '-') seed -= 5;
    if (z == '+') seed += 5;
  }

  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // reset tare:
    scale.tare();
  }
{
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("G-krachten:");       //textlijn
  display.print(a.acceleration.x/10, 0);//, 0 is aantal decimalen
  display.println("g X-as");            //laat x as zien
  display.print(a.acceleration.y/10, 0);//, 0 is aantal decimalen
  display.println("g Y-as");            //laat y as zien
  display.print(a.acceleration.z/10, 0);//, 0 is aantal decimalen
  display.println("g Z-as");            //laat z as zien
  
  display.setCursor(70, 0);     //textlijn op cursor 70 rechts, 0 beneden
  display.println("Beweging:"); 
  display.setCursor(70, 8);     //textlijn op cursor 70 rechts, 8 beneden
  display.print(g.gyro.x, 1);   //, 1 is aantal decimalen
  display.println("x");
  display.setCursor(70, 16);    //textlijn op cursor 70 rechts, 16 beneden
  display.print(g.gyro.y, 1);   //, 1 is aantal decimalen
  display.println("y");
  display.setCursor(70, 24);    //textlijn op cursor 70 rechts, 24 beneden
  display.print(g.gyro.z, 1);   //, 1 is aantal decimalen      
  display.println("z");
  
  display.setCursor(0, 33);    //textlijn op cursor 70 rechts, 37 beneden
  display.print("CPU Temp:");
  display.setCursor(70, 33);    //textlijn op cursor 70 rechts, 37 beneden
  display.print(temp.temperature, 0);
  display.println("\tC");  

  display.setCursor(0, 46);    //textlijn op cursor 70 rechts, 50 beneden
  display.print("Gewicht:");
  display.setCursor(0, 56);    //textlijn op cursor 70 rechts, 37 beneden
  display.print(scale.get_units(1), 2);
  display.println("\gr");
  
  long reading = scale.read();
  Serial.print("HX711 reading: ");
  Serial.println(reading); 
  Serial.println("Geworden in gram:");
  Serial.println(scale.get_units(10), 2);
  Serial.println("\gr");
  Serial.println("Gain:");
  Serial.println(seed);
  
    //gewicht schalen met "+" of "=" teken in serial monitor
  if (Serial.available()) {
    char z = Serial.read();

    if (z == '-') seed -= 5;
    if (z == '=') seed += 5;
  }
}
  display.display();
 delay(10);                   //Coen-tastisch splashscreen vertraging
}
*/
