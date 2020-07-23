/*** temporary file ***
	Must Be Revised 
*/
#include "GlobalBuffer.h"

GlobalBuffer::GlobalBuffer(uint64_t gbsize, DRAMInterface *dram) {
	this->gbsize = gbsize;
	this->dram = dram;
}

GlobalBuffer::~GlobalBuffer() {}