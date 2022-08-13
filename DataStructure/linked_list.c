#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#pragma warning (disable : 4996)
// queue

typedef struct node {
	int data;
	struct node* next; 
	struct node* prev;
}node; //�ڱ���������ü�� �̿��ؼ� �����

void insert(node* target, int data) {
	node* newnode = malloc(sizeof(node*)); //���ο��� ������ֱ�
	// newnode ����
	newnode->data = data;
	newnode->next = target->next;
	newnode->prev = target;
	// target�� target->next�� ���캸��
	if (target->next != NULL) target->next->prev = newnode;
	// ���� target node�� ������ �����, NULL->prev�� ����ĥ ���� �����Ƿ�,
	target->next = newnode;
}

void erase(node* target) {
	target->prev->next = target->next;
	// target->next�� �� ���캸��
	if (target->next != NULL) target->next->prev = target->prev;
}

int main(void) {
	node* p = malloc(sizeof(node*));
	p->next = NULL;
	p->prev = NULL;

	insert(p, 10);
	insert(p, 20);
	insert(p, 30);
	erase(p->next);

	node* ptr = p->next;
	while (ptr != NULL) {
		printf(" %d ", ptr->data);
		ptr = ptr->next;
	}
}