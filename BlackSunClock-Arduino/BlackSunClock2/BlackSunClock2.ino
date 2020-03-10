#include <Wire.h>
#include <RealTimeClockDS1307.h>

/***********************
 * AttachMethods Start
 **********************/
int h=10 ,m=10 ,s=0;
int tp=0,tp2=0,tmp=0,one=0,d=0,temp1=0 ;

//# 1 1 2 3 5
int led_sth [5] = {0,0,0,0,0};
int led_stm[5] = {0,0,0,0,0};

//result led turn on or turn off
int led_result[5] = {0,0,0,0,0};

//# off0 red1 green2 blue3
int led_color[5] = {0,0,0,0,0};

int fib [5]= {1,1,2,3,5};
int fibmin [5]= {5,5,10,15,25};

bool debug = true;
bool gameMode = false;
int lastActionTime[3] = {0,0,0};
int limitActionTime = 2; // min

void print(String message)
{
  if(debug)
  {
    Serial.print(message);
  }
}

void print(int message)
{
  if(debug)
  {
    Serial.print(message);
  }
}

void println(String message)
{
  if(debug)
  {
    Serial.println(message);
  }
}

void println(int message)
{
  if(debug)
  {
    Serial.println(message);
  }
}

void initilze ()
{
  /************************************
   * pin OUTPUT mode set
   ************************************/
  for(int i = 2 ; i<=13; i++)
  {
    if(i == 9)
    {
      continue ;
    }
    else
    {
      pinMode(i,OUTPUT);
    }
  }
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  
  /************************************
   * pin INPUT mode pull up set
   ************************************/
  digitalWrite(9,HIGH);
  RTC.start();
}

//2 parametr --> 1. LED(1,2,3,4,5)-->1 1 3 5  ^ 2. Color(0,1,2,3)-->Off red green blue
void set_color(int l , int c)
{
    switch(l)
    {
        case 1 :
        //1
        switch(c)
        {   
            case 0 :
            //Off
            //PORTC.0 = 0;
            digitalWrite(2,LOW); //blue
            //PORTC.1 = 0;
            digitalWrite(3,LOW); //green
            //PORTC.2 = 0;
            digitalWrite(4,LOW); //red
            
            break;
            
            case 1 :
            //Red
            //PORTC.0 = 0;
            digitalWrite(2,LOW); //blue
            //PORTC.1 = 0;
            digitalWrite(3,LOW); //green
            //PORTC.2 = 0;
            digitalWrite(4,HIGH); //red
            
            break;
            
            case 2 :
            //Green
            //PORTC.0 = 0;
            digitalWrite(2,LOW); //blue
            //PORTC.1 = 0;
            digitalWrite(3,HIGH); //green
            //PORTC.2 = 0;
            digitalWrite(4,LOW); //red
            
            break;
            
            case 3 :
            //Blue
            //PORTC.0 = 0;
            digitalWrite(2,HIGH); //blue
            //PORTC.1 = 0;
            digitalWrite(3,LOW); //green
            //PORTC.2 = 0;
            digitalWrite(4,LOW); //red
            
            break;
        }
        break;
        
        case 2 :
        //1
        switch(c)
        {   
            case 0 :
            //Off
            //PORTC.3 = 0;
            digitalWrite(5,LOW); //blue
            //PORTD.0 = 0;
            digitalWrite(6,LOW); //green
            //PORTD.1 = 0;
            digitalWrite(7,LOW); //red
            
            break;
            
            case 1 :
            //Red
            //PORTC.3 = 0;
            digitalWrite(5,LOW); //blue
            //PORTD.0 = 0;
            digitalWrite(6,LOW); //green
            //PORTD.1 = 0;
            digitalWrite(7,HIGH); //red
            
            break;
            
            case 2 :
            //Green
            //PORTC.3 = 0;
            digitalWrite(5,LOW); //blue
            //PORTD.0 = 0;
            digitalWrite(6,HIGH); //green
            //PORTD.1 = 0;
            digitalWrite(7,LOW); //red
            
            break;
            
            case 3 :
            //Blue
            //PORTC.3 = 0;
            digitalWrite(5,HIGH); //blue
            //PORTD.0 = 0;
            digitalWrite(6,LOW); //green
            //PORTD.1 = 0;
            digitalWrite(7,LOW); //red
            
            break;
        }
        break;
        
        case 3 :
        //2
        switch(c)
        {   
            case 0 :
            //Off
            //PORTD.2 = 0;
            digitalWrite(8,LOW); //blue
            //PORTD.3 = 0;
            digitalWrite(10,LOW); //green
            //PORTD.4 = 0;
            digitalWrite(11,LOW); //red
            
            break;
            
            case 1 :
            //Red
            //PORTD.2 = 0;
            digitalWrite(8,LOW); //blue
            //PORTD.3 = 0;
            digitalWrite(10,LOW); //green
            //PORTD.4 = 0;
            digitalWrite(11,HIGH); //red
            
            break;
            
            case 2 :
            //Green
            //PORTD.2 = 0;
            digitalWrite(8,LOW); //blue
            //PORTD.3 = 0;
            digitalWrite(10,HIGH); //green
            //PORTD.4 = 0;
            digitalWrite(11,LOW); //red
            
            break;
            
            case 3 :
            //Blue
            //PORTD.2 = 0;
            digitalWrite(8,HIGH); //blue
            //PORTD.3 = 0;
            digitalWrite(10,LOW); //green
            //PORTD.4 = 0;
            digitalWrite(11,LOW); //red
            
            break;
        }
        break;
        
        case 4 :
        //3
        switch(c)
        {   
            case 0 :
            //Off
            //PORTD.5 = 0;
            digitalWrite(12,LOW); //blue
            //PORTD.6 = 0;
            digitalWrite(13,LOW); //green
            //PORTD.7 = 0;
            digitalWrite(A0,LOW); //red
            
            break;
            
            case 1 :
            //Red
            //PORTD.5 = 0;
            digitalWrite(12,LOW); //blue
            //PORTD.6 = 0;
            digitalWrite(13,LOW); //green
            //PORTD.7 = 0;
            digitalWrite(A0,HIGH); //red
            
            break;
            
            case 2 :
            //Green
            //PORTD.5 = 0;
            digitalWrite(12,LOW); //blue
            //PORTD.6 = 0;
            digitalWrite(13,HIGH); //green
            //PORTD.7 = 0;
            digitalWrite(A0,LOW); //red
            
            break;
            
            case 3 :
            //Blue
            //PORTD.5 = 0;
            digitalWrite(12,HIGH); //blue
            //PORTD.6 = 0;
            digitalWrite(13,LOW); //green
            //PORTD.7 = 0;
            digitalWrite(A0,LOW); //red
            
            break;
        }
        break;
        
        case 5 :
        //5
        switch(c)
        {   
            case 0 :
            //Off
            //PORTB.0 = 0;
            digitalWrite(A1,LOW); //blue
            //PORTB.1 = 0;
            digitalWrite(A2,LOW); //green
            //PORTB.6 = 0;
            digitalWrite(A3,LOW); //red
            
            break;
            
            case 1 :
            //Red
            //PORTB.0 = 0;
            digitalWrite(A1,LOW); //blue
            //PORTB.1 = 0;
            digitalWrite(A2,LOW); //green
            //PORTB.6 = 0;
            digitalWrite(A3,HIGH); //red
            
            break;
            
            case 2 :
            //Green
            //PORTB.0 = 0;
            digitalWrite(A1,LOW); //blue
            //PORTB.1 = 0;
            digitalWrite(A2,HIGH); //green
            //PORTB.6 = 0;
            digitalWrite(A3,LOW); //red
            
            break;
            
            case 3 :
            //Blue
            //PORTB.0 = 0;
            digitalWrite(A1,HIGH); //blue
            //PORTB.1 = 0;
            digitalWrite(A2,LOW); //green
            //PORTB.6 = 0;
            digitalWrite(A3,LOW); //red
            
            
            break;
        }
        
        break;
        
    }
}

//H , M
void clk(int mt , int ht )
{
    
    int d=0 ;
    //clear
    for (d=0 ; d<5 ; d++)
    {
        led_sth[d] = 0 ;
        led_stm[d] = 0 ;
        led_result[d] = 0 ;
        led_color[d] = 0 ;
    }
    
    //H
    tp = 0;
    
    for (d=4 ; d>=0 ; d--)
    {
        tp += fib[d] ;
        
        if (tp <= ht)
        {
            led_sth[d] = 1 ;
        }
        else
        {
            tp -= fib[d] ;
        }
    }
    
    //M
    tp2 = 0;
    
    for (d=4 ; d>=0 ; d--)
    {
        tp2 += fibmin[d] ;
        
        if (tp2 <= mt)
        {
            led_stm[d] = 1 ;
        }
        else
        {
            tp2 -= fibmin[d] ;
        }
    }
    
    for (d=4 ; d>=0 ; d--)
    {
        //red
        if ( led_sth[d] == 1 && led_stm[d] == 0 )
        {
            led_result[d] = 1 ;
            led_color[d] = 1 ;
        }
        //green
        else if ( led_sth[d] == 0 && led_stm[d] == 1 )
        {
            led_result[d] = 1 ;
            led_color[d] = 2 ;
        }
        //blue
        else if( led_sth[d] == 1 && led_stm[d] == 1)
        {
            led_result[d] = 1 ;
            led_color[d] = 3 ;
        }
        //off
        else if ( led_sth[d] == 0 && led_stm[d] == 0 )
        {
            led_result[d] = 0 ;
            led_color[d] = 0 ;
        }
    }
}
/**
 * AttachMethod Stop
 */

/************************************
 * timeSetValueDs1307 Start
 ************************************/
  
//RealTimeClock RTC;//=new RealTimeClock();

#define Display_Clock_Every_N_Seconds 10           // n.secs to show date/time
#define Display_ShortHelp_Every_N_Seconds 60       // n.secs to show hint for help
//#define TEST_Squarewave
//#define TEST_StopStart
//#define TEST_1224Switch

int count=0;
char formatted[] = "00-00-00 00:00:00x";

/************************************
 * timeSetValueDs1307 Stop
 ************************************/
 
/************************************
 * function Process commands Start
 ************************************/
 void processCommand() {
  if(!Serial.available()) { return; }
  char command = Serial.read();
  int in,in2;
  delay(100);
  if( 'g' == command)//Get Status LED
  {    
    int number=SerialReadPosInt();
    if(number > 0 && number < 6)
    println(led_color[number-1]);
  }
  if(command == 'r')
  {
    String mm = "ledColor=[";
    for(int i = 0 ; i < 5 ; i++)
    {
      mm += led_color[i];
      mm += ",";
    }
    println(mm+"]");
  }
  if(command == 'l')
  {
    in = SerialReadPosInt();
    gameMode = in == 0 ? false : true;
  }
  if(command == 't')
  {
    String tempString = "";
    for(int i = 0 ; i < 5 ; i++)
    {
      print(led_color[i]);  
    }
    println("");
  }
  switch(command)
  {
  
    case 'H':
    case 'h':
      in=SerialReadPosInt();
      RTC.setHours(in);
      RTC.setClock();
      print("Setting hours to ");
      println(in);
      break;
    
    case 'I':
    case 'i':
      in=SerialReadPosInt();
      RTC.setMinutes(in);
      RTC.setClock();
      print("Setting minutes to ");
      println(in);
      break;
    
    case 'S':
    case 's':
      in=SerialReadPosInt();
      RTC.setSeconds(in);
      RTC.setClock();
      print("Setting seconds to ");
      println(in);
      break;
    
    case 'Y':
    case 'y':
      in=SerialReadPosInt();
      RTC.setYear(in);
      RTC.setClock();
      print("Setting year to ");
      println(in);
      break;
    
    case 'M':
    case 'm':
      in=SerialReadPosInt();
      RTC.setMonth(in);
      RTC.setClock();
      print("Setting month to ");
      println(in);
      break;
    
    case 'D':
    case 'd':
      in=SerialReadPosInt();
      RTC.setDate(in);
      RTC.setClock();
      print("Setting date to ");
      println(in);
      break;
    
    case 'W':
      print("Day of week is ");
      println((int) RTC.getDayOfWeek());
      break;
    
    case 'w':
      in=SerialReadPosInt();
      RTC.setDayOfWeek(in);
      RTC.setClock();
      print("Setting day of week to ");
      println(in);
      break;
    
    case 'A':
    case 'a':
      if(RTC.is12hour()) {
        RTC.setAM();
        RTC.setClock();
        println("Set AM.");
      } else {
        println("(Set hours only in 24-hour mode.)");
      }
      break;
    
    case 'P':
    case 'p':
      if(RTC.is12hour()) {
        RTC.setPM();
        RTC.setClock();
        println("Set PM.");
      } else {
        println("(Set hours only in 24-hour mode.)");
      }
      break;

    case 'q':
      RTC.sqwEnable(RTC.SQW_1Hz);
      println("Square wave output set to 1Hz");
      break;
    
    case 'Q':
      RTC.sqwDisable(0);
      println("Square wave output disabled (low)");
      break;
    
    case 'z':
      RTC.start();
      println("Clock oscillator started.");
    break;
    
    case 'Z':
      RTC.start(); //:) Dont shodown Clock , you mast change start to stop for use fiture
      println("Clock oscillator stopped.");
      break;
    
    case '>':
      in=SerialReadPosInt();
      in2=SerialReadPosInt();
      RTC.writeData(in, in2);
      print("Write to register ");
      print(in);
      print(" the value ");
      println(in2);
      break;
        
    case '<':
      in=SerialReadPosInt();
      in2=RTC.readData(in);
      print("Read from register ");
      print(in);
      print(" the value ");
      println(in2);
      break;
      
    case 'b':
      delay(100);
      int temp = SerialReadPosInt();
      int select = temp/10;
      int color = temp%10;
      led_color[select-1] = color;
      println("LED:"+(String)select+" Set Color :"+(String)color);
      //Game Mode Set
      gameMode = true;
      lastActionTime[0] = h;
      lastActionTime[1] = m;
      lastActionTime[2] = s;
      break;
       
    default:
      println("Unknown command. Try these:");
      println(" h## - set Hours [range 1..12 or 0..24]");
      println(" i## - set mInutes [range 0..59]");
      println(" s## - set Seconds [range 0..59]");
      println(" d## - set Date [range 1..31]");
      println(" m## - set Month [range 1..12]");
      println(" y## - set Year [range 0..99]");
      println(" w## - set arbitrary day of Week [range 1..7]");
      println(" t   - Get Status All LED =>00000 ");
      println(" g(LEDGet)# - get Color LED [range 1,2,3,4,5]");
      println(" b(LEDSet)## - set Color LED [range LED 1,2/*--1.2--*/,3/*--2--*/,4/*--3--*/,5][range color 0,1 ]");
      println(" l   -Set Game Mode Status");
      println(" r   -Print Led Status");
      println(" a   - set AM          p   - set PM");
      println(" z   - start clock     Z   - stop clock");
      println(" q   - SQW/OUT = 1Hz   Q   - stop SQW/OUT");
      println(" >##,###  - write to register ## the value ###");
      println(" <##      - read the value in register ##");
    
  }//switch on command
  
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

/************************************
 * function Process Commands Stop
 ************************************/

// Main function
void setup() 
{
  //For set pin mode
  //DDR
  initilze(); 

  //Wire.begin();
  Serial.begin(115200);
  h=10;m=10;s=0;
}

void loop() 
{
  //if Command Resive => process commands Function run
  if(Serial.available())
  {
    processCommand();
  }

  //read Clock of Ds1307
  RTC.readClock();

  //control counter for serial print
  count++;

  //send serial DateTime
  if(count % Display_Clock_Every_N_Seconds == 0 && false){
    print("=>");
    RTC.getFormatted(formatted);
    print(formatted);
    println("");
  }

   /******************************************
   * Start control Bug rtc
   ******************************************/
  #ifdef TEST_Squarewave
  if(count%10 == 0)
  {
  switch(count/10 % 6)
  {
    case 0:
    print("Squarewave disabled (low impedance): ");
    RTC.sqwDisable(0);
    println((int) RTC.readData(7));
    break;
    case 1:
    print("Squarewave disabled (high impedance): ");
    RTC.sqwDisable(1);
    println((int) RTC.readData(7));
    break;
    case 2:
    println("Squarewave enabled at 1 Hz");
    RTC.sqwEnable(RTC.SQW_1Hz);
    break;
    case 3:
    println("Squarewave enabled at 4.096 kHz");
    RTC.sqwEnable(RTC.SQW_4kHz);
    break;
    case 4:
    println("Squarewave enabled at 8.192 kHz");
    RTC.sqwEnable(RTC.SQW_8kHz);
    break;
    case 5:
    println("Squarewave enabled at 32.768 kHz");
    RTC.sqwEnable(RTC.SQW_32kHz);
    break;
    default:
    println("Squarewave test not defined");
  }//switch
  }
  #endif
  
  #ifdef TEST_StopStart
  if(count%10 == 0)
  {
  if(!RTC.isStopped()) 
  {
    if(RTC.getSeconds() < 45) 
    {
      println("Stopping clock for 10 seconds");
      //RTC.stop();
    }
    //if we have enough time
  } 
  else {
    RTC.setSeconds(RTC.getSeconds()+11);
    RTC.start();
    println("Adding 11 seconds and restarting clock");
  }
  }//if on a multiple of 10 counts
  #endif
  
  #ifdef TEST_1224Switch  
  if(count%10 == 0)
  {
    if(count %20 == 0)
    {
      println("switching to 12-hour time");
      RTC.switchTo12h();
      RTC.setClock();
    }
    else
    {
      println("switching to 24-hour time");
      RTC.switchTo24h();
      RTC.setClock();
    }
  }
  #endif

   /******************************************
   * Stop control Bug rtc
   ******************************************/

  /******************************************
   * Start BlackSun Clock process
   ******************************************/
bool bd=true;
if(bd)
{  
  //set My value process Clock
  m = 10;//RTC.getMinutes();
  h = 10;//RTC.getHours();
  bd = false;
}
  //hours Check !(H>12)
  if(h>=13)
  {
      h = h-12;
  }

  
  //Click Sowitch Clock Plus Plus
  if(digitalRead(9) != 1 && digitalRead(9) != temp1)
  {
     m+=5;
     if(m>=60)
     {
      m=0;
      h+=1;
     }
     RTC.setMinutes(m);
     RTC.setHours(h);
  }
  
  temp1 = digitalRead(9);
  
  
  //Counter
  d = 0;
  
  //1-9 , 10-59 
  one = m%10;
  
  if(!gameMode)
  {
  
    // 0 > one > 5
    if( 1 <= one && one <= 4 )
    {
      tmp = m/10 ;
      tmp *= 10;
      tmp += 5;
      
      clk(tmp ,h);
    }
    else if( 6 <= one && one <= 9)
    {
      tmp = m/10 ;
      tmp += 1;
      tmp *= 10;
      tmp += 0;
      
      clk(tmp ,h);
    }
    else
    {
      clk(m ,h);
    }

    print("gameMode=>");
    println((gameMode?"true":"false"));
  }

  //Counter Set Color & Turn off& on mode LED
  for (d=0 ; d<5 ; d++)
  {   
      if (led_result[d]==1) 
      {
        set_color(d+1,led_color[d]);
      }
      else
      {
        set_color(d+1,0);
      }
  }
  println("lastActionTime+limit: "+(lastActionTime[0]*60) + lastActionTime[1] + limitActionTime);
  println("TimeNow"+(h*60) + m);
  //Check Game Mode
  if(gameMode && (lastActionTime[0]*60) + lastActionTime[1] + limitActionTime <= (h*60) + m)
  {
    //Gamode Is Off
    gameMode = false;
  }
  
  /******************************************
   * Stop BlackSun Clock process
   ******************************************/
    
  
}
