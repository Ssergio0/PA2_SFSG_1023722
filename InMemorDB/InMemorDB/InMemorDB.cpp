// InMemorDB.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//C:\Users\Sergio Salguero\OneDrive\Histórico\Desktop\PA2_SFSG_1023722\list.txt

#include <iostream>
#include"FileManager.h"
#include"LinkedList.h"
#include<string>

void printMenu() {
    std::cout << "==============GESTION DE DATOS===============" << std::endl;
    std::cout << "1. Cargar Datos desde archivo." << std::endl;
    std::cout << "2. Buscar Datos por Llave." << std::endl;
    std::cout << "3. Buscar Datos por Valor" << std::endl;
    std::cout << "4. Salir" << std::endl;
    std::cout << "Seleccione una opcion:";
}

void loadData(LinkedList& list) {
    std::string filename;
    std::cout << "Ingrese el nombre del archivo de datos: ";
    std::cin >> filename;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Linea que limpiará el búfer de entrada

    FileManager::readFile(filename, list);
    std::cout << "Datos cargados correctamente." << std::endl;
}

/*void searchData(LinkedList& list) {
    std::string key;
    std::cout << "Ingrese la llave de busqueda: ";
    std::cin >> key;

    DataItem* item = list.search(key);
    if (item) 
        std::cout << "Datos Encontrados: " << item->data << std::endl;
    else 
        std::cout << "No se encontraron datos para la llave: " << key << std::endl;
}*/

void searchByKey(LinkedList& list) {
    std::string keyTerm;
    std::cout << "Ingrese el termino de la llave a buscar: ";
    std::cin >> keyTerm;

    std::vector<DataItem*>results = list.binarySearchByKey(keyTerm);
    for (auto& item : results)
        std::cout << item->data << std::endl;
}

void searchByValue(LinkedList& list) {
    std::string value;
    std::cout << "Ingrese el valor a buscar: ";
    std::cin >> value;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<DataItem*>results = list.sequentialSearchByValue(value);
    for (auto& item : results)
        std::cout << item->data << std::endl;
}
int main()
{
    LinkedList list;
    int opcion;

    while (true)
    {
        printMenu();
        std::cin >> opcion;
        if (std::cin.fail())
        {
            std::cin.clear();//limpia el estado del error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//descarta la linea incorrecta
            std::cout << "Entrada Inválida, porfavor, intente de nuevo." << std::endl;
            continue;
        }

        switch (opcion)
        {
        case 1:
            loadData(list);
            break;
        case 2:
            searchByKey(list);
            break;
        case 3:
            searchByValue(list);
            break;
        case 4:
            std::cout << "Saliendo del programa." << std::endl;
            return 0;
        default:
            std::cout << "Opcion no valida. Intente de nuevo" << std::endl;
            
        }
    }
}
