/*
Orlando Valdez
COSC 1436
2-26-2020
repl.it 
A program to practice passing a struct by pointer
*/
#include <iostream>
using namespace std;
//declaration of struct and function
struct car
{
  string Make;
  string Model;
  int Year;
  string Color;
};
//Function definition declared above int main()
void printCar(car *c)
{
cout << "\nCar Details: " << endl;
cout << "Make -  " << c->Make << endl;
cout << "Model - " << c->Model << endl;
cout << "Year -  " << c->Year << endl;
if(c->Year <= 2010)
{
  c->Color = "RED"; 
}
else if(c->Year > 2010)
{
  c->Color = "GREEN";
}
cout << "Color: " << c->Color << endl;
}

void preserveData(car &c)
{
  cout << "\nORIGINAL DATA: " ;
  printCar(&c);

  car *p_car = &c;
  
  cout << "\nData copied into a new structure p_car";
  printCar(p_car);

  new(p_car) car;
  cout << p_car->Year << endl; //print current Year
  new(p_car) car(); //default constructor (reset values)
  cout << p_car->Year << endl; //0

  cout << "\nData after defaul const reset: ";
  printCar(p_car);

  cout << "\nORIGINAL DATA in c: ";
  printCar(&c);

}

int main()
{
  //declare an instance of the struct
  car car1;
  car1.Make = "Hyundai";
  car1.Model = "Genesis";
  car1.Year = 2016;

  car car2 = {"GMC","Yukon", 1975}; //only works in C++11

  car car3 = {"Toyota", "Avalon", 2003};//only works in C++11

  //print each car
  printCar(&car1);
  printCar(&car2);
  printCar(&car3);

  preserveData(car1);
  preserveData(car2);
  preserveData(car3);
  return 0;
}