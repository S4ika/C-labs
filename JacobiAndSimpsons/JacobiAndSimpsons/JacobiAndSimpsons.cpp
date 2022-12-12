#include <omp.h>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
double f(double x)
{
    double f = (cos(x) * cos(x));
    return f;
}

double Simpson(int a, int b)
{
    double steps = 100.0;
    double Sresult, S1result1;
    double accurasy = 0.000001;
    double step = (b - a) / steps;
    Sresult = S1result1 = 0.0;
    for (int i = 1; i <= steps; ++i)
        Sresult += f(a + (i - 1) * step) + 4 * f(a + (i - 0.5) * step) + f(a + i * step);
    Sresult *= (step / 6);
    while (abs(Sresult - S1result1) > accurasy)
    {
        S1result1 = Sresult;
        step = step / 2.0;
        steps = (double)((b - a) / step);
        for (int i = 1; i <= steps; ++i)
            Sresult += f(a + (i - 1) * step) + 4 * f(a + (i - 0.5) * step) + f(a + i * step);
        Sresult *= (step / 6.0);
    }
    return Sresult;
}
void SimpsonParalell(int a, int b)
{
    double t = omp_get_wtime();
    double sum = 0;
#pragma omp parallel num_threads(8)
    {
        double kol = (b - a) / 8.0;
        double cur = omp_get_thread_num();
        sum += Simpson(kol * cur + a, kol * (cur + 1) + a);
    }
    cout << "Результат интегрирования:" << sum << "\nВремя для параллельного алгоритма Симпсона = " << omp_get_wtime() - t << endl;
}

int main()
{
    int a, b;
    setlocale(LC_ALL, "Russian");
    cout << "Введите границы интегрирования:\n";
    cin >> a >> b;
    double t = omp_get_wtime();
    double x = Simpson(a, b);
    cout << "Результат интегрирования:" << x << "\nВремя для алгоритма Симпсона = " << omp_get_wtime() - t << endl;
    SimpsonParalell(a, b);
    system("pause");
    return 0;
}