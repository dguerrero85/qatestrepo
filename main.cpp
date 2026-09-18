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

// C++ include directive
#include <iostream>
using namespace std;

// From STL
#include <limits.h>

// Number of vertices in the graph
#define V 8

// Function prototypes
void identify ();
int minDistance(int [], bool []);
void print(int []);
void dijkstra(int [V][V], int);

int main ()
{
  // Call function for programmer's identification
  identify();

  // Create a graph
	int graph[V][V] =
  {
    { 0, 0, 5, 0, 0, 7, 0, 0 },
		{ 7, 0, 0, 23, 0, 0, 0, 0 },
		{ 0, 2, 0, 7, 0, 0, 0, 2 },
		{ 0, 0, 0, 19, 9, 0, 0, 1 },
		{ 5, 0, 3, 0, 0, 9, 0, 5 },
		{ 0, 0, 0, 0, 5, 0, 0, 8 },
		{ 0, 5, 0, 0, 3, 2, 6, 0 },
		{ 1, 0, 0, 5, 0, 0, 9, 0 }
  };
  
	// Function call
	dijkstra(graph, 0);

  // One more time from different source
  dijkstra(graph, 7);

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

// Gets called from the dijkstra function.
// Finds the vertex with minimum distance value
// from the vertices not yet in sptSet
int minDistance(int dist[], bool sptSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;
  
  // for loop that executes V times
	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;
  
  // Returns the minimum distance
	return min_index;
}

// Gets called from the dijkstra function,
// prints the distance from source to veritice
void print(int dist[])
{
	// Tell user what's being printed
  cout << "Vertex \t\t Distance from Source" << endl;
	
  // for loop that iterates through each veritice
  // and its distance from source
  for (int i = 0; i < V; i++)
		cout << i << " \t\t\t" << dist[i] << endl;
  
  cout << endl; // extra line for desired output
}

// Main Dijkstra's shortest path algorithm
// function. Calls the minDistance and print functions
// from within
void dijkstra(int graph[V][V], int src)
{
  // Create an array hat holds the distance from source
  // for each veritice
  int dist[V];

  // Create an array where bool value will be true
  // if the veritice is already included in shortest path tree
	bool sptSet[V];

	// Initialize all distances as infinite and stpSet[] as false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source from source is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++)
  {
		// Pick the minimum distance vertex from the set of
		// vertices not yet processed.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update distance of the adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < V; v++)

			// Check if A) veritice is not in sptSet,
			// B) there is an edge from u to v,
			// and C) total weight of path from source to v
			// through u is less than current distance
			if ( ! sptSet[v] && graph[u][v]
				  && dist[u] != INT_MAX
				  && dist[u] + graph[u][v] < dist[v])
				  
          // Update distance if the condition above applies
          dist[v] = dist[u] + graph[u][v];
	}

	// print the dist array that holds the distance
	print(dist);
}