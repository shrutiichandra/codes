// C++ program to find out maximum profit by 
// buying and selling a share atmost k times 
// given stock price of n days 
#include <climits> 
#include <iostream> 
using namespace std; 

// Function to find out maximum profit by buying 
// & selling a share atmost k times given stock 
// price of n days 
int maxProfit(int price[], int n, int k) 
{ 
	// table to store results of subproblems 
	// profit[t][i] stores maximum profit using 
	// atmost t transactions up to day i (including 
	// day i) 
	int profit[k + 1][n + 1]; 

	// For day 0, you can't earn money 
	// irrespective of how many times you trade 
	for (int i = 0; i <= k; i++) 
		profit[i][0] = 0; 

	// profit is 0 if we don't do any transation 
	// (i.e. k =0) 
	for (int j = 0; j <= n; j++) 
		profit[0][j] = 0; 

	// fill the table in bottom-up fashion 
	for (int i = 1; i <= k; i++) { 
		for (int j = 1; j < n; j++) { 
			int max_so_far = INT_MIN; 

			for (int m = 0; m < j; m++) {
			    cout<<"maxsof "<<max_so_far<<endl;
			    cout<<"another: "<<price[j] - price[m] + profit[i - 1][m]<<endl;
				max_so_far = max(max_so_far, 
								price[j] - price[m] + profit[i - 1][m]); 
			}
    
			profit[i][j] = max(profit[i][j - 1], max_so_far); 
			cout<<"profit[i][j] "<<profit[i][j]<<endl;
		} 
		cout<<"----------------------------"<<endl;
	} 
	
	for(int i=0;i<=k;i++){
	    for(int j=1;j<n;j++)
	        cout<<profit[i][j]<<" ";
	   cout<<endl;
	}

	return profit[k][n - 1]; 
} 

// Driver code 
int main() 
{ 
	int k = 2; 
	int price[] = { 3,2,6,5,0,3}; 
	int n = sizeof(price) / sizeof(price[0]); 

	cout << "Maximum profit is: "
		<< maxProfit(price, n, k); 

	return 0; 
} 
