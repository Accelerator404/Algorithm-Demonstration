#include <iostream>
using namespace std;

//����ĸ�ĸ���
//��һ���ַ������ҳ�Ԫ����ĸa,e,i,o,u���ֵĴ�����
//����:����һ���ַ������ַ����п����пո�����cin.getline(s,counts)������һ���ַ������뵽�ַ�����s�У�
//����counts��s����󳤶ȣ�������������ֱ��д80�������ַ�������С��80���ַ���
//���:���һ�У��������a,e,i,o,u�������ַ����г��ֵĴ���������֮���ÿո�ָ���

int main() {
    char s[80];
    int count[5]={0};
    cin.getline(s,80);
    for (int i = 0; i < 80; i++){
        switch(s[i])
        {
            case'a': count[0]++; break;
            case'e': count[1]++; break;
            case'i': count[2]++; break;
            case'o': count[3]++; break;
            case'u': count[4]++; break;
            default:;
        }
    }
    for (int i = 0; i < 5; i++){
        cout << count[i] <<' ';
    }
    return 0;
}