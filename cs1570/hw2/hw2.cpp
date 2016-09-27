/*
 * Programmer: Nathan Jarus
 * File: hw2.cpp        Date: today
 * Class: CS 1570       Instructor: Nathan Jarus
 * Purpose: Calculate the information necessary to build fish
 *   tanks for displaced wildlife
 */
#include<iostream>
using namespace std;

const float WIDTH_RATIO = 1/4.0f; // Ratio of length to width
const float HEIGHT_RATIO = 2/3.0f; // Ratio of height to width

const float FREAKY_FISH_FOOD_GALLONS= 2; // Capacity of freaky fish food
const float GALLONS_PER_FISH = 25; // Gallons of water each fish requires
const int LIFE = 11; // EPA LIFE constant; units: rads*inches

// Unit conversion constants
const float GALLONS_PER_CU_FT = 7.48f;
const int INCHES_PER_FT = 12;

int main()
{
  int length, width, height; // tank dimensions in feet
  float tank_volume, water_volume; // volume of tank and tank water in gallons
  bool has_freaky_fish; // whether or not freaky fish will be placed in the tank
  int num_fish; // number of fish the tank can hold
  float rads; // amount of radiation the tank will require

  // Greetings!
  cout << "Welcome to the Fish Tank Calculator HD208XX" << endl
       << "Please enter the length of your tank in feet: ";
  cin >> length;

  cout << "Are there any freaky fish in the tank? (1 - yes, 0 - no): ";
  cin >> has_freaky_fish;

  // Calculate tank dimensions
  width = static_cast<int>(length * WIDTH_RATIO);
  height = static_cast<int>(length * HEIGHT_RATIO);

  // Calculate capacity and volume of water
  tank_volume = length * width * height * GALLONS_PER_CU_FT;
  water_volume = tank_volume - FREAKY_FISH_FOOD_GALLONS * has_freaky_fish;

  // Calculate number of fish tank holds
  num_fish = static_cast<int>(water_volume / GALLONS_PER_FISH);

  // Calculate number of rads required
  rads = static_cast<float>(LIFE) / (height * INCHES_PER_FT);

  // Present results to user
  cout << endl << "The tank dimensions are:" << endl
       << "\tLength: " << length << " feet" << endl
       << "\tWidth:  " << width << " feet" << endl
       << "\tHeight: " << height << " feet" << endl
       << endl
       << "Tank capacity:   " << tank_volume << " gallons" << endl
       << "Volume of water: " << water_volume << " gallons" << endl
       << endl
       << "Add " << rads << " rads of radiation for your fish." << endl
       << endl
       << "Your tank will hold " << num_fish << " fishies!" << endl
       << endl
       << "Ciao!" << endl;

  return 0;
}