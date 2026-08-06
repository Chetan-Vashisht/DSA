#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
===============================================================================
             RECURSION MODULE 3: ADVANCED BACKTRACKING & PERMUTATIONS
===============================================================================
What is Backtracking?
Backtracking is an algorithmic technique for solving problems incrementally 
by building a candidate solution, and abandoning (backtracking) a candidate 
as soon as it is determined that the candidate cannot lead to a valid solution.

Key Backtracking Steps:
1. Make a Choice (Do work / update state)
2. Explore (Recursive call)
3. Undo the Choice (Backtrack / restore state)
===============================================================================
*/

// ============================================================================
// 1. PERMUTATIONS OF AN ARRAY / STRING (TWO APPROACHES)
// ============================================================================

// Approach A: Map / Visited Array Approach
// Time Complexity:  O(N! * N)
// Space Complexity: O(N) auxiliary space + O(N) map
void permuteVisited(vector<int>& nums, vector<int>& current, vector<bool>& visited, vector<vector<int>>& result) {
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            current.push_back(nums[i]);
            
            // Recurse
            permuteVisited(nums, current, visited, result);
            
            // Backtrack state
            current.pop_back();
            visited[i] = false;
        }
    }
}

// Approach B: In-place Swapping Approach (Optimal Space)
// Time Complexity:  O(N! * N)
// Space Complexity: O(N) recursion stack (No extra visited array required)
void permuteSwap(int index, vector<int>& nums, vector<vector<int>>& result) {
    if (index == nums.size()) {
        result.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);       // Choice
        permuteSwap(index + 1, nums, result); // Explore
        swap(nums[index], nums[i]);       // Backtrack
    }
}


// ============================================================================
// 2. N-QUEENS PROBLEM (OPTIMIZED WITH DIAGONAL HASHING)
// ============================================================================
// Place N chess queens on an N x N chessboard so that no two queens attack each other.
// Optimization: Use hash arrays for Columns, Left Diagonals, and Right Diagonals for O(1) checks.
void solveNQueens(int col, int n, vector<string>& board, vector<vector<string>>& solutions,
                 vector<bool>& leftRow, vector<bool>& lowerDiagonal, vector<bool>& upperDiagonal) {
    // Base Case: All columns filled safely
    if (col == n) {
        solutions.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        // O(1) safety check using diagonal hash formulas
        if (!leftRow[row] && !lowerDiagonal[row + col] && !upperDiagonal[n - 1 + col - row]) {
            // Place Queen
            board[row][col] = 'Q';
            leftRow[row] = true;
            lowerDiagonal[row + col] = true;
            upperDiagonal[n - 1 + col - row] = true;

            // Recurse for next column
            solveNQueens(col + 1, n, board, solutions, leftRow, lowerDiagonal, upperDiagonal);

            // Backtrack state
            board[row][col] = '.';
            leftRow[row] = false;
            lowerDiagonal[row + col] = false;
            upperDiagonal[n - 1 + col - row] = false;
        }
    }
}


// ============================================================================
// 3. RAT IN A MAZE (4-DIRECTIONAL GRID SEARCH)
// ============================================================================
// Given N x N matrix (1 = Open, 0 = Blocked). Rat starts at (0,0) and needs to reach (N-1, N-1).
// Moves allowed: Down ('D'), Left ('L'), Right ('R'), Up ('U').
void solveRatInMaze(int r, int c, int n, vector<vector<int>>& maze, string& currentPath,
                    vector<string>& allPaths, vector<vector<bool>>& visited) {
    // Base Case: Destination reached
    if (r == n - 1 && c == n - 1) {
        allPaths.push_back(currentPath);
        return;
    }

    // Direction vectors for lexicographical ordering: D, L, R, U
    string dir = "DLRU";
    int dr[] = {1, 0, 0, -1};
    int dc[] = {0, -1, 1, 0};

    visited[r][c] = true;

    for (int i = 0; i < 4; i++) {
        int nextR = r + dr[i];
        int nextC = c + dc[i];

        // Validity check
        if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < n &&
            !visited[nextR][nextC] && maze[nextR][nextC] == 1) {

            currentPath.push_back(dir[i]);
            solveRatInMaze(nextR, nextC, n, maze, currentPath, allPaths, visited);
            currentPath.pop_back(); // Backtrack path string
        }
    }

    visited[r][c] = false; // Backtrack visited state
}


// ============================================================================
// 4. GENERATE BALANCED PARENTHESES
// ============================================================================
// Given N pairs of parentheses, generate all combinations of well-formed parentheses.
// Rules:
// 1. Can add '(' if openCount < N
// 2. Can add ')' if closeCount < openCount
void generateParentheses(int openCount, int closeCount, int n, string& current, vector<string>& result) {
    // Base Case: Length reached 2 * N
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }

    if (openCount < n) {
        current.push_back('(');
        generateParentheses(openCount + 1, closeCount, n, current, result);
        current.pop_back(); // Backtrack
    }

    if (closeCount < openCount) {
        current.push_back(')');
        generateParentheses(openCount, closeCount + 1, n, current, result);
        current.pop_back(); // Backtrack
    }
}


// ============================================================================
// 5. SUDOKU SOLVER
// ============================================================================
// Validates if placing digit val at grid[row][col] is valid
bool isValidSudokuPlacement(const vector<vector<char>>& board, int row, int col, char val) {
    for (int i = 0; i < 9; i++) {
        // Check row
        if (board[row][i] == val) return false;
        // Check column
        if (board[i][col] == val) return false;
        // Check 3x3 subgrid
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) return false;
    }
    return true;
}

bool solveSudoku(vector<vector<char>>& board) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == '.') {
                for (char val = '1'; val <= '9'; val++) {
                    if (isValidSudokuPlacement(board, r, c, val)) {
                        board[r][c] = val; // Choice

                        if (solveSudoku(board)) return true; // Explore

                        board[r][c] = '.'; // Backtrack
                    }
                }
                return false; // Couldn't place any digit
            }
        }
    }
    return true; // All cells filled
}


// ============================================================================
// MAIN FUNCTION - DEMONSTRATIONS & TESTS
// ============================================================================
int main() {
    cout << "====================================================\n";
    cout << "   DSA RECURSION MODULE 3: ADVANCED BACKTRACKING    \n";
    cout << "====================================================\n\n";

    // 1. Permutations
    cout << "--- 1. Permutations of an Array ---\n";
    vector<int> nums = {1, 2, 3};

    // Visited approach
    vector<int> currPerm;
    vector<bool> visited(nums.size(), false);
    vector<vector<int>> permRes1;
    permuteVisited(nums, currPerm, visited, permRes1);
    cout << "Permutations using Visited Array (" << permRes1.size() << " total):\n";
    for (const auto& p : permRes1) {
        cout << "[ ";
        for (int x : p) cout << x << " ";
        cout << "] ";
    }
    cout << "\n\n";

    // In-place Swap approach
    vector<vector<int>> permRes2;
    permuteSwap(0, nums, permRes2);
    cout << "Permutations using In-Place Swapping:\n";
    for (const auto& p : permRes2) {
        cout << "[ ";
        for (int x : p) cout << x << " ";
        cout << "] ";
    }
    cout << "\n\n";

    // 2. N-Queens Problem
    cout << "--- 2. N-Queens Problem (N = 4) ---\n";
    int nQueens = 4;
    vector<string> board(nQueens, string(nQueens, '.'));
    vector<vector<string>> queenSolutions;
    vector<bool> leftRow(nQueens, false);
    vector<bool> lowerDiag(2 * nQueens - 1, false);
    vector<bool> upperDiag(2 * nQueens - 1, false);

    solveNQueens(0, nQueens, board, queenSolutions, leftRow, lowerDiag, upperDiag);
    cout << "Found " << queenSolutions.size() << " valid configurations for 4-Queens:\n";
    for (int i = 0; i < queenSolutions.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for (const string& rowStr : queenSolutions[i]) {
            cout << "  " << rowStr << "\n";
        }
        cout << "\n";
    }

    // 3. Rat in a Maze
    cout << "--- 3. Rat in a Maze ---\n";
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int mazeN = maze.size();
    string path = "";
    vector<string> allPaths;
    vector<vector<bool>> visitedCells(mazeN, vector<bool>(mazeN, false));

    if (maze[0][0] == 1) {
        solveRatInMaze(0, 0, mazeN, maze, path, allPaths, visitedCells);
    }
    cout << "Paths to reach destination (0,0) to (" << mazeN - 1 << "," << mazeN - 1 << "):\n";
    for (const string& p : allPaths) {
        cout << p << " ";
    }
    cout << "\n\n";

    // 4. Generate Parentheses
    cout << "--- 4. Generate Parentheses (N = 3) ---\n";
    int parenN = 3;
    string parenCurr = "";
    vector<string> parenResult;
    generateParentheses(0, 0, parenN, parenCurr, parenResult);
    cout << "All balanced parentheses for N = " << parenN << " (" << parenResult.size() << " total):\n";
    for (const string& s : parenResult) {
        cout << s << " ";
    }
    cout << "\n\n";

    // 5. Sudoku Solver
    cout << "--- 5. Sudoku Solver ---\n";
    vector<vector<char>> sudokuBoard = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    if (solveSudoku(sudokuBoard)) {
        cout << "Sudoku Solved Successfully:\n";
        for (int r = 0; r < 9; r++) {
            if (r % 3 == 0 && r != 0) cout << "------+-------+------\n";
            for (int c = 0; c < 9; c++) {
                if (c % 3 == 0 && c != 0) cout << "| ";
                cout << sudokuBoard[r][c] << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "No solution exists for the given Sudoku.\n";
    }

    cout << "\n====================================================\n";
    return 0;
}
