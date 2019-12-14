#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    // 2 将一个一维整型数组写入文件，再读取后打印输出。
    int a[10] = {1,5,6,8,5,6,7,8,6,10};

    ofstream output("output.txt", ios::out);

    if (!output)
    {
        cerr << "open faild" <<endl;
        exit(-1);
    }
    for (int i = 0; i < 10; i++)
    {
        output << a[i] << " ";
    }
    output << "\r\n";

    output.close();

    ifstream input("output.txt", ios::in);
    if (!input)
    {
        cerr << "open failed" << endl;
        exit(-1);
    }
    for (int i = 0; i < 10; i++)
    {
        int t;
        input >> t;
        cout << t << " ";
    }
    cout <<endl;
    input.close();

}
