Go thru the general README first before coming to this page.
The README has all the details on how to setup the device, configure the broker etc.

This document describes how to read the lead nodes of the topic being published from the device.

If in your Arduino code you have programmed the leaf node to be as shown:

   if (Homie.setNodeProperty(temperatureNode, "degC", String(temperature), true)) {

then the end topic is degC that will be used in the broker's page.

Likewise, if you have programmed the leaf node as 
    (Homie.setNodeProperty(temperatureNode, "humPercent", String(h), true)) {
then the end topic will be humPercent

Definition of the node 
HomieNode temperatureNode("temperature", "temperature");

topic is temperature/humPercent
topic is temperature/degC

In homie-configurator
Base topic – sets the base topic name – Ex:  devices/  will make MQTT receive/tx in 
devices/#/ temperature/humPercent
device ID – set the topic next to base topic – Ex: myfridge makes the MQTT receive/tx in
devices/myfridge/ temperature/humPercent

To send a data to node that has subscribed in topic devices/myfridge/ temperature/updateIntvl do
devices/myfridge/ temperature/updateIntvl/set 1000
