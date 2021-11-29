#pragma once

#include <utility>
#include <iostream>

template <typename K, typename T>
class BinaryTree
{
public:
	struct Node {
		std::pair<K, T> data;
		Node* left;
		Node* right;
	};

	using key_type = K;
	using value_type = T;

public:
	BinaryTree() : m_root{ nullptr } {}

	void insert(const K& key, const T& value);
	bool erase(const K& key);
	T& operator[] (const K& key);

	void printInorder() const { inorder(m_root, 0); }

	~BinaryTree() { destroy(m_root); }

private:
	void inorder(Node*, int) const;
	void destroy(Node*);
	Node* pop(Node*, const K& key);
	Node* pop_withoutRecursion(Node*);
	Node* searchMinNode(Node* root);
	Node* searchMinNodeParent(Node* root);

private:
	Node* m_root;
};

template <typename K, typename T>
inline void BinaryTree<K, T>::insert(const K& key, const T& value)
{
	this->operator[](key) = value;
}

template <typename K, typename T>
T& BinaryTree<K, T>::operator[] (const K& key)
{
	Node* cur = m_root;
	if (!m_root) {
		m_root = new Node{ std::make_pair(key, T()), nullptr, nullptr };
		return m_root->data.second;
	}

	while (true) {
		if (key < cur->data.first) {
			if (!cur->left) {
				Node* newNode = new Node{ std::make_pair(key, T()), nullptr, nullptr };
				cur->left = newNode;
				return newNode->data.second;
			}
			cur = cur->left;
		}
		else if (key > cur->data.first) {
			if (!cur->right) {
				Node* newNode = new Node{ std::make_pair(key, T()), nullptr, nullptr };
				cur->right = newNode;
				return newNode->data.second;
			}
			cur = cur->right;
		}
		else
			return cur->data.second;
	}
}

template <typename K, typename T>
void BinaryTree<K, T>::inorder(Node* cur, int depth) const
{
	if (!cur) return;

	inorder(cur->left, depth + 1);

	for (int i = 0; i < depth; i++)
		std::cout << ". ";
	std::cout << cur->data.first << ':' << cur->data.second << std::endl;

	inorder(cur->right, depth + 1);
}

template <typename K, typename T>
void BinaryTree<K, T>::destroy(Node* node)
{
	if (!node) return;
	destroy(node->left);
	destroy(node->right);
	delete node;
}

template <typename K, typename T>
/*inline*/ bool BinaryTree<K, T>::erase(const K& key)
{
	//return m_root = pop(m_root, key);
	//--or---------------------------------------
	Node** parents_child_ptr = &m_root;
	Node* cur = m_root;
	while (cur) {
		if (key < cur->data.first) {
			parents_child_ptr = &cur->left;
			cur = cur->left;
		}
		else if (key > cur->data.first) {
			parents_child_ptr = &cur->right;
			cur = cur->right;
		}
		else {
			*parents_child_ptr = pop_withoutRecursion(cur);
			return true;
		}
	}

	
	return false;
}

template <typename K, typename T>
typename BinaryTree<K, T>::Node* BinaryTree<K, T>::pop(Node* cur, const K& key)
{
	if (!cur) return cur;

	if (key < cur->data.first)
		cur->left = pop(cur->left, key);
	else if (key > cur->data.first)
		cur->right = pop(cur->right, key);
	else {
		if (!cur->left) {
			Node* temp = cur->right;
			delete cur;
			return temp;
		}
		if (!cur->right) {
			Node* temp = cur->left;
			delete cur;
			return temp;
		}
		Node* minNode = searchMinNode(cur->right);
		cur->data.first = minNode->data.first;
		cur->data.second = std::move(minNode->data.second);
		cur->right = pop(cur->right, minNode->data.first);
	}
	return cur;
}

template <typename K, typename T>
typename BinaryTree<K, T>::Node* BinaryTree<K, T>::pop_withoutRecursion(BinaryTree<K, T>::Node* targ)
{
	if (!targ->left) {
		Node* temp = targ->right;
		delete targ;
		return temp;
	}
	if (!targ->right) {
		Node* temp = targ->left;
		delete targ;
		return temp;
	}

	Node** parents_child_ptr = &targ->right;
	Node* minNode = targ->right;
	while (minNode->left) {
		parents_child_ptr = &minNode->left;
		minNode = minNode->left;
	}

	targ->data = std::move(minNode->data);
	*parents_child_ptr = pop_withoutRecursion(minNode);

	return targ;
}

template <typename K, typename T>
typename BinaryTree<K, T>::Node* BinaryTree<K, T>::searchMinNode(Node* root)
{
	while (root->left)
		root = root->left;
	return root;
}