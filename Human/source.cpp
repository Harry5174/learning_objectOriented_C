#include <iostream>
#include <vector>
#include "organ.h"
#include "human.h"

using namespace std;

int main(int argc, char* argv[]) {
	int x = argc -1;
//	cout<<"Argument count except exe. file: "<<argc-1<<endl;
	if ( x % 2 != 0 )
	{
//		cout<<x<<endl;
		cerr<<"usage: " << argv[0] << " <Organ1> <Function1> <Organ2> <Function2> ...\n";
		return 1;
	}
	
	Human human;
	
	for (int i = 1; i<argc ; i+=2) {
		
//		cout<<i<<endl<<i+1<<endl;
		string organName = argv[i];
		string organFunction = argv[i+1];
		
		Organ organ(organName, organFunction);
		human.addOrgan(organ);
	}
	
	cout<<"\nHuman and his organs created by CLI: \n";
	human.display();
	cout<<endl<<endl;	
	
	cout<<"Human and his organs created through main(): \n";
	Human human1("Harry", "male", 19);
	Organ organ1("Heart", "Pumps Blood"),organ2("Brain", "control over body"),organ3("Liver", "Filters Blood");
	
	human1.addOrgan(organ1);
	human1.addOrgan(organ2);
	human1.addOrgan(organ3);
	
	human1.display();
		
	return 0;
}