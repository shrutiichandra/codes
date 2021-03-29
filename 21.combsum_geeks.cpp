// C++ program to find all combinations that 
// sum to a given value 
// https://www.geeksforgeeks.org/combinational-sum/
#include <bits/stdc++.h> 
using namespace std; 
void print(vector<int>& r){
	for(auto i:r)
		cout<<i<<" ";
	cout<<".";
}
// Print all members of ar[] that have given 
void findNumbers(vector<int>& ar, int sum, 
				vector<vector<int> >& res, 
				vector<int>& r, int i) 
{ 
    cout<<"sum: "<<sum<<" i: "<<i<<"\n";
	// If current sum becomes negative 
	if (sum < 0) {
	    // cout<<"---returning findNumbers--\n";
    	return; 
	}

	// if we get exact answer 
	if (sum == 0) 
	{ 
	    // cout<<"exact ";
	    // print(r);
	    // cout<<"\n";
		res.push_back(r); 

		// cout<<"---returning findNumbers-- sum: "<<sum<<" i: "<<i<<"\n";
		return; 
	} 

	// Recur for all remaining elements that 
	// have value smaller than sum. 
	while (i < ar.size() && sum - ar[i] >= 0) 
	{ 	
		// cout<<"------------------------start of while-------------------------------\n";
  //       cout<<"i: "<<i<<", ar[i]: "<<ar[i]<<", sum: "<<sum<<", sum-ar[i]: "<<sum-ar[i]<<", ";
		// Till every element in the array starting 
		// from i which can contribute to the sum 
		// cout<<"push "<<ar[i]<<"\n";
		r.push_back(ar[i]); // add them to list 

		// recur for next numbers 
		// cout<<"--------recur for next number -------\n";
		findNumbers(ar, sum - ar[i], res, r, i); 

        // cout<<"return after recur ---------\n i: "<<i<<", ar[i]: "<<ar[i]<<", sum: "<<sum<<", sum-ar[i]: "<<sum-ar[i]<<", vector now: ";
        // print(r);
        // cout<<"\n";
		i++; 
		// cout<<"increment i: "<<i<<"\n";
		// remove number from list (backtracking) 
		r.pop_back(); 
		// cout<<"after pop_back: ";
		// print(r);
		// cout<<"\n";
		// cout<<"-----------end of while-------------\n";

	} 

} 

// Returns all combinations of ar[] that have given 
// sum. 
vector<vector<int> > combinationSum(vector<int>& ar, 
											int sum) 
{ 
	// sort input array 
	sort(ar.begin(), ar.end()); 

	// remove duplicates 
	ar.erase(unique(ar.begin(), ar.end()), ar.end()); 

	vector<int> r; 
	vector<vector<int> > res; 
	// cout<<"--calling findNumbers sum: "<<sum<<"\n";
	findNumbers(ar, sum, res, r, 0); 
	// cout<<"---returning main---\n";

	return res; 
} 

// Driver code 
int main() 
{ 
	vector<int> ar; 
	ar.push_back(2); 
	ar.push_back(4); 
	ar.push_back(6); 
	ar.push_back(8); 
	int n = ar.size(); 

	int sum = 8; // set value of sum 
	vector<vector<int> > res = combinationSum(ar, sum); 

	// If result is empty, then 
	if (res.size() == 0) 
	{ 
		cout << "Emptyn"; 
		return 0; 
	} 

	// Print all combinations stored in res. 
	for (int i = 0; i < res.size(); i++) 
	{ 
		if (res[i].size() > 0) 
		{ 
			cout << " ( "; 
			for (int j = 0; j < res[i].size(); j++) 
				cout << res[i][j] << " "; 
			cout << ")"; 
		} 
	} 
} 
