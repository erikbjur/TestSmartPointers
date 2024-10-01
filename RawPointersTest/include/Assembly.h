#ifndef Assembly_H
#define Assembly_H

#include <memory>
#include <string>
#include <unordered_map>
#include "HasID.h"

namespace Model
{
// Forward Declaration
class Part;

class Assembly : public Model::HasID
{
 public:
  std::string Name;

  Assembly();
  Assembly( std::string name );
  ~Assembly();
  Assembly( const Assembly & ) = delete;             // Copy constructor
  Assembly &operator=( const Assembly & ) = delete;  // Copy assignment operator
  Assembly( Assembly && ) = default;                 // Move constructor
  Assembly &operator=( Assembly && ) = default;      // Move assignment operator

  const std::unordered_map<unsigned, std::shared_ptr<Model::Part>> &GetPartsList() const;
  Model::Part *AddPart();
  Model::Part *AddPart( std::string name );
  void RemovePart( const std::shared_ptr<Model::Part> &partToRemove );

 private:
  std::unordered_map<unsigned, std::shared_ptr<Model::Part>> m_PartsList;
};
}  // namespace Model

#endif  // Assembly_H