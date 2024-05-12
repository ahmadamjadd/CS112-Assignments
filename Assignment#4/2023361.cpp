#include <iostream>
#include <cstring>
#include <windows.h> // Include Windows.h for system commands
using namespace std;

// Forward declaration of Car class
class Car;

// Engine class definition
class Engine {
private:
    int cylinders;
    int horsepower;
public:
    Engine(int cylinders, int horsepower); // Constructor
    int getcylinder(); // Getter for cylinders
    int gethorsepower(); // Getter for horsepower
};

// Car class definition
class Car {
private:
    string make;
    string model;
    Engine engine;
public:
    Car(string make, string model, int cylinders, int horsepower); // Constructor
    void setmake(); // Set make of the car
    void setmodel(); // Set model of the car
    void setengine(); // Set engine details of the car
    string getmake(); // Get make of the car
    string getmodel(); // Get model of the car
    void printinfo(); // Print information about the car
};

int main() {
    Car car("Ford", "Mustang", 8, 450);
    car.printinfo();
    
    cout << endl;
    
    system("pause"); // Pause the console output
    system("cls"); // Clear the console screen
    
    cout << "==========================" << endl;
    cout << "Now we will modify values: " << endl;
    cout << "==========================\n" << endl;
    
    car.setmake();
    car.setmodel();
    car.setengine();
    
    system("cls"); // Clear the console screen
    
    car.printinfo();
    
    return 0;
}

// Engine class constructor implementation
Engine::Engine(int cylinders, int horsepower) {
    this->cylinders = cylinders;
    this->horsepower = horsepower;
}

// Car class constructor implementation
Car::Car(string make, string model, int cylinders, int horsepower)
: make(make), model(model), engine(cylinders, horsepower) {}

// Set make of the car function implementation
void Car::setmake() {
    string a;
    cout << "Enter make of car: ";
    getline(cin, a);
    make = a;
}

// Set model of the car function implementation
void Car::setmodel() {
    string b;
    cout << "Enter model of car: ";
    getline(cin, b);
    model = b;
}

// Set engine details of the car function implementation
void Car::setengine() {
    int c, d;
    
    cout << "How many cylinders does the car contain? ";
    cin >> c;
    
    cout << "Write horsepower of the car: ";
    cin >> d;
    
    cout << endl;
    
   engine = Engine(c, d);
}

// Get make of the car function implementation
string Car::getmake() {
   return make;
}

// Get model of the car function implementation
string Car::getmodel() {
   return model;
}

// Getter for cylinders function implementation in Engine class
int Engine::getcylinder() {
   return cylinders;
}

// Getter for horsepower function implementation in Engine class
int Engine::gethorsepower() {
   return horsepower;
}

// Print information about the car function implementation
void Car::printinfo() {
   cout << "==========================" << endl;
   cout << "Displaying Info about Car!" << endl;
   cout << "==========================\n" << endl;

   cout << "Make of Car: " << make << endl;
   cout << "Model of Car: " << model << endl;
   cout << "Number of cylinders in Car: " << engine.getcylinder() << endl;
   cout << "Horsepower of Car: " << engine.gethorsepower() << endl;
}

