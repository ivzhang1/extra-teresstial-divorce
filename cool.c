#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char** parse_args( char* line ){
  char** args = calloc(6, sizeof(char**));
  for(int i = 0; line; i++) args[i] = strsep(&line, " ");
  return args;
}
void arg_printer(char** args) {
  printf("[ ");
  for(;*args;printf("%s, ",*args++));
  printf("NULL ]\n");
}
int main(){
  char sl[] = "sl";
  char ls[] = "ls -l -a";
  char gt[] = "git commit -a -m 'my_program_did_this_commit_for_me_this_is_so_epic'";
  char** args = parse_args(sl);
  arg_printer(args);
  execvp(args[0], args);
  //free(args);
  args = parse_args(ls);
  arg_printer(args);
  execvp(args[0], args);
  //free(args);
  args = parse_args(gt);
  arg_printer(args);
  execvp(args[0], args);
  free(args); // never freed because the program exits before getting to this point... :(
  return 0;
}
