#include<iostream>
using namespace std;
int ack_recursive(int m, int n) {
	if (m == 0) return n + 1;//結束條件
	else if (n == 0) return ack_recursive(m - 1, 1);//遞迴規則
	else return ack_recursive(m - 1, ack_recursive(m, n - 1));
}
int ack_nonrecursive(int m, int n) {
    while (m != 0) {
        if (m > 0 && n == 0) {
            n = 1;      // 如果 n == 0，m > 0，那麼計算 ack(m - 1, 1)
            m = m - 1;  // 將 m-1，繼續外層的計算
        }
        else if (m > 0 && n > 0) {
            int temp = m - 1; // 暫存 ack(m-1, ack(m, n-1)) 中的 m-1
            n = n - 1;          // 計算 ack(m, n-1)
            while (m > 0 && n == 0) {
                n = 1;      // 將 n 設為 1，對應到 ack(m - 1, 1)
                m = m - 1;
            }
            n = ack_nonrecursive(m, n); // 遞迴呼叫進行內部計算
            m = temp;  // 回到外層計算 m-1
        }
    }
    return n + 1;
}
int main(){

	cout<<"使用遞迴計算：" << ack_recursive(2, 2) << "\n";
    cout << "使用非遞迴計算：" << ack_nonrecursive(2, 2)<<endl;
    system("pause");
	return 0;
}