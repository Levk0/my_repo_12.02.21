#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>

using namespace std;

class TwoDimensionalArray
    {
private:
	vector <vector <double> > a;
	int VectorSize;

	double CalculateAverage (int row)
	{
		double res = 1;
		    for (int i = row + 1; i < VectorSize; i++)
			    res *= a [i] [row];
		        return pow (res, 1.0 / (VectorSize - row - 1));
	}

	void BubbleSort (vector <double>& m)
	{
		for (int j = 0; j < VectorSize - 1; j++)
			for (int i = 0; i < VectorSize - j - 1; i++)
				if (m[i] < m[i + 1])
					swap (m [i], m [i + 1]);
	}

public:
	TwoDimensionalArray(int size)
	{
		this->VectorSize = VectorSize;
		a = vector <vector <double> >(size);
		for (int i = 0; i < VectorSize; i++)
			a[i] = vector <double> (size);
	}

	void ReadFromKeyboard()
	{
		for (int i = 0; i < VectorSize; i++)
			for (int c = 0; c < VectorSize; c++)
				cin >> a [c][i];
	}

	void SortColumns()
	{
		for (int column = 0; column < VectorSize; column++)
			BubbleSort (a [column]);
	}

	void print()
	{
		for (int i = 0; i < VectorSize; i++)
		{
			for (int c = 0; c < VectorSize; c++)
				cout << a[c][i] << " ";
			cout << endl;
		}
	}

	void CalculateAndPrint()
	{
		double f, F = 1;
		for (int i = 0; i < VectorSize - 1; i++)
		{
			f = CalculateAverage(i);
			cout << f << " ";
			F += f;
		}

		cout << endl << F << endl;;
	}
};

int main()
{
	int size;
	cin >> size;

	    TwoDimensionalArray m(size);
	    m.ReadFromKeyboard();
	    m.SortColumns();

	        cout << endl << "Sorted matrix: " << endl;
	        m.print();

	            cout << endl;
	            m.CalculateAndPrint();
}
