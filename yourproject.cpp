#include <iostream>
#include <fstream>
#include <string>
void read_matrix(std::ifstream & input_file, const int & column, int * matrix){
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
        for (int i = 0; i < 2; i ++){
            for (int j = 0; j < column; j ++){
                matrix[i * column + j] = matrix[(i + 1) * column + j];
            }
        }
        for (int i = 0; i < column; i ++){
            input_file >> matrix[2 * column + i];
        }
    }
}
int main(void){
    int row, column;
    std::ifstream input_file;
    input_file.open("matrix.data");
    input_file >> row;
    input_file >> column;
    int matrix [3][column];
    for (int num = 0; num < row - 2; num ++){
        read_matrix(input_file, column, &matrix[0][0]);
        for (int i = 0; i < 3; i ++){
            for (int j = 0; j < column; j ++){
                std::cout << matrix[i][j] << " ";
            }
            std::cout << '\n';
        }
    }
    return 0;
}
