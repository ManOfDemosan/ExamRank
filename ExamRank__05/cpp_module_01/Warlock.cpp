#include "Warlock.hpp"

Warlock::Warlock(string name, string title): _name(name), _title(title){
    cout << _name << ": This looks like another boring day.\n";
}

Warlock::~Warlock(){
    cout << _name << ": My job here is done!\n";
}

string Warlock::getName() const{return _name;}
string Warlock::getTitle() const{return _title;}

void Warlock::setTitle(const string title){
    _title = title;
}

void Warlock::introduce() const{
    cout << _name << ": I am " << _name << ", " << _title << "!\n";
}

void Warlock::learnSpell(ASpell *a){
    _spell.insert(make_pair(a->getName(), a));
}
void Warlock::forgetSpell(string name){
    _spell.erase(name);
}
void Warlock::launchSpell(string name, ATarget &t){
    map<string, ASpell*>::iterator it;
    it = _spell.find(name);
    if(it != _spell.end())
        it->second->launch(t);
}
