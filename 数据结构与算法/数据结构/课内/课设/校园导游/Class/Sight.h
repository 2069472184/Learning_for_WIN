//������
class Sight
{
    public:
        Sight(int x = 0, int y = 0, string id = "", string name = "", string intro = "", string comment = "");
        Sight(const Sight &s);
        void Update_Postion(int new_x, int new_y);    // ��������
        void Update_ID(string new_id);                // ���±��
        void Update_Name(string new_name);            // ��������
        void Update_Intro(string new_intro);          // ���¼��
        void Update_Comment(string new_comment);      // ��������
        string getID();   // ���ر��
        int getX();       // ����x����
        int getY();       // ����y����
        void Show ();   
        ~Sight();
    private:
        string ID, Name, Intro, Comment;
        int X, Y;
};

Sight::Sight(int x, int y, string id, string name, string intro, string comment)
{
    X = x;
    Y = y;
    ID = id;
    Name = name;
    Intro = intro;
    Comment = comment;
}

Sight::Sight(const Sight &s)
{
    X = s.X;
    Y = s.Y;
    ID = s.ID;
    Name = s.Name;
    Intro = s.Intro;
    Comment = s.Comment;
}

void Sight::Update_Postion(int new_x, int new_y)
{
    X = new_x;
    Y = new_y;
}

void Sight::Update_ID(string new_id)
{
    ID = new_id;  
}

void Sight::Update_Name(string new_name)
{
    Name = new_name;
}

void Sight::Update_Intro(string new_intro)
{
    Intro = new_intro;
}

void Sight::Update_Comment(string new_comment)
{
    Comment = new_comment;
}

string Sight::getID()
{
    return ID;
}

int Sight::getX()
{
    return X;
}

int Sight::getY()
{
    return Y;
}

void Sight::Show()
{
    cout << "������" << Name << "�ľ�����Ϣ��" << endl;
    cout << "λ�ã�(" << X << "," << Y << ")" << endl;
    cout << "�����ţ�" << ID << endl;
    cout << "�����飺" << Intro << endl;
    cout << "�������ۣ�" << Comment << endl;
}

Sight::~Sight() {}