#include "List.h"
#include <stdlib.h>
#include <stdio.h>

struct strNode{
	Type key;
	Type data;
	struct strNode* next;
};

typedef struct strNode * Node;

struct strList{
	int size;
	Node first;
	Node last;
	void(*destructorK)(void*);
	void(*destructorV)(void*);
};


List list_create(void (*destructorK)(void*), void(*destructorV)(void*)){
	List l = (List)malloc(sizeof(struct strList));
	l->first = l->last = NULL;
	l->size = 0;
	l->destructorK = destructorK;
	l->destructorV = destructorV;
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
		if(l->destructorK != NULL){
			l->destructorK(current->key);
		}
		if(l->destructorV != NULL){
			l->destructorV(current->data);
		}
		free(current);
		current = next;
	}
	free(l);
}

int  list_size(List l){
	return l->size;
}

void list_add(List l, Type k, Type v){
	//printf("JAZ");
	if(l == NULL){
		return;
	}
	Node n = (Node)malloc(sizeof(struct strNode));
	if(n == NULL){
		return;
	}
	n->data = v;
	n->key=k;
	n->next = NULL;
	if(l->size == 0){
		l->first= l->last = n;
	}
	else if (l->size>0){
		l->last->next = n;
		l->last= n;
	}
	l->size++;
}

Type list_getkey(List l, int p){
	if(l == NULL){
		return NULL;
	}
	int i = 0;
	Node current = l->first;
	while(i != p){
		current = current->next;
		i++;
	}
	return current->key;
}
Type list_getdata(List l, int p){
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
	Node prior = l->first;
	Type temp;
	while(i < p){
		prior=current;
		current = current->next;
		i++;
	}
	temp=current->data;
	if(current==l->first){
		if(current->next==NULL)
			l->first=NULL;
		else
			l->first=current->next;
		free(current);
	}
	else if(current == l->last){
		prior->next=NULL;
		l->last=prior;
		free(current);
	}
	else{
		prior->next=current->next;
		free(current);
	}
	l->size--;
	return (temp);
}


void print(List l){
	Node current = l->first;
	while(current != NULL){
		printf("%s ,%d\t", (char*)current->key, *(int*)current->data);
		current = current->next;
	}
}



