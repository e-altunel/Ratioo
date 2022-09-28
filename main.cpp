#include<iostream>
using namespace std;

class ratioo;
std::ostream& operator << (std::ostream& os, const ratioo& obj);

class ratioo
{
    public:
    int pay;
    int payda;

    void sadelestirici(ratioo * x)
    {
        for (int i = 2; i <= std::abs(x->pay) && i <= std::abs(x->payda); i++)
        {
            if (x->pay % i == 0 && x->payda % i == 0)
            {
                x->pay /= i;
                x->payda /= i;
                i--;
            }
        }
        if ((x->pay < 0 && x->payda < 0) || (x->pay > 0 && x->payda < 0))
        {
            x->pay = -x->pay;
            x->payda = -x->payda;
        }
    }

    ratioo()
    {
        this->pay = 0;
        this->payda = 1;
    }
    ratioo(int pay)
    {
        this->pay = pay;
        this->payda = 1;
    }
    ratioo(double pay)
    {
        this->payda = 1;
        int c = 0;
        while (pay != (int) pay)
        {
            c++;
            if (c > 4) break;
            this->payda *= 10;
            pay *= 10;
        }
        this->pay = pay;
        sadelestirici(this);
    }
    ratioo(int pay, int payda)
    {
        this->pay = pay;
        this->payda = payda;
        sadelestirici(this);
    }
    ratioo(double pay, double payda)
    {
        pay = pay / payda;
        this->payda = 1;
        int c = 0;
        while (pay != (int) pay)
        {
            c++;
            if (c > 4) break;
            this->payda *= 10;
            pay *= 10;
        }
        this->pay = pay;
        sadelestirici(this);
    }

    ratioo operator = (int i)
    {
        ratioo dum(i);
        return dum;
    }
    ratioo operator = (double i)
    {
        ratioo dum(i);
        return dum;
    }

#pragma region sum
    ratioo operator + (ratioo &i)
    {
        ratioo sum;
        sum.payda = payda * i.payda;
        sum.pay = payda * i.pay + i.payda * pay;
        sadelestirici(&sum);
        return sum;
    }
    ratioo operator + (int i)
    {
        ratioo sum;
        sum.payda = payda;
        sum.pay = payda * i + pay;
        return sum;
    }
    ratioo operator + (double x)
    {
        ratioo sum;
        ratioo i(x);
        sum.payda = payda * i.payda;
        sum.pay = payda * i.pay + i.payda * pay;
        sadelestirici(&sum);
        return sum;
    }
    
    ratioo operator += (ratioo &i)
    {
        ratioo sum;
        sum.payda = payda * i.payda;
        sum.pay = payda * i.pay + i.payda * pay;
        sadelestirici(&sum);
        *this = sum;
        return sum;
    }
    ratioo operator += (int i)
    {
        ratioo sum;
        sum.payda = payda;
        sum.pay = payda * i + pay;
        *this = sum;
        return sum;
    }
    ratioo operator += (double x)
    {
        ratioo sum;
        ratioo i(x);
        sum.payda = payda * i.payda;
        sum.pay = payda * i.pay + i.payda * pay;
        sadelestirici(&sum);
        *this = sum;
        return sum;
    }
#pragma endregion
#pragma region minus
    ratioo operator - (ratioo &i)
    {
        ratioo sum;
        sum.payda = payda * i.payda;
        sum.pay = i.payda * pay - payda * i.pay;
        sadelestirici(&sum);
        return sum;
    }
    ratioo operator - (int i)
    {
        ratioo sum;
        sum.payda = payda;
        sum.pay = pay - payda * i;
        return sum;
    }
    ratioo operator - (double x)
    {
        ratioo sum;
        ratioo i(x);
        sum.payda = payda * i.payda;
        sum.pay = i.payda * pay - payda * i.pay;
        sadelestirici(&sum);
        return sum;
    }
    
    ratioo operator -= (ratioo &i)
    {
        ratioo sum;
        sum.payda = payda * i.payda;
        sum.pay = i.payda * pay - payda * i.pay;
        sadelestirici(&sum);
        *this = sum;
        return sum;
    }
    ratioo operator -= (int i)
    {
        ratioo sum;
        sum.payda = payda;
        sum.pay = pay - payda * i;
        *this = sum;
        return sum;
    }
    ratioo operator -= (double x)
    {
        ratioo sum;
        ratioo i(x);
        sum.payda = payda * i.payda;
        sum.pay = i.payda * pay - payda * i.pay;
        sadelestirici(&sum);
        *this = sum;
        return sum;
    }
#pragma endregion
#pragma region carpma
    ratioo operator * (ratioo &i)
    {
        ratioo sum;
        sum.payda = payda * i.payda;
        sum.pay = pay * i.pay;
        sadelestirici(&sum);
        return sum;
    }
    ratioo operator * (int i)
    {
        ratioo sum;
        sum.payda = payda;
        sum.pay = pay * i;
        sadelestirici(&sum);
        return sum;
    }
    ratioo operator * (double x)
    {
        ratioo sum;
        ratioo i(x);
        sum.payda = payda * i.payda;
        sum.pay = pay * i.pay;
        sadelestirici(&sum);
        return sum;
    }
    
    ratioo operator *= (ratioo &i)
    {
        ratioo sum;
        sum.payda = payda * i.payda;
        sum.pay = pay * i.pay;
        sadelestirici(&sum);
        *this = sum;
        return sum;
    }
    ratioo operator *= (int i)
    {
        ratioo sum;
        sum.payda = payda;
        sum.pay = pay * i;
        sadelestirici(&sum);
        *this = sum;
        return sum;
    }
    ratioo operator *= (double x)
    {
        ratioo sum;
        ratioo i(x);
        sum.payda = payda * i.payda;
        sum.pay = pay * i.pay;
        sadelestirici(&sum);
        *this = sum;
        return sum;
    }
#pragma endregion
#pragma region bolme
    ratioo operator / (ratioo &i)
    {
        ratioo sum;
        sum.payda = payda * i.pay;
        sum.pay = pay * i.payda;
        sadelestirici(&sum);
        return sum;
    }
    ratioo operator / (int i)
    {
        ratioo sum;
        sum.payda = payda * i;
        sum.pay = pay;
        sadelestirici(&sum);
        return sum;
    }
    ratioo operator / (double x)
    {
        ratioo sum;
        ratioo i(x);
        sum.payda = payda * i.pay;
        sum.pay = pay * i.payda;
        sadelestirici(&sum);
        return sum;
    }
    
    ratioo operator /= (ratioo &i)
    {
        ratioo sum;
        sum.payda = payda * i.pay;
        sum.pay = pay * i.payda;
        sadelestirici(&sum);
        *this = sum;
        return sum;
    }
    ratioo operator /= (int i)
    {
        ratioo sum;
        sum.payda = payda * i;
        sum.pay = pay;
        sadelestirici(&sum);
        *this = sum;
        return sum;
    }
    ratioo operator /= (double x)
    {
        ratioo sum;
        ratioo i(x);
        sum.payda = payda * i.pay;
        sum.pay = pay * i.payda;
        sadelestirici(&sum);
        *this = sum;
        return sum;
    }
#pragma endregion

};

std::ostream& operator << (std::ostream& os, const ratioo& obj)
{
    if (obj.payda != 1)
    {
        if (obj.pay != 0)
        {
            os << obj.pay << '/' << obj.payda << " -> " << (double)obj.pay / obj.payda;
        }
        else
        {
            os << 0;
        }
    } 
    else 
    {
        os << obj.pay;
    }
    return os;
}

int main(int argc, char const *argv[])
{
    ratioo test(5,4);
    test /= 5;
    cout << test;
    return 0;
}
