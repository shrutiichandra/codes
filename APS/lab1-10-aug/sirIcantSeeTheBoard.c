/*
https://www.hackerrank.com/contests/aps-2018-lab-1/challenges/sir-i-cant-see-the-board
APS class is going on and N students are sitting in the class room. Although this is a weird class room where there is only 1 column and N number of rows. Because of this weird arrangement, not everyone is able to see the board. A student is able to see the board only if his/her height is more than each of the student sitting in front of him/her. You need to tell whether a student is able to see the board.

Input Format

First row contains an integer N

Next row contains N space separated integers denoting the height of the students.

Student at 0th index is sitting at last position and student at last index is sitting at front.

Constraints

1
N

10^6

1
Height

10^18

Output Format

N space separted values. 0 if student is not able to see the board and 1 if student is able to see the board.

First value represent student sitting at the back and last value represent student sitting the front.

Sample Input 0

10
98 7 82 13 25 83 88 11 39 22 

Sample Output 0

1 0 0 0 0 0 1 0 1 1 

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
void solve(long long int* arr,int size){
    long long int maximum=arr[size-1];
    long long int leaders[size];
    int i,j;
    leaders[size-1]=arr[size-1];
    
    for(i=size-2;i>=0;i--){
        if(arr[i]>maximum){
            maximum=arr[i];
            leaders[i]=maximum;
         }
        else leaders[i]=leaders[i+1];
    }
   
    for(i=0;i<size-1;i++){
        if(arr[i]==leaders[i]) cout<<"1 ";
        else cout<<"0 ";
    }
    cout<<"1 ";
}
int main() {  
   int n; //10^6
   cin>>n; //students
   long long int height[n];
    
    for(int i=0;i<n;i++)
        cin>>height[i];
    solve(height,n);
    return 0;
}