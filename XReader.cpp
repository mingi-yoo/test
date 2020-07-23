/*** temporary file ***
	Must Be Revised 
*/
#include "XReader.h"

using namespace std;

XReader::XReader(int id, DRAMInterface *dram) {
	this->id = id;
	this->dram = dram;
}

XReader::~XReader() {}