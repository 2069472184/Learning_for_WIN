#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;

typedef long long ll;

int public_Key, private_Key;
int Keys[30], idx1;
int n, fn, e, d;
int Es[10000], idx2;

int choice;

string originalText, codedText;

// շת������������
int gcd (int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

// ������
int qmi (int a, int b, int p)
{
    int res = 1;

    while (b)
    {
        if (b & 1) res = (ll)res * a % p;

        b >>= 1;
        
        a = (ll)a * a % p;
    }

    return res;
}

// ���ɹ�˽Կ������nһ������int('z')����ȷ���ܹ��ӽ������е���ĸ
void Init ()
{
    srand(static_cast<unsigned>(time(nullptr)));

	for (int i = 2; i <= 100; i++)
	{
		bool flag = true;
		for (int j = 2; j < i; j++)
			if (i % j == 0) 
			{
				flag = false;
				break;
			}	
			
		if (flag) Keys[idx1++] = i;
	}
	
	// ������ɹ�˽Կ 
	int public_key_idx = rand() % idx1, private_key_idx = rand() % idx1;
	while (public_key_idx == private_key_idx || Keys[public_key_idx] * Keys[private_key_idx] < 122)
	{
		public_key_idx = rand() % idx1;
		private_key_idx = rand() % idx1;
	}
	
	public_Key = Keys[public_key_idx];
	private_Key = Keys[private_key_idx];
}

// ��� n, fn , e �� d 
void Get ()
{
	n = public_Key * private_Key;
	fn = (public_Key - 1) * (private_Key - 1);
	
	// �������e 
	for (int i = 2; i < fn; i++)
		if (gcd(fn, i) == 1)
			Es[idx2++] = i;
			
	int e_idx = rand() % idx2;
	e = Es[e_idx];

	// ȡ����С����Ԫ 
    for (int k = 1; ; k++)
        if ((k * e - 1) % fn == 0)
        {
            d = k;
            break;
        }
}

void Coding ()
{
    cout << "The codedText is: ";
	for (char ch: originalText)
    {
        int tem = int(ch);

        cout << qmi(tem, e, n) << ' ';
    }
    cout << endl;
}

void DisCoding ()
{
    stringstream str(codedText);
    string sstr;

    cout << "The originalText is: ";
    while (str >> sstr)
    {
        int idx = 0, tem = 0;
        while (sstr[idx])
        {
            tem = tem * 10 + int(sstr[idx] - '0');
            idx++;
        }

        cout << char(qmi(tem, d, n));
    }
    cout << endl;
}

int main ()
{
	Init(); 
	
	Get();
	
	cout << "The public_Key is: " << "(" << e << ", " << n << ")" << endl;
    cout << "The private_Key is: " << "(" << d << ", " << n<< ")" << endl;

    cout << "Coding or DisCoding (1. Coding, 2. DisCoding, 3. Exit): ";
    cin >> choice;
    while (choice != 1 && choice != 2)
    {
        cout << "Type again, coding or disCoding (1. Coding, 2. DisCoding, 3. Exit): ";
        cin >> choice;
    }

    while (choice != 3)
    {
        getchar();

        if (choice == 1)
        {
            cout << "Now give me the originalText: ";
            getline(cin, originalText);
            codedText = originalText;

            cout << "The originalText is: ";
            for (char ch: originalText) cout << ch;
            cout << endl;
            
            Coding();
        }

        if (choice == 2)
        {
            cout << "Now give me the codedText: ";
            getline(cin, codedText);

            cout << "The codedText is: ";
            for (char ch: codedText) cout << ch;
            cout << endl;
            
            DisCoding();
        }

        cout << "Coding or DisCoding (1. Coding, 2. DisCoding, 3. Exit): ";
        cin >> choice;
        while (choice != 1 && choice != 2 && choice != 3)
        {
            cout << "Type again, coding or disCoding (1. Coding, 2. DisCoding, 3. Exit): ";
            cin >> choice;
        }
    }

	return 0;
}
