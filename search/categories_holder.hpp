#pragma once
#include "../base/base.hpp"

#include "../std/vector.hpp"
#include "../std/string.hpp"
#include "../std/fstream.hpp"
#include "../std/algorithm.hpp"

namespace search
{

struct Category
{
  /// Classificator types
  vector<uint32_t> m_types;

  struct Name
  {
    string m_Name;
    int8_t m_Lang;
    uint8_t m_prefixLengthToSuggest;
  };

  /// <language, synonym>
  vector<Name> m_synonyms;
};

class CategoriesHolder
{
  typedef vector<Category> ContainerT;
  ContainerT m_categories;

public:
  /// @return number of loaded categories or 0 if something goes wrong
  size_t LoadFromStream(istream & stream);

  template <class ToDo>
  void ForEachCategory(ToDo toDo) const
  {
    for_each(m_categories.begin(), m_categories.end(), toDo);
  }
};

}
