#pragma once

#include "DataRecord.h"
#include <memory>
#include <unordered_map>

class LinkedList
{
private:
	struct Node
	{
		std::unique_ptr<DataRecord> data;
		std::unique_ptr<Node>next;
		Node* prev;
	};
	/*Node(std::unique_ptr<DataRecord> dataValue, Node* prevNode, std::unique_ptr<Node> nextNode)
		: data(std::move(dataValue)), prev(prevNode), next(std::move(nextNode)) {}*/
};

