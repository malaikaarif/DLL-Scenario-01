// Question 1: You are designing a music playlist manager app where users can add songs, remove songs, 
// and navigate through the playlist both forwards and backwards.
// •	Implement a Doubly Linked List with each node containing a song's ID and name.
// •	Write functions to:
// •	Add a song at the head (addSongAtHead).
// •	Add a song at the tail (addSongAtTail).
// •	Remove a song by ID (removeSongById).
// •	Search for a song by ID (searchSongById).
// •	Print the playlist forward (printPlaylistForward).
// •	Print the playlist backward (printPlaylistBackward).



#include <iostream>
#include <string>
using namespace std;

struct Node{
    public:
      int id;
      string name;
      Node* prev;
      Node* next ;

      // constructor
      Node(int id, string name){
        this->id=id;
        this->name=name;
        this->prev=NULL;
        this->next=NULL;
      }

      // destructor
      ~Node(){
        cout<<"Memory is free for node with "<< id << "-" << name << endl;
        next=NULL;
      }

};


// -------------------------------------------------------------------------------------------------------------


class Song{
    private:
     Node*head;
     Node*tail;

     public:
     Song(){
        head=NULL;
        tail=NULL;
     }




    //  ----------------------------------------------------------------------------------------------------------


     void addSongAtHead(int id, string name){
        Node* newNode = new Node(id,name);
        // empty list
        if(head == NULL){
            head=newNode;
            tail=newNode;
            return;
        }
          newNode -> next = head;
          head -> prev = newNode;
          head= newNode;
     }


// ---------------------------------------------------------------------------------------------------------------

     void addSongAtTail(int id, string name){
        Node* newNode = new Node(id,name);
        // empty list
        if(head == NULL){
            head=newNode;
            tail=newNode;
            return;
        }

         newNode -> prev = tail;
         tail -> next = newNode;
         tail=newNode;

    
     }

    //  ----------------------------------------------------------------------------------------------------------


     void removeSongById(int id){
        // if empty list
        if(head == NULL){
            cout<<" No songs are availabe! "<<endl;
            return;
        }


        // if it is on first position

        Node*temp=head;
        if(head -> id == id){
              head=head -> next;
              head -> prev = NULL;
              temp -> next = NULL;
              delete temp;
              if(head==NULL){
                tail=NULL;
              }
              return;
        }

        // Traversing

        Node*prev=head;
        Node* curr = head -> next;
        while(curr != NULL && curr -> id != id ) {
            prev=curr;
             curr = curr -> next;
        }

       
        // invalid

        if(curr == NULL){
            cout << "new song can't be entered "<< endl;
            return;
        }


        // To handle middle or last node
        if(curr == tail){     // last node is handled here
            tail = curr -> prev;
            tail -> next = NULL;
        }
        else{                         // middle node is handled here
        curr -> prev -> next  = curr -> next;
        curr -> next -> prev = curr -> prev;
        }
        curr -> next = NULL;
        curr -> prev = NULL;
        delete curr;

        
        cout << "song with id number "<< id << " has been deleted successfully! ";
        cout<<endl;

     }


// -----------------------------------------------------------------------------------------------------------------

     string searchSongById(int id){
        Node* temp=head;
        while(temp != NULL){
          if(temp -> id == id){
            return temp->name;
          }
          temp=temp->next;
        }
        return "Not Found";
     }


    //  -----------------------------------------------------------------------------------------------------------



     void printPlaylistForward(){
        Node* temp = head;
        while(temp != NULL){
            cout<< temp -> id << "-" << temp-> name <<endl;
            temp=temp -> next;
        }
        cout<<endl;
     }

    //  -------------------------------------------------------------------------------------------------------------


     void printPlaylistBackward(){
        Node*temp=tail;
        while(temp != NULL){
            cout<< temp->id << "-"<< temp->name<<endl;
            temp=temp->prev;
        }
        cout<<endl;
     }
};

// ----------------------------------------------------------------------------------------------------------------

int main(){
    Song song;
    song.addSongAtHead(1, "A");
    song.addSongAtHead(2, "B");
    song.addSongAtHead(3, "C");

    song.printPlaylistForward();


    song.addSongAtTail(4,"D");
    song.printPlaylistForward();

    song.removeSongById(2);
    song.printPlaylistForward();


   string result = song.searchSongById(4);
   if(result != "Not Found"){
       cout<< "Song has been found with "<< result << endl;
   }

   else{
    cout<< "Song has not been found with name "<< result << endl;
   }
   

   song.printPlaylistForward();
   cout<<endl;
   cout<<"reverse the playlist "<<endl;
   song.printPlaylistBackward();

}



