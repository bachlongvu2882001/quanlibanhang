#include <iostream>
using namespace std;

class Phanso
{
    int ts, ms;
public:
    Phanso();
    Phanso(int ts1, int ms1);
    friend istream & operator >> (istream &, Phanso &);
    friend ostream & operator << (ostream &, Phanso &);
    void rutgon();
    bool operator > (Phanso &);
};
int ucln(int a, int b)
{
int tam = a;
while(!(a%tam==0&&b%tam==0&&tam>0))
tam --;
return tam;

}
Phanso::Phanso()
{
ts = 0;
ms =1;
}
Phanso::Phanso(int ts1, int ms1)
{
ts = ts1;
ms = ms1;
}
ostream & operator << (ostream &os, Phanso &r)
{
  os << r.ts << "/" << r.ms;
return os;
}
istream & operator >> (istream &is, Phanso &r)
{
    cout << "Nhap tu so:";
    is >> r.ts;
    cout << "Nhap mau so:";
    is >> r.ms;
    return is;
}

bool Phanso::operator > (Phanso &r)
{
int ts1, ms1;
ts1 = ts*r.ms - ms*r.ts;
ms1 = ms * r.ms;
return (ts1*ms1>0);
}

void Phanso::rutgon()
{
int uc = ucln(ts, ms);
ts = ts/uc;
ms = ms/uc;
}
void sapxep(Phanso a[], int n)
{
Phanso tam;
int i, j;
for (i=0;i<n;++i)
for(j=i+1;j<n;++j)
if(a[j]>a[i])
{
tam = a[j];
a[j] = a[i];
a[i] = tam;
}
}
int main()
{
Phanso * a;
int n, i;
cout << "Nhap n=";
cin >> n;
a = new Phanso[n];
for(i=0;i<n;++i)
    {
        cout << "Nhap phan so thu " << i << endl;
        cin >> a[i];
    }
cout << "Mang cac phan so vua nhap vao:\n";
    for(i=0;i<n;++i){
        cout << a[i] <<endl;
        
    }
    sapxep(a, n);
    cout << "Mang sau khi sap xep:" << endl;
    for(i=0;i<n;++i){
       cout << a[i] << endl;
    }
delete  a;
system("pause");
return 0;
}