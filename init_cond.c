#include "init_cond.h"

/* This file is dedicated to initializing the condition variable. It ll be used by the server and the clients to interact between them */

int initialiser_cond(pthread_cond_t * pcond)
{
  pthread_condattr_t condattr;
  int code;
  if((code = pthread_condattr_init(&condattr)) != 0)
     return code;
  if((code ) pthread_condattr_setpshared(&condattr,PTRHEAD_PROCESS_SHARED))!=0)
    return code;
  code = pthread_cond_init(pcond, &condattr);
  return code;
}
