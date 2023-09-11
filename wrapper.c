#include <linux/linkage.h>
#include <linux/types.h>
#include<linux/syscall.h>
#include <sys/types.h>
#include <unistd.h>
#include <linux/sysinfo.h>
#include<linux/shed.h>
#include "header.h"
#include <sched.h>
#include<linux/pid.h>
#define MY_SYSCALL_NUM 451
#define PAGE_POWER=12
SYSCALL_DEFINE2(add_syscall,int, pid,int num2){
    struct task_struct *task_p;
    long free;
    long used;
    long total;
    long total_memory;
    long physical_memory;
    struct mm_struct *mempt;
    struct sysinfo mySys;
    task_p =pid_task(find_vpid(pid),PITDTYPE_PID);
    if(pid<=0){
        return 1;
    }
    memPt=task_p->mm;
    if(task_p==NULL){
        return ESRCH;
    }
    if(opt==0)
    {
        total_memory=memPt->total_vm;
        return total_memory<<(PAGE_POWER-10);
    }
    else if(opt==1){
        physical_memory=get_mm_rss(memPt);
        return physical_memory<<(PAGE_POWER-10);
    }
    else if(opt==2){
        si_meminfo(&mySys);
        free=mySys.freeram;
        total=mySys.totalram;
        used=total-free;
        return used;
    }
    else if(opt==3){
        si_meminfo(&mySys);
        free=mySys.freeram;
        total=mySys.totalram;
        used=total-free;
        return (used*100/total);
    }
    else{
        return EINVAL;
    }


        
}



