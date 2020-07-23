/*** temporary file ***
	Must Be Revised 
*/
#ifndef __VERTEXREADER_H__
#define __VERTEXREADER_H__

#include <iostream>
#include <queue>
#include "DRAMInterface.h"
#include "Common.h"

using namespace std;

class VertexReader {
public:
	VertexReader(int id, DRAMInterface *dram);
	~VertexReader();
	void ReceiveData(queue<uint64_t> data);
	void Request();
private:
	int id;
	int q_space;
	bool req_need;
	DRAMInterface *dram;
	queue<uint64_t> vq; //save vertex data from DRAM
};

#endif