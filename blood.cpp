#include <bits/stdc++.h>
using namespace std;

int donorCount = 1, hospitalCount = 1;

// ================= DONOR =================
class donor {
public:
    int DNR, fitness;
    char name[20], contact[15], t, r;

    void input() {
        char str[3];
        cout<<"Name: "; cin>>name;
        cout<<"Contact: "; cin>>contact;
        cout<<"Fitness (1-fit,0-unfit): "; cin>>fitness;

        while(1){
            cout<<"Blood type (A/B/O/AB): ";
            cin>>str;
            if(strcmp(str,"AB")==0||strcmp(str,"ab")==0){t='X';break;}
            if(strcmp(str,"A")==0||strcmp(str,"B")==0||strcmp(str,"O")==0||
               strcmp(str,"a")==0||strcmp(str,"b")==0||strcmp(str,"o")==0){
                t=toupper(str[0]); break;
            }
            cout<<"Invalid\n";
        }

        while(1){
            cout<<"Rhesus (+/-): ";
            cin>>r;
            if(r=='+'||r=='-') break;
            cout<<"Invalid\n";
        }

        DNR = donorCount;
        cout<<"Your DNR: "<<DNR<<endl;
    }

    void show(){
        cout<<DNR<<"\t"<<name<<"\t"<<contact<<"\t"<<fitness<<"\t"<<t<<r<<endl;
    }
};

// ================= HOSPITAL =================
class hospital {
public:
    int HPID;
    char contact[15];

    void input(){
        HPID = hospitalCount;
        cout<<"Hospital contact: ";
        cin>>contact;
        cout<<"Hospital ID: "<<HPID<<endl;
    }

    void show(){
        cout<<HPID<<"\t"<<contact<<endl;
    }
};

// ================= BLOOD =================
class blood {
public:
    int Apos=0,Aneg=0,Bpos=0,Bneg=0,Opos=0,Oneg=0,ABpos=0,ABneg=0;

    void donate(char t,char r){
        if(t=='A'&&r=='+')Apos++;
        else if(t=='A')Aneg++;
        else if(t=='B'&&r=='+')Bpos++;
        else if(t=='B')Bneg++;
        else if(t=='O'&&r=='+')Opos++;
        else if(t=='O')Oneg++;
        else if(t=='X'&&r=='+')ABpos++;
        else ABneg++;
    }

    bool issue(char t,char r){
        if(t=='A'&&r=='+'&&Apos>0){Apos--;return true;}
        if(t=='A'&&r=='-'&&Aneg>0){Aneg--;return true;}
        if(t=='B'&&r=='+'&&Bpos>0){Bpos--;return true;}
        if(t=='B'&&r=='-'&&Bneg>0){Bneg--;return true;}
        if(t=='O'&&r=='+'&&Opos>0){Opos--;return true;}
        if(t=='O'&&r=='-'&&Oneg>0){Oneg--;return true;}
        if(t=='X'&&r=='+'&&ABpos>0){ABpos--;return true;}
        if(t=='X'&&r=='-'&&ABneg>0){ABneg--;return true;}
        return false;
    }

    void show(){
        cout<<"\nA+ "<<Apos<<" A- "<<Aneg;
        cout<<"\nB+ "<<Bpos<<" B- "<<Bneg;
        cout<<"\nO+ "<<Opos<<" O- "<<Oneg;
        cout<<"\nAB+ "<<ABpos<<" AB- "<<ABneg<<endl;
    }
};

// ================= ADMIN =================
class admin {
public:
    donor d[50];
    hospital h[20];
    blood b;

    string username = "admin";
    string password = "1234";

    // ---------- LOGIN ----------
    bool login(){
        string u,p;
        int attempt=0;
        while(attempt<3){
            cout<<"Username: ";
            cin>>u;
            cout<<"Password: ";
            cin>>p;
            if(u==username && p==password){
                cout<<"Login successful\n";
                return true;
            }
            cout<<"Invalid login\n";
            attempt++;
        }
        return false;
    }

    // ---------- FILE HANDLING ----------
    void loadDonor(){
        ifstream f("donor.txt");
        if(!f) return;
        donorCount=1;
        while(f>>d[donorCount].DNR>>d[donorCount].name
              >>d[donorCount].contact>>d[donorCount].fitness
              >>d[donorCount].t>>d[donorCount].r)
            donorCount++;
        f.close();
    }

    void saveDonor(){
        ofstream f("donor.txt");
        for(int i=1;i<donorCount;i++)
            f<<d[i].DNR<<" "<<d[i].name<<" "<<d[i].contact<<" "
             <<d[i].fitness<<" "<<d[i].t<<" "<<d[i].r<<endl;
        f.close();
    }

    void loadHospital(){
        ifstream f("hospital.txt");
        if(!f) return;
        hospitalCount=1;
        while(f>>h[hospitalCount].HPID>>h[hospitalCount].contact)
            hospitalCount++;
        f.close();
    }

    void saveHospital(){
        ofstream f("hospital.txt");
        for(int i=1;i<hospitalCount;i++)
            f<<h[i].HPID<<" "<<h[i].contact<<endl;
        f.close();
    }

    void loadBlood(){
        ifstream f("blood.txt");
        if(!f) return;
        f>>b.Apos>>b.Aneg>>b.Bpos>>b.Bneg
         >>b.Opos>>b.Oneg>>b.ABpos>>b.ABneg;
        f.close();
    }

    void saveBlood(){
        ofstream f("blood.txt");
        f<<b.Apos<<" "<<b.Aneg<<" "<<b.Bpos<<" "<<b.Bneg<<" "
         <<b.Opos<<" "<<b.Oneg<<" "<<b.ABpos<<" "<<b.ABneg;
        f.close();
    }

    // ---------- MENU FUNCTIONS ----------
    void addDonor()
    {
        d[donorCount].input();
     donorCount++; saveDonor();
      }

    void showDonor(){
        cout<<"DNR\tName\tContact\tFit\tBlood\n";
        for(int i=1;i<donorCount;i++) d[i].show();
    }
    void addHospital()

    {
        h[hospitalCount].input();
     hospitalCount++; saveHospital();
      }

    void donate()
    {
        int id; cout<<"DNR: "; cin>>id;
        if(id<=0||id>=donorCount||d[id].fitness==0)

            {
            cout<<"Invalid donor\n"; return;
        }

        b.donate(d[id].t,d[id].r);
        saveBlood();
        cout<<"Donation success\n";
    }
    void requestBlood(){
        char t,r;
        cout<<"Type: "; cin>>t;
        cout<<"Rhesus: "; cin>>r;
        if(b.issue(t,r)){ saveBlood(); cout<<"Blood issued\n"; }
        else cout<<"Not available\n";
    }
};

// ================= MAIN =================
int main(){
    admin a;

    if(!a.login()){
        cout<<"Access denied\n";
        return 0;
    }

    a.loadDonor();
    a.loadHospital();
    a.loadBlood();

    int ch;
    while(1){
        cout<<"\n1.Add Donor\n2.Show Donor\n3.Add Hospital\n4.Donate\n5.Request Blood\n6.Show Blood\n7.Exit\nChoice: ";
        cin>>ch;
        switch(ch){
            case 1:a.addDonor();break;
            case 2:a.showDonor();break;
            case 3:a.addHospital();break;
            case 4:a.donate();break;
            case 5:a.requestBlood();break;
            case 6:a.b.show();break;
            case 7:return 0;
            default:cout<<"Invalid\n";
        }
    }
}
