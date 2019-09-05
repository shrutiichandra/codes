#include <iostream>
#include <cstring>
using namespace std;

struct TrieNode* getNode();
void insert(struct TrieNode* root, string key);
bool search(struct TrieNode* root, string toFind);
struct TrieNode{
	struct TrieNode *child[26];
	bool isEndOfWord;
};

int main(){
	string words[]={"abc","aab","adc","bca","bcab","bfa"};

	int n=sizeof(words)/sizeof(words[0]);

	struct TrieNode *root=getNode();	

	for(int i=0;i<n;i++)
		insert(root,words[i]);
	if(search(root,"aab"))
		cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}

struct TrieNode* getNode(){
	struct TrieNode *node=new TrieNode;
	node->isEndOfWord=false;
	for(int i=0;i<26;i++)
		node->child[i]=NULL;

	return node;

}

void insert(struct TrieNode* root, string key){
	struct TrieNode* track=root;
	cout<<"inserting: "<<key<<endl;
	for(int i=0;i<key.length();i++){

		int index=key[i]-'a';
		cout<<"key["<<i<<"]: "<<key[i]<<", index: "<<index<<endl;
		cout<<"track->child["<<index<<"]: "<<track->child[index]<<endl;
		if(!track->child[index]){
			cout<<"inside if"<<endl;
			track->child[index]=getNode();
		}

		track=track->child[index];
		cout<<"2ndtrack->child["<<index<<"]: "<<track->child[index]<<endl;
	}

	track->isEndOfWord=true;
	cout<<endl;

}

bool search(struct TrieNode* root, string toFind){
	struct TrieNode* track=root;

	for(int i=0;i<toFind.length();i++){

		int index=toFind[i]-'a';
		if(!track->child[index]){
		//	cout<<"NO"<<endl;
			return false;
		}
		track=track->child[index];
	}
	return (track!=NULL&&track->isEndOfWord);
}
