#include "Fireball.hpp"

Fireball::Fireball(): ASpell("Fireball", "Fireballed"){}
Fireball::~Fireball(){}
ASpell* Fireball::clone() const{
   return new Fireball;
}