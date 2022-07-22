#include<iostream>
#include<cstring>
using namespace std;
//开放寻址法
// const int n = 200003,null = 0x3f3f3f3f;   //记住开放寻址方式选择2~3倍最大存储量的质数
// int h[n];//一般边界都会采用 null = 0x3f3f3f3f 肯定比10**9大, 与memset要对应
// int find(int x){
//     int t = (x%n+n)%n;
//     while(h[t]!=null&&h[t]!=x)
//         t++;
//     if(t==n)t=0;
//     return t;
// }
// int main(){
//     int N,temp;
//     memset(h,0x3f,sizeof h);
//     scanf("%d",&N);
//     while(N--){
//         char op[2];
//         scanf("%s",op);
//         if(op[0]=='I'){
//             scanf("%d",&temp);    //记得加地址运算符
//             int k = find(temp);
//             h[k] = temp;
//         }
//         else{
//             scanf("%d",&temp);   //记得地址运算符
//             if(h[find(temp)]==temp)
//                 puts("Yes");
//             else
//                 puts("No");
//         }
//     }
//     return 0;
// }
const int n = 100003;
int h[n], e[n], ne[n], idx;
void insert(int x) {
    int t = (x % n + n) % n;
    e[idx] = x;
    ne[idx] = h[t];
    h[t] = idx;      //h里面存的是头节点的地址
    idx++;
}
bool find(int x) {
    int t = (x % n + n) % n;
    for (int i = h[t];i != -1;i = ne[i]) { //h里面存的是哈希表相应索引对应的头节点的地址
        if (e[i] == x)         //注意e里面存的是数据
            return true;
    }
    return false;
}
int main() {
    int N, temp;
    memset(h, -1, sizeof h);
    scanf("%d", &N);
    while (N--) {
        char op[2];
        scanf("%s", op);
        if (op[0] == 'I') {
            scanf("%d", &temp);
            insert(temp);
        }
        else {
            scanf("%d", &temp);
            if (find(temp)) puts("Yes");
            else puts("No");
        }

    }

    return 0;
}


作者：啥也不会的小白菜
链接：https ://www.acwing.com/activity/content/code/content/3866152/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。