#include <iostream>

namespace RawList {
	struct ListElem {
		int val;
		ListElem* next{};
	};
	struct List
	{
		ListElem* head{};
	};

	//Dodaje na początek
	void Add(List& L, int val) {
		ListElem* newElem = new ListElem{ val, L.head };
		L.head = newElem;
	}
	void AddBack(List& L, int val) {
		ListElem* newElem = new ListElem{ val };
		if (!L.head) {
			L.head = newElem;
		}
		else {
			ListElem* current = L.head;
			while (current->next) {
				current = current->next;
			}
			current->next = newElem;
		}
	}


	void PrintBackward(ListElem* current) {
		if (!current) {
			return;
		}
		PrintBackward(current->next);
		std::cout << current->val << " ";
	}

	void PrintBackward(const List& L) {
		PrintBackward(L.head);
		std::cout << std::endl;
	}
	//Wyswietla
	void Print(const List& L) {
		ListElem* current = L.head;
		while (current) {
			std::cout << current->val << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}

	//Usuwa cala liste
	void RemoveAll(List& L) {
		while (L.head) {
			ListElem* temp = L.head;
			L.head = L.head->next;
			delete temp;
		}
	}
}

namespace UniquePtrList {
	struct ListElem {
		int val;
		std::unique_ptr<ListElem> next;
	};

	struct List {
		std::unique_ptr<ListElem> head;
	};

	// Dodaje na początek
	void Add(List& L, int val) {
		L.head = std::make_unique<ListElem>(ListElem{ val, std::move(L.head) });
	}
	void AddBack(List& L, int val) {
		ListElem* newElem = new ListElem{ val };
		if (!L.head) {
			L.head = std::unique_ptr<ListElem>(newElem);
		}
		else {
			ListElem* current = L.head.get();
			while (current->next) {
				current = current->next.get();
			}
			current->next = std::unique_ptr<ListElem>(newElem);
		}
	}
	void PrintBackward(ListElem* current) {
		if (!current) {
			return;
		}
		PrintBackward(current->next.get());
		std::cout << current->val << " ";
	}

	void PrintBackward(const List& L) {
		PrintBackward(L.head.get());
		std::cout << std::endl;
	}
	// Wyswietla
	void Print(const List& L) {
		ListElem* current = L.head.get();
		while (current) {
			std::cout << current->val << " ";
			current = current->next.get();
		}
		std::cout << std::endl;
	}

	// Usuwa cala liste
	void RemoveAll(List& L) {
		L.head.reset();
	}

}

int main() {
	//using namespace RawList;
	using namespace UniquePtrList; //odkomentować i zakomentować powyższe dla przełączenia się

	List L;
	AddBack(L, 3);
	AddBack(L, 2);
	AddBack(L, 1);
	PrintBackward(L); // powinno wyświetlić 1 2 3
	RemoveAll(L);
	PrintBackward(L); // powinno nic nie wyświetlić
}