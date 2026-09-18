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
*/

#ifndef GRAPH_HPP
#define GRAPH_HPP

// C++ include directives
#include <vector>
#include <iomanip>
#include <iostream>
#include <queue>
#include <list>

using namespace std;

// C include directoves
#include <cstdlib>

#define INF 0x3f3f3f3f // Defines infinity(rather audacious)
typedef pair <int, int> iPair;
 
// Class for graph using adjacency list
class Graph
{
  int V; // No. of vertices

  // Stores vertex and weight pair for every edge
  list <pair <int, int> > *adj;
 
  public:
    Graph(int V); // Constructor
 
    // function to add an edge to graph
    void addEdge(int u, int v, int w);
 
    // prints shortest path from s
    void shortestPath(int s);
};
 
// Allocates memory for adjacency list
Graph::Graph(int V)
{
  this->V = V;
  adj = new list <iPair> [V];
}
 
void Graph::addEdge(int u, int v, int w)
{
  adj[u].push_back (make_pair(v, w));
  adj[v].push_back (make_pair(u, w));
}

void Graph::shortestPath(int src)
{
  priority_queue <iPair, vector<iPair>, greater<iPair>> pq;
 
  // Create vector for distances and initialize all as infinite (INF)
  vector<int> dist(V, INF);
 
  // Insert start vertex and initialize its distance as 0.
  pq.push(make_pair(0, src));
  dist[src] = 0;
 
  // Looping till PQ is empty
  while (!pq.empty())
  {
    int u = pq.top().second;
    pq.pop();
 
    // Get all adjacent vertices of a vertex
    list <pair<int, int> >::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
      // Get vertex label and weight of current adjacent of u.
      int v = (*i).first;
      int weight = (*i).second;
 
      // If there is a shorter path to v through u.
      if (dist[v] > dist[u] + weight)
      {
        // Updating distance of v
        dist[v] = dist[u] + weight;
        pq.push(make_pair(dist[v], v));
      }
    }
  }
}

#endif