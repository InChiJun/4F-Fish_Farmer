CXX = gcc # 컴파일러 선택
LIBS = -lbluetooth # bluetooth 라이브러리 삽입

# 인자값에 따라 다른 실행파일 생성
ifeq ($(filter server client,$(MAKECMDGOALS)),server)
    TARGET := RFCOMM_server
else ifeq ($(filter server client,$(MAKECMDGOALS)),client)
    TARGET := RFCOMM_client
endif

#인자값에 따라 다른 소스코드 컴파일
ifeq ($(filter server client,$(MAKECMDGOALS)), server)
	SRCS := RFCOMM_server.c
else ifeq ($(filter server client,$(MAKECMDGOALS)), client)
	SRCS := RFCOMM_client.c
endif

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) -o $@ $^ $(LIBS)

clean:
	rm -f $(TARGET)