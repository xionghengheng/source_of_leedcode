/*思路：二分查找的升级版。是剑指offer的一道原题，书中用的递归实现，我这里是循环实现。
上界的确定即找到的值和target相等且它的前一个不和target相等，那么该值就是上界。*/
class Solution {
public:
    int findlow(int A[],int n,int target){
        int mid=0;
        int start=0;
        int end=n-1;
        while(start<=end){
            mid=(start+end)/2;
            if(A[mid]<target) start=mid+1;
            else if(A[mid]>target) end=mid-1;
            else{
                if(mid==0||(mid>0&&A[mid]==target&&A[mid-1]!=target))
                    return mid;
                else end=mid-1;
            }
        }
        return -1;
    }
    int findhigh(int A[],int n,int target){
        int mid;
        int start=0;
        int end=n-1;
        while(start<=end){
            mid=(start+end)/2;
            if(A[mid]<target) start=mid+1;
            else if(A[mid]>target) end=mid-1;
            else{
                if(mid==n-1||(mid<n-1&&A[mid]==target&&A[mid+1]!=target))
                    return mid;
                else start=start+1;
            }
        }
        return -1;
    }
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;
        if(n==0) return result;
        int l=findlow(A,n,target);
        int h=findhigh(A,n,target);
        result.push_back(l);
        result.push_back(h);
        return result;
    }
};
