#include "DataStorage.h"
#include <cstddef>
#include <memory>
#include "Assembly.h"
#include "Part.h"
#include <iostream>
#include <algorithm>
#include <format>

Data::DataStorage::DataStorage()
{
}

Data::DataStorage::~DataStorage()
{
}

const std::unordered_map<unsigned, std::shared_ptr<Model::Assembly>>& Data::DataStorage::GetAssemblyList()
{
  return this->m_AssemblyList;
}

Model::Assembly* Data::DataStorage::AddAssembly()
{
  auto assembly = std::make_shared<Model::Assembly>();
  auto [iterator, success] = this->m_AssemblyList.try_emplace( assembly->GetID(), std::move( assembly ) );
  if( success ) {
    return iterator->second.get();
  } else {
    return nullptr;
  }
}

Model::Assembly* Data::DataStorage::AddAssembly( std::string name )
{
  auto assembly = std::make_shared<Model::Assembly>( name );
  auto [iterator, success] = this->m_AssemblyList.try_emplace( assembly->GetID(), std::move( assembly ) );
  if( success ) {
    return iterator->second.get();
  } else {
    return nullptr;
  }
}

void Data::DataStorage::RemoveAssembly( const std::shared_ptr<Model::Assembly>& assemblyToRemove )
{
  this->m_AssemblyList.erase( assemblyToRemove->GetID() );
}

void Data::DataStorage::PrintAllData()
{
  for( auto& [it_assembly, assembly] : this->m_AssemblyList ) {
    std::cout << assembly->Name << " ID: " << assembly->GetID() << std::endl;
    for( auto& [it_part, part] : assembly->GetPartsList() ) {
      std::cout << "\t" << part->Name << " ID: " << part->GetID() << " owned by: " << part->GetOwner().Name
                << std::endl;
    }
  }
}

void Data::DataStorage::PrintSortedData()
{
  // Create a vector with enough room to load everything in one shot
  size_t numberOfAssemblies = this->m_AssemblyList.size();

  std::vector<Model::Assembly*> sortedListOfAssemblies;
  sortedListOfAssemblies.reserve( numberOfAssemblies );

  // Load the pointers from each of the assemblies into the vector
  for( auto& assembly : this->m_AssemblyList ) {
    sortedListOfAssemblies.push_back( assembly.second.get() );
  }

  // Now sort the vector by assembly name
  std::sort( sortedListOfAssemblies.begin(), sortedListOfAssemblies.end(),
             []( const Model::Assembly* a, const Model::Assembly* b ) { return a->Name < b->Name; } );

  // Now print the sorted vector
  for( auto& assembly : sortedListOfAssemblies ) {
    std::cout << assembly->Name << " ID: " << assembly->GetID() << std::endl;
    for( auto& [it_part, part] : assembly->GetPartsList() ) {
      std::cout << "\t" << part->Name << " ID: " << part->GetID() << " owned by: " << part->GetOwner().Name
                << std::endl;
    }
  }
}

void Data::DataStorage::SortDataForTiming()
{
  // Create a vector with enough room to load everything in one shot
  size_t numberOfAssemblies = this->m_AssemblyList.size();

  std::vector<Model::Assembly*> sortedListOfAssemblies;
  sortedListOfAssemblies.reserve( numberOfAssemblies );

  // Load the pointers from each of the assemblies into the vector
  for( auto& assembly : this->m_AssemblyList ) {
    sortedListOfAssemblies.push_back( assembly.second.get() );
  }

  // Now sort the vector by assembly name
  std::sort( sortedListOfAssemblies.begin(), sortedListOfAssemblies.end(),
             []( const Model::Assembly* a, const Model::Assembly* b ) { return a->Name < b->Name; } );

  // Now print the sorted vector
  for( auto& assembly : sortedListOfAssemblies ) {
    auto assemblyString = std::format( "{}{}{}", assembly->Name, " ID: ", assembly->GetID() );
    for( auto& [it_part, part] : assembly->GetPartsList() ) {
      auto partString =
          std::format( "{}{}{}{}{}{}", "\t", part->Name, " ID: ", part->GetID(), " owned by: ", part->GetOwner().Name );
    }
  }
}
