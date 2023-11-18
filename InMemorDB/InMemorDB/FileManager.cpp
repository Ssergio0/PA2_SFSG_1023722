#include<iostream>
#include<sstream>
#include<fstream>
#include"FileManager.h"
#include"HashFunction.h"

FileManager::FileManager() {

}
void FileManager::CargarDatos() {
	std::string ruta_archivo;
	std::cout << "Ingrese la Ruta del .txt que se desea leer: ";
	std::getline(std::cin, ruta_archivo);
	std::ifstream file(ruta_archivo);
	if (!file) {
		std::cerr << "Error. No se pudo abrir el archivo." << std::endl;
		return;
	}
	std::string linea;
	while (std::getline(file, linea)) {
		FileManager registro(linea);
		std::string keyHash = HashFunction::hashFunction(registro.getPrimaryKey());
		registro.insertar(registro);
	}
	file.close();
	std::cout << "Datos cargados de forma exitosa: " << ruta_archivo << std::endl;
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

	while (actual != nullptr && HashFunction::hashFunction(actual->getDato().getPrimaryKey() == keyHash) {
		actual->getDato().mostrarDatos();
		actual = actual->getSiguiente();
	}
}
void FileManager::BusquedaValorUsuario() {
	std::string valor;
	std::cout << "Ingrese el valor que quiere ver para buscarlo: ";
	std::getline(std::cin, valor);
	BusquedaValor(valor);
}

void FileManager::busquedaValor(const std::string& valor) {
	Nodo* actual = Registros.getHead();
	bool foundit = false;
	while (actual != nullptr) {
		const FileManager& registro = actual->getDato();

		if (registro.searchSequentialValue(const std::string & valor)const) {
			registro.showData();
			foundit = true;
		}
		actual = actual - getSiguiente();
	}
	if (!foundit) {
		std::cout << "No se han podido encontrar registros con el valor solicitado: " << valor << std::endl;
	}
}