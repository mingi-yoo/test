/*** temporary file ***
	Must Be Revised 
*/
#include "AController.h"

using namespace std;

AController::AController(int id,
						 DRAMInterface *dram, 
						 DataController *data, 
						 GlobalBuffer *gb, 
						 Accelerator *acc) {
	this->id = id;
	this->dram = dram;
	this->data = data;
	this->gb = gb;
	this->acc = acc;
	vr = new VertexReader(id, dramm);
	er = new EdgeReader(id, dram);
	xwr = new XWReader(id, gb, acc);
}

AController::~AController() {
	delete vr;
	delete er;
	delete xwr;
}

void AController::RunController() {
	if (dram->IsReadComplete()) {
		uint64_t address = dram->GetReadData();
		Type type = data->ReturnDataType(address);
		queue <uint64_t> ret_data;
		if (type == A_ROW) {
			ret_data = data->AdjRowDataReturn();
			vr->ReceiveData(ret_data);
		}
		else if (type == A_COL) {
			ret_data = data->AdjColDataReturn();
			er->ReceiveData(ret_data);
		}
	}
}