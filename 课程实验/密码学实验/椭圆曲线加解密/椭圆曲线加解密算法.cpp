#include<iostream>
#include<math.h>
#include<time.h>
#include<cstring>
using namespace std;
 
class point
{
public:
	int x;
	int y;
};
point P[100];
int num = 0;
 
//ȡģ
int my_mod(int a, int p)
{
	//ע�⸺�����Ҫ����һ��p
	int i;
	i = a / p;
	int re = a - i * p;
	if (re >= 0)
	{
		return re;
	}
	else
	{
		return re + p;
	}
}
 
//�ݴ����㣬��ģ���㣬��ֹ���
int my_pow(int a, int m, int p)
{
	int result = 1;
	for (int i = 0; i < m; i++)
	{
		result = (result*a) % p;
	}
	return result;
}
 
//������y,���ж�ƽ�����Ƿ�Ϊ���� 
int my_sqrt(int s)
{
	int t;
	t = (int)sqrt(s);
	if (t*t == s)
	{
		return t;
	}
	else {
		return -1;
	}
}
 
void all_points(int a,int b,int p)
{
	for (int i = 0; i < p; i++)
	{
		int s = i * i * i + a * i + b;
		while (s < 0) s += p;
		s = my_mod(s, p);
		//�ж��Ƿ�Ϊƽ��ʣ��
		//pΪ23����������
		//Euler׼��
		int re = my_pow(s, (p - 1) / 2, p);
		if (re == 1)
		{
			//��y
			int n = 1, y;
			int f = my_sqrt(s);
			if (f != -1) y = f;
			else 
				for (; n <= p - 1;)
				{
					s = s + n * p;
					f = my_sqrt(s);
					if (f != -1)
					{
						y = f;
						break;
					}
					n++;
				}
			y = my_mod(y, p);
			P[num].x = i;
			P[num].y = y;
			num++;
			if (y != 0)
			{
				P[num].x = i;
				P[num].y = (p - y) % p;
				num++;
			}
		}
	}		
}
 
void show()
{
	for (int i = 0; i < num; i++)
	{
		cout << P[i].x << " " << P[i].y << endl;
	}
}
 
 
//��չŷ����÷����ݹ鷨
int extend(int a, int b, int&x, int&y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int r = extend(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - a / b * y;
	return r;
}
 
//�����ݹ���չŷ���������
int inv(int a, int b)
{
	int x, y;
	int r = extend(a, b, x, y);
	if (r != 1)
	{
		return 0;
	}
	x = x % b;
	if (x < 0)
	{
		x = x + b;
	}
	return x;
}
 
 
//����ļӷ����� 
point add(point p1, point p2, int a, int p)
{
	long t;int flag = 0;
	int x1 = p1.x;int y1 = p1.y;
	int x2 = p2.x;int y2 = p2.y;
	int tx, ty;int x3, y3;
	
	if ((x2 == x1) && (y2 == y1))
	{
		//��ͬ��
		if (y1 == 0)
		{
			flag = 1;
		}
		else 
		{
			t = (3 * x1*x1 + a)*inv(2 * y1, p) % p;
		}
	}
	else 
	{
		//��ͬ�����
		ty = y2 - y1;
		tx = x2 - x1;
		while (tx<0)
		{
			tx = tx + p;
		}
		while (ty<0)
		{
			ty = ty + p;
		}
		
		if (tx == 0 && ty != 0)
		{
			flag = 1;
		}
		else 
		{
			//�㲻���
			t = ty * inv(tx, p) % p;
		}
	}
	
	if (flag == 1)
	{
		//���޵�
		p2.x = -1;
		p2.y = -1;
	}
	else 
	{
		x3 = (t*t - x1 - x2) % p;
		y3 = (t*(x1 - x3) - y1) % p;
		while (x3<0)
		{
			x3 += p;
		}
		while (y3<0)
		{
			y3 += p;
		}
		p2.x = x3;
		p2.y = y3;
	}
	return p2;
}
 
//���ѡȡһ������Ԫ�������
int jie(point &pp, int a, int p)
{
	int ii = rand() % num;
	point P0 = P[ii];
	point p1, p2;
	int number = 1;
	p1.x = P0.x; p2.x = P0.x;
	p1.y = P0.y; p2.y = P0.y;
	while (true)
	{
		p2 = add(p1, p2, a, p);
		if (p2.x == -1 && p2.y == -1)
		{
			break;
		}
		number++;
		if (p2.x == p1.x)
		{
			break;
		}
	}
	pp.x = p1.x;
	pp.y = p1.y;
	int n = ++number;
	return n;
}
 
//�����ж�
bool judge(int num)
{
	bool ret = true;
	int ubound = sqrt(num) + 1;
	for (int i = 2; i < ubound; i++)
	{
		if (num % i == 0)
		{
			ret = false;
			break;
		}
	}
	return ret;
}
 
//����kG
point cal(point G, int k, int a, int p)
{
	point temp = G;
	for (int i = 0; i < k - 1; i++)
	{
		temp = add(temp, G, a, p);
	}
	return temp;
}
 
int main()
{
	srand(time(NULL));
	int a, b, p;
	point generator; int n;
	char SE[10];
	char CR[10];
 
	cout << "��������Բ����Ⱥ��a,b,p����";
	cin >> a >> b >> p;
	cout << "���������ģ�";
	cin >> SE;
	cout << "��������Կ��";
	cin >> CR;
 
	//�������е�
	all_points(a, b, p);
	//ѡȡ����Ԫ��ֱ����Ϊ����
	do
	{
		n = jie(generator, a, p);
	} while (judge(n) == false);
	cout << endl << "ѡȡ����Ԫ��" << generator.x << "," << generator.y << "��,��Ϊ��" << n << endl;
	//ѡȡ˽Կ
	int ka = int(CR[0]) % (n - 1) + 1;//ѡȡʹ�õ���Կ
	point pa = cal(generator, ka, a, p);//���㹫Կ
	cout << "˽Կ��" << ka << endl;
	cout << "��Կ����" << pa.x << "," << pa.y << "��" << endl;
 
	//����
	int k = 0;//�����k
	k = rand() % (n - 2) + 1;
	point C1 = cal(generator, k, a, p);//����C1
		
	//mǶ�뵽��Բ����
	int t = rand() % num; //ѡ��ӳ���
	point Pt = P[t];
	point P2 = cal(pa, k, a, p);
	point Pm = add(Pt, P2, a, p);
	cout << endl << "Ҫ���͵����ģ�" << endl;
	cout << "kG=(" << C1.x << "," << C1.y << "),pt+kPa=(" << Pm.x << "," << Pm.y << ")";
	int C[100];
	cout<<",C = { ";
	for (int i = 0; i<strlen(SE); i++)
	{
		C[i] = int(SE[i]) * Pt.x + Pt.y;//ѡȡҪ���ܵ�����
		cout<< C[i] <<" ";
	}
	cout << "}" << endl;
 
	
	//����
	point temp, temp1;
	int m;
	temp = cal(C1, ka, a, p);
	temp.y = 0 - temp.y;
	temp1 = add(Pm, temp, a, p);//���Pt 
	printf("\n���ܽ����\n");
	for (int i = 0; i<strlen(SE); i++)
	{
		m = (C[i] - temp1.y) / temp1.x;
		printf("%c", char(m));//������� 
	}
	printf("\n");
 
	return 0;
}
