#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char buf[600];

int main(int argc, char *argv[]){
	int fd0,fd1,n;

	if (argc < 3){
		printf(1, "rename: not enough arguments\n");
		exit();
	}

	else if(argc == 3){
		if((fd0 = open(argv[1], O_RDONLY)) < 0){
			printf(1, "rename: cannot open %s\n",argv[1]);
			exit();
		}

		if((fd1 = open(argv[2], O_CREATE|O_RDWR)) < 0){
			printf(1, "rename: cannot open %s\n",argv[2]);
			exit();
		}

		while((n = read(fd0, buf,sizeof(buf))) > 0){
			write(fd1, buf, n);
		}

		if(unlink(argv[1]) < 0){
			printf(1, "rename: cannot open %s\n", argv[1]);
			exit();
		}

		close(fd0);
		close(fd1);

		exit();
	}

	else{
		printf(1, "rename: too many arguments\n");
		exit();
	}

	exit();
}
