#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// 1 ��һ��������С�����ַ����ֱ�д���ļ��������ζ�ȡ���ӡ�����
int main()
{
    int z = 10;
    float f = 1.1;
    string a("zsjlagjlaf");
    ofstream output("output.txt", ios::out);
    if (!output)
    {
        cerr << "open faild" << endl;
        exit(-1);
    }

    output << z << " " << f << " " << a ;
    output << "\r\n";

    output.close();

    ifstream input("output.txt", ios::in);
    if (!input)
    {
        cerr << "open faild" << endl;
        exit(-1);
    }
    int zz;
    float ff;
    string aa;
    input >> zz >> ff >> aa;
    cout << zz << " "<<ff << " "<<aa << endl;
    return 0;

}
