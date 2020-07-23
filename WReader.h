/*** temporary file ***
	Must Be Revised 
*/
#ifndef __WREADER_H__
#define __WREADER_H__

#include <iostream>
#include <queue>
#include "DRAMInterface.h"
#include "Common.h"

using namespace std;

class WReader {
public:
	WReader(GlobalBuffer *gb, Accelerator *acc);
	~WReader();
private:
	GlobalBuffer *gb;
	Accelerator *acc;
};

#endif