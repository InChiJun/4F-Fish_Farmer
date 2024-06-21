CXX = gcc # 컴파일러 선택
LIBS = -lbluetooth # bluetooth 라이브러리 삽입

TARGET := server
SRCS := server.c

# 인자값에 따라 다른 실행파일 생성
ifeq ($(filter server,$(MAKECMDGOALS)),server)
    TARGET := server
	SRCS := server.c
endif
ifeq ($(filter client,$(MAKECMDGOALS)),client)
    TARGET := client
	SRCS := client.c
endif

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) -o $@ $^ $(LIBS)

clean:
	rm -f $(TARGET)