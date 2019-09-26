#pragma once
#include <string>
#include <vector>
#include "Readers.h"
using namespace std;

class Books{

	friend ostream& operator<<(ostream&out, Books&anther);
	friend istream& operator>>(istream&in, Books&anther);

public:
	Books();			  //book�๹�캯��
	void set_id();		//�������
	string get_name();           //��ȡ����
	string get_writer();		  //��ȡ����
	vector<Reader>& get_vborrower();			  //��ȡ������
	int get_id();				 //��ȡ���
	int get_borr_num();			 //��ȡ������ѧ��
	int get_store();			 //��ȡ�ִ���
	int get_total();			 // ��ȡ�ܴ���
	string get_pub_time();		 //��ȡ����ʱ��
	float get_price();			//��ȡ�۸�
	string get_publish();		 //��ȡ������
private:
	string name;        //����
	string writer;      //����
	vector<Reader> vborrower;//������
	int id;            //���
	int store;         //�ִ���
	int total;         // �ܴ���
	string pub_time;   //����ʱ��
	float price;       //�۸�
	string publish;    //������

};