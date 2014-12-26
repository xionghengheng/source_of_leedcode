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
