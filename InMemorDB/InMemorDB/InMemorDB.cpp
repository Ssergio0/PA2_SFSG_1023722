// InMemorDB.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include"FileManager.h"
#include"LinkedList.h"
#include<string>

void printMenu() {
    std::cout << "==============GESTIÓN DE DATOS===============" << std::endl;
    std::cout << "1. Cargar Datos desde archivo." << std::endl;
    std::cout << "2. Buscar Datos." << std::endl;
    std::cout << "3.Salir" << std::endl;
    std::cout << "Seleccione una opcion:";
}

void loadData(LinkedList& list) {
    std::string filename;
    std::cout << "Ingrese el nombre del archivo de datos: ";
    std::cin >> filename;

    FileManager::readFile(filename, list);
    std::cout << "Datos cargados correctamente." << std::endl;
}

void searchData(LinkedList& list) {
    std::string key;
    std::cout << "Ingrese la llave de búsqueda: ";
    std::cin >> key;

    DataItem* item = list.search(key);
    if (item) 
        std::cout << "Datos Encontrados: " << item->data << std::endl;
    else 
        std::cout << "No se encontraron datos para la llave: " << key << std::endl;
}
int main()
{
    LinkedList list;
    int opcion;

    while (true)
    {
        printMenu();
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            loadData(list);
            break;
        case 2:
            searchData(list);
            break;
        case 3:
            std::cout << "Saliendo del programa." << std::endl;
            return 0;
        default:
            std::cout << "Opcion no valida. Intente de nuevo" << std::endl;
        }
    }
}
