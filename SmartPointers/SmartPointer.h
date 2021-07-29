//
// Created by daria on 18/06/2021.
//

#ifndef SMARTPOINTERS_SMARTPOINTER_H
#define SMARTPOINTERS_SMARTPOINTER_H


template<class TElem>
class SmartPointer {
private:
    TElem* data;
public:
    SmartPointer() = default;

    SmartPointer(TElem* data): data{data}{

    }

    TElem& operator*() {
        return *(this->data);
    }

    friend std::ostream& operator <<(std::ostream& output, const SmartPointer<TElem>& sp) {
        output << sp.data;
        return output;
    }

    bool operator==(const SmartPointer<TElem> &sm) const {
        if (this->data == sm.data)
            return true;
        return false;
    }

    ~SmartPointer() {
        delete this->data;
    }
};


#endif //SMARTPOINTERS_SMARTPOINTER_H
