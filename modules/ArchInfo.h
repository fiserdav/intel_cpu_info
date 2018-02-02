
/* 
 * File:   ArchInfo.h
 * Author: david_fiser
 *
 * Created on February 2, 2018, 12:23 PM
 */

#ifndef ARCHINFO_H
#define ARCHINFO_H

#include "CpuInfo.h"


class ArchInfo : public CpuInfo{
public:
    ArchInfo();
    ArchInfo(const ArchInfo& orig);
    

    virtual void printInformation();

    virtual const char * getDesc();

    
    virtual ~ArchInfo();
private:

};

#endif /* ARCHINFO_H */

