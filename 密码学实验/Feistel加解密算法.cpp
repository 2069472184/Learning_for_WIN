#include <iostream>
#include <string>
#include <vector>

using namespace std;

string OriginalText, Key;

class FeistelTest 
{
    public:
        static const int LOOP_NUM = 16;  // ��������
        vector<string> keys;
        vector<string> pContent;
        vector<string> cContent;
        int origin_length;

        FeistelTest(string content, string key); // ���캯��������������ġ���Կ������������Կ����������
 
        void encrypt ();  // ���ܺ���
        void decrypt ();  // ���ܺ���
        void generateKey(string key);  // ����Կ���ɺ���
        string swapStr(string key, int i);  // �������Ķ�
        void divideGroups(string content);  // ���Ļ��ֺ���
        string loop(string content, int flag);  // �ֺ���
        string f(int time, string content, int flag);  // f����
};

FeistelTest::FeistelTest(string content, string key)
{
    keys.resize(LOOP_NUM);
    generateKey(key);
    divideGroups(content);

    cout << "--------Create Feistel Module successfully--------" << endl << endl;
}

void FeistelTest::encrypt () 
{
    string c;
    for(int i = 0; i < pContent.size(); i++) 
    {
        cContent[i] = loop(pContent[i], 0);
        c += cContent[i];
    }

    cout << "The CodedText is: " << c << endl;
}

void FeistelTest::decrypt () 
{
    string p;
    for(int i = 0; i < cContent.size(); i++) 
    {
        pContent[i] = loop(cContent[i], 1);
        p += pContent[i];
    }
    cout << "The DisCodedText is: " << p.substr(0, origin_length) << endl;
}

void FeistelTest::generateKey (string key) 
{
    while (key.length() < 16)
        key += key;

    key = key.substr(0, 16);

    for(int i = 0; i < 16; i++)
    {
        key = swapStr(key, i);
        keys[i] = key;
    }
}

string FeistelTest::swapStr (string key, int i) 
{
    char last = key[key.length() - 1];
    key = last + key.substr(0, key.length() - 1);
    return key;
}

void FeistelTest::divideGroups (string content) 
{
    int g_num;
    int m_num;
    int b_num;
    origin_length = content.length();
    g_num = origin_length / 8;
    m_num = origin_length % 8;
    b_num = 8 - m_num;

    if(m_num)
        for (int i = 0; i <= b_num; i++)
            content += to_string(b_num);

    g_num = content.length() / 8;
    pContent.resize(g_num);
    cContent.resize(g_num);

    for(int i = 0; i < g_num; i++)
        pContent[i] = content.substr(8 * i, 8);
}

string FeistelTest::loop (string content, int flag) 
{
    if (!flag) 
    {
        for(int i = 0; i < 16; i++)
            content = f(i, content, flag);
    }
    else
    {
        for(int i = 15; i > -1; i--)
            content = f(i, content, flag);
    }

    return content;
}

string FeistelTest::f (int time, string content, int flag) 
{
    string LE = content.substr(0, 4);
    string RE = content.substr(4, 8);
    string LE1;
    string RE1;
    string key = keys[time];
    vector<char> tmp(4);

    for(int j = 0; j < 4; j++) 
        tmp[j] = RE[j] ^ key[4 * j] ^ LE[j];

    LE1 = RE;
    RE1 = string(tmp.begin(), tmp.end());

    if (((flag == 0) && (time == 15)) || ((flag == 1) && (time == 0)))
        return RE1 + LE1;

    return LE1 + RE1;
}

int main() 
{
    cout << "Please give me the originalText: ";
    getline(cin, OriginalText);

    cout << "Then give me the key to encrypt the text: ";
    getline(cin, Key);

    cout << endl;

    FeistelTest feistelTest(OriginalText, Key);
    feistelTest.encrypt();
    feistelTest.decrypt();

    return 0;
}
