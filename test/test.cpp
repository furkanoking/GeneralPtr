#include "GeneralPtr.hpp"

int main() {

    int* x = new int(78);

    int* a = new int(78);

    GenericPointer hop{x};
    GenericPointer selam{a};
    selam = std::move(hop);

    if( x == nullptr ){
        std::cout <<" lAn oglummmm"<<std::endl;
    }

    std::cout<<"Sekam"<<std::endl;

    

}