#include "Figura.h"

Figura::Figura() : x(0) {
    std::cout << "Constructor de Figura llamado" << std::endl;
}

Figura::Figura(float valorX) : x(valorX) {
    std::cout << "Constructor de Figura con parametro llamado" << std::endl;
}

Figura::~Figura() {
    std::cout << "Destructor de Figura llamado" << std::endl;
}

void Figura::mostrarInformacion() {
    std::cout << "Tipo de figura: " << obtenerTipo() << std::endl;
    std::cout << "Valor del atributo x: " << x << std::endl;
}