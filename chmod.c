#ifdef CS333_P5
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
    if(argv > 2)
    {
        if((atoo(argv[1]) > 0 && atoo(argv[1]) < 1778) || atoi(argv[1]) == 0)
        {
            if(chmod(argv[2], atoo(argv[1])))
            {
                printf(1, "chmod %s is failed\n", argv[2]);
            }
            else
            {
                printf(1, "changing permissions...\n");
            }
        }
        else
        {
            printf(1, "invalid arguments, please input 'chmod' 'numeric' 'file'\n");
        }
    }
    exit();
}
#endif
