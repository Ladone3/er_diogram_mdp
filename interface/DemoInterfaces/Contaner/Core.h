#ifndef CORE_H
#define CORE_H

#include <string>
#include "List.h"

using namespace std;
class ERDiagram;
class Entitie;
class Relation;

class Core {
private:
	ERDiagram* content;
    int focus;
    int state;
    // 0 - Сущность
    // 1 - Связь
    // 2 - Выделить
    // 3 - Указатель
    // 4 - Удалить
    bool focusEntitieOrRelation;

public:
	Core();
	~Core();
    void saveProject(string file);
    void loadProject(string file);
    void addRelation(Entitie* e1, Entitie* e2, string id, string key);
    void addEntitie(string name);
    void addEntitieTo(string name, int x, int y);
    void addEntitieTo(Entitie* e);
    void popRelationAt(int n);
    void popRelationByID(string ID);
    void popEntitieAt(int n);
    void popEntitieByID(string ID);
    int getEntitieCount();
    int getRelationCount();
    Entitie* getEntitieByID(string name);
    Relation* getRelationByID(string name);
    Entitie* getEntitieAt(int n);
    Relation* getRelationAt(int n);
    List<string>* getBestWay();
    int getState();
    int getFocus();
    void setState(int state);
    void setFocus(int focus);
    void spotFocus();
    bool getFocusObj();
    void setFocusObj(bool feor);

};

#endif //CORE_H
