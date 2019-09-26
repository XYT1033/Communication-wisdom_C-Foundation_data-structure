#pragma once
#include <string>
using namespace std;

class Reader{

	friend ostream& operator<<(ostream&out, Reader&anther);
	friend istream& operator>>(istream&in, Reader&anther);

public:
	Reader();
	int getnum();				 //��ȡ����ѧ�ź���
	string getgrade();		//��ȡ�����꼶����
	string getclas();	    	//��ȡ���߰༶����
	string getsex();			//��ȡ�����Ա���
	string getbook_name();	//��ȡ��������������
	string getdate();	        //��ȡ�������ں���
	string getname();         //��ȡ������������
	int  getavaiday();		//��ȡ�ɽ���������
	int setname(string); 		//���ö�����������
	int setnum(int);         //���ö���ѧ�ź���
	int setgrade(string);     //���ö����꼶����
	int setclas(string);      //���ö��߰༶����
	int setsex(string);	     //���ö����Ա���
	int setbook_name(string);	 //���������鼮��������
	int setdate(string);	     //���ý������ں���
	int setavaiday(int);	     //���ÿɽ���������
	void book_out();			//���麯��
	void book_in();			//���麯��

private:
	string name;                  //����
	int	   num;                  //ѧ��
	string grade;                 //�꼶
	string clas;                  //�༶
	string sex;                   //�Ա�
	string book_name;              //�����������
	string date;                   //��������
	int avai_days;                  //�ɽ�����
};

