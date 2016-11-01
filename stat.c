#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <time.h>
#include <sys/stat.h>

void getSize(struct stat fileStats){
  int size = (int)fileStats.st_size;
  if (size > 1000000000){
    printf("%f GB\n", size/1000000000.0);
  }
  else if (size > 1000000){
    printf("%f MB\n", size/100000.0);
  }
  else if (size > 1000){
    printf("%f KB\n", size/1000.0);
  }
  else{
  	printf("%d B\n", size);
  }
}

void getTime(struct stat fileStats){
	printf("Time of last access: %s", ctime((time_t *) &fileStats.st_atime));
}

void getPermissions(struct stat fileStats){
	int mode = fileStats.st_mode;
	if(S_ISDIR(mode)){
		printf("d");
	}else{
		printf("-");
	}

	if(mode & S_IRUSR){
		printf("r");
	} else{
		printf("-");
	}

	if(mode & S_IWUSR){
		printf("w");
	} else{
		printf("-");
	}

	if(mode & S_IXUSR){
		printf("x");
	} else{
		printf("-");
	}

	if(mode & S_IRGRP){
		printf("r");
	} else{
		printf("-");
	}

	if(mode & S_IWGRP){
		printf("w");
	} else{
		printf("-");
	}

	if(mode & S_IXGRP){
		printf("x");
	} else{
		printf("-");
	}

	if(mode & S_IROTH){
		printf("r");
	} else{
		printf("-");
	}

	if(mode & S_IWOTH){
		printf("w");
	} else{
		printf("-");
	}

	if(mode & S_IXOTH){
		printf("x");
	} else{
		printf("-");
	}

	printf("\n");
}

int get_stats(char * fileName) {
  struct stat fileStats;
  int result = stat(fileName, &fileStats);
  if (result < 0) return result;

  printf("File Stats:\nName: %s\n", fileName);
  printf("Size: %d bytes\n", (int) fileStats.st_size);
  printf("Permissions: %o\n", fileStats.st_mode);
  printf("Time of last access: %s", ctime((time_t *) &fileStats.st_atime));
  return 0;
}

int main() {
  struct stat fileStats;
  stat("stat.c", &fileStats);
  printf("File Stats:\nFile Name: stat.c\n");
  printf("File Size: ");
  getSize(fileStats);
  getTime(fileStats);
  printf("File Permissions: ");
  getPermissions(fileStats);
  return 0;
}
