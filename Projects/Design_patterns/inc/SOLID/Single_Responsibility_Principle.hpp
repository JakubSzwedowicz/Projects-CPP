//
// Author: JakubSzwedowicz
// Date: 17.08.2021.
// e-mail: kuba.szwedowicz@gmail.com 
//

#ifndef DESIGN_PATTERNS_SINGLE_RESPONSIBILITY_PRINCIPLE_HPP
#define DESIGN_PATTERNS_SINGLE_RESPONSIBILITY_PRINCIPLE_HPP

#include <string>
#include <vector>

class Single_Responsibility_Principle
{
private:
    struct Journal
    {
        std::string m_title;
        std::vector<std::string> m_entries;

        Journal(const std::string& a_title)
                : m_title(a_title)
        {};

        void add_entry(const std::string& a_entry);
    };

public:
    static void test();

    struct Good
    {
        static void test();

        struct Good_journal : public Journal
        {
            Good_journal(const std::string& a_title)
                    : Journal(a_title)
            {};
        };

        struct Persistence_manager
        {
            static void save(const Journal& a_journal, const std::string& a_filename);
        };
    };

    struct Bad
    {
        static void test();

        struct Bad_journal : public Journal
        {
            Bad_journal(const std::string& a_title)
                    : Journal(a_title)
            {};

            // You want to save the journal
            void save(const std::string& a_filename);
        };
    };
};

#endif //DESIGN_PATTERNS_SINGLE_RESPONSIBILITY_PRINCIPLE_HPP
