#include <mosquitto.h>
#include <ctime> // 실시간 받아오는 라이브러리
#include <cstring>
#include <iostream>

using namespace std;

// MQTT 메시지 수신 콜백 함수
void on_message(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message)
{
    cout << "Received message: " << static_cast<const char *>(message->payload) << std::endl; // 수신된 MQTT 메세지 출력
}

int main()
{
    struct mosquitto *mosq = nullptr;

    // Mosquitto 라이브러리 초기화
    mosquitto_lib_init();

    // Mosquitto 클라이언트 생성
    mosq = mosquitto_new(nullptr, true, nullptr);
    if (!mosq)
    {
        cerr << "Error: Out of memory." << endl; // 메모리 할당 오류시 출력
        return 1;
    }

    // MQTT 브로커에 연결
    int rc = mosquitto_connect(mosq, "10.10.10.19", 1883, 60);
    if (rc != MOSQ_ERR_SUCCESS)
    {
        cerr << "Error: Could not connect to MQTT broker." << endl; // MQtt 브로커 연결 오류시 출력
        mosquitto_destroy(mosq);
        mosquitto_lib_cleanup();
        return 1;
    }
    
    // 메시지 수신 콜백 함수 설정
    mosquitto_message_callback_set(mosq, on_message);

    // 특정 토픽 구독
    rc = mosquitto_subscribe(mosq, nullptr, "sensor/image", 0);
    if (rc != MOSQ_ERR_SUCCESS)
    {
        cerr << "Error: Could not subscribe to topic." << endl; // 특정 토픽 구독 오류시 출력
        mosquitto_destroy(mosq);
        mosquitto_lib_cleanup();
        return 1;
    }

    // 메시지 루프 시작
    rc = mosquitto_loop_forever(mosq, -1, 1);
    if (rc != MOSQ_ERR_SUCCESS)
    {
        cerr << "Error: Could not start message loop." << endl; // 메시지 루프 시작 오류 출력
        mosquitto_destroy(mosq);
        mosquitto_lib_cleanup();
        return 1;
    }

    return 0;
}