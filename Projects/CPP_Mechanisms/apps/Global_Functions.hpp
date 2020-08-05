#include <iostream>
#include "Entity.hpp"
#include "Figure.hpp"
#include "Square.hpp"
#include "Rectangle.hpp"
#include "Block.hpp"
#include "Temp.hpp"
#include "Double_Linked_List.hpp"
#include "Tree_Node.hpp"
#include "Binary_Tree.hpp"
#include <memory>
#include <array>
#include <numeric>
#include <chrono>
#include <random>

class Timer
{
private:
    std::string m_name;
    std::chrono::system_clock::time_point m_start;
public:
    Timer(const std::string& a_name) : m_name(a_name){ m_start = std::chrono::high_resolution_clock::now();};
    ~Timer(){
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> diff = end - m_start;
        float ms = diff.count() * 1000.0f;
        std::cout << "Function " << m_name << " took " << ms << "ms" << std::endl;
    }
};

void TestTemplates()
{
    std::cout << "Testing templates" << std::endl;
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
    std::cout << "---------------------------------- \n" << "Press anything to continue" << std::endl;
    std::cin.get();

    {
        std::cout << "--------------TEST2--------------" << std::endl;
        std::unique_ptr<Figure> base_ptr;
        base_ptr = std::make_unique<Rectangle>(10, 5);
        std::cout << "object's name under base_ptr is " << base_ptr->GetName() << " and its area is: " << base_ptr->Area() << std::endl;
    }
    std::cout << "---------------------------------- \n" << "Press anything to continue" << std::endl;
    std::cin.get();

    {
        std::cout << "--------------TEST3--------------" << std::endl;
        std::unique_ptr<Figure> base_ptr;
        base_ptr = std::make_unique<Block>(10, 5, 10, 2, 4, "My block");
        std::cout << "object's name under base_ptr is " << base_ptr->GetName() << " its area is: " << base_ptr->Area()
        << " and its volume is: " << base_ptr->Volume() << std::endl;
    }

}
void TestSmartPointers()
{
    std::cout << "Testing Smart Pointers" << std::endl;
    {
        std::cout << "--------------TEST1--------------" << std::endl;
        std::unique_ptr<Temp> u_ptr = std::make_unique<Temp>();
        std::shared_ptr<Temp> s_ptr1 = std::make_shared<Temp>();
        std::shared_ptr<Temp> s_ptr2 = s_ptr1;
    }
    std::cout << "---------------------------------- \n" << "Press anything to continue" << std::endl;
    std::cin.get();

    {
        std::cout << "--------------TEST2--------------" << std::endl;
        std::unique_ptr<Temp> u_ptr = std::make_unique<Temp>();
        std::shared_ptr<Temp> s_ptr1 = std::make_shared<Temp>(*u_ptr.release());
        std::cout << "s_ptr1.use_count() =  " << s_ptr1.use_count() << std::endl;
        std::weak_ptr<Temp> w_ptr = s_ptr1;
        std::cout << "w_ptr.use_count() =  " << w_ptr.use_count() << std::endl;
        std::cin.get();
        if(!w_ptr.expired())
        {
            auto s_ptr2 = w_ptr.lock();
            std::cout << "s_ptr2.use_count() =  " << s_ptr2.use_count() << std::endl;
            std::cout << "s_ptr2->GetNumber() = " << s_ptr2->GetNumber() << std::endl;
        }
        std::cout << "w_ptr.use_count() =  " << w_ptr.use_count() << std::endl;
    }
    std::cout << "---------------------------------- \n" << "Press anything to continue" << std::endl;
    std::cin.get();

    {
        std::cout << "--------------TEST3--------------" << std::endl;
        std::weak_ptr<Temp> w_ptr = std::make_shared<Temp>();
        std::cout << "w_ptr.use_count() = " << w_ptr.use_count() << std::endl;
        std::cout << "w_ptr.expired() = " << w_ptr.expired() << std::endl;
        std::shared_ptr<Temp> s_ptr1 = std::make_shared<Temp>();
        std::shared_ptr<Temp> s_ptr2 = s_ptr1;
        w_ptr = s_ptr1;
        std::cout << "w_ptr.use_count() = " << w_ptr.use_count() << std::endl;
    }
    std::cout << "---------------------------------- \n" << "Press anything to continue" << std::endl;
    std::cin.get();

    {
        std::cout << "--------------TEST4--------------" << std::endl;
        std::unique_ptr<Temp> u_ptr1 = std::make_unique<Temp>();
        std::unique_ptr<Temp> u_ptr2 = std::make_unique<Temp>();
        std::cout << "Before u_ptr1.swap(u_ptr2): " << std::endl;
        std::cout << "u_ptr1.GetNumber() = " << u_ptr1->GetNumber() << std::endl;
        std::cout << "u_ptr2.GetNumber() = " << u_ptr2->GetNumber() << std::endl;
        u_ptr1.swap(u_ptr2);
        std::cout << "After u_ptr1.swap(u_ptr2): " << std::endl;
        std::cout << "u_ptr1.GetNumber() = " << u_ptr1->GetNumber() << std::endl;
        std::cout << "u_ptr2.GetNumber() = " << u_ptr2->GetNumber() << std::endl;
    }
    std::cout << "---------------------------------- \n" << "Press anything to continue" << std::endl;
    std::cin.get();

    {
        std::cout << "--------------TEST5--------------" << std::endl;
        std::shared_ptr<Temp> s_ptr1 = std::make_shared<Temp>();
        std::shared_ptr<Temp> s_ptr2 = s_ptr1;
        std::shared_ptr<Temp> s_ptr3 = std::make_shared<Temp>();
        std::cout << "Before s_ptr2.swap(s_ptr3): " << std::endl;
        std::cout << "s_ptr1.use_count() = " << s_ptr1.use_count() << " and GetNumber() = " << s_ptr1->GetNumber() << std::endl;
        std::cout << "s_ptr2.use_count() = " << s_ptr2.use_count() << " and GetNumber() = " << s_ptr2->GetNumber() << std::endl;
        std::cout << "s_ptr3.use_count() = " << s_ptr3.use_count() << " and GetNumber() = " << s_ptr3->GetNumber() << std::endl;
        s_ptr2.swap(s_ptr3);
        std::cout << "After s_ptr2.swap(s_ptr3): " << std::endl;
        std::cout << "s_ptr1.use_count() = " << s_ptr1.use_count() << " and GetNumber() = " << s_ptr1->GetNumber() << std::endl;
        std::cout << "s_ptr2.use_count() = " << s_ptr2.use_count() << " and GetNumber() = " << s_ptr2->GetNumber() << std::endl;
        std::cout << "s_ptr3.use_count() = " << s_ptr3.use_count() << " and GetNumber() = " << s_ptr3->GetNumber() << std::endl;

        std::weak_ptr<Temp> w_ptr1(s_ptr1);


    }
    std::cout << "---------------------------------- \n" << "Press anything to continue" << std::endl;
    std::cin.get();

}

void TestDataStructures() {
    std::cout << "Testing data structures" << std::endl;
    {

        std::cout << "--------------TEST1--------------" << std::endl;

        DLinkedList myList;
        std::cout << "Adding 5 nodes to double linked list" << std::endl;
        std::cin.get();
        myList.PushBack(People());
        myList.PushFront(People(10, 3.0, "Hodor"));
        myList.PushFront(People(15, 4.0, "Vader"));
        myList.PushFront(People(22, 4.5, "Halt"));
        myList.PushFront(People(26, 3.5, "Will"));
        std::cout << myList << std::endl;
        std::cout << "Adding another node at the place pointed by index = 3" << std::endl;
        std::cin.get();
        myList.Insert(People(2, 2.0, "Drab"), 3);
        std::cout << myList << std::endl;

        std::cin.get();
        std::cout << "Removing list" << std::endl;
    }
    std::cout << "---------------------------------- \n" << "Press anything to continue" << std::endl;
    std::cin.get();

    {
        std::cout << "--------------TEST2--------------" << std::endl;
        DLinkedList myList;
        std::cout << "Adding 6 nodes to double linked list" << std::endl;
        std::cin.get();
        myList.PushBack(People(54, 1.0, "Skarsnik"));
        myList.PushFront(People(10, 2.0, "Big Uns"));
        myList.PushFront(People(15, 0.5, "Black Ork"));
        myList.PushFront(People(22, 1.5, "Savage Ork"));
        myList.PushFront(People(666, 5.5, "Da Best"));
        myList.PushFront(People(123, 3.5, "Wulfrag"));
        std::cout << myList << std::endl;

        std::cout << "Testing Merge sort" << std::endl;
        std::cout << "Sorting list by elements' age" << std::endl;
        std::cin.get();
        myList.MergeSort('a');
        std::cout << myList << std::endl;

        std::cout << "Sorting list by elements' grade" << std::endl;
        std::cin.get();
        myList.MergeSort('g');
        std::cout << myList << std::endl;

        std::cout << "Sorting list by elements' name" << std::endl;
        std::cin.get();
        myList.MergeSort('n');
        std::cout << myList << std::endl;

        std::cout << "Now swapping myList[1] and myList[2]" << std::endl;
        std::cin.get();
        myList.SwapTwo(myList[1], myList[2]);
        std::cout << myList << std::endl;

        std::cout << "Now swapping myList[1] and myList[3]" << std::endl;
        std::cin.get();
        myList.SwapTwo(myList[1], myList[3]);
        std::cout << myList << std::endl;
        std::cin.get();
    }
    std::cout << "---------------------------------- \n" << "Press anything to continue" << std::endl;
    std::cin.get();

    {
        std::cout << "--------------TEST3--------------" << std::endl;
        DLinkedList firstList, secondList, thirdList;
        std::cout << "Adding 1000 nodes to double linked list" << std::endl;
        std::cin.get();

        std::array<int, 1000> random_age;
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::iota(random_age.begin(), random_age.end(), 0);
        std::shuffle(random_age.begin(), random_age.end(), std::default_random_engine(seed));


        std::array<double, 1000> random_grade;
        std::iota(random_grade.begin(), random_grade.end(), 0);
        std::shuffle(random_grade.begin(), random_grade.end(), std::default_random_engine(seed + 10));

        for(int i = 0; i < 1000; i++)
        {
            firstList.PushBack(People(random_age[i], random_grade[i]));
            secondList.PushBack(People(random_age[i], random_grade[i]));
            thirdList.PushBack(People(random_age[i], random_grade[i]));
        }

        std::cout << "There are 3 identical lists: firstList, secondList, thirdList" << std::endl;
        std::cout << "MergeSort: Sorting firstList by elements' age" << std::endl;
        std::cin.get();
        {
            Timer timer("Merge Sort");
            firstList.MergeSort('a');
        }
        std::cin.get();
        std::cout << "BubbleSort: Sorting secondlist by elements' age" << std::endl;
        std::cin.get();
        {
            Timer timer("Bubble Sort");
            secondList.BubbleSort('a');
        }
        std::cin.get();

        std::cout << "EasySort: Sorting thirdList by elements' age" << std::endl;
        std::cin.get();
        {
            Timer timer("Easy Sort");
            thirdList.EasySort('a');
        }
        std::cout << "Press to print the sorted list" << std::endl;
        std::cin.get();
        std::cout << thirdList << std::endl;
    }
    std::cout << "---------------------------------- \n" << "Press anything to continue" << std::endl;
    std::cin.get();

}

void TestBinaryTree()
{
    std::cout << "Testing Binary Tree" << std::endl;

    {
        std::cout << "--------------TEST1--------------" << std::endl;
        BinaryTree<int> myTree;
        myTree.Insert(15);
        myTree.Insert(9);
        myTree.Insert(8);
        myTree.Insert(7);
        myTree.Insert(6);
        myTree.Insert(60);
        myTree.Insert(59);
        myTree.Insert(12);
        myTree.Insert(11);
        myTree.Insert(10);
        myTree.PrintTree();

    }
}