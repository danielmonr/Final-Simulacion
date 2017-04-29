#include <iostream>
#include <stdlib.h>
#include "../helper.h"

#define CUTOMER_WT_COST 100
#define LAMDA 30
#define SERVICE_TIME 0.05
#define SALARY 10
#define OPEN_PER_DAY 10

using namespace std;

int number_clerks[3] = {2,3,4};

void A(){
	cout << "Average time in line for:" << endl;
	
}

int main(int argc, char* argv[]){

	values_t* v = Helper::MMm(2,3,2);
	Helper::printValues(v);


	return 0;
}