#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <time.h>
#include <sys/stat.h>

int get_stats(char * fileName) {
  struct stat fileStats;
  int result = stat(fileName, &fileStats);
  if (result < 0) return result;

  printf("File Stats:\nName: %s\n", fileName);
  printf("Size: %d bytes\n", (int) fileStats.st_size);
  printf("Permissions: %o\n", fileStats.st_mode);
  printf("Time of last access: %s", ctime((time_t *) &fileStats.st_atim));
  return 0;
}

int main() {
  get_stats("test");
}
