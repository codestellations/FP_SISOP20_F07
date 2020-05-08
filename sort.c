#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int fd0, fd1, n,line=0;
char buf[512];
char temp[512];
char str[100][100];

int main(int argc, char *argv[]) {
  int i, j=0, srt=0;

  if(argc < 2){
		printf(1, "sort: not enough arguments\n");
		exit();
	}

	else{
    if((fd0 = open(argv[argc-1], O_RDONLY)) < 0){
			printf(1,"sort: cannot open %s\n", argv[argc-1]);
			exit();
		}

    while((n = read(fd0, buf, sizeof(buf))) > 0){
      for(i = 0; i<n; i++){
        if(buf[i] == '\n'){
          line++; j = 0;
        }
        else{
          str[line][j] = buf[i];
          j++;
        }
      }
    }

    for(i = 0; i<line-1; i++){
      for(j = 0; j<line-i-1; j++){
        if(strcmp(str[j], str[j+1]) > 0){
          strcpy(temp, str[j]);
          strcpy(str[j], str[j+1]);
          strcpy(str[j+1], temp);
          srt++;
        }
      }
    }

    if(argc == 2){
      for(i = 0; i<line; i++){
        printf(1, "%s\n", str[i]);
      }
      exit();
    }

    else if(argc == 3){
      if(strcmp(argv[1], "-r") == 0){
        for(i = line-1; i>=0; i--){
          printf(1, "%s\n", str[i]);
        }
        exit();
      }

      else if(strcmp(argv[1], "-u") == 0){
        char piv[512];
        strcpy(piv, str[0]);
        printf(1, "%s\n", str[0]);

        for(i = 1; i<line; i++){
          if(strcmp(piv, str[i]) != 0){
            strcpy(piv, str[i]);
            printf(1, "%s\n", str[i]);
          }
        }
        exit();
      }

      else if(strcmp(argv[1], "-c") == 0){
        if(srt == 0){
          printf(1, "data sudah terurut\n");
        }
        else{
          for(i = 0; i<line; i++){
            printf(1, "%s\n", str[i]);
          }
        }
      }

      else{
        printf(1, "sort: argumen salah\n");
        exit();
      }

    }

    else if(argc == 4){
      if(strcmp(argv[1], "-o") == 0){
        if((fd1 = open(argv[2], O_CREATE|O_RDWR)) < 0){
    			printf(1,"sort: cannot open %s\n",argv[2]);
    			exit();
    		}

        for(i = 0; i<line; i++){
          write(fd1, str[i], strlen(str[i]));
          write(fd1, "\n", 1);
        }

        close(fd1);
      }
      else{
        printf(1, "sort: argumen salah\n");
        exit();
      }
    }

    close(fd0);
  }
  exit();
}
