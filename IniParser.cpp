/*** temporary file ***
	Must Be Revised 
*/
#include "IniParser.h"

using namespace std;

IniParser::IniParser(string path) { ReadIni(path); }

IniParser::~IniParser() {}

bool IniParser::ReadIni(string path)
{
	ifstream openFile(path);
	if (openFile.is_open()) {
		string line;
		while (getline(openFile, line)) {
			string delimiter = " = ";
			if (string::npos == line.find(delimiter)) 
				delimiter = "=";
			string token1 = line.substr(0, line.find(delimiter));
			string token2 = line.substr(line.find(delimiter)+delimiter.length(), line.length());
			m_table[token1] = token2;
		}
		openFile.close();
		ParseIni();
		return true;
	}
	else {
		throw invalid_argument("Cannot open inifile");
	}
}

bool IniParser::Contain(string name)
{
	if (m_table.find(name) == m_table.end()) 
		return false;
	return true;
}

bool IniParser::GetBool(string name)
{
	if (Contain(name)) {
		if (m_table[name][0] == 't' || m_table[name][0] == 'T')
			return true;
		else
			return false;
	}
	else {
		throw invalid_argument("Not exist.");
	}
}

string IniParser::GetString(string name)
{
	if (Contain(name)) {
		if (m_table[name].find("\"") == string::npos)
			return m_table[name];
		else
			return m_table[name].substr(1, m_table[name].length() - 2);
	}
	else {
		throw invalid_argument("Not exist.");
	}
}

float IniParser::GetFloat(string name)
{
	if (Contain(name))
		return stof(m_table[name]);
	else
		throw invalid_argument("Not exist.");
}

int IniParser::GetInt(string name)
{
	if (Contain(name))
		return stoi(m_table[name]);
	else
		throw invalid_argument("Not exist.");
}

uint64_t IniParser::GetUint64(string name)
{
	if (Contain(name))
		return stoull(m_table[name], NULL, 0);
	else
		throw invalid_argument("Not exist.");
}

void IniParser::ParseIni()
{
	gbsize = GetUint64("GlobalBufferSize");
	xbsize = GetUint64("XBufferSize");
	tot_acc = GetUint64("TotalNumOfAcc");
	CACHE_LINE_BYTE = GetUint64("CacheLineByte");
	CACHE_LINE_COUNT = GetUint64("CacheLineCount");
	A_COL_START = GetUint64("AColStartAddress");
	A_ROW_START = GetUint64("ARowStartAddress");
	X_START = GetUint64("XStartAddress");
	WEIGHT_START = GetUint64("WeightStartAddress");
	XW_START = GetUint64("XWResultStartAddress");
	AXW_START = GetUint64("AXWResultStartAddress");
}
