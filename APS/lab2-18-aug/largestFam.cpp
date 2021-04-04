/*
Ravi has a dream to be a King. One of the rule in his kingdom will be that for a couple to name their kids they have to choose only from certain number of alphabets. So, if a couple choose a,b and c alphabets their children's names can be abc,acb,cab,etc. These sets of alphabets are unique for every couple. You being a minister in Ravi's ministry has the task to find out the size of largest family in kingdom.

Input Format

First line contains N i.e. Number of children in kingdom.

Second line contains N space separated strings denoting name of child.

(Only lower case letters are used to form names)

Constraints

1<= N <= 10000000

length of name <= 100

Output Format

Single integer denoting size of largest family.

Sample Input 0

5
abc
cab
pqr
xyz
rst

Sample Output 0

2

Explanation 0

abc and cab belongs to same family.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;


int main() {

    int n;//10^7
    cin>>n;
    
    string name;
    int tot,i,j,max;
    vector<string> list;
    vector<string>::iterator it;
    int count[MAX]={0};
 
    for(int i=0;i<n;i++){
        cin>>name;
        sort(name.begin(),name.end());
        list.push_back(name);
    }
    
    sort(list.begin(),list.end());
  
  //  for(int i=0;i!=list.size();i++){
    //    cout<<"i "<<i<<" ";
        for( j=0,i=0;j<n,i!=list.size();j++,i++){
         //   cout<<"j: "<<j<<" i: "<<i<<endl;
            count[j]=0; 
          //  cout<<list[i]<<" "<<list[i+1]<<endl;
            while(i<list.size()-1&&list[i]==list[i+1]){
             //   cout<<"inside while"<<endl;
                count[j]=count[j]+1;
                i++;
            }
         //   cout<<"new i: "<<i<<endl;
        }
    //}
  tot=j;
    //cout<<j;
    
    
        max=count[0];
        for(i=1;i<tot;i++){
            if(count[i]>max)
                max=count[i];
        }
    cout<<max+1;
    
    return 0;
}