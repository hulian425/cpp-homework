/*6 重新实现一个字典程序，能进行英文翻译，并具有提示功能。
中英文单词存放在文件中，每次程序打开时，读取这些单词保存在STL容器中，再提供翻译功能。
文件读写可用C完成，其余C++

Dictionary类
LoadLibrary()//加载字典，从外存到内存
LookupWord()//查单词，根据输入的英文，给出相应的中文，如果字典里没有，给出最接近的
InsertWord()//插入一组新单词
DeleteWord()//删除一组单词
RestoreLibrary()//重新加载字典
FreeLibrary()//释放字典

输入"TIGER"和"DOT"后应有的结果：
find the word "TIGER" -- 老虎
find the word "DOT" -- 没有该单词 Maybe you want to look for "DOG" -- 狗*/
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <locale.h>
#include <IOSTREAM>
#include <FSTREAM>
#include <windows.h>
using namespace std;

class UtfFile
{
public:
	static char* UnicodeToGB2312(WCHAR uData, char buffer[2]);  // Unicode 转换成 GB2312
	static WCHAR* UTF_8ToUnicode(char* pText, WCHAR& unicode);  // 把UTF-8 转化成 Unicode
	static char* TranslateUTF8ToGB(char* str, size_t len);   // 把UTF-8字符串转化成ANSI（GB2312）编码形式
	char* GetString(char* str, int maxLen = 1024);  // 读取一个字符串，以换行符为结束标示
	char* GetLine(char* str, int maxLen);    // 读取一行字符
	void close();          // 关闭文件流
	int open(const char* sFileName);     // 用于打开一个文件
	UtfFile(const char* sour);
	virtual ~UtfFile();

private:
	ifstream inf;
};
class Dictionary
{
public:
	map<string, string> dic;
	void LoadLibrary();
	void LookupWord(string a);
};
/*
int main(void)
{
	ifstream inf("data.txt");
	if (!inf) {
		cerr << "open data.txt fail\n";
		return 1;
	}

	string oneline;
	while (inf.peek() != EOF) { // 关键行
		getline(inf, oneline);
		cout << oneline << "\n";
	}
}
*/
void Dictionary::LoadLibrary()
{
	ifstream inf("dic.txt", ios_base::in);
	if (!inf)
	{
		cerr << "open failed" << endl;
		exit(-1);
	}

	string a, b;
	while (inf.peek() != EOF)
	{
		getline(inf, a);
		getline(inf, b);
		dic.insert(make_pair(a, b));
	}
	inf.close();

}

void Dictionary::LookupWord(string a)
{
	map<string, string>::iterator i;
	i = dic.find(a);
	if (i != dic.end())
	{
		cout << i->second;
	}
	else cout << "NOT FIND\n";
	return;
}
int main()
{
	Dictionary dic;
	dic.LoadLibrary();
	// cout << dic.dic.begin()->first << endl;
	dic.LookupWord("apple");
}
