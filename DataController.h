/*** temporary file ***
	Must Be Revised 
*/
#include <iostream>
#include <queue>
#include "Common.h"

using namespace std;

class DataController {
public:
	DataController(int id, 
				   queue<float> xvalue, 
				   queue<uint64_t> adjrowindex, 
				   queue<uint64_t> adjcolindex);
	~DataController();
	Type ReturnDataType(uint64_t address); //Data Type Check
	queue<float> XDataReturn(); //Return X Data in the form of queue 
	queue<uint64_t> AdjRowDataReturn(); //Return A_ROW Data in the form of queue
	queue<uint64_t> AdjColDataReturn(); //Return A_COL Data in the form of queue
private:
	int id;
	queue<float> xvalue, xvalue_archive;
	queue<uint64_t> adjrowindex, adjrowindex_archive;
	queue<uint64_t> adjcolindex, adjcolindex_archive;
};