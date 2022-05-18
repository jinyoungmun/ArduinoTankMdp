#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출
 
int blueTx=2;   //Tx (보내는핀 설정)at
int blueRx=3;   //Rx (받는핀 설정)
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
char test;
void setup() 
{
  Serial.begin(9600);   //시리얼모니터
  mySerial.begin(9600); //블루투스 시리얼
}
void loop()
{
  if (mySerial.available()) {       
    print(mySerial.read());  //블루투스측 내용을 시리얼모니터에 출력
  }
  test = mySerial.read();
  if (Serial.available()) {         
    print(Serial.read());  //시리얼 모니터 내용을 블루추스 측에 WRITE
  }
    if(test == 'w')    //입력된 데이터가 '1'이라면
    {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);   //앞으로 회전
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }
    else if(test == 's') //입력된 데이터가 '2'라면
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);  //뒤로 회전 (어떤 방향으로 꽂았느냐에 따라서 방향 반대)
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
    else if(test == 'd')
    {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);  //뒤로 회전 (어떤 방향으로 꽂았느냐에 따라서 방향 반대)
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
    else if(test == 'a')
    {      
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);  //뒤로 회전 (어떤 방향으로 꽂았느냐에 따라서 방향 반대)
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);      
    }
    else if(test == 'x')
    {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);  //뒤로 회전 (어떤 방향으로 꽂았느냐에 따라서 방향 반대)
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
    }
}
