#ifndef CATALOG_FACTORY_H
#define CATALOG_FACTORY_H

#include <memory> // for std::unique_ptr
#include <string>
#include "Catalog.h"  // Include the generic Catalog template
#include <variant>    // Include for std::variant
#include <string>     // Include for std::string

// Define the variant type for different Catalog types
using CatalogVariant = std::variant<Catalog<ElevPrimar>, Catalog<ElevGimnaziu>>;

class CatalogFactory {
public:
    static CatalogVariant createCatalog(const std::string& className);
};

#endif // CATALOG_FACTORY_H
