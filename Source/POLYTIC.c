#include "POLYTIC.h"
#include "stdlib.h"

#define lambda(lambda$_ret, lambda$_args, lambda$_body) \
    ({ lambda$_ret lambda$__anon$ lambda$_args          \
           lambda$_body                                 \
               &lambda$__anon$; })




char test_by_time_and_pro(List Me, List P) {
    if (Me->info.time_ariver < P->info.time_ariver) 
        return 1;
    else
        if (Me->info.time_ariver > P->info.time_ariver)
            return 0;
        else 
            return Me->info.time_ariver < P->info.time_ariver;
            
}

List ScanfProssces()
{
    printf("BRUH");
    int GO;
    List prossces = malloc(sizeof(struct Node));
    prossces = NULL;

    do
    {
        GO = 1;
        Prossce tmp;
        ScanfProssce(&tmp, EXE | ARRIVE | PRIORITY);

        prossces = Insert(tmp, prossces, lambda(char, (List Me, List P), {
                              return Me->info.time_ariver < P->info.time_ariver;
                          }));

        printf("\nare you done yet (0 for no, anything else for yes)\n\t>> ");
        scanf("%d", &GO);

    } while (GO);

    return prossces;
}

List TESTScanfProssces()
{
    printf("BRUH");

    List prossces = malloc(sizeof(struct Node));
    prossces = NULL;

    prossces = Insert(TESTScanfProssce(4, 3, 6 ), prossces, lambda(char, (List Me, List P), { return Me->info.time_ariver < P->info.time_ariver; }));
    prossces = Insert(TESTScanfProssce(5, 5, 1 ), prossces, lambda(char, (List Me, List P), { return Me->info.time_ariver < P->info.time_ariver; }));
    prossces = Insert(TESTScanfProssce(8, 2, 2 ), prossces, lambda(char, (List Me, List P), { return Me->info.time_ariver < P->info.time_ariver; }));
    prossces = Insert(TESTScanfProssce(2, 2, 5 ), prossces, lambda(char, (List Me, List P), { return Me->info.time_ariver < P->info.time_ariver; }));
    prossces = Insert(TESTScanfProssce(7, 4, 8 ), prossces, lambda(char, (List Me, List P), { return Me->info.time_ariver < P->info.time_ariver; }));
    prossces = Insert(TESTScanfProssce(3, 0, 4 ), prossces, lambda(char, (List Me, List P), { return Me->info.time_ariver < P->info.time_ariver; }));

    return prossces;
}

void destribute(List *TheProssuce, List Queues[3])
{
    for (List I = *TheProssuce; I; I = I->Next)
    {
        int i = I->info.time_ex - 1;
        i = i / 3;
        i = (i < 3) ? i : 2;

        Queues[i] = Insert(I->info, Queues[i], lambda(char, (List Me, List P), { return Me->info.priority > P->info.priority; }));
    }
}



void I_can_run(List __Queue[3] , List * __index) {
    
    if (*__index < 0) return 0 ;
    return __Queue[*__index] 
}
void RR(List *TheProssuce, List *DONES, int *t)
{
    List Queues[3] = {NULL, NULL, NULL};
    int GO = 1, index = 0; 
    while (GO)
    {
        if(I_have_to_add(TheProssuce,t))
            add(Queues,TheProssuce); 

        if(I_can_run(Queues , &index))
        {    
            // pointer to there   the pressus if it is done
            // NULL if the pressus isnt finished
            List result = run(Queues , &index , t);
            if(result)
                (*DONES) = InsertBY_PTR(result, (*DONES), lambda(char, (List Me, List P), { return 1;  }));
        }
        GO = is_it_done(Queues , TheProssuce);
    }
    
}

void SGF(List *TheProssuce, List *TheQueue, List *DONES, int *t)
{
    printf("----------------------(%d)----------------------\n", *t);

    // PrintProssce(*TheProssuce)
    // // PrintProssce(*TheQueue)
    // PrintProssce(*DONES)

    printf("--[TheProssuce][%x]--\n", *TheProssuce);
    PrintList((*TheProssuce));

    printf("--[TheQueue][%x]--\n", *TheQueue);
    PrintList((*TheQueue));

    printf("--[DONES][%x]--\n", *DONES);
    PrintList(*DONES);

    if (!(
            (unsigned long)TheProssuce |
            (unsigned long)TheQueue |
            (unsigned long)DONES |
            (unsigned long)t))
    {
        printf("return exit(125);");
        return exit(125);
    }
    printf("((*TheQueue) == NULL) &&\n");
    printf("((*DONES)       == NULL) &&\n");
    printf("((*TheProssuce) != NULL) && \n");
    if (
        ((*TheQueue) == NULL) &&
        ((*DONES) == NULL) &&
        ((*TheProssuce) != NULL))
    {
        printf("[\t\n");
        printf(" (*t) == -1 )\n");
        (*TheQueue) = PoPHead(TheProssuce);
        (*t) = (*TheQueue)->info.time_ariver;
        printf("]\n");
        return SGF(TheProssuce, TheQueue, DONES, t);
    }

    printf("((unsigned long)(*TheProssuce) | (unsigned long)(*TheQueue)) == (unsigned long)(*TheProssuce) \n");
    if (
        ((*TheProssuce) != NULL) &&
        (*TheQueue) == NULL)
    // ((unsigned long)(*TheProssuce) | (unsigned long)(*TheQueue)) == (unsigned long)(*TheProssuce))
    {
        printf("[\t\n");

        (*TheQueue) = PoPHead(TheProssuce);
        (*t) = (*TheQueue)->info.time_ariver;
        printf("]\n");
        return SGF(TheProssuce, TheQueue, DONES, t);

        /* code */
    }

    printf("((*TheProssuce)->info.time_ariver == *t)\n");
    if ((*TheProssuce))
    {
        if ((*TheProssuce)->info.time_ariver == *t)
        {
            printf("[\t\n");
            (*TheQueue) = InsertBY_PTR(PoPHead(TheProssuce), (*TheQueue), lambda(char, (List Me, List P), { return Me->info.priority > P->info.priority; }));
            printf("]\n");
            return SGF(TheProssuce, TheQueue, DONES, t);
        }
    }
    printf("((*TheProssuce) == NULL) && \n");
    printf("((*TheQueue) != NULL)) \n");
    if (
        ((*TheProssuce) == NULL) &&
        ((*TheQueue) != NULL))
    {
        printf("[\t\n");

        (*t) += (*TheQueue)->info.time_ex - (*TheQueue)->info.time_attont;
        (*TheQueue)->info.time_sort = (*t);
        (*DONES) = InsertBY_PTR(PoPHead(TheQueue), (*DONES), lambda(char, (List Me, List P), { return Me->info.priority < P->info.priority; }));
        printf("]\n");
        return SGF(TheProssuce, TheQueue, DONES, t);
    }
    else
    {
        printf("[\t\n");
        printf("! ((*TheProssuce) == NULL) && \n");
        printf("! ((*TheQueue) != NULL)) \n");
        if ((*TheQueue) != NULL)
        {
            printf("(*TheQueue)->info.time_ex        : %d \n", (*TheQueue)->info.time_ex);
            printf("(*TheQueue)->info.time_attont    : %d \n", (*TheQueue)->info.time_attont);
            printf("(*TheProssuce)->info.time_ariver : %d \n", (*TheProssuce)->info.time_ariver);
            printf("(*t)                             : %d \n", (*t));
            int tmp_min = MIN(
                ((*TheQueue)->info.time_ex - (*TheQueue)->info.time_attont),
                ((*TheProssuce)->info.time_ariver - (*t)));
            // printf()
            (*TheQueue)->info.time_attont += tmp_min;
            (*t) += tmp_min;
            printf("]\n");

            printf("((*TheQueue)->info.time_attont == (*TheQueue)->info.time_ex) \n");
            if ((*TheQueue)->info.time_attont == (*TheQueue)->info.time_ex)
            {
                printf("[\t\n");
                (*TheQueue)->info.time_sort = (*t);
                (*DONES) = InsertBY_PTR(PoPHead(TheQueue), (*DONES), lambda(char, (List Me, List P), {
                                            return Me->info.priority < P->info.priority;
                                        }));

                printf("]\n");
            }

            return SGF(TheProssuce, TheQueue, DONES, t);
        }
    }
}

void Calc(List *DONE)
{
    puts("----------------------(CALC)----------------------");
    for (List I = (*DONE); I; I = I->Next)
    {
        I->info.time_reponse = I->info.time_sort - I->info.time_ariver;
        I->info.time_attont = I->info.time_reponse - I->info.time_ex;
    }
}

//
// enum State{
//     Q1 ,
//     Q2 ,
//     Q4 ,
//     QF
// };
//
// int  machine(const char * str ,enum State *  state) {
//     return STATIC_TEST(str[0] , &state) && machine(str+1 ,  state);
// }
//