#include "FileManager.h"
#include "HashFunction.h"
#include <fstream>
#include <sstream>
#include <iostream>

void FileManager::readFile(const std::string& filename, LinkedList& list) {
	std::ifstream file(filename);
	if (!file)
	{
		std::cout << "Error al abrir el archivo " << std::endl;
	}
	std::string line;

	while (std::getline(file,line))
	{
		std::stringstream ss(line);
		std::string key, data;
		getline(ss, key, ',');//Esto extraerá la key primaria

		unsigned long hash = HashFunction::hash(key);
		std::string hashKey = std::to_string(hash).substr(0, 10);

		list.insertSorted(new DataItem(hashKey, line));	
	}
}
