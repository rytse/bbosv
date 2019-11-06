#include "nav.h"

/** Path linked list */
typedef struct v2d_ll_s {
	struct v2d data;
	path_ll *next;
} path_ll_s;

typedef struct node_ll_s {
	Node data;
	node_ll_s *next;
} node_ll_s;

class Node_Priority_Queue {
public:
	Node_Priority_Queue();
	Node *top() const;
	bool empty() const;
	unsigned int size() const;
	void pop();
	void push(Node *e);
private:
	node_ll_s *front;
	node_ll_s *rear;
}