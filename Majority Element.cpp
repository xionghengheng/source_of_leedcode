//法1：用map记录每个数字出现的次数，时间复杂度和空间复杂度O(n)，没有利用数组的结构特性
class Solution {
public:
	int majorityElement(vector<int> &num) {
		map<int,int> m;
		for(int i=0;i<num.size();++i){
			++m[num[i]];
		}
        int p;
        if(num.size()%2==0)
            p=num.size()/2;
        else
            p=num.size()/2+1;
		map<int,int>::iterator it=m.begin();
		for(it;it!=m.end();++it){
			if(it->second>=p){
				return it->first;
			}
		}
	}
};

/*法2：由于数组中有一个数字出现的次数大于数组长度的一半，所以两两抵消不同的数字，最终剩下的即为解。
candidate:候选数字*/
class Solution {
public:
	int majorityElement(vector<int> &num) {
		int ntimes=1;
		int candidate=num[0];
		for(int i=1;i<num.size();++i){
			if(num[i]!=candidate){
				--ntimes;
				if((i!=num.size()-1)&&ntimes==0){
					candidate=num[i+1];
					++ntimes;
					++i;
				}
			}else{
				++ntimes;
			}
		}
		return candidate;
	}
};
