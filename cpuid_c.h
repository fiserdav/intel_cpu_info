
/* 
 * File:   cpuid.h
 * Author: david_fiser
 *
 * Created on January 29, 2018, 3:57 PM
 */

#ifndef CPUID_H
#define CPUID_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <cpuid.h>
    
struct cpuid_result {
    uint8_t valid;
    uint32_t eax, ebx, ecx, edx;
}; 

struct cpuid_result cpuid(uint32_t eaxIn, uint32_t ecxIn);

#ifdef __cplusplus
}
#endif

#endif /* CPUID_H */

