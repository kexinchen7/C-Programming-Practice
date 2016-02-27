
#include "list.h"


node* swap_pairs(node *head) {
	if(head == NULL) {
		return;
	}

	node *dummy_head = newNode(0);
	dummy_head->next = head;

	node *last = dummy_head;

	node *cur = head;
	node *nxt = head->next;

	while(cur != NULL && nxt != NULL) {
		node *temp = nxt->next;
		nxt->next = cur;
		cur->next = NULL;
		last->next = nxt;
		last = cur;

		cur = temp;
		nxt = cur->next;
	}
	// if there is odd number of nodes
	if(cur != NULL) {
		last->next = cur;
		last = cur;
	}

	return dummy_head->next;
}


int main() {
	node *head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);

	// before swap the pairs
	printf("before swapping: \n");
	print_list(head);

	printf("after swapping: \n");
	print_list(swap_pairs(head));

	return 0;
}