
#include <map>
#include "element.hpp"
#include "rarity.hpp"

#ifndef ITEM_H
#define ITEM_H

class Item {

	public:
		Item();
		Item(unsigned int _ID, unsigned int _slotID, std::string name, std::string description, unsigned int level);
		virtual ~Item();

		//var getters
		unsigned int get_ID();
		unsigned int get_slotID();
		std::string get_name();
		std::string get_description();

		unsigned int get_level();
		unsigned int get_runeCount();
		float get_patch_version();
		Rarity get_rarity();

		int get_HP();
		int get_AP();
		int get_MP();
		int get_agility();
		int get_strength();
		int get_intelligence();
		int get_chance();
		int get_range();
		int get_control();
		int get_wisdom();
		int get_prospecting();
		int get_initiative();
		int get_dodge();
		int get_lock();
		int get_block();
		int get_critical_hit_p();
		int get_critical_hit_damage();
		int get_kit_skill();
		int get_remove_AP_p();
		int get_heal_p();
		int get_backstab_damage_p();
		int get_CMC_damage_p();
		int get_resis_MP_loss();
		int get_resis_behind();
		int get_resis_heal();
		
		std::map<Element, int> get_damage_p();
		std::map<Element, int> get_resistance_p();

		int get_damage_p_all();
		int get_damage_p_fire();
		int get_damage_p_water();
		int get_damage_p_earth();
		int get_damage_p_air();
		
		int get_resistance_p_all();
		int get_resistance_p_fire();
		int get_resistance_p_water();
		int get_resistance_p_earth();
		int get_resistance_p_air();

		//var setters
		void set_ID(unsigned int ID);
		void set_slotID(unsigned int slotID);
		void set_name(std::string name);
		void set_description(std::string description);
		void set_level(unsigned int level);

		void set_runeCount(unsigned int runeCount);
		void set_rarity(Rarity rarity);
		void set_patch_version(float patch_version);

		void set_HP(int HP);
		void set_AP(int AP);
		void set_MP(int MP);
		void set_agility(int agility);
		void set_strength(int strength);
		void set_intelligence(int intelligence);
		void set_chance(int chance);
		void set_range(int range);
		void set_control(int control);
		void set_wisdom(int wisdom);
		void set_prospecting(int prospecting);
		void set_initiative(int initiative);
		void set_dodge(int dodge);
		void set_lock(int lock);
		void set_block(int block);
		void set_critical_hit_p(int critical_hit_p);
		void set_critical_hit_damage(int critical_hit_damage);
		void set_kit_skill(int kit_skill);
		void set_remove_AP_p(int remove_AP_p);
		void set_heal_p(int heal_p);
		void set_backstab_damage_p(int backstab_damage_p);
		void set_CMC_damage_p(int CMC_damage_p);
		void set_resis_MP_loss(int resis_MP_loss);
		void set_resis_behind(int resis_behind);
		void set_resis_heal(int resis_heal);
		
		void set_damage_p_all(int damage_p_all);
		void set_damage_p_fire(int damage_p_fire);
		void set_damage_p_water(int damage_p_water);
		void set_damage_p_earth(int damage_p_earth);
		void set_damage_p_air(int damage_p_air);
		
		void set_resistance_p_all(int resistance_p_all);
		void set_resistance_p_fire(int resistance_p_fire);
		void set_resistance_p_water(int resistance_p_water);
		void set_resistance_p_earth(int resistance_p_earth);
		void set_resistance_p_air(int resistance_p_air);

	protected:
		unsigned int _ID;
		unsigned int _slotID;
		std::string _name;
		std::string _description;

		unsigned int _level;
		unsigned int _runeCount;

		Rarity _rarity;
		float _patch_version;

		//int because it can be negative
		int _HP;
		int _AP, _MP;

		std::map<Element, int> _damage_p;
		std::map<Element, int> _resistance_p;

		int _agility, _strength, _intelligence, _chance;
		int _range, _control, _wisdom, _prospecting, _initiative;
		int _dodge, _lock, _block;
		int _critical_hit_p, _critical_hit_damage;
		int _kit_skill;

		int _remove_AP_p, _heal_p;
		int _backstab_damage_p, _CMC_damage_p;
		int _resis_MP_loss, _resis_behind, _resis_heal; 
};

#endif /* end of include guard: ITEM_H */
