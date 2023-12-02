#include <iostream>
#include <vector>
using namespace std;

// Ham kiem tra toa do (x, y) có nam trong anh khong
bool isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

// Ham DFS
void floodFillDFS(vector<vector<int>>& image, int x, int y, int newColor, int oldColor) {
    int rows = image.size();
    int cols = image[0].size();

    if (!isValid(x, y, rows, cols) || image[x][y] != oldColor || image[x][y] == newColor) {
        return;
    }

    image[x][y] = newColor;

    floodFillDFS(image, x + 1, y, newColor, oldColor);
    floodFillDFS(image, x - 1, y, newColor, oldColor);
    floodFillDFS(image, x, y + 1, newColor, oldColor);
    floodFillDFS(image, x, y - 1, newColor, oldColor);
}

// Ham Flood Fill chinh
void floodFill(vector<vector<int>>& image, int x, int y, int newColor) {
    int oldColor = image[x][y];
    floodFillDFS(image, x, y, newColor, oldColor);
}

// Ham in anh
void printImage(const vector<vector<int>>& image) {
    for (const auto& row : image) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> image = {{1, 1, 1, 1, 0},
                                 {1, 1, 0, 1, 0},
                                 {1, 0, 0, 0, 0},
                                 {0, 1, 1, 1, 1},
                                 {0, 0, 0, 1, 1}};

    int startRow = 2, startCol = 2; // Toa do ban dau
    int newColor = 2; // Mau moi

    cout << "Before Flood Fill:" << endl;
    printImage(image);

    floodFill(image, startRow, startCol, newColor);

    cout << "\nAfter Flood Fill:" << endl;
    printImage(image);

    return 0;
}

