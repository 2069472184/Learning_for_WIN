#include <iostream>
#include <cstring>

using namespace std;

const int N = 50010;

int T, n, a[N];
int f[N], b[N];

int main ()
{
    cin >> T;
    
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        
        memset(f, -0x3f, sizeof(f));
        memset(b, -0x3f, sizeof(b));
        
        //�õ���벿�����зֽ���������Ԫ�غ�
        //tem��ʾ��a[i]Ϊ�Ҷ˵������Ԫ�����У����ǵĺ���ʱ������
        int tem = 0;
        for (int i = 1; i < n; i++) //�Ұ벿��������һ��Ԫ��
        {
            tem = max(tem, 0) + a[i];
            //������a[i]���������кͰ���a[i - 1]���������н��бȽ�
            //����Ϊʲôֻ����i - 1�����ȥ����i����Ϊ���������������a[i]����ȡ�������
            //��temһֱС��0��f[i - 1]��Ȼ��������������ֵ������ԭ�������ֵ����һֱ������ȥ��
            //ֱ������ĳ��tem�����������
            f[i] = max(f[i - 1], tem);
        }
        
        //�õ��Ұ벿�����зֽ���������Ԫ�غ�
        tem = 0;                       
        for (int i = n; i > 1; i--) //��벿��������һ��Ԫ��
        {
            tem = max(tem, 0) + a[i];
            b[i] = max(b[i + 1], tem);
        }
        
        int res = -0x3f3f3f3f;
        for (int i = 1; i < n; i++) res = max(res, f[i] + b[i + 1]);
        
        cout << res << endl;
    }
    
    return 0;
}