#include <iostream>
#include "chain.h"
using namespace std;

int main(){
	chain CHA;
	chain* A = new chain();
	CHA.push_front(20);
	CHA.push_back(40);
	CHA.push_front(40);
	CHA.push_front(47);

	cout << endl <<"size="<<CHA.size()<<">>"<< CHA.front() <<"/"<<CHA.back() <<endl;

	CHA.insert(500,4);
	int c = CHA[0];
	cout << c <<endl;
	cout << endl <<"size="<<CHA.size()<<">>"<< CHA.front() <<"/"<<CHA.back() <<endl;
	CHA.clear();
	cout << endl <<"size="<<CHA.size()<<">>"<< CHA.front() <<"/"<<CHA.back() <<endl;
	CHA.insert(200,0);
	cout << CHA[0] << endl;
	cout << endl <<"size="<<CHA.size()<<">>"<< CHA.front() <<"/"<<CHA.back() <<endl;

	CHA.push_back(40);
	CHA.push_front(40);
	CHA.push_front(47);
	CHA.insert(345,CHA.size());

	cout << endl <<"size="<<CHA.size()<<">>"<< CHA.front() <<"/"<<CHA.back() <<endl;
	/*
	*/
}