#include<iostream>
using namespace std;
unsigned factTR(unsigned int n, unsigned int a)
{
    if (n == 0)  return a;
 
    return factTR(n-1, n*a);
}
 
// A wrapper over factTR
unsigned int fact(unsigned int n)
{
   return factTR(n, 1);
}
 
// Driver program to test above function
int main()
{
    cout << fact(5)<<endl;
    return 0;
}