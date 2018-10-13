#include <iostream>
#include <fstream>
#include <string>
#include <queue>

void find_peak(std::queue<int> & result, const int & row , const int & column, int * matrix, const int & cur_row, int & rotating_row, int & count){
    int cur_matrix_row_idx = cur_row % 3;
    for (int i = 0; i < column; i ++){
        bool flag = true;
        if (cur_row > 0 && matrix[((cur_matrix_row_idx + 2) % 3) * column + i] > matrix[cur_matrix_row_idx * column + i])
            flag = false;
        else if (cur_row < row - 1 && matrix[((cur_matrix_row_idx + 1) % 3) * column + i] > matrix[cur_matrix_row_idx * column + i])
            flag = false;
        else if (i > 0 && matrix[cur_matrix_row_idx * column + i - 1] > matrix[cur_matrix_row_idx * column + i])
            flag = false;
        else if (i < column - 1 && matrix[cur_matrix_row_idx * column + i + 1] > matrix[cur_matrix_row_idx * column + i])
            flag = false;
        if (flag){
            result.push(cur_row + 1);
            result.push(i + 1);
            count = count + 1;
        }
    }
    rotating_row = (rotating_row + 1) % 3;
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
int main(int argc, char** argv) {
    int row, column;
    int rotating_row = 1;
    int count = 0;
    std::ifstream input_file;
    std::ofstream output_file;
    std::queue<int> result;
    input_file.open("./"+ std::string(argv[1]) + "/matrix.data");
    output_file.open("./"+ std::string(argv[1]) + "/final.peak");
    input_file >> row;
    input_file >> column;
    int matrix [3][column];
    for (int cur_row = 0; cur_row < row; cur_row ++){
        read_matrix(input_file, column, &matrix[0][0], rotating_row);
        find_peak(result, row, column, &matrix[0][0], cur_row, rotating_row, count);
    }
    output_file << count << '\n';
    for (int i = 0; i < count; i ++){
        output_file << result.front() << " ";
        result.pop();
        output_file << result.front() << '\n';
        result.pop();
    }
    return 0;
}
