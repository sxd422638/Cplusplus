#pragma once
#pragma once

//Binary_Search_Tree  搜索二叉树
template<class K>
struct BSTreeNode  
{
	BSTreeNode<K>* _left; //指向左孩子
	BSTreeNode<K>* _right;//指向右孩子
	K _key;               //关键字

	BSTreeNode(const K& key)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
	{}
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	// 1.非递归（循环）插入
	bool Insert(const K& key) 
	{
		if (_root == nullptr)
		{
			_root = new Node(key);//空树的第一个节点
			return true;
		}

		Node* parent = nullptr; //parent最开始为空
		Node* cur = _root;
		while (cur)//cur走到空 表示这就是cur要插入的位置
		{
			if (cur->_key < key)
			{
				parent = cur;//cur往下走之前先给parent
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;//cur往下走之前先给parent
				cur = cur->_left;
			}
			else //表示插入的值已经有了 
			{
				return false;
			}
		}

		cur = new Node(key);//插入数据
		if (parent->_key < cur->_key) //让parent链接上cur
		{
			parent->_right = cur; 
		}
		else
		{
			parent->_left = cur;
		}

		return true;
	}
	// 2.递归的方式插入
	//比根大，就到右树去插入
	//比根小，就到左树去插入
	bool _InsertR(Node*& root, const K& key)
	{
		if (root == nullptr)
			root = new Node(key);

		if (root->_key < key)//要插入的值比根大
			return _InsertR(root->_right, key); //到右树去插入 把符合条件结点的右指针传给root root也是parent->right的别名
		//root走到空了以后，开新节点，但是root同时是上一层父亲左/右的别名 ，新开的节点给root就和父亲连接起来了
		else if (root->_key > key)//要插入的值比根小
			return _InsertR(root->_left, key);//到左树去插入
		else
			return false;
	}

	bool InsertR(const K& key)
	{
		return _InsertR(_root, key);
	}
	//3.查找
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
				cur = cur->_right;
			else if (cur->_key > key)
				cur = cur->_left;
			else
				return cur;//相等就表示找到了 返回
		}

		return NULL;
	}
	//递归查找
	Node* _FindR(Node* root, const K& key)
	{
		if (root == nullptr)
			return nullptr;

		if (root->_key < key)
			return _FindR(root->_right, key);
		else if (root->_key > key)
			return _FindR(root->_left, key)
		else
			return  root;
	}

	Node* FindR(const K& key)
	{
		return _FindR(_root, key);
	}
	//4.递归 删除一个值
	bool _EraseR(Node*& cur, const K& key)
	{
		if (cur == nullptr)
			return false;

		if (cur->_key < key)
		{
			return _EraseR(cur->_right, key);
		}
		else if (cur->_key > key)
		{
			return _EraseR(cur->_left, key);
		}
		else
		{
			// 1.左为空
			// 2.右为空
			// 3.左右都不为空
			Node* del = cur;
			if (cur->_left == nullptr)
			{
				cur = cur->_right;
				delete del;
				return true;
			}
			else if (cur->_right == nullptr)
			{
				cur = cur->_left;
				delete del;
				return true;
			}
			else
			{
				// 替换法删除  左树的最大节点(最右节点) 或者是右树的最小节点(最左节点)
				Node* minNode = cur->_right;
				while (minNode->_left)
				{
					minNode = minNode->_left;
				}
				cur->_key = minNode->_key;

				// 转换成去右子树中删除这个最小节点的值的子问题。
				return _EraseR(cur->_right, minNode->_key);
			}
		}
	}
	
	bool EraseR(const K& key)
	{
		return _EraseR(_root, key);
	}
	//4.找到指定的值 并删除 非递归
	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				// 1.左为空
				// 2.右为空
				// 3.左右都不为空
				if (cur->_left == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_right;
					}
					else
					{
						if (cur == parent->_left)
							parent->_left = cur->_right; //如果我是父亲的左 就让父亲的左指向我的右
						else
							parent->_right = cur->_right;
					}

					delete cur;
				}
				else if (cur->_right == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_left;
					}
					else
					{
						if (cur == parent->_left)
							parent->_left = cur->_left;
						else
							parent->_right = cur->_left;
					}

					delete cur;
				}
				else //左右都不为空的情况
				{
					// 替换法删除  左树的最大节点(最右节点) 或者是右树的最小节点(最左节点)
					Node* minNodeParent = cur;  // 这里要注意不能初始化给空
					Node* minNode = cur->_right;
					while (minNode->_left)
					{
						minNodeParent = minNode;
						minNode = minNode->_left;
					}

					swap(cur->_key, minNode->_key);//把根节点和找到的值替换
					// 转换成删除minNode

					// 因为minNode是作为空的节点，可以直接删除
					if (minNodeParent->_right == minNode)
						minNodeParent->_right = minNode->_right;
					else
						minNodeParent->_left = minNode->_right;

					delete minNode;
				}

				return true;
			}
		}

		return false;
	}

	void _InOrder(Node* root)//中序遍历
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);//中序先走左子树
		cout << root->_key << " ";//再走key
		_InOrder(root->_right);//最后走右子树
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	Node* _root = nullptr; //根
};

void TestBSTree()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> bst;
	for (auto e : a)
	{
		//bst.Insert(e);
		bst.InsertR(e);
	}
	bst.InOrder();

	bst.Erase(2);
	bst.InOrder();
	bst.Erase(8);
	bst.InOrder();
	bst.Erase(1);
	bst.InOrder();
	bst.Erase(5);
	bst.InOrder();

	for (auto e : a)
	{
		bst.EraseR(e);
		bst.InOrder();
	}
	bst.InOrder();
}