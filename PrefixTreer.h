#ifndef __PrefixTree_h__
#define __PrefixTree_h__
#include <string>
#include <vector>
#include <map>
class PrefixTree
{
private:
	struct Node
	{
		std::string name = "";
		int* value = nullptr;
		std::map<char,Node*> children;
		Node()  { }
		Node(const Node& copyNode);
		~Node() { }
	};
	Node* root_;
public:

	PrefixTree(){ root_ = new Node(); }
	PrefixTree(const PrefixTree& copyPrefixTree);
	~PrefixTree() { }
	Node* find(std::string s);
	std::pair<Node*,bool> insert(std::string str, int val);
};

#endif

