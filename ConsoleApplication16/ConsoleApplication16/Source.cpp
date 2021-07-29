#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <Windows.h>
#include "Header.h"
using namespace std;


void Items::createWeapon(Weapon& weapon, int dungeon, string quality) {
	int typeNum;
	//creates a basic beapon for new players
	if (dungeon == 0) {
		weapon.level = 1;
		weapon.type = "Sword";
		weapon.quality = "Common";
		weapon.accuracy = 0.9;
		weapon.attackBoost = 1;
	}
	//sets the stats of the weapon
	else {
		weapon.level = dungeon;
		weapon.quality = quality;
		typeNum = rand() % 3;
		//randomized weapon's type
		if (typeNum == 0) {
			weapon.type = "Sword";
			weapon.accuracy = 0.9;
			weapon.attackBoost = weapon.level / 9 + 1;
		}
		else if (typeNum == 1) {
			weapon.type = "Axe";
			weapon.accuracy = 0.8;
			weapon.attackBoost = weapon.level / 7 + 2;
		}
		else {
			weapon.type = "Maul";
			weapon.accuracy = 0.7;
			weapon.attackBoost = weapon.level / 5 + 3;
		}
	}
	//the quality is accepted in from another function that randomized item quality, and the quality determines boosts
	if (quality == "Legendary") {
		weapon.accuracy += 0.1;
		weapon.attackBoost += (rand() % (weapon.level/2+1)+(weapon.level/4));
	}
	else if (quality == "Epic") {
		weapon.accuracy += 0.05;
		weapon.attackBoost += (rand() % (weapon.level/2+1)+(weapon.level/8));
	}
	else if (quality == "Rare") {
		weapon.accuracy += 0.025;
		weapon.attackBoost += (rand() % (weapon.level/2+1)+(weapon.level/12));
	}
	return;
}
void Items::retrieveWeapon(Weapon& weapon) {
	//gets the weapon's stats from the previous save file
	ifstream retrieveWeapon;
	string propertyName;
	retrieveWeapon.open("PlayerWeapon.txt");
	while (!retrieveWeapon.eof()) {
		retrieveWeapon >> propertyName;
		if (propertyName == "Type")
			retrieveWeapon >> weapon.type;
		if (propertyName == "Quality")
			retrieveWeapon >> weapon.quality;
		if (propertyName == "Accuracy")
			retrieveWeapon >> weapon.accuracy;
		if (propertyName == "AttackBoost")
			retrieveWeapon >> weapon.attackBoost;
		if (propertyName == "Level")
			retrieveWeapon >> weapon.level;
	}
	retrieveWeapon.close();
	return;
}
void Items::saveWeapon(Weapon weapon) {
	//saves the weapon to be retrieved for later retreive functions
	ofstream saveWeapon;

	saveWeapon.open("PlayerWeapon.txt");
	saveWeapon << "Quality " << weapon.quality << endl
		<< "Type " << weapon.type << endl
		<< "Level " << weapon.level << endl
		<< "Accuracy " << weapon.accuracy << endl
		<< "AttackBoost " << weapon.attackBoost << endl << endl;
	saveWeapon.close();
	return;
}
void Items::printWeapon(Weapon weapon) {
	//displays the weapon's stats
	cout << weapon.quality << " " << weapon.type << endl
		<< "Level: " << weapon.level << endl
		<< "Accuracy: " << weapon.accuracy * 100 << "%" << endl
		<< "Attack Boost: " << weapon.attackBoost << endl << endl;
	return;
}

void Items::createArmor(Armor& armor,int dungeon, string quality) {
	int typeNum;
	//creates the armor for new players
	if (dungeon == 0) {
		armor.level = 1;
		armor.type = "Light";
		armor.quality = "Common";
		armor.defenseBoost = 0;
		armor.healthBoost = 1;
	}
	//the armor's stats are calculated here
	else {
		armor.level = dungeon;
		armor.quality = quality;
		typeNum = rand() % 3;
		//randomized the armor type
		if (typeNum == 0) {
			armor.type = "Light";
			armor.defenseBoost = ceil(armor.level / 6.0);
			armor.healthBoost = ceil((armor.level * 2) / 3.0);
		}
		else if (typeNum == 1) {
			armor.type = "Medium";
			armor.defenseBoost = ceil(armor.level / 4.0);
			armor.healthBoost = ceil(armor.level / 2.0);
		}
		else {
			armor.type = "Heavy";
			armor.defenseBoost = ceil(armor.level / 3.0);
			armor.healthBoost = ceil(armor.level / 3.0);
		}
	}
	//the armor's quality is determined by another function that randomizes quality, and the quality determinines boosts
	if (quality == "Legendary") {
		armor.defenseBoost += (rand() % (armor.level / 2 + 1) + armor.level / 8);
		armor.healthBoost += ((rand() % (armor.level / 2 + 1) + armor.level / 8) * 2);
	}
	else if (quality == "Epic") {
		armor.defenseBoost += (rand() % (armor.level / 2 + 1) + armor.level / 16);
		armor.healthBoost += ((rand() % (armor.level / 2 + 1) + armor.level / 16) * 2);
	}
	else if (quality == "Rare") {
		armor.defenseBoost += (rand() % (armor.level/2+1) + armor.level / 24);
		armor.healthBoost += ((rand() % (armor.level/2+1) + armor.level / 24) * 2);
	}
	return;
}
void Items::retrieveArmor(Armor& armor) {
	//retrieves the saved armor stats from a file
	ifstream retrieveArmor;
	string propertyName;
	retrieveArmor.open("PlayerArmor.txt");
	while (!retrieveArmor.eof()) {
		retrieveArmor >> propertyName;
		if (propertyName == "Type")
			retrieveArmor >> armor.type;
		if (propertyName == "Quality")
			retrieveArmor >> armor.quality;
		if (propertyName == "DefenseBoost")
			retrieveArmor >> armor.defenseBoost;
		if (propertyName == "HealthBoost")
			retrieveArmor >> armor.healthBoost;
		if (propertyName == "Level")
			retrieveArmor >> armor.level;
	}
	retrieveArmor.close();
	return;
}
void Items::saveArmor(Armor armor) {
	//saves the armor stats for later retrieve functions
	ofstream saveArmor;

	saveArmor.open("PlayerArmor.txt");
	saveArmor << "Quality " << armor.quality << endl
		<< "Type " << armor.type << endl
		<< "Level " << armor.level << endl
		<< "HealthBoost " << armor.healthBoost << endl
		<< "DefenseBoost " << armor.defenseBoost << endl << endl;
	saveArmor.close();
	return;
}
void Items::printArmor(Armor armor) {
	//prints the armor's stats
	cout << armor.quality << " " << armor.type << " Armor" << endl
		<< "Level: " << armor.level << endl
		<< "Health Boost: " << armor.healthBoost << endl
		<< "Defense Boost: " << armor.defenseBoost << endl << endl;
	return;
}

void Items::createPotion(vector <int>& potions, string quality) {
	//adds potions according to the randomized item quality function
	if (quality == "Common") {
		cout << "You've received a Small Potion." << endl<<endl;
		potions.at(0)++;
	}
	else if (quality == "Rare") {
		cout << "You've received a Medium Potion." << endl<<endl;
		potions.at(1)++;
	}
	else if (quality == "Epic") {
		cout << "You've received a Large Potion." << endl<<endl;
		potions.at(2)++;
	}
	else if (quality == "Legendary") {
		cout << "You've received a Revive." << endl<<endl;
		potions.at(3)++;
	}
	return;
}
void Items::retrievePotions(vector <int>& potions) {
	//Retrieves the amount of potions a player gathered from a save file
	ifstream retrievePotions;
	string potionSize;
	retrievePotions.open("PlayerPotions.txt");
	while (!retrievePotions.eof()) {
		retrievePotions >> potionSize;
		if (potionSize == "Small")
			retrievePotions >> potions.at(0);
		if (potionSize == "Medium")
			retrievePotions >> potions.at(1);
		if (potionSize == "Large")
			retrievePotions >> potions.at(2);
		if (potionSize == "Revive")
			retrievePotions >> potions.at(3);
	}
	retrievePotions.close();
	return;
}
void Items::savePotions(vector <int> potions) {
	//saves the current amount of potions the player has to a file for future retrieve functions
	ofstream savePotions;
	savePotions.open("PlayerPotions.txt");
	savePotions << "Small " << potions.at(0) << endl
		<< "Medium " << potions.at(1) << endl
		<< "Large " << potions.at(2) << endl
		<< "Revive " << potions.at(3) << endl << endl;
	savePotions.close();
	return;
}
void Items::printPotions(vector <int> potions) {
	//prints the amount of potions a player has
	cout << "Small Potions: " << potions.at(0) << endl
		<< "Medium Potions: " << potions.at(1) << endl
		<< "Large Potions: " << potions.at(2) << endl
		<< "Revives: " << potions.at(3) << endl;
	return;
}

string Items::chestLootLevel()
{
	//randomizes the quality of gear received in chests
	string chestLootLevel;
	int Rarity;
	Rarity = (rand() % 100) + 1;

	if (Rarity <= 60)
		chestLootLevel = "Common";

	else if (Rarity > 60 && Rarity <= 80)
		chestLootLevel = "Rare";

	else if (Rarity > 80 && Rarity <= 95)
		chestLootLevel = "Epic";

	else if (Rarity > 95)
		chestLootLevel = "Legendary";
	else
		chestLootLevel = "Common";

	return chestLootLevel;
}

Entities::Player Entities::newPlayer(string type, int health, int attack, int defense) {
	//creates a new player save data
	Player player;
	player.type = type;
	player.level = 1;
	player.health = health;
	player.attack = attack;
	player.defense = defense;
	player.dungeon = 1;
	player.XP = 0;
	return player;
}
void Entities::retrieveStats(Player& player) {
	//retrieves the player's stats from a save file
	ifstream retrieveStats;
	string statName;

	retrieveStats.open("PlayerStats.txt");
	while (!retrieveStats.eof()) {
		retrieveStats >> statName;
		if (statName == "PlayerClass")
			retrieveStats >> player.type;
		if (statName == "Level")
			retrieveStats >> player.level;
		if (statName == "Health")
			retrieveStats >> player.health;
		if (statName == "Attack")
			retrieveStats >> player.attack;
		if (statName == "Defense")
			retrieveStats >> player.defense;
		if (statName == "Dungeon")
			retrieveStats >> player.dungeon;
		if (statName == "XP")
			retrieveStats >> player.XP;
	}
	retrieveStats.close();
	return;
}
void Entities::saveStats(Player player) {
	//saves the player's current stats for future retrieval functions
	ofstream saveStats;

	saveStats.open("PlayerStats.txt");
	saveStats << "PlayerClass " << player.type << endl
		<< "Level " << player.level << endl
		<< "Health " << player.health << endl
		<< "Attack " << player.attack << endl
		<< "Defense " << player.defense << endl
		<< "Dungeon " << player.dungeon << endl
		<< "XP " << player.XP << endl;
	saveStats.close();
	return;
}
void Entities::printStats(Player player) {
	//displays the player's stats
	cout << player.type << endl
		<< "Level: " << player.level << endl
		<< "Health: " << player.health << endl
		<< "Attack: " << player.attack << endl
		<< "Defense: " << player.defense << endl
		<< "Dungeon: " << player.dungeon << endl
		<< "XP: " << player.XP <<"/"<<player.level*player.level*10 << endl << endl;
	return;
}
void Entities::levelUp(Player& player)
{
	//if a player levels up, the function updates the stats
	string choice;
	player.level++;
	cout << "Congratulations! You leveled up!" << endl;
	cout << "You are now level " << player.level <<"."<< endl;
	do {
		cout << "Pick either health, attack, or defense to upgrade: ";
		choice.clear();
		cin >> choice;
		choice.at(0) = toupper(choice.at(0));
		if (choice == "Health") {
			if (player.type == "Juggernaut")
				player.health += 4;
			else
				player.health+=2;
			cout << "Your health is now " << player.health <<"."<< endl << endl;
		}
		else if (choice == "Attack") {
			if (player.type == "Warrior")
				player.attack += 2;
			else
				player.attack++;
			cout << "Your attack is now " << player.attack <<"."<< endl << endl;
		}
		else if (choice == "Defense") {
			if (player.type == "Knight")
				player.defense += 2;
			else
				player.defense++;
			cout << "Your defense is now " << player.defense <<"."<< endl << endl;
		}
		else {
			cout << "Invalid choice." << endl;
			choice.clear();
		}
	} while (choice.empty());
	player.XP = 0;
}

void Entities::is_boss(Enemy& enemy) {
	//if the enemy is a boss, this function changes the data type
	enemy.boss = true;
	return;
}
void Entities::is_swarm(Enemy& enemy) {
	//if the enemy is part of a swarm, this changes the data type
	enemy.swarm = true;
	return;
}
void Entities::createEnemy(Enemy& enemy, int dungeon) {
	//randomizes enemy creation
	int classNum = rand() % 4;
	//enemy types are determined by floor level; it changes every 5 floors
	//if the enemy is a boss, the name suggests it
	switch (dungeon % 20) {
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		enemy.type = "Skeletal ";
		if (enemy.boss && !enemy.swarm)
			enemy.type = "Necromancer ";
		break;
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
		enemy.type = "Dark ";
		if (enemy.boss && !enemy.swarm)
			enemy.type = "Dark General ";
		break;
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		enemy.type = "Demonic ";
		if (enemy.boss && !enemy.swarm)
			enemy.type = "Fallen ";
		break;
	case 16:
	case 17:
	case 18:
	case 19:
	case 0:
		enemy.type = "Vampiric ";
		if (enemy.boss && !enemy.swarm)
			enemy.type = "Vampire Lord ";
		break;
	}
	//randomizes class number
	switch (classNum) {
	case 0:
		enemy.classType = "Juggernaut";
		enemy.type += "Juggernaut";
		break;
	case 1:
		enemy.classType = "Warrior";
		enemy.type += "Warrior";
		break;
	case 2:
		enemy.classType = "Knight";
		enemy.type += "Knight";
		break;
	default:
		if (!enemy.boss) {
			enemy.classType = "Slime";
			enemy.type += "Slime";
		}
		else {
			enemy.classType = "Warlock";
			enemy.type += "Warlock";
		}
		break;
	}
	//the level of the enemy is determined by the dungeon it's found in. if it's a swarm or boss, the levels are updated to show it
	enemy.level = dungeon;
	if (enemy.swarm)
		enemy.level = (enemy.level * 4) / 5;
	if (enemy.boss)
		enemy.level = (enemy.level * 5) / 4;
	if (enemy.level == 0)
		enemy.level = 1;
	//the enemy's stats reflect its class type (juggernauts have high health, warrior have high attack, and knights have high defense)
	if (classNum == 0) {
		enemy.health = enemy.level + 10;
		enemy.attack = enemy.level / 3 + 10;
		enemy.defense = enemy.level / 3 + 10;
	}
	else if (classNum == 1) {
		enemy.health = enemy.level / 3 + 10;
		enemy.attack = enemy.level + 10;
		enemy.defense = enemy.level / 3 + 10;
	}
	else if (classNum == 2) {
		enemy.health = enemy.level / 3 + 10;
		enemy.attack = enemy.level / 3 + 10;
		enemy.defense = enemy.level + 10;
	}
	else {
		enemy.health = enemy.level / 2 + 10;
		enemy.attack = enemy.level / 2 + 10;
		enemy.defense = enemy.level / 2 + 10;
	}
	enemy.health *= 2;
	return;
}

void Entities::battlePrint(Player player, Enemy enemy) {
	//prints both the enemy's and the player's stats for reference
	cout << setw(20) << "Your stats:" << setw(24) << "Enemy's stats:" << endl
		<< setw(10) << "Level: " << setw(10) << player.level << setw(24) << enemy.level << endl
		<< setw(10) << "Health: " << setw(10) << player.health << setw(24) << enemy.health << endl
		<< setw(10) << "Attack: " << setw(10) << player.attack << setw(24) << enemy.attack << endl
		<< setw(10) << "Defense: " << setw(10) << player.defense << setw(24) << enemy.defense << endl << endl;
	Sleep(1000);
	return;
}
void Entities::usePotion(Player& player,int maxHealth, int healthGain) {
	//adds health points to the player's health after using a potion; checks if the potion will give the player too much health
	if (player.health + healthGain > maxHealth)
		player.health = maxHealth;
	else
		player.health += healthGain;
	return;
}
void Entities::playerStrike(Player player, Enemy& enemy) {
	//player attacks here; checks for data ranges
	//if the attack is greater than the health that the enemy has left over, the attack deals the remainding health's worth of damage
	if (player.attack >= (enemy.health + enemy.defense)) {
		cout << "You do " << enemy.health << " damage!" << endl;
		enemy.health = 0;
	}
	//if the enemy's defense is greater than the player's attack, the player will attack for 1
	else if (player.attack <= enemy.defense) {
		enemy.health -= 1;
		cout << "You do 1 damage!" << endl;
	}
	//the program takes into account the defense, attack, and health of both the enemy and the player to figure out the total damage dealth
	else {
		enemy.health -= (player.attack - enemy.defense);
		cout << "You do " << player.attack - enemy.defense<< " damage!" << endl;
	}
	return;
}
void Entities::enemyStrike(Player& player, Enemy enemy)
//enemy attacks here; checks for data ranges
{
	//if the attack is greater than the health that the player has left over, the attack deals the remainding health's worth of damage
	if (enemy.attack >= (player.health + player.defense)) {
		cout << "The "<<enemy.type<<" does " << player.health << " damage!" << endl;
		player.health = 0;
	}
	//if the player's defense is greater than the enemy's attack, the enemy will attack for 1
	else if (enemy.attack <= player.defense) {
		player.health -= 1;
		cout << "The " << enemy.type << " does 1 damage!" << endl;
	}
	//the program takes into account the defense, attack, and health of both the enemy and the player to figure out the total damage dealth
	else {
		player.health -= (enemy.attack - player.defense);
		cout << "The " << enemy.type << " does " << enemy.attack - player.defense << " damage!" << endl;
	}
	return;
}
