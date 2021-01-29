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
  Games library[40];

  // Opens Input File
  ifstream read;
  read.open("Games.txt");

  // Variable Declarations
  int numGames;
  string nameGame;
  int index = 0;
  char selection;
  
  // Reads number of games in input file
  read >> numGames;

  // Reads entire input file
  for (int i= 0; i < numGames; i++)
  {
        read >> library[i].Title;
        read >> library[i].Price;
        read >> library[i].Rating;
        read >> library[i].Year;
  }

  // While loop for switch statement to keep running
  while (selection != 4)
  {
    // output statements for selections 
    cout << "Please input number for what selection you would like" << '\n';
    cout << "1. Instructions" << '\n';
    cout << "2. Example" << '\n';
    cout << "3. Search Engine" << '\n';
    cout << "Selction: ";
    cin >> selection;
    cout << '\n';

    // switch statment for multiple selections
    switch (selection)
    {
      // Case 1 for INSTRUCTIONS on what to do
      case '1':
        cout << "INSTRUCTIONS" << '\n';
        cout << ">Use _ as spaces when looking up games" << '\n';
        cout << ">Make sure to use capital letters where they are needed" << '\n';
        cout << ">At the end of search type NEW or new for a new search" << '\n';
        cout << ">If you want to stop the program just type END to stop program" << '\n';
        cout << "----------------------------------------------------------------" << '\n';
        break;
      
      // Case 2 for an EXAMPLE of how to write the game names
      case '2':
        cout << "EXAMPLE" << '\n';
        cout << "Please write the name of the game like this: " << '\n';
        cout << "Hyrule_Warriors_Age_of_Calamity" << '\n';
        cout << "----------------------------------------------------------------" << '\n';
        break;

      // Case 3 starts the search engine 
      case '3':
      cout << "What game would you like? ";
      cin >> nameGame;
      cout << '\n';

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
            cout << left << setw(17) <<  "Title: " << library[index].Title 
                << left << setw(18) <<"\nPrice: " <<library[index].Price 
                << left << setw(18) <<"\nRating:  " <<library[index].Rating 
                << left << setw(18) <<"\nRelease Date:  " <<library[index].Year;
            
            
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
      
      //Closes if you type END
      read.close();
      return(0);
    }

  }
    // closes input file and returns
    read.close();
    return(0);
}

