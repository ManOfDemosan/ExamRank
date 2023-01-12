#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook{
    private:
        map<string, ASpell*> _book;
        SpellBook(const SpellBook &w);
        SpellBook &operator=(const SpellBook &w);
    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell *a);
        void forgetSpell(const string& name);
        ASpell* createSpell(const string& name);
};