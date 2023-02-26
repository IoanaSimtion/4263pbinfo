#ifndef lista.h
#define lista.h

#include "node.h";


template<typename U>
struct Lista {

	Node<U>* head = NULL;

	void addStart(U data) {

		if (head == NULL) {

			head = new Node<U>();

			head->data = data;

			head->next = NULL;

		}
		else {

			Node<U>* nou = new Node<U>();

			nou->data = data;

			nou->next = head;

			head = nou;

		}

	}


	void add(U data) {

		if (head == NULL) {

			head = new Node<U>();

			head->data = data;

			head->next = NULL;

		}
		else {

			Node<U>* nou = new Node<U>();

			Node<U>* aux = head;

			while (aux->next != NULL) {

				aux = aux->next;

			}

			aux->next = nou;

			nou->data = data;

			nou->next = NULL;

		}

	}


	void addPoz(U data, int index) {

		if (index == 0) {

			addStart(data);

			return;

		}

		Node<U>* aux = head;

		int ct = 0;

		while (aux != NULL && ct != index - 1) {

			aux = aux->next;

			ct++;

		}

		if (aux == NULL) {

			add(data);

			return;

		}

		Node<U>* nou = new Node<U>();

		nou->data = data;

		nou->next = aux->next;

		aux->next = nou;

	}


	void afisare() {

		Node<char>* aux = head;

		while (aux != NULL) {

			cout << aux->data << " ";

			aux = aux->next;

		}
	}


	void stergereSfarsit() {

		Node<U>* aux = head;

		while (aux->next->next != NULL) {

			aux = aux->next;

		}

		aux->next = NULL;
	}


	void stergereStart() {

		head = head->next;

	}


	void removeIndex(int index) {

		Node<U>* aux = head;

		int ct = 0;

		if (index == 0) {

			stergereStart();

			return;

		}

		while (aux != NULL && ct != index - 1) {

			aux = aux->next;

			ct++;

		}

		if (aux == NULL) {

			stergereSfarsit();

			return;

		}

		aux->next = aux->next->next;

	}


	void removeObject(U elem) {

		Node<U>* aux = head;

		int ct = 0;

		while (aux != NULL) {

			if (aux->data == elem) {

				removeIndex(ct);

				return;

			}

			aux = aux->next;

			ct++;

		}

	}


	bool contains(U elem) {

		Node<U>* aux = head;

		while (aux != NULL) {

			if (aux->data == elem) {

				return true;

			}

			aux = aux->next;

		}

		return false;

	}


	bool isEmpty() {

		if (head == NULL) {

			return true;

		}

		return false;

	}


	int indexOf(U elem) {

		Node<U>* aux = head;

		int i = 0;

		while (aux != NULL) {

			if (aux->data == elem) {

				return i;

			}

			aux = aux->next;

			i++;

		}

		return -1;

	}


	int size() {

		Node<U>* aux = head;

		int s = 0;

		while (aux != NULL) {

			s++;

			aux = aux->next;

		}

		return s;

	}


	U get(int index) {

		Node<U>* aux = head;

		int ct = 0;

		while (aux != NULL) {

			if (ct == index) {

				return aux->data;

			}

			aux = aux->next;

			ct++;

		}

	}


	void set(U elem, int index) {

		Node<U>* aux = head;

		int ct = 0;

		while (aux != NULL && ct != index) {

			aux = aux->next;

			ct++;

		}

		aux->data = elem;

	}

};









#endif // lista.h
