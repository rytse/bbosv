/*
Node_Priority_Queue::Node_Priority_Queue() {
	front = NULL;
	rear = NULL;
}

Node *Node_Priority_Queue::top() {
	return front;
}

bool Node_Priority_Queue::empty() {
	return front == NULL;
}

unsigned int Node_Priority_Queue::size() {
	unsigned int c = 0;
	for (node_ll_s *n = ll; n != NULL && n->next != NULL; n = n->next) {
		c++;
	}
	return c;
}

void Node_Priority_Queue::pop() {
	if (front == NULL) {
		return;
	}

	if (front == rear) {
		front = rear = NULL;
	} else {
		Node *tmp = front;
		front = front->next;
		delete tmp;
	}
}

void Node_Priority_Queue::push(Node *n) {
	if (front == NULL) {
		front = rear = n;
	} else {
		rear->next = n;
		rear = n;
	}
}

void Node_Priority_Queue::~Node_Priority_Queue() {
	while (front != NULL) {
		Node *tmp = front;
		front = front->next;
		delete tmp;
	}
	rear = NULL;
}
*/
