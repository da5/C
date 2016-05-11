#include<stdio.h>
#include<stdlib.h>

struct tree_node{
	int data;
	struct tree_node *left;
	struct tree_node *right;
};

struct tree_node *dll_head = NULL, *dll_tail=NULL;

void insert(struct tree_node **root, int data){
	struct tree_node *node = (struct tree_node*)malloc(sizeof(struct tree_node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	struct tree_node *curr = *root;
	
	if(curr==NULL){
		*root = node;	
	}else{
		while(curr!=NULL){
			if(curr->data == data)
				break;
			else if(curr->data < data){
				if(curr->right==NULL){
					curr->right = node;
					break;
				}else{
					curr = curr->right;
				}
			}else{
				if(curr->left==NULL){
					curr->left = node;
					break;
				}else{
					curr = curr->left;
				}
			}
		}	
	}
//	return root;
}

struct stack_node{
	struct tree_node *data;
	struct stack_node *next;
};

void push(struct stack_node **head, struct tree_node *data){
	struct stack_node *node = (struct stack_node*)malloc(sizeof(struct stack_node));
	node->data = data;
	node->next = *head;
	*head = node;
}

struct tree_node* pop(struct stack_node **head){
	struct stack_node *node = *head;
	struct tree_node *data = (*head)->data;
	*head = (*head)->next;
	free(node);
	return data;
}

int is_stack_empty(struct stack_node *head){
	if(head==NULL)
		return 1;
	else
		return 0;
}

void print_stack(struct stack_node *head){
	printf("Stack(%d) :: ",is_stack_empty(head));
	for(;head!=NULL;head=head->next){
		printf("%d ",head->data->data);
	}
	printf("\n");
}


void rec_inorder(struct tree_node *root){
	if(root!=NULL){
		rec_inorder(root->left);
		printf("%d ", root->data);
		rec_inorder(root->right);
	}
}

void itr_inorder(struct tree_node *root){
	struct stack_node *stack = NULL;	
	struct tree_node *tnode;
	while(!is_stack_empty(stack) || root!=NULL){
		if(root!=NULL){
			push(&stack, root);
			root = root->left;
		}else{
			tnode = pop(&stack);
			printf("%d ", tnode->data);
			root = tnode->right;
		}
	}
}

void rec_preorder(struct tree_node *root){
	if(root!=NULL){
		printf("%d ", root->data);
		rec_preorder(root->left);
		rec_preorder(root->right);
	}
}

void itr_preorder(struct tree_node *root){
	struct stack_node *stack = NULL;	
	struct tree_node *tnode;
	if(root!=NULL){
		push(&stack, root);
	}
	while(!is_stack_empty(stack)){
		tnode = pop(&stack);
		printf("%d ", tnode->data);
		if(tnode->right!=NULL){
			push(&stack, tnode->right);
		}
		if(tnode->left!=NULL){
			push(&stack, tnode->left);
		}
	}
}

void rec_postorder(struct tree_node *root){
	if(root!=NULL){
		rec_postorder(root->left);
		rec_postorder(root->right);
		printf("%d ", root->data);
	}
}

void itr_postorder(struct tree_node *root){
	struct stack_node *stack1 = NULL;	
	struct stack_node *stack2 = NULL;
	struct tree_node *tnode;
	if(root!=NULL){
		push(&stack1, root);
	}
	while(!is_stack_empty(stack1)){
		tnode = pop(&stack1);
		push(&stack2, tnode);
		if(tnode->left!=NULL){
			push(&stack1, tnode->left);
		}
		if(tnode->right!=NULL){
			push(&stack1, tnode->right);
		}
	}
	while(!is_stack_empty(stack2)){
		tnode = pop(&stack2);
		printf("%d ", tnode->data);
	}
}

void convert(struct tree_node *root){
	if(root==NULL)
		return;
	convert(root->left);
	if(dll_head == NULL){
		dll_head = dll_tail = root;
		root->left = NULL;
	}else{
		dll_tail->right = root;
		root->left = dll_tail;
		dll_tail = root;
	}
	convert(root->right);
}

int main(){
	int n, x;
	printf("Enter N:");
	scanf("%d", &n);
	struct tree_node *root = NULL;
//	struct tree_node *curr = root;
	
	while(n--){
		scanf("%d", &x);
		insert(&root, x);
	}
//	curr = root;
	
	printf("Recursive Inorder Traversal\n");
	rec_inorder(root);
	printf("\n\n");
	printf("Iterative Inorder Traversal\n");
	itr_inorder(root);
	printf("\n\n");

//	printf("Recursive Prerder Traversal\n");
//	rec_preorder(root);
//	printf("\n\n");
//	printf("Iterative Prerder Traversal\n");
//	itr_preorder(root);
//	printf("\n\n");
//
//	printf("Recursive Postorder Traversal\n");
//	rec_postorder(root);
//	printf("\n\n");
//	printf("Iterative Postorder Traversal\n");
//	itr_postorder(root);
//	printf("\n\n");
//	
	convert(root);
	for(;dll_head!=NULL; dll_head = dll_head->right)
		printf("%d ", dll_head->data);
	printf("\n\n");	

}