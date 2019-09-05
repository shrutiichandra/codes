#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    string dna;
    getline(cin,dna);
    vector<string> substrings;
    int i,j,tot,len;
    len=dna.length()-10;
    int count[len]={0};
    
    for(int i=0;i<len;i++)
        substrings.push_back(dna.substr(i,10));
    
    sort(substrings.begin(),substrings.end());
   
 /*   for(auto i:substrings)
        cout<<i<<endl;
   */ 
     for( j=0,i=0;j<len,i!=len;j++,i++){

          while(i<len-1&&substrings[i]==substrings[i+1]){
             count[j]=count[j]+1;
             i++;
          }
    }
    tot=j;
    
    for(i=0;i<tot;i++)
        if(count[i]>0){
            cout<<substrings[i+1]<<" ";
        }
    
    return 0;
}

