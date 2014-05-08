/**
 * Implementation of the software paging unit.
 */
#include "addressTranslation.h"

#include <stdio.h>
#include <stdlib.h>

static pagetable *ptr = NULL; // ptr = "page table register"

void setPageTable(pagetable *pt) {
    ptr = pt;
}

int getPhysical(int logical) {
    // check if the logical page value exists
    // JD: Max check could have been unhardcoded via the #define's.
    if ( logical < 0 || logical >= 256 ) {
        return ERR_OUT_OF_RANGE;
    }
    
    // get bits corresponding to the page
    int page = (( logical & PAGEMASK) >> PAGEBITS);
    // JD: Because you are right-shifting, note you don't need the & :)
    // get bits corresponding to the offset
    int offset = (logical & PAGESIZE);
    
    // check if the page is valid
    if (ptr[page].valid == 0) {
        return ERR_INVALID;
    }
    
    // return the page address + the offset
    return ((ptr[page].frame) << PAGEBITS) + offset;
}
