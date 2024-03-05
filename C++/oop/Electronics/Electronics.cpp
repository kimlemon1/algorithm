#include "Electronics.h"

// Fill in here
// 내일 price까지 넣어서 만들어보자 + 배운 내용 정리 (prac)같이 보자
// 더 효율적으로 변형시켜봐
// GPU 최대 2개임 고려, GPU에 컴퓨터 이외에 다른것 고려 안함
// 실수 계산이지만 출력은 소수점 안나오게!

// pure virtual func은 자식에서 재정의 안하면 사용 불가능하다!

// Electronics body
Electronics::Electronics(double asize) : Size(asize) {}

double Electronics::GetSize(void) {
            return Size;
        }
void Electronics::SetSize(double asize){
            Size = asize;
        }


// TV body
TV::TV(double asize):Electronics(asize){};

void TV::PrintSelf(void){
    std::cout << "It is a TV, Size="<< GetSize()\
     << ", Price=" << (int)(1.8 * GetSize()) << std::endl;
}

// Computer body
Computer::Computer(double aSize):Electronics(aSize){};

void Computer::PrintSelf(void){
    std::cout << "It is a Computer, Size="<< GetSize()\
     << ", Price=" << (int)(0.6* GetSize()) << std::endl;
}

// Cellphone body
Cellphone::Cellphone(double aSize):Electronics(aSize){};

void Cellphone::PrintSelf(void){
    std::cout << "It is a Cellphone, Size="<< GetSize()\
     << ", Price=" << (int)(0.7* GetSize()) << std::endl;
}

// Laptop body
Laptop::Laptop(double aSize):Computer(aSize){
    GPU_in = false;
    GPU_price = 0;
    GPU_num = 0;
}
void Laptop::AddGPU(Electronics* aGPU){
    if (GPU_num ==2){
        std::cout << "Already 2 GPU in Laptop" << std::endl;
    }
    else{
        GPU_in = true;
        // 오직 computer만 gpu가능하다고 가정 
        GPU_price += aGPU->GetSize() * 0.6;
        GPU_num++;
    }
}
void Laptop::PrintSelf(void){
    double price = 0;
    if (GPU_num > 0 ) price = 1.2 * GetSize();
    else if (GPU_num == 0) price = 0.6 * GetSize();
    std::cout << "It is a Laptop with " << GPU_num << " GPU(s),"\
    << " Size=" << GetSize() << ", Price=" << (int)price \
    << ", Total Price=" << (int)(GPU_price + price) << std::endl;

}