#include <iostream>
#include <string>

// Separate class for pet status (follows SRP)
class PetStatus {
private:
    int health;
    int happiness;

public:
    // Constructor
    PetStatus(int initialHealth = 100, int initialHappiness = 100) 
        : health(initialHealth), happiness(initialHappiness) {}

    int getHealth() const { return health; }
    void setHealth(int newHealth) { health = (newHealth >= 0) ? newHealth : 0; }

    int getHappiness() const { return happiness; }
    void setHappiness(int newHappiness) { happiness = (newHappiness >= 0) ? newHappiness : 0; }

    void display() const {
        std::cout << "Health: " << health << ", Happiness: " << happiness << std::endl;
    }
};

// Abstract Base Class - Pet
class Pet {
private:
    std::string name;
    int age;

protected:
    PetStatus status; // Composition to manage health and happiness

public:
    // Constructor
    Pet(const std::string& petName, int petAge) 
        : name(petName), age(petAge), status() {}

    virtual ~Pet() {}

    std::string getName() const { return name; }
    void setName(const std::string& newName) { name = newName; }

    int getAge() const { return age; }
    void setAge(int newAge) { age = newAge; }

    // Abstract methods (to be implemented by derived classes)
    virtual void feed() = 0;
    virtual void play() = 0;
    virtual void makeSound() const = 0;

    void displayStatus() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
        status.display();
    }
};

// Derived Class - Dog
class Dog : public Pet {
public:
    Dog(const std::string& petName, int petAge) : Pet(petName, petAge) {}

    void feed() override {
        status.setHealth(status.getHealth() + 10);
        status.setHappiness(status.getHappiness() + 5);
        std::cout << "Feeding the dog." << std::endl;
    }

    void play() override {
        status.setHealth(status.getHealth() + 5);
        status.setHappiness(status.getHappiness() + 10);
        std::cout << "Playing with the dog." << std::endl;
    }

    void makeSound() const override {
        std::cout << "Woof!" << std::endl;
    }
};

// Derived Class - Cat
class Cat : public Pet {
public:
    Cat(const std::string& petName, int petAge) : Pet(petName, petAge) {}

    void feed() override {
        status.setHealth(status.getHealth() + 8);
        status.setHappiness(status.getHappiness() + 7);
        std::cout << "Feeding the cat." << std::endl;
    }

    void play() override {
        status.setHealth(status.getHealth() + 6);
        status.setHappiness(status.getHappiness() + 9);
        std::cout << "Playing with the cat." << std::endl;
    }

    void makeSound() const override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    Dog bruno("Bruno", 3);
    Cat whiskers("Whiskers", 2);

    // Display initial statuses
    bruno.displayStatus();
    whiskers.displayStatus();

    // Perform actions
    bruno.feed();
    bruno.play();
    bruno.makeSound();

    whiskers.feed();
    whiskers.play();
    whiskers.makeSound();

    // Display updated statuses
    bruno.displayStatus();
    whiskers.displayStatus();

    return 0;
}
