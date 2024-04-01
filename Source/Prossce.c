#include "Prossce.h"

#define lambda(lambda$_ret, lambda$_args, lambda$_body) \
    ({                                                  \
        lambda$_ret lambda$__anon$ lambda$_args         \
            lambda$_body                                \
                &lambda$__anon$;                        \
    })

List Insert(Prossce p_pross, List p_head, ComparisonFunction TEST)
{

    List P;
    P = (struct Node *)malloc(sizeof(struct Node));
    P->info = p_pross;
    return InsertBY_PTR(P, p_head, TEST);
}





List InsertBY_PTR(List P, List p_head, ComparisonFunction TEST)
{
    if(P == NULL) return p_head;
    P->Next = NULL;

    if (p_head == NULL)
    {
        P->Next = p_head;
        return P;
    }

    List Me = p_head, Befor = NULL;
    while ((Me != NULL) && (*TEST)(Me, P))
    {
        Befor = Me;
        Me = Me->Next;
    }
    if (Befor == NULL)
    {
        P->Next = p_head;
        return P;
    }
    else
    {
        P->Next = Me;
        Befor->Next = P;
    }
    return p_head;
}

List InsertBY_PTR_rev(List P, List p_head, ComparisonFunction TEST)
{
    if (P == NULL)
        return p_head;
    
    P->Next = NULL;

    if (p_head == NULL || (*TEST)(p_head, P))
    {
        P->Next = p_head;
        return P;
    }

    p_head->Next = InsertBY_PTR(P, p_head->Next, TEST);
    return p_head;
}




void PrintProssce(Prossce p_pross)
{
    printf("\t{\n");

    printf("\t\ttime_ariver : %d ,\n", p_pross.time_ariver);
    printf("\t\ttime_ex : %d , \n", p_pross.time_ex);
    printf("\t\tpriority : %d , \n", p_pross.priority);
    printf("\t\ttime_sort : %d , \n", p_pross.time_sort);
    printf("\t\ttime_attont : %d ,\n", p_pross.time_attont);
    printf("\t\ttime_reponse : %d ,\n", p_pross.time_reponse);

    printf("\t},\n");
}

void PrintList(List p_head)
{
    printf("------------------------------------------------------\n{\n");
    for(List I = p_head; I != NULL; I = I->Next) 
        PrintProssce(I->info);
    
    printf("\n}\n------------------------------------------------------\n");
}

Prossce TESTScanfProssce(int exe, int arrive, int prop)
{
    Prossce tmp = {
        time_ariver : arrive,
        priority : prop,
        time_ex : exe,
        time_sort : 0,
        time_attont : 0,
        time_reponse : 0
    };
    return tmp;
}

void ScanfProssce(Prossce *p_pross, int what_to_scan)
{
    printf("TESTS : \n");
    printf("ARRIVE : %d \n", what_to_scan & ARRIVE);
    printf("PRIORITY : %d \n", what_to_scan & PRIORITY);
    printf("EXE : %d \n", what_to_scan & EXE);
    printf("SORT : %d \n", what_to_scan & SORT);
    printf("ATTONT : %d \n", what_to_scan & ATTONT);

    if (what_to_scan & ARRIVE)
    {
        do
        {
            if (p_pross->time_ariver >= 0)
                break;
            printf(" \nYou can put a negative number \n");
        } while (1);

        printf("what's the time if the arrier \n >> ");
        scanf("%d", &p_pross->time_ariver);
    }
    if (what_to_scan & PRIORITY)
    {
        do
        {
            printf("what's the priority  the bigger it get the less powerfull it will be \n >> ");
            scanf("%d", &p_pross->priority);

            if (p_pross->priority >= 0)
                break;
            printf(" \nYou can put a negative number \n");
        } while (1);
    }
    if (what_to_scan & EXE)
    {
        
        do{
            printf("what's the time it need to be executed \n >> ");
            scanf("%d", &p_pross->time_ex);

            if (p_pross->time_ex >= 0)
                break;
            printf(" \nYou can put a negative number or zero \n");
        } while (1);
    }
    if (what_to_scan & SORT)
    {
        do
        {
            printf("what's the time if the arrier \n >> ");
            scanf("%d", &p_pross->time_ariver);

            if (p_pross->time_ariver > 0)
                break;
            printf(" \nYou can put a negative number \n");
        } while (1);
    }
    if (what_to_scan & ATTONT)
    {
        do
        {
            printf("what's the time of (attont) \n >> ");
            scanf("%d", &p_pross->time_attont);

            if (p_pross->time_attont > 0)
                break;
            printf(" \nYou can put a negative number \n");
        } while (1);
    }
}

List PoPHead(List *p_head)
{
    if ((*p_head) == NULL)
        return NULL;
    List head = (*p_head);
    (*p_head) = (*p_head)->Next;
    head->Next = NULL;

    return head;
}
