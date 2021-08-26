//
// Author: JakubSzwedowicz
// Date: 17.08.2021.
// e-mail: kuba.szwedowicz@gmail.com 
//

#ifndef DESIGN_PATTERNS_OPENED_CLOSED_PRINCIPLE_HPP
#define DESIGN_PATTERNS_OPENED_CLOSED_PRINCIPLE_HPP

#include <string>
#include <vector>

class Opened_closed_principle
{
private:
    enum class Color
    {
        red, green, blue
    };
    enum class Size
    {
        small, medium, large
    };
    struct Product
    {
        std::string m_name;
        Color m_color;
        Size m_size;
    };
public:
    static void test();

    struct Good
    {
        static void test();

    private:
        // Specification Pattern - Enterprise pattern
        template<typename T>
        struct Specification
        {
            virtual ~Specification() = default;

            virtual bool is_satisfied(T* a_item) const = 0;

        };

        template<typename T>
        struct Filter
        {
            virtual ~Filter() = default;

            virtual std::vector<T*> filter(const std::vector<T*>& a_items, const Specification<T>& a_spec) = 0;
        };

        struct Product_filer : Filter<Product>
        {
            virtual ~Product_filer() = default;

            std::vector<Product*>
            filter(const std::vector<Product*>& a_items, const Specification<Product>& a_spec) override;
        };

    public:
        struct Color_specification : Specification<Product>
        {
            Color m_color;

            Color_specification(Color a_color) : m_color(a_color) {};

            bool is_satisfied(Product* a_item) const override;
        };

        struct Size_specification : Specification<Product>
        {
            Size m_size;

            Size_specification(Size a_size) : m_size(a_size) {};

            bool is_satisfied(Product* a_item) const override;
        };

        template <typename T>
        struct And_specification : Specification<T>
        {
            const Specification<T>& m_first;
            const Specification<T>& m_second;

            And_specification(const Specification<T>& a_first, const Specification<T>& a_second)
                    : m_first(a_first), m_second(a_second)
            {}

            bool is_satisfied(T* a_item) const override;

        };

    };

    struct Bad
    {
        static void test();

        struct Product_filter
        {
            std::vector<Product*> by_color(const std::vector<Product*>& a_items, Color a_color);

            std::vector<Product*> by_size(const std::vector<Product*>& a_items, Size a_size);

            std::vector<Product*> by_size_and_color(const std::vector<Product*>& a_items, Size a_size, Color a_color);

        };
    };
};




#endif //DESIGN_PATTERNS_OPENED_CLOSED_PRINCIPLE_HPP
