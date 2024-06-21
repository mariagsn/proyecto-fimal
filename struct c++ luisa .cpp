#include <iostream>
#include <string>
using namespace std;


struct Persona {
    
    string nombre;
    int edad;
    double altura;
    
    
    Persona(string n, int a, double h) : nombre(n), edad(a), altura(h) {}
    
    
    void mostrar() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << ", Altura: " << altura << " metros" << endl;
    }
};

int main() {
    
    Persona persona1("Alice", 30, 1.75);
    
    
    cout << "Nombre: " << persona1.nombre << endl;
    cout << "Edad: " << persona1.edad << endl;
    cout << "Altura: " << persona1.altura << " metros" << endl;
    
   
    persona1.mostrar();
    
    return 0;
}
