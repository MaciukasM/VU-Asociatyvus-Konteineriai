#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> //std::transform
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;
using std::vector;
using std::map;
using std::multimap;
using std::ofstream;
using std::remove_if;
using std::transform;


bool arEgzistuoja(string duomFailas);
void NuskaitykFaila(string duomFailas);
void IstrinkIkiPointerio(int pointeris, string &eilute);
void DarbasSuEilute(string eilute, int &kelintas, int &eilSk);
void RezIsvedimas(string RezFailas, int uzd);