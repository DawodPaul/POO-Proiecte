#include <iostream>
#include <fstream>

using namespace std;
ifstream f("matrice");
ifstream g("vector");


class Matrice
{
    int **a;
    int n;
public:
    friend ostream& operator <<(ostream&,Matrice out);


    Matrice()
    {
        a=NULL;
        n=0;
    }

    Matrice(int nr)
    {

        n=nr;

    }

    Matrice(const Matrice &cop)
    {
        delete []a;
        n=cop.n;

          a=new int*[n];
        for(int i=0;i<n;i++)
          a[i]=new int[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                a[i][j]=cop.a[i][j];
        }

    }

    ~Matrice()
    {

         delete[]a;
         n=0;
         a=NULL;

    }

    void Golire()
    {
        delete []a;
        n=0;
    }

    void Umplere()
    {
        a=new int*[n];
        for(int i=0;i<n;i++)
          a[i]=new int[n];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                f>>a[i][j];
        }
    }


    void Creare_mat(int v)
    {
        n=v;
         a=new int*[n];
        for(int i=0;i<n;i++)
          a[i]=new int[n];

    }
    void Creare_el(int v,int i,int j)
    {
        a[i][j]=v;
    }

    void Afisare()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<a[i][j]<<" ";

            cout<<endl;
        }
    }

  Matrice& operator =(const Matrice&cop)
  {
      n=cop.n;
      delete []a;
      a=new int*[n];
      for(int i=0;i<n;i++)
        a[i]=new int[n];

      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j]=cop.a[i][j];
  }




};


istream& operator >>(istream& input,Matrice &in)
{
    int temp,temp2;
    in.Golire();
   cout<<"Ordin Matrice:"; input>>temp;
    in.Creare_mat(temp);
    for(int i=0;i<temp;i++)
        for(int j=0;j<temp;j++)
        {
            printf("Elem[%d][%d]:",i,j);
            input>>temp2;
            in.Creare_el(temp2,i,j);
        }
}


ostream& operator <<(ostream& output,Matrice out)
{
for(int i=0;i<out.n;i++)
{
    for(int j=0;j<out.n;j++)
    {
        output<<out.a[i][j]<<" ";
    }
    output<<endl;
}
}



class Vector
{
    int *v;
    int dim;
public:
    friend bool operator ==(const Vector&,const Vector&com);
    friend bool operator !=(Vector&,const Vector&com);
    friend ostream& operator <<(ostream& output,const Vector& scot);

    Vector()
    {
        v=NULL;
        dim=0;
    }
    Vector(int n)
    {
        dim=n;
        v=new int[dim];

    }
    Vector(const Vector&cop)
    {
        delete[]v;
        dim=cop.dim;
        v=new int[dim];
        for(int i=0;i<dim;i++)
            v[i]=cop.v[i];

    }
    ~Vector()
    {
        delete[]v;
        v=NULL;
        dim = 0;
    }
    void Umplere()
    {
        for(int i=0;i<dim;i++)
            g>>v[i];
    }
    void Adaugare_el(int n)
    {
        dim++;


       int* temp=new int[dim-1];
            for(int i=0; i<dim-1; i++)
                temp[i]=v[i];


          delete []v;
        v=new int[dim];


          for(int i=0; i<n-1; i++)
                v[i]=temp[i];
        v[dim-1]=n;
    }
    void Golire()
    {
        delete[]v;
        v=NULL;
        dim = 0;
    }

    void Afisare()
    {
        for(int i=0;i<dim;i++)
            cout<<v[i]<<" ";

        cout<<endl;
    }


    Vector& operator =(const Vector&cop)
{
if(this!=&cop)
{
    delete[]v;
    dim=cop.dim;
    v=new int[dim];
    for(int i=0;i<dim;i++)
        v[i]=cop.v[i];
}
}

bool operator ==(const Vector&com)
{
    if(this->dim==com.dim)
    {
        for(int i=0;i<this->dim;i++)
            if(this->v[i]!=com.v[i])
                return 0;

    }
    return 1;
}

bool operator !=(const Vector&com)
{
       if(this->dim==com.dim)
    {
        for(int i=0;i<this->dim;i++)
            if(this->v[i]!=com.v[i])
                return 1;

    }
    else if(this->dim!=com.dim)
    return 1;

    return 0;
}


};

istream& operator >>(istream& input,Vector& bag)
 {
     bag.Golire();
     int n,temp;
     cout<<"NR EL:";
     input>>n;
     for(int i=0;i<n;i++)
     {
         cout<<"Elem "<<i+1<<"=";
         input>>temp;
         bag.Adaugare_el(temp);
     }
     return input;
 }

 ostream& operator <<(ostream& output,const Vector& scot)
 {
     for(int i=0;i<scot.dim;i++)
     {
         output<<scot.v[i]<<" ";
     }
     output<<"\n";
     return output;
 }





struct Nod
    {
       Vector* l;
    Nod* urm;

    };


class Lista
{

    Nod* Cap;

public:
friend ostream& operator<<(ostream&output,const Lista&out);


    int cnt=0;
    Lista()
    {
        Cap->l=NULL;
        Cap->urm=NULL;
    }
    Lista(const Lista &cop)
    {
        Cap->l=cop.Cap->l;
        Cap->urm=cop.Cap->urm;
    }

    ~Lista()
    {
    cnt=0;
    Nod* temp=NULL;
    while(Cap->urm!=NULL)
    {
      temp=Cap;

        delete temp;
    }

    }

    void inserareFinal(Vector& val)
{
    cnt++;
    Nod *elem = new Nod;
    elem->l = &val;
    elem->urm = NULL;
    if (&Cap == NULL)
        Cap=elem;
    else
    {
        Nod *nod_curent = Cap;
        while (nod_curent->urm != NULL)
            nod_curent = nod_curent->urm;
        nod_curent->urm = elem;
    }
}
    void Afisare()
    {
        Nod*temp=Cap;
        while(temp!=NULL)
        {
            temp->l->Afisare();
            temp=temp->urm;
        }
    }

void    Stergere_totala()
{
    cnt=0;
    Nod* temp=NULL;
    while(Cap!=NULL)
    {
      temp=Cap;
      Cap=Cap->urm;
        delete temp;
    }
}



Lista& operator =(const Lista& cop)
    {
      Stergere_totala();
      Nod* temp=cop.Cap;
      Vector *tp=new Vector;
      tp=NULL;
      while(temp!=NULL)
      {
          tp=temp->l;
          inserareFinal(*tp);
          temp=temp->urm;
      }


    }



};

istream& operator>>(istream& input,Lista&in)
{
    int nr_v;
    cout<<"Nr vectori:"; input>>nr_v;
    for(int i=0;i<nr_v;i++)
    {
        Vector temp;
        input>>temp;
        in.inserareFinal(temp);
    }
}
ostream& operator<<(ostream&output,const Lista&out)
{
    Nod *t=new Nod;
    t=out.Cap;
 while(t)
 {
     output<<t->l;
     t=t->urm;
 }
}


struct gr
{
    int nd1;
    int* nd2;
};


class Graf
{
    int nr;
    gr *grf;
    Matrice mtr;
    Lista *lst;
 public:

     Graf()
     {
         nr=0;
         grf=NULL;
         lst=NULL;
         mtr=NULL;

     }
     Graf(const Matrice&org)
     {
         mtr=org;
     }
     Graf(const Lista&org)
     {
         *lst=org;
     }
     Graf(const Graf&cop)
     {
      nr=cop.nr;
      grf=cop.grf;
      mtr=cop.mtr;
      lst=cop.lst;
     }
    ~Graf()
    {
        nr=0;
        delete []grf;
        mtr.Golire();
        lst->Stergere_totala();
    }
    virtual void tip()=0;

    void InNr(int n)
    {
        nr=n;
    }
    void IntMat(Matrice m)
    {
        mtr=m;
    }
    void IntList(Lista ls)
    {
     *lst=ls;
    }

    void Creare_O()
    {
    Matrice temp =mtr;
        {
            cout<<endl;
            cout<<"[";
            for(int i=0;i<temp.n;i++)
                for(int j=0;j<temp.n;j++)
                if(temp.a[i][j]==1)
                cout<<"("<<i+1<<","<<j+1<<")";
            cout<<"]";
        }
    }



    void Creare_N()
    {
            int i=1;
            Nod *temp=new Nod;
            temp=lst->Cap;
            while(temp!=NULL)
            {
                cout<<"Legaturi nod "<<i<<":"; cout<<temp.l;
                i++;
                temp=temp->urm;
            }
    }
};



class Graf_O: public Graf
{
Matrice mt;

 public:
     friend ostream& operator<<(ostream& output,Graf_O out);
     Graf_O():Graf()
     {
    mt=NULL;
     }
     Graf_O(const Graf_O&cop):Graf(cop)
     {
        mt=cop.mt;


     }
     ~Graf_O()
     {
        mt.Golire();

     }
     void Adaugare(const Matrice&cop)
     {
         mt=cop;
         this.IntMat(cop);
     }
    void tip()
    {
     cout<<"Graf Orientat";
    }
};


istream& operator>>(istream& input,Graf_O& in)
{

        Matrice temp;
        input>>temp;
        in.IntMat(temp);

}

ostream& operator<<(ostream& output,Graf_O out)
{
    out.Creare_O()
}
class Graf_N:public Graf
{
     Lista lista=NULL;
     Graf_N():Graf()
     {

     }
     Graf_N(const Graf_N&cop):Graf(cop)
     {
         vct=cop.vct;
     }
     Graf_N(Lista&og):Graf(og)
     {
        lista=og;
     }
     ~Graf_N()
     {
         vct.Golire();
         vct=NULL;
     }

     void Adaugare(const Lista&cop)
     {
         lista=cop;
         this.IntList(cop);
     }
     void tip()
     {
         cout<<"Graf Neorientat";
     }
};

istream* operator>>(istream& input,Graf_N& in)
{
    Lista *temp=NULL
    cout<<"Cate liste:";int nr;input>>nr;
    for(int i=0;i<nr;i++)
    {
    input>>temp;
    in.Adaugare(temp);
    }
}


    int main()
    {
        /*
Matrice m(3);
m.Umplere();
m.Afisare();

Matrice j(m);
j.Afisare();


j.Golire();
j.Afisare();
cout<<"G"<<endl;


Matrice pr;
cin>>pr;
pr.Afisare();
cout<<pr;

cin>>pr;
cout<<pr;

Vector k(8);
k.Umplere();
k.Afisare();

Vector i(8);
i.Umplere();
i.Afisare();

Vector l(6);
l.Umplere();
l.Afisare();


k=i;
k.Afisare();
l.Afisare();

cout<<"T";

Vector ts;
ts.Afisare();
ts.Adaugare_el(23);
ts.Afisare();
ts.Adaugare_el(70);
cout<<ts;

Vector a(8);
a.Umplere();
Vector b(8);
b.Umplere();

a.Afisare();
b.Afisare();
Lista grf;
grf.inserareFinal(a);
grf.Afisare();
*/


 return 0;
    }


