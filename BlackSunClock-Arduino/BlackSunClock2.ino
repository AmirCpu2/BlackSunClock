#include <Wire.h>
#include <RealTimeClockDS1307.h>

/***********************
 * AttachMethods Start
 **********************/
int h=0 ,m=0 ,s=0;
int tp=0,tp2=0,tmp=0,one=0,d=0,temp1=0 ;
int second=0,minute=5,hour=5;

//# 1 1 2 3 5
int led_sth [5] = {0,0,0,0,0};
int led_stm[5] = {0,0,0,0,0};

//result led turn on or turn off
int led_result[5] = {0,0,0,0,0};

//# off0 red1 green2 blue3
int led_color[5] = {0,0,0,0,0};

int fib [5]= {1,1,2,3,5};
int fibmin [5]= {5,5,10,15,25};

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
  switch(command)
  {
    case 'H':
    case 'h':
    in=SerialReadPosInt();
    RTC.setHours(in);
    RTC.setClock();
    Serial.print("Setting hours to ");
    Serial.println(in);
    break;
    case 'I':
    case 'i':
    in=SerialReadPosInt();
    RTC.setMinutes(in);
    RTC.setClock();
    Serial.print("Setting minutes to ");
    Serial.println(in);
    break;
    case 'S':
    case 's':
    in=SerialReadPosInt();
    RTC.setSeconds(in);
    RTC.setClock();
    Serial.print("Setting seconds to ");
    Serial.println(in);
    break;
    case 'Y':
    case 'y':
    in=SerialReadPosInt();
    RTC.setYear(in);
    RTC.setClock();
    Serial.print("Setting year to ");
    Serial.println(in);
    break;
    case 'M':
    case 'm':
    in=SerialReadPosInt();
    RTC.setMonth(in);
    RTC.setClock();
    Serial.print("Setting month to ");
    Serial.println(in);
    break;
    case 'D':
    case 'd':
    in=SerialReadPosInt();
    RTC.setDate(in);
    RTC.setClock();
    Serial.print("Setting date to ");
    Serial.println(in);
    break;
    case 'W':
    Serial.print("Day of week is ");
    Serial.println((int) RTC.getDayOfWeek());
    break;
    case 'w':
    in=SerialReadPosInt();
    RTC.setDayOfWeek(in);
    RTC.setClock();
    Serial.print("Setting day of week to ");
    Serial.println(in);
    break;
    case 't':
    case 'T':
    if(RTC.is12hour()) {
      RTC.switchTo24h();
      Serial.println("Switching to 24-hour clock.");
    } else {
      RTC.switchTo12h();
      Serial.println("Switching to 12-hour clock.");
    }
    RTC.setClock();
    break;
    
    case 'A':
    case 'a':
    if(RTC.is12hour()) {
      RTC.setAM();
      RTC.setClock();
      Serial.println("Set AM.");
    } else {
      Serial.println("(Set hours only in 24-hour mode.)");
    }
    break;
    
    case 'P':
    case 'p':
    if(RTC.is12hour()) {
      RTC.setPM();
      RTC.setClock();
      Serial.println("Set PM.");
    } else {
      Serial.println("(Set hours only in 24-hour mode.)");
    }
    break;

    case 'q':
    RTC.sqwEnable(RTC.SQW_1Hz);
    Serial.println("Square wave output set to 1Hz");
    break;
    case 'Q':
    RTC.sqwDisable(0);
    Serial.println("Square wave output disabled (low)");
    break;
    
    case 'z':
    RTC.start();
    Serial.println("Clock oscillator started.");
    break;
    case 'Z':
    RTC.start(); //:) Dont shodown Clock , you mast change start to stop for use fiture
    Serial.println("Clock oscillator stopped.");
    break;
    
    case '>':
    in=SerialReadPosInt();
    in2=SerialReadPosInt();
    RTC.writeData(in, in2);
    Serial.print("Write to register ");
    Serial.print(in);
    Serial.print(" the value ");
    Serial.println(in2);
    break;
        
    case '<':
    in=SerialReadPosInt();
    in2=RTC.readData(in);
    Serial.print("Read from register ");
    Serial.print(in);
    Serial.print(" the value ");
    Serial.println(in2);
    break;

    case "LED1" :
    Serial.println(led_color[0]);
    break;

    case "LED1.2" :
    Serial.println(led_color[1]);
    break;

    case "LED2" :
    Serial.println(led_color[2]);
    break;

    case "LED3" :
    Serial.println(led_color[3]);
    break;

    case "LED5" :
    Serial.println(led_color[4]);
    break;
    
    default:
    Serial.println("Unknown command. Try these:");
    Serial.println(" h## - set Hours [range 1..12 or 0..24]");
    Serial.println(" i## - set mInutes [range 0..59]");
    Serial.println(" s## - set Seconds [range 0..59]");
    Serial.println(" d## - set Date [range 1..31]");
    Serial.println(" m## - set Month [range 1..12]");
    Serial.println(" y## - set Year [range 0..99]");
    Serial.println(" w## - set arbitrary day of Week [range 1..7]");
    Serial.println(" t   - toggle 24-hour mode");
    Serial.println(" LED# - get Color LED [range 1,1.2,2..5]");
    Serial.println(" a   - set AM          p   - set PM");
    Serial.println();
    Serial.println(" z   - start clock     Z   - stop clock");
    Serial.println(" q   - SQW/OUT = 1Hz   Q   - stop SQW/OUT");
    Serial.println();
    Serial.println(" >##,###  - write to register ## the value ###");
    Serial.println(" <##      - read the value in register ##");
    
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
  if(count % Display_Clock_Every_N_Seconds == 0){
    Serial.print("=>");
    RTC.getFormatted(formatted);
    Serial.print(formatted);
    Serial.println();
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
    Serial.print("Squarewave disabled (low impedance): ");
    RTC.sqwDisable(0);
    Serial.println((int) RTC.readData(7));
    break;
    case 1:
    Serial.print("Squarewave disabled (high impedance): ");
    RTC.sqwDisable(1);
    Serial.println((int) RTC.readData(7));
    break;
    case 2:
    Serial.println("Squarewave enabled at 1 Hz");
    RTC.sqwEnable(RTC.SQW_1Hz);
    break;
    case 3:
    Serial.println("Squarewave enabled at 4.096 kHz");
    RTC.sqwEnable(RTC.SQW_4kHz);
    break;
    case 4:
    Serial.println("Squarewave enabled at 8.192 kHz");
    RTC.sqwEnable(RTC.SQW_8kHz);
    break;
    case 5:
    Serial.println("Squarewave enabled at 32.768 kHz");
    RTC.sqwEnable(RTC.SQW_32kHz);
    break;
    default:
    Serial.println("Squarewave test not defined");
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
      Serial.println("Stopping clock for 10 seconds");
      //RTC.stop();
    }
    //if we have enough time
  } 
  else {
    RTC.setSeconds(RTC.getSeconds()+11);
    RTC.start();
    Serial.println("Adding 11 seconds and restarting clock");
  }
  }//if on a multiple of 10 counts
  #endif
  
  #ifdef TEST_1224Switch  
  if(count%10 == 0)
  {
    if(count %20 == 0)
    {
      Serial.println("switching to 12-hour time");
      RTC.switchTo12h();
      RTC.setClock();
    }
    else
    {
      Serial.println("switching to 24-hour time");
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
  
  //set My value process Clock
  m = RTC.getMinutes();
  h = RTC.getHours();
  
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
  
  /******************************************
   * Stop BlackSun Clock process
   ******************************************/
    
  
}
