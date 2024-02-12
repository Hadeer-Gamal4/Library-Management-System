#include <iostream>
#include<string>
using namespace std;

const int librarySize = 6;   //the max size of places in library. 
int numOfBooks=5;            //the num of books in library.
   
   
   //each book has some details (id,title,name of author,status if the book is avalible or not).
int ids[librarySize]={};
string titles [librarySize]={"To Kill a Mockingbird", "1984","Pride and Prejudice", "The Great Gatsby", "The Hobbit"};
string authors [librarySize]={"Harper lee", "George Orwell", "Jane Austen" , "F.Scott Fitzgerald", "J.R.R Tolkien"};

bool status[librarySize]={true, true , false , true , false};


/*
the system can do :

display books data --
add new book --
borrow book --
return book --
update book --
delete book

search --


*/

void mainMenu(){
	cout<<"Welcome to Enchanted Book Haven Library\n";
	cout<<"=========================================\n\n\n";
	cout<<"choose an option: \n";
	cout<<"============================\n\n";
	cout<<"1-Display all books data\n";
	cout<<"2-Add new book to the system\n";
	cout<<"3-Borrow a book from the library\n";
	cout<<"4-Return the book to the library\n";
	cout<<"5-Update details in particular book\n";
	cout<<"6-Delete\n";
	cout<<"7-Exit\n";
	cout<<"\n\nYour choice: ";
}

void confirmMenu(){
	cout<<"Do you confirm?\n\n";
		cout<<"1-Yes\n";
		cout<<"2-No\n";
		cout<<"\n Your choice: ";
}

void updateMenu(){
	cout<<"What do you want to update?\n\n";
			cout<<"1-title\n";
			cout<<"2-author\n";
			cout<<"3-status\n";
			cout<<"\n\nYour choice: ";
}

//to display details about  particular book.
void displayBook(int id , string title , string author , bool status){
	string bookStatus;
	if(status){
		bookStatus="available";
	}
	else
	{
		bookStatus="not available";
	}
	cout<<"Book Info: \n";
	cout<<"===========\n\n";
	cout<<"ID: "<<id<<endl;
	cout<<"Title: "<<title <<endl;
	cout<<"Auothers: "<<author <<endl;
	cout<<"status: "<<bookStatus<<endl;
	cout<<"====================================\n\n\n";
}

//to display details about all books in the library.
void displayBooksData(){
	for(int i=0 ; i<numOfBooks ; i++){
		displayBook(ids[i], titles[i], authors[i], status[i]);
	}
}


void addNewBook(){
	if(numOfBooks==librarySize){
		cout<<"\n\n you can not add new books to the system! \n\n";
	}
	else {
		string title, author,bookStatus;
	bool temp; 
	cout<<"Enter new book title: ";
	cin>>title;
	cout<<"Enter new book author: ";
	cin>>author;
	cout<<"Enter new book status: ";
	cin.ignore();
	getline(cin, bookStatus);
	
	if(bookStatus=="available"){
		temp=true;
	}
	else if (bookStatus=="not available"){
		temp=false;
	}
	
	titles[numOfBooks]=title;
	authors[numOfBooks]=author;
	status[numOfBooks]=temp;
	ids[numOfBooks]=numOfBooks+1;
	numOfBooks++;
	}
}

int search(int id) {
	for(int i=0 ; i<numOfBooks ; i++){
		if(ids[i]==id){
			return i;
		}
	}
	return -1;
}	
	


void borrowBook(){
	int id, searchIndex,choice;
	cout<<"Enter the id of the book you want to borrow: \n";
	cin>>id;
	searchIndex=search(id);
	if(searchIndex== -1){
		cout<<"\n\nBook is not found!\n\n";
	}
	else {
		
		if(status[searchIndex]==true)
		{
		  displayBook(id , titles[searchIndex], authors[searchIndex],status[searchIndex]);
		  confirmMenu();
		  cin>>choice;
		if(choice == 1){
			status[searchIndex]=false;
			cout<<"\n\nBook is borrowed successfully!\n\n";
		}
			
	}
		else {
			cout<<"\n\n Book is already borrowed!\n\n";
		}
	}
	
}

void returnBook(){
	int id, searchIndex,choice;
	cout<<"Enter the id of the book you want to return: \n";
	cin>>id;
	searchIndex=search(id);
	if(searchIndex== -1){
		cout<<"\n\nBook is not found!\n\n";
	}
	else {
		if(status[searchIndex]==false)
		{
			displayBook(id , titles[searchIndex], authors[searchIndex],status[searchIndex]);
		  confirmMenu();
		  cin>>choice;
		if(choice == 1){
			status[searchIndex]=true;
			cout<<"\n\nBook is returned successfully!\n\n";
		
		 }
	}
		else {
			cout<<"\n\n Book is already returned!\n\n";
		}
	}
}


void updateBook(){
	int id, searchIndex,choice;
	cout<<"Enter the id of the book you want to update: \n";
	cin>>id;
	searchIndex=search(id);
	if(searchIndex== -1){
		cout<<"\n\nBook is not found!\n\n";
	}
	else {
		displayBook(id , titles[searchIndex], authors[searchIndex],status[searchIndex]);
		  confirmMenu();
		  cin>>choice;
		if(choice == 1){
			string input;
			updateMenu();
			cin>>choice;
			switch(choice){
				case 1:
					cout<<"Enter new title: "<<endl;
					cin.ignore();
					getline(cin , input);
					titles[searchIndex]=input;
					break;
				case 2:
					cout<<"Enter new author: "<<endl;
					cin.ignore();
					getline(cin , input);
					authors[searchIndex]=input;
			    	break;
				case 3:
					cout<<"Enter new status: "<<endl;
					cin.ignore();
					getline(cin , input);
					status[searchIndex]= input=="available"? true:false ;
				    break;
				default :
				    cout<<"Wromg input!\n\n";		
			}
			
			cout<<"\n\nBook is updated successfully!\n\n";
		
		 }
	}
}
void deleteBook(){
	int id, searchIndex,choice;
	cout<<"Enter the id of the book you want to delete: \n";
	cin>>id;
	searchIndex=search(id);
	if(searchIndex== -1){
		cout<<"\n\nBook is not found!\n\n";
	}
	else {
		  displayBook(id , titles[searchIndex], authors[searchIndex],status[searchIndex]);
		  confirmMenu();
		  cin>>choice;
		if(choice == 1){
			for(int i= searchIndex ; i<numOfBooks-1 ; i++){
				titles[i]=titles[i+1];
				authors[i]=authors[i+1];
				status[i]=status[i+1];
			}
			ids[numOfBooks-1]=0;
			numOfBooks--;
			cout<<"\n\nBook is deleted successfully!\n\n";
		}
			
	}
	
}

int main (){
	for(int i=0 ; i<numOfBooks ; i++){
		ids[i]=i+1; //0 0 0 0 0 0
		           //1 2 3 4 5
	}
	int choice;
	bool flag= true;
	while(flag){
	mainMenu();
	cin>>choice;
	switch (choice){
		case 1:
			displayBooksData();
			break;
		case 2:
		    addNewBook();
			break;
		case 3:
		    borrowBook();
			break;
		case 4:
		    returnBook();
			break;
		case 5 :
		    updateBook();
			break;
		case 6:
		    deleteBook();
			break;					
		case 7:
			cout<<"\n\n Goodbye!\n\n";
				flag=false;
				break;
		default : 
			 cout<<"wrong input!\n\n\n";
	}
	}
	return 0;
}
