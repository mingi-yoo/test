/*** temporary file ***
	Must Be Revised 
*/
#include "WReader.h"

using namespace std;

WReader::WReader(GlobalBuffer *gb, Accelerator *acc) {
	this->gb = gb;
	this->acc = acc;
}

WReader::~WReader() {}