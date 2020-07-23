/*** temporary file ***
	Must Be Revised 
*/
#ifndef __EDGEREADER_H__
#define __EDGEREADER_H__

#include <iostream>
#include <queue>
#include "DRAMInterface.h"
#include "Common.h"

using namespace std;

class EdgeReader {
public:
	EdgeReader(int id, DRAMInterface *dram);
	~EdgeReader();
	void ReceiveData(queue<uint64_t> data);
	void ReceiveData(uint64_t vertex);
private:
	int id;
	uint64_t cur_v;
	uint64_t prev_v;
	DRAMInterface *dram;
	queue<uint64_t> eq; //save edge data from DRAM
};

#endif