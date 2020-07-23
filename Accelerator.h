/*** temporary file ***
	Must Be Revised 
*/
#ifndef __ACCELERATOR_H__
#define __ACCELERATOR_H__

#include <iostream>
#include <queue>
#include "DRAMInterface.h"
#include "Common.h"

using namespace std;

class Accelerator {
public:
	Accelerator(uint64_t tot_acc, DRAMInterface *dram);
	~Accelerator();
private:
	uint64_t tot_acc;
	DRAMInterface *dram;
};

#endif