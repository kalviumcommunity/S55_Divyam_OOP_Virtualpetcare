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

    // Method to display the pet's status
    void displayStatus() {
        std::cout << "Name: " << name << ", Age: " << age << ", Health: " << health << ", Happiness: " << happiness << std::endl;
    }

    // Pure virtual methods
    virtual void feed() = 0;
    virtual void play() = 0;
};

class Dog : public Pet {
public:
    Dog(std::string petName, int petAge) : Pet(petName, petAge) {}

    // Method to feed the dog
    void feed() override {
        this->health += 10;
        this->happiness += 5;
        std::cout << "Feeding the dog." << std::endl;
    }

    // Method to play with the dog
    void play() override {
        this->health += 5;
        this->happiness += 10;
        std::cout << "Playing with the dog." << std::endl;
    }

    // Method to make the dog sound
    void makeSound() {
        std::cout << "Woof!" << std::endl;
    }

    // Method to return the current object for demonstration purposes
    Dog& getThisDog() {
        return *this;
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
