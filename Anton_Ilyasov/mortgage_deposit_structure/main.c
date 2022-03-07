#include <stdio.h> //������� � ����� ����� ���������

int life = 120;

struct Country //����������� ��������� "������"
{
    char *name;
    double infl;
};


struct Investor //����������� ��������� "��������"
{
    char *name;
    long long int cap;
    long long int bank;
    double dep_per;
    long long int flat;
    long rent_m;
    long int salary;
    long int m_save;
    long int mortg_r_m;
};

void _Russia(struct Country* country) //������������� ������� ������
{
    country->name = "Russia";
    country->infl = 0.08;
}

void _Alice(struct Investor* investor) //������������� ������� �����
{
    investor->name = "Alice";
    investor->cap = 10;
    investor->bank = 12000;
    investor->dep_per = 0.01;
    investor->flat = 100;
    investor->mortg_r_m = 0;
    investor->salary = 15;
    investor->m_save = 5;
}

void _output(struct Investor* investor) //����� ������
{
    printf("Investor's name: %s\n", investor->name);

    int rur_m = investor->bank/1000000;
    int rur_t = investor->bank/1000 - rur_m * 1000;
    int rur = investor->bank
        - (rur_m * 1000 * 1000 + rur_t * 1000);
    int kop = investor->bank%100;
    printf("Bank account: %d,%.3d,%.3d rur %.2d kop \n", rur_m, rur_t, rur, kop);
    printf("Flat: %lld\n", investor->flat);
    printf("Capital: %lld\n", investor->cap);
}

void _bank_month_update(struct Investor* investor) //����� ����� �� ����� � ����� � ����� ������� ������
{
    int income = investor->bank * investor->dep_per / 12.;
    investor->bank += income;
    investor->bank += investor->m_save;
}

void _cap_rec(struct Investor* investor) //��������� ��������� �������� � ���������� ������
{
    investor->cap = investor->bank + investor->flat;
}

void _month_update(struct Investor* investor, struct Country* country) //����������� ��������� 
{
    _bank_month_update(investor);
}

void _flat_price_year_update(struct Investor* investor, struct Country* country) //���� �������� � ����� ������� ����
{
    int addon = investor->flat * country->infl;
    investor->flat += addon;
}

void _year_update(struct Investor* investor, struct Country* country) //��������� ���������
{
    _flat_price_year_update(investor,country);
}


int main(void)
{
    struct Country Russia; //����������� ������� ������
    struct Investor Alice; //����������� ������� �����
    _Alice(&Alice); //����� ������� ��� �������������� ������� �����
    _Russia(&Russia); //����� ������� ��� ������������� ������� ������
    for (int month = 1; month <= life; month++)
    {
        _month_update(&Alice, &Russia);
            if (month % 12 == 0)
            {
                _year_update(&Alice, &Russia);
            }
        _cap_rec(&Alice);
    }
    _output(&Alice);
    return 0;
}






