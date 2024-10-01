#ifndef Part_H
#define Part_H

#include "Assembly.h"
#include "HasID.h"
#include <memory>
#include <string>

namespace Model
{
class Part : public Model::HasID
{
 public:
  std::string Name;

  Part( std::shared_ptr<Model::Assembly> owner );
  Part( std::shared_ptr<Model::Assembly> owner, std::string name );
  ~Part();
  Part( const Part& ) = delete;             // Copy constructor
  Part& operator=( const Part& ) = delete;  // Copy assignment operator
  Part( Part&& ) = default;                 // Move constructor
  Part& operator=( Part&& ) = default;      // Move assignment operator

  const std::shared_ptr<Model::Assembly> GetOwner();

 private:
  std::weak_ptr<Model::Assembly> m_Owner;
};
}  // namespace Model

#endif  // Part_H