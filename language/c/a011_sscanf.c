#include <stdio.h>

#define MESSAGE "{\"temperature\":12.34,\"humidity\":23.45}"

int main() {
  float temperature;
  float humidity;

  ssize_t sscanfReturnValue = sscanf(MESSAGE, "{\"temperature\":%f,\"humidity\":%f}", NULL, NULL);
  printf("sscanfReturnValue : %zd, temperature : %.2f, humidity : %.2f\n", sscanfReturnValue, temperature, humidity);

  return 0;
}
