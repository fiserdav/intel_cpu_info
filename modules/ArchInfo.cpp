
/* 
 * File:   ArchInfo.cpp
 * Author: david_fiser
 * 
 * Created on February 2, 2018, 12:23 PM
 */

#include "ArchInfo.h"
#include <cstdint>
#include <iostream>

using namespace std;

ArchInfo::ArchInfo() {
    this->cpu_result = cpuid(0xa,0x0);
}

ArchInfo::ArchInfo(const ArchInfo& orig) {
}

ArchInfo::~ArchInfo() {
}

void ArchInfo::printInformation(){
    // Intel manual page reference .. Table 3-8. Information Returned by CPUID Instruction; Vol. 2A 3-195
    if(this->cpu_result.valid) {
        cout << "Printing architectural CPU Information:" << endl << endl; 

        uint32_t arch_version = this->cpu_result.eax & 0xff; 
        uint32_t counter_per_logical_processor = (this->cpu_result.eax & 0xff00) >> 8;
        uint32_t bit_width = (this->cpu_result.eax & 0xff0000) >> 16;
        uint32_t bit_vector = (this->cpu_result.eax & 0xff000000) >> 24;

        cout << "Version ID of architectural performance monitoring = " << arch_version << endl;
        cout << "Number of general-purpose performance monitoring counter per logical processor = " << counter_per_logical_processor << endl;

        cout << "Bit width of general-purpose, performance monitoring counter = " << bit_width << endl;
        cout << "Length of EBX bit vector to enumerate architectural performance monitoring events = " << bit_vector << endl;


        /*
        Bit 00: Core cycle event not available if 1.
        Bit 01: Instruction retired event not available if 1.
        Bit 02: Reference cycles event not available if 1.
        Bit 03: Last-level cache reference event not available if 1.
        Bit 04: Last-level cache misses event not available if 1.
        Bit 05: Branch instruction retired event not available if 1.
        Bit 06: Branch mispredict retired event not available if 1.
         */

        cout << "Core cycle event available:" << YES_NO_I((this->cpu_result.ebx & BIT_X(0)));

        cout << "Instruction retired event available: " << YES_NO_I((this->cpu_result.ebx & BIT_X(1)));
        cout << "Reference cycles event available: " << YES_NO_I((this->cpu_result.ebx & BIT_X(2)));
        cout << "Last-level cache reference event available: " << YES_NO_I((this->cpu_result.ebx & BIT_X(3)));
        cout << "Last-level cache misses event available: " << YES_NO_I((this->cpu_result.ebx & BIT_X(4)));
        cout << "Branch instruction retired event available: " << YES_NO_I((this->cpu_result.ebx & BIT_X(5)));
        cout << "Branch mispredict retired event available: " << YES_NO_I((this->cpu_result.ebx & BIT_X(6)));

        cout << "Number of fixed-function performance counters ((if Version ID > 1) = " << (this->cpu_result.edx & 0xf) << endl;
        cout << "Bit width of fixed-function performance counters (if Version ID > 1) = " << ((this->cpu_result.edx & 0xff0) >> 5) << endl;
    
    }
    
}

const char * ArchInfo::getDesc() {
   return "prints cpuid - Architectural Performance Monitoring Leaf information";
}
