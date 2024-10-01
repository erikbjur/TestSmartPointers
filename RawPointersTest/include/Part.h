#ifndef Part_H
#define Part_H

#include "Assembly.h"
#include "HasID.h"
#include <string>

namespace Model
{
class Part : public Model::HasID
{
 public:
  std::string Name;

  Part( const Model::Assembly& owner );
  Part( const Model::Assembly& owner, std::string name );
  ~Part();
  Part( const Part& ) = delete;             // Copy constructor
  Part& operator=( const Part& ) = delete;  // Copy assignment operator
  Part( Part&& ) = default;                 // Move constructor
  Part& operator=( Part&& ) = delete;       // Move assignment operator

  const Model::Assembly& GetOwner();

 private:
  const Model::Assembly& m_Owner;
};
}  // namespace Model

#endif  // Part_H