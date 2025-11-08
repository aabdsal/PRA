#include <iostream>
int main(){ 
    std::cout << __cplusplus << "\n"; return 0;
}
//g++ t.cpp && ./a.out   # 201703 ⇒ C++17; 202002 ⇒ C++20; 201402 ⇒ C++14