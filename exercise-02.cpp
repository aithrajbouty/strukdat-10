#include <iostream>
#include <stdlib.h>
using namespace std;

struct ElemenQueue{
    int info;
    ElemenQueue* next;
};
typedef ElemenQueue* pointer;
typedef pointer List;

struct Queue {
    List Head;
    List Tail;
};
Queue Q;

void createQueue(Queue& Q){
    Q.Head = NULL;
    Q.Tail = NULL;
}

void CreateElement(pointer& pBaru){
    pBaru = new ElemenQueue;
    cout << "Masukkan queue: "; cin >> pBaru->info;
    pBaru->next = NULL;
}

void insertQueue(Queue& Q, pointer pBaru){
    if(Q.Head==NULL && Q.Tail==NULL){
        Q.Head = pBaru;
        Q.Tail = pBaru;
    }
    else{
        Q.Tail->next = pBaru;
        Q.Tail = pBaru;
    }
}

void deleteQueue(Queue& Q, pointer& pHapus){
    if(Q.Head==NULL && Q.Tail==NULL){
        pHapus = NULL;
        cout << "List queue kosong" << endl;
    }
    else if(Q.Head->next == NULL){
        pHapus = Q.Head;
        Q.Head = NULL;
        Q.Tail = NULL;
    }
    else{
        pHapus = Q.Head;
        Q.Head = Q.Head->next;
        pHapus->next = NULL;
    }
}

void traversal(Queue Q){
    pointer pBantu;
    cout << "ANTRIAN : ";
    if(Q.Head==NULL){
        cout << "Antrian Kosong";
    }
    else{
        pBantu=Q.Head;
        do{
            cout << pBantu->info << " ";
            pBantu = pBantu->next;
        } while(pBantu != NULL);
    }
    cout << endl;
}

int main()
{
    Queue q;
    pointer p;
    int menu;

    createQueue(q);

    do{
        system("cls");
        cout << "Menu" << endl;
        cout << "1. Masukkan antrian " << endl;
        cout << "2. Hapus antrian" << endl;
        cout << "3. Tampilkan antrian" << endl;
        cout << "4. Selesai" << endl;
        cout << "Pilih salah satu menu : "; cin >> menu;
        cout << endl;

        switch(menu){
        case 1:
            CreateElement(p);
            insertQueue(q,p);
            traversal(q);
        break;

        case 2:
            deleteQueue(q,p);
            traversal(q);
        break;

        case 3:
            traversal(q);
        break;

        default :
            exit(0);
        }
        cout << endl;
        system("pause");
    }while(menu!=4);
}
