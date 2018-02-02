
/* 
 * File:   CpuInfo.h
 * Author: david_fiser
 *
 * Created on February 2, 2018, 11:48 AM
 */

#ifndef CPUINFO_H
#define CPUINFO_H
#include "../cpuid_c.h"


#define YES_NO(val) (val ? "yes\n" : "no\n");
#define YES_NO_I(val) (val ? "no\n" : "yes\n")
#define BIT_X(X) ( 1 << X)

class CpuInfo {
     
public:
    CpuInfo();
    CpuInfo(const CpuInfo& orig);
    virtual ~CpuInfo();
    
    virtual void printInformation() = 0;
    virtual const char * getDesc() = 0;
    
protected:
    struct cpuid_result cpu_result;
    
};


#endif /* CPUINFO_H */

