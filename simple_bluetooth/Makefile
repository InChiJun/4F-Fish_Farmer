CXX = gcc # 컴파일러 선택
LIBS = -lbluetooth # mosquitto 라이브러리 삽입

TARGET = simple_bluetooth # 실행파일 이름

SRCS = simple.c # 컴파일할 소스 파일 리스트

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) -o $@ $^ $(LIBS)

clean:
	rm -f $(TARGET)