#include <iostream>
#include <iomanip>

using namespace std;

void Create(int*& a, const int size, int Min, int Max, int i);
void Sum(int* list, const int size, int& indexMax, int& sum, int i);
void Mult(int* list, const int size, int& mul, int i);
void Print(int* list, const int size, int i);

int main()
{
    

    srand((unsigned)time(NULL));

   

    int n, leftLimit, rightLimit;
    cout << "n: "; cin >> n;
    cout << "Left limit: "; cin >> leftLimit;
    cout << "Right limit: "; cin >> rightLimit;

    int* a;

    int Min = leftLimit;
    int Max = rightLimit;
    int MaxItemI = 0;
    int sum = 0;
    int mul = 1;
   

    Create(a, n, Min, Max, 0);
    cout << "Before:"; Print(a, n, 0);

   
    Sum(a, n, MaxItemI, sum, 0);

    int* inLimit = new int[n];
    int* outLimit = new int[n];
   

    cout << "After:  ";
    for (int i = n - 1; i >= 0; i--)
        cout << a[i] << " ";
    cout << " " << endl;
    cout << "Sum : " << sum << endl;
    cout << "MaxItemPos : " << MaxItemI+1 << endl;
   

    Mult(a, n, mul, 0);
    cout << "mult: " << setw(4) << mul << endl;

    delete[] a;
    delete[] inLimit;
    delete[] outLimit;
}



void Create(int*& a, const int size, int Min, int Max, int i)
{
    if (i == 0)
        a = new int[size]; // виділили пам'ять
    if (i < size)
    {
        a[i] = (Max - Min) * rand() / RAND_MAX + Min;
        return Create(a, size, Min, Max, ++i);
    }
}


void Sum(int* list, const int size, int& indexMax, int& sum, int i)
{
    
    for (int i = 0; i < size; i++)
        if ((list[i]) > (list[indexMax]))
            indexMax++;

  
    while (i < indexMax) {
        if (list[i] > 0) {
            sum+= list[i];
            i++;
        }

        return Sum(list, size, indexMax, sum, ++i);
    }
}



void Mult(int* list, const int size, int& mul, int i) {
    if (i < size) {
        if (list[i]<0) {
            mul*= list[i];
           i++ ;
        }

        Mult(list, size, mul, ++i);
    }
}

void Print(int* list, const int size, int i)
{
    if (i < size) {
        cout << setw(4) << list[i];
        return Print(list, size, ++i);
    }
    cout << endl;
}