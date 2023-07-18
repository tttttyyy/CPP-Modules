#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    {
        // const aAnimal* meta = new aAnimal();
        const aAnimal* j = new Dog();
        const aAnimal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        // meta->makeSound();
        // delete meta;
        delete j;
        delete i;
    }
    // aAnimal an;
    // system("leaks Abstract");
    return 0;
}