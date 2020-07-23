/*** temporary file ***
	Must Be Revised 
*/
#ifndef __XWREADER_H__
#define __XWREADER_H__

#include <iostream>
#include <queue>
#include "GlobalBuffer.h"
#include "Accelerator.h"
#include "Common.h"

using namespace std;

class XWReader {
public:
	XWReader(int id, GlobalBuffer *gb, Accelerator *acc);
	~XWReader();
private:
	GlobalBuffer *gb;
	Accelerator *acc;
};

#endif