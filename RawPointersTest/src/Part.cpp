#include "Part.h"

Model::Part::Part( const Model::Assembly& owner ) : m_Owner( owner )
{
}

Model::Part::Part( const Model::Assembly& owner, std::string name ) : m_Owner( owner ), Name( std::move( name ) )
{
}

Model::Part::~Part()
{
}

const Model::Assembly& Model::Part::GetOwner()
{
  return this->m_Owner;
}
