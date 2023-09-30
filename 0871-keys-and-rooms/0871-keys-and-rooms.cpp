class Solution {
public:
   void helper(vector<vector<int>> &rooms, vector<bool> &flag, int row, int col) {
    if (flag[row] == 1)
        return ;

    flag[row] = 1;
    for (int i = 0; i < rooms[row].size(); i++) {
        if (rooms[row][i] != row)
            helper(rooms, flag, rooms[row][i], 0);
    }
}

bool canVisitAllRooms(vector<vector<int>> &rooms) {
    if (rooms.size() == 1) {
        return true;
    }
    int n = rooms.size();
    vector<bool> flag(n, 0);
    helper(rooms, flag, 0, 0);
    for (auto x: flag) {
        if (x == 0)
            return 0;
    }
    return 1;
}
};