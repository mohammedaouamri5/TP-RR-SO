#ifndef _PROSSCE_H_
#define _PROSSCE_H_

#include "malloc.h"
#include "stdlib.h"
 
#define ISbetween(x ,A , B) ((x > A ) && (x  < B ))
#define MIN(A , B) ((B < A ) ? ( B ) : ( A ) )
 
typedef struct Prossce
{
    int time_ariver;
    int priority;
    int time_ex;
    int time_sort;
    int time_attont;
    int time_reponse;

} Prossce;

enum PROSSMEMBER
{
    ARRIVE = 0b1 << 1 ,
    PRIORITY = 0b1 << 2 ,
    EXE = 0b1 << 3 ,
    SORT = 0b1 << 4 ,
    ATTONT = 0b1 << 5 ,
}; 


struct Node
{
    struct Prossce info;
    struct Node *Next;
};

typedef struct Node *List;

typedef char (*ComparisonFunction)(List, List);

List Insert(Prossce p_pross, List p_head, ComparisonFunction TEST);
void ScanfProssce(Prossce *p_pross, int what_to_scan);
void PrintProssce(Prossce p_pross);
void PrintList(List p_head);
List PoPHead(List *p_head) ;
List InsertBY_PTR(List P, List p_head, ComparisonFunction TEST);
List InsertBY_PTR_rev(List P, List p_head, ComparisonFunction TEST);
Prossce TESTScanfProssce(int exe , int arrive, int prop);



#endif 
