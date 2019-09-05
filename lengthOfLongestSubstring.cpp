//g++ -std=c++11 -o lols lengthOfLongestSubstring.cpp 
#include <string>
#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s) {
        string temp;
        int temp_count;
        int max=-999;
        int flag=0;
        if(s.length()==1){
            return 1;
        }
        for(int i=0;i<s.length()-1;i++){
            temp_count=0;
            temp="";
            temp+=s[i];
            // cout<<"temp: "<<temp<<"\n";
            temp_count=temp.length();
            for(int j=i+1;j<s.length();j++){
                if(temp.find(s[j]) != std::string::npos){
                    // cout<<temp<<"\n";
                    break;
                }   
                else{
                    temp+=s[j];
                    // cout<<temp<<" ";
                    temp_count=temp.length();    
                    // cout<<temp_count<<"\n";
                    if(max<temp_count){
                        flag=1;
                        max=temp_count;
                    }               
                }
            }
            
        }
        // cout<<temp<<"\n";
        if(!flag) max=temp_count;
        return max;
    }

    int main(){
    	cout<<"enter testcases: ";
    	int n;
    	cin>>n;
    	while(n--){
    		string s;
    		cout<<"\nenter string s: ";
    		cin>>s;
    		cout<<lengthOfLongestSubstring(s)<<"\n";

    	}
    	return 0;

    }