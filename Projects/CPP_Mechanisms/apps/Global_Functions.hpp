#include <iostream>
#include "Entity.hpp"
#include "Figure.hpp"
#include "Square.hpp"
#include "Rectangle.hpp"
#include "Block.hpp"
#include <memory>

void TestTemplates()
{
    // Templates and different constructors
    {
        std::cout << "--------------TEST1--------------" << std::endl;
        Entity<char> entity1("some entity");
        entity1.Print();
    }
    std::cout << "---------------------------------- \n" << "Press anything to continue" << std::endl;
    std::cin.get();
    {
        std::cout << "--------------TEST2--------------" << std::endl;
        Entity<char> entity2(String<char>("some nice entity"));
        entity2.Print();
    }
    std::cout << "---------------------------------- \n" << "Press anything to continue" << std::endl;
    std::cin.get();
    {
        std::cout << "--------------TEST3--------------" << std::endl;
        Entity<char> entity3(String<char>("some nicer entity"));
        entity3.Print();
        Entity<char> entity4(String<char>("some even nicer entity"));
        entity3.Print();
        entity3 = entity4;
        entity3.Print();
    }
    std::cout << "---------------------------------- \n" << "Press anything to continue" << std::endl;
    std::cin.get();
    {
        std::cout << "--------------TEST4--------------" << std::endl;
        Entity<char> entity5("some boring entity");
        entity5.Print();
        entity5 = Entity<char>("Some more boring entity");
        entity5.Print();
    }
}

void TestInheritance()
{
    std::cout << "Testing inheritance" << std::endl;
    //Multiple inheritance and polymorphism
    {
        std::cout << "--------------TEST1--------------" << std::endl;
        std::unique_ptr<Figure> base_ptr;
        base_ptr = std::make_unique<Square>(10, "My square");
        std::cout << "object's name under base_ptr is " << base_ptr->GetName() << " and its area is: " << base_ptr->Area() << std::endl;
    }
    std::cout << "Press anything to continue" << std::endl;
    std::cin.get();

    {
        std::cout << "--------------TEST2--------------" << std::endl;
        std::unique_ptr<Figure> base_ptr;
        base_ptr = std::make_unique<Rectangle>(10, 5);
        std::cout << "object's name under base_ptr is " << base_ptr->GetName() << " and its area is: " << base_ptr->Area() << std::endl;
    }
    std::cout << "Press anything to continue" << std::endl;
    std::cin.get();

    {
        std::cout << "--------------TEST3--------------" << std::endl;
        std::unique_ptr<Figure> base_ptr;
        base_ptr = std::make_unique<Block>(10, 5, 10, 2, 4, "My block");
        std::cout << "object's name under base_ptr is " << base_ptr->GetName() << " its area is: " << base_ptr->Area()
        << " and its volume is: " << base_ptr->Volume() << std::endl;
    }

}