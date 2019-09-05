//g++ cloneGraphDFS.cpp -o cloneGraphDFS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

//  * Definition for undirected graph.
 struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
 };
 
class Solution {
public:
    typedef UndirectedGraphNode UGN;

    UGN* dfs(UGN* node,unordered_map<UGN*,UGN*>& map){
    	cout<<"in dfs\n";
    	unordered_map<UGN*, UGN*>:: iterator iter;
    	iter=map.find(node);
    	if(iter!=map.end()){
    		cout<<"returning\n";
    		return iter->second;
    	}

    	UGN* newnode=new UGN(node->label);
    	map[node]=newnode;
    	cout<<"after adding in map\n";
    	vector<UGN*>::iterator it;
    	cout<<"before for\n";
    	for(it=node->neighbors.begin(); it!=node->neighbors.end(); it++){
    		UGN* adj=*it;
    		map[node]->neighbors.push_back(dfs(adj,map));
    		cout<<"in for\n";
    	}
    	cout<<"after for\n";
    	return newnode;


    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	cout<<"in cloneGraph\n";
        UGN *newnode=NULL;
        if(node==NULL){
        	return NULL;
        }

        // newnode=new UGN(node->label);
        unordered_map<UGN*, UGN*> map; //maintaining this mapping is imp
        newnode=dfs(node,map);

     
        return newnode;
    }
};

int main(){
	UndirectedGraphNode* head=new UndirectedGraphNode(-1);
	// UndirectedGraphNode* node1=new UndirectedGraphNode(2);
	// UndirectedGraphNode* node2=new UndirectedGraphNode(3);

	// head->neighbors.push_back(node1);
	// head->neighbors.push_back(node2);

	// node1->neighbors.push_back(node2);

	// node2->neighbors.push_back(node2); //cycle

	Solution obj;
	UndirectedGraphNode* deep_copy=NULL;
	deep_copy=obj.cloneGraph(head);
	
	for(auto neighbor: deep_copy->neighbors){
		cout<<neighbor->label<<" ";
	}
	cout<<"\n";

	return 0;
}