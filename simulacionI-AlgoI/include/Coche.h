#ifndef COCHE_H
#define COCHE_H

#include "Vehiculo.h"

class Coche : public Vehiculo {
private:
    int motor;

public:
    Coche();
    Coche(const std::string& colorCoche, const std::string& marcaCoche, int motorCoche);
    
    ~Coche();
    
    void arrancar() override;
    void parar() override;
    void repostar() override;
    
    int obtenerMotor() const { return motor; }
    void mostrarInformacion() override;
};

#endif