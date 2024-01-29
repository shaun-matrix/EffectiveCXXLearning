//
// Created by 姚轩 on 2024/1/29.
//
#include "sales_item.h"

// note here p is initialized 0. this is an implicit type conversion
Sales_item::Sales_item(): p(0), count(0) {}

Sales_item::Sales_item(Item_base &i): p(&i), count(1) {}

Sales_item::Sales_item(const Sales_item &s): p(s.p), count(s.count) { count++; }

Sales_item& Sales_item::operator=(const Sales_item &s) {
    p = s.p;
    count = s.count;
    count++;
    return *this;
}

Item_base& Sales_item::operator*() {
    if(p) return *p;
    else throw std::logic_error("unbound Sales_item object");
}

const Item_base& Sales_item::operator*() const {
    if(p) return *p;
    else throw std::logic_error("unbound Sales_item object");
}

Item_base* Sales_item::operator->() {
    if(p) return p;
    else throw std::logic_error("unbound Sales_item object");
}

const Item_base* Sales_item::operator->() const {
    if(p) return p;
    else throw std::logic_error("unbound Sales_item object");
}

Sales_item::~Sales_item() {
    if(--count==0){
        delete p;
    }
}