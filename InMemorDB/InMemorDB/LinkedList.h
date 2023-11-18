#pragma once

#include "DataItem.h"
#include "DataRecord.h"
#include "Nodo.h"
#include <memory>
#include <unordered_map>

class LinkedList
{
private:
	Nodo* head;
	Nodo* tail;
	int longitud;
	

public:
	LinkedList();
	~LinkedList();

	void insertar(const DataItem& FileManager);
	Nodo* search(const std::string& key)const;
	void erase(const std::string& key);
	int getLongitud()const;
	Nodo* getNodoEnIndex(int index)const;
	Nodo* getHead()const;


	void insertSorted(DataItem* newItem);
	DataItem* search(const std::string& key);
	std::vector<DataItem*>binarySearchByKey(const std:: string & keyTerm);
	std::vector<DataItem*>sequentialSearchByValue(const std::string& value);
};

