#include "ASpell.hpp"

ASpell::ASpell(){}
ASpell::ASpell(const ASpell &a): _name(a.getName()), _effects(a.getEffects()){}
ASpell::ASpell(string name, string effects): _name(name), _effects(effects){}
ASpell &ASpell::operator=(const ASpell &a){
    _name = a.getName();
    _effects = a.getEffects();
    return *this;
}
ASpell::~ASpell(){}

string ASpell::getName() const{return _name;}
string ASpell::getEffects() const{return _effects;}

void ASpell::launch(const ATarget &t){
    return t.getHitBySpell(*this);
}

