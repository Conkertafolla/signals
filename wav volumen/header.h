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

void fill_header (char * buffer, header * hed);
