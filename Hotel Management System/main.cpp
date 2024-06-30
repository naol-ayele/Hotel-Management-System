#include <bits/stdc++.h>

using namespace std;


   struct Node
   {
    int id,date;
    string name,roomtype;
    Node*next;
   }*head=NULL;

        void insert();
        void menu();
        void update();
        void search();
        void del();
        void sort();
        void show();

void menu()
{
    int choice;
    cout<<"\n";
    cout<<"\t****** WELCOME TO HOTEL MANAGEMENT SYSTEM APPLICATION  *******"<<endl;
    cout<<"\n\t ______Hotel Management system______";
    cout<<"\n\nS.NO         function                   Description"<<endl;
    cout<<"========     ============              ================="<<endl;
    cout<<"\n1.          Allocate Room             Insert new Room"<<endl;
    cout<<"\n2.          search Room               search Room with Room ID"<<endl;
    cout<<"\n3.          Update Room               Update Room Record"<<endl;
    cout<<"\n4.          Delete Room               Delete Room"<<endl;
    cout<<"\n5.          Show Room Records         Show Room Records"<<endl;
    cout<<"\n6.          Exit                      Quit                 "<<endl;
cout<<"=========================================================================="<<endl;
cout<<"Enter your choice"<<endl;
cin>>choice;
switch(choice)
{
    case 1:
        insert();
        menu();
        break;
    case 2:
        search();
        menu();
        break;

    case 3:
        update();
        menu();
        break;

            case 4:
        del();
        menu();
        break;

    case 5:
        sort();
        show();
        menu();
        break;
    case 6:
         exit(0);
         menu();
        break;
    default:
       cout<<"Invalid";

   }

}

void insert()
{
    cout<<"\n_________Hotel Management System_________";
    cout<<" "<<endl;
    Node*new_node = new Node;
    cout<<"\nPlease Enter Room Number:";
    cin>>new_node->id;
     cout<<"\nCustomer Name:";
    cin>>new_node->name;
    cout<<"\nEnter Room type:";
    cin>>new_node->roomtype;
     cout<<"\nAllocate Date:";
    cin>>new_node->date;

    if(head==NULL)
    {
        head=new_node;
    }
    else
    {
        Node*ptr= head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new_node;
    }
    cout<<"***==========================================================================***"<<endl;
    cout<<"ROOM INSERTED SUCCSEFULY";
    cout<<" "<<endl;

}
void search()
{
    cout<<"\n\t_______Hotel Management System________"<<endl;
    int t_id;
    if(head==NULL)
    {
        cout<<"!!! sorry linked list is empty";
        cout<<" "<<endl;
    }
    else
    {
        cout<<"\n\nRoom ID";
        cin>>t_id;
        Node*ptr=head;
        while(ptr!=NULL)
        {
            if(t_id==ptr->id)
            {
                cout<<"\n\n Room ID"<<ptr->id;
                  cout<<"\n\n Customer Name"<<ptr->name;
                    cout<<"\n\nRoom Allocated Date"<<ptr->date;
                      cout<<"\n\n Room type"<<ptr->roomtype;

            }
            ptr=ptr->next;
        }
    }
}
 void update()
{
    cout<<"\n\t_______Hotel Management System__________"<<endl;
    int t_id;
    if(head==NULL)
    {
       cout<<"!!! sorry linked list is empty";
        cout<<" "<<endl;
    }
    else
    {
        cout<<"\n\n Room ID";
        cin>>t_id;
        Node*ptr=head;
        while(ptr!=NULL)
        {
            if(t_id==ptr->id)
            {
                cout<<"\n\nRoom ID";
                cin>>ptr->id;
                cout<<"\n\nCustomer Name";
                cin>>ptr->name;
                cout<<"\n\nAllocated Date";
                cin>>ptr->date;
                cout<<"\n\nRoom type";
                cin>>ptr->roomtype;
                cout<<"\n\n\t\t Update Record successfully";
            }
            ptr=ptr->next;
        }
    }
}
 void del()
{
    cout<<"\n\t_______Hotel Management System_______"<<endl;
    int t_id;
    if(head==NULL)
    {
       cout<<"!!! sorry linked list is empty";
        cout<<" "<<endl;
    }
    else
    {
        cout<<"\n\n Room ID";
        cin>>t_id;
       if(t_id == head->id)
       {
           Node*ptr=head;
           head=head->next;
           delete ptr;
           cout<<"Delete Room Record successful\n";
       }
     else
     {
         Node*pre=head;
          Node*ptr=head;
          while(ptr!=NULL)
          {
              if(t_id==ptr->id)
              {
                  pre->next=ptr->next;
                  delete ptr;
                    cout<<"Delete Room Record successful\n";
                    break;
              }
              pre=ptr;
              ptr=ptr->next;
          }

     }
}
}
void show()
{
    Node*ptr=head;
    while(ptr!=NULL)
    {
        cout<<"\nRoom ID"<<ptr->id;
         cout<<"\nCustomer Name"<<ptr->name;
          cout<<"\nAllocated Date"<<ptr->date;
           cout<<"\nRoom type"<<ptr->roomtype;
           ptr=ptr->next;
    }
}
void sort()
{
    if(head==NULL)
    {
        cout<<"!!! sorry linked list is empty";
        cout<<" "<<endl;
        menu();
    }
    int count=0, t_date,t_id;
    string t_name,t_roomtype;
    Node*ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    for( int i=1; i<=count ; i++ )
    {
        Node*ptr=head;
        for(int j=1; j<count; j++)
        {
            if(ptr->id > ptr->next->id)
                {
                t_id=ptr->id;
                  t_name=ptr->name;
                     t_date=ptr->date;
                        t_roomtype=ptr->roomtype;

            ptr->id=ptr->next->id;
                ptr->name=ptr->next->name;
                    ptr->date=ptr->next->date;
                        ptr->roomtype=ptr->next->roomtype;

               ptr->next->id =t_id;
                    ptr->next->name =t_name;
                        ptr->next->date=t_date;
                            ptr->next->roomtype =t_roomtype;

                }
                ptr=ptr->next;
        }
    }
}


int main()
{
menu();

}
