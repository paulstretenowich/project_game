#include <iostream>
#include <cstdlib>
#include <vector>

#include "character.h"

Character::Character(std::string name_character, int life_character, int strength_character, int defense_character, int speed_character, int intelligence_character):
    name(name_character), life(life_character), strength(strength_character), defense(defense_character), speed(speed_character), intelligence(intelligence_character){}
