#include <bits/stdc++.h>
using namespace std;
#define long long LL
#define short sh
int alegere;
class Nod
{
private:
    int top;
    Nod *next;

public:
    Nod()
    {
        top = 0;
        next = nullptr;
    }

    Nod(int inform)
    {
        top = inform;
        next = nullptr;
    }

    ~Nod()
    {
        next = nullptr;
    }

    int functieinform()
    {
        return top;
    }

    Nod* urmatorul()
    {
        return next;
    }

    void set_info(int top)
    {
        top = top;
    }

    void set_next(Nod* urm)
    {
        next = urm;
    }
};
class Lista_circulara
{
private:
    Nod *prim;
    int nr;
public:
    Lista_circulara()
    {
        prim = nullptr;
        nr = 0;
    }

    Lista_circulara(Nod *p, int n)
    {
        prim = p;
        nr = n;
    }

    Lista_circulara(const Lista_circulara &l)
    {
        nr = l.nr;
        prim = l.prim;
    }

    ~Lista_circulara()
    {
        Nod *p = prim, *q;
        while (nr)
        {
            q = p;
            p = p->urmatorul();
            delete q;
            nr--;
        }
        this-> prim = nullptr;
    }

    void set_prim(Nod *p)
    {
        prim = p;
    }

    void set_nr(int n)
    {
        nr = n;
    }

    Nod* get_prim() const
    {
        return prim;
    }

    int get_nr() const
    {
        return nr;
    }

    void add(int poz, Nod *element)
    {
        if (nr == 0)
        {
            prim = element;
            prim->set_next(prim);
            nr++;
        }
        else if (poz == 0)
        {
            Nod *i = prim;
            int j = 0;
            while (j != nr - 1)
            {
                j++;
                i = i->urmatorul();
            }
            i->set_next(element);
            element->set_next(prim);
            prim = element;
            nr++;
        }
        else
        {
            Nod *i = prim;
            int j = 0;
            while (j != poz - 1)
            {
                j++;
                i = i->urmatorul();
            }

            element->set_next(i->urmatorul());
            i->set_next(element);
            nr++;
        }
    }

    friend istream &operator>>(istream &dev, Lista_circulara &l)
    {
        cout << "nr elem: ";
        int numar;
        dev >> numar;

        for (int i = 0; i < numar; i++)
        {
            cout << "pozitie element " << i << ": ";
            int val;
            dev >> val;
            Nod *element = new Nod(val);
            l.add(i, element);
        }
        return dev;
    }

    void afisare_k(int k)
    {
        if (nr)
        {
            int i = 0;
            Nod *inc = prim;
            while (i != k)
            {
                i++;
                inc = inc->urmatorul();
            }

            i = nr + 1;
            cout << "lista: ";
            while (i != 0)
            {
                cout << inc->functieinform() << " ";
                inc = inc->urmatorul();
                i--;
            }
            cout << "\n";
        }
        else
            cout << "nu avem elemente!\n";
    }

    void deletef(int poz)
    {
        if (nr == 0)
        {
            cout << "lista goala nu putem sterge elemente!\n";
        }
        else if (nr == 1)
        {
            prim = nullptr;
            nr = 0;
        }
        else if (poz == 0)
        {
            Nod *i = prim;
            int j = 0;
            while (j != nr - 1)
            {
                i = i->urmatorul();
                j++;
            }
            i->set_next(prim->urmatorul());
            prim->set_next(nullptr);
            prim = i->urmatorul();
            nr--;
        }
        else
        {
            Nod *i = prim, *k;
            int j = 0;
            while (j != poz - 1)
            {
                i = i->urmatorul();
                j++;
            }
            k = i->urmatorul();
            i->set_next(k->urmatorul());
            k->set_next(nullptr);
            nr--;
        }
    }

    void stergere(int k)
    {
        if (nr)
        {
            int i = 0;
            Nod *inc = prim;
            while (i != k)
            {
                i++;
                inc = inc->urmatorul();
            }

            cout << "lista:";
            int val = inc->functieinform();
            while (nr != 0)
            {
                cout << inc->functieinform() << " ";
                inc = inc->urmatorul();
                if (i == nr - 1 && nr != 1)
                {
                    deletef(i);
                    i = 0;
                }
                else
                    deletef(i);
            }
            cout << val << "\n";
        }
        else
            cout << "lista nu are elemente!\n";
    }

    void inversare()
    {
        if (nr == 0)
        {
            cout << "lista nu are elemente!\n";
        }
        else
        {
            int i = nr;
            Nod *current = prim;
            Nod *prev = nullptr;
            Nod *next = nullptr;
            Nod *firstnode = nullptr;

            next = current->urmatorul();
            current->set_next(prev);
            prev = current;
            current = next;
            firstnode = prev;
            i--;

            while (i)
            {
                next = current->urmatorul();
                current->set_next(prev);
                prev = current;
                current = next;
                i--;
            }
            firstnode->set_next(prev);
            prim = prev;
        }
    }

    Lista_circulara operator+(const Lista_circulara &l2)
    {
        Nod *firstnode;
        Nod *p = prim;
        Nod *element_p = new Nod(prim->functieinform()), *q;
        firstnode = element_p;
        q = firstnode;
        p = p->urmatorul();

        for (int i = 1; i < nr; i++)
        {
            Nod *element = new Nod(p->functieinform());
            q->set_next(element);
            q = q->urmatorul();
            p = p->urmatorul();
        }

        p = l2.prim;
        for (int i = 0; i < l2.nr; i++)
        {
            Nod *element = new Nod(p->functieinform());
            q->set_next(element);
            q = q->urmatorul();
            p = p->urmatorul();
        }
        q->set_next(firstnode);
        return Lista_circulara(firstnode, nr + l2.nr);
    }
};
int main()
{
    Lista_circulara l1;
    cout << "citire:1\n afisare lista prin eliminare:2\n afisare lista:3\n adaugare element:4\n eliminare element:5\n inversare legaturi lista:6\n adunare 2 liste:7\n exit:8\n";
    while(alegere != 8)
    {
        cin>>alegere;
            if(alegere == 1)
            {
                cin >> l1;
                l1.afisare_k(0);
                break;
            }

            if(alegere == 2)
            {
                cout << "Pozitie stergere: ";
                int poz;
                cin >> poz;
                if(poz >= 0 && poz < l1.get_nr())
                    l1.stergere(poz);
                else
                    cout << "Pozitie gresita!\n";
                break;
            }

            if(alegere == 3)
            {
                l1.afisare_k(0);
                break;
            }

            if(alegere  == 4)
            {
                cout << "Element de adaugat: ";
                int val, poz;
                cin >> val;
                cout << "Pozitia: ";
                cin >> poz;
                if(poz >= 0 && poz < l1.get_nr())
                {
                    Nod *elem = new Nod(val);
                    l1.add(poz,elem);
                    l1.afisare_k(0);
                }
                else
                    cout << "Pozitie gresita!\n";
                break;
            }
            if(alegere == 5)
            {
                cout << "Pozitie element de sters: ";
                int poz;
                cin >> poz;
                if(poz >= 0 && poz < l1.get_nr())
                {
                    l1.deletef(poz);
                    l1.afisare_k(0);
                }
                else
                    cout << "Pozitie gresita!\n";
                break;
            }

            if(alegere  == 6)
            {
                l1.inversare();
                l1.afisare_k(0);
                break;
            }

            if(alegere  == 7)
            {
                if(l1.get_nr() == 0)
                    cout << "lista goala!\n";
                else
                {
                    cout << "Lista care trebuie adunata:\n";
                    Lista_circulara l2;
                    cin >> l2;
                    (l1 + l2).afisare_k(0);
                }
                break;
            }
        cout << "\n";
        cout <<  "citire:1\n afisare lista prin eliminare:2\n afisare lista:3\n adaugare element:4\n eliminare element:5\n inversare legaturi lista:6\n adunare 2 liste:7\n exit:8\n";
        cin >> alegere;
    }
}
