#include <linux/linkage.h>
#include <linux/types.h>
#include<linux/types.h>
#include<linux/syscall.h>
#include <sys/types.h>
#include <unistd.h>
#include <linux/sysinfo.h>
#include "header.h"
#define MY_SYSCALL_NUM 451

int main(int argc, char* argv[]){
    if (argc != 3) {
        printf("Usage: %s <PID> <OPT>\n", argv[0]);
        return 1;
    }
    int pid = atoi(argv[1]);
    int opt = atoi(argv[2]);
    unsigned long result;
    long ret = syscall(MY_SYSCALL_NUM, pid, opt);
    if(ret==1){
        printf("THere is no such process:");
    }
        switch (opt) {
            case 0:
                printf("Total memory used by process %d: %lu bytes\n", pid, ret);
                break;
            case 1:
                printf("Physical memory used by process %d: %lu bytes\n", pid, ret);
                break;
            case 2:
                printf("System memory stats in KB: %lu KB\n", ret);
                break;
            case 3:
                printf("System memory stats in %%: %lu%%\n", ret);
                break;
            default:
                printf("Invalid option\n");
        }
    
    

    return 0;
}



