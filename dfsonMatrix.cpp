//incomplete
#include <iostream>
#include <stack>

int main(){

	int mrows,ncols;
	cout<<"Enter rows and cols: ";
	cin>>mrows;
	cin>>ncols;
	int num;
	int arr[mrows][ncols];
	cout<<"\nenter "<<mrows*ncols<<" numbers: \n";
	for(int i=0;i<mrows;i++){
		for(int j=0;j<ncols;j++){
			cin>>num;
			arr[i][j]=num;
		}
	}

	int visited[mrows][ncols];
	memset(visited,-1,sizeof(visited));

	int islands=0;
	cout<<"\n---islands---\n";

	for(int i=0;i<mrows;i++){
		for(int j=0;j<ncols;j++){
			if(arr[i][j]==1&&visited==-1){
				islands++;
				doDFS(arr[i][j]);
			}
		}
	}


}




