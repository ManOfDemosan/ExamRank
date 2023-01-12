#include "ATarget.hpp"

ATarget::ATarget(){}
ATarget::ATarget(const ATarget &a): _type(a.getType()){}
ATarget::ATarget(string name): _type(name){}
ATarget &ATarget::operator=(const ATarget &a){
    _type = a.getType();
    return *this;
}
ATarget::~ATarget(){}

string ATarget::getType() const{return _type;}

void ATarget::getHitBySpell(ASpell &a)const{
    cout << _type << " has been " << a.getEffects() << "!\n";
}

