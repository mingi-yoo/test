/*** temporary file ***
	Must Be Revised 
*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "IniParser.h"
#include "DataReader.h"
#include "DRAMInterface.h"
#include "GlobalBuffer.h"
#include "XBuffer.h"
#include "Accelerator.h"
#include "AController.h"
#include "XController.h"
#include "Common.h"

using namespace std;

extern char *optarg;

int main(int argc, char** argv) {
	int option = 0;
	string ini;
	string data;

	if (argc == 1)
	{
		cout<<"You must follow this form: \'./sim -i inifile_path -d datafile_path\'"<<endl;
		return 0;
	}

	while ((option = getopt(argc, argv, "i:d:")) != EOF)
	{
		switch (option)
		{
			case 'i':
				ini = optarg;
				break;
			case 'd':
				data = optarg;
				break;
			case '?':
				cout<<"You must follow this form: \'./sim -i inifile_path -d datafile_path\'"<<endl;
				return 0;
		}
	}
	IniParser *iniparser = new IniParser(ini);
	DataReader *datareader = new DataReader(data);
	DRAMInterface *dram = new DRAMInterface("configs/HBM2_8Gb_x128.ini", "GCNSim");
	//TO DO

	return 0;
}