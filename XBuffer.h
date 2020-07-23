/*** temporary file ***
	Must Be Revised 
*/
#ifndef __XBUFFER_H__
#define __XBUFFER_H__

#include <iostream>
#include <queue>
#include "DRAMInterface.h"
#include "Common.h"

using namespace std;

class XBuffer {
public:
	XBuffer(uint64_t xbsize, DRAMInterface *dram);
	~XBuffer();
private:
	int id;
	uint64_t xbsize;
	DRAMInterface *dram;
};

#endif