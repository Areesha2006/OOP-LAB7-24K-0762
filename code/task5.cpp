#include<iostream>
#include<string>
using namespace std;
class Media{
    int uniqueID;
    static int counter;
    string publicationDate,publisher,title;
    public:
        Media(string title,string date,string pub):uniqueID(counter++),title(title),publicationDate(date),publisher(pub){}
        void displayInfo(){
            cout<<"ID: "<<uniqueID<<endl;
            cout<<"Title: "<<title<<endl;
            cout<<"Publication Date: "<<publicationDate<<endl;
            cout<<"Publisher: "<<publisher<<endl;
        }
        int search(string title){
            if(this->title==title){
                return 1;
            }
            else{
                return 0;
            }
        }
};
class Book: public Media{
    int ISBN,numberOfPages;
    string author;
    public:
        Book(string title,string date,string pub,int isbn,int pages,string author):Media(title,date,pub),ISBN(isbn),numberOfPages(pages),author(author){}
        void displayInfo(){
            Media::displayInfo();
            cout<<"ISBN: "<<ISBN<<endl;
            cout<<"Author: "<<author<<endl;
            cout<<"Number Of Pages: "<<numberOfPages<<endl;
        }
        int search(int isbn){
            if(ISBN==isbn){
                return 1;
            }
            else{
                return 0;
            }
        }
};
class DVD: public Media{
    int rating,duration;
    string director;
    public:
        DVD(string title,string date,string pub,int rate,int dur,string director):Media(title,date,pub),rating(rate),duration(dur),director(director){}
        void displayInfo(){
            Media::displayInfo();
            cout<<"Director: "<<director<<endl;
            cout<<"Duration: "<<duration<<endl;
            cout<<"Rating: "<<rating<<endl;
        }
        int search(int rate){
            if(rating==rate){
                return 1;
            }
            else{
                return 0;
            }
        }
};
class CD: public Media{
    int numberOfTracks;
    string artist,genre;
    public:
        CD(string title,string date,string pub,int tracks,string artist,string genre):Media(title,date,pub),artist(artist),numberOfTracks(tracks),genre(genre){}
        void displayInfo(){
            Media::displayInfo();
            cout<<"Artist: "<<artist<<endl;
            cout<<"Genre: "<<genre<<endl;
            cout<<"Number Of Tracks: "<<numberOfTracks<<endl;
        }
        int search(int tracks){
            if(numberOfTracks==tracks){
                return 1;
            }
            else{
                return 0;
            }
        }
};
int Media::counter=1;
int main(){
    Media *media;
    int rating,dur,book_num,dvd_num,cd_num,isbn,pages,tracks;
    string title,date,publisher,author,director,artist,genre;
    cout<<"How many books are there: ";
    cin>>book_num;
    Book *books[book_num];
    cout<<"Enter details for each book"<<endl;
    for (int i = 0; i < book_num; i++)
    {
        cout<<endl<<"For Book "<<i+1<<endl;
        cout<<"Enter title: ";
        cin>>title;
        cout<<"Enter publication date: ";
        cin>>date;
        cout<<"Enter publisher: ";
        cin>>publisher;
        cout<<"Enter author: ";
        cin>>author;
        cout<<"Enter ISBN: ";
        cin>>isbn;
        cout<<"Enter number of pages: ";
        cin>>pages;
        books[i]=new Book(title,date,publisher,isbn,pages,author);
    }
    cout<<endl<<"How many DVDs are there: ";
    cin>>dvd_num;
    DVD *dvds[dvd_num];
    cout<<"Enter details for each DVD"<<endl;
    for (int i = 0; i < dvd_num; i++)
    {
        cout<<endl<<"For DVD "<<i+1<<endl;
        cout<<"Enter title: ";
        cin>>title;
        cout<<"Enter publication date: ";
        cin>>date;
        cout<<"Enter publisher: ";
        cin>>publisher;
        cout<<"Enter director: ";
        cin>>director;
        cout<<"Enter duration: ";
        cin>>dur;
        cout<<"Enter rating: ";
        cin>>rating;
        dvds[i]=new DVD(title,date,publisher,rating,dur,director);
    }
    cout<<endl<<"How many CDs are there: ";
    cin>>cd_num;
    CD *cds[cd_num];
    cout<<"Enter details for each CD"<<endl;
    for (int i = 0; i < cd_num; i++)
    {
        cout<<endl<<"For CD "<<i+1<<endl;
        cout<<"Enter title: ";
        cin>>title;
        cout<<"Enter publication date: ";
        cin>>date;
        cout<<"Enter publisher: ";
        cin>>publisher;
        cout<<"Enter artist: ";
        cin>>artist;
        cout<<"Enter genre: ";
        cin>>genre;
        cout<<"Enter number of tracks: ";
        cin>>tracks;
        cds[i]=new CD(title,date,publisher,tracks,artist,genre);
    }
    int c1,c2,c3;
    while(1){
        cout<<"Enter the appropriate key to perform the desired function\n1.Display details\n2.Search Media\nAny other key to exit\nEnter: ";
        cin>>c1;
        switch(c1){
            case 1:
                cout<<"Enter the appropriate key to according to your media\n1.Book\n2.DVD\n3.CD\nEnter: ";
                cin>>c2;
                switch(c2){
                    case 1:
                        if(book_num!=0){
                            for(int i=0;i<book_num;i++){
                                cout<<endl<<"Book "<<i+1<<endl;
                                books[i]->displayInfo();                                            }
                        }
                        else{
                            cout<<"No book found"<<endl;
                        }
                        break;
                    case 2:
                        if(dvd_num!=0){
                            for(int i=0;i<dvd_num;i++){
                                cout<<endl<<"DVD "<<i+1<<endl;
                                dvds[i]->displayInfo();                                            }
                        }
                        else{
                            cout<<"No DVD found"<<endl;
                        }
                        break;
                    case 3:
                        if(cd_num!=0){
                        for(int i=0;i<cd_num;i++){
                            cout<<endl<<"CD "<<i+1<<endl;
                            cds[i]->displayInfo();                                            }
                        }
                        else{
                            cout<<"No CD found"<<endl;
                        }    
                        break;
                    default:
                        cout<<"Invalid input"<<endl;
                }
                break;
            case 2:
                cout<<"Enter the appropriate key to according to your media\n1.Book\n2.DVD\n3.CD\nEnter: ";
                cin>>c2;
                switch(c2){
                    case 1:
                        cout<<"By Which attribute you want to search the book\n1.Title\n2.ISBN\nEnter: ";
                        cin>>c3;
                        if(c3==1){
                            int found=0;
                            cout<<"Enter the title: ";
                            cin>>title;
                            for(int i=0;i<book_num;i++){
                                media=books[i];
                                if(media->search(title)){
                                    found=1;
                                    cout<<"Book Found"<<endl;
                                    books[i]->displayInfo();
                                    break;
                                }
                            }
                            if(!found){
                                cout<<"No book found with title "<<title<<endl;
                            }
                        }
                        else if(c3==2){
                            int found=0;
                            cout<<"Enter the ISBN: ";
                            cin>>isbn;
                            for(int i=0;i<book_num;i++){
                                if(books[i]->search(isbn)){
                                    found=1;
                                    cout<<"Book Found"<<endl;
                                    books[i]->displayInfo();
                                    break;
                                }
                            }
                            if(!found){
                                cout<<"No book found with ISBN "<<isbn<<endl;
                            }
                        }
                        else{
                            cout<<"Invalid input"<<endl;
                        }
                        break;
                    case 2:
                        cout<<"By Which attribute you want to search the book\n1.Title\n2.Rating\nEnter: ";
                        cin>>c3;
                        if(c3==1){
                            int found=0;
                            cout<<"Enter the title: ";
                            cin>>title;
                            for(int i=0;i<dvd_num;i++){
                                media=dvds[i];
                                if(media->search(title)){
                                    found=1;
                                    cout<<"DVD Found"<<endl;
                                    dvds[i]->displayInfo();
                                    break;
                                }
                            }
                            if(!found){
                                cout<<"No DVD found with title "<<title<<endl;
                            }
                        }
                        else if(c3==2){
                            int found=0;
                            cout<<"Enter the rating: ";
                            cin>>rating;
                            for(int i=0;i<dvd_num;i++){
                                if(dvds[i]->search(rating)){
                                    found=1;
                                    cout<<"DVD Found"<<endl;
                                    dvds[i]->displayInfo();
                                    break;
                                }
                            }
                            if(!found){
                                cout<<"No DVD found with rating "<<rating<<endl;
                            }
                        }
                        else{
                            cout<<"Invalid input"<<endl;
                        }
                        break;
                    case 3:
                        cout<<"By Which attribute you want to search the book\n1.Title\n2.Number of tracks\nEnter: ";
                        cin>>c3;
                        if(c3==1){
                            int found=0;
                            cout<<"Enter the title: ";
                            cin>>title;
                            for(int i=0;i<cd_num;i++){
                                media=cds[i];
                                if(media->search(title)){
                                    found=1;
                                    cout<<"CD Found"<<endl;
                                    cds[i]->displayInfo();
                                    break;
                                }
                            }
                            if(!found){
                                cout<<"No CD found with title "<<title<<endl;
                            }
                        }
                        else if(c3==2){
                            int found=0;
                            cout<<"Enter the number of tracks: ";
                            cin>>tracks;
                            for(int i=0;i<cd_num;i++){
                                if(cds[i]->search(tracks)){
                                    found=1;
                                    cout<<"CD Found"<<endl;
                                    cds[i]->displayInfo();
                                    break;
                                }
                            }
                            if(!found){
                                cout<<"No CD found with number of tracks "<<tracks<<endl;
                            }
                        }
                        else{
                            cout<<"Invalid input"<<endl;
                        }
                        break;
                    default:
                        cout<<"Invalid input"<<endl;
                }    
                break;
            default:
                cout<<"Exited successfully";
                delete[] books;
                delete[] dvds;
                delete[] cds;
                return 0;            
        }
        cout<<endl;
    }
}