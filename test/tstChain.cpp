#include <iostream>
#include "chain.h"
using namespace std;

void testA(){
	chain<double> CHA;
	CHA.push_front(20);
	CHA.push_back(40);
	CHA.push_front(40);
	CHA.push_front(47);
	CHA.insert(500,4);
	int c = CHA[0];
	cout << c <<endl;
	CHA.clear();
	CHA.insert(200,0);
	cout << CHA[0] << endl;

	CHA.push_back(40);
	CHA.push_front(40);
	CHA.push_front(47);
	CHA.insert(345,CHA.size());
	cout << CHA.back() << "------------" <<endl;
}

void testB(){
	chain<double> C;
	for (int i = 1; i < 1000; ++i){
		C.push_front(i*2);
	}
	cout << C.size() << endl;
	cout << C.front() << "/" << C.back() << endl;
	while(C.size()){
		cout << C.back()/2 <<"|";
		C.pop_back();
	}
	cout << endl;
	cout << C.size() << endl;
	cout << C.front() <<"/" <<C.back() << endl;
}

int main(){
	testA();
	testB();
}

