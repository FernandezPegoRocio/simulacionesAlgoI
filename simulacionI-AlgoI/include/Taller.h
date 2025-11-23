#ifndef TALLER_H
#define TALLER_H

#include <vector>
#include "Vehiculo.h"
#include "Coche.h"
#include "Moto.h"

class Taller {
private:
    static const int MAXIMO_VEHICULOS = 100;
    int maximoVehiculos;
    int numeroVehiculos;
    Vehiculo* vehiculos[MAXIMO_VEHICULOS];
    
public:
    Taller();
    Taller(int capacidadMaxima);
    
    ~Taller();
    
    void meter(Vehiculo* vehiculo);
    void arreglarVehiculos();
    
    void arreglarCoches();
    void arreglarMotos();
    void listarVehiculos();
    void mostrarEstadisticasTaller();
    int obtenerNumeroVehiculos() const { return numeroVehiculos; }
    int obtenerCapacidad() const { return maximoVehiculos; }
};

#endif