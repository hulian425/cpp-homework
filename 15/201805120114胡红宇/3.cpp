/*3 实例化3个以下类对象，将它们写入文件，再读取后打印输出。
class Test
{
public:
	int a, b;
        char c;
};*/
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Test
{
public:
	int a, b;
        char c;
    Test(int a = 0, int b = 0, char c = 0):a(a),b(b),c(c){}
};

int main()
{
    Test t1(1, 3, 'a');
    Test t2(5, 6, 'd');
    Test t3(5, 6, 's');
    ofstream output("output.txt", ios_base::out);
    if (!output)
    {
        cerr << "open failed" <<endl;
        exit(-1);
    }
    output.write(reinterpret_cast<char*>(&t1), sizeof(t1));
    output.write(reinterpret_cast<char*>(&t2), sizeof(t2));
    output.write(reinterpret_cast<char*>(&t3), sizeof(t3));

    output.close();
    ifstream input("output.txt", ios_base::in);
    if (!input)
    {
        cerr << "open failed" <<endl;
        exit(-1);
    }
    for (int i = 0; i < 3; i++){
    Test t;
    input.read(reinterpret_cast<char*>(&t), sizeof(t));
    cout << t.a << " " << t.b << " " <<t.c << endl;
    }
    return 0;
}
