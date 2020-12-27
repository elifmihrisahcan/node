#include <iostream>
using namespace std;
class Node
{
public:
    // Veri
    int data;
    Node *next; // Listede sonraki Node
};
class Stack
{
    int count;  //Node sayisi
    Node *head; // ilk elemanin adresi
public:
    Stack()
    {
        count = 0;
        head = NULL; //henuz stack bos
    }
    void push(int value)
    {
        Node *n = new Node(); //veriyle yeni node olustur
        n->data = value;
        n->next = head; //listenin basina ekle
        head = n;       //node'u listenin basi yap
        count++;
    }
    int pop()
    {
        //ilk elemani kaydet
        int result = head->data;
        //listenin basini sonraki elemana esitle
        head = head->next;
        count--;
        return result;
    }
    void empty()
    {
        head = NULL; //listeyi bosalt
        count = 0;
    }
    void print()
    {
        if (count == 0)
        {
            cout << "stack bos\n";
            return;
        }
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data; //simdiki node'u yazdir
            if (current->next != NULL)
                cout << ", ";
            current = current->next; //sonraki node'a gec
        }
    }
    int size() { return count; }
};
class Queue
{
    int count;
    Node *head;
    Node *tail;

public:
    Queue()
    {
        count = 0;
        head = NULL;
        tail = NULL;
    }
    void push(int value)
    {
        Node *n = new Node(); //yepyeni bir node
        n->data = value;
        if (head == NULL)
        { //queue bos ise tek elemanli queue olustur
            head = n;
            tail = n;
            count = 1;
            return;
        }
        tail->next = n; //node'u sona ekle
        count++;        //node sayisini arttir
    }
    int pop()
    {
        // queue bos ise -1 don
        if (count == 0)
        {
            cout << "Queue bos\n";
            return -1;
        }
        int result = head->data; //veriyi kaydet
        head = head->next;       //headi ilerlet
        count--;                 //node sayisini azalt
        return result;
    }
    void empty()
    { //queue'yu bosalt
        head = NULL;
        tail = NULL;
        count = 0;
    }
    void print()
    {
        //pointer tut
        Node *current = head;
        //elemanlar bitene kadar
        while (current != NULL)
        {
            //veriyi yazdir
            cout << current->data;
            if (current->next != NULL)
                cout << ", ";
            //sonraki elemana gec
            current = current->next;
        }
    }
    int size() { return count; }
};

class List
{
    int count;
    Node *head;

public:
    List()
    {
        count = 0;
        head = NULL;
    }
    void push(int value, int index)
    {
        Node *pIzleyen = head, *pTakipEden = pIzleyen;
        Node *n = new Node();
        n->data = value;
        if (index == 0 && count == 0)
        {
            n->next = NULL;
            head = n;
            count++;
        }

        else if (index == 0 && count != 0)
        { //Listenin basi ama Liste bos degil.
            for (int adim = 1; adim <= (count - 1); adim++)
            {
                pIzleyen = pIzleyen->next;
            }
            n->next = NULL;
            pIzleyen->next = n;
            count++;
        }
        //Liste sonuna ekleme.
        else if (index == count)
        {
            n->next = pIzleyen;
            head = n;
            count++;
        }
        else
        {
            for (int adim = 1; adim <= ((count - 1) - index); adim++)
            {
                pIzleyen = pIzleyen->next;
            }
            n->next = pIzleyen->next;
            pIzleyen->next = n;
            count++;
        }
    }
    void pop(int index)
    {
        Node *pIzleyen = head;
        Node *pTakipEden = NULL;

        if (index == count - 1)
        {
            pIzleyen = pIzleyen->next;
            head = pIzleyen;
            count--;
        }
        //ilk elemani cikarma.
        else if (index == 0)
        {
            for (int adim = 1; adim <= count - 1; adim++)
            {
                pTakipEden = pIzleyen;
                pIzleyen = pIzleyen->next;
            }
            pTakipEden->next = NULL;
            count;
        }

        else
        {
            for (int adim = 1; adim <= (count - 1) - index; adim++)
            {
                pTakipEden = pIzleyen;
                pIzleyen = pIzleyen->next;
            }
            pIzleyen = pIzleyen->next;
            pTakipEden->next = pIzleyen;
            count--;
        }
    }
    void empty()
    {
        head = NULL;
        count = 0;
    }
    void print()
    {
        Node *current = head;
        int indexSayaci = count - 1;
        while (current != NULL)
        {
            cout << indexSayaci << ". >\t" << current->data << endl;
            current = current->next;
            indexSayaci--;
        }
    }
    int size() { return count; }
};

void yiginUygulamasi(bool &run2, Stack &yigin)
{
    cout << "*------------*Menu*---------------*" << endl;
    cout << "Stack Uygulamasi                 \n"
         << endl;
    cout << "Yapmak istediginiz islem: " << endl;
    cout << "1: eleman ekle\n";
    cout << "2: eleman cikar\n";
    cout << "3: temizle\n";
    cout << "4: elemanlari goster\n";
    cout << "5: eleman sayisini goster\n";
    cout << "6: ana menuye don\n";
    cout << "*----------------------------------*" << endl;

    int input;
    switch (input)
    {
    case 1:
        cout << "eklemek istediginiz elemani girin: ";
        int input2;
        cin >> input2;
        yigin.push(input2);
        cout << input2 << " Listeye eklendi.\n";
        break;
    case 2:
        if (yigin.size() > 0)
        {
            yigin.pop();
            cout << "son eklenen eleman Listeden cikarildi.\n";
        }
        else
        {
            cout << "yigin zaten bos, cikarma islemi yapilamaz" << endl;
        }
        break;
    case 3:
        yigin.empty();
        cout << "yigin temizlendi.\n";
        break;
    case 4:
        if (yigin.size() == 0)
        {
            cout << "Liste bos..!\n";
        }
        else
        {
            yigin.print();
            cout << "\nListede " << yigin.size() << " adet eleman mevcut\n";
        }
        break;
    case 5:
        cout << "Listede " << yigin.size() << " adet eleman mevcut\n";
        break;
    case 6:
        cout << "ana menuye donuyorum.\n";
        run2 = false;
        break;
    default:
        cout << "boyle bir komut yok, tekrar dene\n";
        break;
    }
}
void kuyrukUygulamasi(bool &run2, Queue &kuyruk)
{
    cout << "*------------*Menu*---------------*" << endl;
    cout << "Kuyruk Uygulamasi" << endl;
    cout << "1-> kuyruga eleman ekle\n";
    cout << "2-> kuyruktan eleman cikar\n";
    cout << "3-> kuyrugu temizle\n";
    cout << "4-> kuyruktaki elemanlari goster\n";
    cout << "5-> kuyruktaki eleman sayisini goster\n";
    cout << "6-> ana menuye don\n";
    cout << "yapmak istediginiz islem: ";
    cout << "*----------------------------------*" << endl;

    int input;
    cin >> input;

    switch (input)
    {
    case 1:
    {
        cout << "eklemek istediginiz elemani girin(tam sayi olmali): ";
        int input2;
        cin >> input2;
        kuyruk.push(input2);
        cout << input2 << " Listeye eklendi.\n";
        break;
    }
    case 2:
    {
        if (kuyruk.size() > 0)
        {
            kuyruk.pop();
            cout << "ilk eklenen eleman kuyruktan cikarildi.\n";
        }
        else
        {
            cout << "kuyruk bos oldugu icin cikarma islemi yapilamiyor\n";
        }
        break;
    }
    case 3:
        kuyruk.empty();
        cout << "kuyruk temizlendi.\n";
        break;
    case 4:
    {
        if (kuyruk.size() == 0)
        {
            cout << "Liste bos\n";
        }
        else
        {
            kuyruk.print();
            cout << "\nListede " << kuyruk.size() << " adet eleman bulunuyor.\n";
        }
        break;
    }
    case 5:
        cout << "Listede " << kuyruk.size() << " adet eleman bulunuyor.\n";
        break;
    case 6:
        run2 = false;
        break;
    default:
        cout << "hatali giris yaptiniz tekrar deneyin..!\n";
        break;
    }
}
void ListeUygulamasi(bool &run2, List &Liste)
{
    cout << "*--------------*Menu*---------------*" << endl;
    cout << " Liste Uygulamasi                  \n"
         << endl;
    cout << "yapmak istediginiz islem:          \n";
    cout << "1: Listeye eleman ekle             \n";
    cout << "2: Listeden eleman cikar           \n";
    cout << "3:Listeyi temizle                  \n";
    cout << "4-> Listedeki elemanlari goster    \n";
    cout << "5: Listedeki eleman sayisini goster\n";
    cout << "6: ana menuye don                  \n";
    cout << "*-----------------------------------*" << endl;
    int input;
    cin >> input;

    switch (input)
    {
    case 1:
    {
        bool disariRun = true;
        while (disariRun)
        {

            cout << "1: araya eleman ekle\n2: sona eleman ekle\n3: ana menuye don\nyapmak istediginiz islem: ";
            int input2;
            cin >> input2;
            if (input2 == 1)
            {
                while (true)
                {
                    Liste.print();
                    cout << "yeni elemani kacinci siraya eklemek istiyorsunuz?\nSectiginiz sirada baska bir eleman varsa o eleman bir sira yukariya kaydirilir.\n";
                    cout << "(hic eleman yoksa 0. indisten baslayabilirsiniz.)elemani eklemek istediginiz sira numarasi: ";
                    int input3;
                    cin >> input3;
                    if (0 <= input3 && input3 <= Liste.size())
                    {
                        cout << "sira numarasi: " << input3;
                        cout << "\nEklemek istediginiz data(tam sayi): ";
                        int input4;
                        cin >> input4;
                        Liste.push(input4, input3);
                        cout << input4 << " degeri, " << input3 << ". siraya eklendi.\n";
                        disariRun = false;
                        break; //iceri dongu kirildi;
                    }
                    else
                    {
                        cout << " 0 < sira numarasi < " << (Liste.size()) << " olmali..!\n";
                        break; //iceri dongu kirildi ama disari dongu kirilmadi..!
                    }
                }
            }
            else if (input2 == 2)
            {
                cout << "eklemek istediginiz datayi girin: ";
                int input3;
                cin >> input3;
                Liste.push(input3, Liste.size());
                cout << input3 << " Listenin sonuna eklendi.\n";
                break;
            }

            else if (input2 == 3)
            {
                disariRun = false;
                break;
            }

            else
            {
                cout << "hatali giris lutfen tekrar deneyin..!" << endl;
                continue;
            }
        }
        break;
    }
    case 2:
    {
        if (Liste.size() == 0)
        {
            cout << "Liste bos oldugu icin cikarma islemi yapilamiyor..!\n";
        }
        else
        {
            while (true)
            {
                Liste.print();
                cout << "\ncikarmak istediginiz elemanin sira numarasi: ";
                int input2;
                cin >> input2;
                if (0 <= input2 && input2 <= Liste.size())
                {
                    Liste.pop(input2);
                    cout << input2 << " Listeden cikarildi.\n";
                    break;
                }
                else
                {
                    cout << "hatali giris yaptiniz..!\n";
                    cout << "0 <= sira numarasi <= " << Liste.size() << " arasinda olmali..!\n";
                    continue;
                }
            }
        }
        break;
    }
    case 3:
        Liste.empty();
        cout << "Liste temizlendi.\n";
        break;
    case 4:
    {
        if (Liste.size() == 0)
        {
            cout << "Liste bos\n";
        }
        else
        {
            Liste.print();
            cout << "\nListede " << Liste.size() << " adet eleman bulunuyor.\n";
        }
        break;
    }
    case 5:
        cout << "Listede " << Liste.size() << " adet eleman bulunuyor.\n";
        break;
    case 6:
        run2 = false;
        break;
    default:
        cout << "hatali giris yaptiniz tekrar deneyin\n";
        break;
    }
}
int main()
{
    Stack yigin;
    Queue kuyruk;
    List Liste;

    bool run = true;
    while (run)
    {
        cout << "*--------------*Menu*----------------*" << endl;
        cout << "Seciminizi Girin:                  \n"
             << endl;
        cout << "1: Yigin Uygulamasi                \n";
        cout << "2: Kuyruk Uygulamasi               \n";
        cout << "3: Tek Yonlu Bagli Liste Uygulamasi\n";
        cout << "4: Cikis                           \n";
        cout << "*------------------------------------*" << endl;
        int input;
        cin >> input;
        bool run2 = true;
        switch (input)
        {
        case 1:
            while (run2)
                yiginUygulamasi(run2, yigin);
            break;
        case 2:
            while (run2)
                kuyrukUygulamasi(run2, kuyruk);
            break;
        case 3:
            while (run2)
                ListeUygulamasi(run2, Liste);
            break;
        case 4:
            run = false;
            break;
        default:
            cout << "hatali giris yaptiniz tekrar deneyin\n";
            break;
        }
    }
    return 0;
}