#ifndef A7_HPP
#define A7_HPP

#include "symbol.hpp"
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

class order {
public:
	bool operator()(const bnode<symbol>* q, const bnode<symbol>* w) 
	{ return ((q->value.count > w->value.count) || (!(w->value.count > q->value.count) && (q->value.value > w->value.value))); }
};

// IMPLEMENT YOUR FUNCTION huffman_tree
template <typename Iter>
bnode<symbol>* huffman_tree(Iter first, Iter last) {
	std::priority_queue<bnode<symbol>*, std::vector<bnode<symbol>* >, order > nodes;

	for (; first < last; first++) {
		bnode<symbol>* temp;
		temp = new bnode<symbol>((*first), 0, 0);
		nodes.push(temp);
	}

	while (nodes.size() > 1) {
		bnode<symbol>* t1 = nodes.top();
		nodes.pop();
		bnode<symbol>* t2 = nodes.top();
		nodes.pop();
		bnode<symbol>* parent;
		parent = new bnode<symbol>(symbol(0,(t1->value.count + t2->value.count)),t1,t2);
		nodes.push(parent);
	}


	bnode<symbol>* root = nodes.top();
	return root;
	
}

// IMPLEMENT YOUR FUNCTION release_tree
void release_tree(bnode<symbol>* root) {
	if (root->left != 0) release_tree(root->left);
	if (root->right != 0) release_tree(root->right);
	delete root;
}

#endif // A7_HPP