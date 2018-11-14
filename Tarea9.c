#include "Map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hashfunc (Type string , int capacity )
{
	char *str = (char*)string; 
	int hash;
	int a1, a2,a3;
	
	a1 = (int)str[0]-65;
	a2 = (int)str[1]-65;
	a3 = (int)str[2]-65;

	hash=(((a1*(26^2))%capacity)+ ((a2*(26))%capacity)+ ((a3*(26^0))%capacity))%capacity;

	return hash;
}

bool Equals (Type value1, Type value2)
{
	char *str1 = (char*)value1; 
	char *str2 = (char*)value2;
	if (!strcmp(str1, str2)) return True;
	else return False;
}

int main(void)
{
	
	Map m = map_create(10, hashfunc,Equals,NULL, NULL);
	
	int n1 = 2001;
	int n2 = 2002;
	int n3 = 2003;
	int n4 = 2001;
	int n5 = 2003;
	
	char a1[] = "ABC";
	char a2[] = "DEF";
	char a3[] = "ADF";
	char a4[] = "CBF";
	char a5[] = "ABH";
	
	map_put(m, a1, &n2);
	map_put(m, a2, &n2);
	map_put(m, a3, &n3);
	map_put(m, a4, &n4);
	map_put(m, a5, &n5);
	map_put(m, a1, &n4);
	
	printm(m);
	printf("\n\n");
	
	printf("%d\n", *(int*)map_remove(m, a3));
	printm(m);
	printf("%d\n\n", *(int*)map_remove(m, a4));
	
	printm(m);
	
	printf("%d\n",*(int*)map_get(m, a1));
	//printf("%d\n", hashfunc(a, 1000));
	//printf("%d", Equals(a, b));
	printf("%d\n",map_size(m));
	
	return 0;
}