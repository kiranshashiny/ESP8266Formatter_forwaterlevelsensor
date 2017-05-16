# ESP8266Formatter_forwaterlevelsensor

This project describes a ESP8266 wifi device that can be configured to a MQTT broker and a temperature sensor data being published and subscribed from the HiVe MQ broker.


This is extrapolated from https://github.com/marvinroger/homie-esp8266

I have utilized the v1.5 for this.

Typically, this project is for hobbyists who wants to Publish and Subscribe data to/from the Broker in the cloud and also for the device to subscribe to commands from the broker - like turn On/Off a light on the wifi module.

The thing to note here is the usage of formatter code to erase the wifi and mqtt attributes saved on the Wifi NodeMCU module, as this can get in the way of frequent uploads of the Homie Examples and sometimes does not erase all data on the NodeMCU flash.

Upload the formatter first to clean flash before uploading the other code like Lights On/Off.

1. Install Homie 1.5.0  library into arduino 

2.  Homie Arduino package -  Hit Sketch -> include library -> add zip 

    https://github.com/marvinroger/homie-esp8266/archive/v1.5.0.zip

3.  Open LightOnOff built-in example inside homie & compile/download

    you should see your AP mode of ESP.  It should also ask for AP passwd to connect

4  Download homie-configurator - Run homie-esp8266-v1/setup-built/index.html  after you unzip this.

https://github.com/marvinroger/homie-esp8266/releases/download/v1.5.0/homie-esp8266-v1-setup.zip

After this - unzip this on your laptop and start the index.html from this unzipped folder.

