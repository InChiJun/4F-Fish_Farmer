#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

int main(int argc , char **argv){
	struct sockaddr_rc loc_addr = {0}, rem_addr = {0};
	char buf[1024] = {0};
	int server_socket, client, bytes_read;
	unsigned int opt = sizeof(rem_addr);

	// allocate socket 
	server_socket = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
	// AF_BLUETOOTH = bluetooth 소켓, SOCK_STREAM = stream, BTPROTO_RFCOMM = 블루투스 프로토콜

	// bind socket to port 1 of the first available bluetooth adapter
	loc_addr.rc_family = AF_BLUETOOTH; // 블루투스 프로토콜 사용
	loc_addr.rc_bdaddr = *BDADDR_ANY; // 로컬디바이스 주소
	loc_addr.rc_channel = 1; // 포트 번호
	bind(server_socket, (struct sockaddr *)&loc_addr, sizeof(loc_addr)); // 소켓 정보들 묶기

	// put socket into listening mode
	if(listen(server_socket, 2) == -1){ // 클라이언트 대기
        printf("listen error\n");
    }

	while (1)
	{
		// accept one connection
		client = accept (server_socket, (struct sockaddr *)&rem_addr, &opt); // 클라이언트 접속하면 새 소켓 생성
		ba2str(&rem_addr.rc_bdaddr, buf); // 주소구조체 -> 주소문자열
		fprintf(stderr, "accepted connection from %s\n", buf); // buf에 담긴 connection 주소 출력
		memset(buf, 0, sizeof(buf));

		// read data from the client
		bytes_read = recv(client, buf, sizeof(buf), 0); // 클라이언트에서 온 데이터 수신
		if(bytes_read > 0){ // 데이터 수신 성공 시
			printf("received [%s]\n", buf);
		}
	}

	// close connection
	close(client);
	close(server_socket);
	return 0;
}
