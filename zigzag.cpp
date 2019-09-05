#include <string>
#include <iostream>
#include <vector>

using namespace std;

void zigzag(string s,int r){
	int len=s.length();
	
	if(r==1){
		cout<<s;
		return;
	}

	string ans[r];

	int row=0;
	bool down;

	for(int i=0;i<len;i++){
		//firsr char is same
		// cout<<"row: "<<row<<", s["<<i<<"]: "<<s[i]<<"\n";
		ans[row].push_back(s[i]);

		//if first row, go down
		if(row==0){
			// cout<<"down true\n";
			down=true;
		}
		//if last row. go up
		else if(row==r-1){
			// cout<<"down false\n";

			down=false;
		}
		//if down, increase row
		if(down){
			// cout<<"down true, ";
			// cout<<"--row inc--\n";
			row++;
		}
		else{
			//go up
			// cout<<"down false, ";
			// cout<<"--row dec--\n";

			row--;
		}
	}

	for(int i=0;i<r;i++)
		cout<<ans[i]<<"\n";
}

int main(){
	string s="nilotpal";
	int rows=3;
	zigzag(s,rows);
	return 0;
}