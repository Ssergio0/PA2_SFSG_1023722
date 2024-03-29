#pragma once
#include"LinkedList.h"
#include<string>

class FileManager {
private:
	LinkedList Registros;
	void mostrarRegistrosLlave(const std::string& keyHash, int initialIndex);
public:
	FileManager();
	void CargarDatos();
	void BusquedaLlave(const std::string& key);
	void BusquedaLlaveUsuario();
	void BusquedaValorUsuario();
	void busquedaValor(const std::string& valor);
};