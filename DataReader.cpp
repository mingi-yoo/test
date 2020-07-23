/*** temporary file ***
	Must Be Revised 
*/
#include "DataReader.h"

using namespace std;

DataReader::DataReader(string path) { ReadData(path); }

DataReader::~DataReader() {}

queue<float> DataReader::GetFloatVal(string line, char delimiter) 
{
	queue<float> internal;
	stringstream ss(line);
	string temp;

	while (getline(ss, temp, delimiter)) {
		if (temp == "\n")
			break;
		internal.push(stof(temp));
	}
	cout<<"OK"<<endl;

	return internal;
}

queue<uint64_t> DataReader::GetUint64Val(string line, char delimiter)
{
	queue<uint64_t> internal;
	stringstream ss(line);
	string temp;

	while (getline(ss, temp, delimiter)) {
		if (temp == "\n")
			break;
		internal.push(stoull(temp));
	}

	return internal;
}

bool DataReader::ReadData(string path)
{
	ifstream openFile(path);
	if (openFile.is_open()) {
		//get weight_h
		string line;
		getline(openFile, line);
		weight_h = stoi(line);
		x_w = weight_h;
		getline(openFile, line);
		//get weight_w(is equal to x_h)
		weight_w = stoi(line);
		getline(openFile, line);
		x_h = stoi(line);
		a_h = x_h;
		//get x matrix
		getline(openFile, line);
		ifvalue = GetFloatVal(line, ' ');
		//get adjacency csr
		getline(openFile, line);
		adjrowindex = GetUint64Val(line, ' ');
		getline(openFile, line);
		adjcolindex = GetUint64Val(line, ' ');
		openFile.close();
		return true;
	}
	else {
		throw invalid_argument("Cannot open datafile.");
	}
}
