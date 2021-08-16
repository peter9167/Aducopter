//---------------------------------------------------------------------
// 이 프로그램은 에어온에서 만들어진 것입니다.
// Mr.Cho 06-01-20 AuduDrone Test
// 조종기로 브러쉬리스모터 제어하는 프로그램
------------------------------------------------------------------------
// RC position 1000 to 2000 writeMicroseconds
//----------------------------------------------------------------------

String readString;
#include <Servo.h> 

Servo mymotor;  // create servo object to control a servo 

//----------------------------------
// 조종기의 채널 -> 4개사용
#define Pitch       5
#define Roll        4
#define Throttle    2
#define Yaw         6
//----------------------------------

// Arduino nano to Motor pin map
// ---------------------------
// Motor   |   M1  M2  M3  M4
// ---------------------------
// Arduino |   3   10  9   11
// ---------------------------
int Motor1 = 3;
int Motor2 = 10;
int Motor3 = 9;
int Motor4 = 11;

//---------------------------------- 
// 조종기 채널에 사용하는 변수
unsigned int ch1; 
unsigned int ch2;
unsigned int ch3;
unsigned int ch4;

//----------------------------------
int LED = 13;

void setup() 
{
// 변속기 포트 초기화
  pinMode(Motor1,OUTPUT);
  mymotor.attach(Motor1);       // 서보모터 제어를 하기위한 핀 설정

// 13번핀 LED 켜기
  pinMode(LED,OUTPUT);
  digitalWrite(LED,HIGH);

  // 입력핀 설정
  pinMode(Pitch, INPUT); 
  pinMode(Roll, INPUT);
  pinMode(Throttle, INPUT);
  pinMode(Yaw, INPUT);
 
//------------------------------------------------------------------------------
  // 변속기 초기화 프로그램
  mymotor.writeMicroseconds(2000);      // 최대값 2000마이크로초 출력
  delay(2500);                          // 2.5초 지연
  mymotor.writeMicroseconds(1000);      // 최소값 1000마이크로초 출력
  delay(2500);                          // 2.5초 지연
//-------------------------------------------------------------------------------

// 시리얼 통신 설정
  Serial.begin(9600);
  Serial.println("AuduDrone Test");   // 시리얼 모니터롤 초기 시작 문자열을 출력
}

void loop() 
{
    // 수신기로 입력되는 PWM 값을 읽는다.
    ch1 = pulseIn(Pitch, HIGH, 20000); 
    ch2 = pulseIn(Roll, HIGH, 20000);
    ch3 = pulseIn(Throttle, HIGH, 20000);
    ch4 = pulseIn(Yaw, HIGH, 20000);

    // 시리얼모니터에 수신기로 부터 입력받은 데이터를 출력
    Serial.print("writing Microseconds: ");
    Serial.print("Channel 1 (Pitch) :");
    Serial.println(ch1);

    Serial.print("Channel 2 (Roll) :");
    Serial.println(ch2);

    Serial.print("Channel 3 (Throttle) :");
    Serial.println(ch3);

    Serial.print("Channel 4 (Yaw) :");
    Serial.println(ch4);

    // 변속기에 수신기로 부터 입력 받은 데이터를 출력
    mymotor.writeMicroseconds(ch1);

    delay(100);

}
