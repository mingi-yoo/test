/*** temporary file ***
	Must Be Revised 
*/
#ifndef __ACONTROLLER_H__
#define __ACONTROLLER_H__

#include <iostream>
#include "DRAMInterface.h"
#include "DataController.h"
#include "GlobalBuffer.h"
#include "Accelerator.h"
#include "VertexReader.h"
#include "EdgeReader.h"
#include "XWReader.h"
#include "Common.h"

using namespace std;

class AController {
public:
	AController(int id,
				DRAMInterface *dram, 
				DataController *data, 
				GlobalBuffer *gb, 
				Accelerator *acc);
	~AController();
	void RunController();
private:
	int id; // for multi processing
	DRAMInterface *dram;
	DataController *data;
	GlobalBuffer *gb;
	Accelerator *acc;
	VertexReader *vr;
	EdgeReader *er;
	XWReader *xwr;
};

#endif