#include <iostream>
using namespace std;

//中位数
//中位数定义：一组数据按从小到大的顺序依次排列，处在中间位置的一个数或最中间两个数据的平均值
//（如果这组数的个数为奇数，则中位数为位于中间位置的那个数；
//如果这组数的个数为偶数，则中位数是位于中间位置的两个数的平均值）.
//给出一组无序整数，求出中位数，如果求最中间两个数的平均数，向下取整即可（不需要使用浮点数）。
//输入:该程序包含多组测试数据，每一组测试数据的第一行为N，代表该组测试数据包含的数据个数，1 <= N <= 15000.
//接着N行为N个数据的输入，N=0时结束输入.
//输出:输出中位数，每一组测试数据输出一行

int main() {
    //冒泡排序进行一半是个基本的思路，更好的思路还没想到
    while(true){
        int N,mid = 0;
        cin >> N;
        int num[N];
        for (int i = 0; i < N; i++){
            cin >>num[i];
        }
        if(N % 2 == 0 && N != 0) {
            int count = N / 2;
            for (int i = 0; i < N; i++) {
                for (int j = N - 1; j > i; j--) {
                    if (num[j] > num[j - 1]) {
                        int temp = num[j - 1];
                        num[j - 1] = num[j];
                        num[j] = temp;
                    }
                }
                if(i > count) break; //num[count - 1]与num[count]的平均值即为中位数
            }
            mid = (num[count - 1] + num[count]) / 2;
        }
        else if(N % 2 == 1){
            int count = (N + 1) / 2; //此时count为中位数下标+1
            for (int i = 0; i < N; i++) {
                for (int j = N - 1; j > i; j--) {
                    if (num[j] > num[j - 1]) {
                        int temp = num[j - 1];
                        num[j - 1] = num[j];
                        num[j] = temp;
                    }
                }
                if(i >= count) break;
            }
            mid = num[count - 1];
        }
        else if(N == 0) break;
        cout << mid << endl;
    }
    return 0;
}
