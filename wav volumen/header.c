#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "header.h"

/* Funcion que recibe los 44 bytes de archivo WAV y lo almacena en la cabecera */
void fill_header (char * buffer, header * hed){
  //CHUnk_ID
  memcpy(hed->ChunkID,buffer,sizeof(hed->ChunkID));
  hed->ChunkID[sizeof(hed->ChunkID)]='\0';
  printf("%s\n",hed->ChunkID);

  //size of file
  memcpy(&hed->size,buffer+4,sizeof(int));
  printf("%d\n", hed->size);

  //size of file
  memcpy(hed->format,buffer+8,sizeof(hed->format));
  hed->format[sizeof(hed->format)]='\0';
  printf("%s\n",hed->format);

  //Subchunk1ID
  memcpy(hed->Subchunk1ID,buffer+12,sizeof(hed->Subchunk1ID));
  hed->Subchunk1ID[sizeof(hed->Subchunk1ID)]='\0';
  printf("%s\n",hed->Subchunk1ID);

  memcpy(&hed->Subchunk1Size,buffer+16,sizeof(int));
  printf("%d\n", hed->Subchunk1Size);
}
