#include<iostream>
using namespace std;

template<typename T>

class node {
public:
    string key; 
    T value;
    node<T>* next;

    node(string key, T value) {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~node() { // destructor
        if(next != NULL) { // it will recursively delete all
            delete next;
        }
    }

};

template<typename T>

class HashTable {

    node<T>** table; // pointer to an array of pointers
    int currentSize;
    int tableSize;

    int hashFunction(string key) {
        int ans = 0;
        int p = 1;

        for(int j = 0; j < key.size(); j++) {
            ans = ans + (key[j]*p)%tableSize;
            ans = ans%tableSize;
            p = (p*27)%tableSize;
        }

        return ans;
    }

    void rehash() {
        node<T>** oldTable = table;
        int oldTableSize = tableSize;
        tableSize = 2*tableSize;

        table = new node<T>*[tableSize];

        for(int i = 0; i < tableSize; i++) {
            table[i] = NULL;
        }

        currentSize = 0;

        // shift the elements from old table to new table

        for(int i = 0; i < oldTableSize; i++) {
            
            node<T>* temp = oldTable[i];

            while(temp != NULL) {
                insert(temp->key, temp->value);
                temp = temp->next;
            }

            if(oldTable[i] != NULL) {
                delete oldTable[i]; // deleting elements from old table
            }

        }
        delete [] oldTable;
    }

public:

    HashTable(int ts = 7) {
        tableSize = ts;
        table = new node<T>*[tableSize];
        currentSize = 0;

        for(int i = 0; i < tableSize; i++) {
            table[i] = NULL; // instead of garbage keep a NULL
        }

    }

    void insert(string key, T value) {
        int idx = hashFunction(key);
        node<T>* n = new node<T>(key, value); // n is pointing to newly built linked list

        // insert at head of the linked list with id = idx
        n->next = table[idx]; // table[idx] is old head i.e., NULL
        table[idx] = n;
        currentSize++;

        // rehashing
        float loadFactor = currentSize/(1.0*tableSize);

        if(loadFactor > 0.7) {
            rehash();
        }
    }

    void print() {
        for(int i = 0; i < tableSize; i++) {
            cout<<"Bucket "<<i<<" -> ";
            node<T>* temp = table[i];

            while(temp != NULL) {
                cout<<temp->key<<", ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    T* search(string key) {
        int idx = hashFunction(key);
        node<T>* temp = table[idx];

        while(temp != NULL) { // traversing in linked list
            if(temp->key == key) {
                return &temp->value;
            }
            temp = temp->next;
        }

        return NULL;
    }

    T& operator [](string key) {
        T* ptr = search(key);

        if(ptr == NULL) {
            // insert key, value(garbage) in the hashmap
            T garbage;
            insert(key, garbage);
            ptr = search(key);
        }

        return *ptr;
    }

    void erase(string key) {
        // int idx = hashFunction(key);

        // node<T>* temp = table[idx];

        // while(temp != NULL) {
        //     if(temp->key == key) {
        //         delete table[idx];
        //     }
        // }
    }

};

int main() {

    HashTable<int> priceMenu;

    priceMenu.insert("Burger", 120);
    priceMenu.insert("Pepsi", 20);
    priceMenu.insert("BurgerPizza", 150);
    priceMenu.insert("Noodles", 60);
    priceMenu.insert("Coke", 40);


    priceMenu.print();

    int* price = priceMenu.search("Noodles");

    if(price == NULL) {
        cout<<"Not Found"<<endl;
    }
    else {
        cout<<*price<<endl;
    }

    priceMenu["Dosa"] = 70;
    cout<<"Price of dosa is "<<priceMenu["Dosa"]<<endl;


    return 0;
}