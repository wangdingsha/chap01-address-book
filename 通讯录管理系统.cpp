#include<iostream>
using namespace std;
#include<string>
#define MAX 1000

//设计联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//性别
	int m_Sex; 
	//年龄
	int m_Age;
	//电话
	string m_Phone;  
	//住址
	string m_Addr;
};

//设计通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];
	//通讯录中当前记录联系人个数  
	int m_Size;

};

//1.添加联系人
void addPerson(Addressbooks * abs)
{
	//判断通讯录是否已满，如果满了就不再添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//添加具体联系人

		//姓名
		string name;
		cout<< "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		cout << "请输入性别： " << endl;
		cout << "1-----男" << endl;
		cout << "2------女" << endl;
		int sex = 0;
		while (true)
		{
			//如果输入的是1或2可以退出循环，因为输出的是正确值
			//如果输入有误，则应重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}

		//年龄
		cout << "请输入年龄： " << endl;
		int age = 0;
		while (true)
		{
			//如果输入的值大于0可以退出循环，因为输出的是正确值
			//如果输入有误，则应重新输入
			cin >> age;
			if (age > 0)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		//电话
		cout << "请输入电话： " << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//住址
		cout << "请输入地址： " << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		
		//更新通信录
		abs->m_Size++;
		cout << "添加成功" << endl;

		system("pause");//请按任意键继续
		system("cls");  //清屏操作

	}

}
void ShowPerson(Addressbooks * abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名： " << abs->personArray[i].m_Name << "\t";
			cout << "性别： " << (abs->personArray[i].m_Sex == 1 ? "男":"女") << "\t";
			cout << "年龄： " << abs->personArray[i].m_Age << "\t";
			cout << "电话： " << abs->personArray[i].m_Phone << "\t";
			cout << "住址： " << abs->personArray[i].m_Addr << endl;
		}
		
	}
	system("pause");//请按任意键继续
	system("cls");  //清屏操作

}

//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
//参数1  通讯录  参数2  对比姓名
int isExist(Addressbooks * abs,string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//找到用户的姓名了
		if (abs->personArray[i].m_Name == name)
		{
			return i;  //找到了，返回这个人在数组中的下标
		}
	}
	return -1; //如果遍历结束都没有找到，返回-1
}

//3.删除联系人
void deletePerson(Addressbooks * abs)
{
	cout << "请输入你要删除的联系人" << endl;
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
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void showMenu()
{
	cout << "*****************************" << endl;
	cout << "******  1、添加联系人  ******" << endl;
	cout << "******  2、显示联系人  ******" << endl;
	cout << "******  3、删除联系人  ******" << endl;
	cout << "******  4、查找联系人  ******" << endl;
	cout << "******  5、修改联系人  ******" << endl;
	cout << "******  6、清空联系人  ******" << endl;
	cout << "******  0、退出通讯录  ******" << endl;
	cout << "*****************************" << endl;

}

int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始通讯录中当前人员个数
	abs.m_Size = 0;

	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select) 
		{
		case 1:  //1.添加联系人
			addPerson(&abs); //利用地址传递，可以修饰实参
			break;
		case 2:   //2.显示联系人
			ShowPerson(&abs);
			break;
		case 3:   //3.删除联系人
		/*{
			cout << "请输入删除联系人的姓名：" << endl;
			string name;
			cin >> name;
			
			if (isExist(&abs, name) == -1)
			{
				cout << "查无此人" << endl;
			}
			else
			{
				cout << "找到此人" << endl;
			}
		}*/
			deletePerson(&abs);
			break;
		case 4:  //4、查找联系人
			break;
		case 5:  //5、修改联系人
			break;
		case 6:  //6、清空联系人
			break;
		case 0:   //0、退出通讯录
			cout << "欢迎下次使用" << endl;
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