#ifndef _CPUTIMER_H_
#define _CPUTIMER_H_

#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#define USECPSEC 1000000ULL

typedef unsigned long long CPUTimer_t;

static inline unsigned long long CPUTimer(void){
  struct timeval tv;
  gettimeofday(&tv, 0);
  return ((tv.tv_sec*USECPSEC)+tv.tv_usec);
}

static inline void print_timer(CPUTimer_t start, CPUTimer_t end, const char* timer){
    printf("%s: %llu\n",timer,end-start);
}

#endif
