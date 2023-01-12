#pragma once

#include <iostream>
#include "ASpell.hpp"
using namespace std;

class Polymorph: public ASpell{
    public:
        Polymorph();
        ~Polymorph();
        virtual ASpell* clone() const;
};