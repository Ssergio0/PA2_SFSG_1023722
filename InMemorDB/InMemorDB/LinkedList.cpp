#include "LinkedList.h"

LinkedList::LinkedList() :head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {
	DataItem* current = head;
	while (current != nullptr)
	{
		DataItem* next = current->next;
		delete current;
		current = next;
	}
}
void LinkedList::insertSorted(DataItem* newItem) {
	if (!head || newItem->keyPrimary < head->keyPrimary)
	{
		if (head) head->prev = newItem;
		newItem->next = head;
		head = newItem;
		return;
	}
	
	DataItem* current = head;
	while (current->next && current->next->keyPrimary < newItem->keyPrimary) 
		current = current->next;

	newItem->next = current->next;
	newItem->prev = current;
	if (current->next)
		current->next->prev = newItem;
	tail = newItem;
	current->next = newItem;
}

DataItem* LinkedList::search(const std::string& key) {
	DataItem* current = head;
	while (current && current->keyPrimary != key)
		current = current->next;
	return current;
}
