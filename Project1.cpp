#include <iostream>
#include <fstream>
using namespace std;

struct Car{
  enum {MAX_CHAR_LENGTH=500};
  char name [MAX_CHAR_LENGTH];
  double MPG;
  int Cylinders;
  double Displacement;
  double Horsepower;
  double Weight;
  double Acceleration;
  int Model;
  char origin[MAX_CHAR_LENGTH];
  bool ValidEntry = false;
};



const int MAX_CARS=500;
Car readCarData(ifstream &inFile){
    Car car; 
    inFile.get(car.name, Car::MAX_CHAR_LENGTH, ';');
    inFile.ignore(100,';');
    inFile >> car.MPG;
    inFile.ignore(100,';');
    inFile >> car.Cylinders;
    inFile.ignore(100,';');
    inFile >> car.Displacement;
    inFile.ignore(100,';');
    inFile >> car.Horsepower;
    inFile.ignore(100,';');
    inFile >> car.Weight;
    inFile.ignore(100,';');
    inFile >> car.Acceleration;
    inFile.ignore(100,';');
    inFile >> car.Model;
    inFile.ignore(100,';');
    inFile >> (car.origin);
    inFile.ignore(100,'\n');
    // If we reached the end of the file while reading, then the entry is not valid
    car.ValidEntry = !inFile.eof();
    return car;
} 

int readCar(Car car[]) {
    ifstream carFile("cars.txt");
    int numCars = 0;
    while(carFile.peek() != EOF && numCars < MAX_CARS) {
        car[numCars] = readCarData(carFile);
        numCars++;
    }
    return numCars;
}

void readCarData (Car car){
    cout << car.name << ";" << car.MPG << ";" << car.Cylinders << ";" << car.Displacement << ";" << car.Horsepower << ";" << car.Weight << ";" << car.Acceleration << ";" << car.Model << ";" << car.origin << endl;
}

void printCars (Car car[]) {
  for (int index = 0; index < MAX_CARS; index++) {
    if (car[index].ValidEntry == true) {
      cout << "Index " << index << ": ";
      readCarData(car[index]);
    }
    
    
  }
}

void printCarsByOrigin(Car car[]) {
  string input;
  cout << "sort by region: ";
  cin >> input;
  for (int index = 0; index < MAX_CARS; index++) {
    if (car[index].origin == input) {
      cout << "Index " << index << ": ";
      readCarData(car[index]);
      }
    }
  }


void removeCar (Car car[]) {
  cout << "Enter index of the car you want to remove: ";
  int index = 0;
  cin >> index;

   while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << "Enter index of the car you want to remove: ";
        cin >> index;
    }
  car[index].ValidEntry = false;
}

int readInt(const char prompt[]) {
    int temp = 0;
    cout << prompt;
    cin >> temp; 
    while (!cin) {
      cin.clear();
      cin.ignore(1000,'\n');
      cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
  return temp;
}

double readDouble(const char prompt[]) {
  double temp = 0;
    cout << prompt;
    cin >> temp; 
    while (!cin) {
      cin.clear();
      cin.ignore(1000,'\n');
      cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
  return temp;
}

void addCar(Car car[]) {
    for (int index = 0; index < MAX_CARS; index++) {
    if (car[index].ValidEntry == false) {
        cout << "Enter car name: ";
        //cin.ignore(1000, '\n');
        cin.getline(car[index].name, Car::MAX_CHAR_LENGTH);
        //cin.ignore(1000, '\n');

        car[index].MPG = readDouble("Enter car MPG: ");
        car[index].Cylinders = readInt("Enter car cylinders: ");
        car[index].Displacement = readDouble("Enter car Displacement: ");
        car[index].Horsepower = readDouble("Enter car Horsepower: ");
        car[index].Weight = readDouble("Enter car Weight: ");
        car[index].Acceleration = readDouble("Enter car Acceleration: ");
        car[index].Model = readInt("Enter car Model: ");

        cout << "Enter car region (Europe, Japan, US): ";
        cin.ignore(1000, '\n');
        cin.getline(car[index].origin, Car::MAX_CHAR_LENGTH);
        car[index].ValidEntry = true;

      break;
        
      }
    }
  }

  void displayMenu() {
    
    Car cars[MAX_CARS];
    char input = ' ';
    readCar(cars);
    
    while (input != 'Q') {
 
      cout << "Please select an option: " << endl << endl;
      cout << "Display car list" << endl << "Number of cars" << endl << "Remove car from list" << endl << "Add car" << endl << "Origin sort" << endl << "Quit" << endl;

      cout << ": ";
      cin >> input;
  
      if (input == 'D') {
        
        printCars(cars);
      }    

      if (input == 'N') {
        int num = readCar(cars);
  cout << "Num of cars: " << num << endl;
      }

      if (input == 'R') {
        removeCar(cars);
      }

      if (input == 'A') {
        addCar(cars);
      }

      if (input == 'O') {
        printCarsByOrigin(cars);
      }

      
    }
  }







int main() {
 
  
  /*printCars(cars);
  printCarsByOrigin(cars);
  addCar(cars);
  printCars(cars);
  addCar(cars);
  removeCar(cars);
  printCars(cars);*/
  displayMenu();

  
    
}


