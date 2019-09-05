//g++ -o minswaps minswaps.cpp
//geeks! do this yourself
// C++ program to find minimum number of swaps required so that
// all pairs become adjacent.
#include<bits/stdc++.h>
using namespace std;
 
// This function updates indexes of elements 'a' and 'b'
void updateindex(int index[], int a, int ai, int b, int bi)
{
    index[a] = ai;
    index[b] = bi;
}
int minSwapsUtil(int arr[],int pairs[],int index[],int i,int n)
{
    if (i > n) return 0;
 
    if (pairs[arr[i]] == arr[i+1])
         return minSwapsUtil(arr,pairs,index,i+2,n);
 
    int one = arr[i+1];
    int indextwo = i+1;
    int indexone = index[pairs[arr[i]]];
    int two = arr[index[pairs[arr[i]]]];
    swap(arr[i+1], arr[indexone]);
    updateindex(index, one, indexone, two, indextwo);
    int a = minSwapsUtil(arr, pairs, index, i+2, n);
 
    swap(arr[i+1], arr[indexone]);
    updateindex(index, one, indextwo, two, indexone);
    one = arr[i], indexone = index[pairs[arr[i+1]]];
 
    two = arr[index[pairs[arr[i+1]]]], indextwo = i;
    swap(arr[i], arr[indexone]);
    updateindex(index, one, indexone, two, indextwo);
    int b = minSwapsUtil(arr, pairs, index, i+2, n);
 
    // Backtrack to previous configuration.  Also restore
    // the previous indices, of one and two
    swap(arr[i], arr[indexone]);
    updateindex(index, one, indextwo, two, indexone);
 
    // Return minimum of two cases
    return 1 + min(a, b);
}
 
// Returns minimum swaps required

int minSwaps(int n,int pairs[],int arr[])
{
    int index[2*n]; 
    for (int i=0;i<2*n;i++)
        index[arr[i]] = i;

    return minSwapsUtil(arr,pairs,index,0,2*n);
}
 
int main(){
    int arr[]={1,8,0,7,6,3,9,4,5,2};
    int pairs[] = {1,0,3,2,5,4,7,6,9,8};
    int m=sizeof(arr)/sizeof(arr[0]);
 
    int n=m/2;  
 
    cout << "Min swaps required is " << minSwaps(n,pairs,arr);
    return 0;
}