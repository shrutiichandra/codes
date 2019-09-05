//g++ mergeSortedAr.cpp  -o mergeSortedAr
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
void print(vector<int>& v){
	for(auto i:v){
		cout<<i<<" ";
	}
	cout<<"\n";
}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

	//start from last element of nums2
	for(int i=n-1; i>=0; i--){
		cout<<"i: "<<i<<" ";
		int j; //iterator for nums1
		//store last element of nums1
		int last=nums1[m-1];
		cout<<"last: "<<last<<" ";
		//find the smallest greater element
		for(j = m-2; j>=0; j--){
			if(nums1[j]>=nums2[i]){
				cout<<"j: "<<j<<" ";
				nums1[j+1]=nums1[j]; //shift elements to right
				cout<<"temp nums1: ";
				print(nums1);
			}	
			else{
				break;
			}

		}

		if(j != m-2 || last>=nums2[i]){
			nums1[j+1]=nums2[i];
			nums1[m]=last;
			m++;
		}
		else{

			nums1[m]=nums2[i];
			m++;
		}
		cout<<"arrays: \n";
		print(nums1);

	}
}

int main(){
	vector <int> n{1,2,3,0,0,0};
	vector <int> m{2,5,6};
	cout<<"originally: \n";
	print(n);

	print(m);
	// cout<<"n.size: "<<n.size()<<" m.size: "<<m.size()<<"\n";
	int nsize=n.size();
	int msize=m.size();
	merge(n,3,m,3);
	cout<<"merge: \n";
	print(n);
	return 0;
}

