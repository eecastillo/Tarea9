
#ifndef MAP_H_
#define MAP_H_

#include "List.h"


typedef struct strMap* Map;

typedef int (*HashFunc) (Type, int);
typedef bool(*EqualsFunc) (Type, Type);
typedef void (*DestroyFunc) (Type);
typedef void (*PrintFunc) (Type);




Map map_create(int m, HashFunc hF, EqualsFunc eF, DestroyFunc aDestructor,DestroyFunc bDestructor);
void map_print(Map m, PrintFunc keyPrinter, PrintFunc valuePrinter);
void map_destroy(Map);
int  map_size(Map);
void map_put(Map mp, Type k, Type v);
Type map_get(Map mp, Type k);
Type map_remove(Map mp, Type k);
void printm(Map);

#endif /* LIST_H_ */
