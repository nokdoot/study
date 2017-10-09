#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
struct Node{
	int data;
	struct Node* XORaddr;
};

struct Node *XOR(struct Node *a, struct Node *b){
	return (struct Node *) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

void *insertNode(struct Node **head, int data){
	struct Node *tmp_node = (struct Node *) malloc(sizeof(struct Node));
	tmp_node->data = data;

	tmp_node->XORaddr = XOR(*head, NULL);

	if(*head != NULL){
		struct Node *next = XOR((*head)->XORaddr, NULL);
		(*head)->XORaddr = XOR(tmp_node, next);
	}

	*head = tmp_node;
}

void printxor(struct Node *head){
	struct Node *cur = head;
	struct Node *pre = NULL;
	struct Node *next;

	while(cur != NULL){
		printf("%d ", cur->data);
		next = XOR(pre, cur->XORaddr);
		
		pre = cur;
		cur=next;
	}
}

int main(){
	struct Node *head = NULL;
	insertNode(&head, 1);
	insertNode(&head, 2);
	insertNode(&head, 3);
	insertNode(&head, 4);
	printxor(head);
}
