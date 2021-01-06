#include<iostream>
using namespace std;

class hashing
{
private:
    int m;
    int *hash;
    int count;
public:
    hashing()
    {
        m = 0;
        //hash = NULL;
        count = 0;
    }
    void create(int m)
    {
        hash = new int[m];
        for (int i = 0; i < m; i++)
            hash[i] = 0;
    }
    void insert(int n, int m)
    {
        int index;
        index = n % m;
        int i = index;
        do {
            if (count == m)
            {
                cout << "Hash table is full";
            }
            else if (hash[i] == '\0') 
            {
                hash[i] = n;
                count++;
                break;
            }
            else if (i == m - 1)
            {
                i = 0;
            }
            else
            {
                i++;
            }
        } 
        while (i != index);
    }
    void print(int m)
    {
        
        cout << "\t\t\tHash Table\n";
        for (int i = 0; i < m; i++)
        {
            cout << "\t\t\t";
            cout << i << "->" << hash[i] << endl;
        }
    }

    void search(int n,int m)
    {
        int index, h,i=0;
        h = n % m;
        index = h;
        while (i<m)
        {
            if (hash[index] == n) 
            {
                cout<<"\t"<<n << " is in the table at position " << index << endl;
                break;
            }
            else
            {
                cout << "\t" << n << " is not in the table"<< endl;
                i++;
                break;
            }
        }
    }
    void Delete(int n, int m)
    {
        int index, h, i = 0;
        h = n % m;
        index = h;
        while (i < m)
        {
            if (hash[index] == n)
            {
                hash[index] = '\0';
                cout<<endl << "\t" << n << " has been deleted from hash table "<< endl;
                break;
            }
            else
            {
                cout<<endl << "\t" << n << " is not in the table" << endl;
                i++;
                break;
            }
        }
    }
};



int main() 
{
    hashing H;
    int opt,size=0,value,search,del;
    while (1)
    {
        cout << "\n\n\t\t1. Insert\n"
            "\t\t2. Delete\n"
            "\t\t3. Search\n"
            "\t\t4. Display\n"
            "\t\t0. Exit\n"
            "\t\tChoice: ";
        cin >> opt;
        if (opt == 1)
        {
            cout << "\tEnter the size of hash table(m): ";
            cin >> size;
            H.create(size);
            cout << "\n\tEnter Data:\n";
            for (int i = 0; i < size; i++)
            {
                cout << "\tEnter value: ";
                cin >> value;
                H.insert(value, size);
            }
            H.print(size);
        }
        if (opt == 2)
        {
            cout << "\n\tEnter value to delete: ";
            cin >> del;
            H.Delete(del, size);
            H.print(size);
        }
        if (opt == 3)
        {
            cout << "\n\tEnter Value to search in hash table: ";
            cin >> search;
            H.search(search,size);
        }
        if (opt == 4)
        {
            H.print(size);
        }
        if (opt == 0)
        {
            exit(0);
        }
    }
    return 0;
}
