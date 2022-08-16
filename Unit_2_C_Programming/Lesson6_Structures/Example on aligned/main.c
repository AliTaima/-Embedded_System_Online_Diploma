#include <stdio.h>
#pragma pack(1)
struct Sdata{
  unsigned char data1;
  unsigned int data2;
  unsigned char data3;
  unsigned short data4;
  /* data */
};
struct Sdata gdata;

void dump_memory(char* ptr, int size);

int  main(int argc, char const *argv[]) {
  printf("Online_Diploma, LEARN-In-Depth\n" );
  gdata.data1 = 0xAA;
  gdata.data2 = 0xFFFFFFFF;
  gdata.data3 = 0x55;
  gdata.data4 = 0xA5A5;
  int total_size = sizeof(struct Sdata);
  printf("Size of struct sdata (non packing) = %d\n", sizeof(struct Sdata));
  dump_memory(&gdata, total_size);

  return 0;
}
void dump_memory(char* ptr, int size)
{
  int i;
  for(i = 0; i< size; i++)
  {
    printf("%p\t %X\n", ptr, (unsigned char)*ptr);
    ptr++;
  }
}
