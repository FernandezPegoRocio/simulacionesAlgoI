#include "Cuadrado.h"
#include <iomanip>

Cuadrado::Cuadrado() : Figura(0) {
    std::cout << "Cuadrado creado con lado 0" << std::endl;
}

Cuadrado::Cuadrado(float lado) : Figura(lado) {
    std::cout << "Cuadrado creado con lado " << lado << std::endl;
}

Cuadrado::~Cuadrado() {
    std::cout << "Destructor de Cuadrado llamado" << std::endl;
}

float Cuadrado::Perimetro() {
    return 4 * x;
}

float Cuadrado::Area() {
    return x * x;
}

void Cuadrado::mostrarInformacion() {
    std::cout << "\n==================================" << std::endl;
    std::cout << "      INFORMACION DEL CUADRADO" << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "Lado: " << obtenerLado() << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Perimetro: " << Perimetro() << std::endl;
    std::cout << "Area: " << Area() << std::endl;
    std::cout << "==================================" << std::endl;
}

std::string Cuadrado::obtenerTipo() {
    return "Cuadrado";
}
