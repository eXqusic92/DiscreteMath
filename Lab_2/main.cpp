#include <iostream>

using namespace std;

void Sorting(float* ar, int size)
{
    float tmp;
    for (int n = 0; n < size - 1; n++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (ar[i] > ar[i + 1])
            {
                tmp = ar[i];
                ar[i] = ar[i + 1];
                ar[i + 1] = tmp;
            }
        }
    }
}

float ArUn(float* ar, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (ar[i] == ar[j])
            {
                for (int n = j; n < size - 1; n++)
                {
                    ar[n] = ar[n + 1];
                }
                size -= 1;
                if (ar[i] == ar[j])
                {
                    j--;
                }
            }
        }
    }
    Sorting(ar, size);
    return size;
}


int main()
{
    int s, s2, s3;

    cout << "\tEnter the size of array A: ";
    cin >> s;
    cout << endl;

    float* a = new float[s];
    int i;
    cout << "\tFill in the array A: ";
    for (i = 0; i < s; i++)
    {
        float ai;
        cin >> ai;
        a[i] = ai;
    }

    cout << "\n\tEnter the size of array B: ";
    cin >> s2;
    cout << endl;

    float* b = new float[s2];
    cout << "\tFill in the array B: ";
    for (i = 0; i < s2; i++)
    {
        float bi;
        cin >> bi;
        b[i] = bi;
    }

    // Операції обєднання та перетину масивів

    s3 = s2 + s;
    float* c = new float[s3];
    for (i = 0; i < s; i++)
    {
        c[i] = a[i];
    }
    for (i = s; i < s3; i++)
    {
        c[i] = b[i - s];
    }
    cout << "\n -> Union of A and B: ";
    for (i = 0; i < ArUn(c, s3); i++)
    {
        cout << c[i] << " ";
    }
    cout << endl << "Power = " << ArUn(c, s3) << endl;


    cout << " -> Intersection of A and B: ";
    int kk = 0;
    float* k = new  float[kk];
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s2; j++)
        {
            if (a[i] == b[j])
            {
                k[kk] = a[i];
                kk++;
            }
        }
    }
    Sorting(k, kk);
    for (i = 0; i < kk; i++)
    {
        cout << k[i] << " ";
    }
    cout << endl << "Power = " << kk << endl;
    return 0;
}