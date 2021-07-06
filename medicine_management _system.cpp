#include<fstream>
#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<dos.h>
#include<stdio.h>
using namespace std;
 
//***************************************
//       CLASS CONTAINING ALL THE FUNCTIONS USED
//***************************************
class medicine
{
   char name_med[100],purpose[50],id[10],per_name[20],address[50],ph_number[15],date[10],
   id1[10],name_med1[100],password[100],doctor_name[50],pat_name[50],phno[15],detail[100],med[100],
   ex_date[10];
   float price,amount;
   int stock,age;	
   public:
   	void getdata();
   	void showdata();
   	void getbill();
   	void showbill();
   	
//*********************
//           FUNCTION TO RETURN ID
//*********************   	
   	char *getid()
   	{
	 	return id;
	 }
	 
//********************************
//           FUNCTION TO RETURN MEDICINE NAME
//********************************	 
   	char *gettype()
   	{
	 	return name_med;
	 }
	 
	 	     
   	void getperson_detail();
   	void showperson_detail();
   	void input_data();
   	void showit();
   	void modify();
   	void search();
   	void delete_records();
   	void per_detail();
   	void add_data();
   	void show_perdetail();
   	void password1();
   	void bill();
   	void show_bill();
   	void per_add();
   	
//***************************
//              FUNCTION TO RETURN PASSWORD	  
//***************************
   	char *getpass()
   	 {
	  	 return password;
	  }	 
	  
	  
   	void enter_file();
   	void choose_function();
   	void choice_function();
   	void pushX(int);
   	void front_screen();
};

   	   	
//********************
//        DETAILS OF MEDICINE
//********************
    void medicine::getdata()
    {
    fflush(stdin);	
    cout<<"Enter the id of the Medicine";
    gets(id);
    fflush(stdin);
	cout<<"Enter the medicine Name";
	gets(name_med);
	cout<<"Enter the Medicine`s Category";
	gets(purpose);
	cout<<"Enter the Price of Medicine";
	cin>>price;
	fflush(stdin);
	cout<<"Enter the Date of Expiry";
	gets(ex_date);
	cout<<"Enter the Stock Left";
	cin>>stock;
    }
	
//****************	   	
//       TO SHOW DETAILS
//****************
    void medicine::showdata()
    {
    cout<<"Id of the Medicine : ";
    puts(id);
    cout<<endl;
    cout<<"Name of Medicine : ";
    puts(name_med);
    cout<<endl;
    cout<<"Medicine`s Category : ";
    puts(purpose);
    cout<<endl;
    cout<<"Expiry Date : ";
    puts(ex_date);
    cout<<endl;
    cout<<"Price : "<<price<<endl<<endl;
    cout<<"Stock Left : "<<stock<<endl<<endl;
    cout<<"==========================================";
    }
    
//****************
//         INPUT BILL DATA 
//****************
    void medicine::getbill()
	{
	  cout<<endl<<endl<<endl<<endl;
      cout<<"************************************************SINGH MEDICAL STORE****************************************************"<<endl;
	  cout<<"                                                 Doctor`s name : ";
	  cin>>doctor_name;	
	  fflush(stdin);
	  cout<<"Patient`s name_ _ _ _ _ _ _";
	  fflush(stdin);
	  cin>>pat_name;
	  cout<<"Age_ _ _ _ _ _";
	  cin>>age;
	  cout<<"Phone number_ _ _ _ _ _ _ _";
	  cin>>phno;
	  fflush(stdin);
	  cout<<"-------------------------------------------------Details of the problem-------------------------------------------------"<<endl;
	  gets(detail);
	  cout<<"---------------------------------------------------------Medicine-------------------------------------------------------"<<endl;
	  gets(med);
	} 
	
//**********************
//        FUNCTION TO SHOW BILL	
//**********************
   void medicine::showbill()
   {
   	          cout<<endl<<endl;
		   	  cout<<"****************************************SINGH MEDICAL STORE***********************************"<<endl;
	          cout<<"                                                    Doctor`s name : "<<doctor_name;
	          cout<<endl<<endl;
	          cout<<"Patient`s name_ _ _ _ _ _ _"<<pat_name<<endl<<endl;
	          cout<<"Age_ _ _ _ _ _"<<age<<endl<<endl;
	          cout<<"Phone number_ _ _ _ _ _ _ _"<<phno<<endl<<endl;
	          cout<<"Details of the problem_ _ _ _ _ _ _ _";
	          puts(detail);
	          cout<<"Medicines priscribed _ _ _ _ _ _ _ _ _ _";
	          puts(med);
	          cout<<endl;
	          cout<<"==============================================================================================="<<endl;
	        
   }        
    
//*********************
//   GET PERSON`S DETAILS 
//*********************
    void medicine::getperson_detail()
	{
		fflush(stdin);
		cout<<"Enter the Person`s Name";
		gets(per_name);
		cout<<"Enter the Address";
		gets(address);
		cout<<"Enter the Mobile Number";
		gets(ph_number);
		cout<<"Enter date of Purchasing, Id and Name of Medicine ";
		gets(date);
		gets(id1);
		gets(name_med1);
		cout<<"Enter the Paid Amount";
		cin>>amount;
	} 
	
	  
//**********************
//      SHOW PERSON`S DETAILS	
//**********************
    void medicine::showperson_detail()
	{
	  	cout<<"NAME : ";
		puts(per_name);
		cout<<"ADDRESS : ";
		puts(address);
		cout<<"MOBILE NUMBER : ";
		puts(ph_number);
		cout<<"DATE OF PURCHASE : ";
		puts(date);
		cout<<"ID : ";
		puts(id1);
		cout<<"NAME OF MEDICINE : ";
		puts(name_med1);
		cout<<"AMOUNT : ";
		cout<<amount;	
	}
	
//******************
//           INPUT OF MEDICINE
//******************
        void medicine::input_data()
		{
			fstream f("stock.dat",ios::out|ios::binary);
			medicine m;
			char ch,ab,op,pu,re,dh;
			system("cls");
			do
			{
				m.getdata();
				cout<<"Want to save the records (y/n)"<<endl;
				cin>>ch;
				if(tolower(ch)=='y')
				{
					f.write((char *)&m,sizeof(m));
					cout<<"Records Saved_ _ _ _ _ _ _ _ "<<endl;
					cout<<"Want to enter more Records (y/n)"<<endl;
					cin>>re;
				}
			else if(tolower(ch)=='n')
			  {
			  	cout<<"Records not saved_ _ _ _ _ _ _ _ "<<endl;
			  	cout<<"Do you again want to enter the Records(y/n)"<<endl;
			  	cin>>ab;
			    if(tolower(ab)=='y')
			  	      {
			  	      	do
			  	      	{
			  	      	    m.getdata();
				            cout<<"Want to Save the Records (y/n)"<<endl;
				            cin>>op;
				            if(tolower(op)=='y')
				             {
					          f.write((char *)&m,sizeof(m));
					           cout<<"Records Saved Successfully _ _ _ _ _ _ _ _ "<<endl;
							   cout<<"Want to enter more records (y/n)"<<endl;
			  	               cin>>pu;	
			  	               fflush(stdin);
							 }
						}while(tolower(pu)=='y');
					    
						break;
				  }	
				  else
				  {
				  	cout<<endl<<endl<<endl;
				  	cout<<"No Records Entered_ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
				  }
			   }
		   }while(tolower(re)=='y');
		   f.close();
		   cout<<endl<<endl;
		   cout<<"Do you want to continue (y/n)";
		   cin>>dh;
		   if(tolower(dh)=='y')
		   {
		   	system("cls");
		   	choice_function();
		   }
		      else 
		      {
				cout<<endl<<endl;
		      	cout<<"PRESS ANY KEY TO EXIT............."<<endl;
		      	exit(1);
			  }
	   }
	   
//*************
//    SHOW RECORDS
//*************	   
	   void medicine::showit()
	   {
	   	fstream f1("stock.dat",ios::in|ios::binary);
	   	medicine m1;
	   	char dh;
	   	system("cls");
	   	while(f1.read((char *)&m1,sizeof(m1)))
	   	{
	   		m1.showdata();
	   		cout<<endl;
		}
		f1.close();
		cout<<endl<<endl;
		   cout<<"Do you want to continue (y/n)";
		   cin>>dh;
		   if(tolower(dh)=='y')
		   {
		   	system("cls");
		   	choice_function();
		   }
		      else 
		      {
		      	cout<<endl<<endl;
		      	cout<<"PRESS ANY KEY TO EXIT............."<<endl;
		      	exit(1);
			  }
	   }
	   
//******************
//        TO MODIFY RECORDS
//******************
        void medicine::modify()
		{
			fstream f2("stock.dat",ios::in|ios::out|ios::binary);
			medicine m2;
			char ids[10],re,ch,dh,name[100];
			system("cls");
			cout<<"Do  you want to Modification! (y/n)";
			cin>>ch;
			if(tolower(ch)=='y')
		   {
			do
			{
				fflush(stdin);
				cout<<"Enter the id which you want to Modify"<<endl;
				gets(ids);
				while(!f2.eof())
				{
					f2.read((char *)&m2,sizeof(m2));
					if(strcmpi(m2.getid(),ids)==0)
					{
						cout<<"Enter the Details"<<endl;
						int i=f2.tellg();
						f2.seekg(i-sizeof(m2),ios::beg);
						m2.getdata();
						f2.write((char *)&m2,sizeof(m2));
						break;
					}
				}
				cout<<"want to modify more records (y/n)"<<endl;
				cin>>re;
			}while(tolower(re)=='y');
		}
		else
		{ 
		  cout<<"==================================="<<endl;
		  cout<<"THANK YOU"<<endl;
		  cout<<endl;  
		}
			f2.close();
			cout<<endl<<endl;
		   cout<<"Do you want to continue (y/n)";
		   cin>>dh;
		   if(tolower(dh)=='y')
		   {
		   	system("cls");
		   	choice_function();
		   }
		      else 
		      {
		      	cout<<endl<<endl;
		      	cout<<"PRESS ANY KEY TO EXIT............."<<endl;
		      	exit(1);
			  }
		}
			   
		
//********************************
//     TO SEARCH A PARTICULAR MEDICINE
//********************************
    void medicine::search()
	{
		fstream c("type.dat",ios::out|ios::binary);
		medicine m3;
		char medic_name[100],ch,ab,dh;
		system("cls");
		do
		{
			fstream f3("stock.dat",ios::in|ios::binary);
			fflush(stdin);
			cout<<"Enter the name of the medicine to be searched"<<endl;
			gets(medic_name);
			while(!f3.eof())
			{
				f3.read((char *)&m3,sizeof(m3));
				if(strcmpi(m3.gettype(),medic_name)==0)
				{
					f3.seekg(0);
					c.write((char *)&m3,sizeof(m3));
					m3.showdata();
					cout<<endl;
					break;
				}
			}
			if(f3.eof())
			{
				f3.seekg(0);
				cout<<" Sorry! Medicine not Found "<<endl;
				f3.close();
			}
			cout<<"want to search again (y/n)"<<endl;
			cin>>ch;
		}while(tolower(ch)=='y');
		c.close();
		cout<<endl<<endl;
		   cout<<"Do you want to continue (y/n)";
		   cin>>dh;
		   if(tolower(dh)=='y')
		   {
		   	system("cls");
		   	choice_function();
		   }
		      else 
		      {
		      	cout<<endl<<endl;
		      	cout<<"PRESS ANY KEY TO EXIT............."<<endl;
		      	exit(1);
			  }
	}		
	
//**********************
//          TO DELETE ANY DETAIL
//**********************
       void medicine::delete_records()
	   {
	   	  fstream f4("stock.dat",ios::in|ios::binary);
	   	  fstream s("del.dat",ios::out|ios::binary);
	   	  medicine m4;
	   	  char medo_name[100],ch,re,dh;
	   	  system("cls");
	   	  cout<<"Do you want to delete any Record (y/n)"<<endl;
	   	  cin>>ch;
	   	  if(tolower(ch)=='y')
	   	  {
	   	  	 do
	   	  	 {
	   	  	 	fflush(stdin);
				cout<<"Enter the name of Medicine which you want to delete--"<<endl;
	   	  	 	gets(medo_name);
	   	  	 	while(!f4.eof())
	   	  	 	{
	   	  	 		f4.read((char *)&m4,sizeof(m4));
	   	  	 		if(strcmpi(m4.gettype(),medo_name)!=0)
	   	  	 		s.write((char *)&m4,sizeof(m4));
				}
				f4.close();
				s.close();
				remove("stock.dat");
				rename("del.dat","stock.dat");
				cout<<"Want to delete more Records (y/n)"<<endl;
				cin>>re;
			 }while(tolower(re)=='y');
		  }
		  else
		  {
		  	cout<<"=C=C=C=C=C=C=C=C=C=C=C=C=C=C=C=C=C=C=C=C=C=C=C="<<endl;
		  	cout<<"THANK YOU"<<endl;
		  	cout<<endl;
		  }
		  cout<<endl<<endl;
		   cout<<"Do you want to continue (y/n)";
		   cin>>dh;
		   if(tolower(dh)=='y')
		   {
		   	system("cls");
		   	choice_function();
		   }
		      else 
		      {
		      	cout<<endl<<endl;
		      	cout<<"PRESS ANY KEY TO EXIT............."<<endl;
		      	exit(1);
			  }
	   }
	   
//***********************
//       FUNCTION TO ADD RECORDS
//***********************
       void medicine::add_data()
	   {
	   	  fstream f5("stock.dat",ios::in|ios::binary|ios::app);
	   	  medicine m5;
	   	  char re,dr,dh;
	   	  system("cls");
	   	  cout<<"Do you want to add Some new Records (y/n)"<<endl;
	   	  cin>>dr;
	   	  if(tolower(dr)=='y')
	   	  {
	   	  	  do
	   	  	  {
	   	  	  	  m5.getdata();
	   	  	  	  f5.write((char *)&m5,sizeof(m5));
	   	  	  	  cout<<"Do you want to Enter more Records (y/n)"<<endl;
	   	  	  	  cin>>re;
			  }while(tolower(re)=='y');
		  }
		  else
		  {
		  	cout<<"=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>"<<endl;
		  	cout<<"THANK YOU"<<endl;
		  	cout<<endl;
		  }
		  f5.close();
		  cout<<endl<<endl;
		   cout<<"Do you want to continue (y/n)";
		   cin>>dh;
		   if(tolower(dh)=='y')
		   {
		   	system("cls");
		   	choice_function();
		   }
		      else 
		      {
		      	cout<<endl<<endl;
		      	cout<<"PRESS ANY KEY TO EXIT............."<<endl;
		      	exit(1);
			  }
	   }	   	
	   
//******************************
//     FUNCTION FOR PERSON`S DETAILS	   
//******************************
         void medicine::per_detail()
         {
         	fstream p("perdetail.dat",ios::out|ios::binary);
         	medicine m6;
         	char ch,dh;
         	system("cls");
         	do
         	{
         		cout<<" Please Enter the details of the person"<<endl;
         		m6.getperson_detail();
         		p.write((char *)&m6,sizeof(m6));
         		cout<<"Do you want to enter more records (y/n)"<<endl;
         		cin>>ch;
			}while(tolower(ch)=='y');
			p.close();
			cout<<endl<<endl;
		   cout<<"Do you want to continue (y/n)";
		   cin>>dh;
		   if(tolower(dh)=='y')
		   {
		   	system("cls");
		   	choice_function();
		   }
		      else 
		      {
		      	cout<<endl<<endl;
		      	cout<<"PRESS ANY KEY TO EXIT............."<<endl;
		      	exit(1);
			  }
		 }
		 
//************************
//         TO SHOW PERSON`S DETAILS
//************************
      void medicine::show_perdetail()
	  {
	  	  fstream p1("perdetail.dat",ios::in|ios::binary);
	  	  medicine m7;
	  	  char dh;
	  	  system("cls");
	  	  while(p1.read((char *)&m7,sizeof(m7)))
	  	  {
	  	  	 cout<<"Person`s Details Are Following ----"<<endl;
	  	  	 cout<<"============================================"<<endl;
	  	  	 cout<<endl;
	  	  	 m7.showperson_detail();
	  	  	 cout<<endl;	  	  	 
		  }
		  p1.close();
		  cout<<endl<<endl;
		   cout<<"Do you want to continue (y/n)";
		   cin>>dh;
		   if(tolower(dh)=='y')
		   {
		   	system("cls");
		   	choice_function();
		   }
		      else 
		      {
		      	cout<<endl<<endl;
		      	cout<<"PRESS ANY KEY TO EXIT............."<<endl;
		      	exit(1);
			  }
	  }
	  
//**************************
//     TO SET PASSWORD ON SYSTEM
//**************************
      void medicine::password1()
	  {
	     	fstream g("pass.dat",ios::out|ios::binary);
	     	medicine m8;
	     	char ch;
	     	system("cls");
	     	START:
	     		system("cls");
	     	cout<<" Please Enter the password to set.... \n \n(Minimum 6 characters Required......)"<<endl;
			 int i=0;
			 char a;
			 for(i=0;;)
			 {
			 	a=getch();
			 	if(a=='\r')
				 {
			 		break;
				 }
				 else{
				 	cout<<"*";
					this->password[i] = a;
					i++;
				 }
			  }	
			  if(i<=5)
			  {
			  	cout<<"Minimum 6 digits needed !"<<endl;
			  	goto START;
			  }
			  g.write((char *)&m8,sizeof(m8));
			  g.close();
			  enter_file();
		   }

//***********************
//     FUNCTION TO CREATE BILLS
//***********************
   void medicine::bill()
   {
   	  fstream b("bill.dat",ios::out|ios::binary|ios::app);
   	  medicine mb;
   	  char dh,ch;
   	  system("cls");
   	  do
   	  {
   	  mb.getbill();
   	  b.write((char *)&mb,sizeof(mb));	
	  cout<<endl<<endl<<endl;
	  cout<<"DATA SAVED_ _ _ _ _ _ _ _ _ "<<endl<<endl; 
	  cout<<"Are you willing to enter more Bills (y/n)"<<endl;
	  cin>>ch;
      }while(tolower(ch)=='y');
      cout<<"=D=D=D=D=D=D=D=D=D=D=D=D=D=D=D=D=D=D=D=D=D=D=D=D=D=D=D=D=D=D"<<endl;
	  cout<<"--- !!!! ----    THANK YOU  --- !!!! ----  ";
	  b.close();
	  cout<<endl<<endl;
		   cout<<"Do you want to continue (y/n)";
		   cin>>dh;
		   if(tolower(dh)=='y')
		   {
		   	system("cls");
		   	choice_function();
		   }
		      else 
		      {
		      	cout<<endl<<endl;
		      	cout<<"PRESS ANY KEY TO EXIT./././././././././././././"<<endl;
		      	exit(1);
			  }
   }	  
   
//**********************
//     FUNCTION TO SHOW BILLS
//**********************
         void medicine::show_bill()
		 {
		   fstream b1("bill.dat",ios::in|ios::binary);
		   medicine mj;
		   char dh;
		   system("cls");
		   while(b1.read((char *)&mj,sizeof(mj)))
		   {
		   	   mj.showbill();
		   	   cout<<endl;
		   } 	
		   b1.close();
		   cout<<endl<<endl;
		   cout<<"Do you want to continue (y/n)";
		   cin>>dh;
		   if(tolower(dh)=='y')
		   {
		   	system("cls");
		   	choice_function();
		   }
		      else 
		      {
		      	cout<<endl<<endl;
		      	cout<<"PRESS ANY KEY TO EXIT............."<<endl;
		      	exit(1);
			  }
		 }   	 
	  
//******************************
//   TO ADD MORE DETAILS OF A PERSON	
//******************************
      void medicine::per_add()
	  {
	  	fstream p6("perdetail.dat",ios::out|ios::app|ios::binary);
	   	  medicine ma;
	   	  char re,dr,dh;
	   	  system("cls");
	   	  cout<<"Are you willing to insert more Records (y/n)"<<endl;
	   	  cin>>dr;
	   	  if(tolower(dr)=='y')
	   	  {
	   	  	  do
	   	  	  {
	   	  	  	  ma.getperson_detail();
	   	  	  	  p6.write((char *)&ma,sizeof(ma));
	   	  	  	  cout<<"Do you want to enter more records (y/n)"<<endl;
	   	  	  	  cin>>re;
			  }while(tolower(re)=='y');
		  }
		  else
		  {
		  	cout<<"*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*"<<endl;
		  	cout<<"THANK YOU"<<endl;
		  	cout<<endl;
		  }
		  p6.close();
		  cout<<endl<<endl;
		   cout<<" Want to Continue ??? (y/n)";
		   cin>>dh;
		   if(tolower(dh)=='y')
		   {
		   	system("cls");
		   	choice_function();
		   }
		      else 
		      {
		      	cout<<endl<<endl;
		      	cout<<"PRESS ANY KEY TO EXIT............."<<endl;
		      	exit(1);
			  }
	  }  
	  	 
//**********************
//      TO ENTER PASSWORD FILE
//**********************
          void medicine::enter_file()
		  {
		  	 system("cls");
			 cout<<endl;
		  	 fstream g2("pass.dat",ios::in|ios::binary);
          	 medicine ml;
         	 char pss1[100];
         	 cout<<"Please Confirm the Password to Enter into the file.........."<<endl;
			 int i=0;
			 char a;
			 for(i=0;;)
			 {
			 	a=getch();
			 	if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
			 	{
			 	   pss1[i]=a;
					++i;
					cout<<"*";
				}
			      if(a=='\r')
			      {
			      	pss1[i]='\0';
			      	break;
				  }
			  }	
			  g2.read((char *)&ml,sizeof(class medicine));
		while(!g2.eof())
		{
         if(strcmp(pss1,getpass())==0)
            {
				front_screen();
			}
			else 
			{
				
				cout<<endl;
				cout<<"ENTERED WRONG PASSWORD !!! "<<endl;
				system("cls");
				enter_file();
			}
       }
       g2.close();
		  }	 
//*******************************
//       TO CHOOSE THE DESIRED FUNCTION	 
//*******************************
          void medicine::choose_function()
          {
          	int no;
          	cout<<"enter your choice"<<endl;
          	cin>>no;
          	if(no==1)
          	{
          	  system("color 4");
			  input_data();		
			}
			  else if(no==2)
			  {
			  	system("color 3");
			  	showit();
			  }
			    else if(no==3)
			    {
			    	system("color 2");
			    	modify();
				}
				  else if(no==4)
				  {
				  	system("color 1");
				  	search();
				  }
				     else if(no==5)
				   {
				   	system("color 5");
				   	delete_records();
				   }
				    else if(no==6)
				    {
				    	system("color 6");
				    	add_data();
					}
					  else if(no==7)
					 {
					 	system("color 4");
					 	per_detail();
					 }
					   else if(no==8)
					   {
					   system("color 8");
					   	show_perdetail();
					   }
					   else if(no==9)
					   {
					   system("color 9");
					   	per_add();
					   }
					     else if(no==10)
					     {
					     	 system("color 1");
							 bill();
						 }
						   else if(no==11)
						   {
						   	   system("color A");
							   show_bill();
						   }
				else if(no==12)
				{	
				exit(1);
				}	
		           else
				   {
				      cout<<"INVALID INPUT !!!!!!!"<<endl;
					  cout<<"Please Select Your Choice Again Between 1 to 12 !"<<endl;
					  cin>>no;
					  
			if(no==1)
          	{
          	  
			  system("color 4");
			  input_data();		
			}
			  else if(no==2)
			  {
			  	system("color 3");
			  	showit();
			  }
			    else if(no==3)
			    {
					system("color 2");
			    	modify();
				}
				  else if(no==4)
				  {
				  	system("color 1");
				  	search();
				  }
				    else if(no==5)
				   {
				   system("color 5");
				   	delete_records();
				   }
				    else if(no==6)
				    {
				    	system("color 6");
				    	add_data();
					}
					 else if(no==7)
					 {
					 system("color 4");
					 	per_detail();
					 }
					 else if(no==8)
					   {
					   system("color 8");
					   	show_perdetail();
					   }
					   else if(no==9)
					   {
					   system("color 9");
					   	per_add();
					   }
			              else if(no==10)
					     {
					     	system("color 1");
					     	bill();
						 }
						   else if(no==11)
						   {
						   	system("color 2"); //system("color f2) for the screen to be with at the 
						   	                      //place of black
						   	show_bill();
						   }
				else if(no==12)
				{	
				exit(1);
				}
				choose_function();	
				   }   
		  }
		  
//****************
//    CHOICE FUNCTION
//****************
     void medicine::choice_function()
	 {
	    system("color 0f");
	    cout<<"(~)~(~)~(~)~~~~~~~~~~~~~~~~~~~~~~~(~)~(~)~(~)~~~~~~WELCOME~~~~~~~(~)~(~)~(~)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~(~)~(~)~(~)"<<endl;
	    cout<<endl;
	    cout<<"=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=  CHOICE SCREEN  =O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O=O="<<endl;
	    cout<<endl<<endl;
	    cout<<"# Enter 1 : To Enter the Stock of Medicine"<<endl;
	    cout<<"# Enter 2 : To show the Stock of Medicine"<<endl;
	    cout<<"# Enter 3 : To Modify Data"<<endl;
	    cout<<"# Enter 4 : To Search any Medicine according to it's Name"<<endl;
	    cout<<"# Enter 5 : To Delete any Record"<<endl;
	    cout<<"# Enter 6 : To Add new Record"<<endl;
	    cout<<"# Enter 7 : To Enter the Person`s Detail"<<endl;
	    cout<<"# Enter 8 : To See Person`s Detail"<<endl;
	    cout<<"# Enter 9 : To Add more Person`s Details"<<endl;
	    cout<<"# Enter 10 : To Make the Bill"<<endl;
	    cout<<"# Enter 11 : To See the Bill"<<endl;
	    cout<<"# Enter 12 : To Exit"<<endl;
	    cout<<endl;
	    cout<<"*******************************************************************************"<<endl;
	    cout<<endl;
	    choose_function();
	    }  
		
//*****************
//     FUNCTION TO PUSH 
//****************		
			void medicine::pushX(int num)
		  {
            for(int i=0;i<num;i++)
            cout<<" ";
          } 
		
//*************
//    FIRST THING TO DISPLAY
//*************
      void medicine::front_screen()
	  {
         system("color 5f"); 
        for(int j=0;j<50;j++)
		{
        system("CLS");
        pushX(j);
        cout<<"/*/*/*/*/*/*/*/*/* WELCOME */*/*/*/*/*/*/*/*/"<<endl;
        cout<<endl<<endl<<endl;
        cout<<"#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#"<<endl;
        cout<<endl<<endl<<endl<<endl;
        pushX(j);
        cout<<"  MADE BY   : "<<"VASHISHT MUNI GUPTA"<<endl;
        cout<<"                                                                ___________________"<<endl<<endl;
        cout<<"#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#=>#"<<endl;
        cout<<endl<<endl<<endl<<endl;
        Sleep(15);
	   }
	  char ch;
	  cout<<endl<<endl;
	  cout<<"Want to Enter_ _ _ _ _ _ _('y/n')"<<endl;
	  cin>>ch;
	  if(tolower(ch)=='y')
	  {
	  	system("cls");
	  	choice_function();
	  }
	   else
	   {
	   	cout<<"TO EXIT PRESS ANY KEY././././././././././././"<<endl;
	   	exit(1);
	   }
     }
main()
{
	medicine f;
    f.password1();
	getch();
}

