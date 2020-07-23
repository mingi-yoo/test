/*** temporary file ***
	Must Be Revised 
*/
#include "EdgeReader.h"

using namespace std;

EdgeReader::EdgeReader(int id, DRAMInterface *dram) : prev_v(0){
	this->id = id;
	this->dram = dram;
}

EdgeReader::~EdgeReader() {}

void EdgeReader::ReceiveData(queue<uint64_t> data) {
	int bound = data.size();
	for (int i = 0; i < bound; i++) {
		eq.push(data.front());
		data.pop();
	}

} 

void EdgeReader::ReceiveData(uint64_t vertex) {
	cur_v = vertex;
}