#include <iostream>
#include <string>

class Pet {
protected:
    std::string name;
    int age;
    int health;
    int happiness;

    static int totalPets;
    static int totalFoodGiven;

public:
    Pet(std::string petName, int petAge) : name(petName), age(petAge), health(100), happiness(100) {
        totalPets++;
    }

    virtual ~Pet() {
        totalPets--;
    }

    void displayStatus() {
        std::cout << "Name: " << name << ", Age: " << age << ", Health: " << health << ", Happiness: " << happiness << std::endl;
    }

    virtual void feed() = 0;
    virtual void play() = 0;

    static void displayTotalPets() {
        std::cout << "Total Pets: " << totalPets << std::endl;
    }

    static void displayTotalFoodGiven() {
        std::cout << "Total Food Given: " << totalFoodGiven << std::endl;
    }

protected:
    void incrementFoodGiven(int amount) {
        totalFoodGiven += amount;
    }
    
    // Encapsulation: Accessors and Mutators for health and happiness
    int getHealth() const {
        return health;
    }

    void setHealth(int newHealth) {
        if (newHealth >= 0 && newHealth <= 100) {
            health = newHealth;
        }
    }

    int getHappiness() const {
        return happiness;
    }

    void setHappiness(int newHappiness) {
        if (newHappiness >= 0 && newHappiness <= 100) {
            happiness = newHappiness;
        }
    }
};

int Pet::totalPets = 0;
int Pet::totalFoodGiven = 0;

class Dog : public Pet {
public:
    Dog(std::string petName, int petAge) : Pet(petName, petAge) {}

    void feed() override {
        setHealth(getHealth() + 10); // Using encapsulation
        setHappiness(getHappiness() + 5); // Using encapsulation
        incrementFoodGiven(10);  
        std::cout << "Feeding the dog." << std::endl;
    }

    void play() override {
        setHealth(getHealth() + 5); // Using encapsulation
        setHappiness(getHappiness() + 10); // Using encapsulation
        std::cout << "Playing with the dog." << std::endl;
    }

    void makeSound() {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Pet {
public:
    Cat(std::string petName, int petAge) : Pet(petName, petAge) {}

    void feed() override {
        setHealth(getHealth() + 8); // Using encapsulation
        setHappiness(getHappiness() + 7); // Using encapsulation
        incrementFoodGiven(8);
        std::cout << "Feeding the cat." << std::endl;
    }

    void play() override {
        setHealth(getHealth() + 6); // Using encapsulation
        setHappiness(getHappiness() + 9); // Using encapsulation
        std::cout << "Playing with the cat." << std::endl;
    }

    void makeSound() {
        std::cout << "Meow!" << std::endl;
    }
};


class Bird : public Pet {
public:
    Bird(std::string petName, int petAge) : Pet(petName, petAge) {}

    void feed() override {
        this->health += 7;
        this->happiness += 6;
        incrementFoodGiven(7); 
        std::cout << "Feeding the bird." << std::endl;
    }

    void play() override {
        this->health += 4;
        this->happiness += 8;
        std::cout << "Playing with the bird." << std::endl;
    }

    void makeSound() {
        std::cout << "Chirp!" << std::endl;
    }
};


int main() {
    Pet* dogArray[2] = { new Dog("Bruno", 3), new Dog("Max", 2) };
    Pet* catArray[2] = { new Cat("Whiskers", 2), new Cat("Mittens", 1) };
    Pet* birdArray[2] = { new Bird("Tweety", 1), new Bird("Polly", 3) };

    Pet::displayTotalPets();  

    for(int i = 0; i < 2; i++) {
        dogArray[i]->displayStatus();
        dogArray[i]->feed();
        dogArray[i]->play();
        static_cast<Dog*>(dogArray[i])->makeSound();
        dogArray[i]->displayStatus();
        std::cout << std::endl;
    }

    for(int i = 0; i < 2; i++) {
        catArray[i]->displayStatus();
        catArray[i]->feed();
        catArray[i]->play();
        static_cast<Cat*>(catArray[i])->makeSound();
        catArray[i]->displayStatus();
        std::cout << std::endl;
    }

    for(int i = 0; i < 2; i++) {
        birdArray[i]->displayStatus();
        birdArray[i]->feed();
        birdArray[i]->play();
        static_cast<Bird*>(birdArray[i])->makeSound();
        birdArray[i]->displayStatus();
        std::cout << std::endl;
    }

    Pet::displayTotalFoodGiven();  

    for(int i = 0; i < 2; i++) {
        delete dogArray[i];
        delete catArray[i];
        delete birdArray[i];
    }

    Pet::displayTotalPets(); 

    return 0;
}
