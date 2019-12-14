/*ʵ����3��������Ա����󣬽����Ƿ���mutlimap�������º������򣩣�Ȼ������д���ļ��������ζ�ȡ�����vector�������º����ӡ�����
class Player
{
public:
	char* name;
	char* team;
        int age;
	int no;
};
*/
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

class Player
{
public:
	string name;
	string team;
    int age;
	int no;
	Player(string name = "None", string team = "None", int age = 0, int no = 0):name("name"), team("team"),age(age),no(no){}
    bool operator < (Player & p1)const
    {
        return no < p1.no;
    }
};
int main()
{
    Player p1("YaoMing", "���", 25, 11);
    Player p2("Jordan", "��ţ", 24, 23);
    Player p3("Lebron", "����", 35, 23);

    multimap<int,Player> p;
    p.insert(make_pair(p1.no, p1));
    p.insert(make_pair(p2.no, p2));
    p.insert(make_pair(p3.no, p3));
    ofstream output("output.txt", ios_base::out);
    if (!output)
    {
        cerr << "open failed" << endl;
        exit(-1);
    }

    multimap<int,Player>::iterator i;
    for (i = p.begin(); i != p.end(); ++i)
    {
        output.write(reinterpret_cast<char*>(&(i->second)), sizeof(i->second));
    }
    output.close();

    vector<int> no;
    ifstream input("output.txt", ios_base::in);
    if (!input)
    {
        cerr << "open failed" << endl;
        exit(-1);
    }
    for (int i = 0; i < 3; ++i)
    {
        Player t;
        input.read(reinterpret_cast<char*>(&t), sizeof(t));
        no.push_back(t.no);
    }
    for (int i = 0; i < 3; i++)
    {
        cout << no[i] << endl;
    }

    input.close();
    return 0;


}
