
Class Abstract

#include <iostream>
using namespace std;

// CarbonFootprint.h

class CarbonFootPrint
{
  public:virtual void getCarbonFootPrint () = 0;
};


// Car.h

class Car:public CarbonFootPrint
{
  public:Car (int gallons);
  void getCarbonFootPrint ();
    private:int gallons;
};



// Car.cpp

Car::Car (int gallons)
{
  this->gallons = gallons;
}

void
Car::getCarbonFootPrint ()
{
  cout << "Total gallons of gas the car has used: " << gallons * (20) << endl;
}



// Building.h

class Building:public CarbonFootPrint
{
  public:Building (int sqft);
  void getCarbonFootPrint ();
  int getSqft ();
    private:int sqft;
};

// Bicycle.h

class Bicycle:public CarbonFootPrint
{
  public:Bicycle ();
  void getCarbonFootPrint ();

};

// Bicycle.cpp

Bicycle::Bicycle ()
{

}

void
Bicycle::getCarbonFootPrint ()
{
  cout << "Carbonfoorprint for a bicycle is 0." << endl;
  cout << endl;
};

// Building.cpp

Building::Building (int sqft)
{
  this->sqft = sqft;
}

void
Building::getCarbonFootPrint ()
{
  cout << "The Building's square feet is:  " << sqft * (134) << endl;
  cout << endl;
}


// main.cpp

int
main ()
{
  const int NUM = 3;

//Creating instances
  Bicycle bicy;
  Building bd (1500);
  Car cr (20);
//Creating an array of CarbonFootPrint pointers
  CarbonFootPrint *array[NUM] = { &bicy, &bd, &cr };

  for (int i = 0; i < NUM; i++)
    {
      array[i]->getCarbonFootPrint ();
    }
  return 0;
}
