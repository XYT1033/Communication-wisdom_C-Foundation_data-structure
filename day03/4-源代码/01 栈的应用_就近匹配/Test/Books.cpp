#include "Books.h"
#include <iostream>
#include <vector>
using namespace std;

Books::Books()    //book�๹�캯��
{
	this->name = "book";
	this->writer = "writer";
	//this->vborrower;
	this->id = 0;
	this->store = 0;
	this->total = 0;
	this->pub_time = "pub_time";
	this->price = 0.0;
	this->publish = "publish";
}

void  Books::set_id()		//�������
{
	cout << "�������鼮��ţ��鼮��Ŵ�10001���Ҳ��ܺ������鼮�غţ���" << endl;
}
string Books::get_name()           //��ȡ����
{
	return name;
}
string Books::get_writer()		  //��ȡ����
{
	return writer;
}

vector<Reader>& Books::get_vborrower()			  //��ȡ������
{
	return vborrower;
}

int Books::get_id()				 //��ȡ���
{
	return id;
}

int Books::get_store()			 //��ȡ�ִ���
{
	return store;
}
int Books::get_total()			 // ��ȡ�ܴ���
{
	return total;
}
string Books::get_pub_time()		 //��ȡ����ʱ��
{
	return pub_time;
}
float  Books::get_price()	//��ȡ�۸�
{
	return price;
}
string Books::get_publish()		 //��ȡ������
{
	return publish;
}

ostream& operator<<(ostream&out, Books&anther)
{

	cout << "������" << anther.name;
	cout << "���ߣ�" << anther.writer;
	cout << "��ţ�" << anther.id;
	cout << "�ִ�����" << anther.store;
	cout << "��������" << anther.total;
	cout << "����ʱ�䣺" << anther.pub_time;
	cout << "�۸�" << anther.price;
	cout << "�����磺" << anther.publish;
	if (anther.total - anther.store > 0)
	{
		for (int i = 0; i < anther.total - anther.store; i++)
			cout << "�������" << i << "��" << anther.vborrower[i];
	}
	return out;
}

istream& operator>>(istream&in, Books&anther)
{

	cout << "������������" << endl; cin >> anther.name;
	cout << "���������ߣ�" << endl; 	cin >> anther.writer;
	//cout << "�������鼮��ţ�" << endl;	cin >> anther.id;
	cout << "����������磺" << endl;	cin >> anther.store;
	cout << "�����뱾����������" << endl;	cin >> anther.total;
	cout << "���������ʱ�䣺" << endl;	cin >> anther.pub_time;
	cout << "�����뱾��۸�" << endl; cin >> anther.price;
	cout << "����������磺" << endl; cin >> anther.publish;
	if (anther.total - anther.store > 0)
	{
		for (int i = 0; i < anther.total - anther.store; i++)
		{
			cout << "�������" << i << "��������ߣ�" << endl;
			cin >> anther.vborrower[i];
		}
	}
	return in;
}
