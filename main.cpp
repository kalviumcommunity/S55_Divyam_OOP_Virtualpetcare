#include <iostream>
#include <string>

class Pet {
protected:
    std::string name;
    int age;
    int health;
    int happiness;

    static int totalPets;       // Static variable to keep track of total pets
    static int totalFoodGiven;  // Static variable to track total food given to all pets

public:
    // Constructor to initialize pet attributes and increment totalPets count
    Pet(std::string petName, int petAge) : name(petName), age(petAge), health(100), happiness(100) {
        totalPets++; 
    }

    // Destructor to decrement totalPets count when a pet object is destroyed
    virtual ~Pet() {
        totalPets--; 
    }

    // Function to display pet's current status
    void displayStatus() {
        std::cout << "Name: " << name << ", Age: " << age << ", Health: " << health << ", Happiness: " << happiness << std::endl;
    }

    // Pure virtual functions to ensure derived classes implement feeding and playing actions
    virtual void feed() = 0;
    virtual void play() = 0;

    // Static function to display the total number of pets
    static void displayTotalPets() {
        std::cout << "Total number of pets: " << totalPets << std::endl;
    }

    // Static function to display the total food given across all pets
    static void displayTotalFoodGiven() {
        std::cout << "Total food given to all pets: " << totalFoodGiven << std::endl;
    }

    // Static function to reset the total food given count
    static void resetTotalFoodGiven() {
        totalFoodGiven = 0;
        std::cout << "Total food given has been reset." << std::endl;
    }

protected:
    // Function to increment the total food given; only accessible within Pet or derived classes
    void incrementFoodGiven(int amount) {
        totalFoodGiven += amount;
    }
};

// Initialize static variables
int Pet::totalPets = 0;
int Pet::totalFoodGiven = 0;

// Derived class Dog
class Dog : public Pet {
public:
    Dog(std::string petName, int petAge) : Pet(petName, petAge) {}

    void feed() override {
        health += 10;
        happiness += 5;
        incrementFoodGiven(10);  // Update total food given
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

// Derived class Cat
class Cat : public Pet {
public:
    Cat(std::string petName, int petAge) : Pet(petName, petAge) {}

    void feed() override {
        health += 8;
        happiness += 7;
        incrementFoodGiven(8);  // Update total food given
        std::cout << "Feeding the cat." << std::endl;
    }

    void play() override {
        health += 6;
        happiness += 9;
        std::cout << "Playing with the cat." << std::endl;
    }

    void makeSound() {
        std::cout << "Meow!" << std::endl;
    }
};

// Derived class Bird
class Bird : public Pet {
public:
    Bird(std::string petName, int petAge) : Pet(petName, petAge) {}

    void feed() override {
        health += 7;
        happiness += 6;
        incrementFoodGiven(7);  // Update total food given
        std::cout << "Feeding the bird." << std::endl;
    }

    void play() override {
        health += 4;
        happiness += 8;
        std::cout << "Playing with the bird." << std::endl;
    }

    void makeSound() {
        std::cout << "Chirp!" << std::endl;
    }
};

int main() {
    // Create arrays of pets
    Pet* dogArray[2] = { new Dog("Bruno", 3), new Dog("Max", 2) };
    Pet* catArray[2] = { new Cat("Whiskers", 2), new Cat("Mittens", 1) };
    Pet* birdArray[2] = { new Bird("Tweety", 1), new Bird("Polly", 3) };

    // Display the total number of pets
    Pet::displayTotalPets();  

    // Interact with each dog
    for(int i = 0; i < 2; i++) {
        dogArray[i]->displayStatus();
        dogArray[i]->feed();
        dogArray[i]->play();
        static_cast<Dog*>(dogArray[i])->makeSound();
        dogArray[i]->displayStatus();
        std::cout << std::endl;
    }

    // Interact with each cat
    for(int i = 0; i < 2; i++) {
        catArray[i]->displayStatus();
        catArray[i]->feed();
        catArray[i]->play();
        static_cast<Cat*>(catArray[i])->makeSound();
        catArray[i]->displayStatus();
        std::cout << std::endl;
    }

    // Interact with each bird
    for(int i = 0; i < 2; i++) {
        birdArray[i]->displayStatus();
        birdArray[i]->feed();
        birdArray[i]->play();
        static_cast<Bird*>(birdArray[i])->makeSound();
        birdArray[i]->displayStatus();
        std::cout << std::endl;
    }

    // Display total food given to all pets
    Pet::displayTotalFoodGiven();

    // Reset the total food given
    Pet::resetTotalFoodGiven();

    // Delete pet objects and release memory
    for(int i = 0; i < 2; i++) {
        delete dogArray[i];
        delete catArray[i];
        delete birdArray[i];
    }

    // Display total pets after deletion
    Pet::displayTotalPets(); 

    return 0;
}
