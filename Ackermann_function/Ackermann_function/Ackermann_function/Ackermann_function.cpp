#include<iostream>
using namespace std;
int ack_recursive(int m, int n) {
	if (m == 0) return n + 1;//��������
	else if (n == 0) return ack_recursive(m - 1, 1);//���j�W�h
	else return ack_recursive(m - 1, ack_recursive(m, n - 1));
}
int ack_nonrecursive(int m, int n) {
    while (m != 0) {
        if (m > 0 && n == 0) {
            n = 1;      // �p�G n == 0�Am > 0�A����p�� ack(m - 1, 1)
            m = m - 1;  // �N m-1�A�~��~�h���p��
        }
        else if (m > 0 && n > 0) {
            int temp = m - 1; // �Ȧs ack(m-1, ack(m, n-1)) ���� m-1
            n = n - 1;          // �p�� ack(m, n-1)
            while (m > 0 && n == 0) {
                n = 1;      // �N n �]�� 1�A������ ack(m - 1, 1)
                m = m - 1;
            }
            n = ack_nonrecursive(m, n); // ���j�I�s�i�椺���p��
            m = temp;  // �^��~�h�p�� m-1
        }
    }
    return n + 1;
}
int main(){

	cout<<"�ϥλ��j�p��G" << ack_recursive(2, 2) << "\n";
    cout << "�ϥΫD���j�p��G" << ack_nonrecursive(2, 2)<<endl;
    system("pause");
	return 0;
}