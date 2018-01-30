#include <iostream>
#include <vector>

using namespace std;

bool is_valid_pos (vector<vector<int> > &board, int i, int j, int n)
{
	for (int k = 0; k < n; k++)
		if (board[k][j] == 1)
			return false;

	int x = i;
	int y = j;

	while (x>=0 && y>=0)
	{
		if (board[x][y])
			return false;
		x--; y--;
	}

	x = i;
	y = j;

	while (x>=0 && y<n)
	{
		if (board[x][y])
			return false;
		x--; y++;
	}

	return true;
}

bool n_queen_util (vector<vector<int> > &board, int i, int n)
{
	if (i == n)
		return true;

	for (int j = 0; j < n; j++)
	{
		if (is_valid_pos (board, i, j, n))
		{
			board[i][j] = 1;
			if (n_queen_util (board, i+1, n))
				return true;
			board[i][j] = 0;
		}
	}
	return false;
}

void n_queen (int n)
{
	vector<vector<int> > board (n);
	for (int i = 0; i < n; i++)
		board[i].resize(n);

	n_queen_util (board, 0, n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << board[i][j] << " ";
		cout << endl;
	}
}