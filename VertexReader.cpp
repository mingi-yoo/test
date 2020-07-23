/*** temporary file ***
	Must Be Revised 
*/
#include "VertexReader.h"

VertexReader::VertexReader(int id, DRAMInterface *dram) : q_space(0), req_need(true) {
	this->id = id;
	this->dram = dram;
}

VertexReader::~VertexReader() {}

void VertexReader::ReceiveData(queue<uint64_t> data) {
	int bound = data.size();
	for (int i = 0; i < bound; i++) {
		vq.push(data.front());
		data.pop();
	}
} 

void VertexReader::Request() {
	q_space += 8;
	if (MAX_QUEUE_SIZE - q_space < 8)
		req_need = false;
	// TO DO
}