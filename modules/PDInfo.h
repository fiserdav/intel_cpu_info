
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
    const char* leaf_ebx_14h[32] = {
				"0 CR3 Filtering Support",
				"1 Configurable PSB_and CycleAccurate Mode Supported",
				"2 IP Filtering and TraceStop supported, and Preserve Intel PT MSRs across warm reset",
				"3 MTC Supported",
				"4 PTWRITE Supported",
				"5 Power Event Trace Supported",
				"rv","rv","rv","rv","rv","rv","rv","rv","rv","rv","rv","rv","rv", //reserved
				"rv","rv","rv","rv","rv","rv","rv","rv","rv","rv","rv","rv","rv"
			};

    const char* leaf_ecx_14h[32] = {
            "0 ToPA Output Supported",
            "1 ToPA Tables Allow Multiple Output Entries",
            "2 Single-Range Output Supported",
            "3 Output to Trace Transport Subsystem Supported",
            "rv","rv","rv","rv","rv","rv","rv","rv","rv","rv","rv","rv","rv","rv", //reserved
            "rv","rv","rv","rv","rv","rv","rv","rv","rv","rv","rv","rv","rv"
            "31 IP Payloads are LIP"
    };
};

#endif /* PDINFO_H */

