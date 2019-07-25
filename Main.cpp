// Note player
// Version 1.0
// by Ryan Isler
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>

	/* // char str[] is different from char*. however they function similarly. Example:
	char str[] ="- This, a sample string.";
	char * pch;
	printf ("Splitting string \"%s\" into tokens:\n",str);
	pch = strtok (str," ,.-");
	while (pch != NULL)
	{
	printf ("%s\n",pch);
	pch = strtok (NULL, " ,.-");
	}*/
using namespace std;
DWORD getFrequency(char _chord[]);

void playString(char a[]);

void play_the_lick() {	
	Beep(getFrequency("A"), 200);
	Beep(getFrequency("B"), 200);
	Beep(getFrequency("C"), 200);
	Beep(getFrequency("D"), 200);
	Beep(getFrequency("Bb"), 200);
	Beep(getFrequency("B"), 200);
	Beep(getFrequency("g"), 200);
	Beep(getFrequency("A"), 200);
	return;
}

int main() {
	ifstream inStream;
	char playThese[32768] = "A";

	system("title Chord Player V1.01 created by Ryan Isler");
	inStream.open("chords.txt");
	if(inStream.fail() == true) {
		cout << "chords.txt not found." << endl;
		strcpy_s(playThese, "F E D C F E D C F E F Gb G E D C _ _ C _ C c");
	} else {
		int _ptIndex = 0;
		char streamGet;
		strcpy_s(playThese, "");
		while(! inStream.eof()) {
			inStream.get(streamGet);
			//strcat(playThese, streamGet);
			sprintf_s(playThese,"%s%c",playThese,streamGet);
			//strcat(playThese, "");
		}
		//cout << playThese;
	}
	cout << "Playing notes..." << endl;
	playString(playThese); 
	//int ihatec = 1;
	//printf("You are dumb: %d %p", ihatec, playThese);
	cout << "Note playing completed. Enter any key to exit." << endl;
	system("pause >nul");
	return 0;
}

void playString(char _i[]) {
	char * nextNote;
	//printf("%s\n", nextNote);
	nextNote = strtok(_i, " ");
	while(nextNote != NULL) {
		printf("%s ", nextNote);
		if(strcmp(nextNote, "_") != 0) { // rest
			Beep(getFrequency(nextNote), 150);
		} else {
			Sleep(150);
		}
		Sleep(150);
		nextNote = strtok(NULL, " ");
	}
	printf("\n");
	return;
}

DWORD getFrequency(char * _chord) {
	DWORD _hz = 220;
	//std::cout << strcmp(_chord,"A") << std::endl;
	if(strcmp(_chord, "ab") == 0) {
		_hz = 208;
	} else if(strcmp(_chord, "a") == 0) {
		_hz = 220;
	} else if(strcmp(_chord, "bb") == 0) {
		_hz = 233;
	} else if(strcmp(_chord, "b") == 0) {
		_hz = 247;
	} else if(strcmp(_chord, "c") == 0) {
		_hz = 262;
	} else if(strcmp(_chord, "db") == 0) {
		_hz = 277;
	} else if(strcmp(_chord, "d") == 0) {
		_hz = 294;
	} else if(strcmp(_chord, "eb") == 0) {
		_hz = 311;
	} else if(strcmp(_chord, "e") == 0) {
		_hz = 330;
	} else if(strcmp(_chord, "f") == 0) {
		_hz = 349;
	} else if(strcmp(_chord, "gb") == 0) {
		_hz = 370;
	} else if(strcmp(_chord, "g") == 0) {
		_hz = 392;
	} else if(strcmp(_chord, "Ab") == 0) {
		_hz = 415;
	} else if(strcmp(_chord, "A") == 0) {
		_hz = 440;
	} else if(strcmp(_chord, "Bb") == 0) {
		_hz = 466;
	} else if(strcmp(_chord, "B") == 0) {
		_hz = 493;
	} else if(strcmp(_chord, "C") == 0) {
		_hz = 523;
	} else if(strcmp(_chord, "Db") == 0) {
		_hz = 554;
	} else if(strcmp(_chord, "D") == 0) {
		_hz = 587;
	} else if(strcmp(_chord, "Eb") == 0) {
		_hz = 622;
	} else if(strcmp(_chord, "E") == 0) {
		_hz = 659;
	} else if(strcmp(_chord, "F") == 0) {
		_hz = 698;
	} else if(strcmp(_chord, "Gb") == 0) {
		_hz = 740;
	} else if(strcmp(_chord, "G") == 0) {
		_hz = 784;
	}
	return _hz;
}