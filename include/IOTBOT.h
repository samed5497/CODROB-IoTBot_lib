#ifndef IOTBOT_H
#define IOTBOT_H

#if defined(ESP32)

#include <Arduino.h>
#include <ESP32Servo.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Stepper.h>
#include <Adafruit_NeoPixel.h>

// Pins
#define JOYSTICK_Y_PIN 34
#define JOYSTICK_X_PIN 15
#define JOYSTICK_BUTTON_PIN 35
#define ENCODER_A_PIN 16
#define ENCODER_B_PIN 17
#define ENCODER_BUTTON_PIN 13
#define B1_AND_B2_BUTTON_PIN 4
#define RELAY_PIN 14
#define BUZZER_PIN 12
#define LDR_PIN 39
#define POT_PIN 36
#define B3_BUTTON_PIN 0
#define LCD_ADRESS 0x27
#define LED_BUILTIN 1

#define IO25 25
#define IO26 26
#define IO27 27
#define IO32 32
#define IO33 33

class IOTBOT
{
public:
  IOTBOT();
  void begin();
  void playIntro();

  /*********************************** Serial Port ***********************************
   */
  void serialStart(int baundrate);
  void serialWrite(const char *message);
  void serialWrite(int value);
  void serialWrite(float value);
  void serialWrite(bool value);

  /*********************************** BUZZER ***********************************
   */
  void buzzerPlayTone(int frequency, int duration);
  void buzzerSoundIntro();
  void buzzertest();

  /*********************************** LCD SCREEN ***********************************
   */
  void lcdWriteMid(const char *line1, const char *line2, const char *line3, const char *line4);
  void lcdWriteCR(int col, int row, const char *text);
  void lcdWriteCR(int col, int row, int value);
  void lcdWriteCR(int col, int row, float value);
  void lcdWriteCR(int col, int row, bool value);
  void lcdWrite(const char *text);
  void lcdWrite(int value);
  void lcdWrite(float value);
  void lcdWrite(bool value);
  void lcdClear();
  void lcdtest();

  /*********************************** LDR ***********************************
   */
  int ldrRead();
  void ldrtest();

  /*********************************** RELAY ***********************************
   */
  void relayWrite(bool status);
  void relaytest();

  /*********************************** POTANTIOMETER ***********************************
   */
  int potentiometerRead();
  void potentiometertest();

  /*********************************** JOYSTICK ***********************************
   */
  int joystickXRead();
  int joystickYRead();
  int joystickButtonRead();
  void joysticktest();

  /*********************************** BUTTONS ***********************************
   */
  int button1Read();
  int button2Read();
  int button3Read();
  void buttonsAnalogtest();

  /*********************************** ENCODER ***********************************
   */
  int encoderRead();
  int encoderButtonRead();
  void encodertest();

  /*********************************** DRIVER AND MOTORS ***********************************
   */
  void moduleStepMotorMotion(int step, bool rotation, int accelometer, int speed);
  void moduleDCMotorGOClockWise(int speed);
  void moduleDCMotorGOCounterClockWise(int speed);
  void moduleDCMotorStop();
  void moduleDCMotorBrake();

  /*********************************** Servo Motor Sensor ***********************************
   */
  void moduleServoGoAngle(int pin, int angle, int acceleration);

  /*********************************** DHT Sensor ***********************************
   */

  int moduleDhtTempRead(int pin);
  int moduleDhtHumRead(int pin);
  int moduleDthFeelingTemp(int pin);

  /*********************************** NTC Temp Sensor ***********************************
   */
  float moduleNtcTempRead(int pin);

  /*********************************** Magnetic Sensor ***********************************
   */
  int moduleMagneticRead(int pin);

  /*********************************** Matris Button Sensor ***********************************
   */
  int moduleMatrisButtonAnalogRead(int pin);
  int moduleMatrisButtonNumberRead(int pin);

  /*********************************** Vibration Sensor ***********************************
   */
  int moduleVibrationDigitalRead(int pin);
  int moduleVibrationAnalogRead(int pin);

  /*********************************** Ultrasonic Distance Sensor ***********************************
   */
  int moduleUltrasonicDistanceRead();

  /*********************************** Trafic Ligh Sensor ***********************************
   */
  void moduleTraficLightWrite(bool red, bool yellow, bool green);

  /*********************************** Smart LED Sensor ***********************************
   */
  void extendSmartLEDPrepare(int pin, int numLEDs);
  void extendSmartLEDFill(int startLED, int endLED, int red, int green, int blue);

  void moduleSmartLEDPrepare(int pin);                             // Initialize NeoPixel strip
  void moduleSmartLEDWrite(int led, int red, int green, int blue); // Write RGB values to specific LED
  void moduleSmartLEDRainbowEffect(int wait);                      // Rainbow effect
  void moduleSmartLEDRainbowTheaterChaseEffect(int wait);          // Rainbow theater chase effect
  void moduleSmartLEDTheaterChaseEffect(uint32_t color, int wait); // Theater chase effect
  void moduleSmartLEDColorWipeEffect(uint32_t color, int wait);    // Color wipe effect
  uint32_t getColor(int red, int green, int blue);                 // Helper function for creating colors

  /*********************************** Motion Sensor ***********************************
   */
  int moduleMotionRead(int pin);

  /*********************************** Smoke Sensor ***********************************
   */
  int moduleSmokeRead(int pin);

  /*********************************** Mic Sensor ***********************************
   */
  int moduleMicRead(int pin);

  /*********************************** Soil Moisture Sensor ***********************************
   */
  int moduleSoilMoistureRead(int pin);

  /*********************************** IR Sensor ***********************************
   */

  int moduleIRRead(int pin);

  /*********************************** Relay Sensor ***********************************
   */
  void moduleRelayWrite(int pin, bool status);

  /*********************************** OTHER PINS ***********************************
   */
  int analogReadPin(int pin);
  void analogWritePin(int pin, int value);
  int digitalReadPin(int pin);
  void digitalWritePin(int pin, int value);

private:
  LiquidCrystal_I2C lcd;
  DHT *dhtSensor;    // Pointer to DHT sensor object
  Servo servoModule; // Create a Servo object for controlling the servo motor
  int currentAngle = 0;
  int encoderCount; // Stores the encoder's position
  int lastStateA;   // Stores the last state of A pin
  int lastStateB;   // Stores the last state of B pin
  int counterBuzzer, counterLCD, counterLDR, counterRelay, counterPot, counterJoystick, counterButtons, counterEncoder = 0;
  void initializeDht(int pin, uint8_t type);
  Adafruit_NeoPixel *pixels; // NeoPixel object pointer
};

#else
#error "Unsupported platform! Only ESP32 and ESP8266 are supported."
#endif

#endif // IOTBOT_H
