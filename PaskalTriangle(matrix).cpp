#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int binomialDegree = 0;

	cout << "Enter binomial degree: ";
	cin >> binomialDegree;

	if (binomialDegree < 0)
	{
		binomialDegree = fabs(binomialDegree);

		cout << "Entered value is negative. Absolute value of ENTERED VALUE is taken...\n";
	}

	//-----Creating dynamic matrix------

	long long **paskalTriangle_Matrix = new long long*[binomialDegree + 1];

	for (int i = 0; i <= binomialDegree; i++)
	{
		paskalTriangle_Matrix[i] = new long long[binomialDegree + 1]();
	}

	//-----Fill matrix according to logic------

	paskalTriangle_Matrix[0][0] = 1;

	for (int rowIndex = 1; rowIndex <= binomialDegree; rowIndex++)
	{
		for (int elemIndex = 0; elemIndex <= binomialDegree; elemIndex++)
		{
			if (elemIndex == 0) paskalTriangle_Matrix[rowIndex][elemIndex] = 1;
			else
			{
				paskalTriangle_Matrix[rowIndex][elemIndex] = paskalTriangle_Matrix[rowIndex - 1][elemIndex - 1] + paskalTriangle_Matrix[rowIndex - 1][elemIndex];
			}
		}
	}

	//-----Output matrix------

	for (int rowIndex = 0; rowIndex <= binomialDegree; rowIndex++) 
	{
		for (int elemIndex = 0; elemIndex <= binomialDegree; elemIndex++)
		{
			if(paskalTriangle_Matrix[rowIndex][elemIndex]) cout << paskalTriangle_Matrix[rowIndex][elemIndex] << " ";
		}

		cout << endl;
	}

	//-----Deleting matrix------

	for (int i = 0; i <= binomialDegree; i++) delete[] paskalTriangle_Matrix[i];

	delete[] paskalTriangle_Matrix;

	return 0;
}
