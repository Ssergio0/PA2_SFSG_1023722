#include "LinkedList.h"
#include"HashFunction.h"

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
    if (!newItem) return; // Si newItem es nulo, no hacemos nada

    // Si la lista está vacía o el nuevo elemento va antes del primer elemento
    if (!head || newItem->hashedKey < head->hashedKey) {
        newItem->next = head; // El siguiente del nuevo elemento será el antiguo primer elemento
        if (head) {
            head->prev = newItem; // Si la lista no estaba vacía, actualizamos el anterior del antiguo primer elemento
        }
        head = newItem; // El nuevo elemento es ahora el primer elemento
        if (!tail) {
            tail = newItem; // Si la lista estaba vacía, el nuevo elemento es también el último elemento
        }
        return;
    }

    // Si el nuevo elemento va después del último elemento
    if (newItem->hashedKey >= tail->hashedKey) {
        tail->next = newItem; // El siguiente del último elemento será el nuevo elemento
        newItem->prev = tail; // El anterior del nuevo elemento será el antiguo último elemento
        tail = newItem; // El nuevo elemento es ahora el último elemento
        return;
    }

    // En cualquier otro caso, buscamos el lugar donde insertar el nuevo elemento
    DataItem* current = head;
    while (current->next && current->next->hashedKey < newItem->hashedKey) {
        current = current->next; // Avanzamos hasta encontrar donde insertar el nuevo elemento
    }

    // Insertamos el nuevo elemento en su lugar correcto
    newItem->next = current->next; // El siguiente del nuevo elemento será el siguiente del elemento actual
    if (current->next) {
        current->next->prev = newItem; // Actualizamos el anterior del siguiente elemento, si existe
    }
    current->next = newItem; // El siguiente del elemento actual es ahora el nuevo elemento
    newItem->prev = current; // El anterior del nuevo elemento es el elemento actual
}

DataItem* LinkedList::search(const std::string& key) {
	DataItem* current = head;
	while (current && current->originalKey != key)
		current = current->next;
	return current;
}

std::vector<DataItem*> LinkedList::binarySearchByKey(const std::string& keyTerm) {
	std::vector<DataItem*> results;
	DataItem* current = head;

	while (current != nullptr) {
		if (current->originalKey.find(keyTerm) == 0) {
			results.push_back(current);
		}
		current = current->next;
	}
	return results;
}


std::vector<DataItem*>LinkedList::sequentialSearchByValue(const std::string& value) {
	std::vector<DataItem*>results;
	DataItem* current = head;
	while (current != nullptr) {
		if (current->data == value)
			results.push_back(current);
		current = current->next;
	}
	return results;
}
