/*** temporary file ***
	Must Be Revised 
*/
#ifndef __XCONTROLLER_H__
#define __XCONTROLLER_H__

#include <iostream>
#include "DRAMInterface.h"
#include "DataController.h"
#include "GlobalBuffer.h"
#include "XBuffer.h"
#include "Accelerator.h"
#include "XReader.h"
#include "WReader.h"
#include "Common.h"

using namespace std;

class XController {
public:
	XController(int id,
				DRAMInterface *dram,
				DataController *data, 
				GlobalBuffer *gb, 
				XBuffer *xb, 
				Accelerator *acc);
	~XController();
private:
	int id = id;
	DRAMInterface *dram;
	DataController *data;
	GlobalBuffer *gb;
	XBuffer *xb;
	Accelerator *acc;
	XReader *xr;
	WReader *wr;
};

#endif