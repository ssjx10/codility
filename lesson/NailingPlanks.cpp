#include <algorithm>
bool nailCheck( int k, vector<int> &A, vector<int> &B, vector<int> &C); 

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    int u_bnd = C.size();
    int l_bnd = 1; 
    int result =-1; 
    int mid=0;
    while(l_bnd<=u_bnd)
    {
        mid = (u_bnd+l_bnd)/2;
        if(nailCheck(mid,A,B,C))
        {
            u_bnd=mid-1;
            result = mid; 
        } else
            l_bnd=mid+1;
    }
    return result; 
}

bool nailCheck(int k,vector<int> &A, vector<int> &B, vector<int> &C)
{
    std::vector<int> used_nails (C.begin(),C.begin()+k); 
    sort(used_nails.begin(),used_nails.end()); 
    // binary search again for fitted nail
    for(int j = 0; j < A.size();j++)
    {
        int max_idx = used_nails.size()-1; 
        int min_idx = 0;
        bool found = false; 
        int mid = 0;
        while (min_idx <= max_idx)
        {
            mid = (max_idx+min_idx)/2; 
            if (used_nails[mid] >= A[j] && used_nails[mid] <= B[j]) // fit 
            { 
                found = true;
                break;
            }
            if(used_nails[mid] < A[j])
            {
                min_idx = mid+1;
            }else if(used_nails[mid] > B[j])
            {
                max_idx = mid-1;
            }
        }
        if (found == false) // all pass
            return false;
    }
    return true;
}