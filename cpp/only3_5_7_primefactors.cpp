//g++ -o only3_5_7_primefactors only3_5_7_primefactors.cpp 
//./only3_5_7_primefactors 
//Find the first k numbers that have only 3,5,7 as their prime factors.

# include <iostream>
# include <algorithm>
using namespace std; 


unsigned* firstK(unsigned* arr, unsigned n) 
{ 
	
	unsigned i7 = 0, i3 = 0, i5 = 0; 
	unsigned next_multiple_of_3 = 3; 
	unsigned next_multiple_of_5 = 5; 
	unsigned next_multiple_of_7 = 7; 
	unsigned next_no; 

	arr[0] = 1; 
	for (int i=1; i<n; i++) 
	{ 
		next_no = min(next_multiple_of_3, 
							min(next_multiple_of_5, 
								next_multiple_of_7)); 
		arr[i] = next_no; 
		if (next_no == next_multiple_of_3) 
		{ 
			i3 = i3+1; 
			next_multiple_of_3 = arr[i3]*3; 
		} 
		if (next_no == next_multiple_of_5) 
		{ 
			i5 = i5+1; 
			next_multiple_of_5 = arr[i5]*5; 
		} 
		if (next_no == next_multiple_of_7) 
		{ 
			i7 = i7+1; 
			next_multiple_of_7 = arr[i7]*7; 
		} 
	} 
	
	
} 


int main() 
{ 
	int n = 20; 
	cout << "The first " << n << " numbers that have only 3,5,7 as their prime factors:\n";

	unsigned arr[n];
	firstK(arr, n); 
	
	for (int i = 1 ; i < n ; i++ ){
		cout << arr[i] << " ";
	}
	cout << "\n";
	return 0; 
} 
