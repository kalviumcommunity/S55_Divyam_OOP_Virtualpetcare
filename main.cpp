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

    virtual void feed() = 0;
    virtual void play() = 0;
};

class Dog : public Pet {
public:
    Dog(std::string petName, int petAge) : Pet(petName, petAge) {}

    void feed() override {
        this->health += 10;
        this->happiness += 5;
        std::cout << "Feeding the dog." << std::endl;
    }

    void play() override {
        this->health += 5;
        this->happiness += 10;
        std::cout << "Playing with the dog." << std::endl;
    }

    void makeSound() {
        std::cout << "Woof!" << std::endl;
    }

    Dog& getThisDog() {
        return *this;
    }
};

class Cat : public Pet {
public:
    Cat(std::string petName, int petAge) : Pet(petName, petAge) {}

    void feed() override {
        this->health += 8;
        this->happiness += 7;
        std::cout << "Feeding the cat." << std::endl;
    }

    void play() override {
        this->health += 6;
        this->happiness += 9;
        std::cout << "Playing with the cat." << std::endl;
    }

    void makeSound() {
        std::cout << "Meow!" << std::endl;
    }

    Cat& getThisCat() {
        return *this;
    }
};

int main() {
    Dog myDog("Bruno", 3);
    Cat myCat("Whiskers", 2);

    myDog.displayStatus();
    myCat.displayStatus();

    myDog.feed();
    myDog.displayStatus();

    myDog.play();
    myDog.displayStatus();

    myDog.makeSound();

    myCat.feed();
    myCat.displayStatus();

    myCat.play();
    myCat.displayStatus();

    myCat.makeSound();

    return 0;
}
