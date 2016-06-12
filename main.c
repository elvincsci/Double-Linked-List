#include <stdlib.h>
#include <stdio.h>
#include <time.h>


struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

//struct Node *tail = NULL;
//struct Node *current = NULL;

struct Node* createNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


//insert at the front
void insert(int i)
{
    struct Node *newNode = createNode(i);
    newNode->data = i;


    if(head == NULL )
    {
        head =  newNode;
        return;
    }
    else
    {
        head->prev=newNode;
    }

    newNode->next=head;

    head=newNode;
}


void addTail(int i)
{
    struct Node * tail=head;
    struct Node *newNode = createNode(i);
    newNode->data = i;

    if(head == NULL)
    {
        head =  newNode;
        return;
    }
    while(tail->next != NULL)
    {
        tail=tail->next;
    }

    tail->next=newNode;
    newNode->prev=tail;


}

struct Node* deleteHead()
{
    struct Node *temp=head;

    if(head->next == NULL)
    {
        printf("deleting only element");
    }

    head->next->prev=NULL;
    head=head->next;

    return temp;

}

//delete tail
struct Node* deleteTail()
{
    struct Node * tail=head;


    while(tail->next != NULL)
    {
        tail=tail->next;
    }

    tail->prev->next=NULL;

    return tail;
}

struct Node* deleteMiddle()
{
    struct Node * current=head;
    struct Node * elementafter;
    struct Node * delete;

    int i;
    i=1;
    while(i < (10/2)-1 && current != NULL)
    {
        current=current->next;
        i++;
    }

    delete=current->next;

    elementafter=delete->next;

    current->next=delete->next;
    elementafter->prev=delete->prev;

    return delete;
}

struct Node *sort_list() {

    struct Node *tmpPtr = head;
    struct Node *tmpNxt = head->next;


    int tmp;

    while(tmpNxt != NULL){
        while(tmpNxt != tmpPtr){
            if(tmpNxt->data < tmpPtr->data){
                tmp = tmpPtr->data;
                tmpPtr->data = tmpNxt->data;
                tmpNxt->data = tmp;
            }
            tmpPtr = tmpPtr->next;
        }
        tmpPtr = head;
        tmpNxt = tmpNxt->next;
    }
    return tmpPtr ; // Place holder
}



//print data forward
void printFront()
{
    struct Node *temp = head;

    //handle empty list nicely
    if (temp==NULL)
    {
        printf("List is empty");
        return;
    }

    printf("Print the list forward: ");
    while(temp  != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }

    printf("\n");
}

//print data in reverse order
void printBackward()
{
    struct Node *temp = head;

    //handle empty list nicely
    if (temp==NULL)
    {
        printf("List is empty");
        return;
    }

    while(temp->next != NULL)
    {
        temp= temp->next;
    }

    printf("Print the list backwards: ");
    while(temp  !=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->prev;
    }

    printf("\n");

}


int main()
{


    int a,b,c,d,e,f,g,h,w,z;

    int max1=230, min1=1;

    time_t t;

    srand((unsigned) time(&t));


    //Randomly create 10 different numbers,range  230 to 1;
    a=(rand() % abs(max1 - min1 + 1)) + min1 ;
    b=(rand() % abs(max1 - min1 + 1)) + min1 ;
    c=(rand() % abs(max1 - min1 + 1)) + min1 ;
    d=(rand() % abs(max1 - min1 + 1)) + min1 ;
    e=(rand() % abs(max1 - min1 + 1)) + min1 ;
    f=(rand() % abs(max1 - min1 + 1)) + min1 ;
    g=(rand() % abs(max1 - min1 + 1)) + min1 ;
    h=(rand() % abs(max1 - min1 + 1)) + min1 ;
    w=(rand() % abs(max1 - min1 + 1)) + min1 ;
    z=(rand() % abs(max1 - min1 + 1)) + min1 ;


    //adding the random numbers
    addTail(a);
    addTail(b);
    addTail(c);
    addTail(d);
    addTail(e);
    addTail(f);
    addTail(g);
    addTail(h);
    addTail(w);
    addTail(z);


    printf("\nAdding Random numbers\n");

    printFront();

    printBackward();


    deleteMiddle();


    printf("\nData after deleting from middle: \n");

    printFront();

    printBackward();

    deleteHead();


    printf("\nData after deleting from the front: \n");
    printFront();

    printBackward();


    deleteTail();

    printf("\nData after deleting from back: \n");

    printFront();

    printBackward();



    sort_list();

    printf("\nSorted Data: \n");

    printFront();

    printBackward();


    printf("\nExtra, add to front: \n");

    a=(rand() % abs(max1 - min1 + 1)) + min1 ;
    b=(rand() % abs(max1 - min1 + 1)) + min1 ;
    c=(rand() % abs(max1 - min1 + 1)) + min1 ;

    insert(a);
    insert(b);
    insert(c);

    printFront();

    printBackward();



    return 0;
}