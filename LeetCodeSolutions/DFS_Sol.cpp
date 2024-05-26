#include<list>
#include<vector>
#include<map>
#include<iostream>
#include<limits.h>
#include<string.h>
using namespace std;

void printVector(vector<int> vectorObj)
{
  for(int val:vectorObj)
  {
    cout<<val<<" ";
  }
  cout<<"\n-----------------------\n";
}

class Graph {
  int numVertices;
  list<int>* adjLists;
  bool* visited;

  public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex);
    int BFS(int startVertex, int endVertex);
    int BFS(bool* visitedVertices, vector<int> visitedVerticesList, int currVertex, int endVertex, int currDistance, int minDistance);
    void printAdjacencyMatrix();
    void printVisitedVertices(bool* visitedVertices);
};

// Create a graph with given vertices,
// and maintain an adjacency list
Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest) 
{  
  // cout<<"Creating edge for " << src << " and " << dest << endl;
  adjLists[src].push_back(dest);
  adjLists[dest].push_back(src);
}

// BFS algorithm
void Graph::BFS(int startVertex) 
{
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  list<int>::iterator i;

  while (!queue.empty()) {
    int currVertex = queue.front();
    // cout << "Visited: " << currVertex << endl;
    queue.pop_front();

    for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
      int adjVertex = *i;
      if (!visited[adjVertex]) {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}

// BFS algorithm
int Graph::BFS(int startVertex, int endVertex)
{
  bool* visitedVertices = new bool[numVertices];
  vector<int> visitedVerticesList;
  for (int i = 0; i < numVertices; i++)
  {
    visitedVertices[i] = false;
  }
  return BFS(visitedVertices, visitedVerticesList, startVertex, endVertex, -1, INT_MAX);
}

int Graph::BFS(bool* visitedVertices, vector<int> visitedVerticesList, int currVertex, int endVertex, int currDistance, int minDistance)
{
  // bool* visitedVerticesTemp = new bool[numVertices];
  vector<int>visitedVerticesListTemp = visitedVerticesList;
  
  visitedVerticesListTemp.push_back(currVertex);
  
  // copy(visitedVertices, visitedVertices+numVertices, visitedVerticesTemp);
  
  visitedVertices[currVertex] = true;
  // visitedVerticesTemp[currVertex] = true;
  currDistance++;
  if(currDistance>=minDistance)
  {
    visitedVertices[currVertex] = false;
    return minDistance;
  }
  // cout << "Visited: " << currVertex << " currDistance: " <<currDistance<< endl;
  // printVisitedVertices(visitedVerticesTemp);
  
  if(currVertex == endVertex)
  {
    cout<<"Reached endVertex: " << endVertex <<endl;
    visitedVertices[currVertex] = false;
    return minDistance < currDistance ? minDistance : currDistance;
  }
  list<int> queue;
  for (list<int>::iterator i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) 
  {
    int adjVertex = *i;
    if(adjVertex == endVertex)
    {
      cout<<"Reached endVertex through adj: " << endVertex <<endl;
      visitedVertices[currVertex] = false;
      return minDistance < (currDistance+1) ? minDistance : (currDistance+1);
    }
    if (!visitedVertices[adjVertex]) 
    {
      queue.push_back(adjVertex);
    }
  }
  while (!queue.empty()) 
  {
    int minDistTemp = BFS(visitedVertices, visitedVerticesListTemp, queue.front(), endVertex, currDistance, minDistance);
    if(minDistTemp < minDistance)
    {
      minDistance = minDistTemp;
    }
    queue.pop_front();
  }
  printVector(visitedVerticesListTemp);
  // printVisitedVertices(visitedVerticesTemp);
  return minDistance;
}

void Graph::printAdjacencyMatrix()
{
  cout<<"-----------------------"<<endl;
  cout<<"printAdjacencyMatrix()"<<endl;
  for(int i = 0; i < numVertices; i++)
  {
    cout<<"Source: " << i <<" Adjacent Elements: ";
    for (list<int>::iterator it = adjLists[i].begin(); it != adjLists[i].end(); ++it) 
    {
      int adjVertex = *it;
      cout<<adjVertex<<" ";
    }
    cout<<endl;
  }
  cout<<"-----------------------"<<endl;
}

void Graph::printVisitedVertices(bool* visitedVertices)
{
  // cout<<"-----------------------"<<endl;
  // cout<<"printVisitedVertices()"<<endl;
  for(int i = 0; i< numVertices;i++)
  {
    // cout<<i <<" "<<(visitedVertices[i] ? "Yes" : "No") << " ";
  }
  // cout<<endl<<"-----------------------"<<endl;
}

class Solution 
{
public:
  int minJumps(vector<int>& arr) 
  {
    int size = arr.size();
    map<int,vector<int>> indexMap;
    int jumps = 0;
    Graph g(size);
    for(int index = 0; index < size; index++)
    {
      int element = arr[index];
      if(index<size-1)
      {
        g.addEdge(index, index + 1);
      }
      auto it = indexMap.find(element);
      bool isElementExists = it != indexMap.end();
      if(!isElementExists)
      {
        indexMap[element] = vector<int>();
      }
      indexMap[element].push_back(index);
      // cout<<element << " exists: " << (isElementExists != 0 ? "Yes" : "No") << endl;
    }
    // cout<<"-----------------------"<<endl;
    for(map<int,vector<int>>::iterator iter = indexMap.begin(); iter != indexMap.end(); ++iter)
    {
      int element =  iter->first;
      vector<int> indexes = iter->second;
      if(indexes.size()>1)
      {
        // cout<<element << " exists more than once!!" <<endl;
        for(int i=0; i<indexes.size(); i++)
        {
          for(int j = i+1; j <indexes.size(); j++)
          {
            int index1 = indexes[i];
            int index2 = indexes[j];
            if(index1!=index2-1)
            {
              g.addEdge(index1, index2); 
            }
          }
        }
      }
    }
    g.printAdjacencyMatrix();
    // return g.BFS(size - 1, 0);
    return g.BFS(0,size - 1);
  }
};

int main()
{
    Solution sol;
    vector<int> input;
    int size,val;
    // cout<<"Enter the size: ";
    cin>>size;
    while(size>0)
    {
        cin>>val;
        size--;
        input.push_back(val);
    }
    int minJumps = sol.minJumps(input);
    cout<<"Min Jumps: " << minJumps;
    return 0;
}

// [100,-23,-23,404,100,23,23,23,3,404]
/*
testBFS 
10
100
-23
-23
404
100
23
23
23
3
404
*/