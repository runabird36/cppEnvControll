// Online C++ compiler to run C++ program online
#include <iostream>

int main() {
    // Write C++ code here
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int* pa = &a[0];
    
    std::cout<<"&a[0]의 값 : "<<&a[0]<<std::endl;
    std::cout<<"a의 값 : "<<a<<std::endl;
    std::cout<<"pa의 값 : "<<pa<<std::endl;

    return 0;
}