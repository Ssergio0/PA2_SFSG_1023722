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
	/*struct Node
	{
		std::unique_ptr<DataRecord> data;
		std::unique_ptr<Node>next;
		Node* prev;
	};
	Node(std::unique_ptr<DataRecord> dataValue, Node* prevNode, std::unique_ptr<Node> nextNode)
		: data(std::move(dataValue)), prev(prevNode), next(std::move(nextNode)) {}*/

public:
	LinkedList();
	~LinkedList();

	void insertSorted(DataItem* newItem);
	DataItem* search(const std::string& key);
	std::vector<DataItem*>binarySearchByKey(const std:: string & keyTerm);
	std::vector<DataItem*>sequentialSearchByValue(const std::string& value);
};

