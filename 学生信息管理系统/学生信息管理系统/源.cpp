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

void InitList_Seq(SeqList &L)//��ʼ��˳���
{
	L.length = 0;
}

void CreatList_Seq(SeqList &L, ElemType a[], int n)//����һ��˳���
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

void Show_Seq(SeqList &L)//����˳���
{
	for (int i=0; i < L.length; i++)
		cout << L.data[i].no << " " << L.data[i].name << " " << L.data[i].sex << " " <<
		L.data[i].age << " " << L.data[i].major << endl;
	cout << endl;
}

int ListLength_Seq(SeqList &L)//˳�����
{
	return L.length;
}

int LocateElem_Seq(SeqList L, int e)//��ѧ�Ų�ѯ
{
	for (int i = 0; i < L.length; i++)
		if (L.data[i].no == e)
			return i + 1;
	return 0;
}

void ListInsert_Seq(SeqList &L, int i, ElemType e)//�ڵ�i��Ԫ��ǰ����
{
	if (L.length >= MAXSIZE) { cout << "���Ա�����" << endl; exit(1); }
	if (i<1 || i>L.length + 1) { cout << "iֵ���Ϸ�" << endl; exit(1); }
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

void ListDelete_Seq(SeqList &L, int i, ElemType &e)//ɾ����i��Ԫ��
{
	if (i<1 || i>L.length) { cout << "iֵ���Ϸ�" << endl; exit(1); }
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
		cout << "************************ѧ����Ϣ����ϵͳ****************\n";
		cout << "*************************1----����***********************\n";
		cout << "*************************2----��ѯ***********************\n";
		cout << "*************************3----ɾ��***********************\n";
		cout << "*************************4----����***********************\n";
		cout << "*************************0----�˳�***********************\n";
		cout << "*********************************************************\n";
		cout << "��ѡ��(0-4)";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "������ѧ��������";
			cin >> n;
			cout << "������ÿλѧ������Ϣ��";
			for (int i = 0; i < n; i++)
				cin >> st[i].no >> st[i].name >> st[i].sex >> st[i].age >> st[i].major;
			CreatList_Seq(List, st, n);
			cout << "ѧ����Ϣ���£�\n";
			Show_Seq(List);
			break;
		}
		case 2:
		{
			cout << "���������ѯѧ����ѧ�ţ�";
			cin >> n;
			int index = LocateElem_Seq(List, n);
			if (index == 0)
				cout << "û�д�ѧ�ŵ�ѧ��\n";
			else
				cout << List.data[index - 1].no << " " << List.data[index - 1].name << " " << List.data[index - 1].sex << " " << List.data[index - 1].age << " " << List.data[index - 1].major << endl;
			break;
		}
		case 3:
		{
			cout << "��������ɾ��ѧ����ѧ�ţ�";
			cin >> n;
			int index = LocateElem_Seq(List, n);
			if (index == 0)
				cout << "û�д�ѧ�ŵ�ѧ��\n";
			else
			{
				struct Student s;
				ListDelete_Seq(List, index, s);
				cout << "ɾ��ѧ����ϢΪ��" << s.no << " " << s.name << " " << s.sex << " " << s.age << " " << s.major << endl;
				cout << "ʣ��ѧ����ϢΪ��\n";
				Show_Seq(List);
			}
			break;
		}
		case 4:
		{
			struct Student s;
			cout << "�����������ѧ����ѧ�ţ�";
			cin >> s.no;
			cout << "�����������ѧ����������";
			cin >> s.name;
			cout << "�����������ѧ�����Ա�";
			cin >> s.sex;
			cout << "�����������ѧ�������䣺";
			cin >> s.age;
			cout << "�����������ѧ����רҵ��";
			cin >> s.major;
			ListInsert_Seq(List, List.length + 1, s);
			cout << "ѧ����Ϣ���£�\n";
			Show_Seq(List);
		}
		case 0:
			break;
		default:
			cout << "�������\n";
		}

	} while (choice);
	return 0;
}