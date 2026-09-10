#include <iostream>
#include <cstdint>
#include <vector>

class test
{

private:
public:
    test()
    {
        std::cout << "test cons. called with no parameter" << std::endl;
    }
    test(int i)
    {
        std::cout << "test cons. called with no int " << std::endl;
    }

    ~test()
    {
        std::cout << "deconds. called!!" << std::endl;
    }
};


class testDerived : public test{
};



class training1{
private:
    /* data */
public:
    training1(/* args */)
    {
        std::cout << "constructor called" << std::endl;
    }
    ~training1()
    {
        std::cout << "deconstructer called" << std::endl;
    }

    void doSomething()
    {
        std::cout << "i am doing something" << std::endl;
    }

    void doAnotherThing()
    {
        std::cout << "i am doing another thing" << std::endl;
    }

    void quit()
    {
        std::cout << "i am quiting" << std::endl;
    }
};






int main()
{
    const char *pointerTest;
    pointerTest = "test 1234";

    std::vector<training1> tv = {};

    std::cout << pointerTest << std::endl;

    return 0;

    uint8_t t3;

    training1 *t1;
    training1 t2;

    t1 = new training1();

    t1->doAnotherThing();
    t1->doSomething();

    std::cout << t1 << std::endl;

    delete t1;

    return 0;

    char *testChrPointer;
    std::string testString = {};

    int intArray[10][20];
    for (int i = 0; i < 10; ++i)
    {

        for (int j = 0; j < 20; ++j)
        {

            intArray[i][j] = i + j;
        }
    }

    std::cout << intArray[0][1];
    return 0;

    testString = "selim keskin test satiridir!";

    for (short i = 0; i < 10; ++i)
    {

        *testChrPointer = testString[i];
        std::cout << "testString[" << i << "]=" << *testChrPointer << std::endl;
        std::cout << testChrPointer << std::endl;
    }

    std::cout << "test 123 deneme selim keskin";
    return 0;
}