// Move constructor, move assignment
// = 등호가 copy, move 2가지 기능을 한다! 언제 어느 것인지 구분 필요함
// move는 실제로 값이 이동됨 : 원본은 다 비운다
// move는 r-value(실체 없는 경우)가 등호 오른쪽에 있는 경우만 일어난다(unnamed object)
// r-value : 이름 없다, 실체 없다, 메모리에 없다로 기억하자 
// ex : 함수 리턴값 : 해당 줄 끝나면 소멸한다, 이름이 없다

// 정의 방법
// 1. move constructor 
// Myclass (Myclass&&); // 파라미터에 && 두개 붙이는것 const나 다른거 안붙는다! 특별 case

// 2. move assignment
// Myclass& operator=(Myclass&&); 여기서는 참조자로 반환함 : r-value가 리턴되는것 아니다! 

// 동적할당의 경우 move가 더 편하다! 기존 A 오브잭트의 주소를 B가 다 가져가면 되기 때문에 (shallow copy 가능)
// r-value 참조자는 move이외에 잘 안쓴다

#include <iostream>
#include <string>
using namespace std;

class Example6{
    string* ptr;
    public:
        Example6 (const string& str) :
            ptr(new string(str)){}
        ~Example6() {delete ptr;}

        // move constructor
        Example6 (Example6&& x):
            ptr(x.ptr) {x.ptr = nullptr;}

        Example6& operator= (Example6&& x){
            delete ptr;
            ptr = x.ptr;
            x.ptr = nullptr;
            return *this;
        }

        const string& content() const {return *ptr;}

        Example6 operator+(const Example6& rhs){
            return Example6(content() + rhs.content());
        }
};