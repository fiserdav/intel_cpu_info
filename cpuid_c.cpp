
/* 
 * File:   cpuid_c.c
 * Author: david_fiser
 *
 * Created on February 2, 2018, 11:43 AM
 */

#include "cpuid_c.h"

/*
 Returns struct with cpuid information
 */

#ifdef _WIN32
#define WINDOWS
#endif

#ifdef _WIN64
#define WINDOWS
#endif

#ifdef WINDOWS
#include <intrin.h>
struct cpuid_result get_cpuid(uint32_t eax, uint32_t ecx) {
	int cpuInfo[4];
	struct cpuid_result ret;
	memset(&ret, 0, sizeof(cpuid_result));
	__cpuidex(cpuInfo,eax,ecx);
	ret.eax = cpuInfo[0];
	ret.ebx = cpuInfo[1];
	ret.ecx = cpuInfo[2];
	ret.edx = cpuInfo[3];

	return ret;
}
#endif

#ifdef __linux__
#define LINUX_OR_MAC
#endif

#ifndef __APPLE__
#define LINUX_OR_MAC
#endif

#ifdef LINUX_OR_MAC
#include <cpuid.h>
struct cpuid_result get_cpuid(uint32_t eaxIn, uint32_t ecxIn){
        cpuid_result ret;
	memset(&ret,0, sizeof(cpuid_result));
        ret.ecx = ecxIn;
	__cpuid_count(eaxIn, ecxIn, ret.eax, ret.ebx, ret.ecx, ret.edx);
        
	return ret;
}
#endif

struct cpuid_result cpuid(uint32_t eaxIn, uint32_t ecxIn){
    struct cpuid_result ret = get_cpuid(0x0,0x0);    
    if(eaxIn <= ret.eax){
        ret = get_cpuid(eaxIn,ecxIn);
        ret.valid = 1;
    }else {
        printf("CPU does not support leaf %x information", eaxIn);
    }
    
    return ret;
}

