#pragma once

#include <iostream>
#include "ASpell.hpp"
using namespace std;

class ASpell;

class ATarget{
    protected:
        string _type;

    public:
        ATarget();
        ATarget(const ATarget &a);
        ATarget(string type);
        ATarget &operator=(const ATarget &a);
        virtual ~ATarget();

        string getType() const;

        virtual ATarget* clone() const = 0;
        void getHitBySpell(ASpell &a) const;
};