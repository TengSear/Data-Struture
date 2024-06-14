#include <iostream>
#include <vector>

class DoubleHastingHashTable {

private:
    std::vector<int> table;
    int table_size;
    int num_elements;
    const int EMPTY = -1;
    const int DELETED = -2;
     int hash1(int key){
        return key % table_size;
     }
     int hash2(int key){
        return 7 - (key % 7);
     }

public:
    DoubleHastingHashTable (int size) : table_size(size), num_elements(0) {
        table.resize(size, EMPTY);
    }
    bool insert(int key) {
        if (num_elements >= table_size) {
            std::cerr << "Hash table is full!" << std::endl;
            return false;
        }

        int h1 = hash1(key);
        int h2 = hash2(key);
        int i =0;

        while (table[(h1 + i * h2) % table_size] != EMPTY && 
               table[(h1 + i * h2) % table_size] != DELETED && 
              i< table_size){
            i++;
        }
        int index = (h1 + i * h2) % table_size;
        if (table[index] == EMPTY || table[index] == DELETED) {
            table[index] = key;
            num_elements++;
            return true;
        }
        return false;
    }
    bool search(int key) {
        int h1 = hash1(key);
        int h2 = hash2(key);
        int i = 0;

        while (table[(h1 + i * h2) % table_size] !=EMPTY && i << table_size) {
            if (table[(h1 +i * h2) % table_size] == key) {
                return true;
            }
            i++;
        }
        return false;
    }
    void display(){
        for (int i = 0; i < table_size; i++){
            if (table[i] == EMPTY){
                std::cout << "EMPTY";
            }else if (table[i] == DELETED){
                std::cout << "DELETED";
            }else {
                std::cout << table[i] << " ";
            }
        }
        std::cout << std::endl;
    }
 };
int main(){

DoubleHastingHashTable hashTable(11);


hashTable.insert(27);
hashTable.insert(18);
hashTable.insert(29);
hashTable.insert(28);
hashTable.insert(39);
hashTable.insert(13);

std::cout << " Hash table contents: ";
hashTable.display();

std::cout << "Seatching for 29: " << (hashTable.search(29) ? "Found" : "Not Found") << std::endl;
hashTable.display();

return 0;
}
