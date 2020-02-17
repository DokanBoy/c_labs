#include <iostream>

class List {
public:
	class ListElt {
	public:
		ListElt* next;
		int data;
		ListElt(int num) {

			data = num;
			next = 0;
		}
	};
	ListElt* first;

	List() {
		first = 0;
	}

	~List() {
		ListElt* currNode;
		while (first) {
			currNode = first;
			first = first->next;
			delete currNode;
		}
	}

	void appendFirst(int num) {
		ListElt* newList = new ListElt(num);
		newList->next = first;
		first = newList;
	}

	void appendEnd(int num) {
		if (!first)
			appendFirst(num);
		else
		{
			ListElt* curr;
			for (curr = first; curr->next; curr = curr->next);

			curr->next = new ListElt(num);

		}
	}

	void printer() {
		for (ListElt* curr = first; curr; curr = curr->next) {
			std::cout << curr->data << ", ";
		}
	}

	int size() {
		int counter = 0;
		for (ListElt* curr = first; curr; curr = curr->next) {
			++counter;
		}
		return counter;
	}

	int* toArray() {
		int* arrayListElt = new int[size()];
		for (ListElt* curr = first, int i = 0; curr; curr = curr->next, i++) {
			arrayListElt[i] = curr->data;
		}
		return arrayListElt;
	}

	void remove(int index) {
		if (index == 0) {
			//TODO
		}
		else {

		}
	}
};

int main() {
	List* list = new List();
	list->appendEnd(123);
	list->appendEnd(456);
	list->appendFirst(789);
	list->printer();
	delete list;
	return 0;
}
