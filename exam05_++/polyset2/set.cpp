#include "set.hpp"


// set::set(){}
set::~set(){}
set::set(searchable_bag& _bag): bag(_bag) {}
// set& set::operator=(const set& o){
//     if(this == &o)
//         return *this;
//     bag = o;
//     return *this;
// }

void set:: insert (int n){
    if(!bag.has(n))
        bag.insert(n);
}
void set:: insert (int *arr, int s){
    for(int i = 0; i < s; i++){

        this->insert(arr[i]);
    }
}
void set:: print() const{
    bag.print();
}
void set:: clear(){
    bag.clear();
}
bool set:: has(int n) const{
    return bag.has(n);
}

const searchable_bag& set::get_bag() const{
    return bag;
}