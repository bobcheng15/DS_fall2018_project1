#include <iostream>
#include <fstream>
#include <string>
void read_matrix(std::ifstream & input_file, const int & column, int * matrix){
    for (int i = 0; i < 3; i ++){
        for (int j = 0; j < column; j ++){
            input_file >> matrix[i * column + j];
        }
    }
}
int main(void){
    int row, column;
    std::ifstream input_file;
    input_file.open("matrix.data");
    input_file >> row;
    input_file >> column;
    std::cout << row << " " << column << '\n';
    int matrix [3][column];
    read_matrix(input_file, column, &matrix[0][0]);
    for (int i = 0; i < 3; i ++){
        for (int j = 0; j < column; j ++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << '\n';
    }
}
