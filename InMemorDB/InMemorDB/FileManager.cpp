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
        std::cout << "Error al abrir el archivo." << std::endl;
        return 0; // Devuelve 0 para indicar que no se cargaron datos
    }
    std::string line;
    int count = 0; // Contador de líneas cargadas

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string originalKey, restOfData;
        getline(ss, originalKey, ','); // Extrae la llave primaria

        unsigned long hash = HashFunction::hash(originalKey);
        std::string hashKey = std::to_string(hash).substr(0, 10);

        // Asume que restOfData contiene el resto de la línea después de la llave primaria
        getline(ss, restOfData); // Extrae el resto de los datos

        list.insertSorted(new DataItem(originalKey, hashKey, restOfData));
        ++count; // Incrementa el contador por cada DataItem cargado
    }
    return count; // Devuelve el número de líneas cargadas
}
