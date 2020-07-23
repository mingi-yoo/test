/*** temporary file ***
	Must Be Revised 
*/
#ifndef __DRAMINTERFACE_H__
#define __DRAMINTERFACE_H__

#include <iostream>
#include <string>
#include <src/dramsim3.h>
#include "Common.h"

using namespace std;

class DRAMInterface {
public:
	DRAMInterface(const string& config_file, const string& output_dir);
	~DRAMInterface();
	void UpdateCycle(); //update 1 cycle
	void DRAMRequest(uint64_t address, bool is_write); //request read/write to dram
	bool IsReadComplete(); //get imformation whether dram read is complete or not
	uint64_t GetReadData(); //get read address that read complete
private:
	dramsim3::MemorySystem *dram;
	bool read_complete;
	uint64_t read_address;
	void ReadCompleteCallback(uint64_t address); 
	void WriteCompleteCallback(uint64_t address); 
};

#endif