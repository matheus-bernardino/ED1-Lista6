#include <iostream>

using namespace std;

struct no
{
    string nome;
    no *next;
    no(no *head, std::string _nome){nome = _nome, next = head;}
    no(){next = nullptr;}
};

no* criar()
{
    no *head = new no();
    head->next = head;
    return head;
}

void inserir(no *head, string nome, int p)
{
    no *aux;
    int i = 0;
    
    for(aux = head; aux->next != head and i < p; aux = aux->next)
        i++;
        
    if(aux->next == head)
        aux->next = new no(head, nome);
    else
    {
        no *k = new no(head, nome);
        k->next = aux->next;
        aux->next = k;
    }
}

no remover(no *head, int p)
{
    no *aux;
    int i = 0;
    
    for(aux = head; aux->next != head and i < p; aux = aux->next)
        i++;
        
    no *k = aux->next, r = *k;
    aux->next = aux->next->next;
    delete(k);
    return r;
}

void deletar(no *head){
    no *aux1 = head->next, *aux2 = head->next;
    
    while(aux1 != head)
        aux1 = aux1->next, delete(aux2), aux2 = aux1;
        
    delete(aux2);
}

string josephus(no *head, int n, int m)
{
    int c = 0, i;
    no *aux = head;
    
    while(n != 1)
    {
        if(aux == head)
            i = -1, aux = aux->next;
        else
        {
            i++, c++;
            if(c == m)
            {
                no r = remover(head, i);
                n--, i--, c = 0, aux = r.next;
            }
            else
                aux = aux->next;
        }
    }
    
    return head->next->nome;
}

int main()
{
    no *head = criar();
    
    inserir(head, "a", 0);
    inserir(head, "b", 1);
    inserir(head, "c", 2);
    inserir(head, "d", 3);
    inserir(head, "e", 4);
    
    cout << josephus(head, 5, 2) << '\n';
    deletar(head);

    return 0;
}
