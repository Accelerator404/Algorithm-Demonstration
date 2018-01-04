#include <iostream>
using namespace std;

//排队游戏
//在幼儿园中，老师安排小朋友做一个排队的游戏。
//首先老师精心的把数目相同的小男孩和小女孩编排在一个队列中，每个小孩按其在队列中的位置发给一个编号（编号从0开始）。
//然后老师告诉小朋友们，站在前边的小男孩可以和他后边相邻的小女孩手拉手离开队列，
//剩余的小朋友重新站拢，再按前后相邻的小男孩小女孩手拉 手离开队列游戏，如此往复。
//由于教师精心的安排，恰好可以保证每两个小朋友都能手拉手离开队列，并且最后离开的两个小朋友是编号最小的和最大的两个小朋友。
//（注：只有小男孩在前，小女孩在后，且他们两之间没有其他的小朋友，他们才能手拉手离开队列）。
//请根据老师的排队，按小女孩编号从小到大的顺序，给出所有手拉手离开队列的小男孩和小女孩的编号对。
//输入：用一个字符串代表小朋友队列。字符串中只会出现两个字符（样例输入里用的是括号但实际数据则不一定），
//分别代表小男孩和小女孩，首先出现的字符代表小男孩，另一个字符代表小女孩。小孩总数不超过100
//输出：按小女孩编号顺序，顺序输出手拉手离开队列的小男孩和小女孩的编号对，
//每行一对编号，编号之间用一个空格分隔。

void mark(int boy,int girl,char data[]){
    cout << boy << ' ' << girl << endl;
    data[boy] = '\0';
    data[girl] = '\0';
}

void analysis(char boy,char girl,char data[]) {
    bool tag = true;
    int i = 0;
    while(tag){
        if(data[i] != boy && i < 100){
            i++;
        }
        else if (i >= 100) break;   //避免溢出
        else {
            int j = i + 1;
            while (tag){
                if(data[j] == girl){
                    mark(i,j,data);
                    analysis(boy,girl,data);     //处理后的序列进行递归
                    tag = false;
                }
                else if (data[j] == boy){     //若相邻的是男孩，则交换到下一个男孩进行配对尝试
                    i = j;
                    break;
                }
                else
                    j++;
            }
        }
    }
}

int main() {
    char data[100] = {'\0'},boy,girl;
    cin.getline(data,100);
    int i = 0;
    boy = data[0];
    while(true){
        if(data[i] != boy){
            girl = data[i];
            break;
        }
        i++;
    }
    analysis(boy,girl,data);
    return 0;
}
