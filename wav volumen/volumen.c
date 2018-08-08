#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "header.h"


int main(int argc, char const *argv[]) {

  FILE * input;
  header  hed;
  char * input_file = (char *) malloc (sizeof (char));
  char   buffer[44] = {'\0'};
  input_file = (char *) argv [1];
  input = fopen(input_file, "rb");
  fread (buffer,sizeof(buffer),1,input);

  fill_header(buffer,&hed);



  return 0;
}
