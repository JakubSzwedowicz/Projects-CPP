//
// Author: JakubSzwedowicz
// Date: 17.08.2021.
// e-mail: kuba.szwedowicz@gmail.com 
//

#include <fstream>
#include "Single_Responsibility_Principle.hpp"

void Single_Responsibility_Principle::Journal::add_entry(const std::string& a_entry)
{
    static int count = 1;
    m_entries.push_back(std::to_string(count++) + ": " + a_entry);
}


void Single_Responsibility_Principle::test()
{
    Single_Responsibility_Principle::Good::test();
    Single_Responsibility_Principle::Bad::test();
}

void Single_Responsibility_Principle::Good::test()
{
    Good::Good_journal j1{"Dear Diary"};
    j1.add_entry("I ate a bug");
    j1.add_entry("I saw a cat");

    Single_Responsibility_Principle::Good::Persistence_manager::save(j1, "saved_good_diary");
}

void Single_Responsibility_Principle::Bad::test()
{
    Bad::Bad_journal j1{"Dear Diary"};
    j1.add_entry("I ate a bug");
    j1.add_entry("I saw a cat");
    j1.save("saved_bad_diary");

}

void Single_Responsibility_Principle::Bad::Bad_journal::save(const std::string& a_filename)
{
    std::ofstream file(a_filename);
    if (file.is_open())
    {
        for (auto& e : m_entries)
        {
            file << e << std::endl;
        }
        file.close();
    }
}

void Single_Responsibility_Principle::Good::Persistence_manager::save(
        const Single_Responsibility_Principle::Journal& a_journal, const std::string& a_filename)
{
    std::ofstream file(a_filename);
    if (file.is_open())
    {
        for (auto& e : a_journal.m_entries)
        {
            file << e << std::endl;
        }
        file.close();
    }
}
