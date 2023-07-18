#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // delete j;//should not create a leak
    // delete i;
    // // ...
    Animal* an = new Dog() ;
    delete an ;

    Animal *array[10];
    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
            array[i] = new Dog();
        else
            array[i] = new Cat();
    }

    for (int i = 0; i < 10; i++)
        delete array[i];
    // system("leaks Brain");
    return 0;
}