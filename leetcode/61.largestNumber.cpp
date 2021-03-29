//https://leetcode.com/problems/largest-number/
#include <iostream>
#include <vector>
// maynot work
#include "common_utils.h"

using namespace std;
class Solution {
public:
    static bool compare(string a, string b) {
        //comparison code here
        

        string a1 = a+b;
        string a2 = b+a;
        if( a1 > a2)
            return true;
        
        return false;      
     }

    string largestNumber(vector<int>& nums) {
        int len=nums.size();
        string ans="";

        vector <string> s;
        for(auto i: nums){
        	s.push_back(to_string(i));
        }
        sort(s.begin(), s.end(),compare);

        for(auto i:s){
        	ans += i;
        }
        cout<<"\n";


        return ans;
    }
};

int main(){
	vector <int> n{3,30,34,5,9};
	string s;
	Solution obj;
	s=obj.largestNumber(n);
	cout<<"vector: ";
	printVector(n);
	cout<<"ans: "<<s<<"\n";
	return 0;
}