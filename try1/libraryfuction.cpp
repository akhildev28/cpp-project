#include "libraryfuction.h"

using namespace std;

#pragma once;

//To write created book details to file

    void write_book()
    {
    char ch;
    fileObj.open("book.dat",ios::out|ios::app);
    do
    {
        //system("clear");
        bk.add_book();
        fileObj.write((char*)&bk,sizeof(Book));
        cout<<"\n\nDo you want to add more record..(y/n?)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fileObj.close();
    }

    // To write created Student details to file

    void write_student()
{
    char ch;
    fileObj.open("student.dat",ios::out|ios::app);
    do
    {
        st.Add_student();
        fileObj.write((char*)&st,sizeof(Student));
        cout<<"\n\ndo you want to add more record..(y/n?)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fileObj.close();
}


void modify_book_file()
{
    char n[6];
    int found=0;
    //system("clear");
    cout<<"\n\n\tMODIFY BOOK REOCORD.... ";
    cout<<"\n\n\tEnter The book no. of The book";
    cin>>n;
    fileObj.open("book.dat",ios::in|ios::out);
    while(fileObj.read((char*)&bk,sizeof(Book)) && found==0)
    {
        if(strcmpi(bk.retbookno(),n)==0)
        {
            bk.show_book();
            cout<<"\nEnter The New Details of book"<<endl;
            bk.modify_book();
            /*The seekp(pos) method of ostream in C++ is used to set the position of the pointer
             in the output sequence with the specified position. 
             This method takes the new position to be set and returns this ostream instance with the position 
             set to the specified new position.*/
            int pos=-1*sizeof(bk);
                fileObj.seekp(pos,ios::cur);
                fileObj.write((char*)&bk,sizeof(Book));
                cout<<"\n\n\t Record Updated";
                found=1;
        }
    }

        fileObj.close();
        if(found==0)
            cout<<"\n\n Record Not Found ";
        getch();
}

//// read file while modifying student details 

void modify_student_file()
{
    char n[6];
    int found=0;
    //system("clear");
    cout<<"\n\n\tMODIFY STUDENT RECORD... ";
    cout<<"\n\n\tEnter The admission no. of The student";
    cin>>n;
    fileObj.open("student.dat",ios::in|ios::out);
    while(fileObj.read((char*)&st,sizeof(Student)) && found==0)
    {
        if(strcmpi(st.retadmno(),n)==0)
        {
            st.show_student();
            cout<<"\nEnter The New Details of student"<<endl;
            st.modify_student();
            int pos=-1*sizeof(st);
            fileObj.seekp(pos,ios::cur);
            fileObj.write((char*)&st,sizeof(Student));
            cout<<"\n\n\t Record Updated";
            found=1;
        }
    }
     
    fileObj.close();
    if(found==0)
        cout<<"\n\n Record Not Found ";
    getch();
}

// read file displaying all details of student

void display_allStudent()
{
    //system("clear");
         fileObj.open("student.dat",ios::in);
         if(!fileObj)
         {
               cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
               getch();
               return;
         }

    cout<<"\n\n\t\tSTUDENT LIST\n\n";
    cout<<"==================================================================\n";
    cout<<"\tLibrary Id."<<setw(10)<<"Name"<<setw(20)<<"Class"<<setw(20)<<"Department"<<setw(15)<<"Book Issued\n";
    cout<<"==================================================================\n";

    while(fileObj.read((char*)&st,sizeof(Student)))
    {
        st.report();
    }
         
    fileObj.close();
    getch();
}

// read file displaying all details of Book

void display_allBooks()
{
    //system("clear");
    fileObj.open("book.dat",ios::in|ios::binary);
    if(!fileObj)
    {
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
               getch();
               return;
         }

    cout<<"\n\n\t\tBook LIST\n\n";
    cout<<"=========================================================================\n";
    cout<<"Book Number"<<setw(20)<<"Book Name"<<setw(20)<<"Author"<<setw(20)<<"Status"<<setw(20)<<"Date Of Issue \n";
    cout<<"=========================================================================\n";

    while(fileObj.read((char*)&bk,sizeof(Book)))
    {
        bk.Display();
    }
         fileObj.close();
         getch();
}

  void admin_menu()
{
    //system("clear");
    int option2;
    cout<<"\n\n\n\tLIBRARIAN MENU";
    cout<<"\n\n\t1.Student Management";
    cout<<"\n\n\t2.Book Management";
    cout<<"\n\n\t3.Logout";
    cout<<"\n\n\tPlease Enter Your Choice:\t";
    cin >> option2;
    if(option2==1)
    {
        int option3;
        switch(option3)
        {
            int option4;
            case 1: system("cls");
                    cout<<"\n\n\n\tSTUDENT MANAGEMENT";
                    cout<<"\n\n\t1.Add new student:";
                    cout<<"\n\n\t2.Dispaly all students details";
                    cout<<"\n\n\t3.Show specific student details";
                    cout<<"\n\n\t4.Update existing student details\t";
                    cout<<"\n\n\t5.Remove a student";
                    cout<<"\n\n\t6.Go Back";
                    cout<<"\n\n\tPlease Enter Your Choice:\t";
                    cin >> option4;
                    switch(option4)
                    {
                        case 1: system("cls");
                                write_student();
                                break;
                        case 2: system("cls");
                                display_allStudent();
                                break;
                        case 3: system("cls");
                                char num[6];
                                //system("clear");
                                cout<<"\n\n\tPlease Enter The Admission No. ";
                                cin>>num;
                                display_showStudent(num);
                                break;
                        case 4: system("cls");
                                modify_student_file();
                                break;
                        case 5: system("cls");
                                delete_student();
                                break;
                        case 6: system("cls");
                                admin_menu();
                                break;
                        default:"Wrong choice..!";
                    }
            case 2: system("cls");
                    cout <<"Back to Main menu";
                    break;
            default:"Wrong choice..!";
    }

    
//User Menu contain all User Function
void user_menu()
{
    int ch3;
    cout<<"\n\n\t01. BOOK LIST";
    cout<<"\n\n\t02. TAKE A BOOK";
    cout<<"\n\n\t03. BOOK DEPOSIT";
    cout<<"\n\n\t04. BACK TO MAIN MENU";
    cout<<"\n\n\tPlease Enter Your Choice (1-4) ";
    cin>>ch3;
    switch (ch3)
    {
    case 1:display_allBooks();
        /* code */
        break;
    case 2:book_issue();
            break;
    case 3:book_deposit();
            break;
    case 4:return;
    
    default:cout<<"\a";
        break;
    }
    user_menu();

}
case 2: system("cls");
                    cout<<"\n\n\n\tBOOK MANAGEMENT";
                    cout<<"\n\n\t1.Add new book details:";
                    cout<<"\n\n\t2.Dispaly all book details";
                    cout<<"\n\n\t3.Show specific book details";
                    cout<<"\n\n\t4.Update existing book details\t";
                    cout<<"\n\n\t5.Remove a book";
                    cout<<"\n\n\t6.Go Back";
                    cout<<"\n\n\tPlease Enter Your Choice:\t";
                    cin >> option4;
                    switch(option4)
                    {
                        case 1: system("cls");
                                write_book();
                                break;
                        case 2: system("cls");
                                display_allBooks();
                                break;
                        case 3: system("cls");
                                char num[6];
                                cout<<"\n\n\tPlease Enter The book No. ";
                                cin>>num;
                                display_showBook(num);
                                break;
                        case 4: system("cls");
                                modify_book_file();
                                break;
                        case 5: system("cls");
                                delete_book();
                                break;
                        case 6: system("cls");
                                student_menu();
                                break;
                        default:"Wrong choice..!";
                    }