#include <iostream>
#include <string>

// Abstract Base Class
class Pet {
private:
    std::string name;
    int age;
    int health;
    int happiness;

    static int totalPets;

protected:
    void incrementTotalPets() { totalPets++; }

public:
    // Constructors
    Pet() : name("Unknown"), age(0), health(100), happiness(100) {
        totalPets++;
        std::cout << "Default Constructor Called: A new pet has been created!" << std::endl;
    }

    Pet(const std::string& petName, int petAge) : name(petName), age(petAge), health(100), happiness(100) {
        totalPets++;
        std::cout << "Parameterized Constructor Called: A new pet named " << name << " has been created!" << std::endl;
    }

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

    // Abstract Methods (Pure Virtual Functions)
    virtual void feed() = 0;
    virtual void play() = 0;

    // Virtual Function with Default Implementation
    virtual void makeSound() const {
        std::cout << "This is a generic pet sound." << std::endl;
    }

    static void displayTotalPets() { std::cout << "Total Pets: " << totalPets << std::endl; }

    void displayStatus() const {
        std::cout << "Name: " << getName() << ", Age: " << getAge() << ", Health: " << getHealth() << ", Happiness: " << getHappiness() << std::endl;
    }
};

int Pet::totalPets = 0;

// Derived Class - Dog
class Dog : public Pet {
public:
    // Constructors
    Dog() : Pet() {}
    Dog(const std::string& petName, int petAge) : Pet(petName, petAge) {}

    // Overriding Virtual Functions
    void feed() override {
        setHealth(getHealth() + 10);
        setHappiness(getHappiness() + 5);
        std::cout << "Feeding the dog." << std::endl;
    }

    void play() override {
        setHealth(getHealth() + 5);
        setHappiness(getHappiness() + 10);
        std::cout << "Playing with the dog." << std::endl;
    }

    void makeSound() const override {
        std::cout << "Woof!" << std::endl;
    }
};

// Derived Class - Cat
class Cat : public Pet {
public:
    // Constructors
    Cat() : Pet() {}
    Cat(const std::string& petName, int petAge) : Pet(petName, petAge) {}

    // Overriding Virtual Functions
    void feed() override {
        setHealth(getHealth() + 8);
        setHappiness(getHappiness() + 7);
        std::cout << "Feeding the cat." << std::endl;
    }

    void play() override {
        setHealth(getHealth() + 6);
        setHappiness(getHappiness() + 9);
        std::cout << "Playing with the cat." << std::endl;
    }

    void makeSound() const override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    // Demonstrating Abstract Class and Virtual Functions
    Pet* pet1 = new Dog("Bruno", 3); // Using polymorphism
    Pet* pet2 = new Cat("Whiskers", 2);

    pet1->displayStatus();
    pet1->feed();
    pet1->play();
    pet1->makeSound();

    pet2->displayStatus();
    pet2->feed();
    pet2->play();
    pet2->makeSound();

    Pet::displayTotalPets();

    // Cleaning up dynamically allocated memory
    delete pet1;
    delete pet2;

    return 0;
}
