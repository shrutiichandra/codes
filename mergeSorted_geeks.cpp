//g++ mergeSorted_geeks.cpp -o mergeSorted_geeks
// C++ program to merge two sorted arrays with O(1) extra space. 
#include <bits/stdc++.h> 
using namespace std; 
void print(int ar[],int m){
    
    for(int i=0;i<m;i++)
        cout<<ar[i]<<" ";
    cout<<"\n";
}
// Merge ar1[] and ar2[] with O(1) extra space 
void merge(int ar1[], int ar2[], int m, int n) 
{   
    // Iterate through all elements of ar2[] starting from 
    // the last element 
    for (int i=n-1; i>=0; i--) 
    {   
        cout<<"i: "<<i<<" ";
        /* Find the smallest element greater than ar2[i]. Move all 
        elements one position ahead till the smallest greater 
        element is not found */
        int j, last = ar1[m-1]; 
        for (j=m-2; j >= 0 ; j--) {
            if(ar1[j] > ar2[i]){
                ar1[j+1] = ar1[j]; 
                cout<<"j: "<<j<<" ";
            }
            else{
                cout<<"break ";
                break;
            }
        }

        // If there was a greater element 
        if (j != m-2 || last > ar2[i]) 
        { 
            ar1[j+1] = ar2[i]; 
            ar2[i] = last; 
        } 
        cout<<"arrays: \n";
        print(ar1,m);
        print(ar2,n);
    } 
} 

// Driver program 
int main(void) 
{ 
    int ar1[] = {1, 2,3}; 
    int ar2[] = {2, 5,6}; 
    int m = sizeof(ar1)/sizeof(ar1[0]); 
    int n = sizeof(ar2)/sizeof(ar2[0]); 
    cout<<"originally: \n";
    print(ar1,m);
    print(ar2,n);
    merge(ar1, ar2, m, n); 

    // cout << "After Merging nFirst Array: "; 
    // for (int i=0; i<m; i++) 
    //     cout << ar1[i] << " "; 
    // cout << "nSecond Array: "; 
    // for (int i=0; i<n; i++) 
    //     cout << ar2[i] << " "; 
    cout<<"after merge: \n";
    print(ar1,m);
    print(ar2,n);
return 0; 
} 
