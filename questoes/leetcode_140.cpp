#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<int, vector<string>> cache;
    unordered_set<string> conjuntoDePalavras;
    string stringPrincipal;

public:
    vector<string> wordBreak(string s, vector<string>& dicionario) {
        stringPrincipal = s;
        conjuntoDePalavras.insert(dicionario.begin(), dicionario.end());
        return buscar(0);
    }

private:
    vector<string> buscar(int indice) {
        if (cache.count(indice)) {
            return cache[indice];
        }

        if (indice == stringPrincipal.length()) {
            return {""};
        }

        vector<string> resultadosParciais;
        for (int i = indice; i < stringPrincipal.length(); ++i) {
            string prefixo = stringPrincipal.substr(indice, i - indice + 1);

            if (conjuntoDePalavras.count(prefixo)) {
                vector<string> sufixos = buscar(i + 1);
                for (const string& sufixo : sufixos) {
                    if (sufixo.empty()) {
                        resultadosParciais.push_back(prefixo);
                    } else {
                        resultadosParciais.push_back(prefixo + " " + sufixo);
                    }
                }
            }
        }

        cache[indice] = resultadosParciais;
        return resultadosParciais;
    }
};