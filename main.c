
/* 
 * File:   main.c
 * Author: david_fiser
 *
 * Created on January 29, 2018, 1:47 PM
 */

#include "modules/PDInfo.h"
#include "modules/TsxCheck.h"
#include "modules/ArchInfo.h"

#include <iostream>

#define BRANCH_TOTAL 3 // used for compiler check  
#define printDashes(n) {for(int i =0; i<n;i++) {std::cout << "-";} std::cout << std::endl;}

// parameters
char *branches[BRANCH_TOTAL] = { "-pd",
                    "-arch",
                    "-tsx" };
// parameters classes 
std::shared_ptr<CpuInfo> intelInfo[] = {
    std::shared_ptr<PDInfo>(new PDInfo),
    std::shared_ptr<ArchInfo>(new ArchInfo),
    std::shared_ptr<TsxCheck>(new TsxCheck)
};


int main(int argc, char** argv) {
    if(argc < 2) {
        std::cout << "invalid parameters, usage: " << std::endl;
        for(int i = 0; i < BRANCH_TOTAL; i++) {
            std::cout << "\t" << branches[i] << " " << intelInfo[i]->getDesc() << std::endl;
        }
        return EXIT_FAILURE;
    }
    
    for(int i = 0; i < BRANCH_TOTAL; i++) {   
        printDashes(80);
        intelInfo[i]->printInformation();
    }
    
    return (EXIT_SUCCESS);
}


