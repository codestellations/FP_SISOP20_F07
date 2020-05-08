#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char buf[512];
char buf1[512];
char temp[512];
int fd0,fd1, n, m;

int writeTo(int n, int type){
	if(type == 0)
	printf(1, "%s ", temp);
	else
	printf(1, "%s\n", temp);

	memset(temp, 0, sizeof temp);

	return 0;
}

int main(int argc, char *argv[])
{
	int i, j=0, x=0;

	if(argc <= 2){
		printf(1, "Need 2 arguments\n");
		exit();
	}

	else{
		if((fd0 = open(argv[1], O_RDONLY)) < 0){
			printf(1,"join: cannot open %s\n",argv[1]);
			exit();
		}

		if((fd1 = open(argv[2], O_RDONLY)) < 0){
			printf(1,"join: cannot open %s\n",argv[2]);
			exit();
		}

		while((n = read(fd0, buf, sizeof(buf))) > 0 && (m = read(fd1, buf1, sizeof(buf1))) > 0){
			for(i = 0; i<n; i++){
				if(buf[i] == '\n'){
					x = writeTo(i, 0);

					for(; j<m; j++){
						if(buf1[j] == '\n'){
							x = writeTo(j, 1);
							j++;

							break;
						}
						else{
							temp[x] = buf1[j];
							x++;
						}
					}
				}
				else{
					temp[x] = buf[i];
					x++;
				}
			}
		}

		close(fd0);
		close(fd1);
	}

  exit();
}
