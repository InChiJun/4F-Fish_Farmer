#include <iostream>
#include <string>
#include "mqtt/async_client.h"  // Paho MQTT C++ 클라이언트 헤더 파일

const std::string SERVER_ADDRESS("tcp://10.10.10.19:1883");  // MQTT 브로커 주소
const std::string CLIENT_ID("raspberryPi");  // 클라이언트 ID
const std::string TOPIC("sensor/");  // 구독할 토픽

class mqtt_callback : public virtual mqtt::callback {
public:
    virtual void connection_lost(const std::string& cause) override {
        std::cout << "\nConnection lost" << std::endl;
        if (!cause.empty())
            std::cout << "\tcause: " << cause << std::endl;
    }

    virtual void delivery_complete(mqtt::delivery_token_ptr token) override {}

    virtual void message_arrived(const mqtt::message_ptr& msg) override {
        std::cout << "Message arrived:\n" << "\ttopic: '" << msg->get_topic() << "'"
                  << "\n\tmessage: '" << msg->to_string() << "'"
                  << "\n\tQoS: " << msg->get_qos() << std::endl;

        // 여기서 메시지 값을 가져와 처리할 수 있음
        std::string payload = msg->to_string();
        process_message(payload);
    }

    void process_message(const std::string& message) {
        // 메시지 처리 로직을 여기에 구현
        std::cout << "Processing message: " << message << std::endl;
    }
};

int main() {
    mqtt::async_client client(SERVER_ADDRESS, CLIENT_ID);

    mqtt_callback cb;
    client.set_callback(cb);

    mqtt::connect_options connOpts;
    connOpts.set_clean_session(true);

    try {
        std::cout << "Connecting to MQTT broker..." << std::flush;
        client.connect(connOpts)->wait_for(std::chrono::seconds(5));
        std::cout << "OK\n" << std::endl;

        std::cout << "Subscribing to topic '" << TOPIC << "'..." << std::flush;
        client.subscribe(TOPIC, 0)->wait();  // QoS 0으로 topic 구독
        std::cout << "OK\n" << std::endl;

        std::cout << "Press Enter to quit..." << std::endl;
        std::cin.ignore();

        std::cout << "\nDisconnecting from MQTT broker..." << std::flush;
        client.unsubscribe(TOPIC)->wait();
        client.disconnect()->wait();
        std::cout << "OK" << std::endl;

    } catch (const mqtt::exception& exc) {
        std::cerr << "Error: " << exc.what() << std::endl;
        return 1;
    }

    return 0;
}