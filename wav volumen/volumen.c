#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//#include "header.h"

typedef struct HEADER
{
	char ChunkID[4];		//Contiene 'RIFF'
  int  size;
  char format[4];
  char Subchunk1ID[4];
  int Subchunk1Size;
  short AudioFormat;
  short NumChannels;
  int sampleRate;
  int byteRate;
  short blockAling;
  short bytesPerSample;
  char Subchunk2ID[4];
  int SubChunk2Size;
}header;

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


int main(int argc, char const *argv[]) {

  FILE * input, * output;
  header  hed_input, hed_output;
  char * input_file = (char *) malloc (sizeof (char));
  char * output_file = (char *) malloc (sizeof (char));
  char   buffer[44] = {'\0'};
  int samples =0;
  short sample=0;

  input_file = (char *) argv [1];
  output_file = (char *) argv[2];

  input = fopen(input_file, "rb");
  if (input == NULL){
		printf ("Error al crear el archivo '%s'", input_file);
		exit (0);
	}
  output = fopen(output_file, "wb");
  if (output == NULL)	{
		printf ("Error al crear el archivo '%s'", output_file);
		exit (0);
	}

  fread (buffer,sizeof(buffer),1,input);
  fwrite(buffer,sizeof(buffer),1,output);
  fill_header(buffer,&hed_input);

  samples = (hed_input.SubChunk2Size / hed_input.blockAling);

  for (int i = 0; i < samples; i ++)
 	{
 		fread (&sample, sizeof (short), 1, input);
 		sample *= 0.5;
 		fwrite (&sample, sizeof (short), 1, output);
 	}

  while (fread (&sample, sizeof (short), 1, input)){
      fwrite (&sample, sizeof (short), 1, output);
  }


  fclose (input);
	fclose (output);
  return 0;
}
