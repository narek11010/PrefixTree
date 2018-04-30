#include "PrefixTreer.h"

PrefixTree::Node::Node(const PrefixTree::Node& copyNode):name(copyNode.name), value(new int())
{
	value = copyNode.value;
	std::map<char, Node*>::const_iterator it = copyNode.children.begin();
	for (; it != copyNode.children.end(); ++it)
	{
		children[it->first] = new Node(*it->second);
	}
}
PrefixTree::PrefixTree(const PrefixTree& copyPrefixTree)
{
	root_ = new Node(*copyPrefixTree.root_);
}
std::pair<PrefixTree::Node*, bool> PrefixTree::insert(std::string str, int val)
{
	Node* current = root_;

	for (int i = 0; i < str.size(); ++i)
	{
		std::map<char, Node*>::iterator it = current->children.find(str[i]);

		if (it == current->children.end())
		{
			for (; i < str.size(); ++i)
			{
				current->children[str[i]] = new Node();
				current = current->children[str[i]];
				current->name = str.substr(0, i + 1);
				current->value = nullptr;
			}
			current->value = new int();
			*(current->value) = val;

			return std::pair<Node*, bool>{ current, true };
		}
		
		current = current->children[str[i]];
	}
	
	if (current->value == nullptr)
	{
		current->value = new int();
		*(current->value) = val;
		return std::pair<Node*, bool>{ current, true };
	}

	return std::pair<Node*, bool>{ current, false };
}

PrefixTree::Node* PrefixTree::find(std::string str)
{	
	Node* current = root_;
	for (int i = 0; i < str.size(); ++i)
	{
		std::map<char, Node*>::iterator it = current->children.find(str[i]);
		if (it == current->children.end())
		{
			return nullptr;
		}
		current = current->children[str[i]];
	}
	if (current->value == nullptr)
	{
		return nullptr;
	}
	return current;
}