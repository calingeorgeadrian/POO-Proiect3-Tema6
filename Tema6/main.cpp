#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Farmacie
{
    public:
        Farmacie(); ///constructor de initializare
        Farmacie(string,int,vector<int>); ///constructor parametrizat
        virtual ~Farmacie();
        Farmacie(const Farmacie& other);
        friend istream& operator>>(istream&,Farmacie& other);
        friend ostream& operator<<(ostream&,Farmacie& other);
        Farmacie& operator=(const Farmacie& other);

        string Getdenumire() { return denumire; }
        void Setdenumire(string val) { denumire = val; }
        int Getnr_angajati() { return nr_angajati; }
        void Setnr_angajati(int val) { nr_angajati = val; }
        vector<int> Getprofit() { return profit; }
        void Setprofit(vector<int> val) { profit = val; }

        virtual void afisare() { cout<<*this<<endl; }
        virtual void citire() { cin>>*this; }

    protected:

    private:
        string denumire;
        int nr_angajati;
        vector<int> profit;
};

Farmacie::Farmacie()
{
    //ctor
    denumire="Farmacie";
    nr_angajati=0;
    profit.resize(12);
    fill(profit.begin(),profit.end(),0);
}

Farmacie::Farmacie(string a,int b,vector<int> c)
{
    //ctor
    denumire=a;
    nr_angajati=b;
    profit=c;
}

Farmacie::~Farmacie()
{
    //dtor
    //delete[] denumire;
    //delete[] profit;
}

Farmacie::Farmacie(const Farmacie& other)
{
    //copy ctor
    denumire=other.denumire;
    nr_angajati=other.nr_angajati;
    profit=other.profit;
}

istream& operator>>(istream &in,Farmacie& other)
{
    string x;
    int y;
    cout<<"Denumire: "; in>>other.denumire;
    cout<<"Numar angajati: "; in>>x;
    for (int i=0;i<x.length();i++)
    {
        try
        {
            if(x[i]<'0' || x[i]>'9')
                throw 1;
        }
        catch(int a)
        {
            cout<<"Numarul de angajati nu poate lua aceasta valoare.\n";
            return in;
        }
    }
    y=stoi(x);
    other.nr_angajati=y;
    //cout<<"Profit: "; in>>other.profit;
    for(int i=0;i<other.profit.size();i++)
    {
        cout<<"Profit luna "<<i+1<<": ";
        in>>x;
        for (int i=0;i<x.length();i++)
        {
            try
            {
                if(x[i]<'0' || x[i]>'9')
                    throw 1;
            }
            catch(int a)
            {
                cout<<"Profitul nu poate lua aceasta valoare.\n";
                return in;
            }
        }
        int y=stoi(x);
        other.profit[i]=y;
    }
    return in;
}

ostream& operator<<(ostream &out,Farmacie& other)
{
    out<<"Denumire: "; out<<other.denumire<<endl;
    out<<"Numar angajati: "; out<<other.nr_angajati<<endl;
    cout <<"Luna:\tIan\tFeb\tMar\tApr\tMai\tIun\tIul\tAug\tSep\tOct\tNov\tDec"<<endl;
    cout<<"Profit:\t";
    for(int i=0;i<other.profit.size();i++)
        out<<other.profit[i]<<"\t";
    cout<<endl;
    return out;
}

Farmacie& Farmacie::operator=(const Farmacie& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    if(this!=&rhs)
    {
        denumire=rhs.denumire;
        nr_angajati=rhs.nr_angajati;
        profit=rhs.profit;
    }
    return *this;
}

class FarmacieOnline: public Farmacie
{
    public:
        FarmacieOnline();
        FarmacieOnline(string,int,double);
        virtual ~FarmacieOnline();
        FarmacieOnline(const FarmacieOnline& other);
        friend istream& operator>>(istream&,FarmacieOnline& other);
        friend ostream& operator<<(ostream&,FarmacieOnline& other);
        FarmacieOnline& operator=(const FarmacieOnline& other);

        string Getadresa_web() { return adresa_web; }
        void Setadresa_web(string val) { adresa_web = val; }
        int Getnr_vizitatori() { return nr_vizitatori; }
        void Setnr_vizitatori(int val) { nr_vizitatori = val; }
        double Getdiscount() { return discount; }
        void Setdiscount(double val) { discount = val; }

        void afisare() { cout<<*this<<endl; }
        void citire() { cin>>*this; }

    protected:

    private:
        string adresa_web;
        int nr_vizitatori;
        double discount;
};

FarmacieOnline::FarmacieOnline()
{
    //ctor
    adresa_web="404 address not found";
    nr_vizitatori=0;
    discount=0;
}

FarmacieOnline::FarmacieOnline(string a,int b,double c)
{
    //ctor
    adresa_web=a;
    nr_vizitatori=b;
    discount=c;
}

FarmacieOnline::~FarmacieOnline()
{
    //dtor
    //delete[] adresa_web;
}

FarmacieOnline::FarmacieOnline(const FarmacieOnline& other)
{
    //copy ctor
    adresa_web=other.adresa_web;
    nr_vizitatori=other.nr_vizitatori;
    discount=other.discount;
}

istream& operator>>(istream &in,FarmacieOnline& other)
{
    string x;
    int y;
    cout<<"Adresa Web: "; in>>other.adresa_web;
    cout<<"Numar vizitatori: "; in>>x;
    for (int i=0;i<x.length();i++)
    {
        try
        {
            if(x[i]<'0' || x[i]>'9')
                throw 1;
        }
        catch(int a)
        {
            cout<<x<<endl;
            cout<<"Numarul de vizitatori nu poate lua aceasta valoare.\n";
            return in;
        }
    }
    y=stoi(x);
    other.nr_vizitatori=y;
    cout<<"Discount: "; in>>x;
    for (int i=0;i<x.length();i++)
    {
        try
        {
            if(x[i]<'0' || x[i]>'9')
                throw 1;
        }
        catch(int a)
        {
            cout<<"Discount-ul nu poate lua aceasta valoare.\n";
            return in;
        }
    }
    y=stoi(x);
    other.discount=y;
    return in;
}

ostream& operator<<(ostream &out,FarmacieOnline& other)
{
    out<<"Adresa Web: "; out<<other.adresa_web<<endl;
    out<<"Numar vizitatori: "; out<<other.nr_vizitatori<<endl;
    out<<"Discount: "; out<<other.discount<<"%"<<endl;
    return out;
}

FarmacieOnline& FarmacieOnline::operator=(const FarmacieOnline& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    if(this!=&rhs)
    {
        adresa_web=rhs.adresa_web;
        nr_vizitatori=rhs.nr_vizitatori;
        discount=rhs.discount;
    }
    return *this;
}

template <class T> class GestionareFarmacii
{
    int index;
    const int id = 1482;
    T **lant;
public:
    GestionareFarmacii()
    {
        index=0;
        lant=new T*[index];
    }
    GestionareFarmacii(int a,T **b)
    {
        index=a;
        lant=new T*[index];
        for(int i=0;i<index;i++)
            lant[i]=b[i];
    }
    virtual ~GestionareFarmacii()
    {
        delete[] lant;
    }
    GestionareFarmacii(const GestionareFarmacii& other)
    {
        index=other.index;
        lant=other.lant;
    }
    friend istream& operator>>(istream &in,GestionareFarmacii& other)
    {
        int op2;
        cout<<"Index: "; in>>other.index;
        other.lant=new T*[other.index];
        try
        {
            for(int i=0;i<other.index;i++)
            {
                cout<<"\nTip farmacie "<<i+1<<"\n";
                cout<<"[1]Cladire\n";
                cout<<"[2]Online\n";
                cout<<"Optiune:";
                cin>>op2;
                try
                {
                    if(op2<1 || op2>2)
                        throw 1;
                }
                catch (int a)
                {
                    cout<<"Tip inexistent.\n";
                    return in;
                }
                switch(op2){
                case 1:{
                    Farmacie *c=new Farmacie;
                    c->citire();
                    other.lant[i]=static_cast<Farmacie*>(c);
                    break;
                    }
                case 2:{
                    FarmacieOnline *c=new FarmacieOnline;
                    c->citire();
                    other.lant[i]=dynamic_cast<FarmacieOnline*>(c);
                    break;
                    }
                }
            }
        }
        catch(...)
        {
            cout<<"Exceptie.";
        }
    return in;
    }
    friend ostream& operator<<(ostream &out,GestionareFarmacii& other)
    {
        out<<"Index: "; out<<other.index<<endl;
        out<<"ID: "; out<<other.id;
        out<<endl;
        out<<"FARMACII GESTIONATE: "<<endl;
        for(int i=0;i<other.index;i++)
            out<<"Farmacie "<<i+1<<endl,other.lant[i]->afisare();
        return out;
    }
    GestionareFarmacii& operator=(const GestionareFarmacii& other)
    {
    if (this == &other) return *this; // handle self assignment
    //assignment operator
    if(this!=&other)
    {
        index=other.index;
        lant=other.lant;
    }
    return *this;
    }
    GestionareFarmacii& operator+=(T& other)
    {
        T **v;
        v=new T*[index+1];
        for(int i=0;i<index;i++)
            v[i]=lant[i];
        v[index]=&other;
        index++;
        lant=v;
        return *this;
    }

    int Getindex() { return index; }
    void Setindex(int val) { index = val; }
    int Getid() { return id; }
    void Setid(int val) { id = val; }
    T** Getlant() { return lant; }
    void Setlant(T **val) { lant = val; }

    void afisare() { cout<<*this<<endl; }
    void citire() { cin>>*this; }
};

template <> class GestionareFarmacii <FarmacieOnline>
{
    int total_vizitatori_online;
    int index;
    const int id=1482;
    FarmacieOnline **lant;

public:
    GestionareFarmacii()
    {
        total_vizitatori_online=0;
        index=0;
        lant=new FarmacieOnline*[index];
    }
    GestionareFarmacii(int a,FarmacieOnline **b,int c)
    {
        index=a;
        lant=new FarmacieOnline*[index];
        for(int i=0;i<index;i++)
            lant[i]=b[i];
        total_vizitatori_online=c;
    }
    virtual ~GestionareFarmacii()
    {
        delete[] lant;
    }
    GestionareFarmacii(const GestionareFarmacii& other)
    {
        total_vizitatori_online=other.total_vizitatori_online;
        index=other.index;
        lant=other.lant;
    }
    friend istream& operator>>(istream &in,GestionareFarmacii& other)
    {
        int op2;
        cout<<"Index: "; in>>other.index;
        other.lant=new FarmacieOnline*[other.index];
        try
        {
            for(int i=0;i<other.index;i++)
            {
                other.lant[i]=new FarmacieOnline;
                other.lant[i]->citire();
            }
        }
        catch(...)
        {
            cout<<"Exceptie.";
            return in;
        }
    return in;
    }

    int calculeazaVizitatori()
    {
        total_vizitatori_online=0;
        for(int i=0;i<index;i++)
                total_vizitatori_online+=lant[i]->Getnr_vizitatori();
        return total_vizitatori_online;
    }

    friend ostream& operator<<(ostream &out,GestionareFarmacii& other)
    {
        /*out<<"Index: "; out<<other.index<<endl;
        out<<"ID: "; out<<other.id;
        out<<endl;
        out<<"FARMACII GESTIONATE: "<<endl;
        for(int i=0;i<other.index;i++)
            out<<"Farmacie "<<i+1<<endl,other.lant[i]->afisare();*/
        int x=other.calculeazaVizitatori();
        out<<"\nTotal vizitatori online: "<<x<<endl;
        return out;
    }
    GestionareFarmacii& operator=(const GestionareFarmacii& other)
    {
    if (this == &other) return *this; // handle self assignment
    //assignment operator
    if(this!=&other)
    {
        index=other.index;
        lant=other.lant;
    }
    return *this;
    }
    GestionareFarmacii& operator+=(FarmacieOnline& other)
    {
        FarmacieOnline **v;
        v=new FarmacieOnline*[index+1];
        for(int i=0;i<index;i++)
            v[i]=lant[i];
        v[index]=&other;
        index++;
        lant=v;
        return *this;
    }

    int Getindex() { return index; }
    void Setindex(int val) { index = val; }
    FarmacieOnline** Getlant() { return lant; }
    void Setlant(FarmacieOnline **val) { lant = val; }

    void afisare() { cout<<*this<<endl; }
    void citire() { cin>>*this; }
};

int main()
{
    /*Farmacie a;
    FarmacieOnline b;
    GestionareFarmacii <FarmacieOnline> c;
    a.citire(); cout<<endl;
    b.citire(); cout<<endl;

    c.citire(); cout<<endl;

    c+=b;
    c.afisare();*/

    while(1)
    {
        int op;
        cout<<"\nMENIU\n";
        cout<<"[1]Citire/stocare/afisare a n obiecte\n";
        cout<<"[2]Gestionare farmacii\n";
        cout<<"[3]Gestionare farmacii online cu afisarea numarului de vizitatori\n";
        cout<<"[4]Iesire\n";
        cout<<"Optiune: "; cin>>op;
        try
        {
            if(op<1 || op>4)
                throw 1;
        }
        catch(int a)
        {
            cout<<"Optiune inexistenta.";
            break;
        }
        switch(op)
        {
        case 1:{
            Farmacie **b;
            int nrob,i,op2;

            cout<<"Cate obiecte doriti sa creati ?\n";
            cout<<"Numar obiecte: ";cin>>nrob;
            b=new Farmacie*[nrob];

            for(int i=0;i<nrob;i++)
            {
                cout<<"\nTip obiect "<<i+1<<"\n";
                cout<<"[1]Obiecte de tip Farmacie\n";
                cout<<"[2]Obiecte de tip FarmacieOnline\n";
                cout<<"Optiune:";
                cin>>op2;
                try
                {
                    if(op<1 || op>2)
                        throw 1;
                }
                catch(int a)
                {
                    cout<<"Optiune inexistenta.";
                    break;
                }
                switch(op2){
                case 1:{
                    Farmacie *c=new Farmacie;
                    c->citire();
                    b[i]=static_cast<Farmacie*>(c);
                    break;
                    }
                case 2:{
                    FarmacieOnline *c=new FarmacieOnline;
                    c->citire();
                    b[i]=dynamic_cast<FarmacieOnline*>(c);
                    break;
                    }
                }
            }

            cout<<"\nObiecte create:\n";
            for(int i=0;i<nrob;i++)
                cout<<"Farmacie "<<i+1<<endl,b[i]->afisare();
            break;
            }
            case 2:{
                Farmacie a[100];
                GestionareFarmacii <Farmacie> b;
                int j=0,op3;
                while(1)
                {
                    cout<<"\nMENIU 2\n";
                    cout<<"[1]Adauga farmacie\n";
                    cout<<"[2]Afiseaza gestiunea\n";
                    cout<<"[3]Iesire\n";
                    cout<<"Optiune: "; cin>>op3; cout<<endl;
                    try
                    {
                        if(op3<1 || op3>3)
                            throw 1;
                    }
                    catch(int a)
                    {
                        cout<<"Optiune inexistenta.";
                        break;
                    }
                    switch(op3)
                    {
                        case 1:{
                            a[j].citire();
                            b+=a[j];
                            j++;
                            break;
                            }
                        case 2:{
                            b.afisare();
                            break;
                        }
                        case 3:{
                            break;
                        }
                    }
                }
            break;
            }
            case 3:{
                FarmacieOnline a[100];
                GestionareFarmacii <FarmacieOnline> b;
                int j=0,op3;
                while(1)
                {
                    cout<<"\nMENIU 3\n";
                    cout<<"[1]Adauga farmacie online\n";
                    cout<<"[2]Afiseaza numarul de vizitatori\n";
                    cout<<"[3]Iesire\n";
                    cout<<"Optiune: "; cin>>op3; cout<<endl;
                    try
                    {
                        if(op3<1 || op3>3)
                            throw 1;
                    }
                    catch(int a)
                    {
                        cout<<"Optiune inexistenta.";
                        break;
                    }
                    switch(op3)
                    {
                        case 1:{
                            a[j].citire();
                            b+=a[j];
                            j++;
                            break;
                            }
                        case 2:{
                            b.afisare();
                            break;
                        }
                        case 3:{
                            break;
                        }
                    }
                }
            break;
            }
            case 4:{
                return 0;
            }
        }
    }

    return 0;
}
