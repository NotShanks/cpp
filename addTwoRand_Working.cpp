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
while (input!=x+y) {
cout << "What is " << x << " + " << y << "?" << endl;
cin >> input;
if (input==x+y){
cout << "congrats";
return 0;
}
else {
cout << "Incorrect, please try again." << endl;
}
}
}
