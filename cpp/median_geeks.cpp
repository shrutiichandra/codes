// A C++ program to find median of two sorted arrays of 
// unequal sizes 
#include <bits/stdc++.h> 
using namespace std; 

// A utility function to find median of two integers 
float MO2(int a, int b) 
{ return ( a + b ) / 2.0; } 

// A utility function to find median of three integers 
float MO3(int a, int b, int c) 
{ 
	return a + b + c - max(a, max(b, c)) 
					- min(a, min(b, c)); 
} 

// A utility function to find median of four integers 
float MO4(int a, int b, int c, int d) 
{ 
	int Max = max( a, max( b, max( c, d ) ) ); 
	int Min = min( a, min( b, min( c, d ) ) ); 
	return ( a + b + c + d - Max - Min ) / 2.0; 
} 

// Utility function to find median of single array 
float medianSingle(int arr[], int n) 
{ 
if (n == 0) 
	return -1; 
if (n%2 == 0) 
		return (double)(arr[n/2] + arr[n/2-1])/2; 
return arr[n/2]; 
} 

// This function assumes that N is smaller than or equal to M 
// This function returns -1 if both arrays are empty 
float findMedianUtil( int A[], int N, int B[], int M ) 
{ 
	cout<<"N: "<<N<<" M: "<<M<<endl;
	// If smaller array is empty, return median from second array 
	if (N == 0) 
	return medianSingle(B, M); 

	// If the smaller array has only one element 
	if (N == 1) 
	{ 
		cout<<" Case 1: If the larger array also has one element\n";
		// simply call MO2() 
		if (M == 1) 
			return MO2(A[0], B[0]); 

		cout<<" Case 2: If the larger array has odd number of elements\n";
		// then consider the middle 3 elements of larger array and 
		// the only element of smaller array. Take few examples 
		// like following 
		// A = {9}, B[] = {5, 8, 10, 20, 30} and 
		// A[] = {1}, B[] = {5, 8, 10, 20, 30} 
		if (M & 1) 
			return MO2( B[M/2], MO3(A[0], B[M/2 - 1], B[M/2 + 1]) ); 

		cout<<"Case 3: If the larger array has even number of element\n";
		// then median will be one of the following 3 elements 
		// ... The middle two elements of larger array 
		// ... The only element of smaller array 
		return MO3( B[M/2], B[M/2 - 1], A[0] ); 
	} 

	
	else if (N == 2) 
	{ cout<<"If the smaller array has two elements \n";
		cout<<" Case 4: If the larger array also has two elements\n";
		// simply call MO4() 
		if (M == 2) 
			return MO4(A[0], A[1], B[0], B[1]); 

		cout<<" Case 5: If the larger array has odd number of elements\n";
		// then median will be one of the following 3 elements 
		// 1. Middle element of larger array 
		// 2. Max of first element of smaller array and element 
		// just before the middle in bigger array 
		// 3. Min of second element of smaller array and element 
		// just after the middle in bigger array 
		if (M & 1) 
			return MO3 ( B[M/2], 
						max(A[0], B[M/2 - 1]), 
						min(A[1], B[M/2 + 1]) 
					); 

		cout<<"Case 6: If the larger array has even number of elements\n";
		// then median will be one of the following 4 elements 
		// 1) & 2) The middle two elements of larger array 
		// 3) Max of first element of smaller array and element 
		// just before the first middle element in bigger array 
		// 4. Min of second element of smaller array and element 
		// just after the second middle in bigger array 
		return MO4 ( B[M/2], 
					B[M/2 - 1], 
					max( A[0], B[M/2 - 2] ), 
					min( A[1], B[M/2 + 1] ) 
				); 
	} 

	int idxA = ( N - 1 ) / 2; 
	int idxB = ( M - 1 ) / 2; 

	cout<<"if A[idxA] <= B[idxB], then median must exist in A[idxA....] and B[....idxB]\n";
	if (A[idxA] <= B[idxB] ) 
	return findMedianUtil(A + idxA, N/2 + 1, B, M - idxA ); 

	cout<<" if A[idxA] > B[idxB], then median must exist in A[...idxA] and B[idxB....] \n";
	return findMedianUtil(A, N/2 + 1, B + idxA, M - idxA ); 
} 

// A wrapper function around findMedianUtil(). This function 
// makes sure that smaller array is passed as first argument 
// to findMedianUtil 
float findMedian( int A[], int N, int B[], int M ) 
{ 
	if (N > M) 
	return findMedianUtil( B, M, A, N ); 

	return findMedianUtil( A, N, B, M ); 
} 

// Driver program to test above functions 
int main() 
{ 
	int A[] = {4,5,6,7,8}; 
	int B[] = {1,2,3}; 

	int N = sizeof(A) / sizeof(A[0]); 
	int M = sizeof(B) / sizeof(B[0]); 

	printf("%f", findMedian( A, N, B, M ) ); 
	return 0; 
} 
