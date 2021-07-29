#ifndef HEADER_H
#define HEADER_H
#include <string>
#include <vector>
using namespace std;

class Entities {
public:
	struct Enemy {
		int level, attack, health, defense;
		bool swarm = false, boss = false;
		string type, classType;
	};
	struct Player {
		string type = "_";
		int level = 0, health = 0, attack = 0, defense = 0, dungeon = 0, XP = 0;
	};
	Player newPlayer(string type, int health, int attack, int defense);
	void retrieveStats(Player& player);
	void saveStats(Player player);
	void printStats(Player player);
	void levelUp(Player& player);

	void is_boss(Enemy& enemy);
	void is_swarm(Enemy& enemy);
	void createEnemy(Enemy& enemy, int dungeon);

	void battlePrint(Player player, Enemy enemy);
	void usePotion(Player& player, int maxHealth,int healthGain);
	void playerStrike(Player player, Enemy& enemy);
	void enemyStrike(Player& player, Enemy enemy);
};


class Items {
public:
	struct Weapon {
		string type, quality;
		double accuracy;
		int attackBoost, level;
	};
	struct Armor {
		string type, quality;
		int defenseBoost, healthBoost, level;
	};
	

	void createWeapon(Weapon& weapon, int dungeon, string quality);
	void retrieveWeapon(Weapon& weapon);
	void saveWeapon(Weapon weapon);
	void printWeapon(Weapon weapon);
	
	void createArmor(Armor& armor, int dungeon, string quality);
	void retrieveArmor(Armor& armor);
	void saveArmor(Armor armor);
	void printArmor(Armor armor);

	void createPotion(vector <int>& potions, string quality);
	void retrievePotions(vector <int>& potions);
	void savePotions(vector <int> potions);
	void printPotions(vector <int> potions);

	string chestLootLevel();
	void chest(string chestType);
};
#endif