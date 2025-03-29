//Master Code

#include<SPI.h>                        
#define push 2
#define LED 4           

int x;
int value;

void setup (void)

{
  Serial.begin(115200);               
  
  pinMode(push,INPUT);              
  pinMode(LED,OUTPUT);                  
  
  SPI.begin();                            
  SPI.setClockDivider(SPI_CLOCK_DIV8); 
  digitalWrite(SS,HIGH);                  
}

void loop(void)
{
  byte m_send,m_receive;          

  value = digitalRead(push); 

  if(value == HIGH)                
  {
    x = 1;
  }
  else
  {
    x = 0;
  }
  
  digitalWrite(SS, LOW);                  
  
  m_send = x;                            
  m_receive=SPI.transfer(m_send); 
  
  if(m_receive == 1)                 
  {
    digitalWrite(LED,HIGH);             
  }
  else
  {
   digitalWrite(LED,LOW);              
  }
  delay(1000);
}


//Slave Code

#include<SPI.h>
#define inputbutton 2
#define outputLED 4

volatile boolean received;
volatile byte Slavereceived,Slavesend;
int buttonvalue;
int x;

void setup()

{
  Serial.begin(115200);
  
  pinMode(inputbutton,INPUT); 
  pinMode(outputLED,OUTPUT);               
  pinMode(MISO,OUTPUT);                  

  SPCR |= _BV(SPE);                  
  received = false;

  SPI.attachInterrupt();                  
  
}

ISR (SPI_STC_vect)                        
{
  Slavereceived = SPDR;         
  received = true;                        
}

void loop()
{  
 if(received)                           
   {
      if (Slavereceived==1) 
      {
        digitalWrite(outputLED,HIGH);       
      }else
      {
        digitalWrite(outputLED,LOW);          
      }
      
      buttonvalue = digitalRead(inputbutton);  
      
      if (buttonvalue == HIGH)           
      {
        x=1;
        
      }else
      {
        x=0;
      }
      
  Slavesend=x;                             
  SPDR = Slavesend;                       
  delay(1000);
}
}
