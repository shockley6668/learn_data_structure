//
//  main.cpp
//  DS查找——折半查找求平方根
//
//  Created by Shockley on 12/10/23.
//

#include <iostream>
#include "vector"
#include <iomanip>
#include "algorithm"
using namespace std;
double binarySearch(double y)
{
    double low=0;
    double high=y;
    double mid=(low+high)/2;
    while (abs(mid*mid-y)>0.00001) {
        
        if(mid*mid<y)
        {
            low=mid;
        }
        else{
            high=mid;
        }
        mid=(low+high)/2;
    }
    return mid;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        double y;
        cin >> y;

        // 调用折半查找平方根的函数
        double result = binarySearch(y);

        // 输出结果，保留小数点后三位
        cout << fixed << setprecision(3) << result << endl;
    }

    return 0;
 
}
