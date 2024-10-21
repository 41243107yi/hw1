#include <iostream>
#include <cmath>
using namespace std;
void powerSet(char set[], int setsize) {
    int powersetsize = pow(2, setsize); // Powerset ���j�p�O 2^n

    for (int i = 0; i < powersetsize;i++) { //�~�h�j���ˬd�Ҧ��i�઺�l���X
      cout << "{ ";
        for (int j = 0; j < setsize; j++) {  // �ϥΦ�B����ˬd��e�����O�_���ӥ]�t�b��e�l���X��
            if (i & (1 << j)) { // �ˬd�� j ��O�_�� 1
               cout << set[j] << " "; // �p�G�O�A��X�Ӥ���
            }
        }
        cout << "}" <<endl;
    }
}

int main() {
    char set[3] = {'1','2','3'};
    cout << "Power set:" << endl;
    powerSet(set, 3);// �I�s��ƨӦC�X���X���Ҧ��l���X

    return 0;
}