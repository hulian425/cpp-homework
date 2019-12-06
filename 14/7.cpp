#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
// 7 使用mutlimap，存放书本信息（编号、书名、出版社、价格）。
// 要求能插入、删除书本，查询某书本信息，统计已卖出的书本总金额等。
class Book {
public:
	Book(string _name, string _press, double _price)
	{
		name = _name;
		press = _press;
		price = _price;
	}
	friend bool operator < (const Book book1, const Book book2)
	{
		return book1.name < book2.name;

	}
	
	friend ostream& operator << (ostream& os, const Book _book)
	{
		cout << "书名：" << _book.name << endl;
		cout << "出版社 ：" << _book.press << endl;
		cout << "价格：" << _book.price << endl;
		return os;
	}
	string name;
	string press;
	double price;
};
int main()
{
	multimap<Book,int> book;
	Book book1("离散数学", "清华大学出版社", 33);
	Book book2("概率论", "中国水利水电出版社", 56);
	Book book3("中国近代史纲要", "高等教育出版社", 26);
	book.insert(make_pair(book1, 0));
	book.insert(make_pair(book2, 0));
	book.insert(make_pair(book3, 0));

	multimap<Book, int>::iterator i;
	for (i = book.begin(); i != book.end(); i++)
	{
		cout << i->first << endl;
		cout << "卖出数量：" << i->second << endl;
		cout << endl;
		i->second += 2;
		
	}
	double sum = 0;
	for (i = book.begin(); i != book.end(); i++)
	{
		sum = (i->first).price * i->second + sum;

	}

	cout << "书本总金额：" << sum << "元" << endl;
	return 0;
	
}
