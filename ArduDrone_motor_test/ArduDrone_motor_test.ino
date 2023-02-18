//--------------------------------------------------------------------- 
// Mr.LEE 06-01-20 AuduDrone Motor Test
//---------------------------------------------------------------------
// servo position 0 to 180 Degree
// RC position 1000 to 2000 writeMicroseconds 
//---------------------------------------------------------------------

String readString;   //문자열을 입력 받고, 객체 생성을 위한.
#include <Servo.h>  //Servo 해더파일 호출
 
Servo mymotor;      //서보를 제어하기 위해 서보 객체를 생성

// Arduino nano to Motor pin map
// ---------------------------
// Motor   |   M1  M2  M3  M4
// ---------------------------
// Arduino |   3   10  9   11
// ---------------------------
int Motor1 = 3; //M1모터 3핀으로 설정
int Motor2 = 10; //M2모터 10핀으로 설정
int Motor3 = 9; //M3모터 9핀으로 설정
int Motor4 = 11; //M4모터 11핀으로 설정



int LED = 13; //LED 13번 핀으로 설정
 
void setup() 
{
  pinMode(Motor1  ,OUTPUT); //Motor1번을 출력 초기화 작업
  pinMode(LED,OUTPUT);    //LED핀을 출력 초기화 작업
  digitalWrite(LED,HIGH); //LED HIGH
  
  Serial.begin(9600);     //Serial 모니터 통신 속도 9600으로 초기화
  mymotor.attach(Motor1); //드론 모터 제어 핀 초기화

//------------------------------------------------------------------------------
  // 변속기 초기화 프로그램
  mymotor.writeMicroseconds(2000);      //원하는 경우 초기 서보 위치 설정
  delay(2500);                          // 2.5s delay
  mymotor.writeMicroseconds(1000);      // set initial servo position if desired
  delay(2500);                          // 2.5s delay
//-------------------------------------------------------------------------------
  
  Serial.println("AuduDrone Motor Test"); // so I can keep track of what is loaded
}

void loop() 
{
  // 사용되는 지역변수 설정
  char c;
  int n;
    
  while (Serial.available()) //Serial.available() 값이 1 이상이라면 반복
  {
    c = Serial.read();     //c변수에 Serial 모니터에 입력 받은 값을 넣는다.
    readString += c;             //c변수에 값을 readString객체에 더한다.
    delay(2);                    //버퍼를 다음 문자로 채울 수 있는 느린 루프
  }

  if (readString.length() > 0) 
  {
    Serial.println(readString);     //캡처한 문자열을 볼 수 있도록 한다.
    n = readString.toInt();      //readString을 변수n에 넣음으로써 숫자로 변환합니다.

    // auto select appropriate value, copied from someone elses code.
    if(n >= 500) //n값이 500 이상이라면
    {
      Serial.print("writing Microseconds: ");
      Serial.println(n); //모터 입력 받은 속도
      mymotor.writeMicroseconds(n);
    }
    else
    {   
      Serial.print("writing Angle: ");
      Serial.println(n);
      mymotor.write(n);
    }

    readString="";            // empty for next input
  }  
}
