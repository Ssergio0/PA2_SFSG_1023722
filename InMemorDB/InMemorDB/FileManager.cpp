#include "FileManager.h"
#include "HashFunction.h"
#include "DataItem.h"
#include"LinkedList.h"
#include <fstream>
#include <sstream>
#include <iostream>

int FileManager::readFile(const std::string& filename, LinkedList& list) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 0;
    }
    std::string line;
    int count = 0;

    while (std::getline(file, line)) {
        std::cout << "Línea leída: " << line << std::endl;

        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string originalKey, restOfData;
        getline(ss, originalKey, ',');
        getline(ss, restOfData);

        if (originalKey.empty() || restOfData.empty()) continue;

        std::string hashKey = HashFunction::hash(originalKey); // La función hash ahora devuelve std::string

        list.insertSorted(new DataItem(originalKey, hashKey, restOfData));
        count++;
    }
    return count;
}
