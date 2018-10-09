#include <iostream>
#include <fstream>
#include <string>
int main(void){
    std::ifstream file;
    std::string output;
    file.open("example.txt");
    file >> output;
    std::cout << output << '\n';
    file.close();
    return 0;
}
