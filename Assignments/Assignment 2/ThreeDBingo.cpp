#include "ThreeDBingoBoard.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;


// Should return true if the indices i, j and k correspond to the 
// centre square and false otherwise.
bool CentreSquare(int i, int j, int k)
{
	return (i == 2 && j == 2 && k == 2);
}

void AllocateBoard(vector<vector<vector<ThreeDBingoSquare>>>& board)
{
	for (int i = 0; i < BOARD_DIM; i++)
	{
		vector<vector<ThreeDBingoSquare>> twoDBoard;
		for (int j = 0; j < BOARD_DIM; j++)
		{
			vector<ThreeDBingoSquare> BoardRow;	
			for (int k = 0; k < BOARD_DIM; k++)
			{
				ThreeDBingoSquare tempsquare;	
				tempsquare.number = -1;
				tempsquare.covered = false;
				BoardRow.push_back(tempsquare);
			}
			twoDBoard.push_back(BoardRow);
		}
		board.push_back(twoDBoard);
	}
}

void PrintBoard(const ThreeDBingoBoard board)
{
	for (int i = 0; i < BOARD_DIM; i++)
	{
		for (int j = 0; j < BOARD_DIM; j++)
		{
			for (int k = 0; k < BOARD_DIM; k++)
			{
				if (board[i][j][k].covered)
				{
					cout << "X" << " ";
				}
				else
				{
					cout << board[i][j][k].number << " ";
				}
			}
			cout << endl;
		}	
		if (i != BOARD_DIM-1)
		{
			cout << endl;
		}
	}		
}

void ReadBoard(ThreeDBingoBoard& board)
{
	AllocateBoard(board);
	for (int i = 0; i < BOARD_DIM; i++)
	{
		for (int j = 0; j < BOARD_DIM; j++)
		{
			for (int k = 0; k < BOARD_DIM; k++)
			{
				int temp;
				cin >> temp;
				board[i][j][k].number = temp;
				if (CentreSquare(i, j, k))
				{
					board[i][j][k].covered = true;
				}
				else
				{
					board[i][j][k].covered = false;	
				}	
			}
		}
	}
}


// Should return true if all board numbers are valid (according to usual Bingo rules)
// on the 3D Bingo board and false otherwise
bool BoardNumbersValid(const ThreeDBingoBoard board)
{
	for (int i = 0; i < BOARD_DIM; i++)
	{
		for (int j = 0; j < BOARD_DIM; j++)
		{
			for (int k = 0; k < BOARD_DIM; k++)
			{
				int number = board[i][j][k].number;

				if (CentreSquare(i, j, k))
				{
					if (number != 0) return false;
					continue;
				}

				if (number < 1 || number > 75) return false;

				if (k == 0 && (number < 1 || number > 15)) return false;
				if (k == 1 && (number < 16 || number > 30)) return false;
				if (k == 2 && (number < 31 || number > 45)) return false;
				if (k == 3 && (number < 46 || number > 60)) return false;
				if (k == 4 && (number < 61 || number > 75)) return false;
			}
		}
	}

	return true;
}

bool IsWinningBoard(const ThreeDBingoBoard board)
{
	// Check rows on each Bingo board
	bool coveredrow;
	for (int i = 0; i < BOARD_DIM; i++)
	{
		for (int j = 0; j < BOARD_DIM; j++)
		{
			coveredrow = true;
			for (int k = 0; k < BOARD_DIM; k++)
			{
				if (!board[i][j][k].covered)	
				{
					coveredrow = false;
				}
			}
			if (coveredrow)
			{
				return true;
			}
		}
	}

	// Check columns on each level of the ThreeD board
	for (int i = 0; i < BOARD_DIM; i++)
	{
		for (int k = 0; k < BOARD_DIM; k++)
		{
			bool coveredhcol = true;
			for (int j = 0; j < BOARD_DIM; j++) 
			{
				if (!board[i][j][k].covered)
				{
					coveredhcol = false;
				}	
			}
			if (coveredhcol)
			{
				return true;
			}
		}
	}


	// Check diagonals and antidiagonals on each level of the 3D board
        for (int i = 0; i < BOARD_DIM; i++)
        {
                bool covereddiag = true, coveredantidiag = true;
                for (int j = 0; j < BOARD_DIM; j++)
                {
                        if (!board[i][j][j].covered)
                        {
                                covereddiag = false;
                        }
                        if (!board[i][j][4-j].covered) 
                        {
                                coveredantidiag = false;
                        }       
                }               
                if (covereddiag || coveredantidiag) return true;
        }       

	// Check columns along height dimension
	for (int j = 0; j < BOARD_DIM; j++)
	{
		for (int k = 0; k < BOARD_DIM; k++)
		{
			bool coveredvcol = true;
			for (int i = 0; i < BOARD_DIM; i++)	
			{
				if (!board[i][j][k].covered)
				{
					coveredvcol = false;
					break;
				}
			}
			if (coveredvcol)
			{
				return true;
			}
		}
	}

	// Check main diagonal and antidiagonal of ThreeDBingoBoard

	bool covereddiag1 = true;
	bool covereddiag2 = true;
	bool covereddiag3 = true;
	bool covereddiag4 = true;
	for (int i = 0 ; i < BOARD_DIM; i++)
	{
		if (!board[i][i][i].covered)
		{
			covereddiag1 = false;
		}
		if (!board[i][i][4-i].covered)
		{
			covereddiag2 = false;	
		}	
		if (!board[i][4-i][i].covered)
		{
			covereddiag3 = false;	
		}	
		if (!board[i][4-i][4-i].covered)
		{
			covereddiag4 = false;	
		}
	}
	if (covereddiag1 || covereddiag2 || covereddiag3 || covereddiag4) return true;

	return false;
}

void CallNumber(ThreeDBingoBoard& board, int callednumber)
{
	for (int i = 0; i < BOARD_DIM; i++)
	{
		for (int j = 0; j < BOARD_DIM; j++)
		{
			for (int k = 0; k < BOARD_DIM; k++)
			{
				if (board[i][j][k].number == callednumber){
					
					board[i][j][k].covered = true;
				}
			}
		}
	}
}

int main()
{
	srand(static_cast <unsigned int> (time(0)));
	ThreeDBingoBoard threeDBoard;
	try
	{
		ReadBoard(threeDBoard);
 		if (!BoardNumbersValid(threeDBoard))
		{
			throw runtime_error("Invalid board input!");
		} 
	}
	catch (exception& e)
	{
		cout << "Exiting program - Exception: " << e.what() << endl;
		exit(1);
	}

	while (!IsWinningBoard(threeDBoard))
	{
		PrintBoard(threeDBoard);
		short callednumber;	
		cin >> callednumber;
		cout << callednumber << endl;
		CallNumber(threeDBoard, callednumber);
	} 
	PrintBoard(threeDBoard); 
	cout << "3D BINGO!" << endl;
}
