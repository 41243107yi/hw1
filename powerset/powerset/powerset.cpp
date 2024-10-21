#include <iostream>
#include <cmath>
using namespace std;
void powerSet(char set[], int setsize) {
    int powersetsize = pow(2, setsize); // Powerset 的大小是 2^n

    for (int i = 0; i < powersetsize;i++) { //外層迴圈檢查所有可能的子集合
      cout << "{ ";
        for (int j = 0; j < setsize; j++) {  // 使用位運算來檢查當前元素是否應該包含在當前子集合中
            if (i & (1 << j)) { // 檢查第 j 位是否為 1
               cout << set[j] << " "; // 如果是，輸出該元素
            }
        }
        cout << "}" <<endl;
    }
}

int main() {
    char set[3] = {'1','2','3'};
    cout << "Power set:" << endl;
    powerSet(set, 3);// 呼叫函數來列出集合的所有子集合

    return 0;
}