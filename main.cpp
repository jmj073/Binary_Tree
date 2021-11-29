#include "basic binary tree.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	BinaryTree<string, int> tree;

	tree.insert("yfh", 1);
	tree.insert("dbb", 2);
	tree.insert("gbb", 3);
	tree.insert("hbb", 4);
	tree.insert("abb", 5);
	tree.insert("cub", 6);
	tree.insert("ybb", 7);
	tree.insert("ubb", 8);

	tree.printInorder();
	cout << "-------------------------------" << endl;
	tree.erase("dbb");
	tree.printInorder();
}