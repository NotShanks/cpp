//Non asking user to try again version aka my version
/*
Create: 

	 1. Using math random function; "What does x + y equal to?" "What does x * y equal to?" Etc.
	 2.
		2a. Ask question and get user's input
		2b. Match user's input and cout if its correct or not. 
  */


#include <iostream>
#include <time.h> 
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int add()
{
  int oneRand = rand() % 100;
  return oneRand;
}

int main()
{
    srand (time(NULL));
  int x{add()};
  int y{add()};
  int input{};
do {
   cout << "What is " <<  x << " + " << y << "?" << endl;
  cin >> input;
  if (input==x+y){
  cout << "congrats";
   return 0;
    }
  } while (input!=x+y);
}
