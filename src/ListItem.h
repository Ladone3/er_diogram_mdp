#ifndef LISTITEM_H
#define LISTITEM_H

template<class Type>
class ListItem{
    private:
		Type x;
		ListItem* next;

    public:
        ListItem(Type x);
		~ListItem();
    public:
		void setNext(ListItem* next);
		ListItem* getNext();
		void setValue(Type x);
		Type getValue();
};

//=============================================================
//Реализация
//=============================================================

template<class Type>
ListItem<Type>::ListItem(Type x){
    this->x = x;
    this->next = 0;
}

template<class Type>
ListItem<Type>::~ListItem(){
    if(this->next!=0 && this->next!=this){
        this->next->~ListItem();
    }
}

template<class Type>
void ListItem<Type>::setNext(ListItem* next){
    this->next = next;
}

template<class Type>
ListItem<Type>* ListItem<Type>::getNext(){
    return this->next;
}

template<class Type>
void ListItem<Type>::setValue(Type x){
    this->x = x;
}

template<class Type>
Type ListItem<Type>::getValue(){
    return x;
}

#endif // LISTITEM_H
