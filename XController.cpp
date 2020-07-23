/*** temporary file ***
	Must Be Revised 
*/
#include "XController.h"

using namespace std;

XController::XController(int id,
						 DRAMInterface *dram, 
						 DataController *data,
						 GlobalBuffer *gb, 
						 Xbuffer *xb, 
						 Accelerator *acc) {
	this->id = id;
	this->dram = dram;
	this->data = data;
	this->gb = gb;
	this->xb = xb;
	this->acc = acc;
	xr = new XReader(id, dram);
	wr = new WReader(id, gb, acc);
}

XController::~XController() {
	delete xr;
	delete wr;
}