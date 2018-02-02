
/* 
 * File:   TsxCheck.h
 * Author: david_fiser
 *
 * Created on February 2, 2018, 11:52 AM
 */

#ifndef TSXCHECK_H
#define TSXCHECK_H
#include "CpuInfo.h"


class TsxCheck : public CpuInfo{
public:
    TsxCheck();
    TsxCheck(const TsxCheck& orig);
    virtual ~TsxCheck();
    
    
    virtual void printInformation();

    virtual const char * getDesc();


private:

};

#endif /* TSXCHECK_H */

