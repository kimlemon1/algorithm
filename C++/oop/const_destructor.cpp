#include <iostream>
#include <string>

// 1. Default 생성자
// 사용자 지정 생성자를 아무것도 만들지 않을 때 만들어진다
// if 사용자 지정 생성자 있으면 소멸! 따라서 파라미터 없는 경우를 받지 못한다
// 디폴트와 같이 쓰고 싶다면 파라미터 없는 생성자도 함께 만들어 오버로딩 해준다


// class Ex2{
//     public:
//         int total;
//         Ex2(int initial_value) : total(initial_value){}; // 사용자 정의 생성자
//         void accumulate(int x) { total += x;};

// };

// int main(){
//     Ex2 ex2; //사용자 정의 생성자가 이미 있어서 불가능!
// }


// 2. Destructors 소멸자
// object 소멸시(영역 벗어날 때) 자동으로 실행
// default destructor 하는 일 : 오브잭트가 할당된 메모리 비우기, 내부에 사용된 다른 object의 class destructor 부르기

// 사용자 정의 소멸자가 필수인 경우 : class 내부 포인터 맴버 변수 or 함수가 있을 때!!
// 디폴트 소멸자는 가진 메모리만 지우니까 포인터가 가리키는 주소는 비우지 못한다!!
// class 내부 new 동적할당 있을 때, 생성자에 new있을 때 소멸자 정의해서 delete해준다고 생각

class Example4{
    std::string* ptr;
    public:
        Example4() : ptr(new std::string){} // 아래 파라미터 있는 생성자와 디폴트 생성자 함께 사용 위해 
        Example4(const std::string& str): ptr(new std::string(str)){}

        // 소멸자
        ~Example4() {delete ptr;}
        // access content, 포인터여서 값을 바꿀 수 있는 겻 주의! const를 앞뒤로 붙인다
        const std::string&  content() const{ // cosnt {자료형} const ptr1 형태로 정의하는 포인터 const와 위치가 좀 다르다!! 구분해!
            return *ptr;
        }
        // ref를 리턴으로 받는 메소드 : dangling ref가 아니기 위해서 메소드 지역변수는 리턴 불가능!
        // ref로 받으니 수정 가능 => 맨 앞 const가 수정 못하게 만든다
        // 중간 const : 메소드 body에서 다른 값 바꾸지 못하게 만든다 (파라미터에 const넣는 것 외에 다른 변수도 바꾸지 못하게)
};

int main(){
    Example4 foo;
    Example4 bar{"Example"};
    std::string ctx1;
    ctx1 = bar.content();
    std::cout << "bar's content: " << ctx1 << '\n';
    return 0;
}