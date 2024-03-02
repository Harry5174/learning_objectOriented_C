#ifndef ORGAN_H
#define ORGAN_H
#include <iostream>

using namespace std;

class Organ {
	string name;
	string function;
	
	public:
		Organ(string nme, string fnc) : name(nme), function(fnc) {}
		
		void setName(const string tmpnme) {
			name = tmpnme;
		}	
		string getName() const {
			return name;
		}
		
		void setFunction(const string fnc) {
			function = fnc;
		}
		string getFunction() const {
			return function;
		}
};
#endif 