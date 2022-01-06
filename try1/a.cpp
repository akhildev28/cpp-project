#include<iostream>
#include <ctime>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<cstring>
#include<iomanip>
#include<stdlib.h>
using namespace std;

//All Functions and Properties of Books is definded in this class

class Book
{
    public:
        char BookName[50];
        char BookNo[6];
        char AuthorName[20];
        char Status[10];
        char DateOfIssue[15];

        //Function add new Book to library

        void add_book()
	{
        cout<<"\nNEW BOOK ENTRY...\n";
        cout<<"\nEnter The book no.";
        cin>>BookNo;
        cout<<"\nEnter The Name of The Book ";
        cin>>BookName;
        cout<<"\n\nEnter The Author's Name ";
        cin>>AuthorName;
        strcpy(Status,"Available");
        strcpy(DateOfIssue,"Book Not Issued");
        cout<<"\n\n\nBook Created..";
    }

    //Function to Show a specific Book

    void show_book()
    {
        cout<<"\nBook no. : "<<BookNo;
        cout<<"\nBook Name : ";
        puts(BookName);
        cout<<"Author Name : ";
        puts(AuthorName);
        cout<<"Status = ";
        puts(Status);
    }

    //

    void modify_book()
    {
        cout<<"\nBook no. : "<<BookNo;
        cout<<"\nModify Book Name : ";
        cin>>BookName;
        cout<<"\nModify Author's Name of Book : ";
        cin>>AuthorName;
    }

    //This Function return BookNumber and its used for further ops

    char* retbookno()
    {
        return BookNo;
    }

    //Function to Display all Book Detalis

    void Display()
    {
        cout<<BookNo<<setw(30)<<BookName<<setw(20)<<AuthorName<<setw(20)<<Status<<setw(20)<<DateOfIssue<<endl;
    }

}; //Book class end Here

//All Functions and Properties of student is definded in this class

class Student
{
    public:
        char LibraryId[4];
        char StudentName[20];
        char ClassName[10];
        char department[20];
        char StBookNo[6];
        int token=0;

        // Function to add new student 
        void Add_student()
    {
        //system("clear");
         cout<<"\nNEW STUDENT ENTRY...\n";
        cout<<"\nEnter The admission no. ";
        cin>>LibraryId;
        cout<<"\n\nEnter The Name of The Student ";
        cin>>StudentName;
        cout<<"\n\nEnter The class of The Student ";
        cin>>ClassName;
        cout<<"\n\nEnter The Department of The Student ";
        cin>>department;

        token=0;
        StBookNo[0]='/0';
        cout<<"\n\nStudent Record Created..";
    }

    //Show details of specific student

    void show_student()
    {
        cout<<"\nAdmission no. : "<<LibraryId;
        cout<<"\nStudent Name : ";
        puts(StudentName);
        cout<<"\nNo of Book issued : "<<token;
        if(token==1)
            cout<<"\nBook No "<<StBookNo;
    }

    // To change name of a student

    void modify_student()
    {
        cout<<"\nAdmission no. : "<<LibraryId;
        cout<<"\nModify Student Name : ";
        cin>>StudentName;
        cout<<"\nModify Class : ";
        cin>>ClassName;
        cout<<"\nModify Department : ";
        cin>>department;
    }

    //Return Library Id which is used for further ops 

     char* retadmno()
    {
        return LibraryId;
    }

    //Return Student_bookno which is used for further ops 

     char* retstbno()
    {
        return StBookNo;
    }

    //Return Token (no of Book taken) which is used for further ops 


     int rettoken()
    {
        return token;
    }

    //Copy Book number to Studnet Book number

    void getstbno(char t[])
    {
        strcpy(StBookNo,t);
    }

    //Display the Details of Student

    void report()
    {

        cout<<"\t"<<LibraryId<<setw(21)<<StudentName<<setw(16)<<ClassName<<setw(20)<<department<<setw(14)<<token<<endl;
    
    }

};

    //class ends here

    fstream fileObj,fileObj1;// creating 2 file object  
    Book bk; // creating an object of Book class
    Student st; // creating an object of Student class

    //This Function Copy TODAYS DATE to given parameter

    void TodayDate(char Date[]) 
    {
    char s[20];
    time_t t = time(0);
    strftime(s, 20, "%m/%d/%Y", localtime(&t));
    strcpy(Date,s);
    } 

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

    // function read file to Display book / search for book

    void display_showBook(char n[])
{
    cout<<"\nBOOK DETAILS\n";
    int flag=0;
    fileObj.open("book.dat",ios::in);
    // iterating through each file object
    while(fileObj.read((char*)&bk,sizeof(Book)))
    {
        //comparing the each bk's with given book number 'n'
        if(strcmpi(bk.retbookno(),n)==0)
        {
            //if found the same book no , then showing the details of the specific book 
            bk.show_book();
             flag=1;
        }
    }
    
    fileObj.close();
    if(flag==0)
        cout<<"\n\nBook does not exist";
    getch();
}

//function to read file to Display a specific student details  / search for a student


void display_showStudent(char n[])
{
    cout<<"\nSTUDENT DETAILS\n";
    int flag=0;
    fileObj.open("student.dat",ios::in);
    while(fileObj.read((char*)&st,sizeof(Student)))
    {
        if((strcmpi(st.retadmno(),n)==0))
        {
            st.show_student();
            flag=1;
        }
    }
    
    fileObj.close();
    if(flag==0)
            cout<<"\n\nStudent does not exist";
     getch();
}

// read file while modifying book details 

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

// Delete a specific Student on Library id / admission  no

void delete_student()
{
    char n[6];
    int flag=0;    
    //system("clear");
        cout<<"\n\n\n\tDELETE STUDENT...";
        cout<<"\n\nEnter The admission no. of the Student You Want To Delete : ";
        cin>>n;
        fileObj.open("student.dat",ios::in|ios::out);
        fstream fileObj2;
        fileObj2.open("Temp.dat",ios::out);
        fileObj.seekg(0,ios::beg);
        while(fileObj.read((char*)&st,sizeof(Student)))
    {
        // write all data to temp.dat except the matching condtion
        //ie,student details with the with given admission no/library id  is excluded 
        if(strcmpi(st.retadmno(),n)!=0)
                 fileObj2.write((char*)&st,sizeof(Student));
        else
               flag=1;
    }
        
    fileObj2.close();
        fileObj.close();
        // deleting the 'student.dat' and renaming the updated list to 'student.dat'
        remove("student.dat");
        rename("Temp.dat","student.dat");
        if(flag==1)
             cout<<"\n\n\tRecord Deleted ..";
        else
             cout<<"\n\nRecord not found";
        getch();
}

// Delete a specific book on book number

void delete_book()
{
    char n[6];
    //system("clear");
    cout<<"\n\n\n\tDELETE BOOK ...";
    cout<<"\n\nEnter The Book no. of the Book You Want To Delete : ";
    cin>>n;
    fileObj.open("book.dat",ios::in|ios::out);
    fstream fileObj2;
    fileObj2.open("Temp.dat",ios::out);
    fileObj.seekg(0,ios::beg);
    while(fileObj.read((char*)&bk,sizeof(Book)))
    {
        // write all data to temp.dat except the matching condtion
        //ie,Book details with the with given Book no.  is excluded 
        if(strcmpi(bk.retbookno(),n)!=0)  
        {
            fileObj2.write((char*)&bk,sizeof(Book));
        }
    }
        
    fileObj2.close();
        fileObj.close();
        // deleting the 'book.dat' and renaming the updated list to 'book.dat'
        remove("book.dat");
        rename("Temp.dat","book.dat");
        cout<<"\n\n\tRecord Deleted ..";
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

//Function to issue a book

void book_issue()
{
   
    char StudentNumber[6],BookNumber[6]; // Temporay variable to store LibrarayId(Ad.Number) and Book number
    int found=0,flag=0;
    
    //clrscr();
    cout<<"\n\nBOOK ISSUE ...";
    cout<<"\n\n\tEnter The student's admission no.";
    cin>>StudentNumber;
    fileObj.open("student.dat",ios::in|ios::out);
        fileObj1.open("book.dat",ios::in|ios::out);
        // Iterating through Student Details
        while(fileObj.read((char*)&st,sizeof(Student)) && found==0)
           {
               //Checkimg For Exact student
        if(strcmpi(st.retadmno(),StudentNumber)==0)
        {
            found=1;
            if(st.rettoken()==0||st.rettoken()==1)//checking the student is eligible to to take book
            {
                      cout<<"\n\n\tEnter the book no. ";
                cin>>BookNumber;
                
                // Iterating through Book list
                while(fileObj1.read((char*)&bk,sizeof(Book))&& flag==0)
                {
                    //Checkimg For Exact Book
                       if(strcmpi(bk.retbookno(),BookNumber)==0 && strcmpi(bk.Status,"Available")==0)
                    {
                        
                        
                        // Displaying Exact Book
                        bk.show_book();
                        flag=1;
                        // Issues the book 
                        //st.addtoken(st.token);
                        st.token++;
                        //Changing status of book
                        strcpy(bk.Status,"Issued");
                        // getsbno (Book Number) Function copy the given book number to Student Book Number
                        st.getstbno(bk.retbookno());
                        //Changing IsuueOfDate 
                        TodayDate(bk.DateOfIssue);
                            //Modification to Student file
                               int pos=-1*sizeof(st);
                        fileObj.seekp(pos,ios::cur);
                        fileObj.write((char*)&st,sizeof(Student));
                        
                        // Modification to Book file after changing status

                        int pos2=-1*sizeof(bk);
                        fileObj1.seekp(pos2,ios::cur);
                        fileObj1.write((char*)&bk,sizeof(Book));
                        cout<<"\n\n\t Book issued successfully\n\nPlease Note: Write current date in backside of book and submit within 15 days fine Rs. 1 for each day after 15 days period";
                    }
                    }
                  if(flag==0)
                        cout<<"Book no does not exist or Issued to Someone else";
            }
                else
                  cout<<"You have not returned the last book ";

        }
    }
          if(found==0)
        cout<<"Student record not exist...";
    getch();
      fileObj.close();
      fileObj1.close();
}

// Function that 

void book_deposit() // need to check the logic
{
    char StudentNumber[6],BookNumber[6],TempNo[6];// Temporay variable to store LibrarayId(Ad.Number) and Book number
    int found=0,flag=0,day,fine;
    //system("clear");
    cout<<"\n\nBOOK DEPOSIT ...";
    cout<<"\n\n\tEnter The studentâ€™s admission no.";
    cin>>StudentNumber;
    fileObj.open("student.dat",ios::in|ios::out);
    fileObj1.open("book.dat",ios::in|ios::out);
    // Iterating through Student Details
    while(fileObj.read((char*)&st,sizeof(Student)) && found==0)
       {
        if(strcmpi(st.retadmno(),StudentNumber)==0)
        {
            found=1;
            // checking token , ie  is the Student have taken any book 
            // if token is 1 then one book is remaining 
            if(st.rettoken()==1||st.rettoken()==2)
            {
                cout<<"Enter Book Number for return : ";
                cin>>TempNo;
                // Iterating through Book list 
            while(fileObj1.read((char*)&bk,sizeof(Book))&& flag==0)
            {
                //Checkimg For Exact Book number
               if(strcmpi(bk.retbookno(),TempNo)==0)
            {
                //need to change so many details
                bk.show_book();
                flag=1;
                cout<<"\n\nBook deposited in no. of days";
                cin>>day;
                if(day>15)
                {
                   fine=(day-15)*1;
                   cout<<"\n\nFine has to deposited Rs. "<<fine;
                }
                // resting the token
                
                    //st.resettoken(st.token);
                    st.token--; // returning of book noted
                    //Changing Book Status
                    strcpy(bk.Status,"Available");

                    // Changing Issue of Date 

                    strcpy(bk.DateOfIssue,"Book Not Issued");

                    //change to student file
                    int pos=-1*sizeof(st);
                    fileObj.seekp(pos,ios::cur);
                    fileObj.write((char*)&st,sizeof(Student));

                    // Modification to Book file

                    int pos2=-1*sizeof(bk);
                        fileObj1.seekp(pos2,ios::cur);
                        fileObj1.write((char*)&bk,sizeof(Book));

                    
                    cout<<"\n\n\t Book deposited successfully";
            }
            }
          if(flag==0)
            cout<<"Book no does not exist";
              }
         else
            cout<<"No book is issued..please check!!";
        }
       }
      if(found==0)
    cout<<"Student record not exist...";
    getch();
  fileObj.close();
  fileObj1.close();
  }

  // admin menu contain all admin functions

  void admin_menu()
{
    //system("clear");
    int ch2;
    cout<<"\n\n\n\tADMINISTRATOR MENU";
    cout<<"\n\n\t1.CREATE STUDENT RECORD";
    cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORD";
    cout<<"\n\n\t3.DISPLAY SPECIFIC STUDENT RECORD ";
    cout<<"\n\n\t4.MODIFY STUDENT RECORD";
    cout<<"\n\n\t5.DELETE STUDENT RECORD";
    cout<<"\n\n\t6.CREATE BOOK ";
    cout<<"\n\n\t7.DISPLAY ALL BOOKS ";
    cout<<"\n\n\t8.DISPLAY SPECIFIC BOOK ";
    cout<<"\n\n\t9.MODIFY BOOK ";
    cout<<"\n\n\t10.DELETE BOOK ";
    cout<<"\n\n\t11.BACK TO MAIN MENU";
    cout<<"\n\n\tPlease Enter Your Choice (1-11) ";
    cin>>ch2;
    switch(ch2)
    {
            case 1: //system("clear");
                write_student();break;
            case 2: display_allStudent();break;
            case 3:
                   char num[6];
                   //system("clear");
                   cout<<"\n\n\tPlease Enter The Admission No. ";
                   cin>>num;
                   display_showStudent(num);
                   break;
              case 4: modify_student_file();break;
              case 5: delete_student();break;
        case 6: //system("clear");
            write_book();break;
        case 7: display_allBooks();break;
        case 8: {
                   char num[6];
                   //system("clear");
                   cout<<"\n\n\tPlease Enter The book No. ";
                   cin>>num;
                   display_showBook(num);
                   break;
            }
              case 9: modify_book_file();break;
              case 10: delete_book();break;
             case 11: return;
              default:cout<<"\a";
       }
       admin_menu();
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
//main menu 

int main()
{
    char password[10]="admin@123";
    char typePassword[10];
    char ch;
    //intro();
    do
    {
        //system("clear");
        cout<<"\n\n\n\tMAIN MENU";
        cout<<"\n\n\t01. ADMINISTRATOR MENU";
        cout<<"\n\n\t02. USER MENU";
          cout<<"\n\n\t03.EXIT ";
          cout<<"\n\n\tPlease Select Your Option (1-3) ";
          cin>>ch;
          switch(ch)
          {
            case '1'://system("clear");
                    {
                        cout<<"\n Enter Password to Continue"<<endl;
                    cin>>typePassword;
                    if (strcmpi(typePassword,password)==0)
                    {
                        admin_menu();
                    }
                    else
                    {
                        cout<<"Wrong Password !"<<endl;
                        break;
                    }
                    }
                 
                    break;
              case '2':user_menu();
                     break;
              case '3':exit(0);
                 break;
              default :cout<<"\a";
        }
        }while(ch!='3');
}

  

  





