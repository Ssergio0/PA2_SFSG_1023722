#include "LinkedList.h"
#include"HashFunction.h"
#include<iostream>

LinkedList::LinkedList() :head(nullptr), tail(nullptr), longitud(0) {}

LinkedList::~LinkedList() {
	Nodo* current = head;
	while (current != nullptr)
	{
		Nodo* next = current->getSiguiente();
		delete current;
		current = next;
	}
}

void LinkedList::insertar(const DataItem& dataItem) {
    Nodo* nuevo = new Nodo(dataItem);
    std::string keyNewHash = HashFunction::hashFunction(dataItem.getPrimaryKey());

    if (head == nullptr) {
        head = nuevo;
        tail= nuevo;
    }
    else {
        Nodo* current = head;
        std::string keyCurrentHash;
        while (current != nullptr) {
            keyCurrentHash = HashFunction::hashFunction(current->getDato().getPrimaryKey());
            if (keyCurrentHash > keyNewHash)
                break;
        }
        current = current->getSiguiente();
        if (current == nullptr) { 
            tail->setSiguiente(nuevo);
            nuevo->setAnterior(tail);
            head = nuevo;
        }
        else if (current == head) {
            nuevo->setSiguiente(head);
            head->setAnterior(nuevo);
            head = nuevo;
        }
        else { 
            nuevo->setSiguiente(current);
            nuevo->setAnterior(current->getAnterior());
            current->getAnterior()->setSiguiente(nuevo);
            current->setAnterior(nuevo);
        }
    }
    longitud++;
}
    



Nodo* LinkedList::search(const std::string& llave) const {
    Nodo* current = head;
    while (current != nullptr) {
        if (current->getDato().getPrimaryKey() == llave) {
            return current;
        }
        current = current->getSiguiente();
    }
    return nullptr;
}

void LinkedList::erase(const std::string& llave) {
    Nodo* current = head;
    while (current != nullptr) {
        if (current->getDato().get.PrimaryKey() == llave) {
            if (current == head) {
                head = head->getSiguiente();
                if (head != nullptr) {
                    head->setAnterior(nullptr);
                }
            }
            else if (current == tail) {
                head = head->getAnterior();
                if (tail != nullptr) {
                    tail->setSiguiente(nullptr);
                }
            }
            else {
                current->getAnterior()->setSiguiente(current->getSiguiente());
                current->getSiguiente()->setAnterior(current->getAnterior());
            }
            delete current;
            longitud--;
            return;
        }
        current = current->getSiguiente();
    }
}
int LinkedList::getLongitud() const {
    return longitud; // Asumiendo que tienes un atributo 'longitud' que lleva la cuenta de la longitud de la lista
}

Nodo* LinkedList::getNodoEnIndex(int indice) const {
    if (indice < 0 || indice >= longitud) {
        return nullptr;
    }
    Nodo* current = head;
    for (int i = 0; i < indice; ++i) {
        current = current->getSiguiente();
    }
    return current;
}

Nodo* LinkedList::getHead() const {
    return head;
}