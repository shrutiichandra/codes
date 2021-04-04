#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <time.h> 
using namespace std;

int partition(int* a,int l,int r,int num){
	//select pivot
	int pivot=a[r];
	int index=l-1;
	for(int i=l;i<r;i++){
	//	cout<<"a["<<i<<"] "<<a[i]<<" pivot:"<<pivot<<endl;
		if(a[i]<=pivot){
			
	//		cout<<"a[i]<=pivot"<<endl;
			index++;
	//		cout<<"a[i]: "<<a[i]<<" a[index] "<<a[index]<<endl;
			swap(a[i],a[index]);
	//		cout<<"a[i]: "<<a[i]<<" a[index] "<<a[index]<<endl;
		}
	}
	//cout<<"a[index+1]: "<<a[index+1]<<" a[r] "<<a[r]<<endl;
	swap(a[index+1],a[r]);
	//cout<<"a[index+1]: "<<a[index+1]<<" a[r] "<<a[r]<<endl;
	//cout<<"in partition"<<endl;
	//	print(a,num);
	return index+1;
}

// int randomized(int* a,int l,int r,int s){
// 	//cout<<"size: "<<s<<endl;
	
// 	//cout<<"random-index "<<random_index<<endl;
	
// 	return partition(a,l,r,s);
// 	//return 0;
// }


int selectNth(int* a, int l,int r,int k,int num){

	if(l==r)
		return a[l];
	else{
		//int index=randomized(a,l,r,num);
		int index=rand()%(r-l+1);
		swap(a[r],a[l+index]);
			//cout<<"Array select nth"<<endl;
			
		
		if((k-1)==index){
			//cout<<"in if1"<<endl;
			
			return a[index];
		}
		else if((k-1)>index){
			//cout<<"in if2"<<endl;
			
			selectNth(a,index+1,r,k,num);
		}
		else if((k-1)<index){
			selectNth(a,l,index-1,k,num);
		}
	}
}
int main(){
	clock_t t; 
    
	int size;
	cout<<"Enter array size: ";
	cin>>size;
	int array[size];
	cout<<"Enter "<<size<<" elements: "<<endl;
	int num;
	for(int i=0;i<size;i++){
		cin>>num;
		array[i]=num;
	}
//	cout<<"You entered: "<<endl;
//	print(array,size);
	int ans;
	int k;
//	quicksort(array,0,size-1,size);
	cout<<"Enter the value of k: ";
	cin>>k;
	if(k>size){
		cout<<"Invalid k"<<endl;
		return 0;
	}
	cout<<"Required smallest element: ";
	t = clock(); 
	ans=selectNth(array,0,size-1,k,size);
	t=clock()-t;
//	cout<<ans<<endl;
	

	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
  
    printf("fun() took %f seconds to execute \n", time_taken); 
  

  	t=clock();
  	nth_element(array,array+k-1,array+size);
  	t=clock()-t;
  	//cout<<ans<<endl;
	  double time_taken2 = ((double)t)/CLOCKS_PER_SEC; // in seconds 
  
    printf("fun() took %f seconds to execute \n", time_taken2); 
    return 0;
}