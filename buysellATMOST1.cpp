//  g++ buysellATMOST1.cpp -o buysellATMOST1
#include <vector>
#include <iostream>

using namespace std;
int maxProfit(vector<int>& prices) {
 	int profit=0;
 	int minValley=9999999;
 	
 	for(int i=0; i<prices.size(); i++){
 		if(prices[i]<minValley){
 			//find the least price
 			minValley=prices[i];
 		}
 		
 		else if(prices[i]-minValley>profit){
 			//find the max price after that
 			profit=prices[i]-minValley;
 			
 		}

 	}

 	return profit;
}

int main(){
	vector <int> v{7,1,5,3,6,4};
	cout<<"prices are: ";
	for(auto i:v) cout<<i<<" ";
	cout<<"\n";
	cout<<"maximum profit, with AT most 1 transacn is: "<<maxProfit(v)<<"\n";

	return 0;
}