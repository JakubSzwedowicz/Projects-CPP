#include <iostream>
#include "Money_Change.hpp"
#include <iterator>

template<typename T>
std::ostream& operator<<(std::ostream& a_out, const std::vector<T>& v)
{
    for(auto& e : v){
        a_out << e << " ";
    }
    return a_out;
}

int main() {
    auto vec = get_change(3453);
    std::cout << vec << std::endl;
    return 0;
}
