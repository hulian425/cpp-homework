#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;

// 2 放若干书本对象进queue，并顺序输出这些书本的书名、价格

class Book
{
private:
    double price;
    string name;
public:
    Book():name("NULL"),price(0){}
    Book(string _name, double _price)
    {
        price = _price;
        name = _name;
    }
    ~Book(){}
    friend ostream& operator <<(ostream &os, const Book book)
    {
        cout << "书名是：" << book.name<< endl;
        cout << "价格是：" << book.price << endl;
        return os;
    }
};

int main()
{
    Book book1("世界十大未解之谜", 30.5);
    Book book2("挑战程序设计竞赛", 45.2);
    Book book3("cpp primer plus", 80.5);
    queue<Book> q;
    q.push(book1);
    q.push(book2);
    q.push(book3);
    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }
    return 0;
}
