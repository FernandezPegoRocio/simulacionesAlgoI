#include "../include/Coche.h"

Coche::Coche() : Vehiculo(), motor(0) {
    std::cout << "Coche creado (constructor por defecto)" << std::endl;
}

Coche::Coche(const std::string& colorCoche, const std::string& marcaCoche, int motorCoche)
    : Vehiculo(colorCoche, marcaCoche), motor(motorCoche) {
    std::cout << "Coche " << marcaCoche << " con motor de " << motorCoche 
              << " cilindros creado" << std::endl;
}

Coche::~Coche() {
    std::cout << "Coche " << obtenerMarca() << " destruido" << std::endl;
}

void Coche::arrancar() {
    std::cout << "[COCHE " << obtenerMarca() << "] Encendiendo motor de " 
              << motor << " cilindros..." << std::endl;
    std::cout << "  -> Comprobando nivel de aceite..." << std::endl;
    std::cout << "  -> Activando sistema de inyeccion..." << std::endl;
    std::cout << "  -> Motor encendido. Coche listo para circular!" << std::endl;
}

void Coche::parar() {
    std::cout << "[COCHE " << obtenerMarca() << "] Apagando motor..." << std::endl;
    std::cout << "  -> Reduciendo revoluciones..." << std::endl;
    std::cout << "  -> Desactivando sistemas..." << std::endl;
    std::cout << "  -> Motor apagado. Coche detenido." << std::endl;
}

void Coche::repostar() {
    std::cout << "[COCHE " << obtenerMarca() << "] Repostando combustible..." << std::endl;
    std::cout << "  -> Abriendo tapa del deposito..." << std::endl;
    std::cout << "  -> Llenando deposito con gasolina 95..." << std::endl;
    std::cout << "  -> Deposito lleno. Capacidad: 50 litros" << std::endl;
}

void Coche::mostrarInformacion() {
    std::cout << "\n=== INFORMACION DEL COCHE ===" << std::endl;
    Vehiculo::mostrarInformacion();
    std::cout << "Tipo: Coche" << std::endl;
    std::cout << "Motor: " << motor << " cilindros" << std::endl;
    std::cout << "=============================" << std::endl;
}