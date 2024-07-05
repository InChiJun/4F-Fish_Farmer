# 브랜치 소개
C언어로 RaspberryPi Hub 코드를 구현하였습니다.  
RaspberryPi 중앙 장치에서 데이터를 처리하는 기능을 담당합니다.  

# raspberryPi_hub.c 기능 소개
- 블루투스 송수신  
  - 시리얼 포트로 연결된 블루투스 모듈로 읽기/쓰기 구현  
- MQTT 데이터 게시/구독  
  - MQTT 게시?  
  - MQTT 구독하여 수신된 데이터 MariaDB에 저장


# Makefile
실행파일 생성 시 라이브러리 삽입과 코드 전환의 편의성을 위해 makefile을 생성하였습니다.  

# 실행파일 생성
"make" 명령어로 실행파일을 생성하고, "hub_run" 파일을 실행하면 됩니다.  