#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <Windows.h>
#include <bits/stdc++.h>
using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
void main_menu();
void shopper_menu(bool);
void customer_menu();
void restaurant_menu(int);
void orderList_customer();
void orderList_shopper();
void payment();
void newOrder();
void position (int x, int y);
void newOrder();
void confirm();
string foods[11][5];
int max_time=0;
int x=0;
struct order{
	string customer;
	int catID;
	int subCatID;
	int timeReady;
	int totalCost;
	bool is_ready = false;
	bool is_payemnt = false;
	string order_list;
};
struct order orders[100];
string customer_orders[100][10];

int main(){
	system("cls");
	std::ofstream ofs;
	ofs.open("orders list/orders.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	ifstream allFoods("restaurant menu/all_List.txt");
	for(int row = 0; row < 11; row++) {
	   for(int column = 0; column < 5; column++){
	        allFoods >> foods[row][column];
	    }
	}
	allFoods.close();
	main_menu();
	
    return 0;
}
void main_menu(){
	while(true){
		system("cls");
		int option;
		SetConsoleTextAttribute(h, 0x06);
		cout << " \t\t\t\t\t\t Welcome To Restaurant \n";
		SetConsoleTextAttribute(h, 0x0A);
		cout << "Main Menu \n**********************\n";
		SetConsoleTextAttribute(h, 0x0f);
		cout<<"1.Shopper Menu\n";
		cout<<"2.Customer Menu\n";
		cout<<"3.Restaurant list\n";
		cout<<"4.exit\n";
		
		cin>>option;
		if(option==1){
			system("cls");
			shopper_menu(false);
			break;
		}
		else if(option==2){
			system("cls");
			customer_menu();
			break;
		}
		else if(option==3){
			system("cls");
			restaurant_menu(1);
			break;
		}
		else if(option==4){
			system("cls");
			string status;
			bool loop=true;
			while(true){
				cout << "Are Sure ? Y/N : ";
				cin >> status;
				if(status=="Y" || status=="y"){
					system("cls");
					cout<<"Good Bye";
					//system("cls");
					loop=false;
					exit(0);
					break;
				}
				else if(status=="N" || status=="n"){
					system("cls");
					loop=true;
					break;
				}
				else{
					system("cls");
					cout << "Wrong Anwser \n\n";
					continue;
					
				}
			}
			if(loop==true){
				system("cls");
				continue;
			}
			else{
				cout<<"\n";
				getch();
				break;
			}
		}
		else{
			system("cls");
			cout << "OPS!!! please Select Current Option \n";
			continue;
		}
	}
}
void shopper_menu(bool IS_LOGIN){
	string administrator;
	int password;
	if(IS_LOGIN==true){
		while(true){
			int option;
			SetConsoleTextAttribute(h, 0x0A);
			cout << "Shopper Menu \n**********************\n";
			SetConsoleTextAttribute(h, 0x0f);
			//cout<<"1.List Of Customers\n";
			cout<<"1.List Of Restaurant Food\n";
			cout<<"2.List Of Orders\n";
			cout<<"3.Confirm Orders\n";
			cout<<"0.Back\n";
			cin>>option;
			if(option==1){
				system("cls");
				restaurant_menu(2);
				break;
			}
			else if(option==2){
				system("cls");
				orderList_shopper();
				break;
			}
			else if(option==3){
				system("cls");
				confirm();
				break;
			}
			else if(option==4){
				system("cls");
				//restaurant_menu(2);
				break;
			}
			else if(option==0){
				system("cls");
				main_menu();
				break;
			}
			else{
				system("cls");
				cout << "OPS!!! please Select Current Option \n";
				continue;
			}
		}
	}
	else{
		cout << "Administrator username : ";
		cin >> administrator;
		cout << "Administrator Passwrod : ";
		cin >> password;
		if(administrator=="admin" && password==123){
			system("cls");
			while(true){
				int option;
				SetConsoleTextAttribute(h, 0x0A);
				cout << "Shopper Menu \n**********************\n";
				SetConsoleTextAttribute(h, 0x0f);
				//cout<<"1.List Of Customers\n";
				cout<<"1.List Of Restaurant Food\n";
				cout<<"2.List Of Orders\n";
				cout<<"3.Confirm Orders\n";
				cout<<"0.Back\n";
				cin>>option;
				if(option==1){
					system("cls");
					restaurant_menu(2);
					break;
				}
				else if(option==2){
					system("cls");
					orderList_shopper();
					break;
				}
				else if(option==3){
					system("cls");
					confirm();
					break;
				}
				else if(option==4){
					system("cls");
					//restaurant_menu(2);
					break;
				}
				else if(option==0){
					system("cls");
					main_menu();
					break;
				}
				else{
					system("cls");
					cout << "OPS!!! please Select Current Option \n";
					IS_LOGIN = true;
					continue;
				}
			}	
		}
		else{
			cout<<"OPS !! Wrong Authentication , please try again \n\n";
			shopper_menu(false);
		}
	}	
	
}
void customer_menu(){
	while(true){
		int option;
		SetConsoleTextAttribute(h, 0x0A);
		cout << "Customer Menu \n**********************\n";
		SetConsoleTextAttribute(h, 0x0f);
		cout<<"1.New Order\n";
		cout<<"2.Restaurant list\n";
		cout<<"3.Order list\n";
		cout<<"4.payment\n";
		cout<<"0.back\n";
		
		cin>>option;
		if(option==1){
			system("cls");
			newOrder();
			break;
		}
		else if(option==2){
			system("cls");
			restaurant_menu(3);
		}
		else if(option==3){
			system("cls");
			orderList_customer();
			break;
		}
		else if(option==4){
			system("cls");
			payment();
			break;
		}
		else if(option==0){
			system("cls");
			main_menu();
			break;
		}
		else{
			system("cls");
			cout << "OPS!!! please Select Current Option \n";
			continue;
		}
	}
}
void restaurant_menu(int come_from){
	while(true){
		int option;
		SetConsoleTextAttribute(h, 0x0A);
		cout << "restaurant Menu \n**********************\n";
		SetConsoleTextAttribute(h, 0x0f);
		cout<<"1.Drinks menu\t";
		cout<<"2.Kebab menu\t";
		cout<<"3.Fast food menu\t";
		cout<<"4.Rice menu\t";
		cout<<"0.back\t\n";
		cout << "**************************************************************\n";
		ifstream category_menu("restaurant menu/category_List.txt");
	    if (category_menu.is_open()){
		
	        cout << category_menu.rdbuf();
		}
		category_menu.close();
		
		cin>>option;
		if(option==1){
			system("cls");
			int back;
			SetConsoleTextAttribute(h, 0x0A);
			cout << "Restaurant Drink Menu \n**********************\n";
			SetConsoleTextAttribute(h, 0x0f);
			ifstream drink_menu("restaurant menu/drink_List.txt");
		    if (drink_menu.is_open()){
		        cout << drink_menu.rdbuf();
			}
			drink_menu.close();
			cout<<"0.back\t\n";
			while(true){
				cin >> back;
				if(back==0){
					system("cls");
					restaurant_menu(come_from);
					break;
				}
				else{
					cout << "OPS !! wrong Anwser , Please Select Current Option\n";
					continue;
				}
			}
		}
		else if(option==2){
			system("cls");
			int back;
			SetConsoleTextAttribute(h, 0x0A);
			cout << "Restaurant Kebab Menu \n**********************\n";
			SetConsoleTextAttribute(h, 0x0f);
			ifstream kebab_menu("restaurant menu/kebab_List.txt");
		    if (kebab_menu.is_open()){
		        cout << kebab_menu.rdbuf();
			}
			kebab_menu.close();
			cout<<"0.back\t\n";
			while(true){
				cin >> back;
				if(back==0){
					system("cls");
					restaurant_menu(come_from);
					break;
				}
				else{
					cout << "OPS !! wrong Anwser , Please Select Current Option\n";
					continue;
				}
			}
		}
		else if(option==3){
			system("cls");
			int back;
			SetConsoleTextAttribute(h, 0x0A);
			cout << "Restaurant Fast Food Menu \n**********************\n";
			SetConsoleTextAttribute(h, 0x0f);
			ifstream fastfood_menu("restaurant menu/fastfood_List.txt");
		    if (fastfood_menu.is_open()){
		        cout << fastfood_menu.rdbuf();
			}
			fastfood_menu.close();
			cout<<"0.back\t\n";
			while(true){
				cin >> back;
				if(back==0){
					system("cls");
					restaurant_menu(come_from);
					break;
				}
				else{
					cout << "OPS !! wrong Anwser , Please Select Current Option\n";
					continue;
				}
			}
		}
		else if(option==4){
			system("cls");
			int back;
			SetConsoleTextAttribute(h, 0x0A);
			cout << "Restaurant Rice Menu \n**********************\n";
			SetConsoleTextAttribute(h, 0x0f);
			ifstream rice_menu("restaurant menu/rice_List.txt");
		    if (rice_menu.is_open()){
		        cout << rice_menu.rdbuf();
		    }
			rice_menu.close();
			cout<<"0.back\t\n";
			while(true){
				cin >> back;
				if(back==0){
					system("cls");
					restaurant_menu(come_from);
					break;
				}
				else{
					cout << "OPS !! wrong Anwser , Please Select Current Option\n";
					continue;
				}
			}
		}
		else if(option==0){
			system("cls");
			if(come_from==1){
				main_menu();
				break;
			}
			else if(come_from==2){
				shopper_menu(true);
				break;
			}
			else if(come_from==3){
				customer_menu();
				break;
			}
		}
		else{
			system("cls");
			cout << "OPS!!! please Select Current Option \n";
			continue;
		}
	}	
}
void newOrder(){
	std::ofstream ofs;
	ofs.open("orders list/orders.txt", ios::app);	
	system("cls");
	string customer;
	SetConsoleTextAttribute(h, 0x0A);
	cout << "New Order \n____________\n\n";
	SetConsoleTextAttribute(h, 0x0f);
	cout << "Enter Your Name : ";
	cin >> customer;
	system("cls");
	while(true){
		int option;
		SetConsoleTextAttribute(h, 0x0A);
		cout << "restaurant Menu \n**********************\n";
		SetConsoleTextAttribute(h, 0x0f);
		cout<<"1.Drinks menu\t";
		cout<<"2.Kebab menu\t";
		cout<<"3.Fast food menu\t";
		cout<<"4.Rice menu\t";
		cout<<"0.back\t\n";
		cout << "**************************************************************\n";
		ifstream category_menu("restaurant menu/category_List.txt");
	    if (category_menu.is_open()){
		
	        cout << category_menu.rdbuf();
		}
		category_menu.close();
		cin>>option;
		if(option==1){
			system("cls");
			int id;
			int catID = option;
			SetConsoleTextAttribute(h, 0x0A);
			cout << "Restaurant Drink Menu \n**********************\n";
			SetConsoleTextAttribute(h, 0x0f);
			ifstream drink_menu("restaurant menu/drink_List.txt");
		    if (drink_menu.is_open()){
		        cout << drink_menu.rdbuf();
			}
			drink_menu.close();
			cout<<"1.Dogh \t\t 2.Noshabe \t\t 3.Water\t\t 0.back\n";
			while(true){
				cout << "Please Select Your Favorite Drink : ";
				cin >> id;
				if(id==0){
					system("cls");
					break;
				}
				else if(id==1){
					ofs << customer << " ";
					ofs << foods[0][0] << " ";
					ofs << foods[0][1] << " ";
					ofs << foods[0][2] << " ";
					ofs << foods[0][3] << " ";
					ofs << false << " ";
					ofs << false << " ";
					ofs << foods[0][4] << " ";
					ofs << foods[0][4] << " " << endl;
					x = x + 1;
					continue;
				}
				else if(id==2){
					ofs << customer << " ";
					ofs << foods[1][0] << " ";
					ofs << foods[1][1] << " ";
					ofs << foods[1][2] << " ";
					ofs << foods[1][3] << " ";
					ofs << false << " ";
					ofs << false << " ";
					ofs << foods[1][4] << " ";
					ofs << foods[1][4] << " " << endl;
					x = x + 1;
					continue;
				}
				else if(id==3){
					ofs << customer << " ";
					ofs << foods[2][0] << " ";
					ofs << foods[2][1] << " ";
					ofs << foods[2][2] << " ";
					ofs << foods[2][3] << " ";
					ofs << false << " ";
					ofs << false << " ";
					ofs << foods[2][4] << " ";
					ofs << foods[2][4] << " " << endl;
					x = x + 1;
					continue;
				}
				else{
					cout << "OPS !! wrong Anwser , Please Select Current Option\n";
					continue;
				}
			}
		}
		else if(option==2){
			system("cls");
			int id;
			int catID = option;
			SetConsoleTextAttribute(h, 0x0A);
			cout << "Restaurant Kebab Menu \n**********************\n";
			SetConsoleTextAttribute(h, 0x0f);
			ifstream kebab_menu("restaurant menu/kebab_List.txt");
		    if (kebab_menu.is_open()){
		        cout << kebab_menu.rdbuf();
			}
			kebab_menu.close();
			cout<<"1.kobide \t\t 2.joje \t\t 3.chenje\t\t 0.back\n";
			while(true){
				cout << "Please Select Your Favorite Kebab : ";
				cin >> id;
				if(id==0){
					system("cls");
					break;
				}
				else if(id==1){
					ofs << customer << " ";
					ofs << foods[3][0] << " ";
					ofs << foods[3][1] << " ";
					ofs << foods[3][2] << " ";
					ofs << foods[3][3] << " ";
					ofs << false << " ";
					ofs << false << " ";
					ofs << foods[3][4] << " " ;
					ofs << foods[3][4] << " " << endl;
					x = x + 1;
					continue;
				}
				else if(id==2){
					ofs << customer << " ";
					ofs << foods[4][0] << " ";
					ofs << foods[4][1] << " ";
					ofs << foods[4][2] << " ";
					ofs << foods[4][3] << " ";
					ofs << false << " ";
					ofs << false << " ";
					ofs << foods[4][4] << " ";
					ofs << foods[4][4] << " " << endl;
					x = x + 1;
					continue;
				}
				else if(id==3){
					ofs << customer << " ";
					ofs << foods[5][0] << " ";
					ofs << foods[5][1] << " ";
					ofs << foods[5][2] << " ";
					ofs << foods[5][3] << " ";
					ofs << false << " ";
					ofs << false << " ";
					ofs << foods[5][4] << " ";
					ofs << foods[5][4] << " " << endl;
					x = x + 1;
					continue;
				}
				else{
					cout << "OPS !! wrong Anwser , Please Select Current Option\n";
					continue;
				}
			}
		}
		else if(option==3){
			system("cls");
			int id;
			int catID = option;
			SetConsoleTextAttribute(h, 0x0A);
			cout << "Restaurant Fast Food Menu \n**********************\n";
			SetConsoleTextAttribute(h, 0x0f);
			ifstream fastfood_menu("restaurant menu/fastfood_List.txt");
		    if (fastfood_menu.is_open()){
		        cout << fastfood_menu.rdbuf();
			}
			fastfood_menu.close();
			cout<<"1.pizza \t\t 2.Hanberger \t\t 3.Sandwich\t\t 0.back\n";
			while(true){
				cout << "Please Select Your Favorite Fast Food : ";
				cin >> id;
				if(id==0){
					system("cls");
					break;
				}
				else if(id==1){
					ofs << customer << " ";
					ofs << foods[6][0] << " ";
					ofs << foods[6][1] << " ";
					ofs << foods[6][2] << " ";
					ofs << foods[6][3] << " ";
					ofs << false << " ";
					ofs << false << " ";
					ofs << foods[6][4] << " ";
					ofs << foods[6][4] << " " << endl;
					x = x + 1;
					continue;
				}
				else if(id==2){
					ofs << customer << " ";
					ofs << foods[7][0] << " ";
					ofs << foods[7][1] << " ";
					ofs << foods[7][2] << " ";
					ofs << foods[7][3] << " ";
					ofs << false << " ";
					ofs << false << " ";
					ofs << foods[7][4] << " ";
					ofs << foods[7][4] << " " << endl;
					x = x + 1;
					continue;
				}
				else if(id==3){
					ofs << customer << " ";
					ofs << foods[8][0] << " ";
					ofs << foods[8][1] << " ";
					ofs << foods[8][2] << " ";
					ofs << foods[8][3] << " ";
					ofs << false << " ";
					ofs << false << " ";
					ofs << foods[8][4] << " ";
					ofs << foods[8][4] << " " << endl;
					x = x + 1;
					continue;
				}
				else{
					cout << "OPS !! wrong Anwser , Please Select Current Option\n";
					continue;
				}
			}
		}
		else if(option==4){
			system("cls");
			int id;
			int catID = option;
			SetConsoleTextAttribute(h, 0x0A);
			cout << "Restaurant Rice Menu \n**********************\n";
			SetConsoleTextAttribute(h, 0x0f);
			ifstream rice_menu("restaurant menu/rice_List.txt");
		    if (rice_menu.is_open()){
		        cout << rice_menu.rdbuf();
		    }
			rice_menu.close();
			cout<<"1.tarem \t\t 2.shirodi \t\t 0.back\n";
			while(true){
				cout << "Please Select Your Favorite Rice : ";
				cin >> id;
				if(id==0){
					system("cls");
					break;
				}
				else if(id==1){
					ofs << customer << " ";
					ofs << foods[9][0] << " ";
					ofs << foods[9][1] << " ";
					ofs << foods[9][2] << " ";
					ofs << foods[9][3] << " ";
					ofs << false << " ";
					ofs << false << " ";
					ofs << foods[9][4] << " ";
					ofs << foods[9][4] << " " << endl;
					x = x + 1;
					continue;
				}
				else if(id==2){
					ofs << customer << " ";
					ofs << foods[10][0] << " ";
					ofs << foods[10][1] << " ";
					ofs << foods[10][2] << " ";
					ofs << foods[10][3] << " ";
					ofs << false << " ";
					ofs << false << " ";
					ofs << foods[10][4] << " ";
					ofs << foods[10][4] << " " << endl;
					x = x + 1;
					continue;
				}
				else{
					cout << "OPS !! wrong Anwser , Please Select Current Option\n";
					continue;
				}
			}
		}
		else if(option==0){
			system("cls");
			customer_menu();
			break;
		}
		else{
			system("cls");
			cout << "OPS!!! please Select Current Option \n";
			continue;
		}
	}
	ofs.close();
}
void orderList_shopper(){
	system("cls");
	string all_orders[100][8];
	bool loop=true;
	bool is_Paid;
	bool is_Ready;
	int option;
	while(true){
		ifstream orders("orders list/orders.txt");
		for(int row = 0; row < x; row++) {
	   	    for(int col = 0; col <= 8; col++){
		   		orders >> all_orders[row][col];
		   		//cout << all_orders[row][col]<<" ";
		    }
		    //cout<<"\n";
		}
		orders.close();
		if(loop==true){
			SetConsoleTextAttribute(h, 0x0A);
			cout << "Orders List For Shopper \n**********************\n";
			SetConsoleTextAttribute(h, 0x0f);
			int row = 0;
			int col = 0;
			cout <<"\n___________________________________________________________________\n";
			cout <<"\n name \t\t foods \t\t\t\t paid status \n";
			cout <<"___________________________________________________________________\n";
			for(int row = 0; row < x-1; row++) {
		   	    cout<<" \n "<< all_orders[row][0]<<" \t\t "<<all_orders[row][3] << " \t\t\t ";
		   	    if(all_orders[row][5]=="0"){
		   	    	cout<<"Not Paid";
				}
				else{
					cout<<"Paid";
				}
		   	    cout <<"\n___________________________________________________________________\n";
			}
			cout << "\n 1.All Orders      2.order by Paid      0.back\n";
			cout << "Please Enter An Option: ";
		}
		cin >> option;
		
		if(option==0){
			system("cls");
			loop=false;
			shopper_menu(true);
			break;
		}
		else if(option==1){
			loop=false;
			system("cls");
			SetConsoleTextAttribute(h, 0x0A);
			cout << "Orders List For Shopper \n**********************\n";
			SetConsoleTextAttribute(h, 0x0f);
			cout <<"\n___________________________________________________________________\n";
			cout <<"\n name \t\t foods \t\t\t\t paid status \n";
			cout <<"___________________________________________________________________\n";
			for(int row = 0; row < x-1; row++) {
		   	    cout<<" \n "<< all_orders[row][0]<<" \t\t "<<all_orders[row][3] << " \t\t\t ";
		   	    if(all_orders[row][5]=="0"){
		   	    	cout<<"Not Paid";
				}
				else{
					cout<<"Paid";
				}
		   	    cout <<"\n___________________________________________________________________\n";
			}
			cout << "\n 1.All Orders      2.order by Paid      0.back\n";
			cout << "Please Enter An Option: ";
		}
		else if(option==2){
			loop=false;
			system("cls");
			SetConsoleTextAttribute(h, 0x0A);
			cout << "Orders List For Shopper \n**********************\n";
			SetConsoleTextAttribute(h, 0x0f);
			cout <<"\n___________________________________________________________________\n";
			cout <<"\n name \t\t foods \t\t\t\t paid status \n";
			cout <<"___________________________________________________________________\n";
			for(int row = 0; row < x-1; row++) {
		   	    if(all_orders[row][5]=="1"){
		   	    	cout<<" \n "<< all_orders[row][0]<<" \t\t "<<all_orders[row][3] << " \t\t\t ";
					cout<<"Paid";
			   	    cout <<"\n___________________________________________________________________\n";	
				}
			}
			for(int row = 0; row < x-1; row++) {
		   	    if(all_orders[row][5]=="0"){
		   	    	cout<<" \n "<< all_orders[row][0]<<" \t\t "<<all_orders[row][3] << " \t\t\t ";
					cout<<"Not Paid";
			   	    cout <<"\n___________________________________________________________________\n";	
				}
			}
			cout << "\n 1.All Orders      2.order by Paid      0.back\n";
			cout << "Please Enter An Option: ";
		}
		else{
			system("cls");
			cout << "OPS!!! please Select Current Option \n";
			continue;
		}
	}
}               
void orderList_customer(){
	string name;
	cout << "Please Enter Your Name : ";
	cin >> name;
	string all_orders[100][8];
	string orders_foods[100];
	bool is_Paid;
	bool is_Ready;
	int time_temp;
	int max_time = 0;
	int totallCost = 0;
	int row = 0;
	int col = 0;
	ifstream orders("orders list/orders.txt");
	for(int row = 0; row < 100; row++) {
   	    for(int col = 0; col <= 8; col++){
	   		orders >> all_orders[row][col];
	   		//cout << all_orders[row][col] << " ";
	    }
	}
	orders.close();
	system("cls");
	SetConsoleTextAttribute(h, 0x0A);
	cout << "Customer Orders List \n**********************\n";
	SetConsoleTextAttribute(h, 0x0f);
	cout <<"\n___________________________________________________\n\n";
	cout << "Name : "<< "\t\t\t" <<name;
	cout <<"\n___________________________________________________\n\n";
	cout << "Orders : "<< "\t\t";
	for(int i=0;i<100;i++){
		if(all_orders[i][0]==name){
			
			orders_foods[i] = all_orders[i][3];
			cout << orders_foods[i]<<" ";
			totallCost = totallCost + stoi(all_orders[i][4]);
			if(all_orders[i][5]=="0"){
				is_Paid = false;
			}
			else{
				is_Paid = true;
			}
			if(all_orders[i][6]=="0"){
				is_Ready = false;
			}
			else{
				is_Ready = true;
			}
			
			if(max_time<stoi(all_orders[i][7])){
				max_time = stoi(all_orders[i][7]);
			}
		}
	}
	cout <<"\n___________________________________________________\n\n";
	cout << "Total Cost : "<< "\t\t" << totallCost << " T";
	cout <<"\n___________________________________________________\n\n";
	cout << "Paid status : "<< "\t\t";
	if(is_Paid == false){
		cout << "No Paid";
	}
	else{
		cout << "Paid";
	}
	cout <<"\n___________________________________________________\n\n";
	cout << "Orders status : \t";
	if(is_Ready == false){
		cout << "No Ready";
	}
	else{
		cout << "Ready";
	}
	cout <<"\n___________________________________________________\n\n";
	cout << "Time To Ready : \t" << max_time <<" min";
	cout <<"\n___________________________________________________\n";
	int exit;
	cin>>exit;
	if(exit==0){
		system("cls");
		customer_menu();
	}
}
void payment(){
	system("cls");
	string name;
	cout << "Please Enter Your Name : ";
	cin >> name;
	system("cls");
	int row = 0;
	int col = 0;
	string all_orders[100][8];
	ifstream orders("orders list/orders.txt");
	for(int row = 0; row < x-1; row++) {
   	    for(int col = 0; col <= 8; col++){
	   		orders >> all_orders[row][col];
	   		//cout << all_orders[row][col] << " ";
	    }
	    //cout<<endl;
	}
	orders.close();
	for(int i=0;i<x-1;i++){
		if(all_orders[i][0]==name){
			all_orders[i][5]="1";
		}
	}
	std::ofstream ofs;
	ofs.open("orders list/orders.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	std::ofstream ofs1;
	ofs1.open("orders list/orders.txt");
	for(int row = 0; row < x-1; row++) {
   	    for(int col = 0; col <= 8; col++){
	   	    ofs1 << all_orders[row][col] << " ";
	    }
	    ofs1 << "\n";
	}
	ofs1.close();
		SetConsoleTextAttribute(h, 0x0A);
	cout << "\n\n\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * *  \n";
	cout << "\t\t\t*\t\t\t\t\t\t*\n";
	cout << "\t\t\t*\t\t\t\t\t\t*\n";
	cout << "\t\t\t* you paid thanks, please wait ready your order *\n";
	cout << "\t\t\t*\t\t\t\t\t\t*\n";
	cout << "\t\t\t*\t\t\t\t\t\t*\n";
	cout << "\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * *  \n\n";
	
	SetConsoleTextAttribute(h, 0x0f);
	int exit;
	cin >> exit;
	if(exit==0){
		system("cls");
		customer_menu();
	}
//	ofs.close();
}
void confirm(){
	system("cls");
	string all_orders[100][8];
	bool loop=true;
	bool is_Paid;
	bool is_Ready;
	string option;
	while(true){
		ifstream orders("orders list/orders.txt");
		for(int row = 0; row < x; row++) {
	   	    for(int col = 0; col <= 8; col++){
		   		orders >> all_orders[row][col];
		   		//cout << all_orders[row][col]<<" ";
		    }
		    //cout<<"\n";
		}
		orders.close();
		SetConsoleTextAttribute(h, 0x0A);
		cout << "Orders List For Cofirm \n**********************\n";
		SetConsoleTextAttribute(h, 0x0f);
		int row = 0;
		int col = 0;
		cout <<"\n___________________________________________________________________\n";
		cout <<"\n name \t\t foods \t\t\t\t paid status \n";
		cout <<"___________________________________________________________________\n";
		for(int row = 0; row < x-1; row++) {
	   	    if(all_orders[row][5]=="1" && all_orders[row][6]=="0"){
	   	    	cout<<" \n "<< all_orders[row][0]<<" \t\t "<<all_orders[row][3] << " \t\t\t ";
	   	    	cout<<"Paid";
	   	    	cout <<"\n___________________________________________________________________\n";
			}
		}
		cout << "\n0.back\n";
		cout << "Please Enter Customer Name For Confirm: ";
		cin >> option;
		if(option=="0"){
			system("cls");
			shopper_menu(true);
			break;
		}
		else{
			system("cls");
			ifstream orders("orders list/orders.txt");
			for(int row = 0; row < x-1; row++) {
		   	    for(int col = 0; col <= 8; col++){
			   		orders >> all_orders[row][col];
			   		//cout << all_orders[row][col] << " ";
			    }
			    //cout<<endl;
			}
			orders.close();
			for(int i=0;i<x-1;i++){
				if(all_orders[i][0]==option){
					all_orders[i][6]="1";
				}
			}
			std::ofstream ofs;
			ofs.open("orders list/orders.txt", std::ofstream::out | std::ofstream::trunc);
			ofs.close();
			std::ofstream ofs1;
			ofs1.open("orders list/orders.txt");
			for(int row = 0; row < x-1; row++) {
		   	    for(int col = 0; col <= 8; col++){
			   	    ofs1 << all_orders[row][col] << " ";
			    }
			    ofs1 << "\n";
			}
			ofs1.close();
			continue;
		}
	}	
}
void position (int x, int y){
  COORD coordinates;
  coordinates.X = x;
  coordinates.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}