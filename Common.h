/*** temporary file ***
	Must Be Revised 
*/
#ifndef __COMMON_H__
#define __COMMON_H__

#define MAX_QUEUE_SIZE 256

using namespace std;

uint64_t CACHE_LINE_BYTE; 
uint64_t CACHE_LINE_COUNT;

uint64_t A_COL_START;  
uint64_t A_ROW_START;  
uint64_t X_START;  
uint64_t WEIGHT_START; 
uint64_t XW_START;
uint64_t AXW_START;

/*Address Topology
X_START
-> A_ROW_START
-> A_COL_START
-> WEIGHT_START
-> XW_START
-> AXW_START
*/

enum Type {X, A_ROW, A_COL};

#endif