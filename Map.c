#include "Map.h"

Map map_create(int m, HashFunc hF, EqualsFunc eF, DestroyFunc aDestructor,
DestroyFunc bDestructor);
void map_destroy(Map);
int  map_size(Map);
void map_put(Map m, Type k, Type v);
Type map_get(Map m, Type k);
Type map_remove(Map m, Type k);
