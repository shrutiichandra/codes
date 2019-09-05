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
 
    for( j=0,i=0;j<n,i!=list.size();j++,i++){
      count[j]=0; 

       while(i<list.size()-1&&list[i]==list[i+1]){
            count[j]=count[j]+1;
            i++;
      }
    }

    tot=j;
   max=count[0];
   for(i=1;i<tot;i++){
       if(count[i]>max)
           max=count[i];
   }
   cout<<max+1;
    
    return 0;
}
