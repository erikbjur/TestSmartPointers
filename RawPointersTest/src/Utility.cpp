#include "Utility.h"

#include "HasID.h"

void Model::Utility::SetNextObjectID( unsigned objectID )
{
  Model::HasID::m_NextID = objectID;
}
