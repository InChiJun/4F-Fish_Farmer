#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

int main(int argc, char** argv){
	inquiry_info *devices = NULL; // inquiry_info는 구조체
	int max_rsp, num_rsp;
	int adapter_id, sock, len, flags;
	int i;
	char addr[19] = {0};
	char name[248] = {0};
	adapter_id = hci_get_route (NULL); // adapter index값 반환
	sock = hci_open_dev(adapter_id); // 소켓 생성(리소스 할당). 실패 시 -1 리턴

	if(adapter_id < 0 || sock < 0){ // 소켓 생성 실패 시 종료
		perror("socket opening failed!");
		exit (1);
	}

	len = 8;
	max_rsp = 255;
	flags = IREQ_CACHE_FLUSH;
	devices = (inquiry_info*)malloc(max_rsp * sizeof(inquiry_info));
	num_rsp = hci_inquiry(adapter_id, len, max_rsp, NULL, &devices, flags); // 장치 검색 브로드캐스트
				// len은 동작 시간. 1.28s * len
				// flags 1 -> 기존 캐시값 flush하고 다시 inquiry
				// flags 0 -> 장치가 주변에 없어도 기존 캐시값 출력

	if(num_rsp < 0){
		perror("device search failed!");
	}

	for(i = 0; i < num_rsp ; i++){
		ba2str(&(devices+i)−>bdaddr, addr); // 주소구조체 -> 주소문자열
		memset(name, 0, sizeof(name));
		if(0 != hci_read_remote_name(sock, &(devices+i)−>bdaddr, sizeof(name), name, 0)){ // 디바이스 주소에서 이름 읽어오기
			strcpy(name, "[unknown]");
		}
		printf("%s %s\n", addr, name);
	}
	free(devices);
	close(sock);
	return 0;
}
