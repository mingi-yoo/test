/*** temporary file ***
	Must Be Revised 
*/
#include "Accelerator.h"

using namespace std;

Accelerator::Accelerator(uint64_t tot_acc, DRAMInterface *dram) {
	this->tot_acc = tot_acc;
	this->dram = dram;
}

Accelerator::~Accelerator() {}