//
//  main.cpp
//  DS二分查找_搜索二维矩阵
//
//  Created by Shockley on 12/12/23.
//

#include <iostream>
#include <vector>
using namespace::std;
bool binarySearchArr(vector<vector<int>>& arr,int target)
{
    int n=arr.size();
    int m=arr[0].size();
    if(n==0||m==0)
    {
        return false;
    }
    int left=0;
    int right=n*m-1;
    int mid;
    while (left<=right) {
        mid=left+(right-left)/2;
        int midValue=arr[mid/m][mid%m];
        if(midValue==target)
        {
            return true;
        }
        else if(midValue<target)
        {
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int m, n;
        cin >> m >> n;

        vector<vector<int>> matrix(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }

        int t;
        cin >> t;

        for (int i = 0; i < t; ++i) {
            int target;
            cin >> target;

            bool result = binarySearchArr(matrix, target);

            if (result) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        }

        return 0;
    return 0;
}
