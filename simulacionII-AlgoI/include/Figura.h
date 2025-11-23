#ifndef FIGURA_H
#define FIGURA_H

#include <iostream>
#include <string>

class Figura {
protected:
    float x; 

public:
    Figura();
    Figura(float valorX);
    
    virtual ~Figura();

    virtual float Perimetro() = 0;
    virtual float Area() = 0;

    virtual void mostrarInformacion();
    virtual std::string obtenerTipo() = 0;
    float obtenerX() const { return x; }
    void establecerX(float nuevoX) { x = nuevoX; }
};

#endif