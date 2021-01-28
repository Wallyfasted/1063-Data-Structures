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
  // Game Array
  Games library[30];

  // Opens Input File
  ifstream read;
  read.open("Games.txt");

  // Variable Declarations
  int numGames;
  string nameGame;
  string END;
  
  read >> numGames;

  // Reads entire input file
  for (int i= 0; i < numGames; i++)
  {
        read >> library[i].Title;
        read >> library[i].Price;
        read >> library[i].Rating;
        read >> library[i].Year;
  }

  cout << "What game are you looking for? " << '\n';
  
  int index = 0;

  cin >> nameGame;

  while (nameGame != END)
  {
    // loop to find game and display information
    for (int i = 0; i < numGames; i++)
    {

      if(library[i].Title == nameGame)
      {
        index = i;

        // Outputs information
        cout << library[index].Title 
             << " " << library[index].Price 
             << " " << library[index].Rating 
             << " " << library[index].Year;
        
        // Makes spaces for multiple searches
        int NEXT;
        cout << '\n' << "Type NEXT to move on" << '\n';
        cin >> NEXT;
        cout << string(300, '\n');
        cin >> nameGame;
      }
    }
  }

  read.close();
  return(0);
}

