#include<iostream>
#include<string>
using namespace std;
#include "Readers.h"

Reader::Reader()
{

}

int Reader::getnum()			 //��ȡ����ѧ�ź���
{
	return num;
}
string Reader::getgrade()	//��ȡ�����꼶����
{
	return grade;
}
string Reader::getclas()	    	//��ȡ���߰༶����
{
	return clas;
}
string Reader::getsex()			//��ȡ�����Ա���
{
	return sex;
}
string Reader::getbook_name()	//��ȡ��������������
{
	return book_name;
}
string Reader::getdate()	        //��ȡ�������ں���
{
	return date;
}
string Reader::getname()         //��ȡ������������
{
	return name;
}
int Reader::getavaiday()		//��ȡ�ɽ���������
{
	return avai_days;
}
int Reader::setname(string)		//���ö�����������
{
	cout << "���������������" << endl;
	cin >> this->name;
	return 0;
}
int Reader::setnum(int)         //���ö���ѧ�ź���
{
	cout << "��������ߵ�ѧ�ţ�ѧ�Ŵ�10001���Ҳ��ܺ����ж���ѧ����ͬ����" << endl;
	cin >> this->num;
	return 0;
}
int Reader::setgrade(string)     //���ö����꼶����
{
	cout << "����������꼶��" << endl;
	cin >> this->grade;
	return 0;
}
int Reader::setclas(string)      //���ö��߰༶����
{
	cout << "��������߰༶��" << endl;
	cin >> this->clas;
	return 0;
}
int Reader::setsex(string)	     //���ö����Ա���
{
	cout << "����������Ա�" << endl;
	cin >> this->sex;
	return 0;
}
int Reader::setbook_name(string)	 //���������鼮��������
{
	cout << "�������������������" << endl;
	cin >> this->book_name;
	return 0;
}
int Reader::setdate(string)	     //���ý������ں���
{
	cout << "��������߽������ڣ�" << endl;
	cin >> this->date;
	return 0;
}
int Reader::setavaiday(int)	     //���ÿɽ���������
{
	cout << "��������߿ɽ�������" << endl;
	cin >> this->clas;
	return 0;
}
void Reader::book_out()			//���麯��
{

}
void Reader::book_in()			//���麯��
{

}
ostream& operator<<(ostream&out, Reader&anther)
{

	cout << "����������" << anther.name << endl;
	cout << "����ѧ��" << anther.num << endl;
	cout << "�����꼶" << anther.grade << endl;
	cout << "���߰༶" << anther.clas << endl;
	cout << "�����Ա�" << anther.sex << endl;
	if (anther.book_name != "δ����")
	{
		cout << "������������" << anther.book_name << endl;
		cout << "���߽�������" << anther.date << endl;
		cout << "���߿ɽ�����" << anther.avai_days << endl;
	}

	return out;
}
istream& operator>>(istream&in, Reader& anther)
{
	cout << "���������������" << endl;
	cin >> anther.name;
	cout << "����������꼶��" << endl;
	cin >> anther.grade;
	cout << "��������߰༶��" << endl;
	cin >> anther.clas;
	cout << "����������Ա�" << endl;
	cin >> anther.sex;
	return in;
}