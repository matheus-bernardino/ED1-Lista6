#include <bits/stdc++.h>

using namespace std;

struct no
{
    int valor;
    no *next;
    
    no(int _valor){ valor = _valor; next = nullptr;}
    no(){valor = 0; next = nullptr;}
};

struct comeco
{
    no *adj;
    no *fim;
    bool flag;
};

comeco* criar(int n)
{
    comeco *head = new comeco[n];
    
    for(int i = 0; i < n; i++)
        head[i].adj = new no(), head[i].flag = false, head[i].fim = head[i].adj;
        
    return head;
}

void inserir(comeco *head, int i, int j)
{
    head[i].fim->next = new no(j);
    head[i].fim = head[i].fim->next;
    head[i].adj->valor++;
}

void deletar(comeco *head, int n)
{
    no *aux, *k;
    
    for(int i = 0; i < n; i++)
    {
        aux = head[i].adj;
        while(aux != nullptr)
            k = aux->next, delete(aux), aux = k;
    }
    
    delete[] head;
}

void mostrar(comeco *head, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for(no *aux = head[i].adj->next; aux != nullptr; aux = aux->next)
            cout << aux->valor << ' ';
        cout << '\n';
    }
}

int main()
{
    comeco *head = criar(5);
    
    inserir(head, 0, 2);
    inserir(head, 2, 0);
    
    inserir(head, 1, 2);
    inserir(head, 2, 1);
    
    inserir(head, 2, 3);
    inserir(head, 3, 2);
    
    inserir(head, 3, 4);
    inserir(head, 4, 3);
    
    inserir(head, 4, 1);
    inserir(head, 1, 4);
    
    mostrar(head, 5);
    deletar(head, 5);

    return 0;
}
