/*
Header for the server part
*/

#ifndef SERVER
#define SERVER

#define NAMELEN 48

#define NB_FUN 3          //to be updated if you wish to add more functions
//include new functions below
#include "trunc.h"
#include "concat.h"
#include "div.h"

lpc_function fun_tab[NB_FUN];

void init_fun_tab()
{
  fptr f1 = &trunc;
  const lpc_function truncat = {"truncate", f1};
  fun_tab[0] = truncat;
  
  fptr f2 = &concat;
  const lpc_function concat = {"concatenate", f2};
  fun_tab[1] = concat;
  
  fptr f3 = &divide;
  const lpc_function divide = {"division", f3};
  fun_tab[2] = divide;
  
  //to add a new function, first update NB_FUN, then include your header and update init_fun_tab to include the new function following the above format
}

int (*find_fun_ptr(const char *name)) (void*)
{
  for(int i = 0; i < NB_FUN; i++)
  {
    if(strcmp(fun_tab[i].fun_name,name) ==0)
      return fun_tab[i].fun;
  }
  return NULL;
}

//to be continued
