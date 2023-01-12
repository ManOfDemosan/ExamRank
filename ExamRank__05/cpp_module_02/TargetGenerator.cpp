#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}
TargetGenerator::~TargetGenerator(){}

void TargetGenerator::learnTargetType(ATarget *a){
    _generator.insert(make_pair(a->getType(), a));
}

void TargetGenerator::forgetTargetType(const string& name){
    _generator.erase(name);
}

ATarget* TargetGenerator::createTarget(const string& name){
    map<string, ATarget*>::iterator it;
    it = _generator.find(name);
    if(it != _generator.end())
        return it->second;
    return NULL;
}
