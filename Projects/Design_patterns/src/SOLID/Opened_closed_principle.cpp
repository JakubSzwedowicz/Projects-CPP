//
// Author: JakubSzwedowicz
// Date: 17.08.2021.
// e-mail: kuba.szwedowicz@gmail.com 
//

#include <iterator>
#include <iostream>
#include <algorithm>

#include "Opened_closed_principle.hpp"

std::vector<Opened_closed_principle::Product*>
Opened_closed_principle::Bad::Product_filter::by_color(const std::vector<Product*>& a_items,
                                                       Color a_color)
{
    std::vector<Product*> result;
    for (auto& i : a_items)
    {
        if (i->m_color == a_color)
        {
            result.push_back(i);
        }
    }
    return result;
}

std::vector<Opened_closed_principle::Product*>
Opened_closed_principle::Bad::Product_filter::by_size(const std::vector<Product*>& a_items,
                                                      Size a_size)
{
    // Notice how this function is almost copy-paste of the by_color(...)
    std::vector<Product*> result;
    for (auto& i : a_items)
    {
        if (i->m_size == a_size)
        {
            result.push_back(i);
        }
    }
    return result;
}

std::vector<Opened_closed_principle::Product*>
Opened_closed_principle::Bad::Product_filter::by_size_and_color(const std::vector<Product*>& a_items,
                                                                Size a_size, Color a_color)
{
    // Notice how this function is almost copy-paste and merge of by_color(...) and by_size(...)
    std::vector<Product*> result;
    for (auto& i : a_items)
    {
        if ((i->m_size == a_size) && (i->m_color == a_color))
        {
            result.push_back(i);
        }
    }
    // At this point it can be seen that it scales very poorly. What if there is going to be more criterions.
    return result;
}

void Opened_closed_principle::test()
{
    Good::test();
    Bad::test();
}
void Opened_closed_principle::Good::test()
{
    std::cout << "================ Good test ==================" << std::endl;

    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};

    std::vector<Product*> items = {&apple, &tree, &house};

    Product_filer pf;
    Color_specification color_spec(Color::green);
    auto green_stuff = pf.filter(items, color_spec);

    for(auto& i : green_stuff){
        std::cout << i->m_name << " is green" << std::endl;
    }

    Size_specification size_spec(Size::large);
    auto large_stuff = pf.filter(items, size_spec);

    for(auto& i : large_stuff){
        std::cout << i->m_name << " is large" << std::endl;
    }

    And_specification and_spec(color_spec, size_spec);
    auto green_large_stuff = pf.filter(items, and_spec);

    for(auto& i : green_large_stuff){
        std::cout << i->m_name << " is gree and large" << std::endl;
    }

}

void Opened_closed_principle::Bad::test()
{
    std::cout << "================= Bad test ===================" << std::endl;

    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};

    std::vector<Product*> items = {&apple, &tree, &house};

    Product_filter pf;
    auto green_stuff = pf.by_color(items, Color::green);

    std::ostream_iterator<std::string> out_iter(std::cout, ", ");
    std::transform(green_stuff.begin(), green_stuff.end(), out_iter, [](Product* x)
    {
        return x->m_name + " is green";
    });
}

std::vector<Opened_closed_principle::Product*>
Opened_closed_principle::Good::Product_filer::filter(const std::vector<Product*>& a_items,
                                                     const Specification<Product>& a_spec)
{
    std::vector<Product*> result;
    for(auto& i : a_items){
        if(a_spec.is_satisfied(i)){
            result.push_back(i);
        }
    }
    return result;
}

bool Opened_closed_principle::Good::Color_specification::is_satisfied(Product* a_item) const
{
    return m_color == a_item->m_color;
}

bool Opened_closed_principle::Good::Size_specification::is_satisfied(Product* a_item) const
{
    return m_size == a_item->m_size;
}

template<typename T>
bool Opened_closed_principle::Good::And_specification<T>::is_satisfied(T* a_item) const
{
    return m_first.is_satisfied(a_item) && m_second.is_satisfied(a_item);
}
