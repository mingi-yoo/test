/*** temporary file ***
	Must Be Revised 
*/
#include "XWReader.h"

using namespace std;

XWReader::XWReader(int id, GlobalBuffer *gb, Accelerator *acc) {
	this->id = id;
	this->gb = gb;
	this->acc = acc;
}

XWReader::~XWReader() {}