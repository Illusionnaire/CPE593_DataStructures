/*
    Author: Marcin Wisniowskis

    I pledge my honor that I have abided by the Stevens Honor System
*/

/*
Assignment:
Create a linked-list data structure.
1) Read in a file called hw5.dat containing a bunch of integers separated by spaces, and add those integers to your listA.

2) Remove all the even numbers from your listA, and place them in a second listB.  You should now have an odd listA, and an even listB.

3) Insert the elements of the even listB into even indices of the odd-listA.  If there are more even numbers than there are odd, then append the extra even numbers to the end, regardless of the index.

4) Print listA.
*/

#include <iostream>
#include <fstream>
using namespace std;

struct Node{
    int value;
    Node* next;

    Node(): value(0),next(nullptr){};
};

class LinkedList{
    private:
        Node* head;
        int length;
    public:
    LinkedList(): head(nullptr),length(0){}; 
    ~LinkedList(){delete head;}

    void insertEnd(int x){
        Node* temp = new Node();
        temp->value = x;

        if(head == nullptr){
            head = temp;
            length++;
        }
        else{
            Node* helper = head;
            while(helper->next != nullptr){
                helper = helper->next;
            }
            helper->next = temp;
            length++;
        }
        }

    
    //Function to Delete
    void removeFromPos(int pos){
        //Is position valid?
        if(pos > 0 && pos <= this->length){
            Node *helper = this->head;
            //If removing from beginning
            if (pos == 1){
                this->head = this->head->next;
                delete helper;
            }
            //If removing from end
            if (pos == this->length){
                for(int i = 1; i < length - 1; i++){
                    helper = helper->next;
                }
                delete helper->next;
                helper->next = NULL;
            }
            //If removing from middle
            else {
                Node *deleteptr = head;
                for (int i = 1; i < pos; i++){
                    helper = deleteptr;
                    deleteptr = deleteptr->next;
                }
                helper->next = helper->next->next;
                delete deleteptr;
            }
        }
        }

    void display(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->value<<'\t';
            temp=temp->next;
        }
        }
    LinkedList& splitMod2(LinkedList& B){
        LinkedList listC;
        Node *helper = this->head;
        while(helper != nullptr){
            if(helper->value % 2 == 0){
                B.insertEnd(helper->value);
                B.length++;
            }
            else{
                listC.insertEnd(helper->value);
                listC.length++;
            }
            helper = helper->next;
        }
        this->length = listC.length;
        swap(this->head,listC.head);
        return *this;
        }

    LinkedList& concatAlternate(LinkedList& B){
        LinkedList listC;
        Node* helperA = this->head;
        Node* helperB = B.head;
        
        
        if(this->length > B.length){ //A is longer than B, need to concat A at end
            while(helperB != nullptr){
                listC.insertEnd(helperB->value);
                helperB = helperB->next;
                listC.length++;
                listC.insertEnd(helperA->value);
                helperA = helperA->next;
                listC.length++;
            }
            if(helperB == nullptr){
                while(helperA != nullptr){
                    listC.insertEnd(helperA->value);
                    helperA = helperA->next;
                    listC.length++;
                }
            }
        }
        else{   //B is longer than A, need to concat B at end
            while(helperA != nullptr){
                listC.insertEnd(helperB->value);
                helperB = helperB->next;
                listC.length++;
                listC.insertEnd(helperA->value);
                helperA = helperA->next;
                listC.length++;
            }
            if(helperA == nullptr){
                while(helperB != nullptr){
                    listC.insertEnd(helperB->value);
                    listC.length++;
                    helperB = helperB->next;  
                }
            }
        }

        this->length = listC.length;
        swap(this->head,listC.head);
        return *this;
    }

};

int main(){
    LinkedList listA;
    LinkedList listB;

    int x;
    
    ifstream myfile;
    myfile.open("hw5.dat");
    while(!myfile.eof()){
        myfile >> x;
        listA.insertEnd(x);   
    }
    myfile.close();

    listA = listA.splitMod2(listB);
    listA = listA.concatAlternate(listB);
    listA.display();

    return 0;
}