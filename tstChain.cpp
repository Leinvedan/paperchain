#include <iostream>
#include "chain.h"
using namespace std;

int main(){
	chain CHA;
	chain* A = new chain();
	CHA.add(20);
	CHA.add(40);
	CHA.add(40);
	CHA.add(47);
	int c = CHA[1];
	cout << c <<endl;
}