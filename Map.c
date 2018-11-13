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
    mp->table=(List*)calloc(m*sizeof(List));
    mp->hF=hF;
    mp->eF=eF;
    mp->aDestructor=aDestructor;
    mp->bDestructor=bDestructor;
    return mp;
}
void map_destroy(Map mp){

}
int  map_size(Map mp){

}
void map_put(Map mp, Type k, Type v){

}
Type map_get(Map mp, Type k){

}
Type map_remove(Map mp, Type k){
    
}
