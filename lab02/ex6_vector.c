/* Include the system headers we need */
#include <stdlib.h>
#include <stdio.h>

/* Include our header */
#include "ex6_vector.h"

/* Define what our struct is */
struct vector_t {
    size_t size;
    int *data;
};

/* Utility function to handle allocation failures. In this
   case we print a message and exit. */
static void allocation_failed() {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
}

/* Bad example of how to create a new vector */
vector_t *bad_vector_new() {
    /* Create the vector and a pointer to it */
    vector_t *retval, v;
    retval = &v;

    /* Initialize attributes */
    retval->size = 1;
    retval->data = malloc(sizeof(int));
    if (retval->data == NULL) {
        allocation_failed();
    }

    retval->data[0] = 0;
    return retval;
}

/* Create a new vector with a size (length) of 1 and set its single component to zero... the
   right way */
/* TODO: uncomment the code that is preceded by // */
vector_t *vector_new() {
    /* Declare what this function will return */
    vector_t *retval;
    /* First, we need to allocate memory on the heap for the struct */
    retval= malloc(sizeof(vector_t));
    /* Check our return value to make sure we got memory */
     if (retval==NULL) {
         allocation_failed();
     }
    /* Now we need to initialize our data.
       Since retval->data should be able to dynamically grow,
       what do you need to do? */
     retval->size = 1;
     retval->data = malloc(sizeof(int));

    /* Check the data attribute of our vector to make sure we got memory */
     if (retval->data==NULL) {
         free(retval);				//Why is this line necessary?
         allocation_failed();
     }

    /* Complete the initialization by setting the single component to zero */
     retval->data[0] = 0;

    /* and return... */
    return retval; /* UPDATE RETURN VALUE */
}

/* Return the value at the specified location/component "loc" of the vector */
int vector_get(vector_t *v, size_t loc) {

    /* If we are passed a NULL pointer for our vector, complain about it and exit. */
    if(v == NULL) {
        fprintf(stderr, "vector_get: passed a NULL vector.\n");
        abort();
    }

    /* If the requested location is higher than we have allocated, return 0.
     * Otherwise, return what is in the passed location.
     */
    /* YOUR CODE HERE */
    if(v->size<loc)
        return 0;
    return v->data[loc];
}

/* Free up the memory allocated for the passed vector.
   Remember, you need to free up ALL the memory that was allocated. */
void vector_delete(vector_t *v) {
    /* YOUR CODE HERE */
    free(v->data);
    free(v);
}

/* Set a value in the vector, allocating additional memory if necessary. 
   If the extra memory allocation fails, call allocation_failed(). */
void vector_set(vector_t *v, size_t loc, int value) {
    /* What do you need to do if the location is greater than the size we have
     * allocated?  Remember that unset locations should contain a value of 0.
     */
    /* realloc 函数的行为是这样的：
    * 如果 realloc 成功，它会分配一块新的内存，并将旧内存的数据复制到新内存中。然后，它会释放旧的内存块，并返回指向新内存块的指针。
    * 如果 realloc 失败，它会返回 NULL，旧内存块保持不变，不会被释放。 */
    if(loc<v->size) {
        int* temp= realloc(v->data, sizeof(int)*loc);
        //分配失败时，释放原先的内存并退出
        if(temp==NULL) {
            free(v->data);
            allocation_failed();
        }
        v->data= temp;
        //set 0
        for(size_t i=size;i<=loc;++i) {
            v->data[i]= 0;
        }
    }
    v->data[loc]= value;
}
