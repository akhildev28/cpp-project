#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class Librarian
{   
    // include protected
        int library_id,bookTaken,status_update,Book_id;
        char studentName[50],className[80],department[80],bookName[30],authorName[30];
        char issue_date[20];
        bool status;

    public:
        void AddStudent()
        {
                //add book fn
            cout << "\n\tAdd Students\t\n\n";

            //enter book name take into BookName
            cout<<"Library ID:\t";
            cin >> library_id;//

            fflush(stdin);
            //enter book name take into BookName
            cout<<"Enter student name:\t";
            cin.getline(studentName,50) ;

            //enter name of auther store it in to Auther
            cout<<"Enter class:\t";
            cin.getline(className,80);

            //enter book name take into BookName
            cout<<"Enter Department:\t";
            cin.getline(department,80) ;

            //enter book name take into BookName
            cout<<"List of book taken:\t";
            cin >> bookTaken;


        }
        Librarian()
        {bookTaken=0;}

        void AddBook()
        {
                 //add book fn
            cout << "\n\tAdd Book\t\n\n";

            //enter book name take into BookName
            cout<<"Book ID:\t";
            cin >> Book_id;//

            fflush(stdin);
            //enter book name take into BookName
            cout<<"Enter Book name:\t";
            cin.getline(bookName,50) ;

            //enter name of auther store it in to Auther
            cout<<"Enter Author Name:\t";
            cin.getline(authorName,80);

            //enter book name take into BookName
            cout<<"Enter status:\t";
            cout<<"1.Available\t2.not available\n";
            cin>>status_update;
            switch (status_update)
           {
              case 1:status=true;break;
              case 2:status=false;break;
              default:"Select correct option";
           }
            
            //enter book name take into BookName
            cout<<"Date of issue:\t";
            cin.getline(issue_date,20) ;

        }
        void display_book()
        {
            cout<<"\n";
            cout << Book_id << setw(30);
             cout<< bookName;
             cout << setw(30) << authorName;
             cout << setw(30) <<(status==true)?"available":"unavailable";
             cout << setw(30) << issue_date;
        }

};

// class Student
// {};

// class Book
// {};


int main()
{
    int option;
    while(true)
    {
        cout << "\n\tLIBRARY MANAGEMENT SYSTEM\t\n\n";
        cout << "1.Librarian\n2.Student\n3.Close\n\n";
        cout << "Enter your option:\t";
        cin  >> option;
        switch(option)
        {
            case 1: {
                        system("cls");
                        Librarian obj_Librarian;
                        fstream   StudentFile,BookFile;
                            //CBookfunction BookObj[];
                            //CStudentfunction StudentObj[]
                            //fstream BookFile,StudentFile;
                            //int option1,bookNum,studentNum,itr;       // Bitr --> iterating variable
                        int option1,studentNum,bookNum;
                        char choice;
                        string studentName;
                        while(true)
                        {
                            cout << "\n\tLIBRARY MANAGEMENT SYSTEM\t\n\n";
                            cout << "\n\tLibrarian port\t\n\n";
                            cout << "1.Add a new student.\n2.Remove an existing student.\n3.Update the student details.\n4.Add new books.\n5.Remove a book.\n6.View all books\n7.Book requests.\n8.Logout.\n\nEnter your choice:\t\n";
                            cin >> option1;
                            switch(option1)
                            {
                                //============ADD STUDENT==================
                                case 1: system("cls");
                                        cout << "\n\tAdd Students\t\n\n";
                                        StudentFile.open("Student_details.txt",ios::app);

                                        // to add students
                                        do
                                        {
                                            obj_Librarian.AddStudent();
                                            StudentFile.write((char*)&obj_Librarian,sizeof(obj_Librarian));   //write the arrayobject to the file
                                            cout<<"\n\ndo you want to add more record..(y/n?)\t";
                                            cin>>choice;
                                        }while (choice =='y' || choice =='Y');
                                        StudentFile.close();
                                        break;

                                //=========== REMOVE STUDENT ==================
                                case 2: cout << "\n\tRemove an existing student\n";
                                        cout << "Enter the student name:";
                                        cin >> studentName;
                                        cout << studentName;
                                                system("cls"); 
                                                break;
                                
                                //============ UPDATE STUDENT DETAILS ===========
                                case 3: cout << "Librarian()";
                                                system("cls"); 
                                                break;

                                //============ ADD NEW BOOK ==================
                                case 4: system("cls");
                                        cout << "\n\tADD NEW BOOK\t\n\n";
                                        BookFile.open("Book_details.txt",ios::app);

                                        // to add students
                                        do
                                        {
                                            obj_Librarian.AddBook();
                                            BookFile.write((char*)&obj_Librarian,sizeof(obj_Librarian));   //write the arrayobject to the file
                                            system("cls"); 
                                            cout << "New Book has been inserted successfully";
                                            cout <<"\n\ndo you want to add more record..(y/n?)";
                                            cin>>choice;
                                        }while(choice=='y'|| choice=='Y');
                                        BookFile.close();
                                        system("cls"); 
                                        break;

                                //============ REMOVE BOOK =================
                                case 5: cout << "Librarian()";
                                                system("cls"); 
                                                break;

                                //============ VIEW ALL BOOKS ==============
                                case 6: system("cls");
                                        BookFile.open("Book_details.txt",ios::binary|ios::in);
                                        cout << "\n\tBOOK DETAILS\t\n\n";
                                        cout << "Book_ID" <<setw(30) << "Book_Name" <<setw(30) << "Author_Name" <<setw(30) << "Status" <<setw(30) << "Issue_date\n";
                                        cout <<"==================================================================================";    
                                        while(BookFile.read((char*)&obj_Librarian,sizeof(Librarian)))
                                        {
                                            obj_Librarian.display_book();
                                        }
                                        BookFile.close(); 
                                        break;

                                //============ SHOW REQUEST ===============
                                case 7: cout << "Librarian()";
                                                system("cls"); 
                                                break;

                                //============ LOGOUT ===================
                                case 8: cout << main();
                                                system("cls"); 
                                                break;

                                default: cout << "Wrong choice, select a valid option.";
                            }
                        }
                    }
                    break;
            case 2: system("cls");
                    cout << "Student()";
                    break;
            case 3: exit(0); break;
            default: cout << "Wrong choice, select a valid choice";
        }
    }
    return 0;
}