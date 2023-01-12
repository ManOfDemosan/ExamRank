#pragma once

#include <iostream>
using namespace std;

class Warlock{
    private:
        string _name;
        string _title;

        Warlock();
        Warlock(const Warlock &w);
        Warlock &operator=(const Warlock &w);
    public:
        Warlock(string name, string title);
        ~Warlock();

        string getName() const;
        string getTitle() const;

        void setTitle(const string title);
        void introduce() const;

};