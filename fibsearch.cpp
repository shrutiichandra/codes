//g++ -std=c++11 -o fibsearch fibsearch.cpp 
//wrong answer
#include <iostream>
#include <vector>
using namespace std;
int fibSearch(vector <int>& v, int key){
	int size=v.size();

	int f2=0,f1=1;
	int f3=f1+f2;

	while(f3<size){
		f2=f1;
		f1=f3;
		f3=f1+f2;

	}
	int offset=-1;
	
	while(f3>1) {
		int index=min(offset+f2,size-1);
		//if(v[index]==key) return true;

		if(v[index]<key){
			//after index
			f3=f1;
			f1=f2;
			f2=f3-f1;
			offset=index;
		}
		else if(v[index]>key){
			//before index
			f3=f2;
			f1=f1-f2;
			f2=f3-f1;
		}
		else return index;
	}

	if(f1)
		if(v[offset+1]==key)
			return offset+1;
	return -1;

}
int main(){

	vector <int> v{1,4,3,2};

	cout<<"==search==\n";

	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" : "<<fibSearch(v,v[i])<<"\n";
	}
}