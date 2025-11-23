#ifndef CUADRADO_H
#define CUADRADO_H

#include "Figura.h"

class Cuadrado : public Figura {
private:
  
public:
    Cuadrado();
    Cuadrado(float lado);
    
    ~Cuadrado();

    float Perimetro() override;
    float Area() override;
    
    void mostrarInformacion() override;
    std::string obtenerTipo() override;
    float obtenerLado() const { return x; }
};

#endif
