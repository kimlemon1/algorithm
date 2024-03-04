// compile : g++ -o <exe_name> oop.cpp
// run : ./<exe_name> exe안붙임

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

class Shape{
public:
    Shape(){}
    virtual double calc_area(void) = 0;
    virtual string get_name() {return "Shape";}
    ~Shape(){}
};

class Rectangle : public Shape{
protected:
    double w;
    double h;
public :
    Rectangle(double width, double height) :w(width), h(height){}
    double calc_area(void) {return w*h;}
    string get_name(){return "Rectangle";}
};

class Square : public Rectangle{
public:
    Square(double length):Rectangle(length, length){}
    string get_name(){return "Square";}
};

class Triangle : public Shape{
private:
    double a;
    double b;
    double c;
public:
    Triangle(double a1, double b1, double c1):a(a1), b(b1), c(c1){}
    double calc_area(){
        s = (a+b+c)/2;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
        return area;
    }
    string get_name(){return "Triangle";}
}

class RightTriangle : public Triangle{
public:
    RightTriangle(double aa, double bb):Triangle(aa,bb, sqrt(a*a+b*b)){}
    double calc_area(){return (a*b)/2;}
    string get_name(){return "RightTriangle";}
}

int main(void){
    // Command: g++ -o prob3 QE_prob3.cpp
    Rectangle rect(4, 3);
    cout << rect.get_name() << endl;
    cout << "Area of rectangle with width 4 and height 3: " << rect.calc_area() << endl;
    Square squ(4);
    cout << squ.get_name() << endl;
    cout << "Area of square with length 4: " << squ.calc_area() << endl;
    Triangle t(3, 4, 6);
    cout << t.get_name() << endl;
    cout << "Area of triangle with 3, 4, 6: " << t.calc_area() << endl;
    RightTriangle rt(3, 4);
    cout << rt.get_name() << endl;
    cout << "Area of Right Triangle with width 3 and height 4: "<<rt.calc_area() << endl;
    return 0;

    //expected output
    /*
    Shape
    Rectangle
    Area of rectangle with width 4 and height 3: 12
    Square
    Area of square with length 4: 16
    Triangle
    Area of triangle with 3, 4, 6: 5.33268
    RightTriangle
    Area of Right Triangle with width 3 and height 4: 6
    */
}