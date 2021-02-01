/*
Andrew Harrison
Samuel Campbell
Data Structures and Analysis
Major Program 1 - Database
1 - 20 - 2021
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Struct for games
struct Games
{
  string Title;
  string Price;
  string Rating;
  float Year;
};


int main()
{

  // Opens Input File
  ifstream read;
  read.open("Games.txt");

  // Variable Declarations
  int numGames;
  string nameGame;
  int index = 0;
  
  // Reads number of games in input file
  read >> numGames;
  
    // Game Array
  Games* library= new Games[numGames];


  // Reads entire input file
  for (int i= 0; i < numGames; i++)
  {
        read >> library[i].Title;
        read >> library[i].Price;
        read >> library[i].Rating;
        read >> library[i].Year;
  }

  // Outputs question for search
  cout << "What game are you looking for? " << '\n';
  cout << "Type END to stop program" << '\n';

  // Enter the name for program to find and display information
  cin >> nameGame;

  // Sentinel loop where you type END to stop program 
  while (nameGame != "END")
  {
    // loop to find game and display information
    for (int i = 0; i < numGames; i++)
    {
      // if statement for displaying games
      if(library[i].Title == nameGame)
      {
        index = i;

        // Outputs information
        cout << left << setw(18) <<  "Title: " << right << setw(17) << library[index].Title 
             << left << setw(18) <<"\nPrice: " << right << setw(7) <<library[index].Price 
             << left << setw(18) <<"\nRating:  " << right << setw(7) <<library[index].Rating 
             << left << setw(18) <<"\nRelease Date:  " << right << setw(5) <<library[index].Year;
        
        // Makes spaces for multiple searches
        string NEW;
        cout << "\n\n" << "Type NEW for the new search" << '\n';
        cin >> NEW;
        cout << string(75, '\n');
        // Repeats question for new search
        cout << "\n" << "What game are you looking for?" << '\n';
        cout << "Type END to stop program" << '\n';
        cin >> nameGame;
      }
    }
  }
  // Program ending statement
  cout << "Thank you, have a nice day :)";

  // closes input file and returns
  read.close();
  delete[] library;
  return(0);
}

