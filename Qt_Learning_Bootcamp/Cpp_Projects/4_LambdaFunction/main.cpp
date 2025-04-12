#include <iostream>



int main()
{
    /*****************************************/
    auto func = [](){
        std::cout << "Hello World" << std::endl;
    };
    func();
    /*****************************************/
    [](){
        std::cout << "Hello World" << std::endl;
    }();
    /******************************************/
    [](int a,int b)
    {
        std::cout << "a + b = " << a+b << std::endl;
    }(7,3);
    /******************************************/
    auto func1 = [](int a,int b)
    {
        std::cout << "a + b = " << a+b << std::endl;
    };
    func1(10,5);
    /******************************************/
    std::cout << "The sum is : " << [](int a, int b) -> int{
        return a+b;
    }(10,10) << std::endl;
    /******************************************/
    auto func2 = [](int a, int b)->int{
        return a+b;
    };
    auto sum = func2(10,20);
    std::cout << "The sum is : " << sum << std::endl;
    /******************************************/
    //capture list

    int a = 10;
    int b = 22;
    //lambda function takes a copy from values of a and b
    auto func3 = [a,b]()->int{
        return a+b;
    };
    a = 30;
    b=50;
    //when the values of a and b changes no change in the values in lambda function
    std::cout << "The sume Equal = " << func3() << std::endl;
    std::cout << "a = " << a << "\t b = " << b<< std::endl;

    /******************************************/
    // passing the values to lambda function by reference
    a = 10;
    b = 22;
    auto func4 = [&]()->int{
        return a+b;
    };
    a = 30;
    b=50;
    // here lambda function take the last updated value of a and b
    std::cout << "The sume Equal = " << func4() << std::endl;
    std::cout << "a = " << a << "\t b = " << b<< std::endl;
    /******************************************/

    return 0;
}
