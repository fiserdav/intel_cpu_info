
/* 
 * File:   PDInfo.cpp
 * author: willgamz
 * merged by : david_fiser
 * 
 * Created on February 2, 2018, 1:33 PM
 */

#include "PDInfo.h"
#include <iostream>
#include <bitset>

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

PDInfo::PDInfo() {
    this->cpu_result = cpuid(0x7, 0);
    this->leaf_14h_result = cpuid(0x14, 0);
    this->leaf_14h_subleaf_01 = cpuid(0x14, 0x1);
}

PDInfo::PDInfo(const PDInfo& orig) {
}

PDInfo::~PDInfo() {
}

void PDInfo::printInformation() {
    std::cout << std::endl;

    if (this->cpu_result.valid) {

        std::cout << "Intel PT CPU capabilities Analysis:" << std::endl;

        if (std::bitset<32>(this->cpu_result.ebx).test(25)) {
            std::cout << " Intel PT Supported." << std::endl;
            std::cout << "   capabilities EBX:" << std::endl;
            for (int i = 0; i <= 31; i++) {
                if (std::bitset<32>(this->leaf_14h_result.ebx).test(i))
                    std::cout << "    " << leaf_ebx_14h[i] << std::endl;
            }

            std::cout << "   capabilities ECX:" << std::endl;
            for (int i = 0; i <= 31; i++) {
                if (std::bitset<32>(this->leaf_14h_result.ecx).test(i))
                    std::cout << "    " << leaf_ecx_14h[i] << std::endl;
            }
        } else {
            std::cout << " No Intel PT Supported" << std::endl;
        }

        std::cout << std::endl;
        std::cout << "Intel PT CPU capabilities raw data:" << std::endl;
        std::cout << " Features: (CPUID.(EAX=07H,ECX=0H)):" << std::endl;
        std::cout << "  EAX:" << std::bitset<32>(this->cpu_result.eax) << std::endl;
        std::cout << "  EBX:" << std::bitset<32>(this->cpu_result.ebx) << "  : Note: 25 bit must be ON. Example: " << std::bitset<32>((1 << 25)) << std::endl;
        std::cout << "  ECX:" << std::bitset<32>(this->cpu_result.ecx) << std::endl;
        std::cout << "  EDX:" << std::bitset<32>(this->cpu_result.edx) << std::endl;

        std::cout << "  Capabilities (CPUID.(EAX=14H,ECX=0)):" << std::endl;
        std::cout << "    EAX:" << std::bitset<32>(this->leaf_14h_result.eax) << std::endl;
        std::cout << "    EBX:" << std::bitset<32>(this->leaf_14h_result.ebx) << std::endl;
        std::cout << "    ECX:" << std::bitset<32>(this->leaf_14h_result.ecx) << std::endl;
        std::cout << "    EDX:" << std::bitset<32>(this->leaf_14h_result.edx) << std::endl;

        std::cout << "  Capabilities (CPUID.(EAX=14H,ECX=1)):" << std::endl;
        std::cout << "    EAX:" << std::bitset<32>(this->leaf_14h_subleaf_01.eax) << std::endl;
        std::cout << "    EBX:" << std::bitset<32>(this->leaf_14h_subleaf_01.ebx) << std::endl;
        std::cout << "    ECX:" << std::bitset<32>(this->leaf_14h_subleaf_01.ecx) << std::endl;
        std::cout << "    EDX:" << std::bitset<32>(this->leaf_14h_subleaf_01.edx) << std::endl;
    }
}

const char* PDInfo::getDesc() {
    return "Intel PT CPU capabilities Analysis";
}
