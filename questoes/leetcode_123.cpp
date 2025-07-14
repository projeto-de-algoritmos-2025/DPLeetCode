#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& valores) {
        int n = valores.size();
        if (n < 2) {
            return 0;
        }

        vector<int> lucroEsquerda(n, 0);
        vector<int> lucroDireita(n, 0);

        int precoDeCompra = valores[0];
        for (int i = 1; i < n; ++i) {
            precoDeCompra = min(precoDeCompra, valores[i]);
            lucroEsquerda[i] = max(lucroEsquerda[i - 1], valores[i] - precoDeCompra);
        }

        int precoDeVenda = valores[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            precoDeVenda = max(precoDeVenda, valores[i]);
            lucroDireita[i] = max(lucroDireita[i + 1], precoDeVenda - valores[i]);
        }

        int lucroTotalMaximo = 0;
        for (int i = 0; i < n; ++i) {
            lucroTotalMaximo = max(lucroTotalMaximo, lucroEsquerda[i] + lucroDireita[i]);
        }

        return lucroTotalMaximo;
    }
};