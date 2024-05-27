#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"


uint64
sys_exit(void)
{
    // uint64 addr;
    char msg[32];
    argstr(1,msg,32);
    int status;
    argint(0, &status);
    exit(status,msg);
 
    // argint(0, &status);
    // if(status < 0)
    //     return -1;
    // argaddr(1, &addr);
    // if(addr < 0)
    //     return -1;
 
    // if(addr == 0) {
    //     exit(status, 0);
    // } else {
    //     if(fetchstr(addr, msg, sizeof(msg)) < 0)
    //         return -1;
    //     exit(status, msg);
    // }
    return 0;  // This line will never be reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 addr;
  uint64 msg_addr;

  argaddr(0, &addr);
  // if(addr < 0)
  //   return -1;
  argaddr(1, &msg_addr);
  // if(msg_addr < 0)
  //   return -1;

  return wait(addr, msg_addr);
}


uint64
sys_sbrk(void)
{
  uint64 addr;
  int n;

  argint(0, &n);
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  argint(0, &n);
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(killed(myproc())){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  argint(0, &pid);
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

//This system call should return the size of the running process’ memory in bytes
uint64
sys_memsize(void)
{
  return myproc()->sz;
}
