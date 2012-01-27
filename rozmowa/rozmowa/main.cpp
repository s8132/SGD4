#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* args[]){

	string jeden;
	bool done=true;

	fstream pierwszy( "start.txt", std::ios::in );

	while(done){
		for(int i=0; i<4; i++){
			getline(pierwszy, jeden);
			cout << jeden << endl;
		}


	}
	getch();

	return 0;
}