/*
Name: Dominick Yenches
Student ID: 2053735
Course: COMSC-210
Section: 5068
Lab Number 05
Lab Name: Dijkstra's Algorithm 
Date: Vovember 11th, 2023
Environment: macOS Big Sur Version 11.6.5
             with Visual Studio Code Version: 1.80.1
Description: This program will implement a graph, and
             then find the shortest path from source
             vertex to all other veritices in the graph
*/

// C++ include directives
#include <vector>
#include <iomanip>
#include <iostream>
#include <queue>
#include <list>

#include "graph.hpp" // Needed for Class "Graph"

using namespace std;

// C include directive
#include <cstdlib>

// Function prototypes
void identify ();

int main ()
{
  // Call function for programmer's identification
  identify();

  

  return 0; // Always include a return
}

// This function identifies the programmer
// Called from main, doesn't recieve any parameters,
// and doesn't return any value
void identify()
{
  // programmer's identification
  cout << "\nProgrammer: Dominick Yenches\n";
  cout << "Programmer's Student ID: 2053735\n";
  cout << "File: " << __FILE__ << endl;
  cout << endl; // For desired output format
}
