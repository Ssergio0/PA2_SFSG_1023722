#pragma once
#include"FileManager.h"
class Nodo
{
private:
	FileManager dato;
	Nodo* anterior;
	Nodo* siguiente;

public:
	Nodo(const FileManager& dato);
	FileManager getDato()const;
	Nodo* getAnterior()const;
	Nodo* getSiguiente()const;
	void setAnterior(Nodo* ant);
	void setSiguiente(Nodo* sig);
};

