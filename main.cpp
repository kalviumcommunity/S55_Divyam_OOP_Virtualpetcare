#include <iostream>
#include <string>

// Base class
class Pet {
private:
    std::string name;
    int age;
    int health;
    int happiness;

    static int totalPets;
    static int totalFoodGiven;

protected:
    void incrementFoodGiven(int amount) { totalFoodGiven += amount; }

public:
    // Default constructor
    Pet() : name("Unknown"), age(0), health(100), happiness(100) {
        totalPets++;
        std::cout << "Default Constructor Called: A new pet has been created!" << std::endl;
    }

    // Parameterized constructor
    Pet(const std::string& petName, int petAge) : name(petName), age(petAge), health(100), happiness(100) {
        totalPets++;
        std::cout << "Parameterized Constructor Called: A new pet named " << name << " has been created!" << std::endl;
    }

    // Copy constructor
    Pet(const Pet& other) : name(other.name), age(other.age), health(other.health), happiness(other.happiness) {
        totalPets++;
        std::cout << "Copy Constructor Called: A new pet has been created by copying " << other.name << "!" << std::endl;
    }

    // Destructor
    virtual ~Pet() {
        totalPets--;
        std::cout << "Destructor Called: Pet " << name << " has been deleted." << std::endl;
    }

    std::string getName() const { return name; }
    void setName(const std::string& newName) { name = newName; }

    int getAge() const { return age; }
    void setAge(int newAge) { age = newAge; }

    int getHealth() const { return health; }
    void setHealth(int newHealth) { health = (newHealth >= 0) ? newHealth : 0; }

    int getHappiness() const { return happiness; }
    void setHappiness(int newHappiness) { happiness = (newHappiness >= 0) ? newHappiness : 0; }

    virtual void feed() = 0;
    virtual void play() = 0;

    static void displayTotalPets() { std::cout << "Total Pets: " << totalPets << std::endl; }
    static void displayTotalFoodGiven() { std::cout << "Total Food Given: " << totalFoodGiven << std::endl; }

    void displayStatus() const {
        std::cout << "Name: " << getName() << ", Age: " << getAge() << ", Health: " << getHealth() << ", Happiness: " << getHappiness() << std::endl;
    }
};

int Pet::totalPets = 0;
int Pet::totalFoodGiven = 0;

// Single Inheritance - ServiceDog derives from Dog
class Dog : public Pet {
public:
    Dog() : Pet() {}

    Dog(const std::string& petName, int petAge) : Pet(petName, petAge) {}

    Dog(const Dog& other) : Pet(other) {}

    void feed() override {
        setHealth(getHealth() + 10);
        setHappiness(getHappiness() + 5);
        incrementFoodGiven(10);
        std::cout << "Feeding the dog." << std::endl;
    }

    void play() override {
        setHealth(getHealth() + 5);
        setHappiness(getHappiness() + 10);
        std::cout << "Playing with the dog." << std::endl;
    }

    void makeSound() const { std::cout << "Woof!" << std::endl; }
};

class ServiceDog : public Dog {
public:
    ServiceDog() : Dog() {}

    ServiceDog(const std::string& petName, int petAge) : Dog(petName, petAge) {}

    void assist() const { std::cout << "The service dog is assisting its owner." << std::endl; }
};

// Hierarchical Inheritance - Parrot and Cat derive from Pet
class Cat : public Pet {
public:
    Cat() : Pet() {}

    Cat(const std::string& petName, int petAge) : Pet(petName, petAge) {}

    Cat(const Cat& other) : Pet(other) {}

    void feed() override {
        setHealth(getHealth() + 8);
        setHappiness(getHappiness() + 7);
        incrementFoodGiven(8);
        std::cout << "Feeding the cat." << std::endl;
    }

    void play() override {
        setHealth(getHealth() + 6);
        setHappiness(getHappiness() + 9);
        std::cout << "Playing with the cat." << std::endl;
    }

    void makeSound() const { std::cout << "Meow!" << std::endl; }
};

class Parrot : public Pet {
public:
    Parrot() : Pet() {}

    Parrot(const std::string& petName, int petAge) : Pet(petName, petAge) {}

    Parrot(const Parrot& other) : Pet(other) {}

    void feed() override {
        setHealth(getHealth() + 7);
        setHappiness(getHappiness() + 6);
        incrementFoodGiven(7);
        std::cout << "Feeding the parrot." << std::endl;
    }

    void play() override {
        setHealth(getHealth() + 5);
        setHappiness(getHappiness() + 8);
        std::cout << "Playing with the parrot." << std::endl;
    }

    void makeSound() const { std::cout << "Squawk!" << std::endl; }
};

int main() {
    Dog bruno("Bruno", 3);
    bruno.displayStatus();

    ServiceDog max("Max", 5);
    max.assist();
    max.displayStatus();

    Cat whiskers("Whiskers", 2);
    whiskers.displayStatus();

    Parrot polly("Polly", 1);
    polly.makeSound();
    polly.displayStatus();

    Pet::displayTotalPets();

    return 0;
}
