#include <iostream>
#include <vector>
#include <cstdio>      // popen, fgets
#include <cstdlib>
#include <sstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " ./creacionNumeros [opciones]" << std::endl;
        return 1;
    }

    // Construir el comando
    std::string comando = argv[1];
    for (int i = 2; i < argc; ++i) {
        comando += " ";
        comando += argv[i];
    }

    FILE* pipe = popen(comando.c_str(), "r");
    if (!pipe) {
        std::cerr << "Error al ejecutar el comando" << std::endl;
        return 1;
    }

    char buffer[1024];
    std::string salida_total;
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        salida_total += buffer;
    }

    pclose(pipe);

    std::istringstream iss(salida_total);
    std::vector<std::vector<int>> listas;

    while (iss) {
        int n;
        iss >> n;
        if (!iss) break; // Si ya no se puede leer más

        std::vector<int> lista(n);
        for (int i = 0; i < n; ++i) {
            if (!(iss >> lista[i])) {
                std::cerr << "Error leyendo lista de tamaño " << n << std::endl;
                return 1;
            }
        }
        listas.push_back(lista);
    }

    // Mostrar todas las listas
    for (size_t i = 0; i < listas.size(); ++i) {
        std::cout << std::endl << "Lista " << i + 1 << ": ";
        for (int num : listas[i]) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


