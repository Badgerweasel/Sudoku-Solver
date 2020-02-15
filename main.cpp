/*
Sean Smith
Alvaro Zamora
 */

#include <iostream>
#include <fstream>

using namespace std;

void print(int grid[9][9]);
bool solver(int grid[9][9], int x, int y);
void initialize(int (&possible)[9]);
void verticle(int grid[9][9], int x, int (&possible)[9]);
void horizontal(int grid[9][9], int y, int (&possible)[9]);
void box(int grid[9][9], int x, int y, int (&possible)[9]);

int main(){
  string sudoku;
  ifstream file;
  int grid[9][9];
  
  cout << "Enter filename of sudoku puzzle: ";
  cin >> sudoku;

  file.open(sudoku);
  if(!file.is_open()){
    cout << "Error, could not open " << sudoku << endl;
    return -1;
  }

  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      file >> grid[i][j];
    }
  }
  solver(grid, 0, 0);
  print(grid);
  
  return 0;
}

bool solver(int grid[9][9], int x, int y){

  for(int i = y; i < 9; i++){

    for(int j = 0; j < 9; j++){

      if(grid[i][j] == 0){
	int possible[9];
	initialize(possible);
	verticle(grid, j, possible);
	horizontal(grid, i, possible);
	box(grid, j, i, possible);

	for(int b = 0; b < 9; b++){
	    if(possible[b] != 0){
	      grid[i][j] = possible[b];
	      if(solver(grid, 0, 0)){
		return true;
	      }
	      else
	      {
		grid[i][j] = 0;
	      }
	    }
	}
	if(grid[i][j] == 0){
	  return false;
	}
	
      }
    }
  }

  return true;
}

void initialize(int (&possible)[9]){
  for(int i = 0; i < 9; i++){
    possible[i] = i + 1;
  }
}

void verticle(int grid[9][9], int x, int (&possible)[9]){
  for(int i = 0; i < 9; i++){
    if(grid[i][x] != 0){
      possible[grid[i][x] - 1] = 0;
    }
  }
}

void horizontal(int grid[9][9], int y, int (&possible)[9]){

  for(int i = 0; i < 9; i++){
    if(grid[y][i] != 0){
      possible[grid[y][i] - 1] = 0;
    }
  }

}

void box(int grid[9][9], int x, int y, int (&possible)[9]){
  x -= x % 3;
  y -= y % 3;

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(grid[y + j][x + i] != 0){
	possible[grid[y + j][x + i] - 1] = 0;
      }
    }
  }
}

void print(int grid[9][9]){

  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}
