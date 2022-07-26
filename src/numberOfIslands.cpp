#include <iostream>
#include <stack>
#include <utility>
#include <vector>

class Solution {
  bool isValid(int row, int col, int ROW, int COL) {
    // return true if row number and column number
    // is in range
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
  }

  void dfs(int j, int i, std::vector<std::vector<char>> &matrix,
           std::vector<std::vector<bool>> &visited) {
    std::stack<std::pair<int, int>> stack;
    stack.push(std::make_pair(j, i));
    int rowNum[] = {-1, 0, 0, 1};
    int colNum[] = {0, -1, 1, 0};
    while (!stack.empty()) {
      // requires C++ 17
      // const auto [pj, py] = stack.top();
      const auto pair = stack.top();
      const auto pj = pair.first;
      const auto py = pair.second;
      // printf("Setting visited %d, %d\n", pj, py);
      visited[pj][py] = true;
      stack.pop();
      for (int x = 0; x < 4; x++) {
        int row = pj + rowNum[x];
        int col = py + colNum[x];
        if (isValid(row, col, matrix.size(), matrix[0].size()) &&
            matrix[row][col] == '1' && visited[row][col] == false) {
          stack.push(std::make_pair(row, col));
        }
      }
    }
  }

public:
  int numIslands(std::vector<std::vector<char>> &matrix) {
    const auto rows = matrix.size();
    const auto col = matrix[0].size();
    int number_islands = 0;
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(col, false));
    for (int j = 0; j < rows; j++) {
      for (int i = 0; i < col; i++) {
        if (matrix[j][i] == '1' && visited[j][i] == false) {
          number_islands++;
          dfs(j, i, matrix, visited);
        }
      }
    }
    return number_islands;
  }
};

int main() {
  std::vector<std::vector<char>> matrix = {
      {'0', '1', '0', '1', '0'}, 
      {'0', '0', '1', '1', '1'},
      {'1', '0', '0', '1', '0'}, 
      {'0', '1', '1', '0', '0'},
      {'1', '0', '1', '0', '1'},
  };

  // Just one island
  std::vector<std::vector<char>> matrix2 = {
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
       '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
       '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
       '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
       '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
       '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
       '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
       '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
       '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
       '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
       '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
       '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
       '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
       '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
       '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
       '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
       '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
       '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
       '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
       '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
       '1', '1', '1', '1', '1', '1', '1'}};
  Solution solution;
  std::cout << solution.numIslands(matrix) << '\n';
  std::cout << solution.numIslands(matrix2) << '\n';
  return 0;
}
