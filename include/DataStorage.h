#ifndef DataStorage_H
#define DataStorage_H

#include <memory>
#include "Assembly.h"
namespace Data
{
class DataStorage
{
 public:
  DataStorage();
  ~DataStorage();
  DataStorage( const DataStorage& ) = default;             // Copy constructor
  DataStorage& operator=( const DataStorage& ) = default;  // Copy assignment operator
  DataStorage( DataStorage&& ) = default;                  // Move constructor
  DataStorage& operator=( DataStorage&& ) = default;       // Move assignment operator

  const std::unordered_map<unsigned, std::shared_ptr<Model::Assembly>>& GetAssemblyList();
  std::shared_ptr<Model::Assembly> AddAssembly();
  std::shared_ptr<Model::Assembly> AddAssembly( std::string name );
  void RemoveAssembly( const std::shared_ptr<Model::Assembly>& assemblyToRemove );

  void PrintAllData();
  void PrintSortedData();

 private:
  std::unordered_map<unsigned, std::shared_ptr<Model::Assembly>> m_AssemblyList;
};
}  // namespace Data

#endif  // DataStorage_H