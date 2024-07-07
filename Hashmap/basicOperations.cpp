#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int main(){
    //creation
    // unordered_map<string, int> m;
    map<string, int> m;

    //insertion
    //1 
    pair<string, int> p1 = make_pair("sehaj", 3);
    m.insert(p1);
    //2
    pair<string, int> p2("mander", 2);
    m.insert(p2);
    //3
    m["hello"] = 1;
    //what will happen - value at give index will be overwritten
    m["hello"] = 2;

    //searching
    cout << "hello : " <<m["hello"] <<endl;
    cout << "sehaj : " <<m.at("sehaj") <<endl;
    //create an entry corresponding to this key with 0
    cout << "unknown with [] : " << m["unknown"] <<endl;
    cout << "unknown with at : " << m.at("unknown") <<endl;

    //size
    cout << "size : " << m.size() <<endl;

    //to check the presence of a value
    cout << "hello : " << m.count("hello") <<endl;
    cout << "random : " << m.count("random") <<endl;

    //to erase
    m.erase("hello");
    cout << "size after erasing : " << m.size() << endl;

    //traversing the map using the iterator
    // unordered_map<string, int> :: iterator it = m.begin();
    map<string, int> :: iterator it = m.begin();
    cout<< "Traversing the map : ";
    while(it != m.end()){
        cout << it->first << " " << it-> second << endl;
        it++;
    }

    return 0;
}