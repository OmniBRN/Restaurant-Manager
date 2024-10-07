#include <iostream>
#include <chrono>
#include <thread>
#include <string>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

//supraincarcare de functie
int add(int i){return i;}
int add(int i, int j) {return i+j;}

//clasa abstract
class base
{
private:
    int numarAscuns = 12;
public:
    void setNumar(int n){numarAscuns=12;}
    virtual int getNumar() const = 0;
};

//Singleton
class Singleton
{
private:
    Singleton(){};
    static Singleton* instancePtr;
    int numar;
public:
    Singleton(const Singleton&) = delete;
    static Singleton* getInstance()
    {
        if(instancePtr==nullptr)
        {
            instancePtr = new Singleton();
        }
        return instancePtr;
    }
    void setValue(int n){numar = n;}
    void print(){cout << numar << '\n';}
};

Singleton* Singleton::instancePtr = nullptr;

void wait()
{
    sleep_for(seconds(2));
    return;
}

void clear()
{
    cout << "\033c";
    return;
}


class produs // clasa abstracta
{

public:
    produs(string s="gol", int p=0)
    :nume{s} 
    ,pret{new int(p)}{}
    produs(const produs& p)
    : nume{p.nume}
    , pret{new int(p.price())} {}
    

    ~produs() = default;
    string name() const{return nume;}
    int price() const{return *pret;}
    virtual void print()
    {
        cout << name() << ": " << price() << " lei\n";
    }
    friend ostream& operator<<(ostream& out, const produs& p);
    
private:
    string nume;
    int* pret;
};

ostream& operator<<(ostream& out, const produs& p)
{
    out << p.name() << ": " << p.price() << '\n';
    return out;
}
class ciorba : public produs
{
public:
    ciorba(int p=0, string nume="Ciorba")
    : produs{nume, p} {}
    
    ciorba(const ciorba& c)
    : produs{c} {}



};

class ciorbaBurta : public ciorba
{
public:
    ciorbaBurta(int p=0, bool hasSour=0, bool hasPepper=0)
    : ciorba{p, "Ciorba de Burta"}
    , areSmantana{hasSour}
    , areArdei{hasPepper} {}

    ciorbaBurta(const ciorbaBurta& cB)
    : ciorba{cB}
    , areSmantana{cB.areSmantana}
    , areArdei{cB.areArdei} {}

    void print() override
    {
        cout << name() << ": " << price() << " lei\n";
        cout << "Are smantana: " << areSmantana << "\n";
        cout << "Are ardei: " << areArdei << "\n";
    }

    friend ostream& operator<< (ostream& out, const ciorbaBurta& cB);
private:
    bool areSmantana=0;
    bool areArdei=0;

    

};

ostream& operator<<(ostream& out, const ciorbaBurta& cB)
{
    out << cB.name() << ": " << cB.price() << " lei\n";
    out << "Has Sour Cream:";
    if(cB.areSmantana) out << " Yes\n";
    else out << " No\n";
    out << "Has Pepper:";
    if(cB.areArdei) out << " Yes\n";
    else out << " No\n";
    return out;
}

class ciorbaDeLegume : public ciorba
{
public:
    ciorbaDeLegume(int p=0, bool hasSour=0, bool hasPepper=0)
    : ciorba{p, "Ciorba de Legume"}
    , areSmantana{hasSour}
    , areArdei{hasPepper} {}

    ciorbaDeLegume(const ciorbaDeLegume& cDL)
    : ciorba{cDL}
    , areSmantana{cDL.areSmantana}
    , areArdei{cDL.areArdei} {}

    friend ostream& operator<< (ostream& out, const ciorbaDeLegume& cDL);

    void print() override
    {
        cout << name() << ": " << price() << " lei\n";
        cout << "Are smantana:" << areSmantana << "\n";
        cout << "Are ardei:" << areArdei << "\n";
    }

private:
    bool areSmantana;
    bool areArdei;
};

ostream& operator<<(ostream& out, const ciorbaDeLegume& cDL)
{
    out << cDL.name() << ": " << cDL.price() << " lei\n";
    out << "Has Sour Cream:";
    if(cDL.areSmantana) out << " Yes\n";
    else out << " No\n";
    out << "Has Pepper:";
    if(cDL.areArdei) out << " Yes\n";
    else out << " No\n";
    return out;
}

class ciorbaDeCiuperci : public ciorba
{
public:
    ciorbaDeCiuperci(int p=0, bool hasSour=0, bool hasPepper=0)
    : ciorba{p, "Ciorba de Ciuperci"} {}


    ciorbaDeCiuperci(const ciorbaDeCiuperci& cDC)
    : ciorba{cDC} {}

    friend ostream& operator<<(ostream& out, const ciorbaDeCiuperci& cDC);

};

ostream& operator<<(ostream& out, const ciorbaDeCiuperci& cDC)
{
    out << cDC.name() << ": " << cDC.price() << " lei\n";
    return out;
}



class pui : public produs
{
public:
    pui(int p=0, string nume="Pui")
    : produs{nume, p}{}

    pui(const pui& p)
    : produs{p}{}

    friend ostream& operator<< (ostream& out, const pui& p);
        
};



class puiFrigarui: public pui
{
public:
    puiFrigarui(int p=0, string nume="Frigarui de Pui")
    : pui{p, nume} {}

    puiFrigarui(const puiFrigarui& pF)
    : pui{pF} {}

    
};

class puiTocana: public pui
{
public:
    puiTocana(int p=0, string nume="Tocana de Pui")
    : pui{p, nume} {}

    puiTocana(const puiTocana& pT)
    : pui{pT} {}
    
};

ostream& operator<< (ostream& out, const pui& p)
{
    out << p.name() << ": " << p.price() << " lei\n";
    return out;
}

class vita: public produs
{
public:
    vita(int p=0, string nume="Vita")
    : produs{nume, p} {}

    vita(const vita& v)
    : produs{v} {}

    friend ostream& operator<<(ostream& out, vita& v);
};

ostream& operator<<(ostream& out, const vita& v)
{
    out << v.name() << ": " << v.price() << " lei\n";
    return out;
}

class chateaubriand : public vita
{
public:
    chateaubriand(int p=0, string rarity="Medium-Rare")
    : vita{p, "Chateaubriand"}
    , raritate {rarity} {}
    chateaubriand(const chateaubriand& c)
    : vita{c}
    , raritate{c.raritate} {}

    friend ostream& operator<<(ostream& out, const chateaubriand& c);

    void print() override
    {
        cout << name() << ": " << price() << " lei\n";
        cout << "Raritate " << raritate << "\n";
    }

private:
    string raritate;

};

ostream& operator<<(ostream& out, const chateaubriand& c)
{
    out << c.name() << ": " << c.price() << "\nHow Well to Cook: "<< c.raritate << '\n';
    return out;
}

class stroganoff : public vita
{
public:
    stroganoff(int p=0)
    : vita(p, "Vita Stroganoff") {}
    stroganoff(const stroganoff& s)
    : vita(s) {}
};

class file : public vita
{
public:
    file(int p=0)
    : vita(p, "Vita File") {}
    file(const file& f)
    : vita(f){}   
};

class cartofi : public produs 
{
public:
    cartofi(int p=0, string nume="cartofi")
    : produs(nume, p) {}

    cartofi(const cartofi& c)
    : produs{c} {}



    friend ostream& operator<<(ostream& out, const cartofi& c);

};

ostream& operator<<(ostream& out, const cartofi& c)
{
    out << c.name() << ": "<< c.price() << '\n';
    return out;
}


class cartofiPrajiti : public cartofi
{
public:
    cartofiPrajiti(int p=0)
    : cartofi(p, "Cartofi Prajiti") {}
    cartofiPrajiti(const cartofiPrajiti& cP)
    : cartofi(cP) {}

};

class cartofiPiure : public cartofi
{
public:
    cartofiPiure(int p=0)
    : cartofi(p, "Piure de Cartofi") {}

    cartofiPiure(const cartofiPiure& cPi)
    : cartofi(cPi){}

    cartofiPiure(const cartofiPrajiti& cP)
    : cartofi(cP) {}
};

class orez : public produs
{
public:
    orez(int pret=0, string nume="orez")
    : produs(nume, pret){}
    
    orez(const orez& o)
    : produs(o){}

    friend ostream& operator<<(ostream& out, const orez& o);
};

ostream& operator<<(ostream& out, const orez& o)
{
    out << o.name() << ": " << o.price() << " lei\n";
    return out;
}

class orezSarbesc : public orez
{
public:
    orezSarbesc(int p=0)
    : orez(p, "Orez Sarbesc"){}
    orezSarbesc(const orezSarbesc& oS)
    : orez(oS) {}
};

class inghetata : public produs
{
public:
    inghetata(int pricePerCup, int nrCups)
    : produs{"Inghetata", pricePerCup*nrCups}
    , nrCupe{nrCups}
    , pretCupa{pricePerCup} {}
    inghetata(const inghetata& i)
    : produs{i}
    , nrCupe{i.nrCupe}
    , pretCupa{i.pretCupa} {}

    friend ostream& operator<<(ostream& out, const inghetata& i);

    void print() override
    {
        cout << name() << ": " << nrCupe << "cupe * "<< pretCupa << " lei =" <<price() << " lei\n";
    }

private:
    int nrCupe;
    int pretCupa;
};

ostream& operator<<(ostream& out, const inghetata& i)
{
    out << i.name() << ": "<< i.price() << " lei = " << i.nrCupe << " cupe * " << i.pretCupa << " lei\n";
    return out;
}

class tortKrantz: public produs
{
public:
    tortKrantz(int pret)
    : produs{"Tort Krantz", pret} {}
    tortKrantz(const tortKrantz& tK)
    : produs{tK}{}

    friend ostream& operator<<(ostream& out, const tortKrantz& tK);

};

ostream& operator<<(ostream& out, const tortKrantz& tK)
{
    out << tK.name() << ": " << tK.price() << " lei\n";
    return out;
}

class vin : public produs
{
public:
    vin(int p=0, string nume="Vin")
    : produs{nume, p} {}
    vin(const vin& v)
    : produs{v} {}

};

class vinVarsat : public vin
{
public:
    vinVarsat(int p=0, string color="rosu")
    : vin{p, "Vin Varsat"}
    , culoare{color}{}
    vinVarsat(const vinVarsat& vV)
    : vin{vV}
    , culoare{vV.culoare}{}

    friend ostream& operator<<(ostream& out, const vinVarsat& vV);

    void print() override
    {
        cout << name() << ": " << price() << " lei\n";
        cout << "Culoare " << culoare << "\n";
    }


private:
    string culoare;
};

ostream& operator<<(ostream& out, const vinVarsat& vV)
{
    out << vV.name() << ' '<< vV.culoare << ": " << vV.price() << " lei\n"; 
    return out;
}

class bordeaux : public vin
{
public:
    bordeaux(int p=0, int year=1996)
    : vin(p, "Vin Bordeaux")
    , an{year} {}

    bordeaux(const bordeaux& b)
    : vin(b)
    , an{b.an} {}

    friend ostream& operator<<(ostream& out, const bordeaux& b);

    void print() override
    {
        cout << name() << ": " << price() << " lei\n";
        cout << "An " << an << "\n";
    }

private:
    int an;
};

ostream& operator<<(ostream& out, const bordeaux& b)
{
    out << b.name() << ' ' << b.an << ": " << b.price() << " lei\n";
    return out;
}

class castelBolovanu : public vin
{
public:
    castelBolovanu(int p=0, int year=2004)
    : vin(p, "Vin Castel Bolovanu")
    , an{year} {}

    castelBolovanu(const castelBolovanu& cB)
    : vin(cB)
    , an{cB.an} {}

    friend ostream& operator<<(ostream& out, const castelBolovanu& cB);

    void print() override
    {
        cout << name() << ": " << price() << " lei\n";
        cout << "an " << an << "\n";
    }


private:
    int an;
};

ostream& operator<<(ostream& out, const castelBolovanu& cB)
{
    out << cB.name() << " " << cB.an << ": " << cB.price() << " lei\n";
    return out;
}

class bere : public produs
{
public:
    bere(int p=0, bool hasAlcohol=1)
    : produs("Bere", p) 
    , areAlcool{hasAlcohol} {}

    bere(const bere& b)
    : produs(b)
    , areAlcool{b.areAlcool} {}

    friend ostream& operator<<(ostream& out, const bere& b);

    void print() override
    {
        cout << name() << ": " << price() << " lei\n";
        cout << "Are Alcool: " << areAlcool << "\n";
    }


private:
    bool areAlcool;
};



ostream& operator<<(ostream& out, const bere& b)
{
    out << b.name();
    if(!b.areAlcool) out << " Fara alcool ";
    out << ": "<< b.price() << " lei\n"; 
    return out;
}

class apa: public produs
{
public:
    apa(int p=0)
    : produs("Apa Plata", p){}
    apa(const apa& a)
    : produs(a){}

    friend ostream& operator<<(ostream& out, const apa& a);
};

ostream& operator<<(ostream& out, const apa& a)
{
    out << a.name() << ": " << a.price() << "\n";
    return out;
}


ciorbaBurta makeCiorbaBurta(int pret, bool areSmantana, bool areArdei)
{
    ciorbaBurta temp{pret, areSmantana, areArdei};
    return temp;
}

ciorbaDeLegume makeCiorbaDeLegume(int pret, bool areSmantana, bool areArdei)
{
    ciorbaDeLegume temp{pret, areSmantana, areArdei};
    return temp;
}

ciorbaDeCiuperci makeCiorbaDeCiuperci(int pret)
{
    ciorbaDeCiuperci temp{pret};
    return temp;
}

puiFrigarui makePuiFrigarui(int pret)
{
    puiFrigarui temp{pret};
    return temp;
}

puiTocana makePuiTocana(int pret)
{
    puiTocana temp{pret};
    return temp;
}

chateaubriand makeChateaubriand(int pret, string raritate)
{
    chateaubriand temp{pret, raritate};
    return temp;
}

stroganoff makeStroganoff(int pret)
{
    stroganoff temp{pret};
    return temp;
}

file makeFile(int pret)
{
    file temp{pret};
    return temp;
}

cartofiPrajiti makeCartofiPrajiti(int pret)
{
    cartofiPrajiti temp{pret};
    return temp;
}

cartofiPiure makeCartofiPiure(int pret)
{
    cartofiPiure temp{pret};
    return temp;
}

orezSarbesc makeOrezSarbesc(int pret)
{
    orezSarbesc temp{pret};
    return temp;
}

inghetata makeInghetata(int pretCupa, int nrCupe)
{
    inghetata temp{pretCupa, nrCupe};
    return temp;
}

tortKrantz makeTortKrantz(int pret)
{
    tortKrantz temp{pret};
    return temp;
}

vinVarsat makeVinVarsat(int pret, string culoare)
{
    vinVarsat temp{pret, culoare};
    return temp;
}

bordeaux makeBordeaux(int pret, int an)
{
    bordeaux temp{pret, an};
    return temp;
}

castelBolovanu makeCastelBolovanu(int pret, int an)
{
    castelBolovanu temp{pret, an};
    return temp;
}

bere makeBere(int pret, bool areAlcool)
{
    bere temp{pret, areAlcool};
    return temp;
}

apa makeApa(int pret)
{
    apa temp{pret};
    return temp;
}

class customer
{
public:
    customer()
    {
        comanda = new produs*[20];
    }
    ~customer()
    {
        for(int i=0; i<nrComenzi; i++)
            if(comanda[i]!=nullptr) delete comanda[i];
        if(comanda) delete comanda;
    }

    //TREBUIE SA FAC O FUNCTIE PENTRU FIECARE TIP DE DATE FIINDCA TREBUIE SA ALOCE SPATIU SUFICIENT PENTRU CLASA DERIVATA :)


    void comandaNoua(ciorbaBurta cB, int index)
    {
        comanda[nrComenzi] = new ciorbaBurta{cB};
        indexComanda[nrComenzi] = index;
        nrComenzi++;
    }

    void comandaNoua(ciorbaDeLegume cL, int index)
    {
        comanda[nrComenzi] = new ciorbaDeLegume{cL};
        indexComanda[nrComenzi] = index;
        nrComenzi++;
    }

    void comandaNoua(ciorbaDeCiuperci cP, int index)
    {
        comanda[nrComenzi] = new ciorbaDeCiuperci{cP};
        indexComanda[nrComenzi] = index;
        nrComenzi++;
    }

    void comandaNoua(puiFrigarui pF, int index)
    {
        comanda[nrComenzi] = new puiFrigarui{pF};
        indexComanda[nrComenzi] = index;
        nrComenzi++;
    }

    void comandaNoua(puiTocana pT, int index)
    {
        comanda[nrComenzi] = new puiTocana{pT};
        indexComanda[nrComenzi] = index;
        nrComenzi++;
    }

    void comandaNoua(chateaubriand c, int index)
    {
        comanda[nrComenzi] = new chateaubriand{c};
        indexComanda[nrComenzi] = index;
        nrComenzi++;
    }

    void comandaNoua(stroganoff s, int index)
    {
        comanda[nrComenzi] = new stroganoff{s};
        indexComanda[nrComenzi] = index;
        nrComenzi++;
    }

    void comandaNoua(file f, int index)
    {
        comanda[nrComenzi] = new file{f};
        indexComanda[nrComenzi] = index;
        nrComenzi++;
    }

    void comandaNoua(cartofiPrajiti cP, int index)
    {
        comanda[nrComenzi] = new cartofiPrajiti{cP};
        indexComanda[nrComenzi] = index;
        nrComenzi++;
    }

    void comandaNoua(cartofiPiure cP, int index)
    {
        comanda[nrComenzi] = new cartofiPiure{cP};
        indexComanda[nrComenzi] = index;
        nrComenzi++;
    }

    void comandaNoua(orezSarbesc o, int index)
    {
        comanda[nrComenzi] = new orezSarbesc{o};
        indexComanda[nrComenzi] = index;
        nrComenzi++;
    }

    void comandaNoua(inghetata i, int index)
    {
        comanda[nrComenzi] = new inghetata{i};
        indexComanda[nrComenzi] = index;
        nrComenzi++;
    }

    void comandaNoua(tortKrantz tK, int index)
    {
        comanda[nrComenzi] = new tortKrantz{tK};
        indexComanda[nrComenzi] = index;
        nrComenzi++;
    }

    void comandaNoua(vinVarsat vV, int index)
    {
        comanda[nrComenzi] = new vinVarsat{vV};
        indexComanda[nrComenzi] = index;
        nrComenzi++;
    }

    void comandaNoua(bordeaux b, int index)
    {
        comanda[nrComenzi] = new bordeaux{b};
        indexComanda[nrComenzi] = index;
        nrComenzi++;
    }

    void comandaNoua(castelBolovanu cB, int index)
    {
        comanda[nrComenzi] = new castelBolovanu{cB};
        indexComanda[nrComenzi] = index;
        nrComenzi++;
    }

    void comandaNoua(bere b, int index)
    {
        comanda[nrComenzi] = new bere{b};
        indexComanda[nrComenzi] = index;
        nrComenzi++;
    }

    void comandaNoua(apa a, int index)
    {
        comanda[nrComenzi] = new apa{a};
        indexComanda[nrComenzi] = index;
        nrComenzi++;
    }

    void printOrder()
    {
        for(int i=0; i<nrComenzi; i++)
        {
            if(indexComanda[i] == 1)
            {
                ciorbaBurta* cB= dynamic_cast<ciorbaBurta*>(comanda[i]);
                cout << *cB;
            }
            else if(indexComanda[i] == 2)
            {
                ciorbaDeLegume* cLE = dynamic_cast<ciorbaDeLegume*>(comanda[i]);
                cout << *cLE;
            }
            else if(indexComanda[i] == 6)
            {
                chateaubriand* c = dynamic_cast<chateaubriand*>(comanda[i]);
                cout << *c;
            }
            else if(indexComanda[i] == 12)
            {
                inghetata* in = dynamic_cast<inghetata*>(comanda[i]);
                in->print();
            }
            else if(indexComanda[i] == 14)
            {
                vinVarsat* vV = dynamic_cast<vinVarsat*>(comanda[i]);
                vV->print();
            }
            else if(indexComanda[i] == 15)
            {
                bordeaux* b = dynamic_cast<bordeaux*>(comanda[i]);
                b->print();
            }
            else if(indexComanda[i] == 16)
            {
                castelBolovanu* cB = dynamic_cast<castelBolovanu*>(comanda[i]);
                cB->print();
            }
            else if(indexComanda[i] == 17)
            {
                bere* b = dynamic_cast<bere*>(comanda[i]);
                b->print();
            }

            else cout << *comanda[i]; 
        }
    }

    friend void operator+(customer &c, int money);
    int getBonPersonal(){return bonPersonal;}
    int getComandatFP(){return aComandatFP;}
    void comandatFP(){aComandatFP = 1;}
    void pay(){bonPersonal = 0;}

    private:
    int bonPersonal = 0;
    int nrComenzi = 0;
    int aComandatFP = 0;
    int indexComanda[20]{};
    produs** comanda;
};

void operator+(customer& c, int money){c.bonPersonal += money;}

class table
{
public:
    table(int nrS=0)
    : nrScaune{nrS}
    , client{new customer[nrS]}
    {}
    ~table()
    {
        delete[] client;
    }
    friend istream& operator>>(istream& in, table& masa);
    friend ostream& operator<<(ostream& out, const table& masa);

    int getNrScaune() const{return nrScaune;}
    int getNrPersoane() const{return nrPersoane;}
    int isFree() const{return !ocupat;}
    int getBon() const{return bon;}
    int getBon(int i) const{return client[i].getBonPersonal();}
    int getComandatFP(int i)const {return client[i].getComandatFP();}

    void setNrPersoane(int nr) {nrPersoane = nr;}
    void occupy() {ocupat = 1;}
    void free() {ocupat = 0;}
    void addToBon(int nr){bon+=nr;}
    void removeFromBon(int nr){bon-=nr;}
    void addToReceipt(int i, int pret)
    {
        client[i] + pret;
        addToBon(pret);
    }
    
    void pay(int i)
    {
        removeFromBon(client[i].getBonPersonal());
        client[i].pay();
    }
    void comandatFP(int i){client[i].comandatFP();}
    void printOrder(int i){client[i].printOrder();}


    void comandaNoua(int persoanaAleasa, ciorbaBurta cB, int index)
    {client[persoanaAleasa].comandaNoua(cB, index);}

    void comandaNoua(int persoanaAleasa, ciorbaDeCiuperci cDC, int index)
    {client[persoanaAleasa].comandaNoua(cDC, index);}    

    void comandaNoua(int persoanaAleasa, ciorbaDeLegume cDL, int index)
    {client[persoanaAleasa].comandaNoua(cDL, index);} 

    void comandaNoua(int persoanaAleasa, puiFrigarui pF, int index)
    {client[persoanaAleasa].comandaNoua(pF, index);}

    void comandaNoua(int persoanaAleasa, puiTocana pT, int index)
    {client[persoanaAleasa].comandaNoua(pT, index);}

    void comandaNoua(int persoanaAleasa, chateaubriand c, int index)
    {client[persoanaAleasa].comandaNoua(c, index);}

    void comandaNoua(int persoanaAleasa, stroganoff s, int index)
    {client[persoanaAleasa].comandaNoua(s, index);}

    void comandaNoua(int persoanaAleasa, file f, int index)
    {client[persoanaAleasa].comandaNoua(f, index);}

    void comandaNoua(int persoanaAleasa, cartofiPrajiti cP, int index)
    {client[persoanaAleasa].comandaNoua(cP, index);}

    void comandaNoua(int persoanaAleasa, cartofiPiure cP, int index)
    {client[persoanaAleasa].comandaNoua(cP, index);}

    void comandaNoua(int persoanaAleasa, orezSarbesc oS, int index)
    {client[persoanaAleasa].comandaNoua(oS, index);}

    void comandaNoua(int persoanaAleasa, inghetata i, int index)
    {client[persoanaAleasa].comandaNoua(i, index);}

    void comandaNoua(int persoanaAleasa, tortKrantz tK, int index)
    {client[persoanaAleasa].comandaNoua(tK, index);}

    void comandaNoua(int persoanaAleasa, vinVarsat vV, int index)
    {client[persoanaAleasa].comandaNoua(vV, index);}

    void comandaNoua(int persoanaAleasa, bordeaux b, int index)
    {client[persoanaAleasa].comandaNoua(b, index);}

    void comandaNoua(int persoanaAleasa, castelBolovanu cBo, int index)
    {client[persoanaAleasa].comandaNoua(cBo, index);}

    void comandaNoua(int persoanaAleasa, bere b, int index)
    {client[persoanaAleasa].comandaNoua(b, index);}

    void comandaNoua(int persoanaAleasa, apa a, int index)
    {client[persoanaAleasa].comandaNoua(a, index);}

private:
    int nrScaune;
    int nrPersoane;
    int bon=0;
    bool ocupat=0;
    customer* client;
};

// >> masa
istream& operator>>(istream& in, table& masa)
{
    in >> masa.nrScaune;
    delete[] masa.client;
    masa.client = new customer[masa.nrScaune];
    return in;
}
// << masa
ostream& operator<<(ostream& out, const table& masa)
{
    out << "Numar Scaune: " << masa.nrScaune << "\nBon:" << masa.bon << "\nOcupat:" << masa.ocupat << '\n';
    return out;
}


void newGroupMenu(int& stop, table *mese, int nrMese)
{
    clear();
    int nrPersoane, k=0, alegere;
    int* mesePosibile = new int[nrMese];
    cout << "A Table For How Many People?\n";
    cin >> nrPersoane;
    for(int i=0; i<nrMese; i++)
    {
        if(mese[i].getNrScaune() >= nrPersoane && mese[i].isFree())
        {
            mesePosibile[k] = i;
            k++;
        } 
        
    }
    if(k==0)
    {
        cout << "There Are No Free Tables OR There Are Not Enough Seats For This Group\n";
        stop = 1;
        wait();
        clear();
        delete[] mesePosibile;
        return;
    }
    do
    {
        cout << "Choose a Table:\n"; 
        for(int i=0; i<k; i++)
        {
            cout << "[" << i+1 << "] Masa " << mesePosibile[i] + 1  <<": " << mese[i].getNrScaune()<< " locuri\n"; 
        }
        cout << "[0] Exit\n";
        cin >> alegere;
        if(alegere == 0) 
        {
            delete[] mesePosibile;
            stop = 1;
            clear();
            return;
        }
        if(alegere < 0 || alegere > k) cout << "Not a valid table number\n";
    }
    while(alegere < 0 || alegere > k);
    
    cout << "Group Has Been Seated At Table " << mesePosibile[alegere-1] + 1 << '\n';
    mese[mesePosibile[alegere-1]].setNrPersoane(nrPersoane);
    mese[mesePosibile[alegere-1]].occupy();
    wait();
    clear();
    delete[] mesePosibile;
    stop = 1;
    
}

void newOrderMenu(int &opreste, table *mese, int masaAleasa)
{
    int alegere, persoanaAleasa;
    clear();
    do
    {
        for(int i=0; i<mese[masaAleasa].getNrPersoane(); i++)
            cout << "[" << i+1 << "] Persoana " << i+1 << " : " << mese[masaAleasa].getBon(i) <<  " lei \n";
        cout << "[0] Back\n";
        cin >> persoanaAleasa;
        if(!persoanaAleasa)
        {
            opreste = 1;
            clear();
            return;
        }
        if(persoanaAleasa<0||persoanaAleasa>mese[masaAleasa].getNrPersoane())
            cout << "Choose a valid number\n";
    }while(persoanaAleasa<0||persoanaAleasa>mese[masaAleasa].getNrPersoane());
    persoanaAleasa--;
    clear();
    do
    {
        cout << "[1] Felul Initial\n";
        cout << "[2] Felul Principal\n";
        cout << "[3] Garnitura\n";
        cout << "[4] Desert\n";
        cout << "[5] Bautura\n";
        cout << "[0] Inapoi\n";
        cin >> alegere;
        if(!alegere) return;
        if(alegere<0||alegere>6) cout << "Choose a valid number\n";
    }while(alegere<0||alegere>6);

    int mancareaAleasa;
    switch(alegere)
    {
        case 1: 
        {
            cout << "[1] Ciorba de Burta: 20 Lei\n";
            cout << "[2] Ciorba de Legume: 21 Lei\n";
            cout << "[3] Ciorba de Ciuperci: 23 Lei\n";
            cout << "[0] Back\n";
            cin >> mancareaAleasa;
            if(!mancareaAleasa) break;
            switch(mancareaAleasa)
            {
                case 1:
                {
                    int sC=0, p=0;
                    char sourCream, pepper;
                    cout << "Do you want Sour Cream?(y/n)\n";
                    cin >> sourCream;
                    cout << "Do you want Pepper?(y/n)\n";
                    cin >> pepper;
                    if(sourCream='y') sC = 1;
                    if(p='y') p = 1;
                    mese[masaAleasa].comandaNoua(persoanaAleasa, makeCiorbaBurta(20, sC, p), 1);
                    mese[masaAleasa].addToReceipt(persoanaAleasa, 20);
                    break;
                }

                case 2:
                {
                    int sC=0, p=0;
                    char sourCream, pepper;
                    cout << "Do you want Sour Cream?(y/n)\n";
                    cin >> sourCream;
                    cout << "Do you want Pepper?(y/n)\n";
                    cin >> pepper;
                    if(sourCream='y') sC = 1;
                    if(p='y') p = 1;
                    mese[masaAleasa].comandaNoua(persoanaAleasa, makeCiorbaDeLegume(21, sC, p), 2); 
                    mese[masaAleasa].addToReceipt(persoanaAleasa, 21);
                    break;
                }

                case 3:
                {
                    mese[masaAleasa].comandaNoua(persoanaAleasa, makeCiorbaDeCiuperci(23), 3);
                    mese[masaAleasa].addToReceipt(persoanaAleasa, 23);
                    break;
                }
            }
            break;
        }

        case 2:
        {
            cout << "Please gaseste preturi bune\n";
            cout << "[1] Frigarui de Pui: nu stiu(12) Lei\n";
            cout << "[2] Tocana de Pui: nu stiu(12) Lei\n";
            cout << "[3] Chateaubriand: nu stiu(12) Lei\n";
            cout << "[4] Stroganoff: nu stiu(12) Lei\n";
            cout << "[5] File\n";
            cout << "[0] Back\n";
            cin >> mancareaAleasa;
            if(!mancareaAleasa) break;
            switch(mancareaAleasa)
            {
                case 1:
                {   
                    mese[masaAleasa].comandaNoua(persoanaAleasa, makePuiFrigarui(12), 4);
                    mese[masaAleasa].addToReceipt(persoanaAleasa, 12);
                    mese[masaAleasa].comandatFP(persoanaAleasa);
                    break;
                }
                case 2:
                {
                    mese[masaAleasa].comandaNoua(persoanaAleasa, makePuiTocana(12), 5);
                    mese[masaAleasa].addToReceipt(persoanaAleasa, 12);
                    mese[masaAleasa].comandatFP(persoanaAleasa);
                    break;
                }
                case 3:
                {
                    int alegereRaritate;
                    cout << "[1] Rare\n";
                    cout << "[2] Medium Rare\n";
                    cout << "[3] Medium\n";
                    cout << "[4] Well Done\n";
                    cout << "[0] Back\n";
                    cin >> alegereRaritate;
                    if(!alegereRaritate) break;
                    switch(alegereRaritate)
                    {
                        case 1:
                        {
                            mese[masaAleasa].comandaNoua(persoanaAleasa, makeChateaubriand(12, "Rare"), 6);
                            break;
                        }
                        case 2:
                        {
                            mese[masaAleasa].comandaNoua(persoanaAleasa, makeChateaubriand(12, "Medium Rare"), 6);
                            break;
                        }
                        case 3:
                        {
                            mese[masaAleasa].comandaNoua(persoanaAleasa, makeChateaubriand(12, "Medium"), 6);
                            break;
                        }
                        case 4:
                        {
                            mese[masaAleasa].comandaNoua(persoanaAleasa, makeChateaubriand(12, "Well Done"), 6);
                            break;
                        }
                    }
                    mese[masaAleasa].addToReceipt(persoanaAleasa, 12);
                    mese[masaAleasa].comandatFP(persoanaAleasa);
                    break;
                }
                case 4:
                {
                    mese[masaAleasa].comandaNoua(persoanaAleasa, makeStroganoff(12), 7);
                    mese[masaAleasa].addToReceipt(persoanaAleasa, 12);
                    mese[masaAleasa].comandatFP(persoanaAleasa);
                    break;
                }
                case 5:
                {
                    mese[masaAleasa].comandaNoua(persoanaAleasa, makeFile(12), 8);
                    mese[masaAleasa].addToReceipt(persoanaAleasa, 12);
                    mese[masaAleasa].comandatFP(persoanaAleasa);
                    break;
                }
                

            }
            break;
        }

        case 3:
        {
            if(!mese[masaAleasa].getComandatFP(persoanaAleasa))
            {
                cout << "Trebuie sa cumperi fel principal inainte de a cumpara garnitura\n";
                wait();
                break;
            }
            do
            {
                cout << "[1] Cartofi Prajiti: nu stiu preturi (12 lei)\n";
                cout << "[2] Cartofi Piure: nu stiu preturi (12 lei)\n";
                cout << "[3] Orez Sarbesc: nu stiu preturi (12 lei)\n";
                cout << "[0] Back\n";

                cin >> mancareaAleasa;
                if(!mancareaAleasa) break;
                if(mancareaAleasa<0||mancareaAleasa>3)
                    cout << "Alege un numar valid\n";
            }while(mancareaAleasa<0||mancareaAleasa>3);
            switch(mancareaAleasa)
            {
                case 1:
                {
                    mese[masaAleasa].comandaNoua(persoanaAleasa, makeCartofiPrajiti(12),9);
                    mese[masaAleasa].addToReceipt(persoanaAleasa, 12);
                    break;
                }
                
                case 2:
                {
                    mese[masaAleasa].comandaNoua(persoanaAleasa, makeCartofiPrajiti(12), 10);
                    mese[masaAleasa].addToReceipt(persoanaAleasa, 12);
                    break;
                }
                
                case 3:
                {
                    mese[masaAleasa].comandaNoua(persoanaAleasa, makeOrezSarbesc(12), 11);
                    mese[masaAleasa].addToReceipt(persoanaAleasa, 12);
                    break;
                }
            }
            break;
        }
        case 4:
        {
            do
            {
                cout << "[1] Inghetata : nu stiu (5 lei/cupa)\n";
                cout << "[2] Tort Krantz : 12 lei\n";
                cout << "[0] Back\n";
                cin >> mancareaAleasa;
                if(!mancareaAleasa) break;
                if(mancareaAleasa<0||mancareaAleasa>2)
                    cout << "Enter Valid Input";
            }while(mancareaAleasa<0||mancareaAleasa>2);
            switch(mancareaAleasa)
            {
                case 1:
                {
                    int nrCupe;
                    cout << "How many cups?\n";
                    cin >> nrCupe;
                    mese[masaAleasa].comandaNoua(persoanaAleasa, makeInghetata(5, nrCupe), 12);
                    mese[masaAleasa].addToReceipt(persoanaAleasa, 5*nrCupe);
                    break;
                }

                case 2:
                {
                    mese[masaAleasa].comandaNoua(persoanaAleasa, makeTortKrantz(12), 13);
                    mese[masaAleasa].addToReceipt(persoanaAleasa, 12);
                    break;
                }
            }
            break;
        }
        case 5:
        {
            do
            {
                cout << "[1] Vin Varsat: 29 lei\n";
                cout << "[2] Bordeaux 1996: 48 lei\n";
                cout << "[3] Castel Bolovanu 2004: 46 lei\n";
                cout << "[4] Bere: 10 lei\n";
                cout << "[5] Apa: 7 lei\n";
                cout << "[0] Back\n";
                cin >> mancareaAleasa;
                if(!mancareaAleasa) break;
                if(mancareaAleasa<0||mancareaAleasa>5)
                    cout << "Enter Valid Input\n";
            }while(mancareaAleasa<0||mancareaAleasa>5);
            switch(mancareaAleasa)
            {
                case 1:
                {
                    int culoareAleasa;
                    do
                    {
                        cout << "[1] Rosu\n";
                        cout << "[2] Alb\n";
                        cout << "[0] Back\n";
                        cin >> culoareAleasa;
                        if(!culoareAleasa) break;
                    }while(culoareAleasa<0||culoareAleasa>2);
                    switch(culoareAleasa)
                    {
                        case 1:
                        {
                            mese[masaAleasa].comandaNoua(persoanaAleasa, makeVinVarsat(29, "Rosu"), 14);
                            break;
                        }
                        case 2:
                        {
                            mese[masaAleasa].comandaNoua(persoanaAleasa, makeVinVarsat(29, "Alb"), 14);
                            break;
                        }
                    }
                    mese[masaAleasa].addToReceipt(persoanaAleasa, 29);
                    break;
                }
                case 2:
                {
                    mese[masaAleasa].comandaNoua(persoanaAleasa, makeBordeaux(48, 1996), 15);
                    mese[masaAleasa].addToReceipt(persoanaAleasa, 48);
                    break;
                }
                case 3:
                {
                    mese[masaAleasa].comandaNoua(persoanaAleasa, makeCastelBolovanu(48, 1996), 16);
                    mese[masaAleasa].addToReceipt(persoanaAleasa, 46);
                    break;
                }
                case 4:
                {   int alcool = 0;
                    char alegereAlcool;
                    cout << "Fara alcool?(y/n)\n";
                    cin >> alegereAlcool;
                    if(alegereAlcool=='n') alcool = 1;
                    mese[masaAleasa].comandaNoua(persoanaAleasa, makeBere(10, alcool), 17);
                    mese[masaAleasa].addToReceipt(persoanaAleasa, 10);
                    break;
                }
                case 5:
                {
                    mese[masaAleasa].comandaNoua(persoanaAleasa, makeApa(7), 18);
                    mese[masaAleasa].addToReceipt(persoanaAleasa, 7);
                    break;
                }
            }
            break;
        }
    }

    
    
    
}

void paymentMenu(int &opreste, table *mese, int masaAleasa)
{
    int alegere;
    do
    {
        cout << "[1] Plata Individuala\n";
        cout << "[2] Plata Colectiva\n";
        cout << "[0] Back\n";
        cin >> alegere;
        if(alegere<0||alegere>2)
            cout << "Enter Valid Input\n";
    }while(alegere<0||alegere>2);
    if(!alegere)
    {
        opreste = 1;
        return;
    } 
    switch(alegere)
    {
        case 1:
        {
            int persoanaAleasa;
            do
            {
                for(int i=0; i<mese[masaAleasa].getNrPersoane(); i++)
                {
                    cout << '[' << i+1 <<"] Persoana " << i+1  << " : " << mese[masaAleasa].getBon(i) << " lei \n";
                }
                cout << "[0] Back\n";
                cin >> persoanaAleasa;
        
                if(persoanaAleasa<0||persoanaAleasa>mese[masaAleasa].getNrPersoane())
                    cout << "Enter Valid Number\n";
            }while(persoanaAleasa<0||persoanaAleasa>mese[masaAleasa].getNrPersoane());
            if(!persoanaAleasa)
            {
                opreste = 1;
                return;
            } 
            persoanaAleasa--;
            mese[masaAleasa].pay(persoanaAleasa);
            cout << "Persoana " << persoanaAleasa + 1 << " a platit\n";
            break;
        }

        case 2:
        {
            for(int i=0; i<mese[masaAleasa].getNrPersoane(); i++)
            {
                if(mese[masaAleasa].getBon(i))
                {
                    mese[masaAleasa].pay(i);
                    cout << "Persoana " << i + 1 << " a platit\n";
                }
            }
            break;
        }
    
    }
    
}

void freeTableMenu(int& back, table *mese, int masaAleasa)
{
    if(mese[masaAleasa].getBon())
    {
        cout << "Nu s-a platit bonul\n";
        wait();
        return;
    }
    else mese[masaAleasa].free();
    back = 1;

}

void goToTableMenu(int& stop, table* mese, int nrMese)
{
    clear();
    int nrMeseOcupate = 0, alegere, masaAleasa;
    int* mesePosibile = new int[nrMese];
    
    for(int i=0; i<nrMese; i++)
    {
        if(mese[i].isFree()==0)
        {
            mesePosibile[nrMeseOcupate] = i;
            nrMeseOcupate++;
        }
    }

    if(nrMeseOcupate == 0)
    {
        delete[] mesePosibile;
        stop = 1;
        cout << "All Tables Are Free\n";
        wait();
        clear();
        return;
    }
    cout << "Choose a Table:\n";
    for(int i=0; i<nrMeseOcupate; i++)
    {
       cout << "[" << i+1 << "] Table " << mesePosibile[i] + 1 << '\n';
    }
    cout << "[0] Exit\n";
    cin >> alegere;
    
    if(alegere==0)
    {
        delete[] mesePosibile;
        stop = 1;
        clear();
        return;
    }

    masaAleasa = mesePosibile[alegere-1];
    delete[] mesePosibile;
    int back = 0;
    while(!back)
    {
        int opreste = 0;
        clear();
        cout << "Table " << masaAleasa + 1<< " - " << mese[masaAleasa].getNrPersoane() 
             << " People - "<< mese[masaAleasa].getBon() << " RON" << '\n';
        cout << "[1] New Order    [2] Pay    [3] Free Table    [4] Back\n";
        cin >> alegere;
        switch(alegere)
        {
            case 1:
            {   //gata (somehow)
                while(opreste==0) newOrderMenu(opreste, mese, masaAleasa);
                break;
            }
            case 2:
            {   //gata
                while(opreste==0) paymentMenu(opreste, mese, masaAleasa);
                break;
            }
            case 3:
            {
                //gata
                freeTableMenu(back, mese, masaAleasa);
                break;
            }
            case 4:
            {
                stop = 1;
                back = 1;
                clear();
                break;
            }
        }
    }
}

void debug(table *mese, int nrMese)
{
    cout << "Debug:\n";
    for(int i=0; i<nrMese; i++)
    {
        cout << "Masa " << i+1 << ":\n";
        cout << "Bon: " << mese[i].getBon() << " lei\n";
        cout << "Nr Scaune: " << mese[i].getNrScaune() << '\n';
        cout << "Libera: " << mese[i].isFree() << '\n';
        if(!mese[i].isFree())
        {
            for(int j=0; j<mese[i].getNrPersoane(); j++)
            {
                cout << "Persoana " << j+1 << ": " << mese[i].getBon(j) << " lei\n";
                mese[i].printOrder(j);
                cout << "\n";
            }
            
        }
        cout << '\n';
    }
}


int main()
{
    
    int nrMese, alegere, exit = 0;
    cout << "Enter the number of tables in the restaurant:";
    cin >> nrMese;
    table* mese = new table[nrMese];
    for(int i=0; i<nrMese; i++)
        cin >> mese[i];
    clear();
    while(!exit)
    {
        
        cout << "Funny Restaurant\n";
        cout << "[1] New Group    [2] Go To Table    [3] Debug    [4] Exit\n";

        cin >> alegere;
        int stop = 0;
        switch(alegere)
        {
            case 1:
            { //gata
                while(!stop)
                    newGroupMenu(stop, mese, nrMese);
                break;
            }
            case 2:
            {
                while(!stop)
                    goToTableMenu(stop, mese, nrMese);
                break;
            }
            case 3:
            {
                debug(mese, nrMese);
                break;
            }
            case 4:
            { //gata
                cout << "Exiting Program\n";
                exit = 1;
                break;
            }

        }
    }
    delete[] mese;
    
    cout << '\n';
    return 0;
}