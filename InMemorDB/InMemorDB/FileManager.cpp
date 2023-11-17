#include "FileManager.h"
#include "HashFunction.h"
#include <fstream>
#include <sstream>
#include <iostream>

void FileManager::readFile(const std::string& filename, LinkedList& list) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error al abrir el archivo " << std::endl;
        return;  // Agregando un return para evitar procesar m�s c�digo si el archivo no se abre
    }
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string originalKey, data;
        getline(ss, originalKey, ','); // Esto extraer� la llave primaria

        unsigned long hash = HashFunction::hash(originalKey);
        std::string hashKey = std::to_string(hash).substr(0, 10);

        // Correcci�n: pasar originalKey, hashKey y la l�nea entera (data)
        list.insertSorted(new DataItem(originalKey, hashKey, line));
    }
}
