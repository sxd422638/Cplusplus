#pragma once

template<class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf; // balance factor3



	pair<K, V> _kv;

	AVLTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _kv(kv)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<const K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		// 1.���������Ĺ��򽫲���ֵ
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_bf = 0;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)//��������
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)//С������
			{
				parent = cur;
				cur = cur->_left;   
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}





		// 1.����ƽ������ 

		while (parent)//parent���µ�����ʱ���ֹ
		{
			if (cur == parent->_right)
				parent->_bf++;//���µ��ұ� ƽ������++
			else if (cur == parent->_left)
				parent->_bf--;//���µ���� ƽ������--

			if (parent->_bf == 0)//������׵�ƽ������Ϊ0 ˵��������� 
			{
				break;
			}
			else if (abs(parent->_bf) == 1)//abs��ʾ�����ֵ �߶ȱ仯�� �������ϸ���
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)//abs��ʾ�����ֵ ��ʾ��Ҫ��ת
			{
				// ˵��parent�����Ѿ���ƽ�⣬��Ҫ��ת��������ƽ��
				if (parent->_bf == 2)
				{
					if (cur->_bf == 1)
					{
						RotateL(parent);//���� ��2 ��1
					}
					else if (cur->_bf == -1)
					{
						RotateRL(parent);//����˫�� ��2 ��-1
					}
				}
				else if (parent->_bf == -2)
				{
					if (cur->_bf == -1)//�ҵ���
					{
						RotateR(parent);
					}
					else if (cur->_bf == 1)//����˫��
					{
						RotateLR(parent);
					}
				}

				break;
			}
			else
			{
				assert(false);
			}
		}

		return true;
	}




	//����

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)//subRL�п����ǿ�
			subRL->_parent = parent;

		subR->_left = parent; 

		Node* ppNode = parent->_parent;

		parent->_parent = subR;

		if (parent == _root) {      //������
			_root = subR;
			subR->_parent = nullptr;
		}
		else {
			if (ppNode->_left == parent)
				ppNode->_left = subR;
			else
				ppNode->_right = subR;

			subR->_parent = ppNode;
		}

		subR->_bf = parent->_bf = 0;
	}








	//�ҵ���

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subL;

		if (parent == _root)//���parentԭ���Ǹ� ���ڸ���subL
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else//��˭��˭��������
		{
			if (ppNode->_left == parent)
				ppNode->_left = subL;
			else
				ppNode->_right = subL;

			subL->_parent = ppNode;
		}

		parent->_bf = subL->_bf = 0;
	}







	void RotateLR(Node* parent)//����˫�� ������ ���ҵ��� ����ͼ������
	{
		RotateL(parent->_left);
		RotateR(parent);
		if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0;
		}
	}

	void RotateRL(Node* parent)//����˫�� ���ҵ��� ������
	{
		RotateR(parent->_right);
		RotateL(parent);

		if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
	}
	






	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	int _Depth(Node* root)
	{
		if (root == nullptr)
			return 0;

		int leftDepth = _Depth(root->_left);
		int rightDepth = _Depth(root->_right);

		return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
	}

	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		int leftDepth = _Depth(root->_left);
		int rightDepth = _Depth(root->_right);

		if (rightDepth - leftDepth != root->_bf)
		{
			cout << root->_kv.first << ":ƽ�������쳣" << endl;
			//return false;
		}

		return abs(rightDepth - leftDepth) < 2
			&& _IsBalance(root->_left)
			&& _IsBalance(root->_right);
	}

	bool IsBalance()
	{
		return _IsBalance(_root);
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < key)
				cur = cur->_right;
			else if (cur->_kv.first > key)
				cur = cur->_left;
			else
				return cur;
		}

		return NULL;
	}

private:
	Node* _root = nullptr;
};




void TestAVLTree()
{

	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(make_pair(e, e));
	}

	t.InOrder();

	cout << t.IsBalance() << endl;
}

