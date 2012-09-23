// 暂时先上传，很多错误
template <typename T>
class XorDoubleLinkedListNode {
public:
	typedef T value_type;
	typedef T& reference_type;
	typedef T const& const_reference_type;
	typedef T* pointer_type;
	typedef T const* const_pointer_type;
	XorDoubleLinkedListNode(value_type info) :
		m_value(info), m_diff(NULL) {
	}

	void setData(const value_type& info) {
		m_value = info;
	}

	void setXorPointer(const pointer_type m_diff) {
		this->m_diff = m_diff;
	}

	pointer_type getXorPointer() {
		return m_diff;
	}

	value_type getValue() {
		return m_value;
	}

private:
	value_type m_value;
	pointer_type m_diff;
};

XorDoubleLinkedListNode* Xor(XorDoubleLinkedListNode* a, XorDoubleLinkedListNode* b) {
	return (XorDoubleLinkedListNode*) ( (unsigned int )a ^ (unsigned int)b);
}

template <typename T>
class XorDoubleLinkedList {
private:
	typedef XorDoubleLinkedListNode<T> node_type;
	typedef node_type* node_pointer;
public:
	typedef typename node_type::value_type value_type;
	typedef typename node_type::reference_type reference_type;
	typedef typename node_type::const_reference_type const_reference_type;

public:
	XorDoubleLinkedList() : m_head(NULL), m_tail(NULL) {
	}

	// 插入head之前
	void push_front(value_type value) {
		node_pointer temp = new node_type(value);
		temp->setXorPointer(Xor(head, NULL));
		if (head == NULL) {
			head = temp;
			tail = temp;
		} else {

			XorDoubleLinkedListNode* next = Xor(head->getXorPointer(), NULL);
			// 重新设置head 的 m_diff;
			head->setXorPointer(Xor(temp, next));
			// head 指向当前节点;
			head = temp;
		}
	}

	void push_back(value_type value) {
		node_pointer temp = new node_type(value);
		temp->setXorPointer(tail, NULL);
		if (tail == NULL) {
			head = temp;
			tail = temp;
		} else {
			// 首先要找到tail 之前的那个指
			XorDoubleLinkedListNode* pre = Xor(tail->getXorPointer(), NULL);
			tail->setXorPointer(Xor(pre, temp));
			tail = temp;
		}

	}

	//value_type pop_front() {
	//}
	//value_type pop_back() {
	
	//}
private:
	node_pointer m_head;
	node_pointer m_tail;
};

