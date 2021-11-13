#include <iostream>
using namespace std;

class Phanso
{
    private:
        int ts, ms;
    public:
        Phanso();
        Phanso(int ts1, int ms1);
        friend istream & operator >> (istream &, Phanso &);
        friend ostream & operator << (ostream &, Phanso &);
        Phanso operator + (Phanso &);
        Phanso operator - (Phanso &);
        Phanso operator * (Phanso &);
        void rutgon();
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
Phanso Phanso::operator+(Phanso &r)
{
    int ts1, ms1;
    ts1 = ts*r.ms + ms*r.ts;
    ms1 = ms * r.ms;
    int uc = ucln(ts1, ms1);
    ts1 = ts1/uc;
    ms1 = ms1/uc;
    return Phanso(ts1, ms1);
}
Phanso Phanso::operator-(Phanso &r)
{
    int ts1, ms1;
    ts1 = ts*r.ms - ms*r.ts;
    ms1 = ms * r.ms;
    int uc = ucln(ts1, ms1);
    ts1 = ts1/uc;
    ms1 = ms1/uc;
    return Phanso(ts1, ms1);
}
Phanso Phanso::operator*(Phanso &r)
{
    int ts1, ms1;

    ts1 = ts*r.ts;
    ms1 = ms * r.ms;
    int uc = ucln(ts1, ms1);
    ts1 = ts1/uc;
    ms1 = ms1/uc;
    return Phanso(ts1, ms1);
}
void Phanso::rutgon()
{
    int uc = ucln(ts, ms);
    ts = ts/uc;
    ms = ms/uc;
}
int main()
{
    Phanso * a;
    int n, i;
    Phanso tong, tich(1,1);
    int m1, m2;
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
        m1 = m2 = 0;
    }
    for(i=0;i<n;++i)
    {
        tong = tong + a[i];
    }
    cout << "Phan so tong:" << tong << endl;
delete  a;
system("pause");
return 0;
}


