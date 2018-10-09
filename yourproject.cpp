#include <iostream>
#include <fstream>
#include <string>
void read_matrix(std::ifstream & input_file, const int & column, int * matrix, int & rotating_row){
    static bool first = true;
    if (first){
        for (int i = 0; i < 3; i ++){
            for (int j = 0; j < column; j ++){
                input_file >> matrix[i * column + j];
            }
        }
        first = false;
    }
    else{
        for (int i = 0; i < column; i ++){
            input_file >> matrix[rotating_row * column + i];
        }
        rotating_row = rotating_row + 1;
    }
}
int main(void){
    int row, column;
    int rotating_row = 0;
    std::ifstream input_file;
    input_file.open("matrix.data");
    input_file >> row;
    input_file >> column;
    std::cout << row << " " << column << '\n';
    int matrix [3][column];
    for (int num = 0; num < row - 2; num ++){
        read_matrix(input_file, column, &matrix[0][0], rotating_row);
        for (int i = 0; i < 3; i ++){
            for (int j = 0; j < column; j ++){
                std::cout << matrix[i][j] << " ";
            }
            std::cout << '\n';
        }
    }
    return 0;
}
