#ifndef HUMAN_H
#define HUMAN_H
#include "organ.h"
#include <iostream>
#include <vector>

using namespace std;

class Human {
	string name;
	string gender;
	int age;
//	const vector<Organ> eOrgans;
	vector<Organ> organs;
	
	public:
		Human() 
			:name("Harry"), gender("male"), age(19) {}
		
		Human(string nm, string gn, int ag)
			: name(nm), gender(gn), age(ag) {}
			
		//Non get/set	
		void addOrgan(Organ &tmpOrgan) {
			organs.push_back(tmpOrgan);
		}
		
		void display () const {
			int i = 0;
			cout<<"Human Details: "<<getDetails()<<endl;
			for(const Organ &tempOrgan : organs)
			{
				cout<<"Organ: "<<tempOrgan.getName()<<endl
					<<"Function: "<<tempOrgan.getFunction()<<endl<<endl;
			}
		}
		
		
		//Get/set
		void setName(const string x) {
			name = x;
		}
		string getName() const {
			return name;
		}
		
		void setGender(const string x) {
			gender = x;
		}
		string getGender() const {
			return gender;
		}
		
		void setAge(const int x) {
			age = x;
		}
		int getAge() const {
			return age;
		}
		
		string getDetails() const {
			return name + ' ' + gender + ' ' + to_string(age);
		}
};

#endif
