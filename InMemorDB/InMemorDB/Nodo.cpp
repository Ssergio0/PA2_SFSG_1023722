#include "Nodo.h"

Nodo::Nodo(const FileManager& dato) : dato(dato), anterior(nullptr), siguiente(nullptr) {
}

FileManager Nodo::getDato() const {
    return dato;
}

Nodo* Nodo::getAnterior() const {
    return anterior;
}

Nodo* Nodo::getSiguiente() const {
    return siguiente;
}

void Nodo::setAnterior(Nodo* ant) {
    anterior = ant;
}

void Nodo::setSiguiente(Nodo* sig) {
    siguiente = sig;
}
