#include <iostream>
#include <fstream>
using namespace std;
const int Cmax = 100;
void Skaityti(int A[], int &n);
void Isvedimas(int A[], int n);
void Salinti(int A[], int&n, int kuris);
void VienodosReiksmes(int A[], int &n);
int main()
{
	int A[Cmax], n, kuris;
	Skaityti(A, n);
	Isvedimas(A, n);
	Vienodos(A, n);
	return 0;
}
void Skaityti(int A[], int &n)
{
	ifstream fd("Duomenys.txt");
	fd >> n;
	for (int i = 0; i < n; i++)
	{
		fd >> A[i];
	}
	fd.close();
}
void Isvedimas(int A[], int n)
{
	ofstream rf("Rezultatai.txt");
	for (int i = 0; i < n; i++)
	{
		rf << A[i] <<" ";
	}
	rf.close();
}
void Vienodos(int A[], int &n)
{
	int kuris = 0;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (A[i] == A[j])
			{
				kuris = i;
				Salinti(A, n, kuris);
			}
		}	
	}
}
void Salinti(int A[], int&n, int kuris)
{
	for (int k = kuris; k< n-1; k++)
	{
		A[k] = A[k + 1];
		n--;
	}
}
