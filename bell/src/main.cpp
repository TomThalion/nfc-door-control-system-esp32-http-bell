#include <Arduino.h>
#include "BellServer.h"
#include "Manager/AcousticOfficeBellManager.h"
#include "Manager/LightsignBellManager.h"
#include "Manager/BellManagerAbstraction.h"
#include "Utils/Port.h"
#include <stdio.h>

#define LED 5
#define PORT 80
#define TESTDURATION 5000

#if !defined(DURATION)
#define DURATION 500
#endif

#if !defined(MY_SSID)
#define MY_SSID "SSID 1234" // is not a correct ssid
#endif 

#if !defined(PASSWORD)
#define PASSWORD "test1234" // is not a correct wifi password
#endif 
#if !defined(ACOUSTIC_BELL)
#define ACOUSTIC_BELL true
#endif 



/**
 * @author Tom Gaßmann
 * @version 1.0
 * 
 */


BellServer server;
boolean finished = false;
std::shared_ptr<BellManagerAbstraction> manager;
/**
 * @brief Setup of the system and startingpoint of the programm. It creates a server
 * and calls the methode startServer() to initialize the bell controller.
 * 
 */
void setup() {
  pinMode(LED, OUTPUT);
  //std::shared_ptr<AcousticOfficeBellManager> manager = std::make_shared<AcousticOfficeBellManager>(Duration(TESTDURATION, Duration::MILLISECOND));
  if(ACOUSTIC_BELL) {
      manager = std::make_shared<AcousticOfficeBellManager>(Duration(DURATION, Duration::MILLISECOND));
      Serial.printf("Arcoustic Bell");
  } else {
      manager =std::make_shared<LightsignBellManager>(Duration(DURATION, Duration::MILLISECOND));
      Serial.printf("Lightsign Bell");
  }
  
  auto port = Port(PORT);
  server.init(manager, port);
  int result = server.startBellServer(MY_SSID, PASSWORD);


  if(result == -1) {
    Serial.print("Error starting the server!");
    while(true) {
      // alarm LED blinking fast
      digitalWrite(LED, HIGH);
      delay(50);
      digitalWrite(LED, LOW);
      delay(50);
    }
  }
  finished = true;
  Serial.println("Finished");
}

/**
 * LED flashes every 5 seconds to signalize that the system runs 
 */
void loop() {
  manager->resetCount();
  digitalWrite(LED, HIGH);
  delay(1000);
  if(!finished) {
    digitalWrite(LED, LOW);
  }
  delay(9000);

}