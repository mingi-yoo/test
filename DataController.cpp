/*** temporary file ***
	Must Be Revised 
*/
#include "DataController.h"

using namespace std;

DataController::DataController(int id,
							   queue<float> xvalue, 
							   queue<uint64_t> adjrowindex, 
							   queue<uint64_t> adjcolindex) {
	this->id = id;
	this->xvalue = xvalue;
	xvalue_archive = xvalue;
	this->adjrowindex = adjrowindex;
	adjrowindex_archive = adjrowindex;
	this->adjcolindex = adjcolindex;
	adjcolindex_archive = adjcolindex;
}

DataController::~DataController() {}

Type DataController::ReturnDataType(uint64_t address) {
	if (address >= X_START && address < A_COL_START)
		return X;
	else if (address >= A_ROW_START && address < A_COL_START)
		return A_ROW;
	else if (address >= A_COL_START && address < WEIGHT_START)
		return A_COL;
}

queue<float> DataController::XDataReturn() {
	int count = CACHE_LINE_COUNT;
	queue<float> ret;

	if (xvalue.size() < CACHE_LINE_COUNT)
		count = xvalue.size();

	for (int i = 0; i < count; i++) {
		ret.push(xvalue.front());
		xvalue.pop();
	}

	return ret;
}

queue<uint64_t> DataController::AdjRowDataReturn() {
	int count = CACHE_LINE_COUNT;
	queue<uint64_t> ret;

	if (adjrowindex.size() < CACHE_LINE_COUNT)
		count = adjrowindex.size();

	for (int i = 0; i < count; i++) {
		ret.push(adjrowindex.front());
		adjrowindex.pop();
	}

	return ret;
}

queue<uint64_t> DataController::AdjColDataReturn() {
	int count = CACHE_LINE_COUNT;
	queue<uint64_t> ret;

	if (adjcolindex.size() < CACHE_LINE_COUNT)
		count = adjcolindex.size();

	for (int i = 0; i < count; i++) {
		ret.push(adjcolindex.front());
		adjcolindex.pop();
	}

	return ret;
}