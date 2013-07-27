#include <stdio.h>

float c_to_f(float c);
float f_to_c(float f);

float c_to_f(float c)
{
  return (9.0/5.0 * c) + 32;
}

float f_to_c(float f)
{
  return 5.0/9.0 * (f - 32);
}

int main(int argc, char *argv[])
{
  int fahr;

  puts("Fahrenheit -> Celcius");

  for(fahr = 0; fahr <= 300; fahr += 20) {
    printf("%3d   %6.2f\n", fahr, f_to_c(fahr));
  }
  
  puts("Celcius -> Fahrenheit");

  int celcius;

  for(celcius = 0; celcius <= 150; celcius += 10) {
    printf("%3d   %6.2f\n", celcius, c_to_f(celcius));
  }

  return 0;
}
