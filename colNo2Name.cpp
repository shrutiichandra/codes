//g++ colNo2Name.cpp -o colNo2Name
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    string convertToTitle(int n) {
        // cout<<int('A')<<", "<<int('Z')<<"\n";
        int rem;
        int quo;
        string ans="";
        rem = n;
        
        while(rem!=0){
        	quo = rem/26;
        	rem = rem % 26;

        	if(rem==0){
	        	// char name = char(rem+64);
				ans += 'Z';
				quo --;
			}

			else{
				char name = char(rem+64);
				ans += name;
			}
			rem = quo;

        }
        reverse (ans.begin(), ans.end());
        return ans;
    }
};

int main(){
	int col_no;
	string name;
	Solution s;
	col_no=26;
	cout<<"col no: "<<col_no<<", ";
	name=s.convertToTitle(col_no);
	cout<<"col name: "<<name<<"\n";

	col_no=51;
	cout<<"col no: "<<col_no<<", ";
	name=s.convertToTitle(col_no);
	cout<<"col name: "<<name<<"\n";
	
	col_no=52;
	cout<<"col no: "<<col_no<<", ";
	name=s.convertToTitle(col_no);
	cout<<"col name: "<<name<<"\n";

	col_no=80;
	cout<<"col no: "<<col_no<<", ";
	name=s.convertToTitle(col_no);
	cout<<"col name: "<<name<<"\n";

	col_no=676;
	cout<<"col no: "<<col_no<<", ";
	name=s.convertToTitle(col_no);
	cout<<"col name: "<<name<<"\n";

	col_no=702;
	cout<<"col no: "<<col_no<<", ";
	name=s.convertToTitle(col_no);
	cout<<"col name: "<<name<<"\n";

	col_no=705;
	cout<<"col no: "<<col_no<<", ";
	name=s.convertToTitle(col_no);
	cout<<"col name: "<<name<<"\n";
	return 0;
}