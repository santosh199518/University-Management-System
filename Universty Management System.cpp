#include<iostream>
#include<fstream>
#include<cstring>
#include<ctime>
using namespace std;
class Faculty{
	string TuserId,Tpassword;
public:
	string getTuserId(){return TuserId;}
	string getTpassword(){return Tpassword;}
	void setTuserId(string userId){this->TuserId=userId;}
	void setTpassword(string password){this->Tpassword=password;}
};

class Student{
private:
	string SuserId,Spassword;
public:
	string getSuserId(){return this->SuserId;}
	string getSpassword(){return this->Spassword;}
	void setSuserId(string userId){this->SuserId=userId;}
	void setSpassword(string password){this->Spassword=password;}
};
int main(){
	Student S;
	Faculty T;
	T.setTpassword("23320");T.setTuserId("23320");
	string userId,password;
	string userType,Task;
	bool loginSuccess=false;
	int opt,Tcount=0,Scount=0,size=0,trial=3;
	int dd,mm,yy=2019;
	char status,dis;
	
	do{

	do
	{
	    cout<<"\tPlease enter the type of User to contnue...\n";
	    cout<<"1.)Faculty / Admin\t";
	    cout<<"2.)Student\nType of User ::";
	    cin>>userType;
	    if(userType=="Faculty"||userType=="Admin"||userType=="Student")
		{
		    cout<<"\tPlease enter the option number to continue...\n";
		    cout<<"1.)Log-in \t2.)Change Password \t3.)Create an Account \nOption ::";
		    cin.ignore();
		    cin>>opt;
		    if(opt==1)
			{
                cout<<"\tPlease enter the User-Id and Passsword to continue...\n";
	
	            do{
	            	cout<<"User-ID:  ";
	                cin>>userId;
	                cout<<"Password: ";
                 	cin.ignore();
                    cin>>password;
                    if(userType=="Student")
	                {
 	                    S.setSuserId(userId);
 	                    S.setSpassword(password);
 	                    cout<<"userId::"<<S.getSuserId()<<"\tPassword::"<<S.getSpassword()<<endl;
 	                    ifstream in("Student.txt",ios::in);
 	                    in.seekg(0,ios::beg);
 	                    while(!in.eof()){
  	                        in.ignore();
 	                        in>>userId;
                            in.ignore();
                            in>>password;
                            if(userId==S.getSuserId()&&password==S.getSpassword())
							{
							loginSuccess=true;
		                    Scount++;
				            trial=0;
		                    system("cls");
							break;}
                            }
                        if(userId!=S.getSuserId()&&password!=S.getSpassword())
						{
							loginSuccess=false;
							cerr<<"\n\tSorry! The Id and Password doesn't matches. Please try again...\n\tTrial left:- "<<--trial<<endl;
					    }
                    }
                    else if(userType=="Faculty"||userType=="Admin")
					{
	                    if(userId==T.getTuserId()&&password==T.getTpassword())
						{
							loginSuccess=true;
							Tcount++;
							trial=0;
							system("cls");
						}
	                    else
						{
						    cerr<<"\n\tSorry! The Id and Password doesn't matches. Please try again...\n\tTrial left:- "<<--trial<<endl;
						    loginSuccess=false;
					    }
					}
                    else{cout<<"Enter correct user type..\n";return 0;}
                    }while(trial>0);
            }
            else if(opt==2)
	        {
	            if(userType=="Admin"||userType=="Faculty")
	                {
	                	cout<<"Please enter the UID ::";
	                    cin>>userId;
	                    cout<<"Please enter the old Password ::";
	                    cin>>password;
	                    if(password==T.getTpassword())
	                        {
	                            cout<<"New Password ::";
		                        cin>>password;
		                        T.setTpassword(password);
		                        cout<<"\tPassowrd changed successfully...\n";
	                        }
	                        else{cerr<<"\tWrong Password\n";}
	                        loginSuccess=false;
	                    }
	            else if(userType=="Student")
	            {
	                cout<<"UserId::";cin>>userId;
	                cout<<"Password::";cin>>password;
	                S.setSuserId(userId);
	                S.setSpassword(password);
	                ifstream in("Student.txt",ios::in);
                    while(!in.eof()){
                    	in.ignore();
    	                in>>userId;
    	                in.ignore();
    	                in>>password;
    	                if(S.getSpassword()==password&&S.getSuserId()==userId){
    	                	cout<<"Enter new password::";
                            cin>>password;
                            S.setSpassword(password);
                            break;
						}
					}
					if(S.getSpassword()!=password&&S.getSuserId()!=userId){cerr<<"\tUser ID and Password doesn't matches.\n";
					}
					else{
                    ofstream out("Student_new.txt",ios::out);
                    out<<" ";
                    in.seekg(0,ios::beg);
                    while(!in.eof())
					{
    	                in.ignore();
    	                in>>userId;
    	                out<<userId<<"    ";
    	                if(S.getSuserId()==userId)
						{
    		                in.ignore();
    		                in>>password;
						    out<<S.getSpassword()<<endl;
    		            }
		                else
						{
    	                    in.ignore();
    	                    in>>password;
    	                    out<<password<<endl;
                        }
    	            }
    	            out.close();
	                in.close();
	                remove("Student.txt");
	                rename("Student_new.txt","Student.txt");
	                loginSuccess=false;}
	            }
	            else{cerr<<"\tUID not found\n";}
	        }
	        else if(opt==3)
	        {
	        	if(userType=="Student")
				{
					ofstream out("Student.txt",ios::app);
	                cout<<"Enter the UserId and password to create a new account."<<endl;
	                cout<<"UserId::";cin>>userId;
	                out<<endl<<userId<<"    ";
	                cout<<"Password::";cin>>password;
	                out<<password;
	                cout<<"\tAccount created successfully...\n";
				}
				else{cout<<"\t Sorry Admin/Faulty is only one\n\tCannot Create Account...\n";
				}
	        }
            else{cout<<"\tPlease enter correct number...\n";}
        }
        else{cout<<"\tPlease enter correct user type. Try again...\n";}
    }while(!loginSuccess);
    
    cout<<"\n\t\tLogin Successful...\n";
    cout<<"\t\tWelcome "<<userId<<" to our software."<<endl;
    if(userType=="Student"){cout<<"\t\tNumber of time log-in :: "<<Scount<<endl;}
	else{cout<<"\t\tNumber of time log-in :: "<<Tcount<<endl;}
	
	do{
    if(userType=="Faculty"||userType=="Admin"){
    	cout<<"\nPlease enter the option number display below :->\n";
    	cout<<"1.)Create a Task\n2.)Assigned a task with Date\n3.)Update the task\n4.)Delete a task\n5.)Display the submission details\n";
		cout<<"6.)Declare or announced the Topper\n0.)Log-out\nOption ::";
		cin.ignore();
		cin>>opt;
		if(opt==1){
			ofstream out("Task.txt",ios::out);
			cout<<"Enter the Task ::\n";
			cin.ignore();
			getline(cin,Task);
			out<<" "<<Task;
			out.close();
			cout<<"\tTask created Successfully...\n";
		}
		else if(opt==2){
			ifstream in("Task.txt",ios::in);
			if(!in){
				cout<<"\tCannot open the file.\n";
			}
			in.ignore();
			getline(in,Task);
			in.close();
			cout<<"Available Task is:->\n"<<Task;
			cout<<"\nSelect the options:\n";
			cout<<"1.)To individual\t2.)To all\nOption ::";
			cin>>opt;
			if(opt==1)
			{
				cout<<"Enter the UID of the student ::";
				cin>>userId;
				S.setSuserId(userId);
				cout<<"\nEnter the date of submission in format dd/mm/yy::";
				cout<<"\nDay::";cin>>dd;
				cout<<"\nMonth::";cin>>mm;
				cout<<"\nYear::";cin>>yy;
				ifstream in1("Student.txt");
				bool res = false;
				while(!in1.eof())
				{
				    in1.ignore();
				    in1>>userId;
				    if(userId==S.getSuserId())
					{
						res = true;
					    userId.append(".txt");
					    ofstream out(userId.c_str(),ios::out);
					    out<<" "<<Task<<endl;
					    out<<dd<<"/"<<mm<<"/"<<yy<<endl;
					    out.close();
					    cout<<"\tTask assign sucessfully...\n";
					    break;
				    }
				    in1.ignore();
				    in1>>password;
				}
				if(!res){cout<<"\tUID not found...\n\tCannot Assign the Task.\n";}
			}
			    if(opt==2)
				{
					cout<<"\nEnter the date of submission for all in format dd/mm/yy::";
				    cout<<"\nDay::";cin>>dd;
				    cout<<"\nMonth::";cin>>mm;
				    cout<<"\nYear::";cin>>yy;
					ifstream in1("Student.txt",ios::in);
					while(!in1.eof())
					{
						in1.ignore();
						in1>>userId;
						userId.append(".txt");
					    ofstream out(userId.c_str(),ios::out);
					    out<<" "<<Task<<endl;
					    out<<dd<<" / "<<mm<<" / "<<yy<<endl;
					    out.close();
					    in1.ignore();
					    in1>>password;
					}
					in1.close();
				    cout<<"\tTask assign to all sucessfully\n";
				}
			//}
		}
		else if(opt==3){
			cout<<"1.)To individual\t2.)To all\nOption ::";
			cin>>opt;
			if(opt==1){
				cout<<"Enter the UID of student ::";
				cin>>userId;
				S.setSuserId(userId);
				userId.append(".txt");
				ifstream in(userId.c_str(),ios::in);
			//	if(in.is_open()){
					getline(in,Task);
		//			in.close();
					cout<<"Available task is:->\n"<<Task<<endl;
					cout<<"Do you want to update? Press y/n::";
					cin>>dis;
					if(dis=='y'){
						cout<<"Enter the new task:->\n";
						cin.ignore();
						getline(cin,Task);
						cout<<"Do you want to update the submission date also? Press y/n::";
						cin>>dis;
						if(dis=='y')
						{
							cout<<"\nEnter the date of submission in format dd/mm/yy::";
				            cout<<"\nDay::";cin>>dd;
				            cout<<"\nMonth::";cin>>mm;
				            cout<<"\nYear::";cin>>yy;
				            ofstream out("Student.txt",ios::trunc);
				            out<<" "<<Task<<endl;
				            out<<dd<<" / "<<mm<<" / "<<yy;
				            out.close();
						}
						else
						{
							const char* str=S.getSuserId().append("_New.txt").c_str();
							ofstream out(str,ios::out);
							out<<Task<<endl;
							getline(in,Task);
							in.ignore();
							getline(in,Task);
							out<<" "<<Task<<endl;
							out.close();
							const char* str1=userId.c_str();
							remove(str1);
							rename(str1,str);
						}
						cout<<"\tTask updated Successfully...\n";
					}
			}
			if(opt==2){
				cout<<"Enter the new Task for all:->\n";
				getline(cin,Task);
				cout<<"Enter the common date of submission for all:->\n";
				cout<<"\nDay::";cin>>dd;
				cout<<"\nMonth::";cin>>mm;
				cout<<"\nYear::";cin>>yy;
				ifstream in("Student.txt",ios::in);
				while(!in.eof())
				{
					in.ignore();
					in>>userId;
					userId.append(".txt");
					ofstream out("Student.txt",ios::out);
					out<<Task<<endl;
					out<<dd<<" / "<<mm<<" / "<<yy;
					out.close();
					in.ignore();
					in>>password;
				}
				in.close();
			}
		}
		else if(opt==4){
			cout<<"1.)To individual\t2.)To all\nOption ::";
			cin>>opt;
			if(opt==1){
			cout<<"Enter the UID :-> ";
			cin>>userId;
			userId.append(".txt");
			ifstream in("Student.txt",ios::in);
			getline(in,Task);
			cout<<"The task give is :->\n"<<Task<<"\ndo you want to delete it? Press y/n...";
			cin>>dis;
			if(dis=='y')
			{
				const char* str=userId.c_str();
			    remove(str);
			    cout<<"\t"<<userId<<" is deleted Sucessfully of\n";
			}
		 }
			else if(opt==2){
				ifstream in("Student.txt",ios::in);
				while(!in.eof()){
				in.ignore();
				in>>userId;
				userId.append(".txt");
				const char* str=userId.c_str();
				remove(str);
				in.ignore();
				in>>password;
			    }
			    cout<<"\tAll Tasks are deleted Sucessfully...";
			}
			else{cout<<"Please enter correct option.\n";}
		}
		else if(opt==5){
			cout<<"1.)First Five Student\t2.)Last Five Student\nOption ::";
			cin>>opt;
			ifstream in("Student.txt",ios::in);
			if(opt==1){
				int i=1;
				while(!in.eof())
				{
					in>>userId;
					userId.append(".txt");
					fstream in1(userId.c_str(),ios::in | ios::out);
					getline(in1,Task);
					getline(in1,Task);
					cout<<"Date of submission of "<<i++<<" student from first is :->\n"<<Task<<endl;
					in.ignore();
					in>>password;
					in1.close();
				}
			}
			else if(opt==2){
				int i=5;
				in.seekg(-101,ios::end);
				while(!in.eof())
				{
					in>>userId;
					userId.append(".txt");
					ifstream in1(userId.c_str(),ios::in);
					getline(in1,Task);
					getline(in1,Task);
					cout<<"Date of submission of "<<i--<<" student from last is :->\n"<<Task<<endl;
					in.ignore();
					in>>password;
				}
			}
			else{cout<<"Please enter correct option.\n";}
		}
		else if(opt==6){
			cout<<"Enter the UID of winner:->";
			cin>>userId;
			ofstream out("Result.txt",ios::out);
			out<<"\tThe UID of the winner is :->"<<userId<<"\n";
			out.close();
		}
		else if(opt==0){
			cout<<"\tyou have been log-out successfully...\n";
		}
		else{
			cerr<<"\tPlease Enter the correct option.\n";
		}
 }
	else if(userType=="Student"){
		cout<<"\nPlease select the option number display below :->\n";
		cout<<"1.)View task\n2.)Submit an assigned task\n3.)Submission Date Checking\n4.)View task with date\n5.)view the final result\n0.)Log-out\nOption ::";
		cin.ignore();
		cin>>opt;
		if(opt==1){
			userId.append(".txt");
			ifstream in(userId.c_str(), ios::in);
			getline(in,Task);
			if(!Task.empty()){
			cout<<"The available Task is \n:->"<<Task<<endl;
		    }
		    else{cout<<"No task is alloted\n";}
		}
		else if(opt==2){
			ifstream in(S.getSuserId().append(".txt").c_str(),ios::in);
			getline(in,Task);
			in>>dd;
			in.ignore();
			in>>mm;
			in.ignore();
			in>>yy;
			time_t now;
	        struct tm nowLocal;
	        now=time(NULL);
	        nowLocal=*localtime(&now);
	        if(nowLocal.tm_mon+1<=mm && nowLocal.tm_mday<=dd){
	        	cout<<"Task submitted successfully.\n";
			}
			else{cout<<"You are out of deadline.\n";
			}
		}
		else if(opt==3){
			ifstream in(S.getSuserId().append(".txt").c_str(),ios::in);
			getline(in,Task);
			getline(in,Task);
			cout<<"The Last date of submission is:->\n"<<Task<<endl;
		}
		else if(opt==4){
			ifstream in(S.getSuserId().append(".txt").c_str(),ios::in);
			getline(in,Task);
			cout<<"The Task with submission date is:->\n"<<Task<<endl;
			getline(in,Task);
			cout<<Task<<endl;
		}
		else if(opt==5){
			ifstream in("Result.txt",ios::in);
			if(!in.is_open()){
				cout<<"Sorry result isn't declared.\n";
			}
			getline(in,Task);
			cout<<Task<<endl;
			in.close();
		}
		else if(opt==0){
			cout<<"\tYou have been log-out successfully...\n";
		}
		else{
			cerr<<"\nPlease Enter the correct option...\n";
		}
	}
    }while(opt!=0);
    cout<<"Press C to continue or any key to exit the program ::";
    cin.ignore();
    cin>>status;
    system("cls");
    
    }while(status=='C');
    cout<<"\n\tThank you for using our software...\n";
}
