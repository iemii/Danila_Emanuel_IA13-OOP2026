#pragma once
#include <iostream>

template <typename T>
class TreeNode {
public:
	T value;
	TreeNode<T>** children;//array dinamic de pointeri
	int childrenCount;//cati sunt efectiv
	int capacity;//cati spatiu este alocat
	TreeNode<T>* parent;//pointer pt parinte

	//constructor
	TreeNode(T val, TreeNode<T>* p = nullptr)
	{
		value = val;
		parent = p;
		childrenCount = 0;
		capacity = 2;
		children = new TreeNode<T>*[capacity];
	}

	~TreeNode()
	{
		for (int i = 0; i < childrenCount; i++)
			delete children[i];
		delete[] children;
	}


	//(ajutator) dublarea cap arrayului
	void expand_capacity() 
	{
		capacity *= 2;
		TreeNode<T>** newArray = new TreeNode<T>*[capacity];
		for (int i = 0; i < childrenCount; i++)
		{
			newArray[i] = children[i];
		}
		delete[] children;
		children = newArray;
	}

	//adaugare la final(ajutator)
	void add_child(TreeNode<T>* child)
	{
		if (childrenCount == capacity) expand_capacity();
		children[childrenCount++] = child;
	}

	//inserare la un index specific(ajutator)
	void insert_child(TreeNode<T>* child, int index)
	{
		if (index < 0 || index > childrenCount) return;
		if (childrenCount == capacity) expand_capacity();

		//mutam la dreapta
		for (int i = childrenCount; i > index; i--) 
		{
			children[i] = children[i - 1];
		}
		children[index] = child;
		childrenCount++;
	}
};

template <typename T>
class Tree {
private:
	TreeNode<T>* root;
	//(ajutator) recursiv pt find
	TreeNode<T>* find_recursive(TreeNode<T>* node, T val, bool (*cmp)(T, T)) {
		if (node == nullptr) return nullptr;

		if (cmp != nullptr) {
			if (cmp(val, node->value)) return node;
		}

		for (int i = 0; i < node->childrenCount; i++) {
			TreeNode<T>* found = find_recursive(node->children[i], val, cmp);
			if (found != nullptr) return found;
		}
		return nullptr;
	}

	//(ajutator) recursiv pentru count
	int count_recursive(TreeNode<T>* node) {
		if (node == nullptr) return 0;
		int total = node->childrenCount; //numaram copiii directi
		for (int i = 0; i < node->childrenCount; i++) {
			total += count_recursive(node->children[i]); //plus toti descendentii lor
		}
		return total;
	}

public:
	Tree() :root(nullptr) {}
	~Tree()
	{
		if (root != nullptr)
			delete root;
	}

	TreeNode<T>* add_node(TreeNode<T>* parent, T value)
	{
		if (parent == nullptr)
		{
			if (root != nullptr)
				delete root;
			root = new TreeNode<T>(value, nullptr);
			return root;
		}
		else
		{
			TreeNode<T>* newNode = new TreeNode<T>(value, parent);
			parent->add_child(newNode);
			return newNode;
		}
	}

	TreeNode<T>* get_node(TreeNode<T>* parent)
	{
		if (parent == nullptr)
			return root;
		return parent;
	}

	void delete_node(TreeNode<T>* node)
	{
		if (node ==nullptr)
			return;
		if (node == root)
		{
			delete root;
			root = nullptr;
			return;
		}

		TreeNode<T>* p = node->parent;
		if (p != nullptr)
		{
			int itoremove = -1;
			for (int i = 0; i < p->childrenCount; i++)
			{
				if (p->children[i] == node)
				{
					itoremove = i;
					break;
				}
			}
			if (itoremove != -1)
			{
				//mutam la stanga
				for (int i = itoremove; i < p->childrenCount - 1; i++)
					p->children[i] = p->children[i + 1];
				p->childrenCount--;
			}
		}
		delete node;
	}

	TreeNode<T>* find(T parameter, bool (*compare)(T, T))
	{
		return find_recursive(root, parameter, compare);
	}

	TreeNode<T>* insert(TreeNode<T>* parent, T value, int index)
	{
		if (parent == nullptr) return nullptr;
		TreeNode<T>* newNode = new TreeNode<T>(value, parent);
		parent->insert_child(newNode, index);
		return newNode;
	}

	void sort(TreeNode<T>* node, bool (*compare)(T, T) = nullptr)
	{
		if (node == nullptr || node->childrenCount < 2) return;

		//bubble
		for (int i = 0; i < node->childrenCount - 1; i++)
		{
			for (int j = i + 1; j < node->childrenCount; j++)
			{
				bool shouldSwap = false;
				if (compare != nullptr) 
				{
					if (compare(node->children[j]->value, node->children[i]->value))
					{
						shouldSwap = true;
					}
				}
				else
				{
					//daca e nullptr folosim operator<
					if (node->children[j]->value < node->children[i]->value)
					{
						shouldSwap = true;
					}
				}

				if (shouldSwap)
				{
					TreeNode<T>* temp = node->children[i];
					node->children[i] = node->children[j];
					node->children[j] = temp;
				}
			}
		}
	}
	int count(TreeNode<T>* node = nullptr) {
		//rete nr de la radacina in jos daca e apl cu nullptr
		if (node == nullptr) {
			return count_recursive(root);
		}
		return count_recursive(node);
	}
};