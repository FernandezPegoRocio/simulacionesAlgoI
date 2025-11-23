#include "../include/Vehiculo.h"

Vehiculo::Vehiculo() : color("Sin color"), marca("Sin marca") {
    std::cout << "Vehiculo creado (constructor por defecto)" << std::endl;
}

Vehiculo::Vehiculo(const std::string& colorVehiculo, const std::string& marcaVehiculo) 
    : color(colorVehiculo), marca(marcaVehiculo) {
    std::cout << "Vehiculo " << marca << " de color " << color << " creado" << std::endl;
}

Vehiculo::~Vehiculo() {
    std::cout << "Vehiculo " << marca << " destruido" << std::endl;
}

void Vehiculo::mostrarInformacion() {
    std::cout << "Marca: " << marca << std::endl;
    std::cout << "Color: " << color << std::endl;
}