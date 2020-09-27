#include "hola.h"
#include <iostream>

std::string saludo(int a){
    while(a != 0) {
        std::cout << "HELLO!!!!!" << std::endl;
        a--;
    }
    std::cout << "HOLA AMIGO MIO" << std::endl;
}