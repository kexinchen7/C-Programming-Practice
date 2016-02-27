/*
 common struct and functions for singly-linked list
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct ListNode {
	int data;
	struct ListNode *next;
} node;

node* newNode(int val) {
	node* new_node = (node *)malloc(sizeof(node));
	new_node->data = val;
	new_node->next = NULL;
	return new_node;
}

void print_list(node *head) {
	node *p = head;
	while(p != NULL) {
		printf("%d\n", p->data);
		p = p->next;
	}
}

