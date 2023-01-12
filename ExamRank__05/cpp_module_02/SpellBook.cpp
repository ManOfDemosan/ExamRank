#include "SpellBook.hpp"

SpellBook::SpellBook(){}
SpellBook::~SpellBook(){}

void SpellBook::learnSpell(ASpell *a){
    _book.insert(make_pair(a->getName(), a));
}

void SpellBook::forgetSpell(const string& name){
    _book.erase(name);
}

ASpell* SpellBook::createSpell(const string& name){
    map<string, ASpell*>::iterator it;
    it = _book.find(name);
    if(it != _book.end())
        return it->second;
    return NULL;
}
