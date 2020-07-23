/*** temporary file ***
	Must Be Revised 
*/
#include "XBuffer.h"

XBuffer::XBuffer(uint64_t xbsize, DRAMInterface *dram) {
	this->xbsize = xbsize;
	this->dram = dram;
}

XBuffer::~XBuffer() {}