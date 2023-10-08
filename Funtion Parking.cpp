#include "Funtion Paking.h"
#include"Vehicle Management.h"
#include"User management.h" 
Funtion::Funtion() {

}

void Funtion::Vehicle_F() {
	Vehicle_Management v;
	char choice;
	char ans;
	system("cls");

	do
	{
		system("cls");
		cout << "********************************************************************" << endl;
		cout << "                          QUAN LY XE                " << endl;
		cout << "\n\t\t   [1]: Them xe vao " << endl
			<< "\n\t\t   [2]: Bang hien thi thong tin " << endl
			<< "\n\t\t   [3]: Chinh sua thong tin " << endl
			<< "\n\t\t   [4]: Xoa xe  " << endl
			<< "\n\t\t   [5]: Thoat " << endl
			<< "\n********************************************************************" << endl
			<< "Nhap tuy chon  : ";
		cin >> choice;

		switch (choice)
		{
			//trong bảng ascii thì 1 - 9 được kí hiệu từ 49 - 57
		case 49: system("cls"); // 1
			cout << "\t\t\t              THEM XE              " << endl;
			v.Add();
			break;

		case 50:system("cls"); // 2
			cout << "\t\t\t          BANG THONG TIN XE GUI             " << endl;
			v.Print();
			break;

		case 51: system("cls");//3
			cout << "\t\t\t               CHINH SUA             " << endl;
			v.Print();
			v.Edit();
			break;
		case 52: system("cls");//4
			cout << "\t\t\t                XOA XE              " << endl;
			v.Print();
			v.Remove();
			break;
		case 53: //5
			Manager_Fution();
		}

		cout << "\nBan co muon tiep tuc khong \n ([co] : phim bat ki | [khong] : n ) :  ";
		cin >> ans;
		if (ans == 'n')
		{
			break;
		}
		else
		{
			continue;
		}

	} while (1);
	system("pause");
}

void Funtion::User_F() {
	User_Management u;
	char choice;
	char ans;
	do
	{
		system("cls");
		cout << "********************************************************************" << endl;
		cout << "                          QUAN LY NGUOI DUNG                " << endl;
		cout << "\n\t\t   [1]: Them Nguoi Dung " << endl
			<< "\n\t\t   [2]: Bang Thong Tin Nguoi Dung" << endl
			<< "\n\t\t   [3]: Chinh sua thong tin " << endl
			<< "\n\t\t   [4]: Xoa Nguoi Dung  " << endl
			<< "\n\t\t   [5]: Thoat " << endl
			<< "\n********************************************************************" << endl
			<< "Nhap tuy chon  : ";
		cin >> choice;

		switch (choice)
		{
			//trong bảng ascii thì 1 - 9 được kí hiệu từ 49 - 57
		case 49: system("cls"); // 1
			cout << "\t\t\t              Them Nguoi Dung             " << endl;
			u.Add();
			break;

		case 50:system("cls"); // 2
			cout << "\t\t\t          BANG THONG TIN XE GUI             " << endl;
			u.Print();
			break;

		case 51: system("cls");//3
			cout << "\t\t\t               CHINH SUA             " << endl;
			u.Print();
			u.Replace();
			break;
		case 52: system("cls");//4
			cout << "\t\t\t                XOA XE              " << endl;
			u.Print();
			u.Remove();
			break;
		case 53: //5
			Manager_Fution();
		}

		cout << "\nBan co muon tiep tuc khong \n ([co] : phim bat ki | [khong] : n ) :  ";
		cin >> ans;
		if (ans == 'n')
		{
			break;
		}
		else
		{
			continue;
		}

	} while (1);
	system("pause");
}

void Funtion::Manager_Fution() {
	char choose;
	char ans;
	
		do
		{
			system("cls");
			cout << "********************************************************************" << endl;
			cout << "                        HE THONG QUAN LY GUI XE                " << endl;
			cout <<"\n\t\t   [1]: Quan Ly Nguoi Dung " << endl
				<< "\n\t\t   [2]: Quan Ly Xe" << endl
				<< "\n\t\t   [3]: Thoat " << endl
				<< "\n********************************************************************" << endl
				<< "Nhap tuy chon  : ";
			cin >> choose;

			switch (choose)
			{

			case 49: system("cls"); // 1

				User_F();
				break;
			case 50:system("cls"); // 2
				Vehicle_F();
				break;
			case 51:;//3
				exit(0);

			}
		} while (1);

	system("pause");
}
