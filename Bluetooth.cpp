/************************************************
 Written by Cruz Monrreal II
 Created on 06-26-2012
 Modified on 11-11-2012
 
 Updates can be found here:
  https://github.com/cmonr/Arduino-Bluetooth-Library
************************************************/

#include <stdint.h>
#include <Arduino.h>
#include <Bluetooth.h>

Bluetooth::Bluetooth(){
    Serial1.begin(115200);
}

Bluetooth::~Bluetooth(){}

char Bluetooth::beginCMD(){
  Serial1.print("$$$");
  
  return readUntilLine() == "CMD";
}
void Bluetooth::endCMD(){
  Serial1.println("---");
  
  readUntilStr("END", 5000);
}

void Bluetooth::connect(){
  do{
    Serial1.println("C");
  } while(readUntilStr("failed", 10000).indexOf("failed") != -1);
}

char Bluetooth::connectToAddr(String addr){
  
}

char Bluetooth::isConnected(){
  Serial1.println("GK");
  
  return readUntilDelay(1000) != "0";
}

String Bluetooth::readUntilStr(String str, unsigned long timeout){
  String resp = "";
  char c = 0;
  
  start = millis();
  Serial.flush();
  while (resp.indexOf(str) == -1 && start + timeout > millis()){
    while(Serial1.available()){
      c = char(Serial1.read());
      
      resp.concat(c);
    }
  }
  
  return resp;
}

String Bluetooth::readUntilLine(){
  String resp = "";
  char c = 0;
  
  while (c != '\n'){
    while(Serial1.available()){
      c = char(Serial1.read());
      
      resp.concat(c);
    }
  }
  
  return resp;
}

String Bluetooth::readUntilDelay(unsigned long delay){
  String resp = "";
  
  start = millis();
  Serial.flush();
  while(start + delay > millis()){
    while(Serial1.available())
      resp.concat(char(Serial1.read()));
  }
  
  return resp;
}