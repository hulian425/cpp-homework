/*实例化3个以下球员类对象，将它们按球衣号码写入文件，再读取后打印输出。
class Player
{
public:
	char* name;
	char* team;
        int age;
	int no;
};*/
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Player
{
public:
	string name;
	string team;
    int age;
	int no;
	Player(string name = "None", string team = "None", int age = 0, int no = 0):name("name"), team("team"),age(age),no(no){}
};

int main()
{
    Player p1("YaoMing", "火箭", 25, 11);
    Player p2("Jordan", "公牛", 24, 23);
    Player p3("Lebron", "湖人", 35, 23);
    ofstream output("output.txt",ios_base::out);
    if (!output)
    {
        cerr << "open failed" << endl;
        exit(-1);
    }

    output << p1.no << "\n" << p2.no << "\n" << p3.no << "\n";
    output.close();

    ifstream input("output.txt", ios_base::in);
    if (!input)
    {
        cerr << "open failed" << endl;
        exit(-1);
    }

    for (int i = 0; i < 3; i++)
    {
         int t;
         input >> t;
         cout << t << endl;
    }
    input.close();
    return 0;

}
