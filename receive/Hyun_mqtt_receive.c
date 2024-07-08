#include <mosquitto.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <stdbool.h>
#include <pthread.h>
#include <time.h>
#include <mariadb/mysql.h>

#define SERIAL_PORT "/dev/ttyUSB0"
#define BAUD_RATE B9600

int serial_fd;
char p_topic1[] = "sensor/value/Sensor1";
char p_topic2[] = "sensor/value/Sensor2";
char p_topic3[] = "sensor/value/Sensor3";
char p_topic4[] = "sensor/value/Sensor4";
char p_topic5[] = "sensor/value/Sensor5";

char p_topic6[] = "sensor/alarm/Sensor1";
char p_topic7[] = "sensor/alarm/Sensor2";
char p_topic8[] = "sensor/alarm/Sensor3";
char p_topic9[] = "sensor/alarm/Sensor4";
char p_topic10[] = "sensor/alarm/Sensor5";

void *read_serial(void *arg);
pthread_mutex_t serial_mutex = PTHREAD_MUTEX_INITIALIZER;

void setup_serial_port();
void publish_sensor_data(struct mosquitto *mosq, char *buffer);
void on_connect(struct mosquitto *mosq, void *obj, int reason_code);
void on_publish(struct mosquitto *mosq, void *obj, int mid);
void on_message(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message);

void setup_serial_port()
{
    serial_fd = open(SERIAL_PORT, O_RDWR | O_NOCTTY | O_NDELAY);
    if (serial_fd < 0)
    {
        perror("Error opening serial port");
        exit(EXIT_FAILURE);
    }

    struct termios options;
    tcgetattr(serial_fd, &options);
    options.c_cflag = BAUD_RATE | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    tcflush(serial_fd, TCIFLUSH);
    tcsetattr(serial_fd, TCSANOW, &options);
}

void publish_sensor_data(struct mosquitto *mosq, char *buffer)
{
    char payload[256];
    snprintf(payload, sizeof(payload), "%s", buffer);
    int rc = mosquitto_publish(mosq, NULL, "example/temperature", strlen(payload), payload, 2, false);

    if (rc != MOSQ_ERR_SUCCESS)
    {
        fprintf(stderr, "Error publishing: %s\n", mosquitto_strerror(rc));
    }
}

void on_connect(struct mosquitto *mosq, void *obj, int reason_code)
{
    printf("on_connect: %s\n", mosquitto_connack_string(reason_code));
    if (reason_code != 0)
    {
        mosquitto_disconnect(mosq);
    }
}

void on_publish(struct mosquitto *mosq, void *obj, int mid)
{
    printf("Message with mid %d has been published.\n", mid);
}

void *read_serial(void *arg)
{
    time_t previous_time = time(NULL);

    struct mosquitto *mosq;
    int rc;
    mosquitto_lib_init();
    mosq = mosquitto_new(NULL, true, NULL);
    if (mosq == NULL)
    {
        fprintf(stderr, "Error: Out of memory.\n");
        pthread_exit(NULL);
    }

    mosquitto_connect_callback_set(mosq, on_connect);
    mosquitto_publish_callback_set(mosq, on_publish);

    rc = mosquitto_connect(mosq, "10.10.20.7", 1883, 60);
    if (rc != MOSQ_ERR_SUCCESS)
    {
        mosquitto_destroy(mosq);
        fprintf(stderr, "Error: %s\n", mosquitto_strerror(rc));
        pthread_exit(NULL);
    }

    rc = mosquitto_loop_start(mosq);
    if (rc != MOSQ_ERR_SUCCESS)
    {
        mosquitto_destroy(mosq);
        fprintf(stderr, "Error: %s\n", mosquitto_strerror(rc));
        pthread_exit(NULL);
    }

    while (true)
    {
        usleep(1000 * 1000);
        char buffer[256] = {0};
        int ret = read(serial_fd, buffer, sizeof(buffer) - 1); // Reserve space for null-terminator

        if ((ret > 0) && (time(NULL) - previous_time > 3))
        {
            previous_time = time(NULL);
            buffer[ret] = '\0'; // Ensure null-terminated string
            publish_sensor_data(mosq, buffer);
            printf("Publishing: %s\n", buffer);
            usleep(1000 * 50);
        }
    }

    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();
    pthread_exit(NULL);
}

void on_message(struct mosquitto *mosq, void *userdata, const struct mosquitto_message *message)
{
    printf("Topic: %s ", message->topic);
    printf("Received message: %s\n", (char *)message->payload);
    char buffer[256];
    int ret;

    // DB 초기화(디비 코드 메인으로)
    MYSQL *db_conn;
    db_conn = mysql_init(NULL);

    // 데이터베이스 초기화 오류시
    if (db_conn == NULL){
        fprintf(stderr, "Error: mysql_init() failed\n");
    }

    // 데이터베이스 연결
    if (mysql_real_connect(db_conn, "localhost", "root", "ubuntu", "4FSensor", 1883, NULL, 0) == NULL){
        fprintf(stderr, "Error: mysql_real_connect() failed\n"); // 연결 오류시 출력
        mysql_close(db_conn);
    }

    // 현재시간 받아오는 코드
    time_t previous_time=time(NULL);
    previous_time=time(NULL);
    char date[20];
    time_t now = time(NULL);
    strftime(date, 20, "%Y-%m-%d %H:%M", localtime(&now));

    char query[100]; // 쿼리 문자열
    if (strcmp(message->topic, p_topic1) == 0)
    {
        snprintf(buffer, sizeof(buffer), "S1%s\r\n", (char *)message->payload);
        sprintf(query, "INSERT INTO temperature (`collect_time`,`temp_value`) VALUES ('%s','%s')", date, (char *)message->payload);
        mysql_query(db_conn, query);
    }
    else if (strcmp(message->topic, p_topic2) == 0)
    {
        snprintf(buffer, sizeof(buffer), "S2%s\r\n", (char *)message->payload);
        sprintf(query, "INSERT INTO humidity (`collect_time`,`humi_value`) VALUES ('%s','%s')", date, (char *)message->payload);
        mysql_query(db_conn, query);
    }
    else if (strcmp(message->topic, p_topic3) == 0)
    {
        snprintf(buffer, sizeof(buffer), "S3%s\r\n", (char *)message->payload);
        sprintf(query, "INSERT INTO pH (`collect_time`,`pH_value`) VALUES ('%s','%s')", date, (char *)message->payload);
        mysql_query(db_conn, query);
    }
    else if (strcmp(message->topic, p_topic4) == 0)
    {
        snprintf(buffer, sizeof(buffer), "S4%s\r\n", (char *)message->payload);
        sprintf(query, "INSERT INTO TDS (`collect_time`,`TDS_value`) VALUES ('%s','%s')", date, (char *)message->payload);
        mysql_query(db_conn, query);
    }
    else if (strcmp(message->topic, p_topic5) == 0)
    {
        snprintf(buffer, sizeof(buffer), "S5%s\r\n", (char *)message->payload);
        sprintf(query, "INSERT INTO waterLevel (`collect_time`,`waterLevel_value`) VALUES ('%s','%s')", date, (char *)message->payload);
        mysql_query(db_conn, query);
    }
    else
    {
        snprintf(buffer, sizeof(buffer), "A%s\r\n", (char *)message->payload);
    }

    // 시리얼 포트 쓰기 동기화
    pthread_mutex_lock(&serial_mutex);
    ret = write(serial_fd, buffer, strlen(buffer));
    pthread_mutex_unlock(&serial_mutex);

    if (ret < 0)
    {
        perror("Error writing to serial port");
    }
    else
    {
        printf("Written to serial port: %s\n", buffer);
    }
}

int main()
{
    setup_serial_port();

    struct mosquitto *mosq = NULL;
    mosquitto_lib_init();
    mosq = mosquitto_new(NULL, true, NULL);
    if (!mosq)
    {
        fprintf(stderr, "Error: Out of memory.\n");
        return 1;
    }

    mosquitto_connect_callback_set(mosq, on_connect);
    mosquitto_message_callback_set(mosq, on_message);

    int rc = mosquitto_connect(mosq, "10.10.20.7", 1883, 60);
    if (rc != MOSQ_ERR_SUCCESS)
    {
        fprintf(stderr, "Error: Could not connect to MQTT broker.\n");
        mosquitto_destroy(mosq);
        mosquitto_lib_cleanup();
        return 1;
    }

    rc = mosquitto_subscribe(mosq, NULL, "sensor/+/+", 0);
    if (rc != MOSQ_ERR_SUCCESS)
    {
        fprintf(stderr, "Error: Could not subscribe to topic.\n");
        mosquitto_destroy(mosq);
        mosquitto_lib_cleanup();
        return 1;
    }

    write(serial_fd, "AT+DISC?\r\n", 10);
    usleep(5000 * 1000);
    char buffer[256] = {0};
    int ret = read(serial_fd, buffer, sizeof(buffer) - 1); // Reserve space for null-terminator
    if ((ret > 0) )
    {
        buffer[ret] = '\0'; // Ensure null-terminated string
        printf("Publishing: %s\n", buffer);
        usleep(1000 * 50);
    }
    int num;
    scanf("%d", &num);
    if (num == 0)
    {
        write(serial_fd, "AT+CONN0\r\n", 10);
        usleep(1000 * 1000);
    }

    pthread_t serial_thread;
    if (pthread_create(&serial_thread, NULL, read_serial, NULL))
    {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    while (1)
    {
        rc = mosquitto_loop(mosq, -1, 1);
        if (rc != MOSQ_ERR_SUCCESS)
        {
            fprintf(stderr, "Error: Could not start message loop.\n");
            mosquitto_destroy(mosq);
            mosquitto_lib_cleanup();
            return 1;
        }
    }

    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();
    close(serial_fd);
    return 0;
}