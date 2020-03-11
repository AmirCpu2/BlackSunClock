#include <ESP8266WiFi.h>
#include "Virtuino_ESP_WifiServer.h"

/*******************
 * Begin Init Value
 *******************/
//  WiFi Config
const char* ssid = "BlackSunClock";    
const char* password = "P@ssM0rd";
int port = 8000;

//  WeMos ESP8266 pins= D0,D1,D2,D3,D4,D5,D6,D7,D8
int d0=16, d1=5, d2=4, d3=0, d4=2, d5=14, d6=12, d7=13, d8=15;

//Virtual Temp Memory
String vPin[] = {"L1","L1.2","L2","L3","L5","LSun","LMan","GameMode","Hour","Minute","Second"};
String tPin[] = {"Command","Response"};
int vTempMamoryPin[] = {0,0,0,0,0,0,0,0,0,0,0};
String tTempMamoryPin[] = {"",""};

//  Example variables
int MaxVDPin=8;
int counter =0;
long storedTime=0;
String timeTemp="";

//  val Color : 0 1 2 3 4 => Black, Read, Green, Blue, White 
int Led1 = 0;
int Led1_2 = 0;
int Led2 = 0;
int Led3 = 0;
int Led5 = 0;

//  Setup GPIO
/*----Sun LED----*/
int out_W = d4;
/*----Man LED----*/
int in_R = d3;
int in_G = d2;
int in_B = d1;

//  Api Server Config
WiFiServer server(port);
//  Initilize Wemos Server
Virtuino_ESP_WifiServer virtuino(&server);

/*******************
 * End Init Value
 *******************/
 
/********************
 * Begin Function
 ********************/

//val Message bufer
String Message = "";
/* Control methods Start*/

//LED 0 == in And 1 == out
//Color 0 == black And 1 == Read And 2 == Green And 3 == Blue And 4 == Red+Green And 5 == Red+Blue And 6 == Green+Blue And 7 == Red+Green+blue(White)
//Amount of light 0 - 2048
void ChangeColor(int led,int color,int light)
{
  switch(led)
  {
    light=1;
    //in
    case 0 :
      //color
      switch(color)
      {
        //black
        case 0 :
          digitalWrite(in_R, 0);
        
          digitalWrite(in_G, 0);
        
          digitalWrite(in_B, 0);
        break;
        
        //read
        case 1 :
          for(int i=0; i<=light; i++)
          {
            digitalWrite(in_R, 1);
        
            digitalWrite(in_G, 0);
        
            digitalWrite(in_B, 0);
        
            delay(100);
          }
        break;
        
        //green
        case 2 :
          for(int i=0; i<=light; i++)
          {
            digitalWrite(in_R, 0);
        
            digitalWrite(in_G, 1);
        
            digitalWrite(in_B, 0);
        
            delay(100);
          }
        break;
        
        //blue
        case 3 :
        
          for(int i=0; i<=light; i++)
          {
            digitalWrite(in_R, 0);
        
            digitalWrite(in_G, 0);
        
            digitalWrite(in_B, 1);
        
            delay(100);
          }
        break;
        
        //red+green
        case 4 :
        
          for(int i=0; i<=light; i++)
          {
            digitalWrite(in_R, 1);
        
            digitalWrite(in_G, 1);
        
            digitalWrite(in_B, 0);
        
            delay(100);
          }
        break;
        
        //red+blue
        case 5 :
        
          for(int i=0; i<=light; i++)
          {
            digitalWrite(in_R, 1);
        
            digitalWrite(in_G, 0);
        
            digitalWrite(in_B, 1);
        
            delay(100);
          }
        break;
        
        //green+blue
        case 6 :
          
          for(int i=0; i<=light; i++)
          {
            digitalWrite(in_R, 0);
        
            digitalWrite(in_G, 1);
        
            digitalWrite(in_B, 1);
        
            delay(100);
          }
        break;
        
        //red+green+blue(White)
        case 7 :
          
          for(int i=0; i<=light; i++)
          {
            digitalWrite(in_R, 1);
        
            digitalWrite(in_G, 1);
        
            digitalWrite(in_B, 1);
        
            delay(100);
          }
        break;
      }
    break;

    //out
    case 1 :
        //color
      switch(color)
      {
        //black
        case 0 :
        
          digitalWrite(out_W,0);
        break;

        //white
        case 1 :
        //Serial.println("LED ON");
          light = 1;
          for(int i=0; i<=light; i++)
          {
            digitalWrite(out_W,1);
  
            delay(100);
          }
        break;
      }
    break;
  }
}

//read in numeric characters until something else
//or no more data is available on serial.
int SerialReadPosInt() {
  int i = 0;
  boolean done=false;
  while(Serial.available() && !done)
  {
    char c = Serial.read();
    if (c >= '0' && c <='9')
    {
      i = i * 10 + (c-'0');
    }
    else 
    {
      done = true;
    }
  }
  return i;
}

void GetLedValue()
{
  //send command
  Serial.println("t");

  //Check Avalibale Response
  if(!Serial.available()) { return; }
  delay(100);

  //Get Response
  int ledColors = SerialReadPosInt();

  //pars Response
  Led1 = ledColors%10;
  virtuino.vMemoryWrite(0,ledColors%10);
  ledColors /= 10;
  
  Led1_2 = ledColors%10;
  virtuino.vMemoryWrite(1,ledColors%10);
  ledColors /= 10;
  
  Led2 = ledColors%10;
  virtuino.vMemoryWrite(2,ledColors%10);
  ledColors /= 10;
  
  Led3 = ledColors%10;
  virtuino.vMemoryWrite(3,ledColors%10);
  ledColors /= 10;
  
  Led5 = ledColors%10;
  virtuino.vMemoryWrite(4,ledColors%10);
}
/********************
 * End Function
 ********************/


void setup() {
  //----- Virtuino settings
  virtuino.DEBUG=false;                        // set this value TRUE to enable the serial monitor status
  virtuino.password="1234";                    // Set a password to your web server for more protection 
                                               // avoid special characters like ! $ = @ # % & * on your password. Use only numbers or text characters

  Serial.begin(115200);                        // set this value equals Arduino Serial Value
  delay(10);
  
  //----  1. Settings as Station - Connect to a WiFi network
  Serial.println("Connecting to "+String(ssid));
  
  WiFi.mode(WIFI_STA);                       // Config module as station only.
  WiFi.begin(ssid, password);

  //Wait To Connect
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  
  /*--------------------  Connected  WIFI  ----------------------*/
  Serial.println(WiFi.localIP());
  
  // ---- Start the server
  server.begin();

  //---- Start Status App
  //virtuino.vDigitalMemoryWrite(0,1);
  //virtuino.vMemoryWrite(2,random(1000));
  
  //---- Enter your setup code below
  /*------------------SerialControl--------------------
   * h## - set Hours [range 1..12 or 0..24]
   * i## - set Minutes [range 0..59]
   * s## - set Seconds [range 0..59]
   * t   - Get Status All LED => 00000
   * g(LEDGet)# - get Color LED [range 1,2,3,4,5]
   * b(LEDSet)## - set Color LED [range LED 1,2--1.2--,3--2--,4--3--,5][range color 0,1,2,3 ]
   * l   - Set Game Mode Status [range 0 , 1 ]
   * r   - Print Led Status
  --------------------SerialControl-------------------*/
  pinMode(d1, OUTPUT);//B = > Man LED
  pinMode(d2, OUTPUT);//G = > Man LED
  pinMode(d3, OUTPUT);//R = > Man LED
  pinMode(d4, OUTPUT);//W = > Sun LED

  //Get Clock Led Values
  GetLedValue();
}

void loop() {
//  Yes LetsGOOO ^__*
  virtuino.run();
/*------------------  Requst Conterol --------------------*/
  for(int i=0;i<11;i++)
  {
    // Read virtual memory 0 to n from Virtuino app
    int v = virtuino.vMemoryRead(i);
    //Serial.println("v:"+String(v));
    
    //Check Last vs new status
    if(vTempMamoryPin[i] != v)
    {
      //Command Swiching
      if(vPin[i] == "L1")
        Serial.println("b1"+String(v));// 0 black, Red 1 , Green 2 , Blue 3
      if(vPin[i] == "L1.2")
        Serial.println("b2"+String(v));// 0 black, Red 1 , Green 2 , Blue 3
      if(vPin[i] == "L2")
        Serial.println("b3"+String(v));// 0 black, Red 1 , Green 2 , Blue 3
      if(vPin[i] == "L3")
        Serial.println("b4"+String(v));// 0 black, Red 1 , Green 2 , Blue 3
      if(vPin[i] == "L5")
        Serial.println("b5"+String(v));// 0 black, Red 1 , Green 2 , Blue 3
      if(vPin[i] == "LSun")
        ChangeColor(1,v,1);// 0 black, White 1
      if(vPin[i] == "LMan")
        ChangeColor(0,v,1);//Color 0 == black And 1 == Read And 2 == Green And 3 == Blue And 4 == Red+Green And 5 == Red+Blue And 6 == Green+Blue And 7 == Red+Green+blue(White)
      if(vPin[i] == "GameMode")
      {
        Serial.println("l"+String(v));// 0 off,1 on
        delay(100);
        
        //Get Clock Led Values
        GetLedValue();
      }
      if(vPin[i] == "Hour")
      {
        timeTemp = v < 10 ? "0" + String(v) : String(v) ;
        Serial.println("h"+timeTemp);// [range 1..12]
      }
      if(vPin[i] == "Minute")
      {
        timeTemp = v < 10 ? "0" + String(v) : String(v) ;
        Serial.println("i"+timeTemp);// [range 0..59]
      }
      if(vPin[i] == "Second")
      {
        timeTemp = v < 10 ? "0" + String(v) : String(v) ;
        Serial.println("s"+timeTemp);// [range 0..59]
      }
      //Set Last status
      vTempMamoryPin[i] = v;
    }
      
  }

  /*for(int i=0;i<2;i++)
  {
    // Read virtual memory 0 to n from Virtuino app
    int v = virtuino.tMemoryRead(i);
  }*/
}
