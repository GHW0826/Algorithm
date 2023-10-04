class Solution {
public:

    void dfs(int index, vector<vector<int>>& rooms, vector<bool>& visit) {

        visit[index] = true;
        for (int i = 0; i < rooms[index].size(); ++i) {
            if (visit[rooms[index][i]] == false)
                dfs(rooms[index][i], rooms, visit);    
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visit(rooms.size(), false);
        dfs(0, rooms, visit);

        bool answer = std::all_of(visit.begin(), visit.end(), [](bool item) { return item == true; });
        return answer;
    }
};
