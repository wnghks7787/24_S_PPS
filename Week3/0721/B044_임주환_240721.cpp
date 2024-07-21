class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> answer;
        vector<int> rows;

        if(r * c != mat.size() * mat[0].size())
            return mat;

        int mat_i = 0;
        int mat_j = 0;

        for(int i = 0 ; i < r ; i++)
        {
            for(int j = 0 ; j < c ; j++)
            {
                rows.push_back(mat[mat_i][mat_j]);

                mat_j++;
                if(mat_j >= mat[0].size())
                {
                    mat_i++;
                    mat_j = 0;
                }
            }
            answer.push_back(rows);
            rows.clear();
        }

        return answer;
    }
};