#ifndef HasID_H
#define HasID_H

#include "Utility.h"

namespace Model
{
class HasID
{
  friend Utility;

 public:
  HasID();
  HasID( unsigned objID );
  virtual ~HasID();
  HasID( const HasID & ) = delete;             // Copy constructor - Deleted
  HasID &operator=( const HasID & ) = delete;  // Copy assignment operator - Deleted
  HasID( HasID && ) = default;                 // Move constructor
  HasID &operator=( HasID && ) = default;      // Move assignment operator

  unsigned GetID() const;

 private:
  static unsigned m_NextID;
  static unsigned GetNextID();
  unsigned m_ID = 0;
};
}  // namespace Model

#endif  // HasID_H