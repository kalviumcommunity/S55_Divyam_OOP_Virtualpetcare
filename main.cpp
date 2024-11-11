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

    // Encapsulated getter and setter methods
    std::string getName() const { return name; }
    void setName(const std::string& newName) { name = newName; }

    int getAge() const { return age; }
    void setAge(int newAge) { age = newAge; }

    int getHealth() const { return health; }
    void setHealth(int newHealth) { health = (newHealth >= 0) ? newHealth : 0; }

    int getHappiness() const { return happiness; }
    void setHappiness(int newHappiness) { happiness = (newHappiness >= 0) ? newHappiness : 0; }

    virtual void feed() {
        std::cout << "Feeding the pet." << std::endl;
    }

    virtual void play() {
        std::cout << "Playing with the pet." << std::endl;
    }

    static void displayTotalPets() {
        std::cout << "Total Pets: " << totalPets << std::endl;
    }

    static void displayTotalFoodGiven() {
        std::cout << "Total Food Given: " << totalFoodGiven << std::endl;
    }

    void displayStatus() const {
        std::cout << "Name: " << getName() << ", Age: " << getAge() << ", Health: " << getHealth() << ", Happiness: " << getHappiness() << std::endl;
    }

protected:
    void incrementFoodGiven(int amount) {
        totalFoodGiven += amount;
    }
};

int Pet::totalPets = 0;
int Pet::totalFoodGiven = 0;

class Dog : public Pet {
public:
    Dog(std::string petName, int petAge) : Pet(petName, petAge) {}

    void feed() {
        setHealth(getHealth() + 10);
        setHappiness(getHappiness() + 5);
        incrementFoodGiven(10);  
        std::cout << "Feeding the dog." << std::endl;
    }

    void play() {
        setHealth(getHealth() + 5);
        setHappiness(getHappiness() + 10);
        std::cout << "Playing with the dog." << std::endl;
    }

    void makeSound() const {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Pet {
public:
    Cat(std::string petName, int petAge) : Pet(petName, petAge) {}

    void feed() {
        setHealth(getHealth() + 8);
        setHappiness(getHappiness() + 7);
        incrementFoodGiven(8);
        std::cout << "Feeding the cat." << std::endl;
    }

    void play() {
        setHealth(getHealth() + 6);
        setHappiness(getHappiness() + 9);
        std::cout << "Playing with the cat." << std::endl;
    }

    void makeSound() const {
        std::cout << "Meow!" << std::endl;
    }
};

class Bird : public Pet {
public:
    Bird(std::string petName, int petAge) : Pet(petName, petAge) {}

    void feed() {
        setHealth(getHealth() + 7);
        setHappiness(getHappiness() + 6);
        incrementFoodGiven(7); 
        std::cout << "Feeding the bird." << std::endl;
    }

    void play() {
        setHealth(getHealth() + 4);
        setHappiness(getHappiness() + 8);
        std::cout << "Playing with the bird." << std::endl;
    }

    void makeSound() const {
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
