#include "HasID.h"

unsigned Model::HasID::m_NextID;

Model::HasID::HasID() : m_ID( Model::HasID::GetNextID() )
{
}

Model::HasID::HasID( unsigned objID ) : m_ID( objID )
{
}

Model::HasID::~HasID()
{
}

unsigned Model::HasID::GetID() const
{
  return this->m_ID;
}

unsigned Model::HasID::GetNextID()
{
  // This will return the current value, then increment
  return Model::HasID::m_NextID++;
}