#include <iostream>
#include <vector>

//Given an image represented by NxN matrix where each pixel is represented by an integer,
//write a function to rotate the image by 90 degrees.
//Can you do this in place?

//void rotateMatrix(std::vector<std::vector<int>> matrix)
void rotateMatrix(int** matrix, int end){
    int temp;
    int start_col = 0;
    int N = end -1;
    while(start_col < (N-start_col)){
        for(int index = start_col; index < (N-start_col); index++){
            temp = matrix[start_col][index];
            matrix[start_col][index] = matrix[N-index][start_col];
            matrix[N-index][start_col] = matrix[N-start_col][N-index];
            matrix[N-start_col][N-index] = matrix[index][N-start_col];
            matrix[index][N-start_col] = temp;
        }
        start_col++;
    }
}

void printMatrix(int** matrix, int N){
    for(int col = 0; col < N; col++){
        for(int row = 0; row < N; row++){
            std::cout << matrix[col][row] << " ";
            //std::cout << "[" << col << "][" << row << "] ";
        }
        std::cout << "" << std::endl;
    }
    std::cout << "\n" << std::endl;
}

void printMatrixIndex(int** matrix, int N){
    for(int col = 0; col < N; col++){
        for(int row = 0; row < N; row++){
            std::cout << "[" << col << "][" << row << "] ";
        }
        std::cout << "" << std::endl;
    }
    std::cout << "\n" << std::endl;
}

int main(){
    int N = 8;
    int** a = new int*[N];
        for(int i = 0; i < N; ++i){
            a[i] = new int[N];
            for(int j = 0; j < N; ++j)
                a[i][j] = j;
        }
    
    printMatrix(a, N);
    printMatrixIndex(a, N);
    rotateMatrix(a, N);
    printMatrix(a, N);

    return 0;
}