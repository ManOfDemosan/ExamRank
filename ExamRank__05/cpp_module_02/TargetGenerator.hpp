#pragma once

#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator{
    private:
        map<string, ATarget*> _generator;
        TargetGenerator(const TargetGenerator &w);
        TargetGenerator &operator=(const TargetGenerator &w);
    public:
        TargetGenerator();
        ~TargetGenerator();

       void learnTargetType(ATarget*a);
       void forgetTargetType(string const &name);
       ATarget* createTarget(string const &name);
};