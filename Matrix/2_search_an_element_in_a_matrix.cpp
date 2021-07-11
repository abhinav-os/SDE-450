/*
    Time Complexity: O(log(n*m))
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

// Binary Search
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
        
    int total = n*m;
    int low = 0, high = total-1;
        
    while(low <= high) {
        int mid = (low + high)/2;
        int row = mid/m, col = mid%m;
        if(matrix[row][col] == target) 
            return true;
        else if(matrix[row][col] > target) 
            high = mid - 1;
        else 
            low = mid + 1;
    }
        
    return false;
}

/*
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int n = matrix.size(), m = matrix[0].size();

    if (n == 0) {
		return false;
	}

	int i = 0, j = m - 1;

	while(i < n && j >= 0) {
	    if (matrix[i][j] == target) {
			return true;
		} else if (target < matrix[i][j]) {
		    j -= 1;
		} else {
		    i += 1;
	    }
	}
    return false;
}
*/

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m, target;
    cin >> n >> m >> target;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    if(searchMatrix(mat, target)) {
        cout << "Present";
    } else {
        cout << "Not Present";
    }
}

/*
3 4 3
1 3 5 7
10 11 16 20
23 30 34 60
*/