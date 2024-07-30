#include <iostream>
#include <string>

class Pet {
protected:
    std::string name;
    int age;
    int health;
    int happiness;

public:
    Pet(std::string petName, int petAge) : name(petName), age(petAge), health(100), happiness(100) {}

    void displayStatus() {
        std::cout << "Name: " << name << ", Age: " << age << ", Health: " << health << ", Happiness: " << happiness << std::endl;
    }

    virtual void feed() = 0; // Pure virtual function
    virtual void play() = 0; // Pure virtual function
};

class Dog : public Pet {
public:
    Dog(std::string petName, int petAge) : Pet(petName, petAge) {}

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

    void makeSound() {
        std::cout << "Woof!" << std::endl;
    }
};


int main() {
    // Creating a Dog object
    Dog myDog("Buddy", 3);

    // Displaying initial status
    myDog.displayStatus();

    // Feeding the dog
    myDog.feed();
    myDog.displayStatus();

    // Playing with the dog
    myDog.play();
    myDog.displayStatus();

    // Making the dog sound
    myDog.makeSound();

    return 0;
}

