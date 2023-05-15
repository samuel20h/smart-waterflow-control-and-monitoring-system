volatile int sensor_frequency;
unsigned int water_hour;
unsigned char flowmeter = 2;
unsigned long present_time;
unsigned long closedlooptime;
unsigned int buzzer=4;
void flow()
{
  sensor_frequency++;
  }
  void setup()
  {
  
    pinMode(flowmeter, INPUT);
     pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
    attachInterrupt(0,flow,RISING);
    sei();
    
    closedlooptime=present_time;
    }
    void loop()
    {
      
      digitalWrite(buzzer, HIGH);  
      present_time=millis();
     
      if (present_time>=(closedlooptime+1000))
      {
        closedlooptime>=present_time;
        water_hour=(sensor_frequency*60/7.5);
        sensor_frequency=0;
        Serial.print(water_hour,DEC);
      
        }
    }
