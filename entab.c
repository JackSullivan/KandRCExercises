#include <stdio.h>
#include <stdlib.h>

#define TABSTOP 4

int can_tab(char *str);
int str_len(char *str);

int can_tab_from(int pos, char *str)
{
  int init_pos = pos;
  while(str[pos] != '\0' && str[pos] == ' ' && pos - init_pos != TABSTOP) {
    ++pos;
  }
  return pos - init_pos == TABSTOP;
}

int str_len(char *str)
{
  int i = 0;
  while(str[i] != '\0') {
    ++i;
  }
  return i;
}



int main(int argc, char *argv[])
{

  if(argc > 2) {
    puts("entab takes a single string as argument, wrapped in quotes if needed");
    return 1;
  }

  char *space_str = argv[1];
  char *tab_str = malloc(str_len(space_str) + 1); // The new string will be no longer than the old one
  
  int space_idex = 0;
  int tab_idex = 0;
  while(space_str[space_idex] != '\0') {
    if(can_tab_from(space_idex, space_str)) {
      tab_str[tab_idex] = '\t';
      space_idex += TABSTOP;
      tab_idex ++;
    } else {
      tab_str[tab_idex] = space_str[space_idex];
      space_idex ++;
      tab_idex ++;
    }
  }
  tab_str[tab_idex] = '\0';
  
  puts(tab_str);

  return 0;
}
