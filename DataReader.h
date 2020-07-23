/*** temporary file ***
	Must Be Revised 
*/
#ifndef __DATAREADER_H__
#define __DATAREADER_H__

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
#include <stdexcept>
#include "Common.h"

using namespace std;

class DataReader {
public:
	DataReader(string path);
	~DataReader();
	uint64_t weight_h;
	uint64_t weight_w;
	uint64_t x_h;
	uint64_t x_w;
	uint64_t a_h;
	queue<float> ifvalue;
	queue<uint64_t> adjrowindex;
	queue<uint64_t> adjcolindex;
private:
	queue<float> GetFloatVal(string line, char delimiter);
	queue<uint64_t> GetUint64Val(string line, char delimiter);
	bool ReadData(string path);
};

#endif