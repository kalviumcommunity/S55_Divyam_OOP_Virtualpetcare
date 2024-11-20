#include <iostream>
#include <vector>
#include <string>

// Abstract Base Class - Pet
class Pet {
protected:
    std::string name;
    int health;
    int happiness;

public:
    Pet(const std::string& petName, int initialHealth = 100, int initialHappiness = 100)
        : name(petName), health(initialHealth), happiness(initialHappiness) {}

    virtual ~Pet() {}

    std::string getName() const { return name; }
    virtual void feed() = 0;
    virtual void play() = 0;
    virtual void makeSound() const = 0;

    void displayStatus() const {
        std::cout << "Name: " << name << ", Health: " << health
                  << ", Happiness: " << happiness << std::endl;
    }
};

// Derived Class - Dog
class Dog : public Pet {
public:
    Dog(const std::string& petName) : Pet(petName) {}

    void feed() override {
        health += 10;
        happiness += 5;
        std::cout << name << " is enjoying dog food!" << std::endl;
    }

    void play() override {
        happiness += 15;
        health += 5;
        std::cout << name << " is playing fetch!" << std::endl;
    }

    void makeSound() const override {
        std::cout << name << " says: Woof!" << std::endl;
    }
};

// Derived Class - Cat
class Cat : public Pet {
public:
    Cat(const std::string& petName) : Pet(petName) {}

    void feed() override {
        health += 8;
        happiness += 7;
        std::cout << name << " is enjoying cat food!" << std::endl;
    }

    void play() override {
        happiness += 10;
        health += 4;
        std::cout << name << " is playing with a yarn ball!" << std::endl;
    }

    void makeSound() const override {
        std::cout << name << " says: Meow!" << std::endl;
    }
};

// Derived Class - Bird
class Bird : public Pet {
public:
    Bird(const std::string& petName) : Pet(petName) {}

    void feed() override {
        health += 6;
        happiness += 8;
        std::cout << name << " is enjoying birdseed!" << std::endl;
    }

    void play() override {
        happiness += 12;
        health += 3;
        std::cout << name << " is chirping while playing!" << std::endl;
    }

    void makeSound() const override {
        std::cout << name << " says: Tweet!" << std::endl;
    }
};

// Function to simulate pet care
void petCare(Pet* pet) {
    std::cout << "Caring for " << pet->getName() << ":" << std::endl;
    pet->feed();
    pet->play();
    pet->makeSound();
    pet->displayStatus();
    std::cout << std::endl;
}

int main() {
    // Create different types of pets
    Dog bruno("Bruno");
    Cat whiskers("Whiskers");
    Bird tweety("Tweety");

    // Store all pets in a vector of type Pet*
    std::vector<Pet*> pets = {&bruno, &whiskers, &tweety};

    // Use polymorphism to care for all pets
    for (Pet* pet : pets) {
        petCare(pet); // Each pet behaves according to its specific type
    }

    return 0;
}
