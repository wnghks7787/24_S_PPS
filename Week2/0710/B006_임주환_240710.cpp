#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define BLACK 0
#define GRAY 1
#define WHITE 2

class Vertex
{
    int number;
    int color;
    vector<int> neighbor;

public:
    Vertex(int num);
    
    int getNumber();
    void setNumber(int num);
    int getColor();
    void setColor(int c);
    vector<int> getNeighbor();
    void addNeighbor(int v);

    void sortNeighbor();
};

vector<Vertex> DFS(vector<Vertex> v, int start_num);

void BFS(vector<Vertex> v, int start_num);


int main()
{
    int n, m, v;

    cin >> n >> m >> v;
    vector<Vertex> vertexes;

    // vertex 생성
    for(int i = 0 ; i < n ; i++)
    {
        Vertex tmpVertex(i + 1);
        vertexes.push_back(tmpVertex);
    }

    // edge 생성
    for(int i = 0 ; i < m ; i++)
    {
        int vertex1, vertex2;

        cin >> vertex1 >> vertex2;

        vertexes[vertex1 - 1].addNeighbor(vertex2);
        vertexes[vertex2 - 1].addNeighbor(vertex1);
    }
    
    // 정렬(이웃)
    for(int i = 0 ; i < n ; i++)
    {
        vertexes[i].sortNeighbor();
    }

    // DFS
    DFS(vertexes, v);
    cout << endl;

    // BFS
    BFS(vertexes, v);
    cout << endl;

    
    return 0;
}

Vertex::Vertex(int num)
{
    number = num;
    color = WHITE;
}

int Vertex::getNumber()
{
    return number;
}

void Vertex::setNumber(int num)
{
    number = num;
}

int Vertex::getColor()
{
    return color;
}

void Vertex::setColor(int c)
{
    color = c;
}

vector<int> Vertex::getNeighbor()
{
    return neighbor;
}

void Vertex::addNeighbor(int v)
{
    neighbor.push_back(v);
}

void Vertex::sortNeighbor()
{
    sort(neighbor.begin(), neighbor.end());
}

vector<Vertex> DFS(vector<Vertex> v, int start_num)
{
    int size = v[start_num - 1].getNeighbor().size();

    if(v[start_num - 1].getColor() == WHITE)
    {
        cout << start_num << " ";
        v[start_num - 1].setColor(GRAY);
    }

    for(int i = 0 ; i < size ; i++)
    {
        if(v[v[start_num - 1].getNeighbor()[i] - 1].getColor() == WHITE)
        {
            v = DFS(v, v[start_num - 1].getNeighbor()[i]);
        }
    }
    v[start_num - 1].setColor(BLACK);
    return v;
}

void BFS(vector<Vertex> v, int start_num)
{
    queue<int> vQ;
    int size = v[start_num - 1].getNeighbor().size();

    if(v[start_num - 1].getColor() == WHITE)
    {
        v[start_num - 1].setColor(GRAY);
        vQ.push(start_num);
    }

    while(1)
    {
        for(int i = 0 ; i < v[start_num - 1].getNeighbor().size() ; i++)
        {
            if(v[v[start_num - 1].getNeighbor()[i] - 1].getColor() == WHITE)
            {
                vQ.push(v[start_num - 1].getNeighbor()[i]);
                v[v[start_num - 1].getNeighbor()[i] - 1].setColor(GRAY);
            }
        }

        v[vQ.front() - 1].setColor(BLACK);
        cout << vQ.front() << " ";
        vQ.pop();

        if(vQ.empty())
            break;

        start_num = vQ.front();
    }
}