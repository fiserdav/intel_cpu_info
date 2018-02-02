
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
#include <memory>
#include <map>
#include <string>

#define printDashes(n) {for(int i =0; i<n;i++) {std::cout << "-";} std::cout << std::endl;}

typedef std::shared_ptr<CpuInfo> fPtr;

// parameters
std::map<std::string, fPtr> pars;

void initPars() {
	pars.insert(std::pair<std::string,fPtr>("-pd",fPtr(new PDInfo)));
	pars.insert(std::pair<std::string,fPtr>("-arch", fPtr(new ArchInfo)));
	pars.insert(std::pair<std::string,fPtr>("-tsx",fPtr(new TsxCheck)));
}

int main(int argc, char** argv) {
	initPars();
    if(argc < 2) {
        std::cout << "invalid parameters, usage: " << std::endl;
		std::map<std::string,fPtr>::iterator it;
		for(it = pars.begin(); it != pars.end(); it++){
			std::cout << "\t" << it->first << " " << it->second->getDesc() << std::endl;
		}
        return EXIT_FAILURE;
    }
    
    for(int i = 1; i < argc; i++) {
		std::map<std::string, fPtr>::iterator it = pars.find(argv[i]);
		
		if( it != pars.end()) {
			it->second->printInformation();
		}
    }
    
    return (EXIT_SUCCESS);
}


