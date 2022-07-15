#include<iostream>
using namespace std;
const int N = 1e+5 + 10;
int idx, head, e[N], ne[N];
void init()
{
    head = -1;
    idx = 0;
}
void InsertHead(int c) {
    e[idx] = c;
    // ne[head] = idx; //����headʼ��ָ��ͷ���
    ne[idx] = head;
    head = idx;
    idx++;   //�ǵ�idxҪ����
}

void Delete(int k) {
    ne[k] = ne[ne[k]];
}

void Insert(int k, int c) {
    e[idx] = c;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

int main()
{
    init();
    int M;
    char c;
    int k, k1;
    scanf("%d", &M);
    while (M--)
    {
        cin >> c;//scanf���ַ����ǰ�滻�ж��룬���Բ���cin����debug���������������
        // printf("%c",c);
        if (c == 'H') {
            scanf("%d", &k);
            // printf("%d",k);
            InsertHead(k);
        }
        else if (c == 'I') { scanf("%d%d", &k, &k1); Insert(k - 1, k1); }
        else if (c == 'D') {
            scanf("%d", &k);
            if (k == 0) head = ne[head];  //ע������Ҫ������
            Delete(k - 1);
        }
    }
    for (int i = head;i != -1;i = ne[i])   //ע������Ľ�βʵ������-1�ƿ�
        printf("%d ", e[i]);
    return 0;
}

