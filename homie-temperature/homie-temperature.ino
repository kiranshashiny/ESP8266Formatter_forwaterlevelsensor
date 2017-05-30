 #include <Homie.h>

#include <dht11.h>

dht11 DHT11;

#define DHTPIN 4 //
#define DHT11PIN 2



unsigned long lastTimeStamp, updtPeriodms ;
float last_temperature, last_h;

HomieNode temperatureNode("temperature", "temp");
HomieNode humidityNode("humidity", "humi");
//HomieNode sensorProp("sensor", "pollInt");
//HomieNode tempPollInterval ("tempPollInt", "tempPollInt");


void setupHandler() {
  Homie.setNodeProperty(temperatureNode, "unit", "c", true);
  Homie.setNodeProperty(humidityNode, "unit", "%", true);
}

bool updateFreqHandler (String value) {

   updtPeriodms = (unsigned long) (value.toFloat());
   Serial.print("Update interval (ms): ");
   Serial.print(value);
   Serial.print(" ");
   Serial.println(updtPeriodms);

   return true;
}

void loopHandler() {

  int chk = DHT11.read(DHT11PIN);

/* Shashi - uncomment this  Serial.print("Read sensor: ");
  switch (chk)
  {
    case DHTLIB_OK: 
    Serial.println("OK"); 
    break;
    case DHTLIB_ERROR_CHECKSUM: 
    Serial.println("Checksum error"); 
    break;
    case DHTLIB_ERROR_TIMEOUT: 
    Serial.println("Time out error"); 
    break;
    default: 
    Serial.println("Unknown error"); 
    break;
  }
*/

   //read temperature from sensor
   //float temperature = DHT11.temperature;
   //float h = DHT11.humidity;
   // For now - simulate a temperature and humidity, by dummying some values.
   float temperature = 81;
   float h = 88;
   
   delay(100);
   if ( (millis() - lastTimeStamp >= updtPeriodms ) || (temperature != last_temperature) || (h != last_h) ) {
     Serial.print ("Shashi : Sending temperature " );
     Serial.println (lastTimeStamp);
     Serial.println (temperature);
     if (Homie.setNodeProperty(temperatureNode, "degC", String(temperature), true)) {

      lastTimeStamp = millis();

    } else {

      Serial.println("Temperature sending failed");
    }
    
    if (Homie.setNodeProperty(humidityNode, "humPercent", String(h), true)) {
      Serial.print ("Shashi : Sending humidity ");
      Serial.println (lastTimeStamp);
      lastTimeStamp = millis();

    } else {

      Serial.println("Humidity sending failed");
    }
    
    lastTimeStamp = millis();

//    Serial.print("Temperature   /Humidity: ");

//    Serial.print(temperature); Serial.print(" ");

//    Serial.print(String(h));

//    Serial.println(" °C / %");
   }
last_h = h;
last_temperature = temperature;

}

void setup() {
Serial.begin(115200);
Serial.println();
Serial.println();
updtPeriodms = 60000;
Homie.setFirmware("awesome-temperature", "1.0.0");
temperatureNode.subscribe("updateIntvl", updateFreqHandler);
Homie.registerNode(temperatureNode);
Homie.registerNode(humidityNode);
Homie.setSetupFunction(setupHandler);
Homie.setLoopFunction(loopHandler);
//Homie.eraseConfig ();
Homie.setup();

}

void loop() {
    Homie.loop();
}

