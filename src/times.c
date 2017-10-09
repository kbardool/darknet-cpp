
#include "times.h"

int gettimeofday(struct timeval* t,void* timezone)
{       struct _timeb timebuffer;
        _ftime( &timebuffer );
        t->tv_sec=timebuffer.time;
        t->tv_usec=1000*timebuffer.millitm;
		return 0;
}

clock_t times (struct tms* __buffer) {

	__buffer->tms_utime = clock();
	__buffer->tms_stime = 0;
	__buffer->tms_cstime = 0;
	__buffer->tms_cutime = 0;
	return __buffer->tms_utime;
}

void timersub(timeval* a, timeval* b, timeval* result)  {                                           
    do {                                                                       
      (result)->tv_sec = (a)->tv_sec - (b)->tv_sec;                            
      (result)->tv_usec = (a)->tv_usec - (b)->tv_usec;                         
      if ((result)->tv_usec < 0) {                                             
        --(result)->tv_sec;                                                    
        (result)->tv_usec += 1000000;                                          
      }                                                                        
    } while (0);
}