
/* 
 * File:   PDInfo.cpp
 * author: willgamz
 * merged by : david_fiser
 * 
 * Created on February 2, 2018, 1:33 PM
 */

#ifndef PDINFO_H
#define PDINFO_H

#include "CpuInfo.h"


class PDInfo :public CpuInfo{
public:
    PDInfo();
    PDInfo(const PDInfo& orig);
    virtual ~PDInfo();
    

    virtual void printInformation();

    virtual const char * getDesc();


private:
    struct cpuid_result leaf_14h_result;
    struct cpuid_result leaf_14h_subleaf_01;
};

#endif /* PDINFO_H */

