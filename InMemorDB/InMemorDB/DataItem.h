#pragma once
#include <string>
class DataItem
{
public:
	std::string keyPrimary;
	std::string data;
	DataItem* next;
	DataItem* prev;

};

