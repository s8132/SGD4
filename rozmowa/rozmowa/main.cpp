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

	string neutralnyText, negatywnyText, pozytywnyText;
	bool done=true;
	int nastawienie = 1, odpowiedz;
	/*
		NASTAWIENIE:
		0 - negtywne
		1 - neutralne
		2 - pozytywne
	*/

	fstream neutralny( "neutralny.txt", std::ios::in );
	fstream negatywny( "negatywny.txt", std::ios::in );
	fstream pozytywny( "pozytywny.txt", std::ios::in );

	while(done){
		for(int i=0; i<4; i++){
			if(nastawienie==0){
				getline(negatywny, negatywnyText);
				if(negatywnyText=="KONIEC"){
					done = false;
					break;
				}
				cout << negatywnyText << endl;
			}
			if(nastawienie==1){
				getline(neutralny, neutralnyText);
				if(neutralnyText=="KONIEC"){
					done = false;
					break;
				}
				cout << neutralnyText << endl;
			}
			if(nastawienie==2){
				getline(pozytywny, pozytywnyText);
				if(pozytywnyText=="KONIEC"){
					done = false;
					break;
				}
				cout << pozytywnyText << endl;
			}
		}
		if(done==false){
			break;
		}

		cin >> odpowiedz;

		if(odpowiedz==1){
			if(nastawienie<2) nastawienie++;
			else nastawienie=2;
		}
		if(odpowiedz==2){
			if(nastawienie>0) nastawienie=0;
			else nastawienie=0;
		}
	}
	getch();

	return 0;
}