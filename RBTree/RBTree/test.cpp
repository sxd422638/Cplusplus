#pragma once

enum Colour
{
	BLACK,
	RED,
};

template<class K, class V>
class RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	pair<K, V> _kv;

	Colour _col;
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		// 1、按搜索树的规则进行插入
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
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

		// 新增节点红的
		cur->_col = RED;
		while (parent && parent->_col == RED)
		{
			// 红黑色的条件关键看叔叔
			Node* grandfther = parent->_parent;
			if (grandfther->_left == parent)
			{
				Node* uncle = grandfther->_right;
				// 情况1：uncle存在，且为红
				// 情况2 or 情况3：uncle不存在 or uncle存在，且为黑
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfther->_col = RED;

					// 继续往上处理
					cur = grandfther;
					parent = cur->_parent;
				}
				else
				{
					// 情况三：双旋 -> 变为单旋
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(parent, cur);
					}

					// 第二中情况(ps：有可能是第三种变过来的)
					RotateR(grandfther);
					grandfther->_col = RED;
					parent->_col = BLACK;

					break;
				}
			}
			else
			{
				// ...
			}
		}

		_root->_col = BLACK;

		return true;

	}

private:
	Node* _root = nullptr;
};