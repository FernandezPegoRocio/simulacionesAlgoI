#include "../include/Moto.h"

Moto::Moto() : Vehiculo(), cilindrada(0) {
    std::cout << "Moto creada (constructor por defecto)" << std::endl;
}

Moto::Moto(const std::string& colorMoto, const std::string& marcaMoto, int cilindradaMoto)
    : Vehiculo(colorMoto, marcaMoto), cilindrada(cilindradaMoto) {
    std::cout << "Moto " << marcaMoto << " de " << cilindradaMoto 
              << "cc creada" << std::endl;
}

Moto::~Moto() {
    std::cout << "Moto " << obtenerMarca() << " destruida" << std::endl;
}

void Moto::arrancar() {
    std::cout << "[MOTO " << obtenerMarca() << "] Encendiendo motor de " 
              << cilindrada << "cc..." << std::endl;
    std::cout << "  -> Activando bomba de combustible..." << std::endl;
    std::cout << "  -> Comprobando presion de neumaticos..." << std::endl;
    std::cout << "  -> Motor encendido. Moto lista para rodar!" << std::endl;
}

void Moto::parar() {
    std::cout << "[MOTO " << obtenerMarca() << "] Apagando motor..." << std::endl;
    std::cout << "  -> Cortando inyeccion..." << std::endl;
    std::cout << "  -> Activando freno motor..." << std::endl;
    std::cout << "  -> Motor apagado. Moto detenida." << std::endl;
}

void Moto::repostar() {
    std::cout << "[MOTO " << obtenerMarca() << "] Repostando combustible..." << std::endl;
    std::cout << "  -> Abriendo tapa del deposito..." << std::endl;
    std::cout << "  -> Llenando deposito con gasolina 98..." << std::endl;
    std::cout << "  -> Deposito lleno. Capacidad: 15 litros" << std::endl;
}

void Moto::mostrarInformacion() {
    std::cout << "\n=== INFORMACION DE LA MOTO ===" << std::endl;
    Vehiculo::mostrarInformacion();
    std::cout << "Tipo: Moto" << std::endl;
    std::cout << "Cilindrada: " << cilindrada << "cc" << std::endl;
    std::cout << "==============================" << std::endl;
}