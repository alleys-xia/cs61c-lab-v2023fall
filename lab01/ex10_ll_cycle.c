#include <stddef.h>
#include "ex10_ll_cycle.h"

int ll_has_cycle(node *head) {
    /* TODO: Implement ll_has_cycle */
    node* slow_ptr= head;
    node* fast_ptr= head;
    while(fast_ptr!=NULL) {
        //fast指针前进两步
        fast_ptr= fast_ptr->next;
        if(fast_ptr==NULL){
            break;
        }else {
            fast_ptr= fast_ptr->next;
        }
        //slow前进一步
        slow_ptr= slow_ptr->next;
        if(slow_ptr==fast_ptr)
            return 1;
    }
    return 0;
}
