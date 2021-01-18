#include<iostream>
#include "cmath"

using namespace std;

void refl(int** arr, int size);
void symmetric(int** arr, int size);
void tranz(int** arr, int size);

int main()
{
    int sA, sB;
    cout << "\nEnter the size of array A: ";
    cin >> sA;
    int* A = new int[sA];
    cout << "Fill in the array A: ";
    for (int i = 0; i < sA; i++)
    {
        cin >> A[i];
    }

    cout << "Enter the size of array B: ";
    cin >> sB;
    int* B = new int[sB];
    cout << "Fill in the array B: ";
    for (int i = 0; i < sB; i++)
    {
        cin >> B[i];
    }


    int** Matrix = new int* [sA];

    for (int i = 0; i < sA; i++)
    {
        Matrix[i] = new int[sB];
    }


    for (int i = 0; i < sA; i++)
    {
        for (int j = 0; j < sB; j++)
        {
            if (pow(A[i], 2) < B[j])
            {
                Matrix[i][j] = 1;
            }
            else
            {
                Matrix[i][j] = 0;
            }
        }
    }

    cout << "\n   Matrix:\n\n";

    for (int i = 0; i < sA; i++)
    {
        for (int j = 0; j < sB; j++)
        {
            cout << Matrix[i][j] << "\t";
        }
        cout << endl << endl;
    }

    if (sA == sB)
    {
        cout << "|| The relation is:\n";
        refl(Matrix, sA);
        symmetric(Matrix, sA);
        tranz(Matrix, sA);
    }


    for (int i = 0; i < sA; i++)
    {
        delete[] Matrix[i];
    }

    delete[] Matrix;
    delete[] A;
    delete[] B;
    system("pause");
    return 0;
}


void refl(int** arr, int size)
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i][i] == 1)
        {
            counter++;
        }
    }

    if (counter == size)
    {
        cout << "   -reflexive;\n";
    }
    else if (counter == 0)
    {
        cout << "   -irreflexive;\n";
    }
    else
    {
        cout << "   -not reflexive;\n";
    }
}

void symmetric(int** arr, int size)
{
    int counter = 0, count1 = 0, count1d = 0, checker = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i][i] == 1) count1d++;

        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] == 1) count1++;
            if (arr[i][j] == arr[j][i] && arr[j][i] == 1) counter++;
            if (arr[i][j] != arr[j][i]) checker++;
        }
    }

    if (counter == 0) cout << "   -asymmetric;\n";
    else if (checker > 0 ) cout << "   -not symmetric;\n";
    else if (counter == count1d && count1d == size) cout << "   -antisymmetric;\n";
    else if(counter == count1) cout << "   -symmetric;\n";
}

void tranz(int** arr, int size)
{

    int t = 0, T = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                if ((arr[i][j] == 1) && (arr[j][k] == 1))
                {
                    if (arr[i][k] != 1)
                    {
                        t = 1;
                        break;
                    }
                }
            }
        }
    }
    if (t == 0) cout << "   -transitive;\n";
    if (t == 1) cout << "   -not transitive; \n";
}
