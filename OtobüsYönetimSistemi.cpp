#include <iostream>
#include <locale.h>
#include <cstdio>
#include <conio.h>
#include <string.h>
#include <cstdlib>
using namespace std;
static int p = 0;
class Bilgi
{
    char otobusNo[5], surucu[10], varis[5], ayrılıs[5], nereden[10], nereye[10], koltuk[8][4][10];
public:
    void monte();
    void tahsis();
    void bos();
    void goster();
    void kar();
    void pozisyon(int i);

}otobus[10];

void vline(char ch)
{
    for (int i = 80; i > 0; i--)
        cout << ch;
}

void Bilgi::monte()
{
    cout << "Otobüs no girin: ";
    cin >> otobus[p].otobusNo;
    cout << "\nSürücü ismi girin: ";
    cin >> otobus[p].surucu;
    cout << "\nVarış zamanı: ";
    cin >> otobus[p].varis;
    cout << "\nAyrılış: ";
    cin >> otobus[p].ayrılıs;
    cout << "\nAyrılılan yer: \t\t\t";
    cin >> otobus[p].nereden;
    cout << "\nVarılan yer: \t\t\t";
    cin >> otobus[p].nereye;
    otobus[p].bos();
    p++;
}

void Bilgi::tahsis()
{
    int koltuk;
    char sayi[5];
    top:
    cout << "Otobüs no: ";
    cin >> sayi;
    int n;
    for (n = 0; n <= p; n++)
    {
        if (strcmp(otobus[n].otobusNo, sayi) == 0)
            break;

    }
    while (n <= p)
    {
        cout << "\nKoltuk Sayısı: ";
        cin >> koltuk;
        if (koltuk > 32)
        {
            cout << "\nBu otobüste sadece 32 koltuk var.";
        }
        else
        {
            if (strcmp(otobus[n].koltuk[koltuk / 4][(koltuk % 4) - 1], "Boş") == 0)
            {
                cout << "Yolcu ismi girin: ";
                cin >> otobus[n].koltuk[koltuk / 4][(koltuk % 4) - 1];
                break;
            }
            else
                cout << "Koltuk zaten dolu.\n";
        }
    }
    if (n > p)
    {
        cout << "Doğru otobüs no girin.\n";
        goto top;
    }
}


void Bilgi::bos()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            strcpy_s(otobus[p].koltuk[i][j], "Boş");
        }
    }
}

void Bilgi::goster()
{
    int n;
    char sayi[5];
    cout << "Otobüs no girin: ";
    cin >> sayi;
    for (n = 0; n <= p; n++)
    {
        if (strcmp(otobus[n].otobusNo, sayi) == 0)
            break;
    }
    while (n <= p)
    {
        vline('*');
        cout << "Otobüs no: \t" << otobus[n].otobusNo << "\nSürücü: \t" << otobus[n].surucu << "\t\tVarış zamanı: \t" << otobus[n].varis << "\tAyrılış zamanı: " << otobus[n].ayrılıs << "\nAyrıldığı yer: \t\t" << otobus[n].nereden << "\t\tGidilen yer: \t\t" << otobus[n].nereye << "\n";
        vline('*');
        otobus[0].pozisyon(n);
        int a = 1;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                a++;
                if (strcmp(otobus[n].koltuk[i][j], "Boş") != 0)
                    cout << "\nKoltuk no " << (a - 1) << " şu yolcunun: " << otobus[n].koltuk[i][j] << ".";
            }
        }
        break;
    }
    if (n > p)
        cout << "Doğru otobüs no girin: ";
}

void Bilgi::pozisyon(int l)
{
    int s = 0, p = 0;
    for (int i = 0; i < 8; i++)
    {
        cout << "\n";
        for (int j = 0; j < 4; j++)
        {
            s++;
            if (strcmp(otobus[l].koltuk[i][j], "Boş") == 0)
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << otobus[l].koltuk[i][j];
                p++;
            }

            else
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << otobus[l].koltuk[i][j];
            }
        }
    }
    cout << "\n\nBoş koltuk sayısı " << p << " dır. Otobüs no: " << otobus[l].otobusNo;
}

void Bilgi::kar()
{
    for (int n = 0; n < p; n++)
    {
        vline('*');
        cout << "Otobüs no: \t" << otobus[n].otobusNo << "\nSürücü: \t" << otobus[n].surucu << "\t\tVarış zamanı: \t" << otobus[n].varis << "\tAyrılış zamanı: " << otobus[n].ayrılıs << "\nAyrıldığı yer: \t\t" << otobus[n].nereden << "\t\tGidilen yer: \t\t\t" << otobus[n].nereye << "\n";
        vline('*');
        vline('_');
    }
}


int main()
{
    setlocale(LC_ALL, "Turkish");
    system("cls");
    int w;
    while (1)
    {
        cout << "\n\n\n\n\n";
        cout << "\t\t\t1.Monte\n\t\t\t" << "2.Rezervasyon\n\t\t\t" << "3.Göster\n\t\t\t" << "4.Ulaşılabilen otobüsler.\n\t\t\t" << "5.Çıkış";
        cout << "\n\t\t\tSeçim girin: ";
        cin >> w;
        switch (w)
        {
        case 1: otobus[p].monte();
            break;
        case 2:
            otobus[p].tahsis();
            break;
        case 3:
            otobus[0].goster();
            break;
        case 4:
            otobus[0].kar();
            break;
        case 5:
            exit(0);
        default:
            break;
        }
    }
    return 0;
}

