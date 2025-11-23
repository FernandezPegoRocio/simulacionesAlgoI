#include "Circulo.h"
#include <iomanip>

Circulo::Circulo() : Figura(0) {
    std::cout << "Circulo creado con radio 0" << std::endl;
}

Circulo::Circulo(float radio) : Figura(radio) {
    std::cout << "Circulo creado con radio " << radio << std::endl;
}

Circulo::~Circulo() {
    std::cout << "Destructor de Circulo llamado" << std::endl;
}

float Circulo::Perimetro() {
    return 2 * PI * x;
}

float Circulo::Area() {
    return PI * x * x;
}

void Circulo::mostrarInformacion() {
    std::cout << "\n==================================" << std::endl;
    std::cout << "       INFORMACION DEL CIRCULO" << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "Radio: " << obtenerRadio() << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Perimetro: " << Perimetro() << std::endl;
    std::cout << "Area: " << Area() << std::endl;
    std::cout << "==================================" << std::endl;
}

std::string Circulo::obtenerTipo() {
    return "Circulo";
}