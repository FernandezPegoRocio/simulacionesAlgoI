#include "../include/Taller.h"
#include <typeinfo>

Taller::Taller() : maximoVehiculos(MAXIMO_VEHICULOS), numeroVehiculos(0) {
    for (int i = 0; i < MAXIMO_VEHICULOS; i++) {
        vehiculos[i] = nullptr;
    }
    std::cout << "Taller creado con capacidad para " << maximoVehiculos 
              << " vehiculos" << std::endl;
}

Taller::Taller(int capacidadMaxima) 
    : maximoVehiculos(capacidadMaxima > MAXIMO_VEHICULOS ? MAXIMO_VEHICULOS : capacidadMaxima), 
      numeroVehiculos(0) {
    for (int i = 0; i < MAXIMO_VEHICULOS; i++) {
        vehiculos[i] = nullptr;
    }
    std::cout << "Taller creado con capacidad personalizada para " 
              << maximoVehiculos << " vehiculos" << std::endl;
}

Taller::~Taller() {
    std::cout << "\nCerrando taller y liberando memoria..." << std::endl;
    for (int i = 0; i < numeroVehiculos; i++) {
        vehiculos[i] = nullptr;
    }
    std::cout << "Taller cerrado correctamente" << std::endl;
}

void Taller::meter(Vehiculo* vehiculo) {
    if (numeroVehiculos < maximoVehiculos) {
        vehiculos[numeroVehiculos] = vehiculo;
        numeroVehiculos++;
        
        std::cout << "\n>>> Vehiculo " << vehiculo->obtenerMarca() 
                  << " ingresado al taller" << std::endl;
        std::cout << "    Posicion en taller: " << numeroVehiculos << std::endl;
        std::cout << "    Espacios disponibles: " << (maximoVehiculos - numeroVehiculos) 
                  << std::endl;
    } else {
        std::cout << "\n!!! ERROR: Taller lleno. No se puede ingresar el vehiculo " 
                  << vehiculo->obtenerMarca() << std::endl;
    }
}

void Taller::arreglarVehiculos() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "   ARREGLANDO TODOS LOS VEHICULOS" << std::endl;
    std::cout << "========================================" << std::endl;
    
    if (numeroVehiculos == 0) {
        std::cout << "No hay vehiculos en el taller para arreglar." << std::endl;
        return;
    }
    
    for (int i = 0; i < numeroVehiculos; i++) {
        if (vehiculos[i] != nullptr) {
            std::cout << "\n[" << (i+1) << "/" << numeroVehiculos 
                      << "] Trabajando en vehiculo:" << std::endl;
            
            vehiculos[i]->mostrarInformacion();
            
            std::cout << "\nProceso de reparacion:" << std::endl;
            std::cout << "------------------------" << std::endl;
            
            vehiculos[i]->arrancar();
            
            std::cout << "\n  -> Realizando diagnostico..." << std::endl;
            std::cout << "  -> Reparando componentes..." << std::endl;
            std::cout << "  -> Cambiando aceite y filtros..." << std::endl;
            
            vehiculos[i]->repostar();
            
            vehiculos[i]->parar();
            
            std::cout << "\n  ✓ Vehiculo reparado exitosamente!" << std::endl;
            std::cout << "========================================" << std::endl;
        }
    }
    
    std::cout << "\n*** TODOS LOS VEHICULOS HAN SIDO REPARADOS ***" << std::endl;
}

void Taller::arreglarCoches() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "      ARREGLANDO SOLO COCHES" << std::endl;
    std::cout << "========================================" << std::endl;
    
    int cochesArreglados = 0;
    
    for (int i = 0; i < numeroVehiculos; i++) {
        if (vehiculos[i] != nullptr) {
            // Usar dynamic_cast para verificar si es un Coche
            Coche* coche = dynamic_cast<Coche*>(vehiculos[i]);
            if (coche != nullptr) {
                cochesArreglados++;
                std::cout << "\nArreglando coche #" << cochesArreglados << ":" << std::endl;
                
                coche->mostrarInformacion();
                
                std::cout << "\nProceso de reparacion del coche:" << std::endl;
                std::cout << "----------------------------------" << std::endl;
                
                coche->arrancar();
                std::cout << "  -> Revisando sistema de frenos..." << std::endl;
                std::cout << "  -> Alineando direccion..." << std::endl;
                std::cout << "  -> Balanceando ruedas..." << std::endl;
                coche->repostar();
                coche->parar();
                
                std::cout << "  ✓ Coche reparado!" << std::endl;
            }
        }
    }
    
    if (cochesArreglados == 0) {
        std::cout << "No hay coches en el taller para arreglar." << std::endl;
    } else {
        std::cout << "\nTotal de coches arreglados: " << cochesArreglados << std::endl;
    }
}

void Taller::arreglarMotos() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "       ARREGLANDO SOLO MOTOS" << std::endl;
    std::cout << "========================================" << std::endl;
    
    int motosArregladas = 0;
    
    for (int i = 0; i < numeroVehiculos; i++) {
        if (vehiculos[i] != nullptr) {
            // Usar dynamic_cast para verificar si es una Moto
            Moto* moto = dynamic_cast<Moto*>(vehiculos[i]);
            if (moto != nullptr) {
                motosArregladas++;
                std::cout << "\nArreglando moto #" << motosArregladas << ":" << std::endl;
                
                moto->mostrarInformacion();
                
                std::cout << "\nProceso de reparacion de la moto:" << std::endl;
                std::cout << "----------------------------------" << std::endl;
                
                moto->arrancar();
                std::cout << "  -> Ajustando cadena de transmision..." << std::endl;
                std::cout << "  -> Revisando embrague..." << std::endl;
                std::cout << "  -> Calibrando carburador..." << std::endl;
                moto->repostar();
                moto->parar();
                
                std::cout << "  ✓ Moto reparada!" << std::endl;
            }
        }
    }
    
    if (motosArregladas == 0) {
        std::cout << "No hay motos en el taller para arreglar." << std::endl;
    } else {
        std::cout << "\nTotal de motos arregladas: " << motosArregladas << std::endl;
    }
}

void Taller::listarVehiculos() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "    INVENTARIO DE VEHICULOS EN TALLER" << std::endl;
    std::cout << "========================================" << std::endl;
    
    if (numeroVehiculos == 0) {
        std::cout << "El taller esta vacio." << std::endl;
    } else {
        int numeroCoches = 0;
        int numeroMotos = 0;
        
        for (int i = 0; i < numeroVehiculos; i++) {
            if (vehiculos[i] != nullptr) {
                std::cout << "\nPosicion " << (i+1) << ":" << std::endl;
                vehiculos[i]->mostrarInformacion();
                
                // Contar tipos de vehículos
                if (dynamic_cast<Coche*>(vehiculos[i]) != nullptr) {
                    numeroCoches++;
                } else if (dynamic_cast<Moto*>(vehiculos[i]) != nullptr) {
                    numeroMotos++;
                }
            }
        }
        
        std::cout << "\n--- RESUMEN ---" << std::endl;
        std::cout << "Total vehiculos: " << numeroVehiculos << std::endl;
        std::cout << "Coches: " << numeroCoches << std::endl;
        std::cout << "Motos: " << numeroMotos << std::endl;
        std::cout << "Espacios libres: " << (maximoVehiculos - numeroVehiculos) << std::endl;
    }
    
    std::cout << "========================================" << std::endl;
}

void Taller::mostrarEstadisticasTaller() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "      ESTADISTICAS DEL TALLER" << std::endl;
    std::cout << "========================================" << std::endl;
    
    int numeroCoches = 0;
    int numeroMotos = 0;
    
    for (int i = 0; i < numeroVehiculos; i++) {
        if (vehiculos[i] != nullptr) {
            if (dynamic_cast<Coche*>(vehiculos[i]) != nullptr) {
                numeroCoches++;
            } else if (dynamic_cast<Moto*>(vehiculos[i]) != nullptr) {
                numeroMotos++;
            }
        }
    }
    
    std::cout << "Capacidad maxima: " << maximoVehiculos << " vehiculos" << std::endl;
    std::cout << "Ocupacion actual: " << numeroVehiculos << " vehiculos" << std::endl;
    std::cout << "Porcentaje ocupacion: " 
              << (numeroVehiculos * 100.0 / maximoVehiculos) << "%" << std::endl;
    std::cout << "\nDistribucion:" << std::endl;
    std::cout << "- Coches: " << numeroCoches;
    if (numeroVehiculos > 0) {
        std::cout << " (" << (numeroCoches * 100.0 / numeroVehiculos) << "%)";
    }
    std::cout << std::endl;
    std::cout << "- Motos: " << numeroMotos;
    if (numeroVehiculos > 0) {
        std::cout << " (" << (numeroMotos * 100.0 / numeroVehiculos) << "%)";
    }
    std::cout << std::endl;
    std::cout << "========================================" << std::endl;
}