CC = gcc # 컴파일러 선택
LIBS = -lmosquitto -lmariadb # 라이브러리 삽입

TARGET = hub_run # 실행파일 이름

SRCS = raspberryPi_hub.c # 컴파일할 소스 파일 리스트

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) -o $@ $^ $(LIBS)

clean:
	rm -f $(TARGET)