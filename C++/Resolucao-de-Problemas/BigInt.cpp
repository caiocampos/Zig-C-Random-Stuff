#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>
using namespace std;

struct BigInt
{
    vector<int> digits;

    BigInt(string str="0");

    BigInt & operator+=(const BigInt & bi);
    BigInt & operator-=(const BigInt & bi);
    BigInt & operator*=(const BigInt & bi);
    BigInt & operator*=(int n);
    BigInt & operator<<=(int n);

    BigInt operator+(const BigInt & bi) const;
    BigInt operator-(const BigInt & bi) const;
    BigInt operator*(const BigInt & bi) const;
    BigInt operator*(int n) const;
    BigInt operator<<(int n) const;
};

typedef const BigInt & BICR;
typedef BigInt & BIR;

struct Ascii2Int { int operator()(int c) {return c-'0';} };

struct Add { int operator()(int a, int b) {return a+b;} };

struct Mul
{
    int k;

    Mul(){}
    Mul(int n):k(n){}

    int operator()(int a) {return a*k;}
};

struct Carry
{
    int & carry;

    Carry(int & c):carry(c){}

    int operator()(int n)
    {
        n+=carry; carry=n/10; n%=10;
        return n;
    }
};

template <class BaseOp>
struct OpWithCarry : public BaseOp, public Carry
{
    OpWithCarry(int & c):Carry(c){}

    int operator()(int a) { return Carry::operator()(BaseOp::operator()(a)); }
    int operator()(int a, int b) { return Carry::operator()(BaseOp::operator()(a,b)); }
};

struct SubWithBorrow
{
    int & borrow;

    SubWithBorrow(int & b):borrow(b){}

    int operator()(int a, int b)
    {
        int n=b-a-borrow;
        borrow=0;
        while (n<0) {n+=10; borrow++;}
        return n;
    }
};

struct Borrow
{
    int & borrow;

    Borrow(int & b):borrow(b){}

    int operator()(int n)
    {
        n-=borrow; borrow=0;
        while (n<0) {n+=10; borrow++;}
        return n;
    }
};

BigInt::BigInt(string str) { transform(str.rbegin(),str.rend(),back_inserter(digits),Ascii2Int()); }

BigInt & BigInt::operator+=(BICR bi)
{
    if (digits.size()<bi.digits.size())
        digits.resize(bi.digits.size());

    int carry=0;
    vector<int>::iterator it;

    OpWithCarry<Add> add_wc(carry);

    it=transform(bi.digits.begin(),bi.digits.end(),
        digits.begin(),digits.begin(),add_wc);

    transform(it,digits.end(),it,Carry(carry));

    if (carry) digits.push_back(carry);

    return *this;
}

BigInt & BigInt::operator-=(BICR bi)
{
    int borrow=0;
    vector<int>::iterator it;

    it=transform(bi.digits.begin(),bi.digits.end(),
        digits.begin(),digits.begin(),SubWithBorrow(borrow));

    transform(it,digits.end(),it,Borrow(borrow));

    return *this;
}

BigInt & BigInt::operator*=(int n)
{
    int carry=0;

    OpWithCarry<Mul> mul_wc(carry);
    mul_wc.k=n;

    transform(digits.begin(),digits.end(),digits.begin(),mul_wc);

    while (carry) { digits.push_back(carry%10); carry/=10; }

    return *this;
}

BigInt & BigInt::operator*=(BICR bi)
{
    const BigInt * max_op=this;
    const BigInt * min_op=&bi;

    int max_size=max_op->digits.size();
    int min_size=min_op->digits.size();

    if (max_size<min_size)
    {
        swap(max_op,min_op);
        swap(max_size,min_size);
    }

    BigInt * array=new BigInt[min_size];

    for (int i=0; i<min_size; i++)
    {
        array[i].digits.resize(max_size);

        //Multiply without carrying
        transform(max_op->digits.begin(),max_op->digits.end(),
            array[i].digits.begin(),Mul(min_op->digits[i]));
    }

    *this=array[0];
    digits.resize(max_size+min_size);

    for (int i=1; i<min_size; i++)
    {
        array[i]<<=i;

        //Add without carrying
        transform(array[i].digits.begin(),array[i].digits.end(),
            digits.begin(),digits.begin(),Add());
    }

    //Perform carrying only once
    int carry=0;
    transform(digits.begin(),digits.end(),digits.begin(),Carry(carry));

    while (carry) { digits.push_back(carry%10); carry/=10; }

    delete[] array;
    return *this;
}

BigInt & BigInt::operator<<=(int n)
{
    digits.resize(digits.size()+n);

    copy(digits.rbegin()+n,digits.rend(),digits.rbegin());
    fill(digits.begin(),digits.begin()+n,0);

    return *this;
}

BigInt BigInt::operator+(BICR bi) const { BigInt result(*this); return (result+=bi); }
BigInt BigInt::operator-(BICR bi) const { BigInt result(*this); return (result-=bi); }
BigInt BigInt::operator*(int n) const { BigInt result(*this); return (result*=n); }
BigInt BigInt::operator*(BICR bi) const { BigInt result(*this); return (result*=bi); }
BigInt BigInt::operator<<(int n) const { BigInt result(*this); return (result<<=n); }

void split(BICR op1, BICR op2, BIR x0, BIR x1, BIR y0, BIR y1, int & m)
{
    int size1=op1.digits.size();
    int size2=op2.digits.size();

    int min_size=size1;
    if (min_size>size2) min_size=size2;

    m=min_size/2;

    x0.digits.resize(m);
    x1.digits.resize(size1-m);

    y0.digits.resize(m);
    y1.digits.resize(size2-m);

    copy(op1.digits.begin(),op1.digits.begin()+m,x0.digits.begin());
    copy(op1.digits.begin()+m,op1.digits.end(),x1.digits.begin());

    copy(op2.digits.begin(),op2.digits.begin()+m,y0.digits.begin());
    copy(op2.digits.begin()+m,op2.digits.end(),y1.digits.begin());
}

BigInt karatsuba(BICR op1, BICR op2)
{
    BigInt x0, x1, y0, y1;
    BigInt z0, z1, z2;

    if (op1.digits.size()<30 || op2.digits.size()<30)
        return op1*op2;

    int m;
    split(op1,op2,x0,x1,y0,y1,m);

    z0=karatsuba(x0,y0);
    z2=karatsuba(x1,y1);
    z1=(karatsuba(x0+x1,y0+y1)-z2)-z0;

    z1<<=m;
    z2<<=2*m;

    return z0+z1+z2;
}

ostream & operator<<(ostream & os, BICR bi)
{
    copy(bi.digits.rbegin(),bi.digits.rend(),ostream_iterator<int>(os));
    return os;
}

void test(string s1, string s2)
{
    BigInt n1(s1);
    BigInt n2(s2);
    BigInt rs, rk;

    int start_s, stop_s, start_k, stop_k;

    start_s=clock();
    rs=n1*n2;
    stop_s=clock();

    start_k=clock();
    rk=karatsuba(n1,n2);
    stop_k=clock();

    cout << rs << endl;
    cout << rk << endl;
    cout << "standard time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    cout << "karatsuba time: " << (stop_k-start_k)/double(CLOCKS_PER_SEC)*1000 << endl;
}

int main()
{
    test(
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789",

    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321");
    cout << "\nhit enter to continue..." << endl;
    cin.get();

    test(
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789",

    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321");
    cout << "\nhit enter to continue..." << endl;
    cin.get();

    test(
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789",

    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321");
    cout << "\nhit enter to continue..." << endl;
    cin.get();

    test(
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789",

    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321");
    cout << "\nhit enter to continue..." << endl;
    cin.get();

    test(
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789"
    "123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789",

    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321"
    "987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321");
    cout << "\nhit enter to continue..." << endl;
    cin.get();

    return 0;
}