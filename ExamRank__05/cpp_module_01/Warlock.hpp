#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"
using namespace std;

class Warlock{
    private:
        string _name;
        string _title;
        map<string, ASpell*> _spell;

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

        void learnSpell(ASpell *a);
        void forgetSpell(string name);
        void launchSpell(string name, ATarget &t);
};