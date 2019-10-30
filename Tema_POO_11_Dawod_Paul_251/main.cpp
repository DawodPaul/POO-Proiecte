#include <iostream>

using namespace std;

class Multime
{
    int*v;
    int n;
public:
    friend Multime operator *(const Multime&A,const Multime&B);
    friend Multime operator -(const Multime&A,const Multime&B);
    friend ostream& operator <<(ostream& output,const Multime& scot);
    friend Multime operator +(const Multime&A,const Multime& B);
    Multime()
    {
        v=NULL;
        n=0;
    }
    Multime(const Multime& cop)
    {
        n=cop.n;
        v=new int[n];
        for(int i=0; i<n; i++)
            v[i]=cop.v[i];
    }
    bool Verificare(int val)
    {
        for(int i=0; i<n; i++)
            if(v[i]==val)
            {
                return 1;
            }
        return 0;
    }
    void Adaugare(int valoare)
    {
        if(Verificare(valoare)==0)
        {
            n++;
            int* temp=new int[n];
            for(int i=0; i<n-1; i++)
                temp[i]=v[i];
            delete []v;
            v=temp;
            v[n-1]=valoare;
        }
    }
    void Golire()
    {
        delete []v;
        n=0;
        v=NULL;
    }
    void TransformareVM(int *vect,int mar)
    {
        Golire();
        for(int i=0; i<mar; i++)
        {
            Adaugare(vect[i]);
        }
    }
    void Afisare()
    {
        for(int i=0; i<n; i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }

    Multime& operator =(const Multime& cop)
    {
        if(this!=&cop)
        {
            Golire();
            n=cop.n;
            v=new int[n];
            for(int i=0; i<n; i++)
                v[i]=cop.v[i];
        }

        return *this;
    }
    ~Multime()
    {
        Golire();
        cout<<"M-am sters\n";
    }

};
istream& operator >>(istream& input,Multime& bag)
 {
     bag.Golire();
     int n,temp; input>>n;
     for(int i=0;i<n;i++)
     {
         input>>temp;
         bag.Adaugare(temp);
     }
     return input;
 }

 ostream& operator <<(ostream& output,const Multime& scot)
 {
     for(int i=0;i<scot.n;i++)
     {
         output<<scot.v[i]<<" ";
     }
     output<<"\n";
     return output;
 }

 Multime operator +(const Multime&A,const Multime& B)
 {
     Multime Rez=A;
     for(int i=0;i<B.n;i++)
     {
         Rez.Adaugare(B.v[i]);
     }
     return Rez;
 }

 Multime operator -(const Multime&A,const Multime&B)
 {
     Multime Rez;
     bool exista;
     for(int i=0;i<A.n;i++)
     {
         exista=0;
         for(int j=0;j<B.n;j++)
         {
             if(A.v[i]==B.v[j])
                exista=1;
         }
         if(exista==0)
            Rez.Adaugare(A.v[i]);
     }
     return Rez;

 }
 Multime operator *(const Multime&A,const Multime&B)
 {
     Multime Rez;
     bool exista;
     for(int i=0;i<A.n;i++)
     {
         exista=0;
         for(int j=0;j<B.n;j++)
         {
             if(A.v[i]==B.v[j])
                exista=1;
         }
         if(exista==1)
            Rez.Adaugare(A.v[i]);
     }
     return Rez;

 }
int main()
{
    Multime X;
    Multime Z;
    Multime H;
    int a[]= {1,2,3,4,1,2,67,54,3};
    int b[]={2,4,100,200};
    X.TransformareVM(a,sizeof(a)/sizeof(int));
    Z.TransformareVM(b,4);
    cout<<X<<Z;
    H=X*Z;
    cout<<H;


    return 0;
}
