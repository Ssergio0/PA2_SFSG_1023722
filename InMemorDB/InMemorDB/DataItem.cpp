#include "FileManager.h"
#include "HashFunction.h"
#include "DataItem.h"
#include"LinkedList.h"
#include <fstream>
#include <sstream>
#include <iostream>

DataItem::DataItem(const std::string& linea) {
	std::istringstream stream(linea);
	std::string elemento;
	std::getline(stream, primaryKey, ',');
	while (std::getline(stream, elemento, ',') && stream.peek() != '\n') { datos.push_back(elemento); }
	std::getline(stream, nextKey);
}
bool DataItem::searchSequentialValue(const std::string& valor)const {
	for (const auto& dato : datos) {
		if (dato == valor)
			return true;
	}
	return false;
}

std::string DataItem::getPrimaryKey()const {
	return primaryKey;
}
std::string DataItem::getNextKey()const {
	return nextKey;
}
void DataItem::showData()const {
	std::cout << "Llave Principal: " << primaryKey << std::endl;
	std::cout << "Datos: ";
	for (const auto& dato : datos)std::cout << dato << " ";
}

