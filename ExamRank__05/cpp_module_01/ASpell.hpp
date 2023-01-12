#pragma once

#include <iostream>
#include "ATarget.hpp"
using namespace std;

class ATarget;

class ASpell{
    protected:
        string _name;
        string _effects;
    public:
        ASpell();
        ASpell(const ASpell &a);
        ASpell(string name, string effects);
        ASpell &operator=(const ASpell &a);
        virtual ~ASpell();

        string getName() const;
        string getEffects() const ;

        virtual ASpell* clone() const = 0;
        void launch(const ATarget &t);

};