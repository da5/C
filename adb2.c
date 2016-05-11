#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
struct node{
        struct node *next;
        int val;
};
typedef struct node node;

node * reverseLinkedList(node *head){
/* For your reference
  struct node{
        node *next;
        int val;
};
typedef struct node node;
You can just start declaring new objects by node *x. It's already declared
*/
    if(head->next==NULL||head==NULL)
        return head;
    else if(head->next->next==NULL){
        node *p = head->next;
        head->next = NULL;
        p->next = head;
        return p;
    }
    
    node *p, *q, *r;
 
    p = head, q = head, r = head;
    p = p->next->next;
    q = q->next;
    r->next = NULL;
    q->next = r;
 
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}

int main() {

    int N;
    scanf("%d",&N);    
    node * head = NULL;
    if (N > 0) { head = (node *)malloc(sizeof(node)); }
    node * t = head;
    int i;
    for( i = 0;i < N;i++ ){
        int x; scanf("%d",&x); t->val = x;
        if( i == N-1 ){ t->next = NULL;continue;}
        t->next = (node *)malloc(sizeof(node));
        t->next->next = NULL;
        t = t->next;
    }
    
    node * ret = reverseLinkedList(head);
   
    while( ret != NULL ){
        printf("%d\n",ret->val);
        ret = ret->next;
    }
    
return 0;

}