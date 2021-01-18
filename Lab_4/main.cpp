#include <iostream>

using namespace std;

void Pruma(int G[][12]);

int main()
{
    int G[12][12] =
            {
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 4, 3, 7, 0, 0, 0, 0, 0, 0, 0},
                    {0, 4, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0},
                    {0, 3, 0, 0, 0, 1, 7, 0, 0, 0, 0, 0},
                    {0, 7, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0},
                    {0, 0, 2, 1, 0, 0, 0, 0, 4, 7, 0, 0},
                    {0, 0, 0, 7, 2, 0, 0, 0, 4, 0, 5, 0},
                    {0, 0, 1, 0, 2, 0, 0, 0, 0, 3, 3, 0},
                    {0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 4},
                    {0, 0, 0, 0, 0, 7, 0, 3, 0, 0, 0, 6},
                    {0, 0, 0, 0, 0, 0, 5, 3, 0, 0, 0, 5},
                    {0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 5, 0},
            };

    Pruma(G);

    cout << endl << endl;
    system("pause");
    return 0;
}

bool chekv(int k, int* array, int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (array[i] == k)
        {
            count++;
            break;
        }
    }
    if (count > 0)
        return 0;
    else
        return 1;
}

void Pruma(int G[][12])
{
    int vertix[11], visited[11], o = 1, edg = 0;
    vertix[0] = 1;
    for (int i = 1; i < 11; i++)
        vertix[i] = 0;

    int edges[20];

    for (int k = 0; k < 10; k++)
    {
        int i = 0;
        int min = 1000;
        for (; i < 11; i++)
        {
            for (int j = 1; j < 12; j++)
            {
                if (chekv(j, vertix, 11))
                {
                    if (G[vertix[i]][j] != 0 && G[vertix[i]][j] < min)
                    {
                        min = G[vertix[i]][j];
                        visited[o] = j;
                        edges[edg] = vertix[i];
                        edges[edg + 1] = j;
                    }
                }
            }
        }
        vertix[k+1] = visited[o];
        o++;
        edg += 2;
    }

    cout << "\n  V = {";
    for (int i = 0; i < 11; i++)
    {
        cout << vertix[i];
        if (i != 10)
            cout << " ,";
        else
            cout << "}";
    }
    cout << endl;

    cout << "\n  E = {";
    for (int i = 0; i < 20; i += 2)
    {
        cout << "(" << edges[i] << ", " << edges[i + 1] << ")";
        if (i != 18)
            cout << "; ";
        else
            cout << "}";
    }
}
