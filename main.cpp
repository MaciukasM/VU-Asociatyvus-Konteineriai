#include "headeriai.hpp"

int main()
{
    string duomFailas;
    cout<<"Iveskite duomenu failo pavadinima (pvz. 'pavadinimas.txt'): "<<endl;
    cin>>duomFailas;
    while(!arEgzistuoja(duomFailas))
    {
        cout<<"Failo pavadinimas neteisingai ivestas/jis neegzistuoja. Iveskite is naujo: "<<endl;
        cin>>duomFailas;
    }

    NuskaitykFaila(duomFailas); //failo nuskaitymas
}