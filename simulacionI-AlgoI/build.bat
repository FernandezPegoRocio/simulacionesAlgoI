@echo off

g++ -std=c++17 -Wall -I".\include" -c ".\src\Vehiculo.cpp"
g++ -std=c++17 -Wall -I".\include" -c ".\src\Coche.cpp"
g++ -std=c++17 -Wall -I".\include" -c ".\src\Moto.cpp"
g++ -std=c++17 -Wall -I".\include" -c ".\src\Taller.cpp"
g++ -std=c++17 -Wall -I".\include" -c ".\main.cpp"

g++ -std=c++17 -Wall -Wextra -Wpedantic -Werror -I".\include" Vehiculo.o Coche.o Moto.o Taller.o main.o -o app.exe

DEL *.o

app.exe
pause