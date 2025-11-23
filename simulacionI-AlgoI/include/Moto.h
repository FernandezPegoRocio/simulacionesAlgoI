#ifndef MOTO_H
#define MOTO_H

#include "Vehiculo.h"

class Moto : public Vehiculo {
private:
    int cilindrada;

public:
    Moto();
    Moto(const std::string& colorMoto, const std::string& marcaMoto, int cilindradaMoto);
    
    ~Moto();
    
    void arrancar() override;
    void parar() override;
    void repostar() override;
    
    int obtenerCilindrada() const { return cilindrada; }
    void mostrarInformacion() override;
};

#endif