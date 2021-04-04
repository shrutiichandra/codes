//g++ validNum.cpp -o validNum
//https://leetcode.com/problems/valid-number/
//very slow
#include <iostream>
// #include <string>
#include <regex>
using namespace std;
bool isNumber(string s) {
		cout<<"s: |"<<s<<"| ";
		cout<<"s.length: "<<s.length()<<"| ";
		int len=s.length();

   		//trim spaces from both ends
   		int idx=0;
		while(s[idx]==' ' && idx<len){
			cout<<"\nidx: "<<idx<<"\n";
			idx++;
		}
		int first_val_idx=idx;
		if(idx>=len){
			return false;
		}
		idx=len-1;

		while(s[idx]==' ' && idx>=0){
			cout<<"idx dec: "<<idx<<"\n";
			idx--;
		}
		cout<<"exit both while\n";
		int last_val_idx=idx+1;
		cout<<"last_val_idx: "<<last_val_idx<<", first_val_idx: "<<first_val_idx<<"\n";
		string new_s(s.begin()+first_val_idx, s.begin()+last_val_idx);
		cout<<"|"<<new_s<<"|\n";
		
		//look for + or -
		if(new_s[0]=='-' || new_s[0]=='+'){
			new_s.erase(0,1);
		}		
		cout<<"after erase: |"<<new_s<<"| ";
		cout<<"new_s.length: "<<new_s.length()<<"| ";
		regex integer("[[:digit:]]+");
		if(regex_match(new_s,integer)){
			cout<<"integer| ";
			return true;
		}
		regex decimal("[[:digit:]]*\\.[[:digit:]]+"); //.9

		regex decimal2("[[:digit:]]+\\.[[:digit:]]*"); //9.

		if(regex_match(new_s,decimal) || regex_match(new_s,decimal2)){
			cout<<"decimal| ";
			return true;
		}

		// regex exp_int("[[:digit:]]+[e][[:digit:]]+");
		regex exp_int("[[:digit:]]+[e][-]?[\\+]?[[:digit:]]+");
		if(regex_match(new_s,exp_int)){
			cout<<"exp int| ";
			return true;
		}	

		regex exp_dec("[[:digit:]]*[.][[:digit:]]+[e][-]?[\\+]?[[:digit:]]+"); //.
		regex exp_dec2("[[:digit:]]+[.][[:digit:]]*[e][-]?[\\+]?[[:digit:]]+"); //9.e4

		if(regex_match(new_s,exp_dec) || regex_match(new_s,exp_dec2)){
			cout<<"exp dec| ";
			return true;

		}
        return false;

    
    
}


int main(){
		isNumber("e1")?cout<<"true\n":cout<<"false\n"; //false
		isNumber("1.e1")?cout<<"true\n":cout<<"false\n";  //true ** o/p:false(lc)
		isNumber(".2e1")?cout<<"true\n":cout<<"false\n";//true
		isNumber(".e1")?cout<<"true\n":cout<<"false\n";  //false **o/p cmd true





		// cout<<isNumber(" 0.1 ")<<"\n";
		// cout<<isNumber("abc")<<"\n";
		// cout<<isNumber("1 a")<<"\n";
		// cout<<isNumber("2e10")<<"\n";
		// cout<<isNumber(" -90e3   ")<<"\n"; 
		// cout<<isNumber(" 1e")<<"\n";
		// cout<<isNumber("e3")<<"\n";
		// cout<<isNumber(" 6e-1")<<"\n"; 
		// cout<<isNumber(" 99e2.5 ")<<"\n"; 
		// cout<<isNumber("53.5e93")<<"\n";  //checkthis
		// cout<<isNumber(" --6 ")<<"\n"; 
		// cout<<isNumber("-+3")<<"\n"; 
		// cout<<isNumber("95a54e53")<<"\n"; 




		


	

	return 0;
}