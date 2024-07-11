#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > makeMatrix(int x);
void printMatrix(vector<vector<int> > v);

int find_node(int current_vertex);

vector<vector<int> > v;

int main()
{
    int vertex_num;
    int edge_num;

    cin >> vertex_num;
    cin >> edge_num;

    v = makeMatrix(vertex_num);
    vector<int> virus(vertex_num);

    for(int i = 0 ; i < edge_num ; i++)
    {
        int tmp1;
        int tmp2;

        cin >> tmp1 >> tmp2;

        v[tmp1 - 1][tmp2 - 1] = 1;
        v[tmp2- 1][tmp1 - 1] = 1;
    }

    virus[0] = -1;

    int current_vertex = 0;
    int count = 0;

    count += find_node(current_vertex);

    // for(int i = 0 ; i < vertex_num ; i++)
    // {
    //     if(virus[i] == -1)
    //     {
    //         count++;
    //     }
    // }
    cout << count<< endl;

    return 0;
}

vector<vector<int> > makeMatrix(int x)
{
    vector<int> matrix1(x);
    vector<vector<int> > resultMatrix;

    for(int i = 0 ; i < x ; i++)
        resultMatrix.push_back(matrix1);

    return resultMatrix;
}

void printMatrix(vector<vector<int> > v)
{
    for(int i = 0 ; i < v.size() ; i++)
    {
        for(int j = 0 ; j < v.size() ; j++)
        {
            cout << v[i][j] << "\t";
        }
        cout << endl;
    }
}

int find_node(int current_vertex)
{
    int count = 0;

    if(v[current_vertex][current_vertex] == -1)
        return -1;

    v[current_vertex][current_vertex] = -1;

    for(int i = 0 ; i < v.size() ; i++)
    {
        if(i == current_vertex)
            continue;
        
        if(v[current_vertex][i] == 0)
            continue;
        else
        {
            v[current_vertex][i] = 0;
            v[i][current_vertex] = 0;

            int t = find_node(i);
            if(t == -1)
                continue;

            count += (1 + t);
        }
    }

    return count;
}