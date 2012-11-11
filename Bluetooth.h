/************************************************
 Written by Cruz Monrreal II
 Created on 06-26-2012
 Modified on 11-11-2012
 
 Updates can be found here:
  https://github.com/cmonr/Arduino-Bluetooth-Library
************************************************/

#ifndef Bluetooth_h
#define Bluetooth_h

#include <stdint.h>
#include <Arduino.h>
#include <Serial.h>

class Bluetooth{

public:
  // public methods
  Bluetooth();
  ~Bluetooth();
  
  char beginCMD();
  void endCMD();
  void connect();
  char connectToAddr( String addr );
  char isConnected();
  
private:
  String readUntilLine();
  String readUntilStr( String str, unsigned long timeout );
  String readUntilDelay( unsigned long delay );
  
  unsigned long start;
};

#endif