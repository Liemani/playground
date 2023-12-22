#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  const char* chipname = "gpiochip0";
  const char* consumer = "me";

  struct gpiod_chip* chip;
  struct gpiod_line* led;

//  chip = gpiod_chip_open_by_name(chipname);
  chip = gpiod_chip_open("/dev/gpiochip0");
  if (!chip)
  {
      fprintf(stderr, "chip is null\n");
      exit(0);
  }

  led = gpiod_chip_get_line(chip, 27);

  gpiod_line_request_output(led, consumer, 1);
  sleep(1);
  gpiod_line_request_output(led, consumer, 0);

  gpiod_line_release(led);
  gpiod_chip_close(chip);

  return 0;
}
