/*
 * Programmer: Nathan Jarus
 * File: hw3.cpp        Date: today
 * Class: CS 1570       Instructor: Nathan Jarus
 * Purpose: Compose appropriately avant-garde tunes
 * https://sites.google.com/a/mst.edu/price/courses/cs-1570/hw/2016/fall/assignment-03
 */
#include<iostream>
using namespace std;

// Last inspiration number to generate a note for
const unsigned short LAST_NOTE = 1;

// Number of notes
const unsigned short NUM_NOTES = 7;

// Note number mappings, sounds, and animal names
const unsigned short A_NOTE = 0;
const string A_SOUND = "wah";
const string A_ANIMAL = "El Chupacabra";

const unsigned short B_NOTE = 1;
const string B_SOUND = "bleep";
const string B_ANIMAL = "Bucktoothed Slug";

const unsigned short C_NOTE = 2;
const string C_SOUND = "doo-wah";
const string C_ANIMAL = "Freaky fish";

const unsigned short D_NOTE = 3;
const string D_SOUND = "ding";
const string D_ANIMAL = "3-legged snakes";

const unsigned short E_NOTE = 4;
const string E_SOUND = "honk";
const string E_ANIMAL = "Trash bears";

const unsigned short F_NOTE = 5;
const string F_SOUND = "wapp";
const string F_ANIMAL = "Hans";

const unsigned short H_NOTE = 6;
const string H_SOUND = "DOH";
const string H_ANIMAL = "Cletus";


// Range for user inspiration input
const unsigned int MIN_INSPIRATION = 10;
const unsigned int MAX_INSPIRATION = 100;

const string USER_NAME = "Lisa";

int main()
{
  unsigned int inspiration; // Inspiration number
  bool is_valid; // Whether or not the input inspiration is within range
  unsigned int iterations = 0; // Number of iterations through the loop

  unsigned short note; // Computed note number

  // Snax counts for each note
  unsigned int A_snax = 0, B_snax = 0, C_snax = 0, D_snax = 0, E_snax = 0,
               F_snax = 0, H_snax = 0;

  // Greet user and get inspiration
  cout << "Hello, " << USER_NAME << "!" << endl
       << "Let's get right down to business and get some of that dank inspiration."
       << endl << "Gimme some digital inspiration between " << MIN_INSPIRATION 
       << " and " << MAX_INSPIRATION << ": ";
  do
  {
    cin >> inspiration;
    is_valid = inspiration >= MIN_INSPIRATION && inspiration <= MAX_INSPIRATION;

    if(!is_valid)
    {
      if(inspiration < MIN_INSPIRATION)
        cout << "It's not jazz if it doesn't have at least 10 minutes of trumpet sounds!" << endl;
      else
        cout << "Look man, it's not legal for civilians to carry that much inspiration..." << endl;

      cout << "Now, no tomfoolery; gimme that inspiration: ";
    }
  } while(!is_valid);

  cout << "Right on!" << endl << endl;

  // Compose a catchy tune
  while(inspiration != LAST_NOTE)
  {
    // Compute note to play
    note = inspiration % NUM_NOTES;

    // Play note and tally snax
    if(note == A_NOTE)
    {
      cout << A_SOUND;
      A_snax++;
    }
    if(note == B_NOTE)
    {
      cout << B_SOUND;
      B_snax++;
    }
    if(note == C_NOTE)
    {
      cout << C_SOUND;
      C_snax++;
    }
    if(note == D_NOTE)
    {
      cout << D_SOUND;
      D_snax++;
    }
    if(note == E_NOTE)
    {
      cout << E_SOUND;
      E_snax++;
    }
    if(note == F_NOTE)
    {
      cout << F_SOUND;
      F_snax++;
    }
    if(note == H_NOTE)
    {
      cout << H_SOUND;
      H_snax++;
    }

    cout << ' ';
    // Wrap long lines
    iterations++;
    if(iterations % 10 == 0)
      cout << endl ;

    // Compute next inspiration number (Collatz Conjecture)
    if(inspiration % 2 == 0)
    {
      inspiration /=2;
    }
    else
    {
      inspiration = 3 * inspiration + 1;
    }
  }

  // Output snax tallies
  cout << endl << endl
       << "   Snax Tallies" << endl
       << "   ------------" << endl
       << A_ANIMAL << ": " << A_snax << endl
       << B_ANIMAL << ": " << B_snax << endl
       << C_ANIMAL << ": " << C_snax << endl
       << D_ANIMAL << ": " << D_snax << endl
       << E_ANIMAL << ": " << E_snax << endl
       << F_ANIMAL << ": " << F_snax << endl
       << H_ANIMAL << ": " << H_snax << endl
       << endl
       << "Play on, Coltrane; play on." << endl;

  return 0;
}