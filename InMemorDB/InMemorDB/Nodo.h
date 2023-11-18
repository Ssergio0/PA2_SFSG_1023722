#pragma once
#include"DataItem.h"
class Nodo
{
private:
	DataItem dato;
	Nodo* anterior;
	Nodo* siguiente;

public:
	Nodo(const DataItem& dato);
	DataItem getDato()const;
	Nodo* getAnterior()const;
	Nodo* getSiguiente()const;
	void setAnterior(Nodo* ant);
	void setSiguiente(Nodo* sig);
};

