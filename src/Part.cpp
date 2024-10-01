#include "Part.h"
#include <iostream>

Model::Part::Part( std::shared_ptr<Model::Assembly> owner ) : m_Owner( owner )
{
}

Model::Part::Part( std::shared_ptr<Model::Assembly> owner, std::string name )
    : m_Owner( owner ), Name( std::move( name ) )
{
}

Model::Part::~Part()
{
}

const std::shared_ptr<Model::Assembly> Model::Part::GetOwner()
{
  return this->m_Owner.lock();
}
