#ifndef _ADD_SYSCALL_H_
#define _ADD_SYSCALL_H_
#include <linux/linkage.h>
#include<linux/syscall.h>
#include <sys/types.h>
#include <unistd.h>
asmlinkage long sys_call(int,int);
#endif