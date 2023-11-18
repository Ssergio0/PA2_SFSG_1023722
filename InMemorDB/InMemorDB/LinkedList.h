#pragma once

#include "DataItem.h"
#include "DataRecord.h"
#include <memory>
#include <unordered_map>

class LinkedList
{
private:
	DataItem* head;
	DataItem* tail;
	

public:
	LinkedList();
	~LinkedList();

	void insertSorted(DataItem* newItem);
	DataItem* search(const std::string& key);
	std::vector<DataItem*>binarySearchByKey(const std:: string & keyTerm);
	std::vector<DataItem*>sequentialSearchByValue(const std::string& value);
};

