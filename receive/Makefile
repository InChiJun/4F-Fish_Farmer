CXX = g++ # 컴파일러 선택
LIBS = -lmosquitto # mosquitto 라이브러리 삽입

TARGET = mqtt_receiver # 실행파일 이름

SRCS = mqtt_receive_code.cpp # 컴파일할 소스 파일 리스트

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) -o $@ $^ $(LIBS)

clean:
	rm -f $(TARGET)