#pragma once
#include <iostream>
// Fill in here

class Electronics {
    private:
        double Size;
    public:
        Electronics(double asize);

        double GetSize(void);
        void SetSize(double asize);

        virtual void PrintSelf(void) = 0;

};

class TV: public Electronics{

    public:
        TV(double asize);
        virtual void PrintSelf(void);

};

class Computer: public Electronics{
    public:
        Computer(double aSize);
        virtual void PrintSelf(void);

};

class Cellphone: public Electronics{
    public:
        Cellphone(double aSize);
        virtual void PrintSelf(void);

};

class Laptop: public Computer{
    private:
        bool GPU_in;
        double GPU_price;
        int GPU_num;

    public:
        Laptop(double aSize);
        virtual void PrintSelf(void);
        void AddGPU(Electronics* aGPU);
        
};