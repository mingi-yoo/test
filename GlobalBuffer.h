/*** temporary file ***
	Must Be Revised 
*/
#ifndef __GLOBALBUFFER_H__
#define __GLOBALBUFFER_H__

#include <iostream>
#include <queue>
#include "DRAMInterface.h"
#include "Common.h"

using namespace std;

class GlobalBuffer {
public:
	GlobalBuffer(uint64_t gbsize, DRAMInterface *dram);
	~GlobalBuffer();
private:
	uint64_t gbsize;
	DRAMInterface *dram;
};

#endif