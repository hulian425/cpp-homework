#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// 1 将一个整数、小数和字符串分别写入文件，再依次读取后打印输出。
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
