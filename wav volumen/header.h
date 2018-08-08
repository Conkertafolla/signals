typedef struct HEADER
{
	char ChunkID[4];		//Contiene 'RIFF'
  int  size;
  char format[4];
  char Subchunk1ID[4];
  int Subchunk1Size;
}header;

void fill_header (char * buffer, header * hed);
