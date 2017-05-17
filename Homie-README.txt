In Arduino program

   if (Homie.setNodeProperty(temperatureNode, "degC", String(temperature), true)) {
The end topic is degC
  if (Homie.setNodeProperty(temperatureNode, "humPercent", String(h), true)) {
The end topic is humPercent

Definition of the node 
HomieNode temperatureNode("temperature", "temperature");

topic is temperature/humPercent
topic is temperature/degC
See also
https://github.com/marvinroger/homie
In homie-configurator

Base topic – sets the base topic name – Ex:  devices/  will make MQTT receive/tx in 
devices/#/ temperature/humPercent
device ID – set the topic next to base topic – Ex: myfridge makes the MQTT receive/tx in
devices/myfridge/ temperature/humPercent

To send a data to node that has subscribed in topic devices/myfridge/ temperature/updateIntvl do
devices/myfridge/ temperature/updateIntvl/set 1000

