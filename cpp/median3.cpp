#include<iostream>
using namespace std;

double median_3(int a,int b,int c){
        double median;
        
        if(a>b){
            if(a>c){
                if(b>c){
                    median=b;
                }
                else{
                    median=c;
                }
            }
            else{
                median=a;
            }
        }
        else{
            if(b>c){
                if(a>c){
                    median=a;
                }
                else{
                    median=c;
                }
            }
            else{
                median=b;
            }
        }
        
        return median;
}

int main(){
    cout<<median_3(8,8,8)<<endl;

    cout<<median_3(1,8,9)<<endl;
    cout<<median_3(8,9,1)<<endl;
    cout<<median_3(1,9,8)<<endl;
    cout<<median_3(8,1,9)<<endl;
    cout<<median_3(9,1,8)<<endl;
    cout<<median_3(9,8,1)<<endl;
    return 0;
}
