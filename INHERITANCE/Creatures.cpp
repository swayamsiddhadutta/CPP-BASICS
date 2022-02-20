// We’re going to write a simple game where you fight monsters. The goal of the game is to collect as much gold as you can before
// you die or get to level 20.
// Our program is going to consist of 3 classes: A Creature class, a Player class, and a Monster class. 
// Player and Monster both inherit from Creature.

// a) First create the Creature class. Creatures have 5 attributes: 
//          - A name (std::string), 
            // - a symbol (a char), 
            // - an amount of health (int), 
//          -  the amount of damage they do per attack (int), and 
            // - the amount of gold they are carrying (int). Implement these as class members. 
// Write a full set of getters (a get function for each member). Add three other functions: void reduceHealth(int) reduces the 
// Creature’s health by an integer amount. bool isDead() returns true when the Creature’s health is 0 or less. 
// void addGold(int) adds gold to the Creature.

// The orc has 3 health and is carrying 15 gold.
#include <iostream>
#include <string>

class Creature
{
protected:
    const std::string& m_name;
    char m_sym;
    int m_health;
    int m_damage;
    int m_gold;
public:
    Creature(const std::string& name, char sym, int health, int damage,int gold) : 
            m_name(name),m_sym(sym),m_health(health),m_damage(damage),m_gold(gold)
    {

    }

    const std::string getName() const
    {
        return m_name;
    }
    char getSym() const
    {
        return m_sym;
    }
    int getHealth() const
    {
        return m_health;
    }
    int getDamage() const
    {
        return m_damage;
    }
    int getGold() const
    {
        return m_gold;
    }

    void reduceHealth(int);
    bool isDead() const;
    void addGold(int);

    ~Creature()
    {

    }
};

void Creature::reduceHealth(int h)
{
    m_health = m_health - h;
}

bool Creature::isDead() const
{
    return (m_health <= 0);
}

void Creature::addGold(int g)
{
    m_gold = m_gold + g;
}

class Player : public Creature
{
private:
    int m_level;
public:
    Player(const std::string& name) : Creature(name,'@',10,1,0)
    {

    }

    int getLevel() const
    {
        return m_level;
    }

    void levelUp()
    {
        m_level++;
        m_damage++;   
    }

    bool hasWon() const
    {
        return (m_level == 20);
    }

};

class Monster : public Creature
{
    enum Type {
        DRAGON,
        ORC,
        SLIME,
        MAX_TYPES
    }
};

int main()
{
	// Creature o{ "orc", 'o', 4, 2, 10 };
	// o.addGold(5);
	// o.reduceHealth(1);

    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    Player p(name);
    std::cout << "Welcome, " << name << ".\n";
	std::cout << "The " << p.getName() << " has " << p.getHealth() << " health and are carrying " << p.getGold() << " gold.\n";

	return 0;
}