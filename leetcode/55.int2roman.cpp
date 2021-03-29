// https://leetcode.com/problems/integer-to-roman/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string int2roman(int num){
	string ans;
	if(num<=0){
		return "";
	}
	unordered_map<int,string> symb_val{ {1,"I"},
										{4,"IV"},
										{5,"V"},
										{9,"IX"},
										{10,"X"},
										{40,"XL"},
										{50,"L"},
										{90,"XC"},
										{100,"C"},
										{400,"CD"},
										{500,"D"},
										{900,"CM"},
										{1000,"M"}
										};

	for(auto i=symb_val.begin();i!=symb_val.end();i++){
		if(i->first==num){
			ans=i->second;
			return ans;
		}
	}
	while(num!=0){
		if(num>=1000){
				ans+=symb_val[1000];
				num-=1000;
		}
		else if(num>=500){
			if(num>=900){
				ans+=symb_val[900];
				num-=900;
			}
			else if(num<900){
				ans+=symb_val[500];
				num-=500;
			}

		}
		else if(num>=100){
			cout<<"num>100: num: "<<num<<"\n";
			if(num>=400){
				ans+=symb_val[400];
				num-=400;
			}
			else if(num<400){
				ans+=symb_val[100];
				num-=100;
			}

		}
		else if(num>=50){
			cout<<"num>50: num: "<<num<<"\n";
			if(num>=90){
				ans+=symb_val[90];
				num-=90;
			}
			else if(num<90){
				ans+=symb_val[50];
				num-=50;
			}
		}
		else if(num>=10){
			cout<<"num>10: num: "<<num<<"\n";
			if(num>=40){
				ans+=symb_val[40];
				num-=40;
			}
			else if(num<40){
				ans+=symb_val[10];
				num-=10;
			}
		}
		else if(num>=5){
			// cout<<"num>5: num: "<<num<<"\n";
			if(num>=9){
				ans+=symb_val[9];
				num-=9;
			}
			else if(num<9){
				ans+=symb_val[5];
				num-=5;
			}
		}
		else if(num>=1){
			// cout<<"num>1: num: "<<num<<"\n";
			
			if(num>=4){
				// cout<<"greater than equal to 4\n";
				ans+=symb_val[4];
				num-=4;
			}
			else if(num<4){
				// cout<<"less 4\n";
				ans+=symb_val[1];
				num-=1;
			}
		}
	}
	return ans;
}

int main(){
	
		cout<<"	"<<int2roman(1210)<<"\n";	
		// cout<<"MCMXCIV	"<<int2roman(1994)<<"\n";	
		// cout<<"CL	"<<int2roman(150)<<"\n";	

			
	return 0;
}