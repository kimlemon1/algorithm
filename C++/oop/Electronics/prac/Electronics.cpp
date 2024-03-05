#include "Electronics.h"

// Electronics body
using namespace std;
double Electronics::Price() {return Size*x;}

Electronics::Electronics(const double &aSize) : Size(aSize){}

double Electronics::GetSize(){
            return Size;
        }
void Electronics::SetSize(const double &aSize){
            Size = aSize;
        }

void Electronics::set_x(const double &ax){
    x = ax;
}

// TV body
TV::TV(const double &aSize): Electronics(aSize){
    set_x(1.8);
}
void TV::PrintSelf(void){
    cout << "It is a TV, Size=" << (int)GetSize() << ", Price=" << (int)Price() << endl;
}

// Computer body
Computer::Computer(const double &aSize): Electronics(aSize){
    set_x(0.6);
}
void Computer::PrintSelf(void){
    cout << "It is a Computer, Size=" << (int)GetSize() << ", Price=" << (int)Price() << endl;

}

// Cellphone body
Cellphone::Cellphone(const double &aSize): Electronics(aSize){
    set_x(0.7);
}
void Cellphone::PrintSelf(void){
    cout << "It is a Cellphone, Size=" << (int)GetSize() << ", Price=" << (int)Price() << endl;
}

// Laptop
Laptop::Laptop(const double &aSize): Computer(aSize){};
void Laptop::AddGPU(Electronics *aGPU){
    if (num_GPU < 2){
        num_GPU++;
        GPU_price += aGPU->Price();
    }
    else cout << "Already 2 GPU in Laptop"<< endl;

}
void Laptop::PrintSelf(void){
    if (num_GPU == 0){
    cout << "It is a Laptop with "<< num_GPU << "GPU(s), Size=" << (int)GetSize() << ", Price="\
     << (int)Price() <<", Total Price="<< (int)Price() << endl;
    }
    else{
    cout << "It is a Laptop with "<< num_GPU << " GPU(s), Size=" << (int)GetSize() << ", Price="\
     << (int)(2* Price()) <<", Total Price="<< (int)(2 * Price() + GPU_price) << endl;
    }

}