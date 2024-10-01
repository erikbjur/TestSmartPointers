#include <cstddef>
#include <format>
#include "Assembly.h"
#include "DataStorage.h"

int main()
{
  // Create a data storage object
  Data::DataStorage data;

  for( size_t i = 1; i <= 10; ++i ) {
    // Creat an assembly and give it a name like "Assembly #1"
    auto assembly = data.AddAssembly( std::format( "Assembly #{}", i ) );
    for( size_t j = 1; j <= 50; ++j ) {
      // Add a new part called "Part #1"
      assembly->AddPart( std::format( "Part #{}", j ) );
    }
  }

  data.PrintSortedData();

  return 0;
}