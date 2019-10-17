#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

const int N = 19;
class Pat{
public:
    Pat();
    ~Pat();
    void Print_pat();
    void Move(int opt);
private:
    char m[20][20];
};
Pat::Pat()
{
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            {
                m[i][j] = ' ';
                if (i == 0 || i == 19) m[i][j] = '#';
                else if (j == 0 || j == 19) m[i][j] = '#';
            }
    m[1][3] = '*';
    m[2][2] = '*'; m[2][4] = '*';
    m[3][1] = '*'; m[3][5] = '*';
    m[4][2] = '*'; m[4][4] = '*';
    m[5][3] = '*';

}
void Pat::Print_pat()
{
    for (int i = 0; i < N + 1; i++)
        for (int j = 0; j < 20; j++)
        {
            printf("%C%C", m[i][j], j == 19 ? '\n' : 0);
        }
}

void Pat::Move(int opt)
{
    if (opt == 'w')
    {
        for (int i = 1; i < N; i++)
            for (int j = 1; j < N; j++)
                {
                    if (m[i][j] == '*'){
                        m[i - 1][j] = m[i][j];
                        m[i][j] = ' ';
                    }
                }
    }
    else if (opt == 'a')
    {
        for (int i = 1; i < N; i++)
            for (int j = 1; j < N; j++)
                {
                    if (m[i][j] == '*'){
                        m[i][j-1] = m[i][j];
                        m[i][j] = ' ';
                    }
                }
    }
    else if (opt == 's')
    {
        for (int i = N - 1; i >= 1; i--)
            for (int j = N - 1; j >= 1; j--)
                {
                    if (m[i][j] == '*'){
                        m[i+1][j] = m[i][j];
                        m[i][j] = ' ';
                    }
                }
    }
    else if (opt == 'd')
    {
        for (int i = N - 1; i >= 1; i--)
            for (int j = N - 1; j >= 1; j--)
                {
                    if (m[i][j] == '*'){
                        m[i][j + 1] = m[i][j];
                        m[i][j] = ' ';
                    }
                }
    }
    //Print_pat();
}
Pat::~Pat()
{

}
int main()
{
    Pat x;
    x.Print_pat();

    int opt;
    cin >> opt;
    system("cls");
    x.Move(opt);
    x.Print_pat();

}
