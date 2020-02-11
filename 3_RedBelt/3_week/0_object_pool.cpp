https://www.coursera.org/learn/c-plus-plus-red/programming/WtGFB/pul-obiektov

/*
На практике часто возникают объекты, создание которых занимает значительное время, например, потоки (threads), TCP-соединения или подключения к базе данных. Поэтому, когда такой объект становится не нужен, его не разрушают, а откладывают в сторону, чтобы потом переиспользовать. В этой задаче вам предстоит реализовать такую схему — вам надо написать шаблон класса ObjectPool: 

    Объект класса ObjectPool должен поддерживать два набора объектов: выделенные и освобождённые, — изначально оба набора пусты.
    Метод Allocate должен работать так:

    если есть хотя бы один освобождённый объект, то его надо перенести в множество выделенных и вернуть указатель на него в качестве результата функции
    если же освобождённых объектов нет, то создаётся новый объект, помещается в множество выделенных, и указатель на него возвращается в качестве результата функции

    Метод TryAllocate работает аналогично, однако если освобождённых объектов нет, он должен просто возвращать nullptr.
    Метод Deallocate переносит объект из множества выделенных в множество освобождённых; если переданный объект не содержится в множестве выделенных, метод Deallocate должен бросать исключение invalid_argument.
    Методы Allocate и TryAllocate должны возвращать объекты в порядке FIFO, т.е. множество освобождённых объектов должно представлять собой очередь: методы [Try]Allocate должны извлекать объекты из её начала, а метод Deallocate должен помещать освобождаемый объект в её конец.
    Деструктор объекта ObjectPool должен уничтожать все объекты пула, как выделенные, так и освобождённые.



*/


#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
#include <list>

using namespace std;

template <class T>
class ObjectPool {
public:
  T* Allocate() {
      if (not freed.empty()) {
        T* temp = freed.front();
        freed.pop();
        allocated.insert(temp);
        return temp;
      } else {
          T* temp = new T();
          allocated.insert(temp);
          return temp;
      }
  }
  T* TryAllocate() {
    if (not freed.empty()) {
        T* temp = freed.front();
        allocated.insert(temp);
        freed.pop();
        return temp;
      } else {
          return nullptr;
      }
  }

  void Deallocate(T* object) {
      if (allocated.find(object) != allocated.end()) {
        allocated.erase(object);
        freed.push(object);
      } else {
          throw invalid_argument("Invalid object");
      }
  }

  ~ObjectPool() {
      while (not freed.empty()) {
        T* temp = freed.front();
        delete temp;
        freed.pop();
      }
      for (auto it = allocated.begin(); it != allocated.end();) {
        auto nextIt = next(it);
        delete *it;
        allocated.erase(*it);
        it = nextIt;
      }
  }

private:
    queue<T*> freed;
    set<T*> allocated;

};


int main() {
  ObjectPool<string> pool;
  auto p1 = pool.Allocate();
  auto p2 = pool.Allocate();
  auto p3 = pool.Allocate();

  *p1 = "first";
  *p2 = "second";
  *p3 = "third";

  pool.Deallocate(p2);
  cout << *pool.Allocate();
  pool.Deallocate(p3);
  pool.Deallocate(p1);
  cout << *pool.Allocate();
  cout << *pool.Allocate();
  return 0;
}
