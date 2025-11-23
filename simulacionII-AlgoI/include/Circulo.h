#ifndef CIRCULO_H
#define CIRCULO_H

#include "Figura.h"

class Circulo : public Figura {
private:
    static constexpr float PI = 3.14159265359;

public:
    Circulo();
    Circulo(float radio);

    ~Circulo();
    
    float Perimetro() override;
    float Area() override;

    void mostrarInformacion() override;
    std::string obtenerTipo() override;
    float obtenerRadio() const { return x; }
};

#endif