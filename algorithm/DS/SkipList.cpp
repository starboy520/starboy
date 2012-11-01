#include <cstdlib>
#include <cassert>
#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <new>

template <class Key, class Comparator>
class SkipList {
private:
	struct Node;
public:
	explicit SkipList(Comparator cmp);

	void Insert(const Key& key);

	// Return true iff an entry that compares equals to key is in the list
	bool Contains(const Key& key) const;

	bool Delete(const Key& key);

private:
	enum {kMaxHeight = 12};

	const Comparator compare_;

	Node* const head_;

	int max_height_;

	inline int GetMaxHeight() const {
		return max_height_;
	}

	int Randomheight();

	Node* NewNode(const Key& key, int height);

	bool Equal(const Key& a, const Key& b) const {
		return (compare_(a, b) == 0);
	}

	// return true if key is greater that data in n
	bool KeyAfterNode(const Key& key, Node* n) const;

	// Return the earliest node that comes at or after key.
	// Return NULL if there is no such node
	//
	// If prev is non-NULL, fills prev[level] with pointer to previous
	// node at level for every level in [0, maxheight -1]
	//
	Node* FindGreaterOrEqual(const Key& key, Node** prev) const;

	// Return the latest node with a node.key < key
	Node* FindLessThan(const Key& key) const;

	// return the last node in the list
	// return head_ if list is empty
	Node* FindLast() const;

	// disallow_copy_and_assign
	SkipList(const SkipList&);
	void operator=(const SkipList&);
};

// details
//
// about Node
template <typename Key, typename Comparator>
struct SkipList<Key, Comparator>::Node {
	const Key key;
	// tricky here!
	// Node* next_[kMaxHeight];
	Node** next_;

	explicit Node(const Key& k, int height) : key(k) {
		next_ = new Node*[height];
	}

	void SetNext(int n, Node* x) {
		assert(n >= 0);
		next_[n] = x;
	}

	Node* Next(int n) {
		return next_[n];
	}
};

template<typename Key, typename Comparator>
typename SkipList<Key, Comparator>::Node*
SkipList<Key, Comparator>::NewNode(const Key& key, int height) {
	return new Node(key, height);
}

template <typename Key, typename Comparator>
int SkipList<Key, Comparator>::Randomheight() {
	static const uint32_t kBranching = 4;
	int height = 1;

	while (height <= kMaxHeight && (rand() % kBranching) == 0) {
		height++;
	}

	assert(height > 0);
	assert(height < kMaxHeight);
	return height;
}

template <typename Key, class Comparator>
bool SkipList<Key, Comparator>::KeyAfterNode(const Key& key, Node* n) const {
	return (n != NULL) && (compare_(n->key, key) < 0 );
}

template <typename Key, typename Comparator>
typename SkipList<Key, Comparator>::Node* SkipList<Key, Comparator>::FindGreaterOrEqual(const Key& key, Node** prev) const {
	Node* x = head_;
	int level = GetMaxHeight() - 1;
	while (true) {
		Node* next = x->Next(level);
		if (KeyAfterNode(key, next)) {
			x = next;
		} else {
			if (prev != NULL) {
				prev[level] = x;
			}
			if (level == 0) {
				return next;
			} else {
				level--;
			}
		}
	}
}

template <typename Key, typename Comparator>
typename SkipList<Key, Comparator>::Node*
SkipList<Key, Comparator>::FindLessThan(const Key& key) const {
	Node* x = head_;
	int level = GetMaxHeight() - 1;
	while (true) {
		assert(x == head_ || compare_(x->key, key) < 0);
		Node* next = x->Next(level);
		if (next == NULL || compare_(next->key, key) >= 0) {
			if (level == 0) {
				return next;
			} else {
				level--;
			}
		} else {
			x = next;
		}
	}
}

template <typename Key, typename Comparator>
typename SkipList<Key, Comparator>::Node* SkipList<Key, Comparator>::FindLast() const {
	Node* x = head_;
	int level = GetMaxHeight() - 1;
	while (true) {
		Node* next = x->Next(level);
		if (next == NULL) {
			if (level == 0) {
				return x;
			} else {
				level--;
			}
		} else {
			x = next;
		}
	}
}

template <typename Key, typename Comparator>
SkipList<Key, Comparator>::SkipList(Comparator cmp) : compare_(cmp), head_(NewNode(0, kMaxHeight)), max_height_(1) {
	srand(time(NULL));
	for (int i = 0; i < kMaxHeight; i++) {
		head_->SetNext(i, NULL);
	}
}

template <typename Key, typename Comparator>
bool SkipList<Key, Comparator>::Delete(const Key& key) {

}

template <typename Key, typename Comparator>
void SkipList<Key, Comparator>::Insert(const Key& key) {
	Node* prev[kMaxHeight];
	Node* x= FindGreaterOrEqual(key, prev);

	assert(x == NULL || !Equal(key, x->key));

	int height = Randomheight();
	if (height > GetMaxHeight()) {
		for (int i = GetMaxHeight(); i < height; i++) {
			prev[i] = head_;
		}
		max_height_ = height;
	}

	x = NewNode(key, height);
	for (int i = 0; i < height; i++) {
		x->SetNext(i, prev[i]->Next(i));
		prev[i]->SetNext(i, x);
	}
}

template <typename Key, typename Comparator>
bool SkipList<Key, Comparator>::Contains(const Key& key) const {
	Node* x = FindGreaterOrEqual(key, NULL);
	if (x != NULL && Equal(key, x->key)) {
		return true;
	} else {
		return false;
	}
}

//////////////// test /////////////////////////

typedef uint64_t Key;

struct Comparator {
	int operator()(const Key& a, const Key& b) const {
		if (a < b) {
			return -1;
		} else if (a > b) {
			return 1;
		} else {
			return 0;
		}
	}
};

int main() {
	Comparator cmp;
	SkipList<Key, Comparator> list(cmp);
	for (int i = 0; i < 100; i++) {
		list.Insert(i);
	}

	for (int i = 0; i < 100; i++) {
		if (list.Contains(i)) {
			printf("yes\n");
		}
	}

	return 0;
}
