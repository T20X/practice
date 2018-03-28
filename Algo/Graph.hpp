#pragma once

#include <vector>
#include <iostream> 
#include <string>
#include <set>
#include <map>
#include <limits>
#include <stack>
#include <queue>
#include <functional>


#include "../Utils/TextFile.hpp"
#include "../Utils/Numeric.hpp"

using namespace std;

class AdjacencyMatrixGraph
{
public:
    enum Type
    {
        DIRECTED,
        UNDIRECTED
    };

    explicit AdjacencyMatrixGraph(const size_t capacity, Type t = DIRECTED);
    ~AdjacencyMatrixGraph();

    struct Edge
    {
       Edge()        
          : w(_no_weight_),
            v(false)
        {}

        explicit Edge(int weight)
         : w(weight),       
           v(true)
        {}
        
        const static int _no_weight_ = numeric_limits<int>::min();
        int w;     
        bool v;        
    };

    bool addVertex(const string& vertex);   

    typedef std::function<void(const string&, const string&)> ReportFunc;
    bool addEdge(const Edge& edge, const string& from, const string& to,
                 ReportFunc&& report = [](const string& from, const string& to)
                 { throw runtime_error("failed to add an Edge" + from + "to " + to); });
    void dijkstraSearch(const string& at, const string& to);
    void dumpEdges(ostream& o);
    void depthFirst(ostream& o);
    void spanningTree(ostream& o);
    void breadthFirst(ostream& o);
  
    //friend class AdjacencyMatrixGraphTest;

private:
    AdjacencyMatrixGraph(const AdjacencyMatrixGraph& other);
    AdjacencyMatrixGraph& operator=(const AdjacencyMatrixGraph& other);

    size_t findVertexPos(const string& v);    
    void doBreadthFirst();

private:   
    Type m_type;
    Edge** m_graph;
    vector<string> m_vertecies;
    size_t m_capacity;
};

/***************************************************************
*/

AdjacencyMatrixGraph::AdjacencyMatrixGraph(const size_t capacity, Type t)
    :m_type(t), m_capacity(capacity)
{
    m_graph = new Edge*[m_capacity];
    for (int i = 0; i < m_capacity; i++)
        m_graph[i] = new Edge[m_capacity];
}

/***************************************************************
 */

AdjacencyMatrixGraph::~AdjacencyMatrixGraph()
{
    for (size_t x = 0; x < m_capacity; x++)            
         delete [] m_graph[x]; 

    delete [] m_graph;
}

/***************************************************************
*/

bool AdjacencyMatrixGraph::addVertex(const string& vertex)
{
    if (find(m_vertecies.begin(), m_vertecies.end(), vertex) ==
             m_vertecies.end())
    {
        m_vertecies.push_back(vertex);
        return true;
    }
    else
    {
        return false;
    }
}

/***************************************************************
*/

bool AdjacencyMatrixGraph::addEdge(const Edge& edge, const string& from, const string& to, ReportFunc&& report)
{
    addVertex(from);
    addVertex(to);

    size_t xPos = findVertexPos(from);
    size_t yPos = findVertexPos(to);

    if (m_type >= 0/*anytype*/)
    {
        Edge& place = m_graph[xPos][yPos];
        if (place.v) return false; // edge already exists!

        place.w = edge.w;
        place.v = edge.v;
    }

    if (m_type == UNDIRECTED)
    {        
        if (m_graph[yPos][xPos].v) return false; // edge already exists!
     
        Edge& place = m_graph[xPos][yPos];
        place.w = edge.w;
        place.v = edge.v;
    }
    
    return true;
}

/***************************************************************
*/

size_t AdjacencyMatrixGraph::findVertexPos(const string& v)
{
    vector<string>::const_iterator it = 
        find(m_vertecies.begin(),
             m_vertecies.end(),
             v);

    if (it == m_vertecies.end()) throw runtime_error("v not found");    
    return (it - m_vertecies.begin());
}

/***************************************************************
*/

struct node
{
    size_t at;
    int cost;

    node(size_t at_, int cost_)
       :at(at_), cost(cost_)
    {}
};

struct minWeight : std::binary_function<node, node, bool>
{
    bool operator()(node left, node right) const
    {
        return left.cost > right.cost; ;
    }
};

void AdjacencyMatrixGraph::dijkstraSearch(const string& at, const string& to)
{
    size_t atPos = findVertexPos(at);
    size_t toPos = findVertexPos(to);

    set<size_t> visited;
    priority_queue<node, vector<node>, minWeight> path;
    path.push(node(0,0));

    while (!path.empty())
    {
        node x = path.top();
        path.pop();

        pair<set<size_t>::iterator, bool> r = visited.insert(x.at);
        if (r.second == false)
            continue;

        cout << "visited node ->" << m_vertecies[x.at] << endl; //visit

        if (toPos == x.at)
        {
            cout << "found [" << to << "]" << endl;
            break;
        } 
      
        for (size_t y = 0; y < m_capacity; y++)
        {
            if (m_graph[x.at][y].v)
            {
                path.push(node(y,m_graph[x.at][y].w));

                // edges
                cout << m_vertecies[x.at] << " to "
                     << m_vertecies[y] << " weight "
                     << m_graph[x.at][y].w << "\n";
            }
        }
    }




   /* set<string> unvisited;
    copy(m_vertecies.begin(), m_vertecies.end(), inserter(unvisited,unvisited.begin()));

    map<string,int> distance;
    {    
        for (set<string>::const_iterator it = unvisited.begin(); it != unvisited.end(); it++)
               distance.insert(make_pair(*it, numeric_limits<int>::max()));       

        distance[at] = 0;
    }

    string current = at;
    int N = m_vertecies.size();
    while(unvisited.empty())
        size_t x = findVertexPos(current);
        for (size_t y = 0; y < N; y++)
        {
            if (m_graph[x][y].v)
            {
                int previousDistance = distance[current];
                int currentDistance = distance[m_vertecies[y]];
               /* if ((m_graph[x][y].d + previousDistance) < currentDistance ) 
                {
                }
            }
        }
    }*/


}

/***************************************************************
*/

void AdjacencyMatrixGraph::depthFirst(ostream& o)
{
    stack<size_t> vertices;
    set<size_t> visited;
    
    vertices.push(0);
    while (!vertices.empty())
    {      
        size_t x = vertices.top();
        vertices.pop();
        
        pair<set<size_t>::iterator, bool> r = visited.insert(x);
        if (r.second == false)
            continue;
        
        o << "visited node ->" << m_vertecies[x] << endl; //visit
      
        for (int y = 0; y < m_capacity; y++)
        {
            if (m_graph[x][y].v)
            {
                vertices.push(y);

                // visit edge
                o << m_vertecies[x] << " to "
                    << m_vertecies[y] << " weight "
                    << m_graph[x][y].w << "\n";
            }
        }      
    } 
}

/***************************************************************
*/

void AdjacencyMatrixGraph::spanningTree(ostream& o)
{
    stack<size_t> vertices;
    set<size_t> spanningTree;

    vertices.push(0);
    while (!vertices.empty())
    {
        size_t x = vertices.top();
        vertices.pop();
        
        //visit node
        o << "visited node ->" << m_vertecies[x] << endl; //visit

        for (int y = 0; y < m_capacity; y++)
        {     
            if (m_graph[x][y].v)
            {
                vertices.push(y);

                if (spanningTree.find(y) !=
                    spanningTree.end())
                    continue;
                                
                spanningTree.insert(y);

                // visit edge
                o << m_vertecies[x] << " to " 
                  << m_vertecies[y] << " weight " 
                  << m_graph[x][y].w << "\n";
            }
        }
    }
}

/***************************************************************
*/

void AdjacencyMatrixGraph::breadthFirst(ostream& o)
{
    set<size_t> v;
    queue<size_t> path;
    path.push(0);
    v.insert(0);

    while (!path.empty())
    {
        size_t x = path.front();
        path.pop();
        
        for (size_t y = 0; y < m_capacity; y++)
        {
            if (m_graph[x][y].v)
            {
                pair<set<size_t>::iterator, bool> r = v.insert(y);
                if (!r.second)
                   continue;

                path.push(y);
                v.insert(x);

                // visit edge
                o << m_vertecies[x] << " to "
                    << m_vertecies[y] << " weight "
                    << m_graph[x][y].w << "\n";
            }
        }

        o << "visited node " << m_vertecies[x] << endl;
    }
}


/***************************************************************
*/

void AdjacencyMatrixGraph::dumpEdges(ostream& o)
{
    int N = m_vertecies.size();
    for (size_t x = 0; x < N; x++)
    {
        for (size_t y = 0; y < N; y++)
        {
            if (m_graph[x][y].v) 
                o << m_vertecies[x] << ":" << x << " to "  
                  << m_vertecies[y] << ":" << y << " is "  
                  << m_graph[x][y].w
                  << endl;
        }  
    }
}

/***************************************************************
*/

class AdjacencyMatrixGraphTest
{
public:
    static void basicTest()
    {
        try
        {
            AdjacencyMatrixGraph graph(5);

            if (!graph.addVertex("A")) throw runtime_error("no vertex A");
            if (!graph.addVertex("B")) throw runtime_error("no vertex B");        
            if (!graph.addVertex("C")) throw runtime_error("no vertex C");  
            if (!graph.addVertex("D")) throw runtime_error("no vertex D");  

            if (!graph.addEdge(AdjacencyMatrixGraph::Edge(23), "A", "B"))
                throw runtime_error("failed to add an Edge A to B 23");

            if (!graph.addEdge(AdjacencyMatrixGraph::Edge(2), "B", "C"))
                throw runtime_error("failed to add an Edge B to C 2");

            graph.dumpEdges(cout);
        }
        catch (const exception& e)
        {
            cout << "Failed AdjacencyMatrixGraphTest::basicTest" << e.what();
        }
    }

    static void depthFirstSearch()
    {
        try
        {
            AdjacencyMatrixGraph graph(8, AdjacencyMatrixGraph::UNDIRECTED);
            {
                graph.addEdge(AdjacencyMatrixGraph::Edge(23), "A", "B");
                graph.addEdge(AdjacencyMatrixGraph::Edge(2), "A", "C");
                graph.addEdge(AdjacencyMatrixGraph::Edge(2), "A", "D");
                graph.addEdge(AdjacencyMatrixGraph::Edge(2), "D", "C");
                graph.addEdge(AdjacencyMatrixGraph::Edge(2), "D", "B");
                graph.addEdge(AdjacencyMatrixGraph::Edge(2), "D", "E");
                graph.addEdge(AdjacencyMatrixGraph::Edge(2), "E", "F");
                graph.addEdge(AdjacencyMatrixGraph::Edge(2), "E", "G");
                //graph.dumpEdges(cout);
            }                    

            cout << endl << "DepthFirstTraverseVertices" << endl;
            graph.depthFirst(cout);

            cout << endl << "DepthFirstSpanningTree" << endl;
           // graph.spanningTree(cout);

            cout << endl << "BreathFirstTraverseVertices" << endl;
            graph.breadthFirst(cout);
           
        }
        catch (const exception& e)
        {
            cout << "Failed AdjacencyMatrixGraphTest::basicTest" << e.what();
        }
    }

    static void dijkstraSearch()
    {
        try
        {
            AdjacencyMatrixGraph graph(10);

            graph.addEdge(AdjacencyMatrixGraph::Edge(1), "A", "B");;
            graph.addEdge(AdjacencyMatrixGraph::Edge(10), "A", "C");
            graph.addEdge(AdjacencyMatrixGraph::Edge(3), "A", "D");
            graph.addEdge(AdjacencyMatrixGraph::Edge(1), "B", "C");
            graph.addEdge(AdjacencyMatrixGraph::Edge(2), "A", "F");
            graph.addEdge(AdjacencyMatrixGraph::Edge(1), "A", "E");

            graph.dijkstraSearch("A", "C");
        }
        catch (const exception& e)
        {
            cout << "Failed AdjacencyMatrixGraphTest::basicTest" << e.what();
        }
    }
};