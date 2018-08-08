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

      memcpy(&hed->AudioFormat,buffer+20,sizeof(hed->AudioFormat));
      //hed->AudioFormat[sizeof(hed->AudioFormat)]='\0';
      printf("%d\n",hed->AudioFormat);
      if (hed->AudioFormat == 1){
          printf("Audio Format:  PCM\n");
      }

      //numero de canales mono o stereo
      memcpy(&hed->NumChannels,buffer+22,sizeof(hed->NumChannels));
      printf("%d\n",hed->NumChannels);
      if (hed->NumChannels == 1){
          printf("MONO\n");
      }else if (hed->NumChannels == 2){
          printf("STEREO\n");
      }

      //sampleRate
      memcpy(&hed->sampleRate,buffer+24,sizeof(hed->sampleRate));
      printf("%d\n",hed->sampleRate);

       //byteRate
      memcpy(&hed->byteRate,buffer+28,sizeof(hed->byteRate));
      printf("%d\n",hed->byteRate);

      //blockAling
      memcpy(&hed->blockAling,buffer+32,sizeof(hed->blockAling));
      printf("%d\n",hed->blockAling);

      //bytesPerSample
      memcpy(&hed->bytesPerSample,buffer+34,sizeof(hed->bytesPerSample));
      printf("%d\n",hed->bytesPerSample);

      memcpy(hed->Subchunk2ID,buffer+36,sizeof(hed->Subchunk2ID));
      hed->Subchunk2ID[sizeof(hed->Subchunk2ID)]='\0';
      printf("%s\n",hed->Subchunk2ID);

      memcpy(&hed->SubChunk2Size,buffer+40,sizeof(hed->SubChunk2Size));
      printf("%d\n",hed->SubChunk2Size);

}


//TODO falta hacerdividir los valores de los bytes de data
