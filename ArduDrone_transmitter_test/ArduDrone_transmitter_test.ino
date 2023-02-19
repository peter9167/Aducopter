//-------------------------------------------------------
// 무단으로 복제를 해서는 안됩니다.
//-------------------------------------------------------

String readString;
#include <Servo.h> 
Servo mymotor; 

//----------------------------------
// 조종기의 채널 -> 4개사용 
#define Pitch       5
#define Roll        4
#define Throttle    2
#define Yaw         6

//---------------------------------- 
// 조종기 채널에 사용하는 변수
unsigned int ch1; 
unsigned int ch2;
unsigned int ch3;
unsigned int ch4;

int Motor1 = 3;
int Motor2 = 10;
int Motor3 = 9;
int Motor4 = 11;

void setup() 
{
  // 입력핀 설정
  pinMode(Pitch, INPUT); 
  pinMode(Roll, INPUT);
  pinMode(Throttle, INPUT);
  pinMode(Yaw, INPUT);

  pinMode(Motor1,OUTPUT);
  pinMode(Motor2,OUTPUT);
  pinMode(Motor3,OUTPUT);
  pinMode(Motor4,OUTPUT);

  mymotor.attach(Motor1); 
  
//------------------------------------------------------------------------------
  // 변속기 초기화 프로그램
  mymotor.writeMicroseconds(2000);      // set initial servo position if desired
  delay(2500);                          // 2.5s delay
  mymotor.writeMicroseconds(1000);      // set initial servo position if desired
  delay(2500);                          // 2.5s delay
//-------------------------------------------------------------------------------

  Serial.begin(9600); // Pour a bowl of Serial

}

void loop() 
{
  // 수신기로 입력되는 PWM값을 읽는다.
//  ch1 = pulseIn(Pitch, HIGH, 20000); 
//  ch2 = pulseIn(Roll, HIGH, 20000);
  ch3 = pulseIn(Throttle, HIGH, 20000);
//  ch4 = pulseIn(Yaw, HIGH, 20000);
  
//  Serial.print("Channel 1 (Pitch) :"); // Print the value of 
//  Serial.println(ch1);        // each channel

//  Serial.print("Channel 2 (Roll) :");
//  Serial.println(ch2);

  Serial.print("Channel 3 (Throttle) :");
  Serial.println(ch3);

//  Serial.print("Channel 4 (Yaw) :");
//  Serial.println(ch4);

  mymotor.write(ch3);

  delay(100); // I put this here just to make the terminal 
              // window happier
              
}
