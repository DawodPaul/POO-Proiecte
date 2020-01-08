#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <fstream>
#include <exception>
using namespace std;

class Persoane
{
    string CNP;
    string Nume;
    double Procent;
    double Suma;
public:
    virtual string tip_job()
    {
        return "Tehnician";
    };
    friend ostream& operator<<(ostream& output,const Persoane& out);
    friend istream& operator>>(istream& inp,Persoane& bag);
    Persoane()
    {
        CNP="";
        Nume="";
        Procent=0;
        Suma=0;
    }
    Persoane(string c,string n,double p,double s)
    {
        CNP=c;
        Nume=n;
        Procent=p;
        Suma=s;
    }
    ~Persoane()
    {
        Golire();
    }

    void Golire()
    {
        CNP="";
        Nume="";
        Procent=0;
        Suma=0;
    }
    string SC_CNP()const
    {
        return CNP;
    }
    string SC_Nume()const
    {
        return Nume;
    }
    double SC_Procent()const
    {
        return Procent;
    }
    double SC_Suma()const
    {
        return Suma;
    }
    void AD_CNP(string c)
    {
        CNP=c;
    }
    void AD_Nume(string c)
    {
        Nume=c;
    }
    void AD_Procent(double c)
    {
        Procent = c;
    }
    void AD_Suma_Extra(double c)
    {
        Suma=Suma+c;
    }
    void Suma_Procente(double S)
    {
        Suma=(Procent/100)*S;
    }
};
istream& operator>>(istream& inp,Persoane&bag)
{
    string tems;
    double temd;


    if(inp==cin)
    {
        cout<<"CNP:";
        inp>>tems;
        bag.AD_CNP(tems);
        cout<<"Nume:";
        inp>>tems;
        bag.AD_Nume(tems);
        B:
        cout<<"Procent:";
        inp>>temd;
        try
        {
        double tr=temd;
        throw tr;
        }
        catch(double e)
        {
            if(e<0)
            {
                cout<<"Nu poate fi procent negativ"<<endl;
                goto B;
            }
        }
        bag.AD_Procent(temd);


    }
    else
    {
        inp>>tems;
        bag.AD_CNP(tems);
        inp>>tems;
        bag.AD_Nume(tems);
        inp>>temd;
        bag.AD_Procent(temd);

    }
}


ostream& operator<<(ostream& output,const Persoane& out)
{
    output<<"CNP:"<<out.SC_CNP()<<endl;
    output<<"Nume:"<<out.SC_Nume()<<endl;
    output<<"Procent:"<<out.SC_Procent()<<endl;
    output<<"Suma:"<<out.SC_Suma()<<endl;
}
class Regizor:public Persoane
{


public:
    friend ostream& operator<<(ostream& output,const Regizor& out);
    friend istream& operator>>(istream& in,Regizor& bag);
    Regizor():Persoane()
    {

    }

    Regizor(const Regizor& cop):Persoane()
    {
        AD_CNP(cop.SC_CNP());
        AD_Nume(cop.SC_Nume());
        AD_Procent(cop.SC_Procent());


    }
    ~Regizor()
    {
        Golire_R();
    }
    string tip_job()
    {
        return "Regizor";
    }


    void Golire_R()
    {
        Golire();
    }

    Regizor& operator=(const Regizor& cop)
    {
        Golire();
        this->AD_CNP(cop.SC_CNP());
        this->AD_Nume(cop.SC_Nume());
        this->AD_Procent(cop.SC_Procent());

        return *this;
    }
};

ostream& operator<<(ostream& output,const Regizor& out)
{
    output<<"CNP:"<<out.SC_CNP()<<endl;
    output<<"Nume:"<<out.SC_Nume()<<endl;
    output<<"Procent:"<<out.SC_Procent()<<endl;
    output<<"Suma:"<<out.SC_Suma()<<endl;

}
istream& operator>>(istream& inp,Regizor&bag)
{
    string tems;
    double temd;


    if(inp==cin)
    {
        cout<<"CNP:";
        inp>>tems;
        bag.AD_CNP(tems);
        cout<<"Nume:";
        inp>>tems;
        bag.AD_Nume(tems);
        B:
        cout<<"Procent:";
        inp>>temd;
         try
        {
        double tr=temd;
        throw temd;
        }
        catch(double e)
        {
            if(e<0)
            {
                cout<<"Nu poate fi procent negativ"<<endl;
                goto B;
            }
        }
        bag.AD_Procent(temd);


    }
    else
    {
        inp>>tems;
        bag.AD_CNP(tems);
        inp>>tems;
        bag.AD_Nume(tems);
        inp>>temd;
        bag.AD_Procent(temd);

    }
}

class Actor:public Persoane
{

public:
    friend ostream& operator<<(ostream& output,const Actor& out);
    friend istream& operator>>(istream& in,Actor& bag);
    Actor():Persoane()
    {

    }

    Actor(const Actor& cop):Persoane()
    {
        AD_CNP(cop.SC_CNP());
        AD_Nume(cop.SC_Nume());
        AD_Procent(cop.SC_Procent());


    }
    ~Actor()
    {
        Golire_A();
    }
    string tip_job()
    {
        return "Actor";
    }


    void Golire_A()
    {
        Golire();
    }

    Actor& operator=(const Actor& cop)
    {
        Golire();
        this->AD_CNP(cop.SC_CNP());
        this->AD_Nume(cop.SC_Nume());
        this->AD_Procent(cop.SC_Procent());

        return *this;
    }
};

ostream& operator<<(ostream& output,const Actor& out)
{
    output<<"CNP:"<<out.SC_CNP()<<endl;
    output<<"Nume:"<<out.SC_Nume()<<endl;
    output<<"Procent:"<<out.SC_Procent()<<endl;
     output<<"Suma:"<<out.SC_Suma()<<endl;

}
istream& operator>>(istream& inp,Actor&bag)
{
    string tems;
    double temd;


    if(inp==cin)
    {
        cout<<"CNP:";
        inp>>tems;
        bag.AD_CNP(tems);
        cout<<"Nume:";
        inp>>tems;
        bag.AD_Nume(tems);
        bool a;
        cout<<"Actor principal?[0/1]:"; cin>>a;
        if(a==1)
        {
            bag.AD_Procent(10);
        }
        else
        {
        B:
        cout<<"Procent:";
        inp>>temd;
 try
        {
        double tr=temd;
        throw temd;
        }
        catch(double e)
        {
            if(e<0)
            {
                cout<<"Nu poate fi procent negativ"<<endl;
                goto B;
            }
            if(e>=10)
            {
                cout<<"Nu poate avea procent mai mare sau egal cu al unui actor principal"<<endl;
                goto B;
            }
        }

        bag.AD_Procent(temd);

}

    }
    else
    {
        inp>>tems;
        bag.AD_CNP(tems);
        inp>>tems;
        bag.AD_Nume(tems);
        inp>>temd;
        bag.AD_Procent(temd);

    }
}

////////////
class Film
{
    string Nume;
    string Tip;
    int Durata;
    double Profit=0;
    vector<Persoane*> Pers;


public:
    friend istream& operator>>(istream& input,Film& bag);
    friend ostream& operator<<(ostream& output,const Film& scot);
    Film()
    {
        Nume="";
        Tip="";
        Durata=0;
        Profit =0.0;
    }
    Film(const Film& cop)
    {
        Nume=cop.Nume;
        Tip=cop.Tip;
        Durata=cop.Durata;
        Profit=cop.Profit;
    }

    Film(string n,string t,int d,double p)
    {
        Nume=n;
        Tip=t;
        Durata=d;
        Profit=p;
    }
    ~Film()
    {
        Golire();
    }

    void Golire()
    {
        Nume="";
        Tip="";
        Durata=0;
        Profit =0;
        Pers.clear();

    }
    void AD_Nume(string c)
    {
        Nume=c;
    }
    void AD_Tip(string c)
    {
        Tip=c;
    }
    void AD_Dur(int c)
    {
        Durata =c;
    }
    void AD_PRO(int c)
    {
        Profit =c;
    }
    void AD_Pers(Persoane*p)
    {
        Pers.push_back(p);
    }
    string SC_Nume() const
    {
        return Nume;
    }
    string SC_Tip() const
    {
        return Tip;
    }
    int SC_Durata() const
    {
        return Durata;
    }
    double SC_PRO()const
    {
        return Profit;
    }

    void Creare_Pers(istream& in)
    {
        int nr_p;
        if(in==cin)
        {
            cout<<"Nr pers=";
        }
        in>>nr_p;
        for(int i=0;i<nr_p;i++)
        {

        int a;
A:
        if(in==cin)
            cout<<"\nTip Job\n1-Regizor\n2-Actor\n3-Tehnician\nAlegere:";
        in>>a;
        switch(a)
        {
        case 1:
        {
            Persoane* temP= new Regizor;
            Regizor* temR=dynamic_cast<Regizor*>(temP);
            in>>*temR;
            if(Profit>0)
            temR->Suma_Procente(Profit);
            double t;
            cout<<"Suma extra Regizor:";
            cin>>t;
            temR->AD_Suma_Extra(t);
            AD_Pers(temR);

        }
        break;
        case 2:
        {
            Persoane* temP=new Actor;
            Actor* temA=dynamic_cast<Actor*>(temP);
            in>>*temA;
            if(Profit>0)
            temA->Suma_Procente(Profit);
            AD_Pers(temA);

        }
        break;
        case 3:
        {
            Persoane *temP=new Persoane;
            in>>*temP;
            if(Profit>0)
            temP->Suma_Procente(Profit);
            AD_Pers(temP);
        }break;
        default:
        {
            cout<<"Nu exista varianta";
            goto A;
        }
        }
        }
    }
    void Print_Pers()
    {
        vector<Persoane*>::iterator it;

        for(it=Pers.begin(); it!=Pers.end(); ++it)
        {
            Persoane* temp=new Persoane;
            temp=*it;
            cout<<temp->tip_job()<<endl<<*temp;
        }

    }
    vector<Persoane*> SC_Pers()
    {
        return Pers;
    }

};

ostream& operator<<(ostream& output,const Film& scot)
{
    output<<"Nume:"<<scot.SC_Nume()<<endl;
    output<<"Tip:"<<scot.SC_Tip()<<endl;
    output<<"Durata:"<<scot.SC_Durata()<<endl;
    output<<"Profit:"<<scot.SC_PRO()<<endl;
}
istream& operator>>(istream& input,Film& bag)
{
    bag.Golire();
    if(input==cin)
    {
        string tems1,tems2;
        int temi1;
        double temd;
        cout<<"Nume:";
        input>>tems1;
        cout<<"Tip:";
        input>>tems2;
        cout<<"Durata:";
        input>>temi1;
        cout<<"Profit:";
        input>>temd;
        bag.AD_Nume(tems1);
        bag.AD_Tip(tems2);
        bag.AD_Dur(temi1);
        bag.AD_PRO(temd);
    }
    else
    {
        string tems1,tems2;
        int temi1;
        double temd;
        input>>tems1;
        input>>tems2;
        input>>temi1;
        input>>temd;
        bag.AD_Nume(tems1);
        bag.AD_Tip(tems2);
        bag.AD_Dur(temi1);
        bag.AD_PRO(temd);
    }

}

template<class T>
class FirmaDistributie
{
    vector<Film*> F;
    int NR_Total_Pers;
public:
    FirmaDistributie()
    {
        NR_Total_Pers=0;
    }
    FirmaDistributie(vector<Film*> cop)
    {
        F=cop;
    }
    ~FirmaDistributie()
    {
        F.clear();
    }
    void AD_Film(Film* ad)
    {
        F.push_back(ad);
        NR_Total_Pers_FC();

    }
    void CR_Film(istream& in)
    {
        Film *t=new Film;
        in>>*t;
        t->Creare_Pers(in);
        F.push_back(t);
        NR_Total_Pers_FC();

    }
    void Print_FILME()
    {
        cout<<"SC_FILM"<<endl;
        vector<Film*>::iterator it;
        for(it=F.begin(); it!=F.end(); ++it)
        {
            Film *temp=new Film;
            temp=*it;
            cout<<*temp;
            cout<<"PERS FILM:"<<endl<<endl;
            temp->Print_Pers();
        }
    }
    vector<Film*> SC_Filme()
    {
        return F;
    }
    void NR_Total_Pers_FC()
    {
        int i=0;
        vector<Film*>::iterator it;
        vector<Persoane*> TemPS;
        for(it=F.begin(); it!=F.end(); ++it)
        {
            Film *temf=new Film;
            temf=*it;
            TemPS=temf->SC_Pers();
            vector<Persoane*>::iterator it2;
            for(it2=TemPS.begin(); it2!=TemPS.end(); ++it2)
            {
                i++;

            }
            TemPS.clear();
        }

        cout<<"NR Total Pers:"<<i<<endl;
        NR_Total_Pers=i;
    }



    int SC_NR_PERS()
    {
        return NR_Total_Pers;
    }


    vector<Persoane*> Actori_Total()
    {
        vector<Persoane*> V_A;
        int cont=0;
       vector<Film*>::iterator it;
        vector<Persoane*> TemPS;
            vector<Persoane*>::iterator it2;
        for(it=F.begin(); it!=F.end(); ++it)
        {
            Film *temf=new Film;
            temf=*it;
            TemPS=temf->SC_Pers();
            for(it2=TemPS.begin();it2!=TemPS.end();++it2)
            {
                Persoane* teP=new Persoane;
                teP=*it2;
                if(teP->tip_job()=="Actor")
                {

                    cont++;
                    V_A.push_back(teP);
                }
            }

    }
    cout<<"NR TOTAL ACTORI:"<<cont<<endl;
    return V_A;
    }
};
template<>
class FirmaDistributie<class Actor>
{
    int contor;
    tuple<Persoane*,bool> *Actori;

public:
    FirmaDistributie()
    {
        contor=0;
        Actori=new tuple<Persoane*,bool>[0];
    }
    ~FirmaDistributie()
    {

    }

    void AD_Actor(Persoane* a)
    {
        tuple<Persoane*,bool>*tuple_temp=new tuple<Persoane*,bool>[contor];
        for(int i=0;i<contor;i++)
        {
          tuple_temp[i]=Actori[i];
        }
        contor++;
        Actori=new tuple<Persoane*,bool>[contor];
        for(int i=0;i<contor;i++)
        {
            Actori[i]=tuple_temp[i];
        }
       if(a->SC_Procent()==10)
            Actori[contor-1]=make_tuple(a,1);
            else
             Actori[contor-1]=make_tuple(a,0);

    }
    void AD_Actor_Film(vector<Persoane*> TP)
    {
        vector<Persoane*>::iterator it;
        for(it=TP.begin();it!=TP.end();++it)
        {
            Persoane *t=new Persoane;
            t=*it;
            AD_Actor(t);
        }

    }
    int NR_Act_P()
    {
        int c=0;
        for(int i=0;i<contor;i++)
        {
            if(get<1>(Actori[i])==1)
                c++;
        }
        return c;
    }
};


int main()
{
    FirmaDistributie<void> Frm;
    FirmaDistributie<Actor> Act;

    Frm.CR_Film(cin);
    Frm.CR_Film(cin);
    Frm.Print_FILME();

  Act.AD_Actor_Film(Frm.Actori_Total());
  cout<<"NR Actori Principali:"<<Act.NR_Act_P();








    return 0;
}
