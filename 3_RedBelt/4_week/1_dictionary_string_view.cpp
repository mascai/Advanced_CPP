/*

Разработайте класс Translator, позволяющий сохранять двуязычные пары слов и затем переводить слова с одного языка на другой с использованием уже добавленных пар:

Более конкретно, объект t типа Translator должен допускать следующие действия:

    Создание с помощью конструктора по умолчанию. В этом случае база переводов пуста.
    Добавление двуязычной пары: t.Add(source, target). После такого вызова считается, что слово source на языке 1 соответствует слову target на языке 2. Переданные в метод Add строки могут быть уничтожены раньше объекта t.
    Перевод с языка 1 на язык 2: t.TranslateForward(source). Если ранее уже был вызов t.Add(source_copy, target)для некоторой строки target и строки source_copy, равной source (или являющейся ей), нужно вернуть target. Если такого вызова не было, нужно вернуть пустую строку. Если таких вызовов было несколько, нужно вернуть target для последнего из них.
    Перевод с языка 2 на язык 1: t.TranslateBackward(target). Если ранее уже был вызов t.Add(source, target_copy)для некоторой строки source и строки target_copy, равной target (или являющейся ей), нужно вернуть source. Если такого вызова не было, нужно вернуть пустую строку. Если таких вызовов было несколько, нужно вернуть source для последнего из них.
    
    */

#include "profile.h"
#include "test_runner.h"
#include <deque>
#include <iostream>
#include <map>
#include <string_view>
#include <vector>

using namespace std;

class Translator {
public:
  void Add(string_view source, string_view target) {
    const string_view source_view = GetClonedView(source);
    const string_view target_view = GetClonedView(target);
    forward_dict[source_view] = target_view;
    backward_dict[target_view] = source_view;
  }
  string_view TranslateForward(string_view source) const {
    return Translate(forward_dict, source);
  }
  string_view TranslateBackward(string_view target) const {
    return Translate(backward_dict, target);
  }

private:
  string_view GetClonedView(string_view s) {
    for (const auto* map_ptr : {&forward_dict, &backward_dict}) {
      const auto it = map_ptr->find(s);
      if (it != map_ptr->end()) {
        return it->first;
      }
    }
    return data.emplace_back(s);
  }

  static string_view Translate(const map<string_view, string_view>& dict, string_view s) {
    if (const auto it = dict.find(s); it != dict.end()) {
      return it->second;
    } else {
      return {};
    }
  }
    

  map<string_view, string_view> forward_dict;
  map<string_view, string_view> backward_dict;
  deque<string> data;
};
