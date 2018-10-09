#include <iostream>
#include <fstream>
#include <string>
#include <queue>

void find_peak(std::ofstream & output_file, const int & row , const int & column, int * matrix, const int & cur_row, int & rotating_row){
    for (int i = 0; i < column; i ++){
        bool flag = true;
        if (cur_row > 0 && matrix[((rotating_row + 2) % 3) * column + i] > matrix[rotating_row * column + i])
            flag = false;
        if (cur_row < row - 1 && matrix[((rotating_row + 1) % 3) * column + i] > matrix[rotating_row * column + i])
            flag = false;
        if (i > 0 && matrix[rotating_row * column + i - 1] > matrix[rotating_row * column + i])
            flag = false;
        if (i < column - 1 && matrix[rotating_row * column + i + 1] > matrix[rotating_row * column + i])
            flag = false;
    }
}

void read_matrix(std::ifstream & input_file, const int & column, int * matrix, const int & rotating_row){
    static bool first = true;
    if (first){
        for (int i = 0; i < 2; i ++){
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
    }
}
int main(void){
    int row, column;
    int rotating_row = 2;
    std::ifstream input_file;
    std::ofstream output_file;
    input_file.open("matrix.data");
    output_file.open("final.peak");
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
