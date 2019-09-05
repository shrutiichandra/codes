//g++ grayCode.cpp -o grayCode
#include <vector>
#include <iostream>

using namespace std;
void print(vector<int> v){
	for(auto i:v){
		cout<<i<<" ";
	}
	cout<<"\n";
}
vector<int> grayCode(int n) {
    vector<int> v;

    vector <string> codes;

    //1bit graycode:
    codes.push_back("0");
    codes.push_back("1");

    int bits;
    int i;
    for(bits=2; bits < (1<<n); bits= bits<<1){
    	//add mirror image of current codes array
    	for(i=bits-1;i>=0;i--){
    		codes.push_back(codes[i]);
    	}

    	//add 0 to 1st half
    	for(i=0; i<bits; i++){
    		codes[i]="0"+codes[i];
    	}

    	for(i=bits; i<2*bits;i++){
    		codes[i]="1"+codes[i];
    	}
    }

    for(auto c:codes){
     int graycode=stoull(c, 0, 2);
     v.push_back(graycode);
    }
    
    return v;
}

int main(){
	vector<int> v;
	v=grayCode(2);
	print(v);
	return 0;
}

