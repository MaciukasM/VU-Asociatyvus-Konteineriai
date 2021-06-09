#include "headeriai.hpp"

regex tikrinimui ("(((http|https)://)?www\\.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");

//pagal zodi galesim ziuret, kiek kas (ir kur) pasikartoja
map<string, int> zodziuSkaicius;
multimap<string, int> kuriojeEiluteje; //multimap, kad galetume naudoti duplikatus

map<int, string> linkai; //linkams saugoti

bool arLinkas(string a)
{
    return regex_match(a, tikrinimui);
}

bool arEgzistuoja(string duomFailas)
{
    ifstream failas(duomFailas);
    bool ArEgzistuoja = failas.good();
    failas.close();
    return ArEgzistuoja;
}

void NuskaitykFaila(string duomFailas)
{
    ifstream failas(duomFailas);
    string eilute;

    int kelintas = 0; //linku numeravimas
    int eilSk = 1; //eiluciu numeravimas
    while(!failas.eof()) //vis eis per kiekviena eilute ir apdirbs ja
    {
        getline(failas, eilute);
        DarbasSuEilute(eilute, kelintas, eilSk);
    }

    failas.close();
    //rezultatu isvedimas atitinkamoms uzduotims (1 - visu zodziu pasikartojimai, 2 - kurioje eiluteje kas pasikartoja, 3 - link'u isvedimas)
    RezIsvedimas("1.txt", 1);
    RezIsvedimas("2.txt", 2);
    RezIsvedimas("3.txt", 3);
}

void IstrinkIkiPointerio(int pointeris, string &eilute)
{
    eilute.erase(0, pointeris);
    if(eilute[0]==' ') eilute.erase(0,1);
}

//kadangi vykdomas toks tikrinimas su ascii lentele, tai veiks tik su angliskais rasmenimis (be lietuvybiu)
bool TikRaides(char a)
{
    if(a==32 || (a>64 && a<91) || (a>96 && a<123) || (a>47 && a<58)) return false; //returninam false, nes naudosim remove_if, kuris removina jei true
    return true;
}

void DarbasSuEilute(string eilute, int &kelintas, int &eilSk)
{
    //kad galetume laisvai keisti string'a kiekvienai uzduociai
    string eil1 = eilute;
    string eil3 = eilute;

    int pointeris = 0; //veiks kaip pointeris, tik rodys nuo kurio simbolio kazka rado
    string zodis; //norint isskirti zodi is string'o

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // 3 daliai atlikti (linkams)

    while(eil3.length()!=0) //tikrina zodi po zodzio ar jis yra linkas
    {
        pointeris = eil3.find(' ');
        if(pointeris!=string::npos)
        {
            zodis = eil3.substr(0, eil3.find(' '));
            if(arLinkas(zodis)) 
            {
                linkai.insert(make_pair(kelintas, zodis));
                kelintas++;
            }
            IstrinkIkiPointerio(eil3.find(' '), eil3);
        }
        else
        {
            if(arLinkas(eil3)) 
            {
                linkai.insert(make_pair(kelintas, eil3));
                kelintas++;
            }
            eil3.erase();
        }
    }

    // 3 daliai atlikti (linkams)
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // 1-2 daliai atlikti (kiek kartu kiekvienas zodis pasikartoja ir kur)

    //istrinam link'us
    for (auto i : linkai)
    {
        if(eil1.find(i.second)!=string::npos)
        {
            pointeris = eil1.find(i.second);
            if(eil1[pointeris+(i.second).length()] == ' ') eil1.erase(pointeris, (i.second).length()+1);
            else eil1.erase(pointeris, (i.second).length());
        }
    }
    //istrinam pasalinius simbolius ir keiciam i mazasias raides
    eil1.erase(remove_if(eil1.begin(), eil1.end(), TikRaides), eil1.end());
    transform(eil1.begin(), eil1.end(), eil1.begin(), ::tolower);
    while(eil1.length()!=0)
    {
        pointeris = eil1.find(' ');
        if(pointeris!=string::npos)
        {
            zodis = eil1.substr(0, pointeris);
            if(zodziuSkaicius.find(zodis) == zodziuSkaicius.end()) zodziuSkaicius.insert(make_pair(zodis, 1));
            else zodziuSkaicius[zodis]++;
            kuriojeEiluteje.insert(make_pair(zodis, eilSk));
            IstrinkIkiPointerio(pointeris, eil1);
        }
        else
        {
            if(zodziuSkaicius.find(eil1) == zodziuSkaicius.end()) zodziuSkaicius.insert(make_pair(eil1, 1));
            else zodziuSkaicius[eil1]++;
            kuriojeEiluteje.insert(make_pair(eil1, eilSk));
            eil1.erase();
        }
    }

    eilSk++;

    // 1-2 daliai atlikti (kiek kartu kiekvienas zodis pasikartoja ir kur)
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void RezIsvedimas(string RezFailas, int uzd)
{
    ofstream isvedimas(RezFailas);

    if(uzd == 1)
    {
        isvedimas<<"Zodziai ir ju pasikartojamu skaicius:\n"<<endl;
        for (auto i : zodziuSkaicius)
        {
            if(i.second>1) isvedimas<<i.first<<" - "<<i.second<<endl;
        }
    }

    if(uzd == 2)
    {
        isvedimas<<"Zodziai ir ju pasikartojamu vieta:\n"<<endl;
        for (auto i : zodziuSkaicius)
        {
            if(i.second>1) 
            {
                isvedimas<<i.first<<": ";
                auto a = kuriojeEiluteje.equal_range(i.first);
                for(auto it = a.first; it!=a.second; it++)
                {
                    isvedimas<<it->second<<" ";
                }
                isvedimas<<endl;
            }
        }
    }

    if(uzd == 3)
    {
        isvedimas<<"Teksto nuorodos:\n"<<endl;
        for (auto i : linkai)
        {
            isvedimas<<(i.first)+1<<". "<<i.second<<endl;
        }
    }

    isvedimas.close();
}