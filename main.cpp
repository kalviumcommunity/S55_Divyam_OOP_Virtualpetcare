#include <iostream>
#include <string>

// Abstract Base Class - Pet
class Pet {
private:
    std::string name;
    int age;

protected:
    int health;
    int happiness;

public:
    // Constructor
    Pet(const std::string& petName, int petAge, int initialHealth = 100, int initialHappiness = 100)
        : name(petName), age(petAge), health(initialHealth), happiness(initialHappiness) {}

    virtual ~Pet() {}

    std::string getName() const { return name; }
    void setName(const std::string& newName) { name = newName; }

    int getAge() const { return age; }
    void setAge(int newAge) { age = newAge; }

    virtual void feed() = 0;
    virtual void play() = 0;
    virtual void makeSound() const = 0;

    void displayStatus() const {
        std::cout << "Name: " << name << ", Age: " << age
                  << ", Health: " << health << ", Happiness: " << happiness << std::endl;
    }
};

// Derived Class - Dog
class Dog : public Pet {
public:
    Dog(const std::string& petName, int petAge)
        : Pet(petName, petAge) {}

    void feed() override {
        health += 10;
        happiness += 5;
        std::cout << "Feeding the dog." << std::endl;
    }

    void play() override {
        health += 5;
        happiness += 10;
        std::cout << "Playing with the dog." << std::endl;
    }

    void makeSound() const override {
        std::cout << "Woof!" << std::endl;
    }
};

// Derived Class - Cat
class Cat : public Pet {
public:
    Cat(const std::string& petName, int petAge)
        : Pet(petName, petAge) {}

    void feed() override {
        health += 8;
        happiness += 7;
        std::cout << "Feeding the cat." << std::endl;
    }

    void play() override {
        health += 6;
        happiness += 9;
        std::cout << "Playing with the cat." << std::endl;
    }

    void makeSound() const override {
        std::cout << "Meow!" << std::endl;
    }
};

// New Derived Class - Bird (Demonstrates OCP)
class Bird : public Pet {
public:
    Bird(const std::string& petName, int petAge)
        : Pet(petName, petAge) {}

    void feed() override {
        health += 6;
        happiness += 8;
        std::cout << "Feeding the bird." << std::endl;
    }

    void play() override {
        health += 4;
        happiness += 12;
        std::cout << "Playing with the bird." << std::endl;
    }

    void makeSound() const override {
        std::cout << "Tweet!" << std::endl;
    }
};

int main() {
    Dog bruno("Bruno", 3);
    Cat whiskers("Whiskers", 2);
    Bird tweety("Tweety", 1); // New pet type added without modifying existing code

    // Display initial statuses
    bruno.displayStatus();
    whiskers.displayStatus();
    tweety.displayStatus();

    // Perform actions
    bruno.feed();
    bruno.play();
    bruno.makeSound();

    whiskers.feed();
    whiskers.play();
    whiskers.makeSound();

    tweety.feed();
    tweety.play();
    tweety.makeSound();

    // Display updated statuses
    bruno.displayStatus();
    whiskers.displayStatus();
    tweety.displayStatus();

    return 0;
}
