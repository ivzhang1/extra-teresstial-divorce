#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char ** parse_args( char * line ){
  char** args = malloc(6);

  for(int i = 0; args[i] = strsep(line, " "); i++);
  

  return args;

  
}

int main(){
  char* s = "ls -l -a";
  char** args = parse_args(s);

  execvp(args[0], args);
  
  return 0;
}
