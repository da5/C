#include<stdio.h>
#include<stdlib.h>

struct sll_node{
	int data;
	struct sll_node *next;
	
};

void sll_insert(struct sll_node **head, int data){
//	printf("Inserting Node ..........\n");
	struct sll_node *node = (struct sll_node*)malloc(sizeof(struct sll_node));
	node->data = data;
	if(*head==NULL){
		*head = node;
	}else{
		struct sll_node *curr=*head; 
		while(curr->next!=NULL){
			curr=curr->next;
		}
		(curr->next) = node;
	}
//	printf("Inserting Node ..........Done\n");
	
}

struct sll_node* create_list_1_to_n(int n){
	int i;
//	printf("Creating list ..........\n");
	struct sll_node *head = NULL;
	for(i=1;i<=n;i++){
		sll_insert(&head, i);
	}
//	printf("Creating list ..........Done\n");
	return head;
}

void fold_sll_(struct sll_node *head, struct sll_node **head_){
	if(head==NULL)
		return;
	printf("Call for %d\n", head->data);	
	fold_sll_(head->next, head_);
	
	
	if(head->next!=NULL && (*head_)->next!=NULL){
		struct sll_node *temp = head;
		printf("Pointing %d to %d\n",head->next->data,(*head_)->next->data);
		head->next->next = (*head_)->next;
		printf("Pointing %d to %d\n",(*head_)->data,head->next->data);
		(*head_)->next = head->next;
		printf("Pointing head_ to %d\n",head->next->next->data);
		*head_ = (*head_)->next->next;
		temp->next = NULL;
	}
	printf("Callback for %d :: *head = %d\n", head->data,(*head_)->data);
}

void fold_sll(struct sll_node **head){
	if((*head)!=NULL){
		if((*head)->next!=NULL){
			if((*head)->next->next!=NULL)
				fold_sll_(*head, head);
		}
	}
	
}

void print_list(struct sll_node *head){
	while(head!=NULL){
		printf("%d->",head->data);
		head=head->next;
	}
	printf("\n");
}

int main(){
	int n, x;
	printf("Enter N:");
	scanf("%d", &n);
	struct sll_node *head = create_list_1_to_n(n);
	print_list(head);
	struct sll_node *head_ref = head;
	fold_sll(&head_ref);
	print_list(head);
	return 0;
}