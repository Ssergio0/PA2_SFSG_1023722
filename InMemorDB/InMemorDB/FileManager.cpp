// FileManager.cpp
#include "FileManager.h"
#include "HashFunction.h"
#include "DataItem.h"
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
        // Imprimir cada línea leída para depuración
        std::cout << "Línea leída: " << line << std::endl;

        if (line.empty()) {
            // Si la línea está vacía, la ignoramos
            continue;
        }

        std::stringstream ss(line);
        std::string originalKey, restOfData;
        getline(ss, originalKey, ',');
        getline(ss, restOfData); // Asumiendo que restOfData es el resto de la línea

        if (originalKey.empty() || restOfData.empty()) {
            // Si alguna parte esencial de los datos está vacía, la ignoramos
            continue;
        }

        unsigned long hash = HashFunction::hash(originalKey);
        std::string hashKey = std::to_string(hash).substr(0, 10);

        // Agregar el nuevo DataItem a la lista
        list.insertSorted(new DataItem(originalKey, hashKey, restOfData));
        count++; // Incrementar el contador solo si se agregó un DataItem
    }
    return count;
}
