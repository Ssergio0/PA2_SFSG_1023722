// InMemorDB.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//C:\Users\Sergio Salguero\OneDrive\Histórico\Desktop\PA2_SFSG_1023722\list.txt
//C:\Users\Sergio Salguero\Downloads\InMemoryDB\InMemoryDB\list_prueba.txt
#include "FileManager.h"
#include <iostream>
#include <string>

int main() {
    FileManager gestorDatos;
    int opcion = 0;

    while (true) {
        std::cout << "\n--- Sistema de Gestion de Datos ---\n";
        std::cout << "1. Cargar Datos desde Archivo\n";
        std::cout << "2. Buscar Datos por Llave\n";
        std::cout << "3. Buscar Datos por Valor\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        // Limpieza del buffer de entrada
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
        case 1:
            gestorDatos.CargarDatos();
            break;
        case 2:
            gestorDatos.BusquedaLlaveUsuario();
            break;
        case 3:
            gestorDatos.BusquedaValorUsuario();
            break;
        case 4:
            std::cout << "Finalizando el programa...\n";
            return 0;
        default:
            std::cout << "Opcion no válida. Por favor, intente nuevamente.\n";
        }
    }

    return 0;
}
