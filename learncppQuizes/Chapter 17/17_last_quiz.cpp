// NO EXTRA CREDIT DONE I.E POTIONS

#include <iostream>
#include <string>
#include <array>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <random>

// Our program is going to consist of 3 classes: a Creature class, a Player class, and a Monster class. 
// Player and Monster both inherit from Creature.


// Creature class with 5 attributes
class Creature
{
// Protected member variables, accessible only to inside of class hierarchy.
protected:
	std::string m_name{};
	char m_symbol{};
	int m_health{};
	int m_dmg{};
	int m_gold{};

public:
	// Constructors
	Creature(std::string_view name, char symbol, int hp, int dmg, int gold)
		: m_name{ name }, m_symbol{ symbol }, m_health{ hp }, m_dmg{ dmg }, m_gold{ gold } {}

	// Return member values
	const std::string& getName() const { return m_name; }
	char getSymbol() const { return m_symbol; }
	int getHealth() const { return m_health; }
	int getDmg() const { return m_dmg; }
	int getGold() const { return m_gold; }

	// Void functions
	void reduceHealth(int value) { m_health -= value; }
	bool isDead() { return (m_health <= 0); }
	void addGold(int value) { m_gold += value; }
};

// Player class
class Player : public Creature
{
protected: 
	int m_level{ 1 };

public:
	Player(std::string name) : Creature(name, '@', 10, 1, 0) {}

	int getLevel() const { return m_level; }

	void levelUp() { ++m_level; ++m_gold; }

	bool hasWon() { return (m_level == 20); }
};

// Monster class
class Monster : public Creature
{	
public:
// Enum type for 3 monsters
	enum class Type
	{
		dragon, orc, slime, max_types
	};

	// Create monsters
	Monster(Type type) : Creature{ getDefaultCreaturer(type) } {}

	static Monster getRandomMonster()
	{
		std::random_device	rd;
		std::mt19937 mt{rd()};

		std::uniform_int_distribution<int> dist(0, static_cast<int>(Type::max_types) - 1);
		return static_cast<Type>(dist(mt));
	}

private:
	// Look-up function -> getDefaultCreature(Type::dragon).getGold()
	static const Creature& getDefaultCreaturer(Type type)
	{
		static const std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData {
			{
				{"dragon", 'D', 20, 4, 100 },
				{ "orc", 'o', 4, 2, 25 },
				{ "slime", 's', 1, 1, 10 }
			}
		};
		return monsterData.at(static_cast<std::size_t>(type));
	}
};

void fightMonster(Player& player);
void attackMonster(Monster& monster, Player& player);
void attackPlayer(Monster& monster, Player& player);


void fightMonster(Player& player)
{

	Monster monster{ Monster::getRandomMonster() };
	std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ").\n";

	while (!player.isDead() && !monster.isDead())
	{
		std::cout << "(R)un or F(ight): ";
		char input;
		std::cin >> input;

		// Creature(std::stringw name, char symbol, int hp, int dmg, int gold) (input == 'r')

		if (input == 'r' || "R")
		{
			if (std::rand() % 2 == 0)
			{
				std::cout << "You have successfully fled.\n";
				return;
			}
			else
			{
				std::cout << "You failed to fled.\n";
				attackPlayer(monster, player);
				continue;
			}
		}

		if (input == 'f' || "F")
		{
			attackMonster(monster, player);
			attackPlayer(monster, player);
		}
	}
}

void attackMonster(Monster& monster, Player& player)
{
	if (player.isDead())
		return;
	
	monster.reduceHealth(player.getDmg());
	std::cout << "You hit the " << monster.getName() << " for " << player.getDmg() << " damage\n";

	if (monster.isDead())
	{
		std::cout << "You killed the " << monster.getName() << '\n';
		player.levelUp();
		std::cout << "You are now level " << player.getLevel() << "!\n";
		std::cout << "You found " << monster.getGold() << " gold.\n";
		player.addGold(monster.getGold());
	}
}

void attackPlayer(Monster& monster, Player& player)
{
	if (monster.isDead())
		return;
	
	player.reduceHealth(monster.getDmg());

	std::cout << "The monster hit you for " << monster.getDmg() << " damage!\n";
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock\

	std::cout << "Enter your name: ";
	std::string name{};
	std::cin >> name;

	std::cout << "Welcome, " << name << '\n';
	Player player{ name };

	while (!player.hasWon() && !player.isDead())
	{
		fightMonster(player);
	}

	if (player.isDead())
	{
		std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold.\n";
		std::cout << "Too bad you can't take it with you!\n";
	}

	else
	{
		std::cout << "Congratulations! You have reached level 20 and won the game.\n";
		std::cout << "You have " << player.getGold() << " gold.\n";
	}

	return 0;
}
