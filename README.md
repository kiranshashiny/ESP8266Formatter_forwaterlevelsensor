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

==

Steps

Upload the homie formatter

Upload the Lights On/Off code

Go to the Wifi Networking icon on your laptop - choose the new Network that got created by above code.

Homie- Network snapshot>

Select this network and let it connect.
<Homie connected snapshot>

Launch the networking html code from the configurator
file:///Users/shashikiran/Downloads/homiedir/homie-esp8266-v1-setup-built/index.html


Connect to an external Hive Broker broker.hivemq.com ,

leave the Base topic to be the default.


<img width="324" alt="screen shot 2017-05-16 at 2 51 22 pm" src="https://cloud.githubusercontent.com/assets/14288989/26099340/054277e4-3a48-11e7-92b2-a3ba3bf1921f.png">
<img width="916" alt="screen shot 2017-05-16 at 2 52 00 pm" src="https://cloud.githubusercontent.com/assets/14288989/26099339/053f413c-3a48-11e7-8de6-0cdf286938c1.png">
<img width="298" alt="screen shot 2017-05-16 at 2 54 16 pm" src="https://cloud.githubusercontent.com/assets/14288989/26099338/050f51e8-3a48-11e7-979b-66136d4fc890.png">
<img width="874" alt="screen shot 2017-05-16 at 2 55 05 pm" src="https://cloud.githubusercontent.com/assets/14288989/26099336/050dfafa-3a48-11e7-9b87-a245f07cda39.png">
<img width="538" alt="screen shot 2017-05-16 at 2 55 17 pm" src="https://cloud.githubusercontent.com/assets/14288989/26099335/050d6126-3a48-11e7-8a1b-d881653d624b.png">
<img width="645" alt="screen shot 2017-05-16 at 2 55 57 pm" src="https://cloud.githubusercontent.com/assets/14288989/26099334/050d2b7a-3a48-11e7-8880-86ce5ca50c5d.png">
<img width="620" alt="screen shot 2017-05-16 at 2 56 37 pm" src="https://cloud.githubusercontent.com/assets/14288989/26099337/050f132c-3a48-11e7-903e-9d4fc3eecbba.png">
<img width="716" alt="screen shot 2017-05-16 at 2 56 46 pm" src="https://cloud.githubusercontent.com/assets/14288989/26099333/050ba070-3a48-11e7-94a0-b21cae2ba860.png">


Open the Serial Monitor on the Arduino IDE and see that the device is connected and now connected to the hive broker.


Open the broker and publish / subscribe to some data.


go to the Publish section and enter the topic that consists of the device name and so on.

devices/aabbccddeeff/light/on/set

Set the Message to either "true" or "false"

If you set the message to "true" the Light is on message should show up on the Arduino IDE sketch Serial Monitor

Likewise

if the message is set to "false" then the Light is off message should show up.

Now the NodeMCU Wifi module is communicating directly to the broker ( thru my home network router )

<img width="1192" alt="screen shot 2017-05-16 at 3 01 07 pm" src="https://cloud.githubusercontent.com/assets/14288989/26099623/ee9f0e48-3a48-11e7-93de-693cb40568b1.png">
<img width="380" alt="screen shot 2017-05-16 at 3 03 35 pm" src="https://cloud.githubusercontent.com/assets/14288989/26099622/ee9e8a40-3a48-11e7-8a11-304be95bdee2.png">
<img width="997" alt="screen shot 2017-05-16 at 3 03 41 pm" src="https://cloud.githubusercontent.com/assets/14288989/26099624/eea379a6-3a48-11e7-841f-c3abfd21d209.png">
<img width="951" alt="screen shot 2017-05-16 at 3 03 51 pm" src="https://cloud.githubusercontent.com/assets/14288989/26099621/ee9b9286-3a48-11e7-9244-07d29926e41c.png">

