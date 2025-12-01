#include <vector>
#define BOARD_DIM 5

using namespace std;

typedef struct
{
  short number; // 0 if free square, otherwise the number on the square
  bool covered; 
} ThreeDBingoSquare;

typedef vector<vector<vector<ThreeDBingoSquare>>> ThreeDBingoBoard;
