#include "Assembly.h"
#include <memory>
#include "Part.h"
#include <iostream>

Model::Assembly::Assembly()
{
}

Model::Assembly::Assembly( std::string name ) : Name( std::move( name ) )
{
}

Model::Assembly::~Assembly()
{
}

const std::unordered_map<unsigned, std::shared_ptr<Model::Part>> &Model::Assembly::GetPartsList() const
{
  return m_PartsList;
}

std::shared_ptr<Model::Part> Model::Assembly::AddPart()
{
  auto newPart = std::make_shared<Model::Part>( shared_from_this() );
  auto [iterator, success] = this->m_PartsList.try_emplace( newPart->GetID(), std::move( newPart ) );
  if( success ) {
    return iterator->second;
  } else {
    return nullptr;
  }
}

std::shared_ptr<Model::Part> Model::Assembly::AddPart( std::string name )
{
  auto newPart = std::make_shared<Model::Part>( shared_from_this(), name );
  auto [iterator, success] = this->m_PartsList.try_emplace( newPart->GetID(), std::move( newPart ) );
  if( success ) {
    return iterator->second;
  } else {
    return nullptr;
  }
}

void Model::Assembly::RemovePart( const std::shared_ptr<Model::Part> &partToRemove )
{
  this->m_PartsList.erase( partToRemove->GetID() );
}
