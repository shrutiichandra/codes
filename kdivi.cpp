//g++ -o kdivi kdivi.cpp
//ques??
#include <cmath>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void check(int* a,int len,int n){
    queue <int> que;
    if(len==1){
        if(a[0]==n){
            cout<<"YES"<<endl;
            return;
        }
        cout<<"NO"<<endl;
        return;
    }
    cout<<"push a[0]: "<<a[0]<<endl;
    que.push(a[0]);
    int exp1,exp2;
    int head=que.front();

    for(int i=1;i<n;i++){
         int k=pow(2,i-1);
       cout<<"before while k: "<<k<<" ";
        while(k--){
            cout<<"k: "<<k<<" ";
                head=que.front();
                cout<<"i: "<<i<<endl;
                exp1=a[i]+head;
                exp2=head-a[i];
                cout<<"push: "<<exp1<<" ";
                que.push(exp1);
                cout<<"push: "<<exp2<<endl;
                que.push(exp2);
                cout<<"pop: "<<head<<endl;
                que.pop();
             //   k=k*2;
          //      k=k/2;
            }

    }

    while(!que.empty()){
        cout<<que.front()<<" ";
        que.pop();
    }
    
}
int main() {
    int testcase=1;
   // cin>>testcase;
    int arr_num=4;
    int arr[10000]={1,2,3,4,5,6,7,8,9,0,11,12,13,14,15,16,17,18,19,20,21,22,23,23,25,26,27,28};
    int k=5;
   /* while(testcase--){
        cin>>arr_num;
        cin>>k;
        for(int i=0;i<arr_num;i++)
            cin>>arr[i];*/
       check(arr,arr_num,k);
        
  //  }

    //cout<<log2(5)<<endl;
    return 0;
}

