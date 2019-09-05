//g++ colName2No.cpp -o colName2No
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    int titleToNumber(string s) {
    	int len=s.size();
    	int col_no=0;
    	
    
    	for(int i=0; i<len; i++){
    		col_no = col_no * 26;
    		col_no = col_no + s[i] - 'A' + 1;
    	}
        

        return col_no;
    }
};

int main(){
	int col_no;
	string name;
	Solution s;
	name="AA";
	col_no=s.titleToNumber(name);
	cout<<"col name: "<<name<<", ";
	cout<<"col no: "<<col_no<<"\n";

	return 0;
}