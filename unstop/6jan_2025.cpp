#include <bits/stdc++.h>
using namespace std;
int res=0;
int func(int n, vector<vector<vector<int>>>& dp, vector<int> balls, int i, int j, int fl) {
    if (i > j) {
        return 0;
    }
    if (dp[i][j][fl] != -1) {
        return dp[i][j][fl];
    }

    int left = 0, right = 0;
    if (fl == 0) { // Player's turn: maximize the score
        left = balls[i] + func(n, dp, balls, i + 1, j, 1 - fl);
        right = balls[j] + func(n, dp, balls, i, j - 1, 1 - fl);
        dp[i][j][fl] = max(left, right);
    } else { // Opponent's turn: minimize the score
        left = func(n, dp, balls, i + 1, j, 1 - fl);
        right = func(n, dp, balls, i, j - 1, 1 - fl);
        dp[i][j][fl] = min(left, right);
    }

    return dp[i][j][fl];
}

std::string determine_winner(int n, const std::vector<int>& balls) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    int sum = accumulate(balls.begin(), balls.end(), 0);
    res = func(n, dp, balls, 0, n - 1, 0); // Start with the player's turn (fl = 0)

    if (res >= (sum - res)) {
        return "Aryan";
    }
    return "Ankit";
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> balls(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> balls[i];
    }

    std::string result = determine_winner(n, balls);
    std::cout << result << std::endl;
    return 0;
}
