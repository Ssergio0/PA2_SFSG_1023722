
#include "HashFunction.h"

std::string HashFunction::hashFunction(const std::string& key) {
    unsigned long hash = 0;
    for (char c : key) {
        hash = (hash * 31) + c; // Usando 31 como base para la dispersi�n
    }

    std::string hashStr = std::to_string(hash);
    while (hashStr.length() < 10) {
        hashStr = "0" + hashStr; // Rellenar con ceros si es m�s corto
    }

    return hashStr.substr(0, 10); // Asegurar que el hash tenga exactamente 10 caracteres
}
