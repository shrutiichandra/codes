#include <vector>
#include <iostream>
using namespace std;
int maxProfit(int cost_per_cut, int metal_price, vector<int>& lengths) {

    	int maxLength = 0;
    	for (auto length : lengths) {
    		if (length > maxLength) {
    			maxLength = length;
    		}
    	}
    	
    	int maxProfit = 0;
    	
    	for (int i = 1; i < maxLength; i++) {
    		cout<<"i: "<<i<<" ";
    		int sumOfLengths = 0;
        	int sumOfCutCounts = 0;
        	int sumOfCutWastes = 0;
    		
    		for (int length : lengths) {
    			cout<<"length: "<<length<<" ";
        		sumOfLengths += length;
        		cout<<"sumOfLengths: "<<sumOfLengths<<" ";
        		if (length % i == 0) {
        			sumOfCutCounts += (length/i - 1);
        		} else {
        			sumOfCutCounts += (length/i);
        		}
        		
        		sumOfCutWastes += (length%i);
                cout<<"sumOfCutWastes: "<<sumOfCutWastes<<"\n";
        	}
    		
    		int profit = sumOfLengths*metal_price - sumOfCutCounts*cost_per_cut - sumOfCutWastes*metal_price;
    		
    		if (profit > maxProfit) {
    			maxProfit  = profit;
    		}
    	}
    	
    	return maxProfit;
    }

int main(){
    vector <int> n{26,103,59};

    cout<<maxProfit(1,10,n)<<"\n";
    return 0;
}
