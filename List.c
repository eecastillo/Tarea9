#include "List.h"
#include <stdlib.h>
#include <stdio.h>

struct strNode{
	Type key;
	Type data;
	struct strNode* next;
	//struct strNode* prior;
};

typedef struct strNode * Node;

struct strList{
	int size;
	Node first;
	Node last;
//	Node preFirst;
//	Node postLast;
	void(*destructor)(void*);
};


List list_create(void (*destructor)(Type)){
	List l = (List)malloc(sizeof(struct strList));
	l->first = l->last = NULL;
	l->size = 0;
	l->destructor = destructor;
	//l->preFirst = (Node)malloc(sizeof(struct strNode));
	//l->preFirst->next = l->first;
	//l->preFirst->prior = NULL;
	//l->postLast = (Node)malloc(sizeof(struct strNode));
	//l->postLast->prior = l->last;
	//l->postLast->next = NULL;
	return (l);
}

void list_destroy(List l){
	if(l == NULL){
		return;
	}
	Node current = l->first;
	Node next;
	while (current != NULL){
		next = current->next;
		if(l->destructor != NULL){
			l->destructor(current->data);
		}
		free(current);
		current = next;
	}
	free(l);
}

int  list_size(List l){
	return l->size;
}

void list_add(List l, Type d){
	if(l == NULL){
		return;
	}
	Node n = (Node)malloc(sizeof(struct strNode));
	if(n == NULL){
		return;
	}
	n->data = d;
	n->next = NULL;
	if(l->size == 0){
		l->first= l->last = n;
		n->prior = NULL;
	//	l->postLast->prior = n;
	//	l->preFirst->next = n;
	}
	else if (l->size>0){
		l->last->next = n;
		n->prior = l->last;
		l->last= n;
	//	l->postLast->prior = n;
	}
	l->size++;
}

Type list_get(List l, int p){
	if(l == NULL){
		return NULL;
	}
	int i = 0;
	Node current = l->first;
	while(i != p){
		current = current->next;
		i++;
	}
	return current->data;
}

void list_set(List l, Type d, int p){
	if(l == NULL){
		return;
	}
	int i = 0;
	Node current = l->first;
	while (i != p){
		current = current->next;
		i++;
	}
	current->data = d;
}

Type list_remove(List l, int p){
	if(l == NULL || l->size == 0){
		return NULL;
	}
	int i = 0;
	Node current = l->first;
	Type temp;
	while(i != p){
		current = current->next;
		i++;
		//printf("%d\n", i);
	}
	temp = current->data;
	//printf("%c\n", *(char*)temp);
	if(current->prior == NULL && current->next == NULL){
		free(current);
		l->first = NULL;
		//l->preFirst->next =NULL;
	}
	else if(current->prior == NULL){
		l->first = l->first->next;
		current->next->prior = NULL;
		free(current);
	}
	else if(current->next == NULL){
		l->last = l->last->prior;
		current->prior->next = NULL;
		free(current);
	}
	else{
		current->prior->next = current->next;
		current->next->prior = current->prior;
		free(current);
	}
	l->size--;
	//printf("%c %d", *(char*)temp, l->size);
	return (temp);
}
/*
Iterator list_begin(List l){
	return l->preFirst;
}

Iterator list_end(List l){
	return l->postLast;
}*/

bool list_hasNext(Iterator i){
	if(i->next != NULL){
		return True;
	}
	return False;
}

bool list_hasPrior(Iterator i){
	if(i->prior != NULL){
		return True;
	}
	return False;
}

Iterator list_next(Iterator i){
	if(list_hasNext(i)){
		return i->next;
	}
	return NULL;
}

Iterator list_prior(Iterator i){
	if(list_hasPrior(i)){
		return i->prior;
	}
	return NULL;
}

Type list_data(Iterator i){
	if(i != NULL){
		return i->data;
	}
	return NULL;
}



