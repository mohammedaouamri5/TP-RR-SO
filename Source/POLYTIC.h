#ifndef _POLYTIC_H_
#define _POLYTIC_H_

#include"Prossce.h"
#include "stdlib.h"

List ScanfProssces() ; 

void SGF(List *TheProssuce, List *TheQueue, List *DONES, int *t ); 
void RR(List *TheProssuce, List *DONES, int *t ); 
void Calc(List* DONE ); 
List TESTScanfProssces();
#endif // _POLYTIC_H_
