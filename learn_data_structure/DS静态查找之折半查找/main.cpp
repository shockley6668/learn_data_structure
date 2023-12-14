//
//  main.cpp
//  DS静态查找之折半查找
//
//  Created by Shockley on 12/6/23.
//

#include <iostream>

#include <iostream>
#include <vector>

int binary_search(const std::vector<int>& data, int target) {
    int left = 0;
    int right = data.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (data[mid] == target) {
            return mid + 1;  // 队列位置从1开始
        } else if (data[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // 查找不成功
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> data[i];
    }

    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        int target;
        std::cin >> target;
        int position = binary_search(data, target);
        if (position == -1) {
            std::cout << "error" << std::endl;
        } else {
            std::cout << position << std::endl;
        }
    }

    return 0;
}
