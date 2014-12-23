//二维数组的旋转
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        vector<int> temp;
        vector<vector<int> > res;
        int row=matrix.size()-1;
        int col=row;
        for(int j=0;j<=col;++j){
            temp.clear();
            for(int i=row;i>=0;--i){
                temp.push_back(matrix[i][j]);
            }
            res.push_back(temp);
        }
        matrix.clear();
        for(int i=0;i<=row;++i){
              matrix.push_back(res[i]);
          }
    }
};