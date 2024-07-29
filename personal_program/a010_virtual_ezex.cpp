#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <cstring>
#include <thread>
#include <chrono>
#include <ctime>

// <?xml version="1.0" encoding="UTF-8" ?><reportStatusEvent><socket><object>000D6F0012576041</object><endpoint>1</endpoint><timestamp>2024-04-19T09:30:08Z</timestamp><energy>73.8805</energy><power>0.0</power><current>0.0</current><voltage>217.838</voltage><enable>0</enable><threshold>1000</threshold></socket></reportStatusEvent>

#define SERVER_IP "127.0.0.1"  // Replace with server IP address
#define SERVER_PORT 3231        // Replace with server port number
#define DATA_TO_SEND_HEAD "<?xml version=\"1.0\" encoding=\"UTF-8\" ?><reportStatusEvent><socket><object>000D6F0012576041</object><endpoint>1</endpoint><timestamp>"
#define DATA_DATE "2024-04-19T09:30:08Z"
#define DATA_TO_SEND_FOOT "</timestamp><energy>73.8805</energy><power>0.0</power><current>0.0</current><voltage>217.838</voltage><enable>0</enable><threshold>1000</threshold></socket></reportStatusEvent>"
#define SENDING_INTERVAL 5      // Sending interval in seconds

char* currentTimeString() {
  std::time_t time = std::time(nullptr);
  const struct tm* localtime = std::localtime(&time);
  return std::asctime(localtime);
}

int main() {
  int sockfd = socket(PF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    std::cerr << "Error creating socket: " << strerror(errno) << std::endl;
    return 1;
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

  if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
    std::cerr << "Error connecting to server: " << strerror(errno) << std::endl;
    close(sockfd);
    return 1;
  }

  std::cout << "Connected to server!" << std::endl;

  while (true) {
    const std::string timeString = std::string(currentTimeString());
//    const std::string timeString = DATA_DATE;
    std::string dataToSend = DATA_TO_SEND_HEAD + timeString + DATA_TO_SEND_FOOT;

    int sent_bytes = send(sockfd, dataToSend.c_str(), strlen(dataToSend.c_str()), 0);
    if (sent_bytes == -1) {
      std::cerr << "Error sending data: " << strerror(errno) << std::endl;
      break;
    }

    std::cout << "Data has sent : " << timeString << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(SENDING_INTERVAL));
  }

  close(sockfd);

  return 0;
}
