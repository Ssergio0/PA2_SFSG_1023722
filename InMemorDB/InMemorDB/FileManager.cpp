#include "FileManager.h"
#include "HashFunction.h"
#include <fstream>
#include <sstream>

void FileManager::readFile(const std::string& filename, LinkedList& list) {
	std::ifstream file(filename);
	std::string line;

	while (std::getline(file,line))
	{
		std::stringstream ss(line);
		std::string key, data;
		getline(ss, key, ',');
		unsigned long hash = HashFunction::hash(key);
		std::string hashKey = std::to_string(hash).substr(0, 10);

		list.insertSorted(new DataItem(hashKey, line));
	}
}
