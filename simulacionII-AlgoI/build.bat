@echo off

g++ -std=c++17 -Wall -I".\include" -c ".\src\Figura.cpp"
g++ -std=c++17 -Wall -I".\include" -c ".\src\Circulo.cpp"
g++ -std=c++17 -Wall -I".\include" -c ".\src\Cuadrado.cpp"
g++ -std=c++17 -Wall -I".\include" -c ".\main.cpp"


g++ -std=c++17 -Wall -Wextra -Wpedantic -Werror -I".\include" Figura.o Circulo.o Cuadrado.o main.o -o app.exe

DEL *.o

app.exe
pause