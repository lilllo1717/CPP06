#include "Base.hpp"


Base* generate(void)
{
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0,2);
    int ran_i = dist(gen);

    switch (ran_i)
    {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;

    }
    return NULL;
}

void identify(Base* p)
{
    if (!p)
        std::cout << "Unknown\n";
    else if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if  (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
    else
        std::cout << "Unknown\n";
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    }
    catch (std::exception&) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    }
    catch (std::exception&) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    }
    catch (std::exception&) {}
}


int main()
{
    Base* instanceClass = generate();
    // std::cout << "value n: " << instanceClass->n << "\n";
    identify(instanceClass);
    identify(*instanceClass);

    Base* baseClass = new Base;
    identify(baseClass);
    identify(*baseClass);



    delete instanceClass;

}