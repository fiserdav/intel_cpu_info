
/* 
 * File:   TsxCheck.cpp
 * Author: david_fiser
 * 
 * Created on February 2, 2018, 11:52 AM
 */

#include "TsxCheck.h"
#include <iostream>
using namespace std;


TsxCheck::TsxCheck() {
    this->cpu_result = cpuid(0x7,0x0);
}

TsxCheck::TsxCheck(const TsxCheck& orig) {
}

TsxCheck::~TsxCheck() {
}


void TsxCheck::printInformation() {
    if( this->cpu_result.valid) {
        cout << "Checking TSX availability:" << endl;

        cout << "\t" << "HLE: " << YES_NO((this->cpu_result.ebx & BIT_X(4))); // if CPUID.07H.EBX.HLE [bit 4] = 1;
        cout << "\t" << "RTM: " << YES_NO((this->cpu_result.ebx & BIT_X(11)));// CPUID.07H.EBX.RTM [bit 11] =
    }
}

const char * TsxCheck::getDesc() {
    return "checks availability of TSX-NI instruction extension";
}
