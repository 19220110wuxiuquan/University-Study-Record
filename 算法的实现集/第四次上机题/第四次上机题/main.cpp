#include<iostream>
#include<vector>
using namespace std;
// 二叉链表结构
template<class T>
struct BiNode {
	T data;
	BiNode<T>* lchild;
	BiNode<T>* rchild;
};

// 二叉树
template<class T>
class BiTree 
{
private:
	
public:
	BiNode<T>* root;
	BiTree() 
	{
		root = NULL;
	}
	BiTree(vector<T>& pre);
	BiNode<T>* CreateByPre(vector<T>& pre, int& i);
	void PreOrder(BiNode<T>* p);
	void InOrder(BiNode<T>* p);
	void PostOrder(BiNode<T>* p);
	void PreOrder();
	void InOrder();
	void PostOrder();
	void LevelOrder();
	int Count(BiNode<T>* p);
	int Height(BiNode<T>* p);
	BiNode<T>* Search(BiNode<T>* p, T e);
	BiNode<T>* SearchParent(BiNode<T>* p, BiNode<T>* child);
	int Count();
	int Height();
	BiNode<T>* Search(T e);
	BiNode<T>* SearchParent(BiNode<T>* child);
};
// 队列实现
template<class T>
class LinkQueue {
private:
	struct Node {
		T data;
		Node* next;
	};
	Node* front;
	Node* rear;

public:
	LinkQueue() {
		front = rear = NULL;
	}
	~LinkQueue() {
		while (!Empty()) {
			DeQueue();
		}
	}

	bool Empty() {
		return front == NULL;
	}

	void EnQueue(T item) {
		Node* newNode = new Node;
		newNode->data = item;
		newNode->next = nullptr;

		if (Empty()) {
			front = rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = newNode;
		}
	}

	T DeQueue() {
		if (Empty()) {
			throw runtime_error("Queue is empty");
		}

		Node* temp = front;
		T item = front->data;
		front = front->next;
		delete temp;

		if (front == nullptr) {
			rear = nullptr;
		}

		return item;
	}
};

// 由带空指针标记的先序序列构造二叉树
template<class T>
BiNode<T>* BiTree<T>::CreateByPre(vector<T>& pre, int& i) {
	T e = pre[i];
	i++;
	if (e == '*') {
		return nullptr;
	}
	BiNode<T>* p = new BiNode<T>;
	p->data = e;
	p->lchild = CreateByPre(pre, i);
	p->rchild = CreateByPre(pre, i);
	return p;
}

template<class T>
BiTree<T>::BiTree(vector<T>& pre) {
	int i = 0;
	root = CreateByPre(pre, i);
}



// 前序遍历
template<class T>
void BiTree<T>::PreOrder(BiNode<T>* p) {
	if (p == nullptr) {
		return;
	}
	cout << p->data;
	PreOrder(p->lchild);
	PreOrder(p->rchild);
}

template<class T>
void BiTree<T>::PreOrder() {
	PreOrder(root);
}

// 中序遍历
template<class T>
void BiTree<T>::InOrder(BiNode<T>* p) {
	if (p == nullptr) {
		return;
	}
	InOrder(p->lchild);
	cout << p->data;
	InOrder(p->rchild);
}

template<class T>
void BiTree<T>::InOrder() {
	InOrder(root);
}

// 后序遍历
template<class T>
void BiTree<T>::PostOrder(BiNode<T>* p) {
	if (p == nullptr) {
		return;
	}
	PostOrder(p->lchild);
	PostOrder(p->rchild);
	cout << p->data;
}

template<class T>
void BiTree<T>::PostOrder() {
	PostOrder(root);
}

// 层次遍历
template<class T>
void BiTree<T>::LevelOrder() {
	LinkQueue<BiNode<T>*> queue;
	BiNode<T>* p = root;
	if (p != nullptr) {
		queue.EnQueue(p);
		while (!queue.Empty()) {
			p = queue.DeQueue();
			cout << p->data;
			if (p->lchild != nullptr) {
				queue.EnQueue(p->lchild);
			}
			if (p->rchild != nullptr) {
				queue.EnQueue(p->rchild);
			}
		}
	}
}

// 计算节点个数
template<class T>
int BiTree<T>::Count(BiNode<T>* p) {
	if (p == nullptr) {
		return 0;
	}
	return 1 + Count(p->lchild) + Count(p->rchild);
}

template<class T>
int BiTree<T>::Count() {
	return Count(root);
}

// 计算树的高度
template<class T>
int BiTree<T>::Height(BiNode<T>* p) {
	if (p == nullptr) {
		return 0;
	}
	int hl = Height(p->lchild);
	int hr = Height(p->rchild);
	return (hl > hr) ? (hl + 1) : (hr + 1);
}

template<class T>
int BiTree<T>::Height() {
	return Height(root);
}

// 查找节点
template<class T>
BiNode<T>* BiTree<T>::Search(BiNode<T>* p, T e) {
	if (p == nullptr) {
		return nullptr;
	}
	if (p->data == e) {
		return p;
	}
	BiNode<T>* temp = Search(p->lchild, e);
	if (temp != nullptr) {
		return temp;
	}
	return Search(p->rchild, e);
}

template<class T>
BiNode<T>* BiTree<T>::Search(T e) {
	return Search(root, e);
}

// 查找节点的父节点
template<class T>
BiNode<T>* BiTree<T>::SearchParent(BiNode<T>* p, BiNode<T>* child) {
	if (p == nullptr) {
		return nullptr;
	}
	if (p->lchild == child || p->rchild == child) {
		return p;
	}
	BiNode<T>* temp = SearchParent(p->lchild, child);
	if (temp != nullptr) {
		return temp;
	}
	return SearchParent(p->rchild, child);
}

template<class T>
BiNode<T>* BiTree<T>::SearchParent(BiNode<T>* child) {
	return SearchParent(root, child);
}


int main() {
	// Create a binary tree using preorder traversal
	vector<char> preorder = { 'A', 'B', 'D', '*', '*', 'E', '*', 'G', '*', '*', 'C', 'F', '*', '*', '*' };
	BiTree<char> tree(preorder);

	int choice;
	char searchElement;
	BiNode<char>* node;
	BiNode<char>* parent;

	do {
		cout << "Binary Tree Menu\n";
		cout << "1. Preorder Traversal\n";
		cout << "2. Inorder Traversal\n";
		cout << "3. Postorder Traversal\n";
		cout << "4. Level-order Traversal\n";
		cout << "5. Count Nodes\n";
		cout << "6. Calculate Height\n";
		cout << "7. Search Element\n";
		cout << "8. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Preorder traversal: ";
			tree.PreOrder(tree.root);
			cout << endl;
			break;
		case 2:
			cout << "Inorder traversal: ";
			tree.InOrder(tree.root);
			cout << endl;
			break;
		case 3:
			cout << "Postorder traversal: ";
			tree.PostOrder(tree.root);
			cout << endl;
			break;
		case 4:
			cout << "Level-order traversal: ";
			tree.LevelOrder();
			cout << endl;
			break;
		case 5:
			cout << "Number of nodes: " << tree.Count(tree.root) << endl;
			break;
		case 6:
			cout << "Height of the tree: " << tree.Height(tree.root) << endl;
			break;
		case 7:
			cout << "Enter the element to search: ";
			cin >> searchElement;
			node = tree.Search(tree.root, searchElement);
			if (node != nullptr) {
				cout << "Found element '" << searchElement << "' in the tree." << endl;
				parent = tree.SearchParent(tree.root, node);
				if (parent != nullptr) {
					cout << "Parent of '" << searchElement << "' is '" << parent->data << "'." << endl;
				}
				else {
					cout << "'" << searchElement << "' is the root of the tree." << endl;
				}
			}
			else {
				cout << "Element '" << searchElement << "' not found in the tree." << endl;
			}
			break;
		case 8:
			cout << "Exiting the program.\n";
			break;
		default:
			cout << "Invalid choice. Please enter a valid option.\n";
			break;
		}

		cout << endl;
	} while (choice != 8);

	return 0;
}