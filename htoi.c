#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int htoi(char *hex);
int place(int len, int i);

int place(int len, int i)
{
  return (int) pow(16, len - i - 1);
}

int htoi(char *hex)
{
  int len = strlen(hex);
  int i = len - 1;
  int res = 0;
  int c_val;
  char c;
  while(i >= 0) {
    c = hex[i];
    if(isdigit(c)) {
      c_val = c - '0';
    } else if ((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')) {
      switch (c) {
        case 'A':
        case 'a':
          c_val = 10;
          break;
        case 'B':
        case 'b':
          c_val = 11;
          break;
        case 'C':
        case 'c':
          c_val = 12;
          break;
        case 'D':
        case 'd':
          c_val = 13;
          break;
        case 'E':
        case 'e':
          c_val = 14;
          break;
        case 'F':
        case 'f':
          c_val = 15;
          break;
        default:
          printf("Invalid hex string:%s\n", hex);
          return 0;
      }
    } else if ((c == 'x' || c == 'X') && i == 1 && hex[0] == '0') {
      return res;
    } else {
      printf("Invalid hex string:%s\n", hex);
      return 0;
    }
    res += c_val * place(len, i);
    c_val = 0;
    i--;
  }
  return res;
}

int main(int argc, char *argv[])
{

  if(argc > 2) {
    puts("htoi takes a single argument of a hexidecimal string");
    return 1;
  } 

  printf("hex string %s = %d\n", argv[1], htoi(argv[1]));

  return 0;
}
