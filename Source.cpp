#include<iostream>
using namespace std;

void draw(int **&board, int rows, int cols)
{
	for (int i = 0;i < rows;i++)
	{
		for (int j = 0;j < cols;j++)
		{
			cout << (*(*(board + i) + j)) << " ";
		}
		cout << endl;
	}
	cout << endl;
}


int main()
{
	int rows, cols;
	cout << "Enter rows (odd number): ";
	cin >> rows;
	cout << "Enter columns (odd numbers): ";
	cin >> cols;
	int **board = new int*[rows];
	for (int i = 0;i < rows;i++)
	{
		*(board+i) = new int[cols];
	}

	for (int i = 0;i < rows;i++)
	{
		for (int j = 0;j < cols;j++)
		{
			(*(*(board + i) + j)) = 0;
		}
	}


	int num = 1;

	int ri = 0;
	int ci = cols / 2;
	int pri = 0;
	int pci = 0;
	// Step 1
	board[0][cols / 2] = num;
	//draw(board, rows, cols);

	// Step2

	for (num=2;num <= rows*cols;num++)
	{
		pri = ri;
		pci = ci;
		if (ri - 1 < 0)
		{
			ri = rows - 1;
		}
		else
		{
			ri--;
		}
		if (ci + 1 == cols)
		{
			ci = 0;
		}
		else
		{
			ci++;
		}
		if ((*(*(board + ri) + ci)) != 0)
		{
			ri = pri + 1;
			if (ci - 1 < 0)
			{
				ci = cols - 1;
			}
			else
			{
				ci = ci - 1;
			}
		}
		board[ri][ci] = num;
		//draw(board, rows, cols);

	}
	draw(board, rows, cols);

	//---------------
	cout << "The sum of every row, column and diagonal is: ";
	int sum = 0;
	for (int i = 0;i < rows;i++)
	{
		sum += board[i][0];
	}
	cout << sum;
	cout << endl;
	system("pause");
	return 0;
}