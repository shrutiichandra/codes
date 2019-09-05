#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

string multiply(string num1,string num2){
    string product;

    int len1=num1.size()-1;
    int len2=num2.size()-1;

    vector<int> res(len1+len2+1,0); 

    int res_idx_1=0;
    int res_idx_2=0;

    for(int i=len1;i>=0;i--){
        int carry=0;
        int multiplier=num1[i]-'0';
        res_idx_2=0;

        for(int j=len2;j>=0;j--){
            int multiplicand=num2[j]-'0';
            int idx=res_idx_2+res_idx_1;
            cout<<"multiplicand "<<multiplicand<<" multiplier "<<multiplier<<" idx "<<idx<<" at res "<<res[idx]<<" carry "<<carry<<"\n";
            int sum=multiplicand*multiplier + res[idx] + carry;

            carry=sum/10;

            res[idx]=sum%10;

            res_idx_2++;
        }
        if(carry>0){
            int new_idx=res_idx_2+res_idx_1;
            cout<<"new_idx : "<<new_idx<<" ";
            res[new_idx]+=carry;
            cout<<"at res "<<res[new_idx]<<"\n";
        }

        res_idx_1++;
    }

    int pr_len=res.size()-1;

    while(pr_len>=0 && res[pr_len]==0){
        pr_len--;
    }

    if(pr_len==-1){
        return "0";
    }
    cout<<"in vector: ";
    for(auto i:res){
        cout<<i;
    }
    cout<<"\n";

    while(pr_len>=0){
        product+=to_string(res[pr_len--]);
    }

    cout<<"product: "<<product<<"\n";
    return product;

}
int main(){
    cout<<multiply("6913259244","71103343")<<"\n";

}