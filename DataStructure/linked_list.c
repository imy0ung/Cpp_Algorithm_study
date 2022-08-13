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
}node; //자기참조구조체를 이용해서 만들기

void insert(node* target, int data) {
	node* newnode = malloc(sizeof(node*)); //새로운노드 만들어주기
	// newnode 설정
	newnode->data = data;
	newnode->next = target->next;
	newnode->prev = target;
	// target과 target->next를 살펴보기
	if (target->next != NULL) target->next->prev = newnode;
	// 만약 target node가 마지막 노드라면, NULL->prev를 가르칠 수도 있으므로,
	target->next = newnode;
}

void erase(node* target) {
	target->prev->next = target->next;
	// target->next를 잘 살펴보기
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