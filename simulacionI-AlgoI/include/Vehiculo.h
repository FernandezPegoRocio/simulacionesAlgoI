#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <iostream>

class Vehiculo {
protected:
    std::string color;
    std::string marca;

public:

    Vehiculo();
    Vehiculo(const std::string& colorVehiculo, const std::string& marcaVehiculo);
    
    virtual ~Vehiculo();
    
    virtual void arrancar() = 0;  
    virtual void parar() = 0;      
    virtual void repostar() = 0;   
    
    std::string obtenerColor() const { return color; }
    std::string obtenerMarca() const { return marca; }
    
    virtual void mostrarInformacion();
};

#endif