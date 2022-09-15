#include <iostream>
using namespace std;

class Node{


        public:
            int data;
            Node * next;
            Node(int data){
                this-> data = data;
                next = NULL;
            }

};


Node* takeimput(){


        int data;
        cin>>data;
        Node * head= NULL;
        Node * tail= NULL;
        while(data!=-1){
                Node* newNode= new Node(data);
                if(head==NULL)
                {
                        head = newNode;
                        tail=newNode;

                }
                else
                {
                        Node* temp= head;
                        while(temp->next != NULL){

                                temp = temp->next;
                        }

                        temp->next= newNode;
                }
                cin>>data;
        }
        return head;


}



void printt(Node * head){


        while(head!= NULL){
                cout<<head->data<<" ";
                head= head->next;

        }
        cout<<endl;


}




Node * deleteNode(Node * head, int i){


        if(i==0){
                Node * temp = head;
                head= head->next;
                delete temp;
                return head;
        }
        Node* temp = head;
        while( temp != NULL && --i){

                temp= temp-> next;

        }
        if((i==0) && /*temp != NULL &&*/ (temp-> next )!= NULL)
        {
                Node* a= temp->next;
                Node* b= a->next;

                temp->next= b;
                delete a;
        }


      return head;
}



Node * Midpoint(Node * head){


        Node * slow = head;
        Node * fast= slow->next;
        Node * Before_slow = head;
        while(fast!=NULL && fast->next!= NULL){

                fast= fast->next->next;
                slow=slow->next;
        }
        Before_slow= slow->next;
        slow->next=NULL; // mergesort ke liye aisa bana rakha hai midpoint
        return Before_slow;

}


int lengthh(Node* temp){


        if(temp==NULL)
        {
                return 0;
        }
        else
        {
                return 1 + lengthh(temp->next);
        }

}
Node * merge2_Soted_LL(Node * head, Node * headd){
        Node * fh= NULL;
        Node * ft= NULL;
        Node * h1= head;
        Node * h2= headd;
        if((h1->data)>= (h2->data))
        {
                fh= h2;
                ft= h2;
                h2= h2->next;
        }
        else
        {
                fh= h1;
                ft= h1;
                h1= h1->next;
        }
        while(h1!= NULL && h2!=NULL){
               if((h1->data)>= (h2->data))
               {
                         ft->next= h2;
                         ft= h2;
                         h2= h2->next;
                 
               }
               else
               {
                        ft->next= h1;
                        ft= h1;
                        h1= h1->next;
               }

        }
        if(h1==NULL)
        {
                ft->next= h2;
        }
        else
        {
                ft->next= h1;
        }
       return fh;



}

Node *  mergesortalgo(Node * head){


       if(lengthh(head)==1)
       {
             return head;
       }

        Node * head1= head;
        Node * head2= Midpoint(head); 


        Node * head11 =mergesortalgo(head1);
        Node * head22= mergesortalgo(head2);
        Node * headff= merge2_Soted_LL(head11, head22);
        return headff;

}

Node * reversell(Node * head){


       if(head->next==NULL)
       {
            return head;
       }


        Node * Smallans = reversell(head->next);
        Node * temp= Smallans;

        while(temp->next!=NULL){
                temp= temp->next;
        }

        temp->next= head;
        head->next= NULL;

        return Smallans;


}

int Findx(Node * head, int x){


       Node * temp = head;
       int index=0;
       while(temp!= NULL){
                if(temp->data ==x)
                {
                     break;
                 }
                temp= temp->next;
                index++;
       }
       if(temp==NULL)
       {
            return -1;
       }
       else
       {
            return index;
       }

}


void printrevrse(Node * head){


        if(head==NULL)
        {
            return;
        }
        printrevrse(head->next);
        cout<<head->data<<" ";


}
class Pairr{


        public:
            Node* oddh;
            Node* evenh;
};

Pairr Evenafterodd(Node * head){
    

        Node* oddH = NULL ,* oddT= NULL, * evenH= NULL, * evenT= NULL;
        while(head!=NULL)
        {
                if((head->data)%2 !=0)
                {
                        if(oddH==NULL)
                        {
                                oddH= head;
                                oddT= head;
                        }
                        else
                        {
                                oddT->next= head;
                                oddT= head;
                        }
                }
                else
                {
                        if(evenH==NULL)
                        {
                                evenH= head;
                                evenT= head;
                        }
                        else
                        {
                                evenT->next= head;
                                evenT= head;

                        }

                }
                head= head->next;
            
        }
        if((oddT)!=NULL)
        {
                oddT->next= NULL;
        }
        if((evenT)!=NULL)
        {
                 evenT->next= NULL;
        }
        Pairr ans;
        ans.oddh= oddH;
        ans.evenh= evenH;
        return ans;

        

}






int main(){
    Node * headi = takeimput();

   //printt(headi);
   Pairr ans1;
   ans1= Evenafterodd(headi);
   printt(ans1.oddh);
   printt(ans1.evenh);

    



}
