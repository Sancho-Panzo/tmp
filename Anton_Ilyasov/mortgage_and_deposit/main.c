#include <stdio.h>
int main(void)
{
	int m, i, ost;
	double sum, p = 50000., g, kv_price=10000000., perv_platezh=1000000., vsego, arenda=20000.;
	m = 240; //�������
	printf("god\tna balanse\n");
	for (sum = 1000000., i = 1; i <= m; i++) //� 1-�� ����� �� 240 �����
	{
		sum = sum + sum * 8. / 1200. + (p-arenda); //����� �� ������� � ����� ������� ������
		kv_price = kv_price * 1.00625; //����������� ���� ���� ��������
		arenda *= 1.00625; //����������� ���� �������� �����
		g = i / 12.;
		ost = i % 12; //������� �� ������� i �� 12
		if (ost == 0)
		{
			p*= 1.075; //���� �������� ��� � ���
			printf("%.0f\t%.2f\n", g, sum); //����� ����� � ����� ������� ����
		}
	}
	printf("kv_price: %.2f\n", kv_price);
	printf("\nCredit:\n");
	double k, kn, pl;
	kn = (1. + 14. / 1200.);
	for (k = kn, i = 2; i <= m; i++)
		k *= kn; //�����������
	pl = 9000000. * (14. / 1200. + (14. / 1200.) / (k - 1)); //����������� ������
	vsego = m * pl; //����� ��������
	printf("Ezhemesyachniy platezh: %.2f\tVsego: %.2f\n", pl,vsego);
	printf("pribil': %.2f\n", kv_price-vsego);

	return 0;
}
