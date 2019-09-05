//  g++ buysellINf.cpp -o buysellINF
#include <vector>
#include <iostream>

using namespace std;
int maxProfit(vector<int>& prices) {
 	int profit=0;
 	int n=prices.size();

 	for(int i=0; i<n-1; i++){
 		if(prices[i]<prices[i+1]){
 			//if price on day i, is less than that on next day, make a profit
 			profit=profit+(prices[i+1]-prices[i]);
 		}

 	}

 	return profit;
}

int main(){
	vector <int> v{1,2,3,4,5};
	cout<<"prices are: ";
	for(auto i:v) cout<<i<<" ";
	cout<<"\n";
	cout<<"maximum profit, with AS many transacns is: "<<maxProfit(v)<<"\n";

	return 0;
}