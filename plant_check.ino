const short SENSOR_THRESHOLD = 610;
const short BLINK_DIFF = 10;
const short INFO_WAITING = 10; // every 100 loops print the current analog value
const short DELAY = 1000;

int sensorPin = A0;
int ledPin = 13;
int sensorValue = 0;
bool fed = true;
short ledState = LOW;
short counter = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void loop()
{
  sensorValue = analogRead(sensorPin);

  if (++counter == INFO_WAITING) {
    counter = 0;
    Serial.print("Current value: ");
    Serial.println(sensorValue);
  }

  if (abs(sensorValue - SENSOR_THRESHOLD) < BLINK_DIFF) {
    // let the led blink
    ledState = !ledState;
  } else if (sensorValue < SENSOR_THRESHOLD) {
    ledState = HIGH;
    Serial.println("Feed me!");
    fed = false;
  } else {
    ledState = LOW;
    digitalWrite(ledPin, LOW);
    if (!fed)
      Serial.println("Thank you, Seymor!");
    fed = true;
  }

  digitalWrite(ledPin, ledState);
  delay(DELAY);
}
