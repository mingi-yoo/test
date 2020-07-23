/*** temporary file ***
	Must Be Revised 
*/
#include "DRAMInterface.h"

using namespace std;

DRAMInterface::DRAMInterface(const string& config_file, const string& output_dir) {
	dram = dramsim3::getMemorySystem(config_file, output_dir, ReadCompleteCallback, WriteCompleteCallback);
	dram->RegisterCallbacks(ReadCompleteCallback, WriteCompleteCallback);
	read_complete = false;
}

DRAMInterface::~DRAMInterface() {
	delete dram;
}

void DRAMInterface::UpdateCycle() {
	dram->ClockTick();
}

void DRAMInterface::DRAMRequest(uint64_t address, bool is_write) {
	dram->AddTransaction(address, is_write);
}

bool DRAMInterface::IsReadComplete() {
	return read_complete;
}

uint64_t DRAMInterface::GetReadData() {
	read_complete = false;
	return read_address;
}

void DRAMInterface::ReadCompleteCallback(uint64_t address) {
	read_complete = true;
	read_address = address;
}

void DRAMInterface::WriteCompleteCallback(uint64_t address) {
	cout<<"Write Complete. Address: "<<hex<<address<<endl;
	//TO DO
	//check total write count for program over
}