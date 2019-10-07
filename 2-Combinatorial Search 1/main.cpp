#include <stdlib.h>
#include <iostream>
#include <vector>
#include <time.h>
#include "timeutil.h"
#include "BackTracking.h"

using namespace std;

int main(int argc, char *argv[]){
//  if (argc<2) { 
//     printf("E necessario informar o nome do arquivo instancia\n");
//     exit(1);
//  }
 

  Estrutura *est = new Estrutura();
  BackTracking *bkt = new BackTracking(est); 
  
  bkt->bkt();

  delete est;
  delete bkt;
  
 return 0;
}

