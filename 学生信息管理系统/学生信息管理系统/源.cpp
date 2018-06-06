#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
const int MAXSIZE = 100;
struct Student
{
	int no;
	char name[10];
	char sex;
	int age;
	char major[12];
};
typedef Student ElemType;
typedef struct
{
	ElemType data[MAXSIZE];
    int length;
}SeqList;

void InitList_Seq(SeqList &L)//初始化顺序表
{
	L.length = 0;
}

void CreatList_Seq(SeqList &L, ElemType a[], int n)//创建一个顺序表
{
	L.length = 0;
	for (int i = 0; i < n; i++)
	{
		L.data[L.length].no = a[i].no;
		strcpy_s(L.data[L.length].name, a[i].name);
		L.data[L.length].sex = a[i].sex;
		L.data[L.length].age = a[i].age;
		strcpy_s(L.data[L.length].major, a[i].major);
		L.length++;

	}
}

void Show_Seq(SeqList &L)//遍历顺序表
{
	for (int i=0; i < L.length; i++)
		cout << L.data[i].no << " " << L.data[i].name << " " << L.data[i].sex << " " <<
		L.data[i].age << " " << L.data[i].major << endl;
	cout << endl;
}

int ListLength_Seq(SeqList &L)//顺序表长度
{
	return L.length;
}

int LocateElem_Seq(SeqList L, int e)//按学号查询
{
	for (int i = 0; i < L.length; i++)
		if (L.data[i].no == e)
			return i + 1;
	return 0;
}

void ListInsert_Seq(SeqList &L, int i, ElemType e)//在第i个元素前插入
{
	if (L.length >= MAXSIZE) { cout << "线性表已满" << endl; exit(1); }
	if (i<1 || i>L.length + 1) { cout << "i值不合法" << endl; exit(1); }
	for (int j = L.length - 1; j > i - 1; j--)
	{
		L.data[j + 1].no = L.data[j].no;
		strcpy_s(L.data[j + 1].name, L.data[j].name);
		L.data[j + 1].sex = L.data[j].sex;
		L.data[j + 1].age = L.data[j].age;
		strcpy_s(L.data[j + 1].major, L.data[j].major);
	}
	L.data[i - 1].no = e.no;
	strcpy_s(L.data[i - 1].name, e.name);
	L.data[i-1].sex = e.sex;
	L.data[i-1].age = e.age;
	strcpy_s(L.data[i-1].major,e.major);
	L.length++;
}

void ListDelete_Seq(SeqList &L, int i, ElemType &e)//删除第i个元素
{
	if (i<1 || i>L.length) { cout << "i值不合法" << endl; exit(1); }
	e.no = L.data[i - 1].no;
	strcpy_s(e.name, L.data[i - 1].name);
	e.sex = L.data[i - 1].sex;
	e.age = L.data[i - 1].age;
	strcpy_s(e.major, L.data[i - 1].major);

	for (int j = i; j < L.length; j++)
	{
		L.data[j - 1].no = L.data[j].no;
		strcpy_s(L.data[j-1].name, L.data[j].name);
		L.data[j - 1].sex = L.data[j].sex;
		L.data[j - 1].age = L.data[j].age;
		strcpy_s(L.data[j - 1].major, L.data[j].major);
	}
	L.length--;
}

int main()
{
	SeqList List;
	struct Student st[100];
	int n;
	int choice;
	do
	{
		cout << "************************学生信息管理系统****************\n";
		cout << "*************************1----建立***********************\n";
		cout << "*************************2----查询***********************\n";
		cout << "*************************3----删除***********************\n";
		cout << "*************************4----增加***********************\n";
		cout << "*************************0----退出***********************\n";
		cout << "*********************************************************\n";
		cout << "请选择(0-4)";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "请输入学生人数：";
			cin >> n;
			cout << "请输入每位学生的信息：";
			for (int i = 0; i < n; i++)
				cin >> st[i].no >> st[i].name >> st[i].sex >> st[i].age >> st[i].major;
			CreatList_Seq(List, st, n);
			cout << "学生信息如下：\n";
			Show_Seq(List);
			break;
		}
		case 2:
		{
			cout << "请输入需查询学生的学号：";
			cin >> n;
			int index = LocateElem_Seq(List, n);
			if (index == 0)
				cout << "没有此学号的学生\n";
			else
				cout << List.data[index - 1].no << " " << List.data[index - 1].name << " " << List.data[index - 1].sex << " " << List.data[index - 1].age << " " << List.data[index - 1].major << endl;
			break;
		}
		case 3:
		{
			cout << "请输入需删除学生的学号：";
			cin >> n;
			int index = LocateElem_Seq(List, n);
			if (index == 0)
				cout << "没有此学号的学生\n";
			else
			{
				struct Student s;
				ListDelete_Seq(List, index, s);
				cout << "删除学生信息为：" << s.no << " " << s.name << " " << s.sex << " " << s.age << " " << s.major << endl;
				cout << "剩余学生信息为：\n";
				Show_Seq(List);
			}
			break;
		}
		case 4:
		{
			struct Student s;
			cout << "请输入需插入学生的学号：";
			cin >> s.no;
			cout << "请输入需插入学生的姓名：";
			cin >> s.name;
			cout << "请输入需插入学生的性别：";
			cin >> s.sex;
			cout << "请输入需插入学生的年龄：";
			cin >> s.age;
			cout << "请输入需插入学生的专业：";
			cin >> s.major;
			ListInsert_Seq(List, List.length + 1, s);
			cout << "学生信息如下：\n";
			Show_Seq(List);
		}
		case 0:
			break;
		default:
			cout << "输入错误！\n";
		}

	} while (choice);
	return 0;
}