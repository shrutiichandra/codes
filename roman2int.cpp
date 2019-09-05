//g++ roman2int.cpp -o roman2int
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int roman2int(string s){
	int num;

	//if the string is empty, return 0
	if(s==""){
		return 0;
	}

	//a map to store symbol and value pairs
	unordered_map<string,int> symb_val{ {"I",1},
										{"V",5},
										{"X",10},
										{"L",50},
										{"C",100},
										{"D",500},
										{"M",1000}
										};

	//first check if the string is one of those in map
	for(auto i=symb_val.begin();i!=symb_val.end();i++){
		if(i->first==s){
			num=i->second;
			return num;
		}
	}

	//do this if some other combination of symbols is input 
	num=0;

	for(int i=0;i<s.length();i++){
		//scan first 2 letters from left
		string first(1,s[i]);	
		string second(1,s[i+1]);
		cout<<"first: "<<first<<" second: "<<second<<"\n";

		//if the first symbol is smaller, then we subtract. e.g IV = V - I = 4
		if(symb_val[first]<symb_val[second]){
			int net = symb_val[second] - symb_val[first];
			cout<<"net: "<<net<<", ";
			num += net;
			cout<<"num: "<<num<<"\n";
			i+=1;
		}

		//if the first symbol is greater or equal, then we simply add. e.g III = I + I + I = 3
		else if(symb_val[first]>=symb_val[second]){
			int val=symb_val[first];
			cout<<"val: "<<val<<",";

			num+=val;
			cout<<"num: "<<num<<"\n";

		}	
	}

	return num;
}

int main(){
	
		// cout<<roman2int("III")<<"\n";	
		// cout<<roman2int("IV")<<"\n";	
		// cout<<roman2int("IX")<<"\n";	
		// cout<<roman2int("ML")<<"\n";	
		cout<<roman2int("MCMXCIV")<<"\n";	

	return 0;
}