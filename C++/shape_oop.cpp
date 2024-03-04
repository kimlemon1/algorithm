#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

class Shape{
public :
    Shape(){}
    virtual string get_name() {return "Shape";} // virtual string??
    virtual double calc_area(void)=0; //pure virtual function
    ~Shape(){}
};

class Rectangle : public Shape{
public : 
    Rectangle(double width, double height) : w(width), h(height) {}
    double calc_area(void) {return w*h;}
    string get_name(){return "Rectangle";}

protected :
    double w; //width
    double h; //height
};

class Square : public Rectangle {
public :
    Square(double width) :  Rectangle(width, width) {}
    string get_name(){return "Square";}
};

class Triangle : public Shape {
public :
    Triangle(double a_, double b_, double c_) : a(a_), b(b_), c(c_) {}
    double calc_area(void){
        double s = (a+b+c) / 2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    string get_name(){return "Triangle";}

protected :
    double a, b, c;
};

class RightTriangle : public Triangle{
public :
    RightTriangle(double a_, double b_) : Triangle(a_, b_, sqrt(a_* a_ + b_* b_)){}
    string get_name(){return "RightTriangle";}
    /*
    In fact, we don't need to define calc_area in RightTriangle class.
    double calc_area(void) override {
        return (a*b) / 2;
    }
    */
};

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