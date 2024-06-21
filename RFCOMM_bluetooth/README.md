# 디렉터리 소개
RFCOMM 프로토콜 블루투스 통신 예제 코드를 담은 디렉터리입니다.  
소켓 통신 과정을 담고 있습니다.  
server 코드와 client 코드가 분리되어 있습니다.  

# server.c
- RFCOMM 서버 코드를 담고 있습니다.  

# client.c
- RFCOMM 클라이언트 코드를 담고 있습니다.  
- (디바이스 맥주소 부분 해결 필요)

# Makefile
블루투스 예제 코드에 필요한 라이브러리를 삽입하였습니다.  
server 실행파일을 만들 때는 make server,  
client 실행파일을 만들 때는 make client  
명령어로 실행파일을 만드시고, server(client)로 실행하시면 됩니다.  