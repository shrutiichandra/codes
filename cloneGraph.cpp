//g++ cloneGraph.cpp -o cloneGraph
//BFS
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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	cout<<"in cloneGraph\n";
        UGN *newnode=NULL;
        newnode=new UGN(node->label);
        unordered_map<UGN*, UGN*> map; //maintaining this mapping is imp
        queue<UGN*> q;
        vector<UGN*>::iterator it;
        map[node]=newnode;
        q.push(node);

        while(!q.empty()){
        	UGN* front=q.front();
        	q.pop();

        	for(it=front->neighbors.begin(); it!=front->neighbors.end(); it++){

        		if(map.find(*it)==map.end()){ //if, this adj node is not in map
		    		int val=(*it)->label;
		    		UGN* adj=new UGN(val);
		    		map[*it]=adj;
		    		q.push(*it);
		    	}

		    	map[front]->neighbors.push_back(map[*it]);
        	}

        }
        return newnode;
    }
};

int main(){
	UndirectedGraphNode* head=new UndirectedGraphNode(1);
	UndirectedGraphNode* node1=new UndirectedGraphNode(2);
	UndirectedGraphNode* node2=new UndirectedGraphNode(3);

	head->neighbors.push_back(node1);
	head->neighbors.push_back(node2);

	node1->neighbors.push_back(node2);

	node2->neighbors.push_back(node2); //cycle

	Solution obj;
	UndirectedGraphNode* deep_copy=NULL;
	deep_copy=obj.cloneGraph(head);
	
	return 0;
}