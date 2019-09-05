//g++ editDistance.cpp -o editDistance
#include <vector>
#include <iostream>

using namespace std;

int minDistance(string word1, string word2) {
	int len_1=word1.length();
	int len_2=word2.length();
	//convert word1 to word2
	int ans;
	int rows=len_1+1;
	int cols=len_2+1;
	vector<vector <int>> dist(rows, vector<int>(cols,0));

	for(int i=0; i<rows; i++){
		dist[i][0]=i;
	}

	for(int j=0; j<cols; j++){
		dist[0][j]=j;
	}
	int left, up, diag, mini;
	for(int i=1; i<rows; i++){
		for(int j=1; j<cols; j++){
			left=dist[i-1][j];
			up=dist[i][j-1];
			diag=dist[i-1][j-1];
			if(word1[i-1]==word2[j-1]){
				diag-=1; //trick
			}
			mini=min(left,min(up,diag));			
            dist[i][j]=1+mini;
		}
	}

	for(auto i: dist){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
	ans=dist[rows-1][cols-1];
	return ans;
}

int main(){
	string s="zoologicoarchaeologist";
	string t="zoogeologist";
	cout<<"Min distance b/w "<<s<<" and "<<t<<" is "<<minDistance(s,t)<<"\n";
	return 0;
}