
 #include "FS.h"
 
void setup() {
Serial.begin(115200);

Serial.println("");

Serial.println("Mounting FS...");

if (!SPIFFS.begin()) {

    Serial.println("Failed to mount file system");

    return;
}


SPIFFS.format();

Serial.println("Done.");

}

 

void loop() { }

