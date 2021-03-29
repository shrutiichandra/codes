//g++ canComplete.cpp
// https://leetcode.com/problems/gas-station/
#include <vector>
#include <iostream>
#include <algorithm>
	
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	int stations=gas.size();
    	int idx=-1;
    	int tank=0;
    	int rem=0;
    	int prev;
    	for(int i=0; i<stations; i++){
    		cout<<"station: "<<i<<" ";
    		tank=gas[i];
    		cout<<"tank: "<<tank<<"\n";
    		prev=i;

    		for(int j=(i+1)%stations; j<stations; j=(j+1)%stations){
    			cout<<"j: "<<j<<" i: "<<i<<"\n";
    			if(j==i){
    				cout<<"tank: "<<tank<<"\n";
    				cout<<"cost: "<<cost[prev]<<"\n";
    				if(tank-cost[prev]>=0){
    					idx=i;
    					return idx;
    				}
    			}

    			cout<<"prev: "<<prev<<" ";
    			rem=tank-cost[prev];
    			cout<<"rem: "<<rem<<" ";
    			if(rem<=0){
    				cout<<"break\n";
    				break;
    			}

    			tank=rem+gas[j];
    			cout<<"new tank: "<<tank<<"\n";
    			prev=j;
    		}
    	}



    	return idx;
    }
};

void print(vector <int> v){
	for(auto i:v)
		cout<<i<<" ";
	cout<<"\n";
}
int main(){
	vector<int> g{1,2,3,4,5};
	vector<int> c{3,4,5,1,2};

	cout<<"gas: ";
	print(g);
	cout<<"cost: ";
	print(c);
	Solution obj;
	cout<<"start from index: "<<obj.canCompleteCircuit(g,c)<<"\n";
	cout<<"\n";

	return 0;
}