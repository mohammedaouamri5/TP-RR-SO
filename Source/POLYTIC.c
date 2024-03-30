#include "POLYTIC.h"
#include "stdlib.h"

#define lambda(lambda$_ret, lambda$_args, lambda$_body) \
    ({ lambda$_ret lambda$__anon$ lambda$_args          \
           lambda$_body                                 \
               &lambda$__anon$; })

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

char test_by_pro(List Me, List P)
{
    return Me->info.priority > P->info.priority;
}

char test_by_time(List Me, List P)
{
    return Me->info.time_ariver < P->info.time_ariver;
}
char test_by_time_and_pro(List Me, List P)
{
    if (Me->info.time_ariver < P->info.time_ariver)
        return 1;
    else if (Me->info.time_ariver > P->info.time_ariver)
        return 0;
    else
        return test_by_pro(Me , P) ;
}

char at_ferst(List Me, List P)
{
    return 0;
}
char at_end(List Me, List P)
{
    return 1;
}
void add(List Queues[3], List *TheProssuce, int *t);
int IsDone(List result);
void destribute(List *TheProssuce, List Queues[3]);
void printqueues(List Queues[3]);
int I_can_run(List __Queue[3], int *__index);

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

    prossces = Insert(TESTScanfProssce(4, 3, 6), prossces, test_by_time); // lambda(char, (List Me, List P), { return Me->info.time_ariver < P->info.time_ariver; })
    prossces = Insert(TESTScanfProssce(5, 5, 1), prossces, test_by_time); // lambda(char, (List Me, List P), { return Me->info.time_ariver < P->info.time_ariver; })
    prossces = Insert(TESTScanfProssce(8, 2, 2), prossces, test_by_time); // lambda(char, (List Me, List P), { return Me->info.time_ariver < P->info.time_ariver; })
    prossces = Insert(TESTScanfProssce(2, 2, 5), prossces, test_by_time); // lambda(char, (List Me, List P), { return Me->info.time_ariver < P->info.time_ariver; })
    prossces = Insert(TESTScanfProssce(7, 4, 8), prossces, test_by_time); // lambda(char, (List Me, List P), { return Me->info.time_ariver < P->info.time_ariver; })
    prossces = Insert(TESTScanfProssce(3, 0, 4), prossces, test_by_time); // lambda(char, (List Me, List P), { return Me->info.time_ariver < P->info.time_ariver; })

    return prossces;
}

void destribute(List *TheProssuce, List Queues[3])
{
    for (List I = *TheProssuce, J = NULL; I;)
    {
        J = I;
        I = I->Next;
        add(Queues, TheProssuce , 0);
        // int i = J->info.time_ex - 1;
        // i = i / 3;
        // i = (i < 3) ? i : 2;

        // Queues[i] = Insert(J->info, Queues[i],  test_by_time_and_pro);
    }
}

void printqueues(List Queues[3])
{
    printf("\n-------------prints queues----------\n");
    printf("Queues {%x,%x,%x}", Queues[0], Queues[1], Queues[2]);
    for (size_t i = 0; i < 3; i++)
    {
        printf("\n------------------------------------\n");
        printf("\nQueue %d: ", i + 1);
        if (Queues[i] != NULL)
            PrintList(Queues[i]);
        else
        {
            printf("is empty\n", i + 1);
        }
    }
    printf("\n------------------------------------\n");
    printf("\n");
}
int I_can_run(List __Queue[3], int *__index)
{

    if (*__index < 0)
        return 0;
    return __Queue[(*__index)] != NULL;
}

List run(List __Queues[3], int *__index, List *TheProssuce, int *t)
{
    int tmp_min;
    // if (*TheProssuce)
    // {

    //     tmp_min = min(, abs((*t) - (*TheProssuce)->info.time_ariver));
    //     printf("((*__index) + 1) = %d \n", ((*__index) + 1));
    //     printf("abs((*t) - (*TheProssuce)->info.time_ariver) = abs(%d , %d) = abs(%d) = %d \n ", (*t), (*TheProssuce)->info.time_ariver, (*t) - (*TheProssuce)->info.time_ariver, abs((*t) - (*TheProssuce)->info.time_ariver));
    // }
    // else
    // {
    //     printf("TheProssuce is empty");
    //     tmp_min = ((*__index) + 1);
    // }

    tmp_min = min(((*__index) + 1), abs(__Queues[*__index]->info.time_ex - ((__Queues[*__index]))->info.time_attont));

    printf("{tmp_min: %d}\n", tmp_min);
    ((__Queues[*__index]))->info.time_attont += tmp_min;
    (*t) += tmp_min;

    return PoPHead(&(__Queues[*__index]));
}

int IsDone(List result)
{
    puts("Is it done ?? \n");
    return (((result))->info.time_attont == ((result))->info.time_ex);
}

void add(List Queues[3], List *TheProssuce, int *t)
{
    puts("Adding ...");
    if (*TheProssuce != NULL)
    {
        List ___new = PoPHead(TheProssuce);
        *t = __MAX__(___new->info.time_ariver , *t) ;
        PrintProssce(___new->info);
        int __index = (___new->info.time_ex - 1) / 3;
        __index = __MIN__(__index, 2);
        Queues[__index] = InsertBY_PTR(___new, Queues[__index], test_by_pro);

    }
}

int I_have_to_add(List Queues[3], List *TheProssuce, int *t)
{
    printf("Have to add ...");
    if ((*TheProssuce) == NULL)
        return 0;
    int result = ((*TheProssuce)->info.time_ariver <= *t);
    if (result)
        return result;

    for (size_t i = 0; (i < 3); i++)
    {
        if (Queues[i] == NULL)
        {
            return 1;
        }
    }
    return 0;
}

int what_to_run(List Queues[3], int ___index)
{
    puts("what to run ...");
    for (size_t i = 0; i < 3; i++)
    {
        if (Queues[(___index + 1 + i) % 3] != NULL)
            return (___index + 1 + i) % 3;
    }

    return -1;
}

void get_him_out(List result, List *DONES, int *t)
{
    printf("done!\n");
    PrintProssce(result->info);
    ((result))->info.time_sort = (*t);
    (*DONES) = InsertBY_PTR(result, (*DONES), at_end); // add in the end
}

int is_it_done(List Queues[3], List *TheProssuce, int *t)
{
    printf("Is it done ?? \n");
    // printqueues(Queues);
    int wtr = (what_to_run(Queues, 0) >= 0);
    // PrintList(*TheProssuce);
    printf("I what to run : %d\n", wtr);
    int ihta = I_have_to_add(Queues, TheProssuce, t);
    printf("I have to add : %d\n", ihta);
    return wtr || ihta;
}

void RR(List *TheProssuce, List *DONES, int *t)
{
    printf("Im IN ");
    List Queues[3] = {NULL, NULL, NULL};
    // destribute(TheProssuce, Queues);
    int GO = 20, index = 0;
    List result = NULL;
    while (GO)
    {
        printf("-----------------------(%d started)-----------------------\n{", *t);
        //        printqueues(Queues);
        // printf("\n");

        if (I_have_to_add(Queues, TheProssuce, t))
             add(Queues, TheProssuce, t);
         // PrintList(*TheProssuce);
        // printqueues(Queues);

        index = what_to_run(Queues, index);
        printf("{index = %d}\n", index);
        printf("{queue = %d}\n", index +1 );
        // printf("{we will run result = %x}\n", Queues[index]);
        // PrintProssce(Queues[index]->info);
        result = run(Queues, &index, TheProssuce, t);
        printf("-----------------------(%d)-----------------------\n{", *t);
        // printf("{we will run result = %x}\n", result);
        // PrintProssce(result->info);

        if (IsDone(result))
            get_him_out(result, DONES, t);
        else
            Queues[index] = InsertBY_PTR(result, Queues[index], at_end); // add in the end
        GO = is_it_done(Queues, TheProssuce, t);
        // GO = 0;
        // GO--; //
        result = NULL;
        printf("}-----------------------(ended on %d)-----------------------\n", *t);
    }
    printf("--------------------(THE END)-----------------------\n", *t);
    printf("-----------------------(%d)-----------------------\n", *t);
    // printqueues(Queues);

    PrintList(*DONES);
    // PrintList(*TheProssuce);
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