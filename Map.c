#include "Map.h"
#include "List.h"

#include <stdio.h>
#include <stdlib.h>

struct strMap{
    int size;
    int m;
    List* table;
    HashFunc hF;
    EqualsFunc eF;
    DestroyFunc aDestructor;
    DestroyFunc bDestructor;
};

Map map_create(int m, HashFunc hF, EqualsFunc eF, DestroyFunc aDestructor,DestroyFunc bDestructor){
    Map mp = (Map)malloc(sizeof(struct strMap));
    mp->size=0;
    mp->m=m;
    mp->table=(List*)calloc(m,sizeof(List));
    mp->hF=hF;
    mp->eF=eF;
    mp->aDestructor=aDestructor;
    mp->bDestructor=bDestructor;
    return mp;
}
void map_destroy(Map mp)
{
	for(int i=0;i<mp->m;i++)
	{
		list_destroy(mp->table[i]);
	}
	
	free(mp	);
}
int  map_size(Map mp){
	int ac=0;

	for(int i=0;i<mp->m;i++)
	{
		if(mp->table[i]!=NULL)
			ac+=list_size(mp->table[i]);
	}
	return ac;
}

void map_put(Map mp, Type k, Type v)
{
	if(mp==NULL) return;
	
	int indice= mp->hF(k,mp->m);
	//printf("%d\n", indice);
	
	if(mp->table[indice]==NULL)
	{
		//printf("JAZ2\n");
		mp->table[indice]=list_create(NULL, NULL);
	//	mp->table[indice]=(List)malloc(sizeof(structStrList));
		list_add(mp->table[indice], k, v);
		//printf("%s\n", (char*)list_getkey(mp->table[indice], 0));
		//printf("%d\n", *(int*)list_getdata(mp->table[indice], 0));
		//mp->table[indice]->key=k;
	}
	else
	{
		//ver si la llave ya existe, entonces se reemplaza
		bool existe=False;
		for(int i=0; i<list_size(mp->table[indice]);i++)
		{
			if(list_getkey(mp->table[indice], i) == k)
			{
				list_set(mp->table[indice], v, i );
				existe=True;
			}
		}
		
		if(!existe)
		{
			list_add(mp->table[indice], k, v);	
		}
	}
	mp->size++;
}
Type map_get(Map mp, Type k)
{
	if(mp==NULL) return NULL;
	bool existe=False;	
	Type x;
	int indice= mp->hF(k,mp->m);
	
	if(mp->table[indice]==NULL)
		return NULL;
	
	int i=0;
	
	for( i=0; i<list_size(mp->table[indice]);i++)
	{
		x=list_getkey(mp->table[indice], i);
		if(mp->eF(x,k)==True)
		{
			existe=True;	
			break;
		}
		else
			existe=False;
	}


	if(existe) return list_getdata(mp->table[indice], i);
	return NULL;
}

Type map_remove(Map mp, Type k)
{
	if(mp==NULL) return NULL;
	bool existe=False;	
	Type x;
	int indice= mp->hF(k,mp->m);
	if(mp->table[indice]==NULL)
		return NULL;
	
	int i=0;
	for( i=0; i<list_size(mp->table[indice]);i++)
	{
		x=list_getkey(mp->table[indice], i);
		if(mp->eF(x,k)==True)
		{
			
			existe=True;
			break;
		}
		else
			existe=False;
	}
	if(existe) return list_remove(mp->table[indice], i);
	return NULL;
	
}

void map_print(Map m, PrintFunc keyPrinter, PrintFunc valuePrinter){
	for(int i = 0; i<m->m; i++){
		printf("%d: ", i);
		if(m->table[i] != NULL){
			for(int j = 0; j<list_size(m->table[i]); j++){
				keyPrinter(list_getkey(m->table[i], j));
				valuePrinter(list_getdata(m->table[i], j));
			}
		}
		printf("\n");
	}
}
