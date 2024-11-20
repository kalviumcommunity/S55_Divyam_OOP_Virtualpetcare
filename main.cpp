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

    // Function Overloading: Multiple ways to feed the pet
    void feed() {
        setHealth(getHealth() + 10);
        setHappiness(getHappiness() + 5);
        incrementFoodGiven(10);
        std::cout << "Feeding the pet a regular meal." << std::endl;
    }

    void feed(int foodAmount) {
        setHealth(getHealth() + foodAmount / 2);
        setHappiness(getHappiness() + foodAmount / 3);
        incrementFoodGiven(foodAmount);
        std::cout << "Feeding the pet with " << foodAmount << " units of food." << std::endl;
    }

    virtual void play() = 0;

    static void displayTotalPets() { std::cout << "Total Pets: " << totalPets << std::endl; }
    static void displayTotalFoodGiven() { std::cout << "Total Food Given: " << totalFoodGiven << std::endl; }

    void displayStatus() const {
        std::cout << "Name: " << getName() << ", Age: " << getAge() << ", Health: " << getHealth() << ", Happiness: " << getHappiness() << std::endl;
    }
};

int Pet::totalPets = 0;
int Pet::totalFoodGiven = 0;

// Derived class - Dog
class Dog : public Pet {
public:
    // Constructor Overloading
    Dog() : Pet() {}

    Dog(const std::string& petName, int petAge) : Pet(petName, petAge) {}

    Dog(const Dog& other) : Pet(other) {}

    void play() override {
        setHealth(getHealth() + 5);
        setHappiness(getHappiness() + 10);
        std::cout << "Playing with the dog." << std::endl;
    }

    void makeSound() const { std::cout << "Woof!" << std::endl; }
};

// Derived class - Cat
class Cat : public Pet {
public:
    // Constructor Overloading
    Cat() : Pet() {}

    Cat(const std::string& petName, int petAge) : Pet(petName, petAge) {}

    Cat(const Cat& other) : Pet(other) {}

    void play() override {
        setHealth(getHealth() + 6);
        setHappiness(getHappiness() + 9);
        std::cout << "Playing with the cat." << std::endl;
    }

    void makeSound() const { std::cout << "Meow!" << std::endl; }
};

int main() {
    // Demonstrating constructor overloading
    Dog defaultDog;
    defaultDog.displayStatus();

    Dog bruno("Bruno", 3);
    bruno.displayStatus();

    Cat whiskers("Whiskers", 2);
    whiskers.displayStatus();

    // Demonstrating function overloading
    bruno.feed(); // Regular meal
    whiskers.feed(15); // Feeding with custom amount

    // Playing with pets
    bruno.play();
    whiskers.play();

    Pet::displayTotalPets();
    Pet::displayTotalFoodGiven();

    return 0;
}
