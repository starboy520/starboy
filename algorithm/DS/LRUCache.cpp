#include <stdio.h>
#include <stdlib.h>

// implement a LRU cache 
// ds: double linked list and hash
// c implementation
struct QNode {
	unsigned int pageNumber;
	struct QNode* prev;
	struct QNode* next;
};

struct Queue {
	unsigned int count;
	unsigned int numberOfFrames;
	QNode* front;
	QNode* rear;
};

struct Hash {
	int capacity;
	QNode** array;
};


QNode* newNode(unsigned int pageNumber) {
	QNode* temp = (QNode*)malloc(sizeof(QNode));
	temp->pageNumber = pageNumber;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

Queue* createQueue(int numberOfFrames) {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->count = 0;
	queue->numberOfFrames = numberOfFrames;

	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}

Hash* createHash(int capacity) {
	Hash* hash = (Hash*)malloc(sizeof(Hash));
	hash->capacity = capacity;
	hash->array = (QNode**)malloc(hash->capacity * sizeof(QNode*));
	for (int i = 0; i < capacity; i++) {
		hash->array[i] = NULL;
	}
	return hash;
}

int isFull(const Queue* queue) {
	return queue->count == queue->numberOfFrames;
}

int isEmpty(Queue* queue) {
	return queue->rear == NULL;
}

void deQueue(Queue* queue) {
	if (isEmpty(queue)) return ;

	if (queue->front == queue->rear)
		queue->front = NULL;
	QNode* temp = queue->rear;
	queue->rear = queue->rear->prev;
	if (queue->rear)
		queue->rear->next = NULL;
	free(temp);
	queue->count--;
}

void enQueue(Queue* queue, Hash* hash, unsigned pageNumber) {
	if (isFull(queue)) {
		hash->array[queue->rear->pageNumber] = NULL;
		deQueue(queue);
	}

	QNode* temp = newNode(pageNumber);
	temp->next = queue->front;
	if(isEmpty) {
		queue->rear = temp;
		queue->front = temp;
	} else {
		queue->front->prev = temp;
		queue->front = temp;
	}

	hash->array[pageNumber] = temp;
	queue->count++;
}


void referencePage(Queue* queue, Hash* hash, unsigned pageNumber) {
	QNode* reqPage = hash->array[pageNumber];

	if (reqPage == NULL) {
		enQueue(queue, hash, pageNumber);
	} else if (reqPage != queue->front) {
		reqPage->prev->next = reqPage->next;
		if (reqPage->next) {
			reqPage->next->prev = reqPage->prev;
		}

		if (reqPage == queue->rear) {
			queue->rear = reqPage->prev;
			queue->rear->next = NULL;
		}

		reqPage->next = queue->front;
		reqPage->prev = NULL;

		reqPage->next->prev = reqPage;
		queue->front = reqPage;
	}
}



// c++ implementation 
// deque + unordered_map
//

class LRUCache {
public:
	typedef deque<int>::iterator diter;
	
	LRUCache(int numbers) : count(0), numberOfFrames(numbers)  {
	}

	void refer(int pageNumber) {
		diter it = hash.find(pageNumber);
		if (it == hash.end()) {

		}
		// ....
	}

private:
	bool isFull() {
		return count == numberOfFrames;
	}

	bool isEmpty() {
		return count == 0;
	}

	int count;
	int numberOfFrames;
	
	deque<int> holder;
	unordered_map<int, diter> hash;
}
