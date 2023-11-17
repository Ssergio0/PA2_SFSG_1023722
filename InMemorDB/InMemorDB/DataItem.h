#pragma once
#include <string>
class DataItem
{
public:
	std::string originalKey;//llave original
	std::string hashedKey;//llave hasheada
	std::string data;
	DataItem* next;
	DataItem* prev;

	DataItem(std::string origigKey, std::string hashKey,std::string data);

};

