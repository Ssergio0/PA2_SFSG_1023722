#include<iostream>
#include<sstream>
#include<fstream>
#include"FileManager.h"
#include"HashFunction.h"

FileManager::FileManager() {

}

/*void FileManager::CargarDatos() {
	std::cout << "Ingrese la Ruta del .txt que se desea leer: ";
	std::string ruta_archivo;
	std::getline(std::cin, ruta_archivo);

	// Verificar si el archivo existe
	std::ifstream file(ruta_archivo);
	if (!file) {
		std::cerr << "Error. No se pudo abrir el archivo en la ruta: " << ruta_archivo << std::endl;
		return;
	}
	else {
		std::cout << "Archivo abierto correctamente." << std::endl;
	}

	// Leer y mostrar cada línea del archivo
	std::string linea;
	int contadorLineas = 0;
	while (std::getline(file, linea)) {
		//std::cout << "Leyendo línea: " << linea << std::endl;
		contadorLineas++;
	}
	
	file.close();
	std::cout << "Total de líneas leídas: " << contadorLineas << std::endl;
}*/


void FileManager::CargarDatos() {
	std::cout << "Ingrese la Ruta del .txt que se desea leer: ";
	std::string ruta_archivo;
	std::getline(std::cin, ruta_archivo);

	std::ifstream file(ruta_archivo, std::ifstream::ate | std::ifstream::binary);
	if (!file) {
		std::cerr << "Error. No se pudo abrir el archivo: " << ruta_archivo << std::endl;
		return;
	}

	// Determinar el tamaño del archivo
	std::streamsize size = file.tellg();
	file.seekg(0, std::ios::beg);

	// Definir el tamaño de bloque basado en el tamaño del archivo
	size_t blockSize = (size > 10000000) ? 10000 : 100; // Por ejemplo, 10,000 líneas para archivos grandes, 100 para pequeños

	std::string linea;
	std::vector<std::string> bloque;
	while (std::getline(file, linea)) {
		bloque.push_back(linea);
		if (bloque.size() >= blockSize) {
			// Procesar bloque de líneas aquí...
			bloque.clear();
		}
	}

	// Procesar el último bloque si no está vacío
	if (!bloque.empty()) {
		// Procesar bloque de líneas aquí...
	}

	file.close();
	std::cout << "Archivo procesado exitosamente." << std::endl;
}


void FileManager::BusquedaLlaveUsuario() {
	std::string key;
	std::cout << "Ingrese el termino de llave para poder buscar: ";
	std::getline(std::cin, key);
	BusquedaLlave(key);
}
void FileManager::BusquedaLlave(const std::string& key) {
	std::string keyHash = HashFunction::hashFunction(key);
	std::cout << "Buscando el hash: " << keyHash << std::endl;

	int start = 0;
	int end = Registros.getLongitud() - 1;
	bool foundit = false;
	while (start <= end) {
		int middle = start + (end - start) / 2;
		Nodo* middleNode = Registros.getNodoEnIndex(middle);
		if (middleNode == nullptr) break;
		std::string middleKey = HashFunction::hashFunction(middleNode->getDato().getPrimaryKey());
		std::cout << "Se está comparando con hash en la mitad: " << middleKey << std::endl;

		if (middleKey < keyHash) {
			start = middle + 1;
		}
		else if (middleKey > keyHash) { end = middle - 1; }
		else {
			foundit = true;
			mostrarRegistrosLlave(keyHash, middle);
			break;
		}
		
		if (!foundit)
			std::cout << "No se ha podido encontrar registros con la llave solicitada: " << key << std::endl;
	}
}

void FileManager::mostrarRegistrosLlave(const std::string& keyHash, int startIndex) {
	Nodo* actual = Registros.getNodoEnIndex(startIndex);

	while (actual != nullptr) {
		std::string actualKeyHash = HashFunction::hashFunction(actual->getDato().getPrimaryKey());
		if (actualKeyHash == keyHash) {
			actual->getDato().showData();
		}
		actual = actual->getSiguiente();
	}
}
void FileManager::BusquedaValorUsuario() {
	std::string valor;
	std::cout << "Ingrese el valor que quiere ver para buscarlo: ";
	std::getline(std::cin, valor);
	busquedaValor(valor);
}

void FileManager::busquedaValor(const std::string& valor) {
	Nodo* actual = Registros.getHead(); // Asegúrate de que getHead() sea un método público en LinkedList
	bool foundit = false;

	while (actual != nullptr) {
		const DataItem& registro = actual->getDato();

		if (registro.searchSequentialValue(valor)) {
			registro.showData();
			foundit = true;
		}
		actual = actual->getSiguiente();
	}

	if (!foundit) {
		std::cout << "No se han podido encontrar registros con el valor solicitado: " << valor << std::endl;
	}
}
