# Node MCU Wifi device connected to Sensors and can Publish/Subscribe to MQTT broker ( e.g: Hive MQ Broker ) 

This project describes a NodeMCU wifi device that can be connected to sensors like Temperature, Humidity, and can communicate to MQ Broker like Hive and can  turn on and off some lights, or send temperature/humidity data.

(This is an ongoing project and I'm documenting it as I go on.. so there are some snapshots to be added, some precise documentation for beginners will be added later.)

I assume that one is familiar with the ESP8266/NodeMCU, Arduino programming, building libraries, and working with IoT sensors like Temperature and Humidity sensors.

This project utilizes the ESP8266 implementation of Homie and is described in detail in this link, https://github.com/marvinroger/homie-esp8266

I have utilized the Homie Configuration version v1.5 for this, as the later version did not complete successfully at the time of this writing ~ May 2017.

The thing to note here is the usage of Formatter Arduino code to erase the Wifi and MQTT attributes saved on the Wifi NodeMCU device everytime before upoading the communication code, as this can get in the way of frequent uploads of the Homie Examples and sometimes does not erase all data on the NodeMCU flash.

Upload the formatter.ino to the NodeMCU first to clean device flash before uploading the other code like turning on/off lights, or reading data from sensor and doing a Publish/Subscribe.


1. Install Homie 1.5.0  library into Arduino 

    Sketch -> Include Library -> Add .zip Library

    https://github.com/marvinroger/homie-esp8266/archive/v1.5.0.zip

2.  Open LightOnOff built-in example inside homie & compile/download.

    You should see your AP mode of ESP.  It should also ask for AP passwd to connect
    
    Likewise the other example is to publish and subscribe the temperature and humidity ( see homie-temperature.ino in this repo)

3  Download homie-configurator on your local workstation or laptop.

    https://github.com/marvinroger/homie-esp8266/releases/download/v1.5.0/homie-esp8266-v1-setup.zip

    After this - unzip this zip file on your laptop and launch the browser pointing to this index.html to start configuration.



This blog describes two instances of connecting devices. One is to turn lights on/off and another is publish Temperature and Humidity to the Broker.
Both are described here.

###  Turn On/Off Lights by publishing commands from the broker.

Upload the Homie formatter

Upload the Lights On/Off code

Go to the Wifi Networking icon on your laptop - choose the new Network that got created by above code. Should be something lik Homie-18fe34d4

<img width="303" alt="screen shot 2017-05-30 at 11 38 41 am" src="https://cloud.githubusercontent.com/assets/14288989/26570160/9da30262-452c-11e7-9fdf-616191821a99.png">

Select this network and connect to it. 

Open the browser and bring up the configuration html page from the Configuration zip file that was downloaded earlier.
file:///Users/shashikiran/Downloads/homiedir/homie-esp8266-v1-setup-built/index.html

Go thru the configuration steps.

<img width="916" alt="screen shot 2017-05-16 at 2 52 00 pm" src="https://cloud.githubusercontent.com/assets/14288989/26099339/053f413c-3a48-11e7-8de6-0cdf286938c1.png">

<img width="298" alt="screen shot 2017-05-16 at 2 54 16 pm" src="https://cloud.githubusercontent.com/assets/14288989/26099338/050f51e8-3a48-11e7-979b-66136d4fc890.png">

<img width="874" alt="screen shot 2017-05-16 at 2 55 05 pm" src="https://cloud.githubusercontent.com/assets/14288989/26099336/050dfafa-3a48-11e7-9b87-a245f07cda39.png">

<img width="538" alt="screen shot 2017-05-16 at 2 55 17 pm" src="https://cloud.githubusercontent.com/assets/14288989/26099335/050d6126-3a48-11e7-8a1b-d881653d624b.png">

<img width="645" alt="screen shot 2017-05-16 at 2 55 57 pm" src="https://cloud.githubusercontent.com/assets/14288989/26099334/050d2b7a-3a48-11e7-8880-86ce5ca50c5d.png">

<img width="620" alt="screen shot 2017-05-16 at 2 56 37 pm" src="https://cloud.githubusercontent.com/assets/14288989/26099337/050f132c-3a48-11e7-903e-9d4fc3eecbba.png">

<img width="716" alt="screen shot 2017-05-16 at 2 56 46 pm" src="https://cloud.githubusercontent.com/assets/14288989/26099333/050ba070-3a48-11e7-94a0-b21cae2ba860.png">

Open the Serial Monitor on the Arduino IDE and see that the device is connected and now connected to the hive broker.

Open the browser and Publish / Subscribe to some data.

Go to the Publish section and enter the topic that consists of the device name 

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


###  NodeMCU connected to a temperature Sensor, publishing and subscribing the temperature and Humidity

Here connect the DHT-11 temperature and humidity sensor to the NodeMCU and Upload the homie-temperature to the NodeMCU

- Repeat Uploading the format-homie arduino code first - to erase any residual wifi configuration details.
- Upload the temperature arduino code from the Arduino IDE from your workstation.
- Set up workstation network wifi to newly created network ( something like Homie-18feda ) 
- Configure the network settings for the Node MCU
- Check that the Arduino IDE Serial Monitor speed is set to 115200

Add all the images here

<img width="1174" alt="screen shot 2017-05-30 at 12 55 31 pm" src="https://cloud.githubusercontent.com/assets/14288989/26572793/e2c44bf6-4538-11e7-8ad2-6b854c807f78.png">

<img width="1170" alt="screen shot 2017-05-30 at 12 55 43 pm" src="https://cloud.githubusercontent.com/assets/14288989/26572795/e548a692-4538-11e7-8118-214c2bf182db.png">

<img width="1168" alt="screen shot 2017-05-30 at 12 55 51 pm" src="https://cloud.githubusercontent.com/assets/14288989/26572796/e75940d6-4538-11e7-89f8-a5acf6e36f94.png">

<img width="1002" alt="screen shot 2017-05-30 at 12 56 12 pm" src="https://cloud.githubusercontent.com/assets/14288989/26572800/e9f95dbc-4538-11e7-84a7-99efb22ea6b2.png">

<img width="651" alt="screen shot 2017-05-30 at 12 56 34 pm" src="https://cloud.githubusercontent.com/assets/14288989/26572807/eea08be2-4538-11e7-91bd-1ad543fc46cf.png">

<img width="707" alt="screen shot 2017-05-30 at 12 56 42 pm" src="https://cloud.githubusercontent.com/assets/14288989/26572809/f0e746b6-4538-11e7-8f10-04ab9c4cfdfd.png">

<img width="402" alt="screen shot 2017-05-30 at 1 03 21 pm" src="https://cloud.githubusercontent.com/assets/14288989/26572815/f40eee34-4538-11e7-939c-1a70e23c872d.png">

<img width="439" alt="screen shot 2017-05-30 at 1 04 09 pm" src="https://cloud.githubusercontent.com/assets/14288989/26572821/f6bf1c76-4538-11e7-82e2-bcbbd54b37cb.png">


After the NodeMCU reboots, the device is publishing data to the broker.

Go to the http://www.hivemq.com/demos/websocket-client/ and subscribe to the temperature and humidity data from the NodeMCU


<img width="626" alt="screen shot 2017-05-30 at 1 09 35 pm" src="https://cloud.githubusercontent.com/assets/14288989/26572947/870cded0-4539-11e7-9263-503d869cc1d0.png">

<img width="599" alt="screen shot 2017-05-30 at 1 10 02 pm" src="https://cloud.githubusercontent.com/assets/14288989/26572949/89c41b16-4539-11e7-85c8-8250839f0881.png">

<img width="586" alt="screen shot 2017-05-30 at 1 11 02 pm" src="https://cloud.githubusercontent.com/assets/14288989/26572952/8b722bec-4539-11e7-8578-2629f805ad14.png">

and you should be able to see the subscriptions.

<img width="863" alt="screen shot 2017-05-30 at 1 11 11 pm" src="https://cloud.githubusercontent.com/assets/14288989/26572953/8d0ca18a-4539-11e7-9e94-ad74191e7c13.png">


