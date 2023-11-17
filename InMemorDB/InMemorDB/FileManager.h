#pragma once
#include "LinkedList.h"
#include <string>

class FileManager
{
public:
	static void readFile(const std::string& filename, LinkedList& list);
};

