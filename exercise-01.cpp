#include <iostream>
#include <stdlib.h>
using namespace std;

const int maxElemen = 5;
struct Queue{
    int isi[maxElemen];
    int head;
    int tail;
};

void createQueue(Queue& Q){
    Q.head = -1;
    Q.tail = -1;
}

void insertQueue(Queue& Q, int elemen){
    int posisiTemp;
    if(Q.tail == -1){
        Q.head = 0;
        Q.tail = 0;
        Q.isi[Q.tail] = elemen;
    }
    else{
        posisiTemp = Q.tail;
        if(Q.tail < maxElemen-1){
            Q.tail = Q.tail + 1;
        }
        else{
            Q.tail = 0;
        }
        if(Q.tail==Q.head){
            cout << "Antrian sudah penuh" << endl;
            Q.tail = posisiTemp;
        }
        else{
            Q.isi[Q.tail] = elemen;
        }
    }
}

void deleteQueue(Queue& Q, int& elemenHapus){
    if(Q.head==-1){
        cout << "Antrian kosong" << endl;
    }
    else if(Q.head==Q.tail){
        elemenHapus = Q.isi[Q.head];
        Q.isi[Q.head] = ' ';
        Q.head = -1;
        Q.tail = -1;
    }
    else{
        elemenHapus = Q.isi[Q.head];
        Q.isi[Q.head] = ' ';
        if(Q.head < maxElemen-1){
            Q.head = Q.head + 1;
        }
        else{
            Q.head = 0;
        }
    }
}

void input (Queue& Q, int elemen){
    cout << "Data : "; cin >> elemen;
    insertQueue(Q,elemen);
}

void output(Queue& Q){
    cout << "ANTRIAN: " << endl;
    for(int i=Q.head;i<=Q.tail;i++){
        cout << Q.isi[i] << " ";
    }
    cout << endl;
}

int main()
{
    Queue q;
    int e, n, menu, maks;

    createQueue(q);
    cout << "Banyak data (Maksimum " << maxElemen << ") : "; cin >> maks;
    for(int i=0;i<maks;i++){
        input(q,e);
    }

    do{
        system("cls");
        cout << "Menu" << endl;
        cout << "1. Tambahkan antrian " << endl;
        cout << "2. Hapus antrian" << endl;
        cout << "3. Tampilkan antrian" << endl;
        cout << "4. Selesai" << endl;
        cout << "Pilih salah satu menu : "; cin >> menu;
        cout << endl;

        switch(menu){
        case 1:
            input(q,e);
            cout << endl;
            output(q);

            /*if(q.tail==maxElemen){
                deleteQueue(q,e);
                input(q,e);
            }
            else{
                input(q,e);
            }
            cout << endl;
            output(q);*/
        break;

        case 2:
            deleteQueue(q,e);
            cout << endl;
            output(q);
        break;

        case 3:
            output(q);
        break;

        default :
            exit(0);
        }
        cout << endl;
        system("pause");
    }while(menu!=4);
}
