#pragma once
#include <string>
class HashFunction
{
public:
	//static unsigned long hash(const std::string& key);
	static std::string hashFunction(const std::string& key);
};

