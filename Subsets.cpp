/*组合问题。
举例说明一下用递归实现组合的思想：
从源数组选取三个构成组合，S=(1,2,3,4,5)==>D=（[_],[_],[_]）
1.当我们固定了D第一个位置之后，接下来的问题即从（2，3，4，5）这个数组中选取2个。
2.进一步，当我们固定了D的第二个位置之后，接下来的问题即事从（3，4，5）这个数组中选取1个。
可以看到问题被一步步子问题化，明显的递归思想的体现。
函数tra参数列表中的start和dep的含义也就清晰了。
start：每个子问题中，新数组的起始位置。
dep：D中已填入的数字的个数。
*/

class Solution {
private:
	vector<vector<int>> res;
	vector<int> s;
public:
	void tra(int k,int start,int dep,vector<int> temp)
	{
		if(dep==k){
			res.push_back(temp);
			return;
		}
		for(int i=start;i<s.size();++i){
			temp.push_back(s[i]);
			tra(k,i+1,dep+1,temp);
			temp.erase(temp.end()-1);
		}
	}
	vector<vector<int>> subsets(vector<int> &S) {
		s=S;
		sort(s.begin(),s.end());
		vector<int> temp;
		for(int k=0;k<=s.size();++k){
			tra(k,0,0,temp);
		}
		return res;
	}
};