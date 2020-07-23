/*** temporary file ***
	Must Be Revised 
*/
#ifndef __XREADER_H__
#define __XREADER_H__

#include <iostream>
#include <queue>
#include "DRAMInterface.h"
#include "Common.h"

using namespace std;

class XReader {
public:
	XReader(int id, DRAMInterface *dram);
	~XReader();
private:
	int id;
	DRAMInterface *dram;
	queue<uint64_t> xq; //save x data from DRAM
};

#endif