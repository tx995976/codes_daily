#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FREE 0
#define BUSY 1
#define Max_length 640

typedef struct freearea//¿ÕÏÐÇøµÄœá¹¹Ìå
{
    int ID;//·ÖÇøºÅ
    int size;//·ÖÇøŽóÐ¡
    int address;//·ÖÇøµØÖ·
    bool isUsed;//Ê¹ÓÃ×ŽÌ¬£¬0ÎªÎŽÕŒÓÃ£¬1ÎªÒÑÕŒÓÃ
} freearea;

typedef struct DuNode//Ê×Î²²»»¥Á¬µÄË«ÏòÁŽ±íœáµã
{
    freearea data;//ÊýŸÝÓò
    struct DuNode *prior;//ÖžÕëÓò
    struct DuNode *next;
} DuNode, *DuLinkList;

DuLinkList m_rid;
DuLinkList m_last;

void init()//¿ÕÏÐÇø¶ÓÁÐ³õÊŒ»¯
{
    m_rid = (DuLinkList)malloc(sizeof(DuNode));
    m_last = (DuLinkList)malloc(sizeof(DuNode));

    m_rid->prior = NULL;
    m_rid->next = m_last;

    m_last->prior = m_rid;
    m_last->next = NULL;

    m_rid->data.size = 0;
    m_rid->data.isUsed = BUSY; //Ê×œáµã²»»á±»Ê¹ÓÃ£¬¶šÒåÎªÕŒÓÃ×ŽÌ¬·ÀÖ¹·ÖÇøºÏ²¢Ê§°Ü

    m_last->data.address = 0;
    m_last->data.size = Max_length;
    m_last->data.ID = 0;
    m_last->data.isUsed = 0;
}

int first_fit(int ID,int size)//Ê×ŽÎÊÊÓŠËã·š
{
    DuLinkList temp = (DuLinkList)malloc(sizeof(DuNode));
    DuNode *p = m_rid->next;

    temp->data.ID=ID;
    temp->data.size=size;
    temp->data.isUsed=BUSY;

    while(p)
    {
        if(p->data.ID == ID)//²»ÔÊÐíŽæÔÚÍ¬Ãû×÷Òµ
        {
            printf("The memory index is already in table!");

            return 0;
        }

        if (p->data.isUsed==FREE && p->data.size==size)//ÇëÇóŽóÐ¡žÕºÃÂú×ã
        {
            p->data.isUsed=BUSY;
            p->data.ID=ID;

            return 1;
        }

        if (p->data.isUsed==FREE && p->data.size>size)//¿ÕÏÐÇø±ÈËùÐèÄÚŽæŽó£¬ÔòÐèÒªœ«¶àµÄÄÚŽæ×÷»ØÊÕŽŠÀí
        {
            temp->next=p;
            temp->prior=p->prior;
            temp->data.address=p->data.address;

            p->prior->next=temp;
            p->prior=temp;
            p->data.address=temp->data.address+temp->data.size;
            p->data.size-=size;

            return 1;
        }

        p=p->next;
    }
    return 0;
}

int best_fit(int ID,int size){
    DuLinkList temp = (DuLinkList)malloc(sizeof(DuNode));
    DuNode *p = m_rid->next;
    DuNode *q = NULL;
    temp->data.ID=ID;
    temp->data.size=size;
    temp->data.isUsed=BUSY;
    while(p){
        if(p->data.ID == ID)
        {
            printf("The memory index is already in table!");

            return 0;
        }
        if (p->data.isUsed==FREE && p->data.size==size)
        {
            p->data.isUsed=BUSY;
            p->data.ID=ID;
            return 1;
        }

        if (p->data.isUsed==FREE && p->data.size>size)
        {
            if(q == NULL)
            {
                q = p;
            }
            else if(q->data.size > p->data.size)
            {
                q = p;
            }
        }
        p=p->next;
    }
    if(q == NULL)
    {
        return 0;
    }
    else
    {
        temp->next=q;
        temp->prior=q->prior;
        temp->data.address=q->data.address;
        q->prior->next=temp;
        q->prior=temp;
        q->data.address=temp->data.address+temp->data.size;
        q->data.size-=size;
        return 1;
    }
    
    return 0;
}

void alloc()
{
    int ID,size1;

    printf("memory index: ");
    scanf("%d", &ID);
    printf("memory size: ");
    scanf("%d", &size1);

    if (ID<=0 || size1<=0)
        printf("mistake! Please enter the correct memory index and memory size");
    if(best_fit(ID,size1))
        printf("memory allocation succeeded! \n");
    else
        printf("memory allocation failure! \n");
}

void freeNode()//ÊÍ·ÅÄÚŽæ
{
    int ID;
    DuNode *p = m_rid->next;

    printf("Enter the memory index that needs to free memory: ");
    scanf("%d", &ID);

    while (p)
    {
        if (p->data.ID == ID)
        {
            p->data.ID = 0;
            p->data.isUsed = FREE;

            if (!p->prior->data.isUsed && p->next->data.isUsed)//ÓëÇ°Ò»žö¿ÕÏÐÇøÏàÁÚ£¬ÔòºÏ²¢
            {
                p->prior->data.size += p->data.size;
                p->prior->next = p->next;
                p->next->prior = p->prior;
            }

            if (!p->next->data.isUsed && p->prior->data.isUsed) //ÓëºóÒ»žö¿ÕÏÐÇøÏàÁÚ£¬ÔòºÏ²¢
            {
                p->data.size += p->next->data.size;

                if(p->next->next)
                {
                    p->next->next->prior=p;
                    p->next = p->next->next;
                }
                else
                    p->next = p->next->next;
            }

            if(!p->prior->data.isUsed && !p->next->data.isUsed) //Ç°ºóµÄ¿ÕÏÐÇøŸùÎª¿Õ
            {
                p->prior->data.size += p->data.size + p->next->data.size;
                if(p->next->next)
                {
                    p->next->next->prior = p->prior;
                    p->prior->next = p->next->next;
                }
                else
                    p->prior->next = p->next->next;
            }

            printf("Free memory sucess!\n");
            break;
        }

        p = p->next;

        if(!p)
            printf("There is no  memory that needs to be freed!");
    }
}

void show()
{
    printf("------------------");
    printf("allocation table");
    printf("------------------\n");

    DuNode *p = m_rid->next;

    while(p)
    {
        printf("memory index: ");
        if (p->data.ID==FREE)
            printf("FREE\n");
        else
            printf("%d \n", p->data.ID);

        printf("memory start: %d\n", p->data.address);
        printf("memory size: %d\n", p->data.size);
        printf("memory status: ");

        if (p->data.isUsed==FREE)
            printf("Unallocated\n");
        else
            printf("Allocated\n");

        printf("------------------\n");
        p=p->next;
    }
}

int main()
{
    printf("------------------");
    printf("First Allocation");
    printf("------------------\n");

    init();

    int tag = 1;

    while(tag < 3 && tag > 0)
    {
        printf("select option  ");
        printf("1-allocation memory 2-free memory  others-quit: ");
        scanf("%d", &tag);

        switch(tag)
        {
        case 1:
            alloc();
            show();
            break;
        case 2:
            freeNode();
            show();
            break;
        default:
            printf("exit");
        }
    }
}