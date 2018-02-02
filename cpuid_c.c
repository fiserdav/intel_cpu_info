
/* 
 * File:   cpuid_c.c
 * Author: david_fiser
 *
 * Created on February 2, 2018, 11:43 AM
 */

#include "cpuid_c.h"
#include "string.h"
/*
 Returns struct with cpuid information
 */
struct cpuid_result cpuid(uint32_t eaxIn, uint32_t ecxIn){
    struct cpuid_result ret;
    memset(&ret, sizeof(struct cpuid_result),0);
    
    __get_cpuid(0x0, &ret.eax, &ret.ebx, &ret.ecx, &ret.edx);
    if(eaxIn <= ret.eax){
        memset(&ret, sizeof(struct cpuid_result),0);
        __get_cpuid(eaxIn, &ret.eax, &ret.ebx, &ret.ecx, &ret.edx);
        ret.valid = 1;
    }else {
        printf("CPU does not support leaf %x information", eaxIn);
    }
    
    return ret;
}