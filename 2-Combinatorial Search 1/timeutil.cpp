/***************************************************************************
                          timeutil.c  -  description
                             -------------------
    begin                : Wed Jan 24 2001
    copyright            : (C) 2001 by Olinto Araújo
    email                : olinto@casm.ufsm.br
 ***************************************************************************/
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>

double getseconds(void) {
   struct rusage tempo;

   int isok=getrusage(0,&tempo);

   if (isok==-1) {
      printf("\nProblemas na rotina de controle do tempo ( cputime.c )\n");
      exit(1);
   }

   return tempo.ru_utime.tv_sec + tempo.ru_utime.tv_usec/1000000.0;

}

