#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <locale>

using namespace std;

string intToString(int n){
	
	string tmp;

	if(n<0){
		tmp = "-";
		n = -n;
	}
	if(n>9) tmp += intToString(n/10);
	tmp += n%10+48;

	return tmp;
}


int main(int argc, char* args[]){

	string text;
	bool done=true;
	int nastawienie = 1, odpowiedz;
	/*
		NASTAWIENIE:
		0 - negtywne
		1 - neutralne
		2 - pozytywne
	*/

	locale myloc("Polish");
	locale oldloc = locale::global(myloc);

	int wezel=0, wybor;
	char *str;

	fstream plik( "test.txt", std::ios::in );
	
	while(done){
		while(!plik.eof()){
			getline(plik, text);
			if(text==intToString(wezel)){
				for(int j=0; j<4; j++){
					getline(plik, text);
					if(text=="KONIEC"){
						done = false;
						break;
					}
					cout << text << endl;
				}
				break;
			}
		}

		if(done==false){
			break;
		}

		cout << "Dokanj wyboru: ";
		cin>>wybor;
		wezel = wezel*3+wybor;
		//cout << "Wezel: " << wezel;
	}
	
	cout << "\nKONIEC (Tu teraz dziejê siê dalsza akcja)" << endl; 
	getch();

	return 0;
}