#include <iostream>
#include <cstring>
#include <list>
using namespace std;

class stu {
private:
	char name[20];
	int grade;
public:
	~stu(){}
	stu(const char *_name, int _grade) {
		strcpy(name, _name);
		grade = _grade;
	}

	stu(const stu &a) {
		strcpy(name, a.name);
		grade = a.grade;
	}

	char* getname() {
		return name;
	}

	int getgrade() {
		return grade;
	}

	bool operator< (const stu a) {
		if (grade < a.grade) {
			return true;
		}

		return false;
	}
};

int main() {
	list<stu> a;
	stu a1("张三", 94), b1("李四", 50), c1("王五", 42);
	a.push_back(a1);
	a.push_back(b1);
	a.push_back(c1);

	a.sort();
	
	list<stu>::iterator iter;
	for (iter = a.begin(); iter != a.end(); iter++) {
		cout <<  iter->getgrade() << " ";
		cout << iter->getname() << " " << endl;
	}
	return 0;
}
