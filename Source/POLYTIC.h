#ifndef _POLYTIC_H_
#define _POLYTIC_H_

#include"Prossce.h"
#include "stdlib.h"

List ScanfProssces() ; 
#define __MAX__(__A__ ,  __B__) ((__A__ >  __B__) ? __A__ : __B__)
#define __MIN__(__A__ ,  __B__) ((__A__ <  __B__) ? __A__ : __B__)
#define __ABS__(__A__) (((__A__ > 0) ? (__A__) : (-__A__)))




int min(int a, int b);
void SGF(List *TheProssuce, List *TheQueue, List *DONES, int *t ); 
void RR(List *TheProssuce, List *DONES, int *t ); 
void Calc(List* DONE ); 
List TESTScanfProssces();
#endif // _POLYTIC_H_
