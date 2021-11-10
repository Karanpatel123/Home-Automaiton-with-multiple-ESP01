
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "3zGoYGvlMPV7t78AfhhsHL0tKBMy0ekC";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "patelcm";
char pass[] = "Chirag@1980";
String stringone,stringtwo;

BLYNK_CONNECTED()
  {
    Blynk.syncAll();
  }


BLYNK_WRITE(V2) // Executes when the value of virtual pin 0 changes
{
  if(param.asInt() == 1)
  {
    // execute this code if the switch widget is now ON
    if(stringone=="roomone")
    { 
    digitalWrite(0,HIGH);  // Set digital pin 2 HIGH
  }
  }
  else
  {
    // execute this code if the switch widget is now OFF
    digitalWrite(0,LOW);  // Set digital pin 2 LOW    
  }
}

BLYNK_WRITE(V3) // Executes when the value of virtual pin 0 changes
{
  if(param.asInt() == 1)
  {
    // execute this code if the switch widget is now ON
    if(stringone=="roomone")
    { 
    digitalWrite(2,HIGH);  // Set digital pin 2 HIGH
  }
  }
  else
  {
    // execute this code if the switch widget is now OFF
    digitalWrite(2,LOW);  // Set digital pin 2 LOW    
  }
}
void setup()
{
  stringone = String("roomone");
  stringtwo = String("roomtwo");
  
  pinMode(1, OUTPUT); // Initialise digital pin 2 as an output pin
  Blynk.begin(auth, ssid, pass);

}
void loop()
{
 Blynk.run();
}
