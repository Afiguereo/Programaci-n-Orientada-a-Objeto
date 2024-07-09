#include <stdio.h>

struct Calculadora {

    double (*sumar)(double, double);
    double (*restar)(double, double);
    double (*multiplicar)(double, double);
    double (*dividir)(double, double);
};

double sumar(double a, double b) {
    return a + b;
}

double restar(double a, double b) {
    return a - b;
}

double multiplicar(double a, double b) {
    return a * b;
}

double dividir(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: División por cero no es permitida.\n");
        return 0;
    }
}

void inicializarCalculadora(struct Calculadora* calc) {
    calc->sumar = sumar;
    calc->restar = restar;
    calc->multiplicar = multiplicar;
    calc->dividir = dividir;
}

int main() {
    struct Calculadora calc;
    inicializarCalculadora(&calc);

    double num1, num2;
