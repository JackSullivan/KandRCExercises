#include <stdio.h>
#include <stdlib.h>

#define WHITESPACE 10
#define OTHER 11

char* n_chars(int num, char c);
int str_len(char *str);

char* n_chars(int num, char c)
{
  char *str = malloc(num + 1);

  int i;
  for(i = 0; i < num; i++) {
    str[i] = c;
  }
  str[num] = '\0';
  return str;
}

int str_len(char *str)
{
  int len = 0;
  while(str[len] != '\0') {
    ++len;
  }
  return len;
}

int main(int argc, char *argv[])
{
  int val_counts[12] = {0};
  int c;

  if(argc > 2) {
    puts("histogram takes a single string as an argument. If you need to represent whitespace you can quote it.");
    return 1;
  }
  
  int i, j;
  for(i = 1; i < argc; i++) {
    for(j = 0; j < str_len(argv[i]); j++) {
      c = argv[i][j];
      if(c >= '0' && c <= '9') {
        ++val_counts[c- '0'];
      } else if(c == ' ' || c == '\n' || c == '\t') { 
        ++val_counts[WHITESPACE]; // because each arg is separated by whitespace
      } else {
        ++val_counts[OTHER];
      }
    }
  }

  for(i = 0; i < 10; i++) {
    printf("%d\t\t|%s\n", i, n_chars(val_counts[i], '='));
  }
  printf("whitespace\t|%s\n", n_chars(val_counts[WHITESPACE], '='));
  printf("other\t\t|%s\n", n_chars(val_counts[OTHER], '='));

  return 0;
}
