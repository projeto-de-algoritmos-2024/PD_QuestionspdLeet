class Solution {
public:
    //recebe um vetor com os precos das açoes 
    int maxProfit(vector<int>& precos) {

    //verifica se ta vazio
    if (precos.empty()) return 0;

    //declarando variaveis 
    int dias = precos.size();    
    vector<int> transacao1(dias, 0), transacao2(dias, 0);

    //Calculando o lucro máximo até o dia i
    int preco_minimo = precos[0];
    for (int i = 1; i < dias; i++) {
        preco_minimo = min(preco_minimo, precos[i]);
        transacao1[i] = max(transacao1[i - 1], precos[i] - preco_minimo);
    }

    //Calculando o lucro máximo a partir do dia i
    int preco_maximo = precos[dias - 1];
    for (int i = dias - 2; i >= 0; i--) {
        preco_maximo = max(preco_maximo, precos[i]);
        transacao2[i] = max(transacao2[i + 1], preco_maximo - precos[i]);
    }

    //Calculando o lucro máximo com duas transações
    int lucro_maximo = 0;
    for (int i = 0; i < dias; i++) {
        lucro_maximo = max(lucro_maximo, transacao1[i] + transacao2[i]);
    }

    return lucro_maximo;
}

};