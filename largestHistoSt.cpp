//g++ largestHistoSt.cpp -o largestHistoSt
//stack
#include <vector>
#include <iostream>
#include <stack>
using namespace std;


int largestRectangleArea(vector<int>& heights) {
	int ans=-999999999;
	int len=heights.size();

	int area=0;

	stack <int> st;
	int idx;
	int top_rem;
	int h,b;
	for(int i=0; i<len; ){
		cout<<"i: "<<i<<" ";
		if(st.empty() || heights[i] >= heights[st.top()]){
			cout<<"push "<<i<<"\n";
			st.push(i);
			i++;
		}
		else{
		
			top_rem=st.top();
			cout<<"top: "<<top_rem<<", ";
			st.pop();

			h=heights[top_rem];
				
			if(st.empty()){
				cout<<"empty stack, ";
				b=i;
			}

			else //trick
				b=i-st.top()-1;
			
			cout<<" b: "<<b<<" ";
			
			area=h*b;
			cout<<"ar: "<<area<<"\n";
			
			if(area>ans){
				ans=area;
			}
		}
		idx=i;

	}
	while(st.empty()==false){
		top_rem=st.top();
		st.pop();

		
		h=heights[top_rem];
			
		if(st.empty()){
			b=idx;
		}
		else b=idx-st.top()-1;
		cout<<"h: "<<h<<" b: "<<b<<" ";
		area=h*b;
		cout<<"ar: "<<area<<"\n";
		if(area>ans){
			ans=area;
		}
	}



	return ans;
}


int main(){

	vector<int> h{2,1,5,6,2,3};
	cout<<largestRectangleArea(h)<<"\n";

	return 0;
}