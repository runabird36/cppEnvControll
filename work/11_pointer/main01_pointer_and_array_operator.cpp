// Online C++ compiler to run C++ program online
#include <iostream>

int main() {
    // Write C++ code here
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int* pa = &a[0];
    int* pb = a;
    
    
    for(int i=0;i<10;i++)
    {
        std::cout<<*(a+i)<<std::endl;
    }
    
    for(int i=0;i<sizeof(a)/sizeof(int);i++)
    {
        std::cout<<*(pa+i)<<std::endl;
    }

    for(int i=0;i<10;i++)
    {
        std::cout<<*(pb+i)<<std::endl;
    }

    return 0;
}