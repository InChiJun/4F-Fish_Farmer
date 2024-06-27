#include <stdio.h>
#include <stdlib.h>
#include <mosquitto.h>
#include <time.h> // 실시간 받아오는 라이브러리
#include <string.h>
#include <unistd.h> // sleep 함수를 사용하기 위한 헤더 파일

// MQTT 메시지 수신 콜백 함수
void on_message(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message)
{
    printf("Received message: %s\n", (char*)message->payload); // 수신된 MQTT 메세지 출력
}

int main()
{
    struct mosquitto *mosq = NULL;

    // Mosquitto 라이브러리 초기화
    mosquitto_lib_init();

    // Mosquitto 클라이언트 생성
    mosq = mosquitto_new(NULL, true, NULL);
    if (!mosq)
    {
        fprintf(stderr, "Error: Out of memory.\n"); // 메모리 할당 오류시 출력
        return 1;
    }

    // MQTT 브로커에 연결
    int rc = mosquitto_connect(mosq, "10.10.10.19", 1883, 60);
    if (rc != MOSQ_ERR_SUCCESS)
    {
        fprintf(stderr, "Error: Could not connect to MQTT broker.\n"); // MQtt 브로커 연결 오류시 출력
        mosquitto_destroy(mosq);
        mosquitto_lib_cleanup();
        return 1;
    }
    
    // 메시지 수신 콜백 함수 설정
    mosquitto_message_callback_set(mosq, on_message);

    // 특정 토픽 구독
    rc = mosquitto_subscribe(mosq, NULL, "sensor/", 0);
    if (rc != MOSQ_ERR_SUCCESS)
    {
        fprintf(stderr, "Error: Could not subscribe to topic.\n");
        mosquitto_destroy(mosq);
        mosquitto_lib_cleanup();
        return 1;
    }

    // 메시지 루프 시작
    while(1){
        rc = mosquitto_loop(mosq, -1, 1);
        if (rc != MOSQ_ERR_SUCCESS)
        {
            fprintf(stderr, "Error: Could not start message loop.\n"); // 메시지 루프 시작 오류 출력
            mosquitto_destroy(mosq);
            mosquitto_lib_cleanup();
            return 1;
        }
    }

    if (rc != MOSQ_ERR_SUCCESS)
    {
        fprintf(stderr, "Error: Could not start message loop.\n"); // 메시지 루프 시작 오류 출력
        mosquitto_destroy(mosq);
        mosquitto_lib_cleanup();
        return 1;
    }
    return 0;
}