
#include "item.hpp"

Item::Item() : 
	_ID(0), _slotID(0), _name(""), _description(""), 
	_level(0), _runeCount(0), 
	_rarity(Rarity::COMMON), 
	_patch_version(0.0),
	_HP(0), _AP(0), _MP(0), 
	_agility(0), _strength(0), _intelligence(0), _chance(0), 
	_range(0), _control(0), _wisdom(0), _prospecting(0), _initiative(0), 
	_dodge(0), _lock(0), _block(0), 
	_critical_hit_p(0), _critical_hit_damage(0), 
	_kit_skill(0), 
	_remove_AP_p(0), _heal_p(0), 
	_backstab_damage_p(0), _CMC_damage_p(0), 
	_resis_MP_loss(0), _resis_behind(0), _resis_heal(0)
{
}

Item::Item(unsigned int ID, unsigned int slotID, std::string name, std::string description, unsigned int level) :
	_ID(ID), _slotID(slotID), _name(name), _description(description), 
	_level(level), _runeCount(0), 
	_rarity(Rarity::COMMON),
	_patch_version(0.0),
	_HP(0), _AP(0), _MP(0), 
	_agility(0), _strength(0), _intelligence(0), _chance(0), 
	_range(0), _control(0), _wisdom(0), _prospecting(0), _initiative(0), 
	_dodge(0), _lock(0), _block(0), 
	_critical_hit_p(0), _critical_hit_damage(0), 
	_kit_skill(0), 
	_remove_AP_p(0), _heal_p(0), 
	_backstab_damage_p(0), _CMC_damage_p(0), 
	_resis_MP_loss(0), _resis_behind(0), _resis_heal(0)
{
}

Item::~Item() {
}

unsigned int Item::get_ID() {
	return _ID;
}

unsigned int Item::get_slotID() {
	return _slotID;
}

std::string Item::get_name() {
	return _name;
}

std::string Item::get_description() {
	return _description;
}

unsigned int Item::get_level() {
	return _level;
}

unsigned int Item::get_runeCount() {
	return _runeCount;
}

float Item::get_patch_version() {
	return _patch_version;
}

Rarity Item::get_rarity() {
	return _rarity;
}

int Item::get_HP() {
	return _HP;
}

int Item::get_AP() {
	return _AP;
}

int Item::get_MP() {
	return _MP;
}

int Item::get_agility() {
	return _agility;
}

int Item::get_strength() {
	return _strength;
}

int Item::get_intelligence() {
	return _intelligence;
}

int Item::get_chance() {
	return _chance;
}

int Item::get_range() {
	return _range;
}

int Item::get_control() {
	return _control;
}

int Item::get_wisdom() {
	return _wisdom;
}

int Item::get_prospecting() {
	return _prospecting;
}

int Item::get_initiative() {
	return _initiative;
}

int Item::get_dodge() {
	return _dodge;
}

int Item::get_lock() {
	return _lock;
}

int Item::get_block() {
	return _block;
}

int Item::get_critical_hit_p() {
	return _critical_hit_p;
}

int Item::get_critical_hit_damage() {
	return _critical_hit_damage;
}

int Item::get_kit_skill() {
	return _kit_skill;
}

int Item::get_remove_AP_p() {
	return _remove_AP_p;
}

int Item::get_heal_p() {
	return _heal_p;
}

int Item::get_backstab_damage_p() {
	return _backstab_damage_p;
}

int Item::get_CMC_damage_p() {
	return _CMC_damage_p;
}

int Item::get_resis_MP_loss() {
	return _resis_MP_loss;
}

int Item::get_resis_behind() {
	return _resis_behind;
}

int Item::get_resis_heal() {
	return _resis_heal;
}

std::map<Element, int> Item::get_damage_p() {
	return _damage_p;
}

std::map<Element, int> Item::get_resistance_p() {
	return _resistance_p;
}

int Item::get_damage_p_all() {
	return _damage_p[Element::ALL];
}

int Item::get_damage_p_fire() {
	return _damage_p[Element::FIRE];
}

int Item::get_damage_p_water() {
	return _damage_p[Element::WATER];
}

int Item::get_damage_p_earth() {
	return _damage_p[Element::EARTH];
}

int Item::get_damage_p_air() {
	return _damage_p[Element::AIR];
}

int Item::get_resistance_p_all() {
	return _resistance_p[Element::ALL];
}

int Item::get_resistance_p_fire() {
	return _resistance_p[Element::FIRE];
}

int Item::get_resistance_p_water() {
	return _resistance_p[Element::WATER];
}

int Item::get_resistance_p_earth() {
	return _resistance_p[Element::EARTH];
}

int Item::get_resistance_p_air() {
	return _resistance_p[Element::AIR];
}

