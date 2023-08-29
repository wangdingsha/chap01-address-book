#include<iostream>
using namespace std;
#include<string>
#define MAX 1000

//�����ϵ�˽ṹ��
struct Person
{
	//����
	string m_Name;
	//�Ա�
	int m_Sex; 
	//����
	int m_Age;
	//�绰
	string m_Phone;  
	//סַ
	string m_Addr;
};

//���ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];
	//ͨѶ¼�е�ǰ��¼��ϵ�˸���  
	int m_Size;

};

//1.�����ϵ��
void addPerson(Addressbooks * abs)
{
	//�ж�ͨѶ¼�Ƿ�������������˾Ͳ������
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��

		//����
		string name;
		cout<< "������������ " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//�Ա�
		cout << "�������Ա� " << endl;
		cout << "1-----��" << endl;
		cout << "2------Ů" << endl;
		int sex = 0;
		while (true)
		{
			//����������1��2�����˳�ѭ������Ϊ���������ȷֵ
			//�������������Ӧ��������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}

		//����
		cout << "���������䣺 " << endl;
		int age = 0;
		while (true)
		{
			//��������ֵ����0�����˳�ѭ������Ϊ���������ȷֵ
			//�������������Ӧ��������
			cin >> age;
			if (age > 0)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		//�绰
		cout << "������绰�� " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//סַ
		cout << "�������ַ�� " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		
		//����ͨ��¼
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;

		system("pause");//�밴���������
		system("cls");  //��������

	}

}
void ShowPerson(Addressbooks * abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������ " << abs->personArray[i].m_Name << "\t";
			cout << "�Ա� " << (abs->personArray[i].m_Sex == 1 ? "��":"Ů") << "\t";
			cout << "���䣺 " << abs->personArray[i].m_Age << "\t";
			cout << "�绰�� " << abs->personArray[i].m_Phone << "\t";
			cout << "סַ�� " << abs->personArray[i].m_Addr << endl;
		}
		
	}
	system("pause");//�밴���������
	system("cls");  //��������

}

//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
//����1  ͨѶ¼  ����2  �Ա�����
int isExist(Addressbooks * abs,string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//�ҵ��û���������
		if (abs->personArray[i].m_Name == name)
		{
			return i;  //�ҵ��ˣ�����������������е��±�
		}
	}
	return -1; //�������������û���ҵ�������-1
}

//3.ɾ����ϵ��
void deletePerson(Addressbooks * abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void showMenu()
{
	cout << "*****************************" << endl;
	cout << "******  1�������ϵ��  ******" << endl;
	cout << "******  2����ʾ��ϵ��  ******" << endl;
	cout << "******  3��ɾ����ϵ��  ******" << endl;
	cout << "******  4��������ϵ��  ******" << endl;
	cout << "******  5���޸���ϵ��  ******" << endl;
	cout << "******  6�������ϵ��  ******" << endl;
	cout << "******  0���˳�ͨѶ¼  ******" << endl;
	cout << "*****************************" << endl;

}

int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;

	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select) 
		{
		case 1:  //1.�����ϵ��
			addPerson(&abs); //���õ�ַ���ݣ���������ʵ��
			break;
		case 2:   //2.��ʾ��ϵ��
			ShowPerson(&abs);
			break;
		case 3:   //3.ɾ����ϵ��
		/*{
			cout << "������ɾ����ϵ�˵�������" << endl;
			string name;
			cin >> name;
			
			if (isExist(&abs, name) == -1)
			{
				cout << "���޴���" << endl;
			}
			else
			{
				cout << "�ҵ�����" << endl;
			}
		}*/
			deletePerson(&abs);
			break;
		case 4:  //4��������ϵ��
			break;
		case 5:  //5���޸���ϵ��
			break;
		case 6:  //6�������ϵ��
			break;
		case 0:   //0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break; 
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}