#pragma once
#include <iostream>
// Fill in here
class Electronics{
    private:
        double Size;
        double x;
    public:
        Electronics(const double &aSize);
        virtual void PrintSelf(void) = 0;
        double GetSize();
        void SetSize(const double &aSize);
        double Price();
        // 여기 addGPU넣어보자! 되는지 확인하기 , 컴퓨터에서도 pure virtual 쓰도록 

    //protected 변수 만들지 말자 안좋다
        //double x = 0;
    protected:
        void set_x(const double &ax);

};

class TV: public Electronics{
    public:
        TV(const double &aSize);

        virtual void PrintSelf(void);
};

class Computer: public Electronics{
    public:
        Computer(const double &aSize);

        virtual void PrintSelf(void);
};

class Cellphone: public Electronics{
    public:
        Cellphone(const double &aSize);

        virtual void PrintSelf(void);
};

class Laptop: public Computer{
    private:
        int num_GPU =0;
        double GPU_price = 0;
    public:
        Laptop(const double &aSize);
        virtual void PrintSelf(void);
        void AddGPU(Electronics *aGPU);

        
};