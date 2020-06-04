#pragma once
#pragma once

//Binary_Search_Tree  ����������
template<class K>
struct BSTreeNode  
{
	BSTreeNode<K>* _left; //ָ������
	BSTreeNode<K>* _right;//ָ���Һ���
	K _key;               //�ؼ���

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
	// 1.�ǵݹ飨ѭ��������
	bool Insert(const K& key) 
	{
		if (_root == nullptr)
		{
			_root = new Node(key);//�����ĵ�һ���ڵ�
			return true;
		}

		Node* parent = nullptr; //parent�ʼΪ��
		Node* cur = _root;
		while (cur)//cur�ߵ��� ��ʾ�����curҪ�����λ��
		{
			if (cur->_key < key)
			{
				parent = cur;//cur������֮ǰ�ȸ�parent
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;//cur������֮ǰ�ȸ�parent
				cur = cur->_left;
			}
			else //��ʾ�����ֵ�Ѿ����� 
			{
				return false;
			}
		}

		cur = new Node(key);//��������
		if (parent->_key < cur->_key) //��parent������cur
		{
			parent->_right = cur; 
		}
		else
		{
			parent->_left = cur;
		}

		return true;
	}
	// 2.�ݹ�ķ�ʽ����
	//�ȸ��󣬾͵�����ȥ����
	//�ȸ�С���͵�����ȥ����
	bool _InsertR(Node*& root, const K& key)
	{
		if (root == nullptr)
			root = new Node(key);

		if (root->_key < key)//Ҫ�����ֵ�ȸ���
			return _InsertR(root->_right, key); //������ȥ���� �ѷ�������������ָ�봫��root rootҲ��parent->right�ı���
		//root�ߵ������Ժ󣬿��½ڵ㣬����rootͬʱ����һ�㸸����/�ҵı��� ���¿��Ľڵ��root�ͺ͸�������������
		else if (root->_key > key)//Ҫ�����ֵ�ȸ�С
			return _InsertR(root->_left, key);//������ȥ����
		else
			return false;
	}

	bool InsertR(const K& key)
	{
		return _InsertR(_root, key);
	}
	//3.����
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
				return cur;//��Ⱦͱ�ʾ�ҵ��� ����
		}

		return NULL;
	}
	//�ݹ����
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
	//4.�ݹ� ɾ��һ��ֵ
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
			// 1.��Ϊ��
			// 2.��Ϊ��
			// 3.���Ҷ���Ϊ��
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
				// �滻��ɾ��  ���������ڵ�(���ҽڵ�) ��������������С�ڵ�(����ڵ�)
				Node* minNode = cur->_right;
				while (minNode->_left)
				{
					minNode = minNode->_left;
				}
				cur->_key = minNode->_key;

				// ת����ȥ��������ɾ�������С�ڵ��ֵ�������⡣
				return _EraseR(cur->_right, minNode->_key);
			}
		}
	}
	
	bool EraseR(const K& key)
	{
		return _EraseR(_root, key);
	}
	//4.�ҵ�ָ����ֵ ��ɾ�� �ǵݹ�
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
				// 1.��Ϊ��
				// 2.��Ϊ��
				// 3.���Ҷ���Ϊ��
				if (cur->_left == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_right;
					}
					else
					{
						if (cur == parent->_left)
							parent->_left = cur->_right; //������Ǹ��׵��� ���ø��׵���ָ���ҵ���
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
				else //���Ҷ���Ϊ�յ����
				{
					// �滻��ɾ��  ���������ڵ�(���ҽڵ�) ��������������С�ڵ�(����ڵ�)
					Node* minNodeParent = cur;  // ����Ҫע�ⲻ�ܳ�ʼ������
					Node* minNode = cur->_right;
					while (minNode->_left)
					{
						minNodeParent = minNode;
						minNode = minNode->_left;
					}

					swap(cur->_key, minNode->_key);//�Ѹ��ڵ���ҵ���ֵ�滻
					// ת����ɾ��minNode

					// ��ΪminNode����Ϊ�յĽڵ㣬����ֱ��ɾ��
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

	void _InOrder(Node* root)//�������
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);//��������������
		cout << root->_key << " ";//����key
		_InOrder(root->_right);//�����������
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	Node* _root = nullptr; //��
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