/*
 * List.h
 *
 *  Created on: 26 oct 2018
 *      Author: gudo0
 */

#ifndef LIST_H_
#define LIST_H_

typedef struct  strList * List;
typedef void * Type;
typedef enum {False, True}bool;
typedef struct strNode * Iterator;

List list_create(void (*destructor)(Type));
void list_destroy(List);
int  list_size(List);
void list_add(List, Type);
Type list_get(List, int p);
void list_set(List, Type, int p);
Type list_remove(List, int p);

//Iterator list_begin(List);
//Iterator list_end(List);
bool list_hasNext(Iterator);
//bool list_hasPrior(Iterator);
//Iterator list_next(Iterator);
//Iterator list_prior(Iterator);
//Type list_data(Iterator);



#endif /* LIST_H_ */
