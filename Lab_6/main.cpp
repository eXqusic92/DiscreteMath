#include <iostream>
#include <cmath>

using namespace std;

int fact (int n)
{
    int rez=1;
    if (n==0) {rez=1; return rez;}
    while(n!=1)
    {
        rez=rez*n;
        n--;
    }
    return rez;
}

int check (int a[], int n)
{
    int b=0;
    for (int i=0; i<n; ++i)
    {
        for (int j=i+1; j<n; ++j)
        {
            if (a[i]==a[j])
            {
                b++;
            }
        }
    }
    return b;
}

int check2 (int a[], int n)
{
    int r=0;
    for (int i=0; i<n-1; ++i)
    {
        if (a[i]<a[i+1])
        {
            r++;
        }
    }
    return r;
}

long int komb(int k, int n)
{
    return fact(n) / (fact(k) * fact(n - k));
}

int main()
{
    int n;
    cout << "\nEnter the number of elements: ";
    cin >> n;
    if ((cin.fail())||(n<=0)){cout << "\n\nINPUT ERROR\n\n"; return 0;}

    int a[n];
    cout << "\nEnter the elements: \n";

    for (int i=0; i<n; ++i)
    {
        cin >> a[i];
        if (cin.fail()){cout << "\n\nINPUT ERROR\n\n"; return 0;}
    }

    int b=check (a, n);

    if(b==0)
    {
        cout << "\nThe number of possible rearrangements: " << fact(n) << "\n";
    }
    else
    {
        cout << "\nThe array has same elements\n\n";
        return 0;
    }


    int k, k2;
    cout << "\nEnter the number of rearrangements to find: ";
    cin >> k;
    if ((cin.fail())||(k<=0)||(k>(fact(n)))){cout << "\n\nINPUT ERROR\n\n"; return 0;}

    k2=0;
    int r=0;
    int d[n];
    int c[n];
    int nb, nc; nb=0; nc=0;

    while (k2<k)
    {
        r=check2(a, n);
        if (r==0)
        {
            cout << "\nIt was the last rearrangement\n\n\n";
            return 0;
        }

        for (int i=0; i<n; ++i)
        {
            d[i]=0;
            c[i]=0;
        }
        nb=0; nc=0;

        for (int i=n-1; i>0; i--)
        {
            if(a[i-1]<a[i])
            {

                for (int j=0; j<i-1; ++j)
                {
                    c[nc]=a[j];
                    nc++;
                }
                for (int j=n-1; j>i-1; j=j-1)
                {
                    d[nb]=a[j];
                    nb++;
                }

                for (int j=0; j<nb; ++j)
                {
                    if(a[i-1]<d[j])
                    {

                        c[nc]=d[j];
                        nc++;

                        d[j]=a[i-1];

                        for (int t=0; t<nb; ++t)
                        {
                            c[nc]=d[t];
                            nc++;
                        }
                        j=nb+1;
                    }


                }
                i=-1;

            }

        }

        cout << "\n";
        for (int i=0; i<n; ++i)
        {
            cout << "" << c[i];
            a[i]=c[i];
        }

        k2++;
    }

    cout << "\n\tNewton Binomial\n";

    int x, y;
    cout << "\n->Enter x/y: ";
    cin >> x >> y;

    if (x == y) {
        cout << "\n\n(x - y)^9 = 0";
    }
    long int binom = 0;
    for (int i = 0; i <= 9; ++i)
    {
        binom += komb(i, 9) * pow(x, i) * pow(-y, 9 - i);
    }
    cout << "\n\n(x - y)^9 = ";
    for (int i = 0; i < 9; ++i)
    {
        if (i % 2)
        {
            cout << " - ";
        }
        else
        {
            cout << " + ";
        }
        cout << komb(i, 9) << "*(x^" << i << ") * (y^" << 9 - i << ")";
    }
    cout << " = " << binom << "\n";

    return 0;
}
