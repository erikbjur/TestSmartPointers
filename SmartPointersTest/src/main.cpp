#include <cstddef>
#include <format>
#include "Assembly.h"
#include "DataStorage.h"

#include <chrono>
#include <iostream>

int main()
{
  // Create a data storage object
  Data::DataStorage data;

  auto start = std::chrono::high_resolution_clock::now();
  for( size_t i = 1; i <= 100; ++i ) {
    // Creat an assembly and give it a name like "Assembly #1"
    auto assembly = data.AddAssembly( std::format( "Assembly #{}", i ) );
    for( size_t j = 1; j <= 50; ++j ) {
      // Add a new part called "Part #1"
      assembly->AddPart( std::format( "Part #{}", j ) );
    }
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto durationLoad = std::chrono::duration_cast<std::chrono::microseconds>( end - start );

  start = std::chrono::high_resolution_clock::now();
  data.PrintAllData();
  end = std::chrono::high_resolution_clock::now();
  auto durationSort = std::chrono::duration_cast<std::chrono::microseconds>( end - start );

  std::cout << "Time to load the data is " << durationLoad.count() << " ms\n";
  std::cout << "Time to sort the data is " << durationSort.count() << " ms\n";

  return 0;
}