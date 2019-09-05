//g++ -o lpslps_my lps_my.cpp 
//./lpslps_my 
#include<string>
//Expand around center
//O(N^2)
#include <iostream>
# include <string>
/*
string substr (size_t pos, size_t len) const;
Parameters:
pos: Position of the first character to be copied.
len: Length of the sub-string.
size_t: It is an unsigned integral type.


*/
using namespace std;
    string substring(string s, int start, int end){
      int len = end - start + 1;
      return s.substr(start, len);
    }
    int expandAroundCenter(string s,int l,int r){
    	int left=l;
    	int right=r;
      cout << "+++ s: " << substring(s, left, right) << "\n";
    	while(left >= 0 && r < s.length() && s[left] == s[right]){
        cout << "---> left " << left << " right: " << right << " ";
        cout << "s: " << substring(s, left, right);
        cout<<" s[left]: "<< s[left]<<", s[right]: "<<s[right]<<"\n";
    		left--;
    		right++;
    	}
    	return right - left - 1;
    }
    string longestPalindrome(string s) {
  		//base condition
  		//s is null
  		if(s=="") return "";
  		string ans;
  		int start=0;
  		int end=0;
      cout << " string is : " << s << "\n";
  		for(int i=0;i<s.length();i++){
        cout << "start: " << start << " end: "<< end << "\n";
        cout << "\nexpandAroundCenter l = " << i << " r = " << i << "\n";
  			int len1=expandAroundCenter(s,i,i);
        cout << "** len1: " << len1 << "\nexpandAroundCenter l = " << i << " r = " << i +1 << "\n" ;

  			int len2=expandAroundCenter(s,i,i+1);
        cout<< "** len2: " << len2 << "\n";
  			int len=max(len1,len2);
        cout << "max (len1, len2) = " << len << " ; end - start: " << end - start;
  			if(len > end - start){
          cout << " len is greater\n";
  				start=i-(len-1)/2;
  				end=i+len/2;
          cout<<"start: "<<start<<", end: "<<end << "\n";
  			}
  		}

  		ans=s.substr(start,end+1);
  		return ans;
    }

int main(){
  string s="malayalam";

	// string s="abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa";
  // cout<<s.length()<<endl;
	cout<< "\n" << longestPalindrome(s)<<endl;
	return 0;
}