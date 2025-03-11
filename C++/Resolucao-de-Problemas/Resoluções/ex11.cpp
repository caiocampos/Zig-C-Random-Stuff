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

ostream & operator<<(ostream & os, BICR bi)
{
    copy(bi.digits.rbegin(),bi.digits.rend(),ostream_iterator<int>(os));
    return os;
}

BigInt counting[1001];

void f(){
	int i, j;
	counting[0] = BigInt("1");
	counting[1] = BigInt("2");
	counting[2] = BigInt("5");
	for(i = 3; i < 1001; i++){
		counting[i] = counting[i-1] + counting[i-1] + counting[i-2] + counting[i-3];
	}
}

int main(int argc , char *argv[]){
	#define SUBMISSAO
	#ifndef SUBMISSAO
	freopen("entrada.txt","r",stdin);
	freopen("saida.txt","w",stdout);
	#endif
	f();
	int n;
	while(true){
		if(!(cin >> n)) return 0;
		cout << counting[n] << endl;
	}
}
