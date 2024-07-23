#include<iostream>
#include<fstream>

using namespace std;

class shopping{
    private:
        int pcode;
        float price;
        float dis;
        string pname;

    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();
    //declared functions and variables

};

void shopping :: menu(){
    m:
    int choice;
    string email;
    string password; //login purpose

    cout << "\t\t\t\t_______________________\n";
    cout << "\t\t\t supermarket main menu   \n";
    cout << "\t\t\t\t_______________________\n";

    cout << "\t\t\t\t|     1) ADMIN   |\n";
    cout << "\t\t\t\t|     2) BUYER   |\n";
    cout << "\t\t\t\t|     3) EXIT    |\n";

    cout << "\t\t\t\t  please select!";
    cin >> choice;

    switch(choice){
        case 1:
            cout<<"\t\t\t    please login \n";
            cout<<"\t\t\t    enter email  \n";
            cin >> email;
            cout <<"\t\t\t     password    \n";
            cin >> password;

            if(email=="ananya@gmail.com" && password=="ananya123"){
                administrator();
            }
            else{
                cout << "invalid email/password";
            }
            break;
        
        case 2:
            {
                buyer();
            }
        case 3:
            {
                exit(0);
            }
            default:
            {
                cout << "please select from the above";
            }
    }

    goto m;

}

void shopping :: administrator(){
    m:
    int choice;
    cout << "\n\n\t\t\t    Administrator menu";
    cout << "\n\t\t\t|     1) Add the product___|";
    cout << "\n\t\t\t|                        |";
    cout << "\n\t\t\t|     2) Modify the product|";
    cout << "\n\t\t\t|                        |";
    cout << "\n\t\t\t|     3) Delete the product|";
    cout << "\n\t\t\t|                        |";
    cout << "\n\t\t\t|     4) Back to main menu|";

    cout << "\n\n\t Please enter your choice";
    cin >> choice;

    switch(choice){
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default :
            cout <<"invalid choice!";
    }
    goto m;
}
void shopping::buyer(){
    m:
    int choice;
    cout << "\t\t\t buyer\n";
    cout <<"              \n";
    cout <<"\t\t\t 1)buy product\n";
    cout << "                   \n";
    cout <<"\t\t\t 2)go back    \n";
    cout <<"\t\t\t Enter your choice\n";

    cin >> choice;

    switch(choice){
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;

        default: 
            cout << "invalid choice";
    }
    goto m;
}

void shopping :: add(){
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;
    
    cout << "\n\n\t\t\t  Add new product";
    cout << "\n\n\t product code of the prodcut";
    cin >> pcode;
    cout << "\n\n\t name of the prodcut";
    cin >> pname;
    cout << "\n\n\t price of the prodcut";
    cin >> price;
    cout << "\n\n\t discount on prodcut";
    cin >> dis;

    data.open("database.txt", ios::in); // ios::in will open the file in reading mode , out in writing mode

    if(!data){
        data.open("database.txt", ios::app | ios::out);
        data <<"  " << pcode <<"  " <<pname << "  "<<price <<"  "<< dis <<"\n";
        data.close();
    }
    else{
        data >> c >> n >> p >> d; //read from file if data exists
        //intilizing index
        while(!data.eof()){

            if(c == pcode){
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    }

    if(token == 1){
        goto m;
    }
    if(token == 0){
        data.open("database.txt", ios::app | ios::out);
        data <<"  " << pcode <<"  " <<pname << "  "<<price <<"  "<< dis <<"\n";
        data.close();
    }
    cout << "\n\n\t\t Record inserted !";
}

void shopping :: edit(){
    fstream data , data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout <<"\n\t\t\t Modify the record";
    cout << "\n\t\t Product code !";
    cin >> pkey;

    data.open("database.txt" , ios::in);
        if(!data){
            cout << "file doesnt exist";
        }
        else{
            data1.open("database1.txt" , ios::app | ios::out);

            data >> pcode >> pname >> price >> dis;

            while(!data.eof()){

                if(pkey == pcode){
                    cout << "\n\t\t Product's new code";
                    cin >> c;
                    cout <<"\n\t\t  Name of the product :";
                    cin >> n;
                    cout << "\n\t\t  Price";
                    cin >>p;
                    cout << "\n\t\t  Discount";
                    cin >> d;
                    data1 << " "<< c << " " << n <<" "<< p <<" " << d <<" ";
                    cout << "\n\t\t  Record edited";
                    token++;
                }
                else{

                    data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
                }

                data >> pcode >> pname >> price >> dis;

            }
            data.close();
            data1.close();

            remove("database.txt");
            rename("database1.txt" , "database.txt");

            if(token == 0){
                cout << "record not found";
            }
        }
    
}


void shopping ::rem(){
    fstream data , data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t Delete product";
    cout << "\n\n\t Product code";
    cin >> pkey;
    data.open("database.txt" , ios::in);
    if(!data){
        cout << " file doesnt exist";
    }
    else{
        data1.open("database1.txt" , ios::app|ios ::out);
        data>>pcode >> pname >> price >> dis;

        while(!data.eof()){

            if(pcode == pkey){
                cout << "product deleted successfully";
                token++;
            }
            else{
                data1 << " " << pcode << " " << pname << " " <<price << " " << dis << "\n";
            }
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt" , "database.txt");
        
        if(token == 0){
            cout << "\n\n Record not found";
        }
    }

}
void shopping :: list(){
    fstream data;
    data.open("database.txt" , ios::in);
    cout << "\n\n|__________________________\n";
    cout << "PRODUCT NUMBER\t\tNAME\t\tPRICE\n";
    cout << "\n\n|__________________________\n";
    data >> pcode >> pname >> price >> dis ;

    while(!data.eof()){
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;

    }
    data.close();
}

void shopping ::receipt(){

    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0 ;
    float dis = 0 ;
    float total = 0;

    cout << "\n\n\t\t\t\t RECEIPT";
    data.open("database.txt" , ios::in);
    if(!data){
        cout << "\n\n empty database";
    }
    else{
        data.close();
        
        list();
        cout << "\n__________________________\n";
        cout << "\n__________________________\n";
        cout << "\n PLEASE ORDER \n";
        cout << "\n__________________________\n";
        cout << "\n__________________________\n";

        do{
            m:
            cout << "\n\n ENTER PRODUCT CODE: ";
            cin >> arrc[c];
            cout << "\n\n ENTER THE PRODUCT QUANTITY";
            cin >> arrq[c];

            for(int i = 0 ; i < c ; i++){
                if(arrc[c] == arrc[i]){
                    cout << "\n\n DUPLICATE PRODUCT CODE PLEASE TRY AGAIN";
                    goto m;
                }
            }
                c++;
                cout << "DO U WANT TO BUY ANOTHER PRODUCT? y / n ??";
                cin >> choice ;
            }
            
        while(choice == 'y');
            cout << "\n\n\t\t___________RECEIPT \n";
            cout << "\n PRODUCT NUMBER\t PRODUCT NAME\t PRODUCT QUANTITY\tprice\tamount\tamount with discout\n";

            for(int i = 0 ; i < c ; i++){
                data.open("database.txt" , ios::in);
                data >> pcode >> pname >> price >> dis;

                while(!data.eof()){
                    if(pcode == arrc[i]){
                        amount = price * arrq[i];
                        dis = amount - (amount *dis / 100);
                        total = total + dis ;
                        cout << "\n" << pcode  << "\t" << pname << "\t" <<arrq[i] << "\t" << price <<"\t" << amount<< "\t" << dis ;
                    }
                    data >> pcode >> pname >> price >> dis;
                    
                }
            }
            data.close();
    }
    cout << "\n\n_____________________________";
    cout << "\n Total Amount : " << total ;
}

int main(){
    shopping s;
    s.menu();
}